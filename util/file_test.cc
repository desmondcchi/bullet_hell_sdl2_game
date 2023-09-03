#include "util/file.h"

#include "absl/strings/string_view.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace util {
namespace file {
namespace {

TEST(UtilFileTest, GetAllFilesInDirectory) {
  EXPECT_TRUE(FileExists("util/testdata/folder/0.txt"));
  EXPECT_TRUE(FileExists("util/testdata/folder/1.txt"));
  EXPECT_FALSE(FileExists("util/testdata/folder/2.txt"));
}

TEST(UtilFileTest, FileExists) {
  std::vector<std::string> all_files =
      GetAllFilesInDirectory("util/testdata/folder/");
  std::vector<std::string> expected_all_files = {"0.txt", "1.txt"};

  EXPECT_EQ(all_files.size(), 2);
  EXPECT_THAT(all_files, ::testing::ElementsAreArray(expected_all_files));
}

}  // namespace
}  // namespace file
}  // namespace util
