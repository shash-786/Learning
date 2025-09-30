load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")


cc_library (
    name = "logger",
    hdrs = ["logger.h"],
    srcs = ["logger.cc"],
)

cc_binary (
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":logger",
    ]
)