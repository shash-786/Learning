load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "Animation",
    srcs = ["Animation.cc"],
    hdrs = ["Animation.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "Vehicle",
    srcs = ["Vehicle.cc"],
    hdrs = ["Vehicle.h"],
    visibility = ["//visibility:public"],
    deps = [":Animation"],
)

cc_library(
    name = "Car",
    srcs = ["Car.cc"],
    hdrs = ["Car.h"],
    visibility = ["//visibility:public"],
    deps = [":Vehicle"],
)

cc_library(
    name = "Bus",
    srcs = ["Bus.cc"],
    hdrs = ["Bus.h"],
    visibility = ["//visibility:public"],
    deps = [":Vehicle"],
)

cc_library(
    name = "Creator",
    srcs = ["Creator.cc"],
    hdrs = ["Creator.h"],
    visibility = ["//visibility:public"],
    deps = [
        ":Car",
        ":Bus",
    ],
)

cc_library(
    name = "VehiclePrototypes",
    srcs = ["VehiclePrototypes.cc"],
    hdrs = ["VehiclePrototypes.h"],
    visibility = ["//visibility:public"],
    deps = [":Vehicle"],
)

cc_library(
    name = "GameManager",
    srcs = ["GameManager.cc"],
    hdrs = ["GameManager.h"],
    visibility = ["//visibility:public"],
    deps = [
        ":Creator",
        ":VehiclePrototypes",
    ],
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    copts = ["-g"],
    deps = [":GameManager"],
)
