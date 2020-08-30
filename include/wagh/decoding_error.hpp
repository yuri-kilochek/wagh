#ifndef WAGH_HEADER_DECODING_ERROR_HPP
#define WAGH_HEADER_DECODING_ERROR_HPP

#include <string>

#include <wagh/exception.hpp>
#include <wagh/byte.hpp>
#include <wagh/detail/api.hpp>
#include <wagh/detail/version_namespace.hpp>

namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE {
///////////////////////////////////////////////////////////////////////////////

struct WAGH_DETAIL_API decoding_error
: virtual exception
{
    explicit
    decoding_error(std::string message, byte const* location);

    auto location() const
    -> byte const*;

private:
    byte const* location_;
};

///////////////////////////////////////////////////////////////////////////////
}  // namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE

#endif
