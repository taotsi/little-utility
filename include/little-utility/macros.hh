#ifndef MACROS_HH
#define MACROS_HH

#define DEFAULT_SPECIAL_FUNCTIONS(T)\
  T(const T&) = default;\
  T(T&&) = default;\
  T& operator=(const T&) = default;\
  T& operator=(T&&) = default;\
  ~T() = default;

#define __FILENAME__                                                       \
  (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 \
                                    : __FILE__)

#endif // MACROS_HH