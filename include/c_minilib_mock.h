#ifndef C_MINILIB_MOCK_H
#define C_MINILIB_MOCK_H

#ifdef ENABLE_MOCKS
#define MOCKABLE(...) __attribute__((noinline, weak)) __VA_ARGS__
#else
#define MOCKABLE(...) __VA_ARGS__
#endif

/* Watch out, using this macro makes static function globally visible!
 */
#ifdef ENABLE_MOCKS
#define MOCKABLE_STATIC(...) MOCKABLE(__VA_ARGS__)
#else
#define MOCKABLE_STATIC(...) static __VA_ARGS__
#endif

/* This macro is usefull if you need orginal function in tests.
 */
#ifdef ENABLE_MOCKS
#define MOCKABLE_DUPLICATE(function_name)                                      \
  __typeof__(function_name) function_name##_orig                               \
      __attribute__((weak, alias(#function_name)))
#else
#define MOCKABLE_DUPLICATE(function_name)
#endif

#endif // C_MINILIB_MOCK_H
