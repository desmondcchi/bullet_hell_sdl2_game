load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
  name = "com_google_googletest",
  urls = ["https://github.com/google/googletest/archive/5ab508a01f9eb089207ee87fd547d290da39d015.zip"],
  strip_prefix = "googletest-5ab508a01f9eb089207ee87fd547d290da39d015",
)

http_archive(
    name = "com_google_absl",
    strip_prefix = "abseil-cpp-5be22f98733c674d532598454ae729253bc53e82",
    urls = ["https://github.com/abseil/abseil-cpp/archive/5be22f98733c674d532598454ae729253bc53e82.zip"],
)

http_archive(
    name = "bazel_skylib",
    sha256 = "66ffd9315665bfaafc96b52278f57c7e2dd09f5ede279ea6d39b2be471e7e3aa",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/bazel-skylib/releases/download/1.4.2/bazel-skylib-1.4.2.tar.gz",
        "https://github.com/bazelbuild/bazel-skylib/releases/download/1.4.2/bazel-skylib-1.4.2.tar.gz",
    ],
)

new_local_repository(
    name = "sdl2",
    build_file = "sdl2.BUILD",
    path = "/opt/homebrew/Cellar/sdl2/2.28.1",
)
