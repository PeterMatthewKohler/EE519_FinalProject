#ifndef FP_MSGS__VISIBILITY_CONTROL_H_
#define FP_MSGS__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define FP_MSGS_EXPORT __attribute__ ((dllexport))
    #define FP_MSGS_IMPORT __attribute__ ((dllimport))
  #else
    #define FP_MSGS_EXPORT __declspec(dllexport)
    #define FP_MSGS_IMPORT __declspec(dllimport)
  #endif
  #ifdef FP_MSGS_BUILDING_LIBRARY
    #define FP_MSGS_PUBLIC FP_MSGS_EXPORT
  #else
    #define FP_MSGS_PUBLIC FP_MSGS_IMPORT
  #endif
  #define FP_MSGS_PUBLIC_TYPE FP_MSGS_PUBLIC
  #define FP_MSGS_LOCAL
#else
  #define FP_MSGS_EXPORT __attribute__ ((visibility("default")))
  #define FP_MSGS_IMPORT
  #if __GNUC__ >= 4
    #define FP_MSGS_PUBLIC __attribute__ ((visibility("default")))
    #define FP_MSGS_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define FP_MSGS_PUBLIC
    #define FP_MSGS_LOCAL
  #endif
  #define FP_MSGS_PUBLIC_TYPE
#endif
#endif  // FP_MSGS__VISIBILITY_CONTROL_H_
// Generated 26-Apr-2023 20:05:22
 