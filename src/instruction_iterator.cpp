#include <wagh/instruction_iterator.hpp>

#include <wagh/decoding_error.hpp>
#include <wagh/skip_varuint32.hpp>

namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE {
///////////////////////////////////////////////////////////////////////////////

using namespace std::literals;

auto instruction_iterator::operator*() const
-> instruction
{
    return {};
}

auto instruction_iterator::operator++()
-> instruction_iterator&
{
    auto begin = ptr_;
    switch (*ptr_++)
    {
    case 0x00u:  // unreachable
    case 0x01u:  // nop
        break;

    case 0x02u:  // block
    case 0x03u:  // loop
        skip_block_type(ptr_, end_);
        while (*ptr_ != 0x0Bu) {
            ++(*this);
        }
        ++ptr_;
        break;

    case 0x04u:  // if
        skip_block_type(ptr_, end_);
        while (*ptr_ != 0x0Bu && *ptr_ != 0x05u) {
            ++(*this);
        }
        if (*ptr_ == 0x05u) {
            ++ptr_;
            while (*ptr_ != 0x0Bu) {
                ++(*this);
            }
        }
        ++ptr_;
        break;

    case 0x0Cu:  // br
    case 0x0Du:  // br_if
        skip_varuint32(ptr_, end_);  // label index
        break;

    case 0x0Eu:  // br_table
        for (auto label_count = parse_varuint32(ptr_, end_); label_count--; ) {
            skip_varuint32(ptr_, end_);  // label index
        }
        skip_varuint32(ptr_, end_);  // default label index
        break;

    case 0x0Fu:  // return
        break;

    case 0x10u:  // call
        skip_varuint32(ptr_, end_);  // function index
        break;

    case 0x11u:  // call_indirect
        try {
            skip_varuint32(ptr_, end_);  // function type index
            if (*ptr_ != 0x00u) {
                throw decoding_error(
                    "expected `0x00`:`byte` after function type index"s, ptr_);
            }
            ++ptr_;
            break;
        } catch (...) {
            std::rethrow_with_nested(decoding_error(
                "failed to decode `call_indirect`"s, begin));
        }

    case 0x1Au:  // drop
    case 0x1Bu:  // select
        break;

    case 0x20u:  // local.get
    case 0x21u:  // local.set
    case 0x22u:  // local.tee
        skip_varuint32(ptr_, end_);  // local variable index
        break;

    case 0x23u:  // global.get
    case 0x24u:  // global.set
        skip_varuint32(ptr_, end_);  // global variable index
        break;

    case 0x28u:  // i32.load
    case 0x29u:  // i64.load
    case 0x2Au:  // f32.load
    case 0x2Bu:  // f64.load
    case 0x2Cu:  // i32.load8_s
    case 0x2Du:  // i32.load8_u
    case 0x2Eu:  // i32.load16_s
    case 0x2Fu:  // i32.load16_u
    case 0x30u:  // i64.load8_s
    case 0x31u:  // i64.load8_u
    case 0x32u:  // i64.load16_s
    case 0x33u:  // i64.load16_u
    case 0x34u:  // i64.load32_s
    case 0x35u:  // i64.load32_u
    case 0x36u:  // i32.store
    case 0x37u:  // i64.store
    case 0x38u:  // f32.store
    case 0x39u:  // f64.store
    case 0x3Au:  // i32.store8
    case 0x3Bu:  // i32.store16
    case 0x3Cu:  // i64.store8
    case 0x3Du:  // i64.store16
    case 0x3Eu:  // i64.store32
        skip_varuint32(ptr_, end_);  // alignment
        skip_varuint32(ptr_, end_);  // offset
        break;

    }
    return *this;
}

///////////////////////////////////////////////////////////////////////////////
}  // namespace wagh::inline WAGH_DETAIL_VERSION_NAMESPACE
