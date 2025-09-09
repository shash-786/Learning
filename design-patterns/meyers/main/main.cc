#include <iostream>
#include "logger.h"

void foo(Logger& ref) {
    ref.writeLog("Something Happens here");
}

int main(int argc, char const *argv[]) {
    Logger& g_loggerInstance = Logger::getInstanceLazily();
    g_loggerInstance.setTag("192.168.0.1");
    g_loggerInstance.writeLog("Application Started");
    foo(g_loggerInstance);
    g_loggerInstance.writeLog("Application Ended");
    return 0;
}