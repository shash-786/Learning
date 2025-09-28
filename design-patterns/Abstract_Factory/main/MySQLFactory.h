#pragma once
#include "DBFactory.h"
#include "MySQLConnection.h"
#include "MySQLCommand.h"

class MySQLFactory : public DBFactory {
    public:
    MySQLConnection* CreateConnection() override;
    MySQLCommand* CreateCommand() override;
};