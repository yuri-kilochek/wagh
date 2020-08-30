#ifndef WAGH_HEADER_MODULE_HPP
#define WAGH_HEADER_MODULE_HPP

#include <span>

#include <wagh/function_type.hpp>
#include <wagh/value_type.hpp>
#include <wagh/detail/api.hpp>
#include <wagh/detail/version_namespace.hpp>

namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE {
///////////////////////////////////////////////////////////////////////////////

struct WAGH_DETAIL_API module {
    std::pmr::vector<function> functions;

private:
    std::span<byte const> bytes_;
    std::pmr::vector<value_type> local_variable_types_;
};

///////////////////////////////////////////////////////////////////////////////
}  // namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE

#endif
