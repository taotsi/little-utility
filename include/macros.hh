#ifndef MACROS_HH
#define MACROS_HH

#define DEFAULT_SPECIAL_FUNCTIONS(T)\
  T(const T&) = default;\
  T(T&&) = default;\
  T& operator=(const T&) = default;\
  T& operator=(T&&) = default;\
  ~T() = default;

#endif // MACROS_HH