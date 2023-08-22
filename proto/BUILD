load("@rules_cc//cc:defs.bzl", "cc_proto_library")
load("@rules_proto//proto:defs.bzl", "proto_library")

package(default_visibility = ["//visibility:public"])

cc_proto_library(
    name = "level_cc_proto",
    deps = [":level_proto"],
)

proto_library(
    name = "level_proto",
    srcs = ["level.proto"],
)
