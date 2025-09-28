#pragma once
#include "command.h"
#include "MySQLCursor.h"

class MySQLCommand: public Command {
    public:
    void ExecuteCommand() override;
    Cursor* ExecuteQuery() override;

    ~MySQLCommand() = default;
};