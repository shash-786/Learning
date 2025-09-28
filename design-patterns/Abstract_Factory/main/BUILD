cc_library(
    name = "interfaces",
    hdrs = [
        "command.h",
        "connection.h",
        "cursor.h",
    ],
)

cc_library(
    name = "mysql",
    srcs = [
        "MySQLCommand.cc",
        "MySQLConnection.cc",
        "MySQLCursor.cc",
    ],
    hdrs = [
        "MySQLCommand.h",
        "MySQLConnection.h",
        "MySQLCursor.h",
    ],
    deps = [":interfaces"],
)

cc_library(
    name = "oraclesql",
    srcs = [
        "OracleSQLCommand.cc",
        "OracleSQLConnection.cc",
        "OracleSQLCursor.cc",
    ],
    hdrs = [
        "OracleSQLCommand.h",
        "OracleSQLConnection.h",
        "OracleSQLCursor.h",
    ],
    deps = [":interfaces"],
)

cc_library(
    name = "dbsimplefactory",
    srcs = ["DBSimpleFactory.cc"],
    hdrs = ["DBSimpleFactory.h"],
    deps = [
        ":mysql",
        ":oraclesql",
    ],
)

cc_library(
    name = "dbfactory",
    hdrs = ["DBFactory.h"],
    deps = [
        ":mysql",
        ":oraclesql",
    ],
)

cc_library(
    name = "mysqlfactory",
    srcs = ["MySQLFactory.cc"],
    hdrs = ["MySQLFactory.h"],
    deps = [
        ":mysql",
        ":dbfactory"
    ],
)

cc_library(
    name = "oraclesqlfactory",
    srcs = ["OracleSQLFactory.cc"],
    hdrs = ["OracleSQLFactory.h"],
    deps = [
        ":oraclesql",
        ":dbfactory"
    ],
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":dbsimplefactory",
        ":mysqlfactory",
        ":oraclesqlfactory",
    ],
)
