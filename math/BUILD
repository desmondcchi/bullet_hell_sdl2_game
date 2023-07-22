cc_library(
    name = "coordinate_cc",
    hdrs = ["coordinate.h"],
)

cc_test(
    name = "coordinate_test",
    srcs = ["coordinate_test.cc"],
    deps = [
        ":coordinate_cc",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "vector_cc",
    srcs = ["vector.cc"],
    hdrs = ["vector.h"],
    deps = [":coordinate_cc"]
)

cc_test(
    name = "vector_test",
    srcs = ["vector_test.cc"],
    deps = [
        ":coordinate_cc",
        ":vector_cc",
        "@com_google_googletest//:gtest_main",
    ],
)
