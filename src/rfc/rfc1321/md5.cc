/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "md5.h"

using namespace rfc1321;

static_assert(sizeof(md5) == 16, "sizeof(rfc1321::md5) != 16");
