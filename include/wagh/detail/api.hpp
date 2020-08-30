#ifndef WAGH_HEADER_DETAIL_API_HPP
#define WAGH_HEADER_DETAIL_API_HPP

#include <wagh/detail/os.hpp>

///////////////////////////////////////////////////////////////////////////////

#if WAGH_USE_DYNAMIC && WAGH_BUILD_DYNAMIC
    #error WAGH_USE_DYNAMIC and WAGH_BUILD_DYNAMIC must not be set \
        simultaneously.
#endif

#if WAGH_DETAIL_OS_WINDOWS
    #if WAGH_USE_DYNAMIC
        #define WAGH_DETAIL_API __declspec(dllimport)
    #elif WAGH_BUILD_DYNAMIC
        #define WAGH_DETAIL_API __declspec(dllexport)
    #else
        #define WAGH_DETAIL_API 
    #endif
#else
    #if WAGH_BUILD_DYNAMIC
        #define WAGH_DETAIL_API __attribute__((visibility("default")))
    #else
        #define WAGH_DETAIL_API
    #endif
#endif

///////////////////////////////////////////////////////////////////////////////

#endif
