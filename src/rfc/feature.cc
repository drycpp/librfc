/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "feature.h"

#include <cassert> /* for assert() */
#include <cstring> /* for std::strcmp() */

static const char* const rfc_feature_names[] = {
  "ascii",
#ifdef ENABLE_DEBUG
  "debug",
#endif
#ifndef DISABLE_UNICODE
  "unicode",
#endif
};

bool
rfc_feature_exists(const char* const feature_name) {
  assert(feature_name != nullptr);

  if (feature_name != nullptr) {
    for (const char* const rfc_feature_name : rfc_feature_names) {
      if (std::strcmp(rfc_feature_name, feature_name) == 0) {
        return true; /* found */
      }
    }
  }

  return false; /* not found */
}
