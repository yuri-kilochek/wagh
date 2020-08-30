#ifndef WAGH_HEADER_DETAIL_ALLOCATOR_USER_HPP
#define WAGH_HEADER_DETAIL_ALLOCATOR_USER_HPP

#include <memory_resource>

#include <wagh/detail/api.hpp>
#include <wagh/detail/version_namespace.hpp>

namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE::detail {
///////////////////////////////////////////////////////////////////////////////

template <typename Derived>
struct WAGH_DETAIL_API allocator_user
{
    using allocator_type = std::pmr::polymorphic_allocator<>;

    explicit
    allocator_user(allocator_type const& allocator)
    noexcept
    : allocator_(allocator)
    {}

    allocator_user(Derived&&, allocator_type const& allocator)
    : allocator_(allocator)
    {}

    allocator_user(Derived const&, allocator_type const& allocator)
    : allocator_(allocator)
    {}

    allocator_user() = default;

    allocator_user(allocator_user&& other)
    noexcept
    : allocator_(other.allocator_)
    {}

    allocator_user(allocator_user const& other)
    : allocator_()
    {}

    auto operator=(allocator_user&&)
    noexcept
    -> allocator_user&
    { return *this; }

    auto operator=(allocator_user const&)
    -> allocator_user&
    { return *this; }

    auto get_allocator() const
    noexcept
    -> allocator_type
    { return allocator_; }

private:
    allocator_type allocator_;
};

///////////////////////////////////////////////////////////////////////////////
}  // namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE::detail

#endif
