/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "md5_digest.h"

#include <cstring> /* for std::strlen() */

using namespace rfc1321;

static_assert(sizeof(md5_digest) == md5_digest::size,
  "sizeof(rfc1321::md5_digest) != rfc1321::md5_digest::size");

md5_digest
md5_digest::compute(const char* const data) noexcept {
  return compute(reinterpret_cast<const std::uint8_t*>(data), std::strlen(data));
}

md5_digest
md5_digest::compute(const std::uint8_t* const data,
                    const std::size_t size) noexcept {
  md5_digest digest;

  (void)data, (void)size; // TODO

  return digest;
}
