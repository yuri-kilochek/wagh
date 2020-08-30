#ifndef WAGH_HEADER_LIMITS_HPP
#define WAGH_HEADER_LIMITS_HPP

#include <optional>

#include <wagh/uint32.hpp>
#include <wagh/detail/api.hpp>
#include <wagh/detail/version_namespace.hpp>

namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE {
///////////////////////////////////////////////////////////////////////////////

struct WAGH_DETAIL_API limits {
    uint32 min;
    std::optional<uint32> max = std::nullopt;
};

///////////////////////////////////////////////////////////////////////////////
}  // namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE

#endif
