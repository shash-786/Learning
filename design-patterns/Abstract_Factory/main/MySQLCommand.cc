#include "MySQLCommand.h"

void MySQLCommand::ExecuteCommand() {
    std::cout << "[MySQL] Executing Command" << std::endl;
}

Cursor *MySQLCommand::ExecuteQuery() {
    std::cout << "[MySQL] Executing Query" << std::endl;
    return new MySQLCursor();
}