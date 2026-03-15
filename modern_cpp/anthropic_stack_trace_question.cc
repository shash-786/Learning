#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <span>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <memory>
#include <numeric>
#include <climits>
#include <functional>
#include <limits.h>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// Problem: Converting stack samples to a trace
// Sampling profilers are a performance analysis tool for finding the slow parts
// of your code by periodically sating the entire call stack (lots of code
// might run between samples). In our problem the samples will be a vector of
// Sample's of a float timestamp and a vector of function names, *in order by
// timestamp*, like this:

struct Sample
{
    double ts;
    std::vector<std::string> stack;
};

// Sometimes it's nice to visualize these samples on a chronological timeline of
// the call stack using a trace visualizer UI. To do this we need to *convert
// the samples tnto a list of start and end events for each function call.*
// Sample stacks contain every function that is currently executing.
// The stacks are in order from outermost function (like "main") to the
// innermost currently executing function. An unlimited amount of
// execution/change can happen between samples. We don't have all the function
// calls that happened, just some samples we want to visualize.
// The returned events should be in a list order properly nested as if
// they were recorded. For example, a nested function call's start event is
// after the one from the enclosing function, and the nested call's end event
// before the enclosing call's end event.

// |----outer----|
//   |--inner--|
// would be ordered: start outer, start inner, end inner, end outer
//*Assume call frames in the last sample haven't finished.* The resulting
// events should use the Event struct:

struct Event
{
    std::string kind;
    double ts;
    std::string name;
    Event(std::string _k, double _ts, std::string _name) : kind(_k), ts(_ts), name(_name) {};

    void PrintDebug() const
    {
        std::cout << "Kind : " << kind << std::endl;
        std::cout << "ts : " << ts << std::endl;
        std::cout << "Name : " << name << std::endl;
        std::cout << "---" << std::endl;
    }
};

std::vector<Event> convertToTrace(const std::vector<Sample> &samples)
{
    // Expected output for the example in main():
    // Event{"start", 7.5, "main"}
    // Event{"start", 9.2, "my_fn"}
    // Event{"start", 9.2, "my_fn2"}
    // Event{"end", 18.7, "my_fu2 }
    // Event{"end", 18.7, "my_fu }
    std::vector<std::string> st;
    std::vector<Event> events;
    
    for (const auto& sample: samples) {
        double ts = sample.ts ;
        const auto& sample_stack = sample.stack ;

        size_t curr_stack_size = st.size(), sample_stack_size = sample_stack.size() ;
    
        int i = 0 ;
        for (; i < std::min (curr_stack_size, sample_stack_size); i++) {
            if (st[i] != sample_stack[i]) {
                break ;
            }
        }

        for (int k = curr_stack_size - 1; k >= i; k--) {
            std::string func_name = st[k] ;
            events.emplace_back ("end", ts, func_name) ;
            st.pop_back () ;
        }
        
        for (int k = i; k < sample_stack_size; k++) {
            std::string func_name = sample_stack[k] ;
            events.emplace_back ("start", ts, func_name) ;
            st.push_back (func_name) ;
        }
    }
    return events;
}

bool eventsEqual(const std::vector<Event>& a, const std::vector<Event>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i) {
        // Compare string values and use a small epsilon for floating point timestamps
        if (a[i].kind != b[i].kind || a[i].name != b[i].name || std::abs(a[i].ts - b[i].ts) > 1e-6) {
            return false;
        }
    }
    return true;
}

void runTest(int testNum, const std::string& testName, const std::vector<Sample>& input, const std::vector<Event>& expected) {
    auto actual = convertToTrace(input);
    if (eventsEqual(actual, expected)) {
        std::cout << "[PASS] Test " << testNum << ": " << testName << "\n";
    } else {
        std::cout << "[FAIL] Test " << testNum << ": " << testName << "\n";
        std::cout << "  Expected:\n";
        for (const auto& e : expected) std::cout << "    " << e.kind << " " << e.ts << " " << e.name << "\n";
        std::cout << "  Actual:\n";
        for (const auto& e : actual) std::cout << "    " << e.kind << " " << e.ts << " " << e.name << "\n";
    }
}

int main()
{
    // Test 1: The Provided Example (Base Case)
    // Notice how your code handles "Assume call frames in the last sample haven't finished" perfectly 
    // by implicitly not popping the remaining stack at the very end.
    runTest(1, "Provided Example", 
        {
            {7.5, {"main"}},
            {9.2, {"main", "my_fn", "my_fn2"}},
            {10.7, {"main"}}
        },
        {
            {"start", 7.5, "main"},
            {"start", 9.2, "my_fn"},
            {"start", 9.2, "my_fn2"},
            {"end", 10.7, "my_fn2"},
            {"end", 10.7, "my_fn"}
        }
    );

    // Test 2: Sibling Calls
    // The stack switches from A->B to A->C. Function A stays open, B closes, C opens.
    runTest(2, "Sibling Calls", 
        {
            {1.0, {"A", "B"}},
            {2.0, {"A", "C"}}
        },
        {
            {"start", 1.0, "A"},
            {"start", 1.0, "B"},
            {"end", 2.0, "B"},
            {"start", 2.0, "C"}
        }
    );

    // Test 3: Completely Different Stacks (Unrelated Contexts)
    // Everything from the first sample must close before the second sample opens.
    runTest(3, "Unrelated Context Switches", 
        {
            {1.0, {"A", "B"}},
            {2.0, {"C", "D"}}
        },
        {
            {"start", 1.0, "A"},
            {"start", 1.0, "B"},
            {"end", 2.0, "B"},    // Note: Reverse order closing
            {"end", 2.0, "A"},
            {"start", 2.0, "C"},
            {"start", 2.0, "D"}
        }
    );

    // Test 4: Fully Unwinding the Stack to Empty
    // The processor goes idle (empty stack) at 4.0.
    runTest(4, "Full Unwind to Empty", 
        {
            {1.0, {"A"}},
            {2.0, {"A", "B"}},
            {3.0, {"A", "B", "C"}},
            {4.0, {}}
        },
        {
            {"start", 1.0, "A"},
            {"start", 2.0, "B"},
            {"start", 3.0, "C"},
            {"end", 4.0, "C"},
            {"end", 4.0, "B"},
            {"end", 4.0, "A"}
        }
    );

    // Test 5: No Change Between Samples
    // The same function continues running. No new start/end events should be fired.
    runTest(5, "Idle/Constant Execution", 
        {
            {1.0, {"main"}},
            {2.0, {"main"}},
            {3.0, {"main"}}
        },
        {
            {"start", 1.0, "main"}
        }
    );

    // Test 6: Empty Input
    runTest(6, "Empty Samples Array", 
        {},
        {}
    );

    return 0;
}