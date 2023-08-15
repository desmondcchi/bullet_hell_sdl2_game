package(default_visibility = ["//visibility:public"])

cc_library(
    name = "entity",
    srcs = ["entity.cc"],
    hdrs = ["entity.h"],
    deps = ["//third_party:sdl2"],
)

cc_library(
    name = "player",
    srcs = ["player.cc"],
    hdrs = ["player.h"],
    data = ["//assets/player:player_asset"],
    deps = [
        "//entities:entity",
        "//math:vector",
        "//third_party:sdl2",
    ],
)
