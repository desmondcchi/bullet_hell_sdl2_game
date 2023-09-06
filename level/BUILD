package(default_visibility = ["//visibility:public"])

cc_library(
    name = "level",
    srcs = ["level.cc"],
    hdrs = ["level.h"],
    deps = [
        ":room",
        "//proto:level_cc_proto",
        "//third_party:sdl2",
        "//util:proto",
        "@com_google_absl//absl/container:flat_hash_map",
        "@com_google_absl//absl/log:check",
        "@com_google_absl//absl/strings:string_view",
    ],
)

cc_test(
    name = "level_test",
    srcs = ["level_test.cc"],
    data = ["//level/testdata:level_graph_txt"],
    deps = [
        ":level",
        "//proto:level_cc_proto",
        "//util:proto",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "room",
    srcs = ["room.cc"],
    hdrs = ["room.h"],
    deps = [
        "//level:tile",
        "//proto:level_cc_proto",
        "//third_party:sdl2",
        "//util:proto",
        "@com_google_absl//absl/container:flat_hash_map",
        "@com_google_absl//absl/strings:string_view",
    ],
)

cc_library(
    name = "tile",
    srcs = ["tile.cc"],
    hdrs = ["tile.h"],
    deps = [
        "//third_party:sdl2",
    ],
)