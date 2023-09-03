package(default_visibility = ["//visibility:public"])

cc_library(
    name = "file",
    srcs = ["file.cc"],
    hdrs = ["file.h"],
    deps = [
        "@com_google_absl//absl/log:check",
        "@com_google_absl//absl/strings:string_view",
    ],
)

cc_test(
    name = "file_test",
    srcs = ["file_test.cc"],
    data = ["//util/testdata:folder"],
    deps = [
        ":file",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "proto",
    hdrs = ["proto.h"],
    deps = [
        "@com_google_absl//absl/log:check",
        "@com_google_absl//absl/strings:string_view",
        "@com_google_protobuf//:protobuf",
    ],
)

cc_test(
    name = "proto_test",
    srcs = ["proto_test.cc"],
    data = ["//util/testdata:test_txt"],
    deps = [
        ":proto",
        "//util/testdata:test_cc_proto",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "audio_manager",
    srcs = ["audio_manager.cc"],
    hdrs = ["audio_manager.h"],
    data = ["//assets/player:player_asset"],
    deps = [
        "//third_party:sdl2",
        "@com_google_absl//absl/container:flat_hash_map",
        "@com_google_absl//absl/strings:string_view",
    ],
)
