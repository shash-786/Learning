load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "game_logic",
    srcs = [
        "Alien.cc",
        "GameObject.cc",
        "GameObjectPool.cc",
        "Missile.cc",
    ],
    hdrs = [
        "Alien.h",
        "GameObject.h",
        "GameObjectPool.h",
        "Missile.h",
    ],
    visibility = ["//main:__pkg__"],
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [":game_logic"],
)
