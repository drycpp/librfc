/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "rfc/module.h"

#include "prelude.h"

const char* const rfc_module_names[] = {
  NULL
};

const unsigned int rfc_module_count =
  (sizeof(rfc_module_names) / sizeof(rfc_module_names[0])) - 1;

static int
rfc_module_index(const char* const module_name) {
  for (unsigned int i = 0; i < rfc_module_count; i++) {
    if (unlikely(str_equal(rfc_module_names[i], module_name))) {
      return i;
    }
  }
  return -1;
}

bool
rfc_module_enumerate(const char** const module_name) {
  validate_with_false_return(is_nonnull(module_name));

  if (is_null(*module_name)) {
    *module_name = rfc_module_names[0];
    return TRUE;
  }

  const int index = rfc_module_index(*module_name);
  if (index == -1) {
    *module_name = NULL;
    return (void)FAILURE(EINVAL), FALSE;
  }

  *module_name = rfc_module_names[index + 1];
  return is_nonnull(*module_name);
}

bool
rfc_module_exists(const char* const module_name) {
  validate_with_false_return(is_nonnull(module_name));

  return rfc_module_index(module_name) != -1;
}
