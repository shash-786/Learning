#include <iostream>
#include "DBSimpleFactory.h"
#include "MySQLFactory.h"
#include "OracleSQLFactory.h"

void preprocessor_instantiate();
void layman_instantiate();
void simple_factory_instantiate();
void abstract_factory_instantiate(DBFactory* factory);

int main(int argc, char const *argv[]) {
    // layman_instantiate();
    // preprocessor_instantiate();
    // simple_factory_instantiate();
    abstract_factory_instantiate(new OracleSQLFactory());
    return 0;
}

void layman_instantiate() {
    auto conn = new MySQLConnection(); // <-- TOO MANY PLACES TO CHANGE FOR OracleSQL
    conn->SetConnectionStr("uid:312,name:shash");
    conn->Open();

    auto command = new MySQLCommand();// <-- TOO MANY PLACES TO CHANGE FOR OracleSQL
    command->SetConnection(conn); 
    command->SetCommand(
        "SELECT * FROM LETTERS"
    );

    Cursor* cursor = command->ExecuteQuery();
    while (cursor->HasNext()) {
        std::cout << cursor->Get() << std::endl;
    }
    delete conn;
    delete command;
    delete cursor;
}

#define ORACLE
/*
    FIXED AT COMPILE TIME
    CAN BE CHANGED FOR RUNTIME
    BY USING IF ELSE STILL 
    MANY CHANGES WOULD BE REQUIRED
*/
void preprocessor_instantiate() {
    Connection* p_conn = nullptr;

#ifdef SQL
    p_conn = new MySQLConnection();
#elif defined(ORACLE)
    p_conn = new OracleSQLConnection();
#endif

    p_conn->SetConnectionStr("uid:312,name:shash");
    p_conn->Open();

    Command* p_command;
#ifdef SQL
    p_command = new MySQLCommand();
#elif defined(ORACLE)
    p_command = new OracleSQLCommand();
#endif

    p_command->SetConnection(p_conn);
    p_command->SetCommand(
        "SELECT * FROM LETTERS"
    );

    Cursor* cursor = p_command->ExecuteQuery();
    while (cursor->HasNext()) {
        std::cout << cursor->Get() << std::endl;
    }
    delete p_conn;
    delete p_command;
    delete cursor;
}

void simple_factory_instantiate() {
    std::string_view type = "oracle";
    Connection* p_conn = DBSimpleFactory::CreateConnection(type);
    p_conn->SetConnectionStr("uid:312,name:shash");
    p_conn->Open();

    Command* p_command = DBSimpleFactory::CreateCommand(type);
    p_command->SetConnection(p_conn);
    p_command->SetCommand(
        "SELECT * FROM LETTERS"
    );

    /*
        STILL CAN ALLOW FOR BUGS OR UNDEFINED BEHAVIOR
        SINCE THERE'S NO GUARANTEE THAT THE SAME 
        DB WILL BE USED BY THE CLIENT FOR COMMAND
        AS CONNECTION
    */
    Cursor* cursor = p_command->ExecuteQuery();
    while (cursor->HasNext()) {
        std::cout << cursor->Get() << std::endl;
    }
    delete p_conn;
    delete p_command;
    delete cursor;
}

void abstract_factory_instantiate(DBFactory *factory) {
    Connection* p_conn = factory->CreateConnection();
    p_conn->SetConnectionStr("uid:312,name:shash");
    p_conn->Open();

    Command* p_command = factory->CreateCommand();
    p_command->SetConnection(p_conn);
    p_command->SetCommand(
        "SELECT * FROM LETTERS"
    );
    Cursor* cursor = p_command->ExecuteQuery();
    while (cursor->HasNext()) {
        std::cout << cursor->Get() << std::endl;
    }
    delete p_conn;
    delete p_command;
    delete cursor;
}
