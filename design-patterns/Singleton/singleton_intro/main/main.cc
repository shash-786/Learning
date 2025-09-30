#include <iostream>
#include "logger.h"

void foo() {
    Logger& _logger = Logger::GetInstance();
    _logger.write_log("Program Exec");
}

int main(int argc, char const *argv[]) {
    Logger& _logger = Logger::GetInstance();
    _logger.write_log("Application Started");
    foo();
    _logger.write_log("Application Ended");
    return 0;
}
