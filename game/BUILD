package(default_visibility = ["//visibility:public"])

cc_library(
    name = "game_cc",
    srcs = ["game.cc"],
    hdrs = ["game.h"],
    data = ["//assets/player:player_asset"],
    deps = [
        ":audio_manager_cc",
        "//entities:player_cc",
        "//projectiles:carrot_gun_projectile_cc",
        "//projectiles:projectile_cc",
        "@sdl2",
    ],
)

cc_library(
    name = "audio_manager_cc",
    srcs = ["audio_manager.cc"],
    hdrs = ["audio_manager.h"],
    data = ["//assets/player:player_asset"],
    deps = [
        "@com_google_absl//absl/container:flat_hash_map",
        "@com_google_absl//absl/strings:string_view",
        "@sdl2",
    ],
)
