#ifndef WAGH_HEADER_INSTRUCTIONS_NOP_HPP
#define WAGH_HEADER_INSTRUCTIONS_NOP_HPP

#include <wagh/detail/allocator_user.hpp>
#include <wagh/detail/api.hpp>
#include <wagh/detail/version_namespace.hpp>

namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE::instructions {
///////////////////////////////////////////////////////////////////////////////

struct WAGH_DETAIL_API nop
: detail::allocator_user<nop>
{
    using detail::allocator_user<nop>::allocator_user;
};

///////////////////////////////////////////////////////////////////////////////
}  // namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE::instructions

#endif
