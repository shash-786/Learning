#pragma once
#include "MySQLConnection.h"
#include "MySQLCommand.h"
#include "OracleSQLConnection.h"
#include "OracleSQLCommand.h"

class DBSimpleFactory {
public:
    static Connection* CreateConnection(std::string_view& connection_type);
    static Command* CreateCommand(std::string_view& command_type);
};