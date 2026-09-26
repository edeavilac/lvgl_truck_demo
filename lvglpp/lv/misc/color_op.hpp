#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

/**
 * @param fg  
 * @param bg  
 * @see lv_color_mix32
 */
inline lv_color32_t color_mix32(lv_color32_t fg, lv_color32_t bg) noexcept { return lv_color_mix32(fg, bg); }

/**
 * Blends two premultiplied ARGB8888 colors while maintaining correct alpha compositing.
 * This function correctly blends the foreground (fg) and background (bg) colors,
 * ensuring that the output remains in a premultiplied alpha format.
 * @param fg  The foreground color in premultiplied ARGB8888 format.
 * @param bg  The background color in premultiplied ARGB8888 format.
 * @return The resulting blended color in premultiplied ARGB8888 format.
 * @see lv_color_mix32_premultiplied
 */
inline lv_color32_t color_mix32_premultiplied(lv_color32_t fg, lv_color32_t bg) noexcept { return lv_color_mix32_premultiplied(fg, bg); }

/**
 * Get the brightness of a color
 * @param c  a color
 * @return brightness in range [0..255]
 * @see lv_color_brightness
 */
inline uint8_t color_brightness(Color c) noexcept { return lv_color_brightness(c.raw()); }

/**
 * Blend two colors that have not been pre-multiplied using their alpha values
 * @param fg  the foreground color
 * @param bg  the background color
 * @return result color
 * @see lv_color_over32
 */
inline lv_color32_t color_over32(lv_color32_t fg, lv_color32_t bg) noexcept { return lv_color_over32(fg, bg); }

} // namespace lv
