#ifndef UTIL_FILE_H_
#define UTIL_FILE_H_

#include <filesystem>
#include <string>
#include <vector>

#include "absl/strings/string_view.h"

namespace util {
namespace file {

// Returns the if a file exists in a directory.
bool FileExists(absl::string_view file_path);

// Returns a list of all files in a directory (includes extension).
std::vector<std::string> GetAllFilesInDirectory(
    absl::string_view directory_path);

}  // namespace file
}  // namespace util

#endif
