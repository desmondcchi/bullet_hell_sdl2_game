#include "util/file.h"

#include <filesystem>
#include <string>

#include "absl/log/check.h"
#include "absl/strings/match.h"
#include "absl/strings/string_view.h"

namespace util {
namespace file {

bool FileExists(absl::string_view file_path) {
  return std::filesystem::exists(file_path);
}

std::vector<std::string> GetAllFilesInDirectory(
    absl::string_view directory_path) {
  CHECK_EQ(std::filesystem::exists(directory_path), true)
      << "Directory does not exist.";

  std::vector<std::string> all_files;
  for (const std::filesystem::directory_entry& directory_entry :
       std::filesystem::recursive_directory_iterator(directory_path)) {
    all_files.emplace_back(directory_entry.path().filename().c_str());
  }

  return all_files;
}

}  // namespace file
}  // namespace util
