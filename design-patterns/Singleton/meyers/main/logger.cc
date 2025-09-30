#include <iostream>
#include "logger.h"

Logger::Logger() {
    std::cout << "constructor called " << std::endl;
    this->m_pstream = fopen("log.txt", "w");
    if (!this->m_pstream) {
        fprintf(stderr, "error in opening the file");
    }
}

// NOT THREAD SAFE
Logger& Logger::getInstanceLazily() {
    // SCENARIO 1 MAKE IT THREAD SAFE
    // m_mut.lock();
    // if (!Logger::m_lptr) {
    //     Logger::m_lptr.reset(new Logger());
    // }
    // m_mut.unlock();
    // return *Logger::m_lptr;

    // AFTER THE INSTANCE IS CREATED THE
    // LOCKING IS NOT NECESSARY
    // SO ONLY USE THE LOGIC WHEN m_lptr is null

    // if (!Logger::m_lptr) {
    //     m_mut.lock();
    //     if (!Logger::m_lptr) {
    //         Logger::m_lptr.reset(new Logger());
    //     }
    //     m_mut.unlock();
    // }
    // return *Logger::m_lptr;

    // BUT WHAT HAPPENS IF A THREAD 1 IS INITIALIZING 
    // m_lptr to logger and at this time time a THREAD 2 checks
    // if the m_lptr is null or not since new is not an atomic 
    // operation data may be uninitialized and THREAD 2 will get 
    // REFERENCE OF A LOGGER INSTANCE which is not initialized <-- Holy shit

    // THREAD SAFE - MEYERS PATTERN
    static Logger logger;
    return logger;
}

void Logger::writeLog(const char* log) {
    fprintf(this->m_pstream, "[%s] %s\n", this->m_tag.c_str(), log);
    std::fflush(this->m_pstream);
}

void Logger::setTag(std::string tag) {
    this->m_tag = tag;
}

Logger::~Logger() {
    std::cout << "destructor called" << std::endl;
    fclose(this->m_pstream);
}