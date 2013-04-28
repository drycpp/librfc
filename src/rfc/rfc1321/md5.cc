/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "md5.h"

#include <cstring> /* for std::strlen() */

using namespace rfc1321;

static_assert(sizeof(md5) == 16, "sizeof(rfc1321::md5) != 16");

md5
md5::compute(const char* const data) noexcept {
  return md5::compute(reinterpret_cast<const std::uint8_t*>(data), std::strlen(data));
}

md5
md5::compute(const std::uint8_t* const data,
             const std::size_t size) noexcept {
  md5 digest;

  (void)data, (void)size; // TODO

  return digest;
}
