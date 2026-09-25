#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_RLE
/** @see lv_rle_decompress */
inline uint32_t rle_decompress(const uint8_t* input, uint32_t input_buff_len, uint8_t* output, uint32_t output_buff_len, uint8_t blk_size) noexcept { return lv_rle_decompress(input, input_buff_len, output, output_buff_len, blk_size); }
#endif // LV_USE_RLE

} // namespace lv
