load("@rules_cc//cc:defs.bzl" , "cc_library", "cc_binary")

cc_library (
    name = "logger",
    srcs = [ "logger.cc" ],
    hdrs = [ "logger.h" ],
)

cc_binary (
    name = "singleton",
    srcs = [ "main.cc"],
    deps = [ ":logger" ]
)