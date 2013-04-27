/* This is free and unencumbered software released into the public domain. */

#ifndef RFC_MODULE_H
#define RFC_MODULE_H

/**
 * @file
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h> /* for bool */

/**
 * Determines whether librfc includes a given module.
 */
bool rfc_module_exists(const char* module_name);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* RFC_MODULE_H */
