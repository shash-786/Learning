#include "printer.h"
#include "localprinter.h"

Printer& Printer::getInstance(const std::string& type) {
    if (type == "local") {
        return LocalPrinter::getInstance();
    } else {
        std::__throw_runtime_error("Unknown printer type");
    }
}
