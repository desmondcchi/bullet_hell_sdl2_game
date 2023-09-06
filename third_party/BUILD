package(default_visibility = ["//visibility:public"])

cc_library(
    name = "sdl2",
    srcs = select({
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
        "@bazel_tools//src/conditions:darwin_arm64": glob(["sdl2/2.28.2/darwin_arm64/lib/*.dylib"]),
        "@bazel_tools//src/conditions:darwin_x86_64": glob(["sdl2/2.28.2/darwin_x86_64/lib/*.dylib"]),
        "@bazel_tools//src/conditions:windows_x64": glob(["sdl2/2.28.2/windows_x64/lib/*.dll"]),
=======
        "@bazel_tools//src/conditions:darwin_arm64" or "@bazel_tools//src/conditions:darwin": [":sdl2_darwin_arm64"],
=======
=======
>>>>>>> 2634f34 (Integrate GitHub Actions CI/CD with Bazel.)
=======
>>>>>>> 90f683f (Fix.)
        "@bazel_tools//src/conditions:darwin_arm64": [":sdl2_darwin_arm64"],
<<<<<<< HEAD
        "@bazel_tools//src/conditions:darwin": [":sdl2_darwin_arm64"],
>>>>>>> d17ada7 (Fix.)
=======
        "@bazel_tools//src/conditions:darwin_x86_64": [":sdl2_darwin_arm64"],
>>>>>>> 60c5fbc (Fix.)
        "@bazel_tools//src/conditions:windows_x64": [":sdl2_windows_x64"],
    }),
    hdrs = select({
        "@bazel_tools//src/conditions:darwin_arm64": glob(["sdl2/2.28.2/darwin_arm64/include/SDL2/*.h"]),
        "@bazel_tools//src/conditions:darwin_x86_64": glob(["sdl2/2.28.2/darwin_arm64/include/SDL2/*.h"]),
        "@bazel_tools//src/conditions:windows_x64": glob(["sdl2/2.28.2/windows_x64/include/SDL2/*.h"]),
>>>>>>> c4e06fc (Fix.)
    }),
    hdrs = glob(["sdl2/2.28.2/include/SDL2/*.h"]),
    linkopts = ["-framework OpenGL"],
<<<<<<< HEAD
    strip_include_prefix = "sdl2/2.28.2/include",
=======
    strip_include_prefix = select({
        "@bazel_tools//src/conditions:darwin_arm64": "sdl2/2.28.2/darwin_arm64/include",
        "@bazel_tools//src/conditions:darwin_x86_64": "sdl2/2.28.2/darwin_arm64/include",
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
>>>>>>> 9776ab2 (Fix.)
)
