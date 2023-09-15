#ifndef UTIL_PROTO_H_
#define UTIL_PROTO_H_

#include <fcntl.h>

#include "absl/log/check.h"
#include "absl/strings/match.h"
#include "absl/strings/string_view.h"
#include "google/protobuf/io/zero_copy_stream_impl.h"
#include "google/protobuf/text_format.h"

namespace util {
namespace proto {

// Reads `.txt` file into a protobuf message.
template <typename T>
inline void ReadTextProto(T* message, absl::string_view textproto_path) {
  CHECK_EQ(absl::EndsWith(textproto_path, ".txt"), true)
      << "File extension must be .txt.";
  int file_descriptor = open(textproto_path.data(), O_RDONLY);
  google::protobuf::io::FileInputStream finput(file_descriptor);
  finput.SetCloseOnDelete(true);
  bool success = google::protobuf::TextFormat::Parse(&finput, message);
  CHECK_EQ(success, true) << "Failed to parse .txt into proto message. "
                             "(Incorrect fields/formatting?)";
}

}  // namespace proto
}  // namespace util

#endif
