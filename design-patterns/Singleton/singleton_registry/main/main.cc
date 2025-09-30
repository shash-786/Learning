#include <iostream>
#include "localprinter.h"

void Print() {
    Printer::getInstance("local").print("world");
}

int main(int argc, char const *argv[]) {
    auto& p = Printer::getInstance("local");
    p.print("Hello");
    Print();
    return 0;
}
