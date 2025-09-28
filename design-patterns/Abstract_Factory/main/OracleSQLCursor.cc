#include "OracleSQLCursor.h"

OracleSQLCursor::OracleSQLCursor() {
    this->it = OracleSQLdb.begin();
}

const std::string &OracleSQLCursor::Get() {
    return *this->it++;
}

bool OracleSQLCursor::HasNext() {
    return this->it != OracleSQLdb.end();
}
