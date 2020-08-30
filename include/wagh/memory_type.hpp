#ifndef WAGH_HEADER_MEMORY_TYPE_HPP
#define WAGH_HEADER_MEMORY_TYPE_HPP

#include <wagh/limits.hpp>
#include <wagh/detail/api.hpp>
#include <wagh/detail/version_namespace.hpp>

namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE {
///////////////////////////////////////////////////////////////////////////////

struct WAGH_DETAIL_API memory_type {
    wagh::limits limits;
};

///////////////////////////////////////////////////////////////////////////////
}  // namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE

#endif
