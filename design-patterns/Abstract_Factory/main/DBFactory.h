#pragma once
#include "connection.h"
#include "command.h"

class DBFactory {
    public:
    virtual Connection* CreateConnection() = 0;
    virtual Command* CreateCommand() = 0;
    virtual ~DBFactory() = default;
};