/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "module.h"

#include <cassert> /* for assert() */
#include <cstring> /* for std::strcmp() */

static const char* const rfc_module_names[] = {
#ifndef DISABLE_RFC1321
  "rfc1321", /* MD5 */
#endif
#ifndef DISABLE_RFC2616
  "rfc2616", /* HTTP/1.1 */
#endif
#ifndef DISABLE_RFC3174
  "rfc3174", /* SHA-1 */
#endif
#ifndef DISABLE_RFC3629
  "rfc3629", /* UTF-8 */
#endif
#ifndef DISABLE_RFC3986
  "rfc3986", /* URI */
#endif
#ifndef DISABLE_RFC4122
  "rfc4122", /* UUID */
#endif
#ifndef DISABLE_RFC4627
  "rfc4627", /* JSON */
#endif
};

bool
rfc_module_exists(const char* const module_name) {
  assert(module_name != nullptr);

  if (module_name != nullptr) {
    for (const char* const rfc_module_name : rfc_module_names) {
      if (std::strcmp(rfc_module_name, module_name) == 0) {
        return true; /* found */
      }
    }
  }

  return false; /* not found */
}
