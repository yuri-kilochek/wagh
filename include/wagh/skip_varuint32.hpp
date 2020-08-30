#ifndef WAGH_HEADER_SKIP_VARUINT32_HPP
#define WAGH_HEADER_SKIP_VARUINT32_HPP

#include <wagh/byte.hpp>
#include <wagh/decoding_error.hpp>
#include <wagh/detail/api.hpp>
#include <wagh/detail/version_namespace.hpp>

namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE {
///////////////////////////////////////////////////////////////////////////////

using namespace std::literals;

inline WAGH_DETAIL_API
void skip_varuint32(byte const*& ptr, byte const* end) {
    if (ptr == end) {
        throw decoding_error("expected LEB128-encoded `u32`"s, ptr);
    }
    auto begin = ptr;
    while (*ptr & 0b1000'0000) {
        ++ptr;
        if (ptr == end) {
            throw decoding_error(
                "expected more bytes of LEB128-encoded `u32`"s, ptr);
        }
    }
    if (size == 5) {
        throw decoding_error(
            "LEB128-encoded `u32`"s, ptr);
    }
    ++ptr;
}

///////////////////////////////////////////////////////////////////////////////
}  // namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE

#include <wagh/instruction.hpp>

#endif
