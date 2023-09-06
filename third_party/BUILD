package(default_visibility = ["//visibility:public"])

cc_library(
    name = "sdl2",
    srcs = select({
        "@bazel_tools//src/conditions:darwin_arm64": glob(["sdl2/2.28.2/darwin_arm64/lib/*.dylib"]),
        "@bazel_tools//src/conditions:darwin_x86_64": glob(["sdl2/2.28.2/darwin_arm64/lib/*.dylib"]),
        "@bazel_tools//src/conditions:windows_x64": glob(["sdl2/2.28.2/windows_x64/lib/*.dll"]),
    }),
    hdrs = glob(["sdl2/2.28.2/include/SDL2/*.h"]),
    linkopts = ["-framework OpenGL"],
    strip_include_prefix = "sdl2/2.28.2/include",
)

# cc_library(
#     name = "sdl2",
#     hdrs = glob(["sdl2/2.28.2/darwin_arm64/include/SDL2/*.h"]),
#     includes = ["sdl2/2.28.2/darwin_arm64/include"],
#     linkopts = ["-framework OpenGL"],
#     linkstatic = 1,
#     deps = [
#         ":sdl2_base",
#         ":sdl2_image",
#         ":sdl2_main",
#         ":sdl2_mixer",
#     ],
# )

# cc_import(
#     name = "sdl2_base",
#     hdrs = glob(["sdl2/2.28.2/darwin_arm64/include/SDL2/*.h"]),
#     shared_library = "sdl2/2.28.2/darwin_arm64/lib/libSDL2.dylib",
#     static_library = "sdl2/2.28.2/darwin_arm64/lib/libSDL2.a",
#     alwayslink = 1,
# )

# cc_import(
#     name = "sdl2_main",
#     hdrs = glob(["sdl2/2.28.2/darwin_arm64/include/SDL2/*.h"]),
#     static_library = "sdl2/2.28.2/darwin_arm64/lib/libSDL2main.a",
#     alwayslink = 1,
# )

# cc_import(
#     name = "sdl2_image",
#     hdrs = glob(["sdl2/2.28.2/darwin_arm64/include/SDL2/*.h"]),
#     static_library = "sdl2/2.28.2/darwin_arm64/lib/libSDL2_image.a",
#     alwayslink = 1,
# )

# cc_import(
#     name = "sdl2_mixer",
#     hdrs = glob(["sdl2/2.28.2/darwin_arm64/include/SDL2/*.h"]),
#     static_library = "sdl2/2.28.2/darwin_arm64/lib/libSDL2_mixer.a",
#     alwayslink = 1,
# )
