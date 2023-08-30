#include "util/proto.h"

#include <memory>

#include "gtest/gtest.h"
#include "util/testdata/test.pb.h"

namespace util {
namespace proto {
namespace {

TEST(ProtoUtilTest, ReadTextProto) {
  ::util::Test test;

  ReadTextProto(&test, "util/testdata/test.txt");

  EXPECT_EQ(test.id(), 123);
  EXPECT_EQ(test.nodes_size(), 2);
}

TEST(ProtoUtilTest, FailReadTextProto) {
  ::util::Test test;

  EXPECT_DEATH(ReadTextProto(&test, "util/testdata/test.textproto"),
               "File extension must be .txt.");
}

TEST(ProtoUtilTest, MessageRawPointer) {
  ::util::Test* test = new ::util::Test();

  ReadTextProto(test, "util/testdata/test.txt");

  EXPECT_EQ(test->id(), 123);
  EXPECT_EQ(test->nodes_size(), 2);
}

TEST(ProtoUtilTest, MessageUniquePointer) {
  std::unique_ptr<::util::Test> test = std::make_unique<::util::Test>();

  ReadTextProto(test.get(), "util/testdata/test.txt");

  EXPECT_EQ(test->id(), 123);
  EXPECT_EQ(test->nodes_size(), 2);
}

}  // namespace
}  // namespace proto
}  // namespace util
