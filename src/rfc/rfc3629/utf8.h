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
   * Lookup table for UTF-8 decoding.
   */
  extern const std::uint8_t utf8_skip_table[256];

  /**
   * @param c the Unicode codepoint to encode
   * @param buffer the output buffer (at least 4 bytes)
   * @return the number of encoded bytes
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
}

#endif /* RFC_RFC3629_UTF8_H */
