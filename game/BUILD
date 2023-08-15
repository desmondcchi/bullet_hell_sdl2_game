package(default_visibility = ["//visibility:public"])

cc_library(
    name = "game",
    srcs = ["game.cc"],
    hdrs = ["game.h"],
    data = ["//assets/player:player_asset"],
    deps = [
        ":audio_manager",
        "//entities:player",
        "//projectiles:carrot_gun_projectile",
        "//projectiles:projectile",
        "//third_party:sdl2",
    ],
)

cc_library(
    name = "audio_manager",
    srcs = ["audio_manager.cc"],
    hdrs = ["audio_manager.h"],
    data = ["//assets/player:player_asset"],
    deps = [
        "@com_google_absl//absl/container:flat_hash_map",
        "@com_google_absl//absl/strings:string_view",
        "//third_party:sdl2",
    ],
)
