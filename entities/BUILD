package(default_visibility = ["//visibility:public"])

cc_library(
    name = "entity_cc",
    srcs = ["entity.cc"],
    hdrs = ["entity.h"],
    deps = ["@sdl2"],
)

cc_library(
    name = "player_cc",
    srcs = ["player.cc"],
    hdrs = ["player.h"],
    data = ["//assets/player:player_asset"],
    deps = [
        "//entities:entity_cc",
        "//math:vector_cc",
        "@sdl2",
    ],
)
