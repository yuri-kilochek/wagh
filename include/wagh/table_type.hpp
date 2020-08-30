#ifndef WAGH_HEADER_TABLE_TYPE_HPP
#define WAGH_HEADER_TABLE_TYPE_HPP

#include <wagh/limits.hpp>
#include <wagh/element_type.hpp>
#include <wagh/detail/api.hpp>
#include <wagh/detail/version_namespace.hpp>

namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE {
///////////////////////////////////////////////////////////////////////////////

struct WAGH_DETAIL_API table_type {
    wagh::limits limits;
    element_type element;
};

///////////////////////////////////////////////////////////////////////////////
}  // namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE

#endif
