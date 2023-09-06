cc_library(
    name = "sdl2",
    srcs = select({
        "@bazel_tools//src/conditions:darwin_arm64": [":sdl2_darwin_arm64"],
        "@bazel_tools//src/conditions:darwin_x86_64": [":sdl2_darwin_arm64"],
        "@bazel_tools//src/conditions:windows_x64": [":sdl2_windows_x64"],
    }),
    hdrs = select({
        "@bazel_tools//src/conditions:darwin_arm64": glob(["sdl2/2.28.2/darwin_arm64/include/SDL2/*.h"]),
        "@bazel_tools//src/conditions:darwin_x86_64": glob(["sdl2/2.28.2/darwin_arm64/include/SDL2/*.h"]),
        "@bazel_tools//src/conditions:windows_x64": glob(["sdl2/2.28.2/windows_x64/include/SDL2/*.h"]),
    }),
    linkopts = ["-framework OpenGL"],
    strip_include_prefix = select({
        "@bazel_tools//src/conditions:darwin_arm64": "sdl2/2.28.2/darwin_arm64/include",
        "@bazel_tools//src/conditions:windows_x64": "sdl2/2.28.2/windows_x64/include",
    }),
    visibility = ["//visibility:public"],
)

filegroup(
    name = "sdl2_darwin_arm64",
    srcs = glob(["sdl2/2.28.2/darwin_arm64/lib/*.dylib"]),
)

filegroup(
    name = "sdl2_windows_x64",
    srcs = glob(["sdl2/2.28.2/windows_x64/lib/*.dll.a"]),
)
