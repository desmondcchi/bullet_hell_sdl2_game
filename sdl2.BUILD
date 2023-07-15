cc_library(
    name = "sdl2",
    hdrs = glob(["include/SDL2/*.h"]),
    linkopts = [
        "-L ./sdl2/2.28.1/lib -l SDL2-2.0.0",
        "-framework OpenGL"
    ],
    visibility = ["//visibility:public"],
)