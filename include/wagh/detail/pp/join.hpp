#ifndef WAGH_HEADER_DETAIL_PP_JOIN_HPP
#define WAGH_HEADER_DETAIL_PP_JOIN_HPP

///////////////////////////////////////////////////////////////////////////////

#define WAGH_DETAIL_PP_JOIN_IMPL(a, b) \
    a ## b                             \
//

#define WAGH_DETAIL_PP_JOIN(a, b)  \
    WAGH_DETAIL_PP_JOIN_IMPL(a, b) \
//

///////////////////////////////////////////////////////////////////////////////

#endif
