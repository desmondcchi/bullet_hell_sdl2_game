package(default_visibility = ["//visibility:public"])

cc_library(
    name = "projectile",
    srcs = ["projectile.cc"],
    hdrs = ["projectile.h"],
    deps = [
        "//math:vector",
        "//third_party:sdl2",
    ],
)

cc_library(
    name = "carrot_gun_projectile",
    srcs = ["carrot_gun_projectile.cc"],
    hdrs = ["carrot_gun_projectile.h"],
    deps = [
        ":projectile",
        "//math:vector",
        "//third_party:sdl2",
    ],
)
