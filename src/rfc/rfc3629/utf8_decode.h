/* This is free and unencumbered software released into the public domain. */

#ifndef RFC_RFC3629_UTF8_DECODE_H
#define RFC_RFC3629_UTF8_DECODE_H

/**
 * @file
 */

#include <cstddef> /* for std::size_t */
#include <cstdint> /* for std::uint*_t, std::uintptr_t */

namespace rfc3629 {
  /**
   * Lookup table for UTF-8 parsing.
   */
  extern const std::uint8_t utf8_skip_table[256];

  /**
   * Lookup table for UTF-8 decoding.
   */
  extern const std::uint8_t utf8_decode_table[64];

  /**
   */
  static inline const char* utf8_skip_char(const char* const input) noexcept {
    return input + utf8_skip_table[*reinterpret_cast<const std::uint8_t*>(input)];
  }

  /**
   */
  static inline char* utf8_skip_char(char* const input) noexcept {
    return input + utf8_skip_table[*reinterpret_cast<std::uint8_t*>(input)];
  }

  /**
   * Decodes a single Unicode code point from UTF-8 input.
   *
   * @param input the UTF-8 input string
   * @return the decoded Unicode code point
   */
  static inline std::uint32_t utf8_decode(const char* const input_) noexcept {
    const std::uint8_t* input = reinterpret_cast<const std::uint8_t*>(input_);
    std::uint32_t c = *input++;
    if (c >= 0xC0) {
      c = utf8_decode_table[c - 0xC0];
      while ((*input & 0xC0) == 0x80) {
        c = (c << 6) + (*input++ & 0x3F);
      }
      if ((c < 0x80) ||
          (c & 0xFFFFF800) == 0xD800 ||
          (c & 0xFFFFFFFE) == 0xFFFE) {
        c = 0xFFFD; /* replacement character (U+FFFD) */
      }
    }
    return c;
  }
}

#endif /* RFC_RFC3629_UTF8_DECODE_H */
