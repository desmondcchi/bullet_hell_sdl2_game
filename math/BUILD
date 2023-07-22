package(default_visibility = ["//visibility:public"])

cc_library(
    name = "vector_cc",
    srcs = ["vector.cc"],
    hdrs = ["vector.h"],
    deps = [
        "@sdl2",
    ],
)

cc_test(
    name = "vector_test",
    srcs = ["vector_test.cc"],
    deps = [
        ":vector_cc",
        "@com_google_googletest//:gtest_main",
    ],
)
