#pragma once
#include "connection.h"

class MySQLConnection: public Connection {
    public:
    ~MySQLConnection() = default;
    void Open() override;
};