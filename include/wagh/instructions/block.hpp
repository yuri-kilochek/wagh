#ifndef WAGH_HEADER_INSTRUCTIONS_BLOCK_HPP
#define WAGH_HEADER_INSTRUCTIONS_BLOCK_HPP

#include <vector>
#include <utility>

#include <wagh/function_type.hpp>
#include <wagh/instruction.hpp>
#include <wagh/detail/api.hpp>
#include <wagh/detail/version_namespace.hpp>

namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE::instructions {
///////////////////////////////////////////////////////////////////////////////

struct instruction;

struct WAGH_DETAIL_API block {
    using allocator_type = std::pmr::polymorphic_allocator<>;

    function_type type;
    std::pmr::vector<instruction> body;

    block(function_type type,
          std::pmr::vector<instruction> body,
          allocator_type const& allocator = {})
    : type(std::move(type), allocator)
    , body(std::move(body), allocator)
    {}

    explicit
    block(allocator_type const& allocator)
    : type(allocator)
    , body(allocator)
    {}

    block(block&& other, allocator_type const& allocator)
    : type(std::move(other.type), allocator)
    , body(std::move(other.body), allocator)
    {}

    block(block const& other, allocator_type const& allocator)
    : type(other.type, allocator)
    , body(other.body, allocator)
    {}

    block() = default;

    auto get_allocator() const
    noexcept
    -> allocator_type
    { return type.get_allocator(); }
};

///////////////////////////////////////////////////////////////////////////////
}  // namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE::instructions

#endif
