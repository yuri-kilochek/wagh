#ifndef WAGH_HEADER_INSTRUCTION_ITERATOR_HPP
#define WAGH_HEADER_INSTRUCTION_ITERATOR_HPP

#include <iterator>

#include <wagh/byte.hpp>
#include <wagh/detail/api.hpp>
#include <wagh/detail/version_namespace.hpp>

namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE {
///////////////////////////////////////////////////////////////////////////////

struct instruction;

struct WAGH_DETAIL_API instruction_iterator {
    using iterator_concept = std::input_iterator_tag;

    explicit
    instruction_iterator(byte const* ptr, byte const* end)
    : ptr_(ptr)
    , end_(end)
    {}

    friend
    auto operator==(instruction_iterator a, instruction_iterator b) {
        return a.ptr_ == b.ptr_;
    }

    auto operator*() const
    -> instruction;

    auto operator++()
    -> instruction_iterator&;

    auto operator++(int) {
        auto copy = *this;
        ++(*this);
        return copy;
    }

private:
    byte const* ptr_;
    byte const* end_;
};

///////////////////////////////////////////////////////////////////////////////
}  // namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE

#include <wagh/instruction.hpp>

#endif
