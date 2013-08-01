/* This is free and unencumbered software released into the public domain. */

#ifndef RFC_RFC3629_UTF8_H
#define RFC_RFC3629_UTF8_H

/**
 * @file
 */

#include <cstdint> /* for std::uint8_t */

namespace rfc3629 {
  extern const std::uint8_t utf8_skip_table[256];
}

#endif /* RFC_RFC3629_UTF8_H */
