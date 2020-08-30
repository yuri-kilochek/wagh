#include <wagh/decoding_error.hpp>

#include <utility>

namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE {
///////////////////////////////////////////////////////////////////////////////

decoding_error::decoding_error(std::string message, byte const* location)
: exception(std::move(message))
, location_(location)
{}

auto decoding_error::location() const
-> byte const* 
{ return location_; }

///////////////////////////////////////////////////////////////////////////////
}  // namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE
