#pragma once
#include "connection.h"

class OracleSQLConnection : public Connection {
    public:
    ~OracleSQLConnection() = default;
    void Open() override;
};