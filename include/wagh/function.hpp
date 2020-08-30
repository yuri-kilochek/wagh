#ifndef WAGH_HEADER_FUNCTION_HPP
#define WAGH_HEADER_FUNCTION_HPP

#include <vector>
#include <utility>

#include <wagh/function_type.hpp>
#include <wagh/value_type.hpp>
#include <wagh/instruction.hpp>
#include <wagh/detail/api.hpp>
#include <wagh/detail/version_namespace.hpp>

namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE {
///////////////////////////////////////////////////////////////////////////////

struct WAGH_DETAIL_API function {
    using allocator_type = std::pmr::polymorphic_allocator<>;

    function_type type;
    std::pmr::vector<value_type> local_variable_types;
    std::pmr::vector<instruction> body;

    function(function_type type,
             std::pmr::vector<value_type> local_variable_types,
             std::pmr::vector<instruction> body,
             allocator_type const& allocator = {})
    : type(std::move(type), allocator)
    , local_variable_types(std::move(local_variable_types), allocator)
    , body(std::move(body), allocator)
    {}

    explicit
    function(allocator_type const& allocator)
    : type(allocator)
    , local_variable_types(allocator)
    , body(allocator)
    {}

    function() = default;

    function(function&& other, allocator_type const& allocator)
    : type(std::move(other.type), allocator)
    , local_variable_types(std::move(other.local_variable_types), allocator)
    , body(std::move(other.body), allocator)
    {}

    function(function const& other, allocator_type const& allocator)
    : type(other.type, allocator)
    , local_variable_types(other.local_variable_types, allocator)
    , body(other.body, allocator)
    {}
};

///////////////////////////////////////////////////////////////////////////////
}  // namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE

#endif
