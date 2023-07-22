package(default_visibility = ["//visibility:public"])

cc_library(
    name = "projectile_cc",
    srcs = ["projectile.cc"],
    hdrs = ["projectile.h"],
    deps = [
        "//math:vector_cc",
        "@sdl2",
    ],
)

cc_library(
    name = "carrot_gun_projectile_cc",
    srcs = ["carrot_gun_projectile.cc"],
    hdrs = ["carrot_gun_projectile.h"],
    deps = [
        ":projectile_cc",
        "//math:vector_cc",
        "@sdl2",
    ],
)
