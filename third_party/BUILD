package(default_visibility = ["//visibility:public"])

cc_library(
    name = "sdl2",
    srcs = select({
        "@bazel_tools//src/conditions:darwin_arm64": glob(["sdl2/2.28.2/darwin_arm64/lib/*.dylib"]),
        "@bazel_tools//src/conditions:darwin_x86_64": glob(["sdl2/2.28.2/darwin_arm_x86_64/lib/*.dylib"]),
        "@bazel_tools//src/conditions:windows_x64": glob(["sdl2/2.28.2/windows_x64/lib/*.dll"]),
    }),
    hdrs = glob(["sdl2/2.28.2/include/SDL2/*.h"]),
    linkopts = ["-framework OpenGL"],
    strip_include_prefix = "sdl2/2.28.2/include",
)
