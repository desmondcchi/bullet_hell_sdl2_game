#include "util/proto.h"

#include "gtest/gtest.h"
#include "util/testdata/test.pb.h"

namespace util {
namespace proto {
namespace {

TEST(ProtoUtilTest, ReadTextProto) {
  ::util::Test test;

  ReadTextProto(&test, "util/testdata/test.txt");

  EXPECT_EQ(test.id(), 123);
}

TEST(ProtoUtilTest, FailReadTextProto) {
  ::util::Test test;

  EXPECT_DEATH(ReadTextProto(&test, "util/testdata/test.textproto"), "File extension must be .txt.");
}

}  // namespace
}  // namespace proto
}  // namespace util
