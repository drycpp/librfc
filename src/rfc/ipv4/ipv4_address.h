/* This is free and unencumbered software released into the public domain. */

#ifndef RFC_IPV4_ADDRESS_H
#define RFC_IPV4_ADDRESS_H

/**
 * @file
 */

#include <cstddef> /* for std::size_t */
#include <cstdint> /* for std::uint8_t */
#include <cstring> /* for std::memcmp(), std::memset() */
#include <utility> /* for std::swap() */

namespace rfc791 {
  class ipv4_address;
}

/**
 * Represents an Internet Protocol version 4 (IPv4) address.
 */
class rfc791::ipv4_address {
protected:
  std::uint8_t _octets[4] = {0, 0, 0, 0};

public:
  static constexpr std::size_t size = 4; /* 4 bytes (32 bits) */

  /**
   * Default constructor. The address is all zeroes after construction.
   */
  inline ipv4_address() noexcept {}

  /**
   * Constructor.
   */
  inline ipv4_address(const std::uint8_t octet1,
                      const std::uint8_t octet2,
                      const std::uint8_t octet3,
                      const std::uint8_t octet4) noexcept
    : _octets{octet1, octet2, octet3, octet4} {}

  /**
   * Copy constructor.
   */
  inline ipv4_address(const ipv4_address& other) noexcept {
    *_octets = *other._octets;
  }

  /**
   * Move constructor.
   */
  inline ipv4_address(ipv4_address&& other) noexcept {
    std::swap(_octets, other._octets);
  }

  /**
   * Destructor.
   */
  inline ~ipv4_address() noexcept = default;

  /**
   * Copy assignment operator.
   */
  inline ipv4_address& operator=(ipv4_address other) noexcept {
    std::swap(_octets, other._octets);
    return *this;
  }

  /**
   * Move assignment operator.
   */
  inline ipv4_address& operator=(ipv4_address&& other) noexcept {
    std::swap(_octets, other._octets);
    return *this;
  }

  /**
   * Equality operator.
   */
  inline bool operator==(const ipv4_address& other) const {
    return compare(other) == 0;
  }

  /**
   * Inequality operator.
   */
  inline bool operator!=(const ipv4_address& other) const {
    return compare(other) != 0;
  }

  /**
   * Less-than operator.
   */
  inline bool operator<(const ipv4_address& other) const {
    return compare(other) < 0;
  }

  /**
   * Less-than-or-equal-to operator.
   */
  inline bool operator<=(const ipv4_address& other) const {
    return compare(other) <= 0;
  }

  /**
   * Greater-than operator.
   */
  inline bool operator>(const ipv4_address& other) const {
    return compare(other) > 0;
  }

  /**
   * Greater-than-or-equal-to operator.
   */
  inline bool operator>=(const ipv4_address& other) const {
    return compare(other) >= 0;
  }

  /**
   * Returns a reference to the octet at the given position.
   */
  inline std::uint8_t& operator[](const std::size_t position) noexcept {
    return _octets[position];
  }

  /**
   * Returns a reference to the octet at the given position.
   */
  inline const std::uint8_t& operator[](const std::size_t position) const noexcept {
    return _octets[position];
  }

  /**
   * Returns a pointer to the octet data.
   */
  inline std::uint8_t* data() {
    return _octets;
  }

  /**
   * Returns a pointer to the octet data.
   */
  inline const std::uint8_t* data() const {
    return _octets;
  }

  /**
   * Compares this address to the given other address.
   */
  inline int compare(const ipv4_address& other) const noexcept {
    return std::memcmp(_octets, other._octets, sizeof(_octets));
  }

  /**
   * Clears this address to be all zeroes.
   */
  inline void clear() noexcept {
    std::memset(_octets, 0, sizeof(_octets));
  }

  /**
   * Exchanges this address with the given other address.
   */
  inline void swap(ipv4_address& other) noexcept {
    std::swap(_octets, other._octets);
  }
};

#endif /* RFC_IPV4_ADDRESS_H */
