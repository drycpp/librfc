/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "json_writer.h"

#include <cassert> /* for assert() */
#include <cstdio>  /* for fflush() */

using namespace rfc4627;

json_writer&
json_writer::flush() {
  if (fflush(_stream) != 0) {
    // TODO: error handling
  }
  return *this;
}
