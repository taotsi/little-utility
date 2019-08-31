#ifndef MACROS_HH
#define MACROS_HH

#include <cstring>

#define DEFAULT_SPECIAL_FUNCTIONS(T)\
  T(const T&) = default;\
  T(T&&) = default;\
  T& operator=(const T&) = default;\
  T& operator=(T&&) = default;\
  ~T() = default;

#define DELETE_COPY_MOVE(T)\
  T(const T&) = delete;\
  T(T&&) = delete;\
  T& operator=(const T&) = delete;\
  T& operator=(T&&) = delete;

#ifndef __FILENAME__
#ifdef __linux__
  #define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#elif _WIN32
  #define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#else
  #define __FILENAME__ __FILE__
#endif
#endif

#define VAR_NAME(var) static_cast<std::string>(#var)

#endif // MACROS_HH