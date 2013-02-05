/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "rfc/feature.h"

#include "prelude.h"

const char* const rfc_feature_names[] = {
  "ascii",
#ifndef NDEBUG
  "debug",
#endif
#ifndef DISABLE_UNICODE
  "unicode",
#endif
  NULL
};

const unsigned int rfc_feature_count =
  (sizeof(rfc_feature_names) / sizeof(rfc_feature_names[0])) - 1;

static int
rfc_feature_index(const char* const feature_name) {
  for (unsigned int i = 0; i < rfc_feature_count; i++) {
    if (unlikely(str_equal(rfc_feature_names[i], feature_name))) {
      return i;
    }
  }
  return -1;
}

bool
rfc_feature_enumerate(const char** const feature_name) {
  validate_with_false_return(is_nonnull(feature_name));

  if (is_null(*feature_name)) {
    *feature_name = rfc_feature_names[0];
    return TRUE;
  }

  const int index = rfc_feature_index(*feature_name);
  if (index == -1) {
    *feature_name = NULL;
    return (void)FAILURE(EINVAL), FALSE;
  }

  *feature_name = rfc_feature_names[index + 1];
  return is_nonnull(*feature_name);
}

bool
rfc_feature_exists(const char* const feature_name) {
  validate_with_false_return(is_nonnull(feature_name));

  return rfc_feature_index(feature_name) != -1;
}
