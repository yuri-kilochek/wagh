#ifndef WAGH_HEADER_DETAIL_OS_HPP
#define WAGH_HEADER_DETAIL_OS_HPP

///////////////////////////////////////////////////////////////////////////////

#if defined(_WIN32) \
 || defined(_WIN64) \
 || defined(__WIN32__) \
 || defined(__TOS_WIN__) \
 || defined(__WINDOWS__)
    #define WAGH_DETAIL_OS_WINDOWS 1
#endif

///////////////////////////////////////////////////////////////////////////////

#endif
