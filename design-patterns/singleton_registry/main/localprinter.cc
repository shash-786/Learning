#include "localprinter.h"
#include <iostream>

LocalPrinter LocalPrinter::m_instance;
void LocalPrinter::print(const std::string& data) {
    std::cout << "[LOCALPRINTER] " << data << std::endl;
}

LocalPrinter& LocalPrinter::getInstance() {
    return m_instance;
}