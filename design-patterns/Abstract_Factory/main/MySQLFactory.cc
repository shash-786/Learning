#include "MySQLFactory.h"

MySQLConnection *MySQLFactory::CreateConnection() {
    return new MySQLConnection();
}

MySQLCommand *MySQLFactory::CreateCommand() {
    return new MySQLCommand();
}
