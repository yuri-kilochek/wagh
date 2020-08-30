#include <wagh/exception.hpp>

#include <utility>

namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE {
///////////////////////////////////////////////////////////////////////////////

exception::exception(std::string message)
: message_(std::move(message))
{}

auto exception::message() const
noexcept
-> std::string const&
{ return message_; }

auto exception::what() const
noexcept
-> char const*
{ return message_.data(); }

///////////////////////////////////////////////////////////////////////////////
}  // namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE
