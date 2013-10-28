/* This is free and unencumbered software released into the public domain. */

#ifndef RFC_UTIL_STR_H
#define RFC_UTIL_STR_H

/**
 * @file
 */

#include <cstddef>   /* for std::size_t */
#include <cstring>   /* for std::mem*(), std::str*() */
#include <stdexcept> /* for std::out_of_range */
#include <string>    /* for std::string */

namespace rfc {
  class str;
}

/**
 * C string wrapper class.
 *
 * @note Instances of this class are movable, but not copyable.
 */
class rfc::str {
  char* _data = nullptr;

public:
  /**
   * Maximum value for `std::size_t`.
   */
  static constexpr std::size_t npos = static_cast<std::size_t>(-1);

  /**
   * Default constructor.
   */
  str() noexcept {}

  /**
   * Constructor.
   */
  explicit str(const std::string& string) noexcept
    : _data(const_cast<char*>(string.data())) {}

  /**
   * Constructor.
   */
  explicit str(char* data) noexcept
    : _data(data) {}

  /**
   * Constructor.
   */
  explicit str(const char* data) noexcept
    : _data(const_cast<char*>(data)) {}

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

  /**
   * @name Iterators
   */

  /**@{*/

  /**
   * Returns a const-qualified iterator to the beginning of this string.
   */
  inline const char* cbegin() const noexcept {
    return begin();
  }

  /**
   * Returns a const-qualified iterator to the end of this string.
   */
  inline const char* cend() const noexcept {
    return end();
  }

  /**
   * Returns an iterator to the beginning of this string.
   */
  inline char* begin() noexcept {
    return _data;
  }

  /**
   * Returns a const-qualified iterator to the beginning of this string.
   */
  inline const char* begin() const noexcept {
    return _data;
  }

  /**
   * Returns an iterator to the end of this string.
   */
  inline char* end() noexcept {
    return _data + size();
  }

  /**
   * Returns a const-qualified iterator to the end of this string.
   */
  inline const char* end() const noexcept {
    return _data + size();
  }

  /**@}*/

  /**
   * @name Capacity
   */

  /**@{*/

  /**
   * Tests whether this string is empty.
   *
   * The string is empty in case the data pointer is `nullptr` or the first
   * character of the string is NUL.
   */
  inline bool empty() const noexcept {
    return _data == nullptr || _data[0] == '\0';
  }

  /**
   * Clears this string by resetting the data pointer to `nullptr`.
   */
  inline void clear() noexcept {
    _data = nullptr;
  }

  /**
   * Returns the byte length of this string.
   */
  inline std::size_t length() const noexcept {
    return size();
  }

  /**
   * Returns the byte length of this string.
   */
  inline std::size_t size() const noexcept {
    return _data ? std::strlen(_data) : 0;
  }

  /**@}*/

  /**
   * @name Element access
   */

  /**@{*/

  /**
   * Alias for `data()`.
   */
  inline const char* c_str() const noexcept {
    return _data;
  }

  /**
   * Returns a pointer to the underlying C string data.
   */
  inline const char* data() const noexcept {
    return _data;
  }

  /**
   * ...
   */
  inline char& operator[](std::size_t pos) noexcept {
    return _data[pos];
  }

  /**
   * ...
   */
  inline const char& operator[](std::size_t pos) const noexcept {
    return _data[pos];
  }

  /**
   * @throws std::out_of_range if `pos` >= `size()`
   */
  inline char& at(std::size_t pos) {
    if (pos >= size()) throw std::out_of_range("pos >= size()");
    return _data[pos];
  }

  /**
   * @throws std::out_of_range if `pos` >= `size()`
   */
  inline const char& at(std::size_t pos) const {
    if (pos >= size()) throw std::out_of_range("pos >= size()");
    return _data[pos];
  }

  /**
   * ...
   */
  inline char& back() noexcept {
    return _data[size() - 1];
  }

  /**
   * ...
   */
  inline const char& back() const noexcept {
    return _data[size() - 1];
  }

  /**
   * ...
   */
  inline char& front() noexcept {
    return _data[0];
  }

  /**
   * ...
   */
  inline const char& front() const noexcept {
    return _data[0];
  }

  /**@}*/

  /**
   * @name Mutative operations
   */

  /**@{*/

  /**
   * Erases the last character of this string.
   */
  inline void pop_back() noexcept {
    _data[size() - 1] = '\0';
  }

  /**@}*/

  /**
   * @name String operations
   */

  /**@{*/

  /**
   * Compares this string to another sequence of characters.
   */
  inline int compare(const std::string& other) const noexcept {
    return compare(other.data());
  }

  /**
   * Compares this string to another sequence of characters.
   */
  inline int compare(const str& other) const noexcept {
    return compare(other.data());
  }

  /**
   * Compares this string to another sequence of characters.
   */
  inline int compare(const char* other) const noexcept {
    return std::strcmp(_data, other);
  }

  /**
   * Copies a sequence of characters into a given buffer.
   */
  inline void copy(char* target, std::size_t length, std::size_t pos = 0) const {
    std::strncpy(target, _data + pos, length);
  }

  /**
   * Finds the first occurrence of the given character.
   */
  inline std::size_t find(char c) const noexcept {
    const char* const pos = std::strchr(_data, c);
    return pos ? pos - _data : npos;
  }

  /**
   * Finds the last occurrence of the given character.
   */
  inline std::size_t rfind(char c) const noexcept {
    const char* const pos = std::strrchr(_data, c);
    return pos ? pos - _data : npos;
  }

  /**
   * Returns a substring of this string.
   */
  inline str substr(std::size_t pos) const noexcept {
    return str(_data + pos);
  }

  /**@}*/
};

#endif /* RFC_UTIL_STR_H */
