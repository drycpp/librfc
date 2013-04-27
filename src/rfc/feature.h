/* This is free and unencumbered software released into the public domain. */

#ifndef RFC_FEATURE_H
#define RFC_FEATURE_H

/**
 * @file
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h> /* for bool */

/**
 * Determines whether librfc supports a given feature.
 */
bool rfc_feature_exists(const char* feature_name);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* RFC_FEATURE_H */
