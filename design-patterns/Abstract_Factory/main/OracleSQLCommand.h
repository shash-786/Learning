#pragma once
#include "command.h"
#include "OracleSQLCursor.h"

class OracleSQLCommand : public Command {
    public:
    void ExecuteCommand() override;
    Cursor* ExecuteQuery() override;

    ~OracleSQLCommand() = default;
};