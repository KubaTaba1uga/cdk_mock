#ifndef C_MINILIB_MOCK_H
#define C_MINILIB_MOCK_H

#ifdef DEBUG
#define MOCKABLE(...)                                                          \
  __attribute__((noinline)) __attribute__((weak)) __VA_ARGS__
#else
#define MOCKABLE(...) __VA_ARGS__
#endif

/* Watch out, using this macro makes static function globally visible!
 */
#ifdef DEBUG
#define MOCKABLE_STATIC(...) MOCKABLE(__VA_ARGS__)
#else
#define MOCKABLE_STATIC(...) static __VA_ARGS__
#endif

#endif // C_MINILIB_MOCK_H
