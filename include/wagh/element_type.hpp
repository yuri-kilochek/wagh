#ifndef WAGH_HEADER_ELEMENT_TYPE_HPP
#define WAGH_HEADER_ELEMENT_TYPE_HPP

#include <wagh/byte.hpp>
#include <wagh/detail/version_namespace.hpp>

namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE {
///////////////////////////////////////////////////////////////////////////////

enum class element_type
: byte
{
    function_reference = 0x70u,
};

///////////////////////////////////////////////////////////////////////////////
}  // namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE

#endif
