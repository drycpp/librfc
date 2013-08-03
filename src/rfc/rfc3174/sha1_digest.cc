/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "sha1_digest.h"

#include <cstring> /* for std::strlen() */

using namespace rfc3174;

static_assert(sizeof(sha1_digest) == sha1_digest::size,
  "sizeof(rfc3174::sha1_digest) != rfc3174::sha1_digest::size");

sha1_digest
sha1_digest::compute(const char* const data) noexcept {
  return compute(reinterpret_cast<const std::uint8_t*>(data), std::strlen(data));
}

sha1_digest
sha1_digest::compute(const std::uint8_t* const data,
                     const std::size_t size) noexcept {
  sha1_digest digest;

  (void)data, (void)size; // TODO

  return digest;
}
