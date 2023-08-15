cc_library(
    name = "sdl2",
    srcs = select({"@bazel_tools//src/conditions:darwin_arm64": [":sdl2_lib"]}),
    hdrs = glob(["sdl2/2.28.2/darwin_arm64/include/SDL2/*.h"]),
    linkopts = ["-framework OpenGL"],
    strip_include_prefix = "sdl2/2.28.2/darwin_arm64/include",
    visibility = ["//visibility:public"],
)

filegroup(
    name = "sdl2_lib",
    srcs = glob(["sdl2/2.28.2/darwin_arm64/lib/*.dylib"]),
)
