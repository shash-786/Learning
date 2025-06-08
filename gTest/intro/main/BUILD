cc_library (
    name = "libraryCode",
    srcs = ["LibraryCode.cpp"],
    hdrs = ["LibraryCode.hpp"],
    visibility = ["//visibility:public"],
)

cc_binary (
    name = "myApp",
    srcs = ["main.cpp"],
    deps = [":libraryCode"],
)

cc_test (
    name = "sumtest",
    srcs = ["test.cpp"],
    deps = [
        ":libraryCode",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ]
)
