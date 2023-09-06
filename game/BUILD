package(default_visibility = ["//visibility:public"])

cc_library(
    name = "game",
    srcs = ["game.cc"],
    hdrs = ["game.h"],
    data = [
        "//assets/player:player_asset",
        "//assets/tiles:all_tiles_png",
        "//game/levels:all_txt",
    ],
    deps = [
        "//entities:player",
        "//level",
        "//projectiles:carrot_gun_projectile",
        "//projectiles:projectile",
        "//third_party:sdl2",
        "//util:audio_manager",
    ],
)
