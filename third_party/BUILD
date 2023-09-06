package(default_visibility = ["//visibility:public"])

cc_library(
    name = "sdl2",
    srcs = select({
<<<<<<< HEAD
<<<<<<< HEAD
        "@bazel_tools//src/conditions:darwin_arm64": glob(["sdl2/2.28.2/darwin_arm64/lib/*.dylib"]),
        "@bazel_tools//src/conditions:darwin_x86_64": glob(["sdl2/2.28.2/darwin_x86_64/lib/*.dylib"]),
        "@bazel_tools//src/conditions:windows_x64": glob(["sdl2/2.28.2/windows_x64/lib/*.dll"]),
=======
        "@bazel_tools//src/conditions:darwin_arm64" or "@bazel_tools//src/conditions:darwin": [":sdl2_darwin_arm64"],
=======
        "@bazel_tools//src/conditions:darwin_arm64": [":sdl2_darwin_arm64"],
        "@bazel_tools//src/conditions:darwin": [":sdl2_darwin_arm64"],
>>>>>>> d17ada7 (Fix.)
        "@bazel_tools//src/conditions:windows_x64": [":sdl2_windows_x64"],
    }),
    hdrs = select({
        "@bazel_tools//src/conditions:darwin_arm64": glob(["sdl2/2.28.2/darwin_arm64/include/SDL2/*.h"]),
        "@bazel_tools//src/conditions:darwin": glob(["sdl2/2.28.2/darwin_arm64/include/SDL2/*.h"]),
        "@bazel_tools//src/conditions:windows_x64": glob(["sdl2/2.28.2/windows_x64/include/SDL2/*.h"]),
>>>>>>> c4e06fc (Fix.)
    }),
    hdrs = glob(["sdl2/2.28.2/include/SDL2/*.h"]),
    linkopts = ["-framework OpenGL"],
    strip_include_prefix = "sdl2/2.28.2/include",
)
