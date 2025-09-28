#pragma once
#include "connection.h"
#include "cursor.h"

class Command {
    Connection* m_pConnection;
    std::string m_Command;

    public:
    void SetConnection(Connection* pConnection) {
        this->m_pConnection = pConnection;
    }

    const Connection* GetConnection() const {
        return this->m_pConnection;
    }

    const std::string& GetCommand() const {
        return this->m_Command;
    }

    void SetCommand(const std::string& command) {
        this->m_Command = m_Command;
    }
    
    virtual void ExecuteCommand() = 0;
    virtual Cursor* ExecuteQuery() = 0;
    virtual ~Command() = default;
};
