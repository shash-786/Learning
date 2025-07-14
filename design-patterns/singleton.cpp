#include <iostream>
#include <vector>

class Logger {
public:
    static Logger& getInstance() {
        if (_instance == nullptr) 
            _instance = new Logger();
        return *_instance;
    }

    void get_messages() {
        for (auto& message: messages) {
            std::cout << message << std::endl;
        }
    }

    void add_message(const std::string& message) {
        messages.push_back(message);
    }

private:
    Logger() {
        std::cout << "Logger Created" << std::endl;
    }

    ~Logger() {
        std::cout << "Logger Destroyed" << std::endl;
    }
    static Logger* _instance;
    std::vector< std::string > messages;
};

static Logger* _instance = nullptr;

int main(int argc, char const *argv[]) {
    Logger::getInstance().add_message("hello");
    Logger::getInstance().add_message("world");
    Logger::getInstance().get_messages();
    return 0;
}
