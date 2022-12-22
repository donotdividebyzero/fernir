#ifndef __THOR_CORE_H
#define __THOR_CORE_H

#define DEBUG 1
#ifdef DEBUG
#define ASSERT(x) if (!(x)) __builtin_debugtrap()
#else
#define ASSERT(x)
#endif

#if defined(_WIN32) && defined(_THOR_BUILD_DLL)
 #define THAPI __declspec(dllexport)
#elif defined(_WIN32) && defined(THOR_DLL)
 #define THAPI __declspec(dllimport)
#elif defined(__GNUC__) && defined(_THOR_BUILD_DLL)
 #define THAPI __attribute__((visibility("default")))
#else
 #define THAPI
#endif

#endif