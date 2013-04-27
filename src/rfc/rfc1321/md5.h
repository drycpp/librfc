/* This is free and unencumbered software released into the public domain. */

#ifndef RFC1321_MD5_H
#define RFC1321_MD5_H

#include <cstdint> /* for std::uint8_t */
#include <cstring> /* for std::memcmp() */
#include <utility> /* for std::swap() */

/**
 * @file
 */

namespace rfc1321 {
  struct md5;
}

/**
 * Represents an MD5 digest.
 */
struct rfc1321::md5 {
protected:
  std::uint8_t _data[16] = {};

public:
  /**
   * Default constructor. The structure is all zeroes after construction.
   */
  md5() noexcept {}

  /**
   * Constructor.
   */
  md5(const std::uint8_t* const data) noexcept {
    *_data = *data;
  }

  /**
   * Copy constructor.
   */
  md5(const md5& other) noexcept {
    *_data = *other._data;
  }

  /**
   * Move constructor.
   */
  md5(md5&& other) noexcept {
    std::swap(_data, other._data);
  }

  /**
   * Destructor.
   */
  ~md5() noexcept {}

  /**
   * Copy assignment operator.
   */
  md5& operator=(md5 other) noexcept {
    std::swap(_data, other._data);
    return *this;
  }

  /**
   * Move assignment operator.
   */
  md5& operator=(md5&& other) noexcept {
    std::swap(_data, other._data);
    return *this;
  }

  /**
   * Equality operator.
   */
  bool operator==(const md5& other) const {
    return std::memcmp(_data, other._data, sizeof(_data)) == 0;
  }

  /**
   * Inequality operator.
   */
  bool operator!=(const md5& other) const {
    return std::memcmp(_data, other._data, sizeof(_data)) != 0;
  }

  /**
   * Less-than operator.
   */
  bool operator<(const md5& other) const {
    return std::memcmp(_data, other._data, sizeof(_data)) < 0;
  }

  /**
   * Less-than-or-equal-to operator.
   */
  bool operator<=(const md5& other) const {
    return std::memcmp(_data, other._data, sizeof(_data)) <= 0;
  }

  /**
   * Greater-than operator.
   */
  bool operator>(const md5& other) const {
    return std::memcmp(_data, other._data, sizeof(_data)) > 0;
  }

  /**
   * Greater-than-or-equal-to operator.
   */
  bool operator>=(const md5& other) const {
    return std::memcmp(_data, other._data, sizeof(_data)) >= 0;
  }
};

#endif /* RFC1321_MD5_H */
