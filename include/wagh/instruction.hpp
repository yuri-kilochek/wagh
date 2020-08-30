#ifndef WAGH_HEADER_INSTRUCTION_HPP
#define WAGH_HEADER_INSTRUCTION_HPP

#include <concepts>
#include <variant>
#include <memory>
#include <memory_resource>

#include <wagh/instructions/unreachable.hpp>
#include <wagh/instructions/nop.hpp>
#include <wagh/instructions/block.hpp>

#include <wagh/detail/api.hpp>
#include <wagh/detail/version_namespace.hpp>

namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE {
///////////////////////////////////////////////////////////////////////////////

namespace detail {
    using instruction_base = std::variant<
        instructions::unreachable,
        instructions::nop,
        instructions::block
    >;
}  // namespace detail

struct WAGH_DETAIL_API instruction
: detail::instruction_base
{
    using allocator_type = std::pmr::polymorphic_allocator<>;

    template <typename... Args, std::constructible_from<Args...> Instruction>
    instruction(std::allocator_arg_t, allocator_type const& allocator,
                std::in_place_type_t<Instruction>, Args&&... args)
    : instruction(

            )
    {}

    template <std::convertible_to<detail::instruction_base> Instruction>
    instruction(Instruction&& other, allocator_type const& allocator = {})
    : instruction(std::allocator_arg, allocator,
                  std::in_place_type<std::remove_cvref_t<Instruction>>,
                  std::forward<Instruction>(other))
    {}

    explicit
    instruction(allocator_type const& allocator)
    : instruction(std::allocator_arg, allocator, std::in_place_index<0>)
    {}

    instruction(instruction&& other, allocator_type const& allocator)
    : instruction(std::visit([&](auto&& other) {
          return instruction(std::move(other), allocator);
      }, std::move(other)))
    {}

    instruction(instruction const& other, allocator_type const& allocator)
    : instruction(std::visit([&](auto const& other) {
          return instruction(other, allocator);
      }, other))
    {}

    instruction() = default;

    auto get_allocator() const
    noexcept
    -> allocator_type
    {
        return std::visit([](auto const& self) {
            return self.get_allocator();
        }, *this);
    }
};

///////////////////////////////////////////////////////////////////////////////
}  // namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE

#endif
