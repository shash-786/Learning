#include "logger.h"
#include <ctime>

Logger::Logger() {
    this->m_pstream = fopen("logs.txt", "w");
    if (this->m_pstream == nullptr) {
        std::cerr << "Error: Could not open logs.txt file for writing." << std::endl;
    }
}

void Logger::write_log(const char *logs) {
    time_t now = time(NULL);
    tm* tm_local = localtime(&now);
    fprintf(m_pstream, "[%d:%d:%d] %s %s\n", tm_local->tm_hour, tm_local->tm_min, tm_local->tm_sec, logs, m_tag.empty() ? "" : m_tag.c_str());
    fflush(m_pstream);
}

void Logger::add_tag(const std::string _tag) {
    this->m_tag = _tag;
}

Logger::~Logger() {
    fclose(this->m_pstream);
}