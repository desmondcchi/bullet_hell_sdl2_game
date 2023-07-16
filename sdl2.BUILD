cc_library(
    name = "sdl2",
    hdrs = glob(["include/SDL2/*.h"]),
    linkopts = [
        # TODO: File path for -L flag should be relative path to sdl2/2.28.1/lib. (Unable to do so.)
        "-L /Users/desmondchi/dev/bullet_hell_sdl2_game/sdl2/2.28.1/lib -l SDL2-2.0.0",
        "-framework OpenGL"
    ],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)