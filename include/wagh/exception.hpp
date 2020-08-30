#ifndef WAGH_HEADER_EXCEPTION_HPP
#define WAGH_HEADER_EXCEPTION_HPP

#include <exception>
#include <string>

#include <wagh/detail/api.hpp>
#include <wagh/detail/version_namespace.hpp>

namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE {
///////////////////////////////////////////////////////////////////////////////

struct WAGH_DETAIL_API exception
: virtual std::exception
{
    explicit
    exception(std::string message);

    auto message() const
    noexcept
    -> std::string const&;

    auto what() const
    noexcept
    -> char const*
    override;

private:
    std::string message_;
};

///////////////////////////////////////////////////////////////////////////////
}  // namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE

#endif
