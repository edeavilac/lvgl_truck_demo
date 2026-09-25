#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/draw/draw_buf.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

/**
 * Searches base[0] to base[n - 1] for an item that matches *key.
 * @param key  Pointer to item being searched for
 * @param base  Pointer to first element to search
 * @param n  Number of elements
 * @param size  Size of each element
 * @return a pointer to a matching item, or NULL if none exists.
 * @see lv_utils_bsearch
 */
inline void* utils_bsearch(const void* key, const void* base, size_t n, size_t size, int (*arg)(const void*, const void*)) noexcept { return lv_utils_bsearch(key, base, n, size, arg); }

/**
 * Reverse the order of the bytes in a 32-bit value.
 * @param x  a 32-bit value.
 * @return the value `x` with reversed byte-order.
 * @see lv_swap_bytes_32
 */
inline uint32_t utils_swap_bytes_32(uint32_t x) noexcept { return lv_swap_bytes_32(x); }

/**
 * Reverse the order of the bytes in a 16-bit value.
 * @param x  a 16-bit value.
 * @return the value `x` with reversed byte-order.
 * @see lv_swap_bytes_16
 */
inline uint16_t utils_swap_bytes_16(uint16_t x) noexcept { return lv_swap_bytes_16(x); }

inline Result DrawBuf::save_to_file(const char* path) const noexcept { return static_cast<Result>(lv_draw_buf_save_to_file(p_, path)); }

} // namespace lv
