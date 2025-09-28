#include "OracleSQLFactory.h"

OracleSQLConnection *OracleSQLFactory::CreateConnection() {
    return new OracleSQLConnection();
}

OracleSQLCommand *OracleSQLFactory::CreateCommand() {
    return new OracleSQLCommand;
}
