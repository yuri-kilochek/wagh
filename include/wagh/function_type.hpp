#ifndef WAGH_HEADER_FUNCTION_TYPE_HPP
#define WAGH_HEADER_FUNCTION_TYPE_HPP

#include <vector>
#include <utility>

#include <wagh/value_type.hpp>
#include <wagh/detail/api.hpp>
#include <wagh/detail/version_namespace.hpp>

namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE {
///////////////////////////////////////////////////////////////////////////////

struct WAGH_DETAIL_API function_type {
    using allocator_type = std::pmr::polymorphic_allocator<>;

    std::pmr::vector<value_type> parameters;
    std::pmr::vector<value_type> results;

    function_type(std::pmr::vector<value_type> parameters,
                  std::pmr::vector<value_type> results,
                  allocator_type const& allocator = {})
    : parameters(std::move(parameters), allocator)
    , results(std::move(results), allocator)
    {}

    explicit
    function_type(allocator_type const& allocator)
    : parameters(allocator)
    , results(allocator)
    {}

    function_type() = default;

    function_type(function_type&& other, allocator_type const& allocator)
    : parameters(std::move(other.parameters), allocator)
    , results(std::move(other.results), allocator)
    {}

    function_type(function_type const& other, allocator_type const& allocator)
    : parameters(other.parameters, allocator)
    , results(other.results, allocator)
    {}
};

///////////////////////////////////////////////////////////////////////////////
}  // namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE

#endif
