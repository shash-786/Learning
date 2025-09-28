#include "OracleSQLCommand.h"

void OracleSQLCommand::ExecuteCommand() {
    std::cout << "[OracleSQL] Executing Command" << std::endl;
}

Cursor *OracleSQLCommand::ExecuteQuery() {
    std::cout << "[OracleSQL] Executing Query" << std::endl;
    return new OracleSQLCursor();
}
