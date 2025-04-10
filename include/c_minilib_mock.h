#ifndef C_MINILIB_MOCK_H
#define C_MINILIB_MOCK_H

#ifdef DEBUG
#define MOCKABLE(...)                                                          \
  __attribute__((noinline)) __attribute__((weak)) __VA_ARGS__
#else
#define MOCKABLE(...) __VA_ARGS__
#endif

#endif // C_MINILIB_MOCK_H
