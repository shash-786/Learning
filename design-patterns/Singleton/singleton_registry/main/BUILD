load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library (
    name = "printer",
    hdrs = ["printer.h"],
    srcs = ["printer.cc"],
)

cc_library (
    name = "localprinter",
    hdrs = ["localprinter.h"],
    deps = [":printer"],
    srcs = ["localprinter.cc"],
)

cc_binary (
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":printer",
    ]
)