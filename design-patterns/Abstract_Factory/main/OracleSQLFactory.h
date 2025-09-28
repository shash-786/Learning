#pragma once
#include "DBFactory.h"
#include "OracleSQLConnection.h"
#include "OracleSQLCommand.h"

class OracleSQLFactory: public DBFactory {
    public:
    OracleSQLConnection* CreateConnection() override;
    OracleSQLCommand* CreateCommand() override;
};