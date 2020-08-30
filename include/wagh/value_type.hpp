#ifndef WAGH_HEADER_VALUE_TYPE_HPP
#define WAGH_HEADER_VALUE_TYPE_HPP

#include <wagh/byte.hpp>
#include <wagh/detail/version_namespace.hpp>

namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE {
///////////////////////////////////////////////////////////////////////////////

enum class value_type
: byte
{
    i32 = 0x7Fu,
    i64 = 0x7Eu,
    f32 = 0x7Du,
    f64 = 0x7Cu,
};

///////////////////////////////////////////////////////////////////////////////
}  // namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE

#endif
