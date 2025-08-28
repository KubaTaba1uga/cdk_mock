/*
 * Copyright (c) 2025 Jakub Buczynski <KubaTaba1uga>
 * SPDX-License-Identifier: MIT
 * See LICENSE file in the project root for full license information.
 */
#ifndef CDK_MOCK_H
#define CDK_MOCK_H

/*
  Use this macro to mock global functions.
 */
#ifdef CDK_MOCK_ENABLE
#define CDKM_MOCKABLE(...) __attribute__((noinline, weak)) __VA_ARGS__
#else
#define CDKM_MOCKABLE(...) __VA_ARGS__
#endif

/*
  Use this macro to mock static functions.
  Watch out, using this macro makes static function globally visible!
 */
#ifdef CDK_MOCK_ENABLE
#define CDKM_MOCKABLE_STATIC(...) CDKM_MOCKABLE(__VA_ARGS__)
#else
#define CDKM_MOCKABLE_STATIC(...) static __VA_ARGS__
#endif

/*
  Use this macro if you need orginal function in tests.
 */
#ifdef CDK_MOCK_ENABLE
#define CDKM_MOCKABLE_DUPLICATE(function_name)                                 \
  __typeof__(function_name) function_name##_orig                               \
      __attribute__((weak, alias(#function_name)))
#else
#define CDKM_MOCKABLE_DUPLICATE(function_name)
#endif

#endif // CDK_MOCK_H
