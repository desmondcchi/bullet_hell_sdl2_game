load("@rules_cc//cc:defs.bzl", "cc_proto_library")
load("@rules_proto//proto:defs.bzl", "proto_library")

package(default_visibility = ["//util:__subpackages__"])

filegroup(
    name = "folder",
    srcs = glob(["folder/*"]),
)

filegroup(
    name = "test_txt",
    srcs = [
        "test.txt",
    ],
)

proto_library(
    name = "test_proto",
    srcs = ["test.proto"],
)

cc_proto_library(
    name = "test_cc_proto",
    deps = [":test_proto"],
)
