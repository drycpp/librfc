/* This is free and unencumbered software released into the public domain. */

#ifndef RFC_RFC3629_UTF8_H
#define RFC_RFC3629_UTF8_H

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
   * @param c a Unicode code point
   * @return the number of bytes needed
   */
  static inline constexpr std::size_t utf8_length(const std::uint32_t c) noexcept {
    return (c < 0x00080) ? 1 : (c < 0x00800) ? 2 : (c < 0x10000) ? 3 : 4;
  }

  /**
   * Encodes a single Unicode code point as UTF-8.
   *
   * The given output buffer must have at least 4 bytes of space.
   *
   * @param c the Unicode code point to encode
   * @param buffer the UTF-8 output buffer
   * @return the number of bytes written
   */
  static inline std::size_t utf8_encode(const std::uint32_t c, char* const buffer) noexcept {
    std::uint8_t* output = reinterpret_cast<std::uint8_t*>(buffer);
    if (c < 0x00080) {
      *output++ = static_cast<std::uint8_t>(c & 0xFF);
    }
    else if (c < 0x00800) {
      *output++ = 0xC0 + static_cast<std::uint8_t>((c >> 6) & 0x1F);
      *output++ = 0x80 + static_cast<std::uint8_t>(c & 0x3F);
    }
    else if (c < 0x10000) {
      *output++ = 0xE0 + static_cast<std::uint8_t>((c >> 12) & 0x0F);
      *output++ = 0x80 + static_cast<std::uint8_t>((c >> 6)  & 0x3F);
      *output++ = 0x80 + static_cast<std::uint8_t>(c & 0x3F);
    }
    else {
      *output++ = 0xF0 + static_cast<std::uint8_t>((c >> 18) & 0x07);
      *output++ = 0x80 + static_cast<std::uint8_t>((c >> 12) & 0x3F);
      *output++ = 0x80 + static_cast<std::uint8_t>((c >> 6) & 0x3F);
      *output++ = 0x80 + static_cast<std::uint8_t>(c & 0x3F);
    }
    return reinterpret_cast<std::uintptr_t>(output) -
      reinterpret_cast<std::uintptr_t>(buffer);
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

#endif /* RFC_RFC3629_UTF8_H */
