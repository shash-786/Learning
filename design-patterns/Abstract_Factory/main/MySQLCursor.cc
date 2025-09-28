#include "MySQLCursor.h"

MySQLCursor::MySQLCursor() {
    this->it = MySQLdb.begin();
}

const std::string &MySQLCursor::Get() {
    return *this->it++;
}

bool MySQLCursor::HasNext() {
    return this->it != MySQLdb.end();
}