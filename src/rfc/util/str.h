/* This is free and unencumbered software released into the public domain. */

#ifndef RFC_UTIL_STR_H
#define RFC_UTIL_STR_H

/**
 * @file
 */

#include <cstddef> /* for std::size_t */
#include <cstring> /* for std::mem*(), std::str*() */

namespace rfc {
  class str;
}

/**
 * C string wrapper class.
 *
 * @note Instances of this class are movable, but not copyable.
 */
class rfc::str {
  const char* _data = nullptr;

public:
  /**
   * ...
   */
  static constexpr std::size_t npos = static_cast<std::size_t>(-1);

  /**
   * Default constructor.
   */
  str() noexcept {}

  /**
   * Constructor.
   */
  str(const char* data) noexcept
    : _data(data) {}

  /**
   * Copy constructor.
   */
  str(const str& other) noexcept = delete;

  /**
   * Move constructor.
   */
  str(str&& other) noexcept = default;

  /**
   * Destructor.
   */
  ~str() noexcept = default;

  /**
   * Copy assignment operator.
   */
  str& operator=(const str& other) noexcept = delete;

  /**
   * Move assignment operator.
   */
  str& operator=(str&& other) noexcept = default;
};

#endif /* RFC_UTIL_STR_H */
