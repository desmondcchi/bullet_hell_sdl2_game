#ifndef UTIL_PROTO_
#define UTIL_PROTO_

#include "absl/strings/string_view.h"
#include "google/protobuf/message.h"

namespace util {
namespace proto {

// Reads `.txt` file into a protobuf message.
void ReadTextProto(google::protobuf::Message* message,
                   absl::string_view textproto_path);

}  // namespace proto
}  // namespace util

#endif
