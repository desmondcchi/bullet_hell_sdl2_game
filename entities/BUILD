package(default_visibility = ["//visibility:public"])

filegroup(
    name = "ben_forward_face_png",
    srcs = ["ben_forward_face.png"],
)

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
