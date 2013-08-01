/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "sha1.h"

#include <cstring> /* for std::strlen() */

using namespace rfc3174;

static_assert(sizeof(sha1) == sha1::size, "sizeof(rfc3174::sha1) != rfc3174::sha1::size");

sha1
sha1::compute(const char* const data) noexcept {
  return compute(reinterpret_cast<const std::uint8_t*>(data), std::strlen(data));
}

sha1
sha1::compute(const std::uint8_t* const data,
              const std::size_t size) noexcept {
  sha1 digest;

  (void)data, (void)size; // TODO

  return digest;
}
