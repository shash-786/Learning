#include "DBSimpleFactory.h"

Connection *DBSimpleFactory::CreateConnection(std::string_view &connection_type) {
    if (connection_type == "mysql") {
        return new MySQLConnection();
    } else if (connection_type == "oracle") {
        return new OracleSQLConnection();
    } 
    throw std::runtime_error("unknown connection type");
}

Command *DBSimpleFactory::CreateCommand(std::string_view &command_type) {
    if (command_type == "mysql") {
        return new MySQLCommand();
    } else if (command_type == "oracle") {
        return new OracleSQLCommand();
    } 
    throw std::runtime_error("unknown connection type");
}
