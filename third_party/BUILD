package(default_visibility = ["//visibility:public"])

filegroup(
    name = "test",
    srcs = ["sdl2/2.28.2/darwin_arm64/lib"],
)

cc_library(
    name = "sdl2",
    srcs = select({
        "@bazel_tools//src/conditions:darwin_arm64": glob(["sdl2/2.28.2/darwin_arm64/lib/*.dylib"]),
        "@bazel_tools//src/conditions:darwin_x86_64": glob(["sdl2/2.28.2/darwin_x86_64/lib/*.dylib"]),
        "@bazel_tools//src/conditions:windows_x64": glob(["sdl2/2.28.2/windows_x64/lib/*.dll"]),
    }),
    hdrs = glob(["sdl2/2.28.2/include/SDL2/*.h"]),
    linkopts = select({
        "@bazel_tools//src/conditions:darwin_x86_64": [
            "-framework OpenGL",
            "-Wl,sdl2/2.28.2/darwin_x86_64/lib/libSDL2-2.0.0.dylib",
        ],
        "//conditions:default": [
            "-framework OpenGL",
            # "-Wl, sdl2/2.28.2/darwin_arm64/lib/libSDL2-2.0.0.dylib",
            # "-Wl,--script=$(location :sdl2/2.28.2/darwin_arm64/lib/libSDL2-2.0.0.dylib)",
        ],
    }),
    strip_include_prefix = "sdl2/2.28.2/include",
)
