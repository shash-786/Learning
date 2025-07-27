#include <iostream>
#include "logger.h"

Logger::Logger() {
    std::cout << "constructor called " << std::endl;
    this->m_pstream = fopen("log.txt", "w");
    if (!this->m_pstream) {
        fprintf(stderr, "error in opening the file");
    }
}

Logger& Logger::getInstanceLazily() {
    if (!Logger::m_lptr) {
        Logger::m_lptr.reset(new Logger());
    }
    return *Logger::m_lptr;
}

void Logger::writeLog(const char* log) {
    fprintf(this->m_pstream, "[%s] %s\n", this->m_tag.c_str(), log);
    std::fflush(this->m_pstream);
}

void Logger::setTag(std::string tag) {
    this->m_tag = tag;
}

Logger::~Logger() {
    std::cout << "desrtcutor called" << std::endl;
    fclose(this->m_pstream);
}