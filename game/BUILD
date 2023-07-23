package(default_visibility = ["//visibility:public"])

cc_library(
    name = "game_cc",
    srcs = ["game.cc"],
    hdrs = ["game.h"],
    deps = [
        "//entities:player_cc",
        "//projectiles:carrot_gun_projectile_cc",
        "//projectiles:projectile_cc",
        "@sdl2",
    ],
)

cc_library(
    name = "texture_manager_cc",
    srcs = ["texture_manager.cc"],
    hdrs = ["texture_manager.h"],
    deps = [
        "@com_google_absl//absl/strings:string_view",
        "@sdl2",
    ],
)
