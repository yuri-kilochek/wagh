#ifndef WAGH_HEADER_DETAIL_VERSION_NAMESPACE_HPP
#define WAGH_HEADER_DETAIL_VERSION_NAMESPACE_HPP

#include <wagh/version.hpp>
#include <wagh/detail/pp/join.hpp>

///////////////////////////////////////////////////////////////////////////////

#define WAGH_DETAIL_VERSION_NAMESPACE \
    WAGH_DETAIL_PP_JOIN(v, WAGH_VERSION_MAJOR) \
//

///////////////////////////////////////////////////////////////////////////////

#endif
