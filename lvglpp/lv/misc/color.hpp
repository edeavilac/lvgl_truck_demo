#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

/** @see lv_color_filter_shade */
inline constexpr const lv_color_filter_dsc_t* color_filter_shade = &lv_color_filter_shade;

/**
 * Get the pixel size of a color format in bits, bpp
 * @param cf  a color format (`LV_COLOR_FORMAT_...`)
 * @return the pixel size in bits
 * @see lv_color_format_get_bpp
 */
inline uint8_t color_format_get_bpp(ColorFormat cf) noexcept { return lv_color_format_get_bpp(static_cast<lv_color_format_t>(cf)); }

/**
 * Get the pixel size of a color format in bytes
 * @param cf  a color format (`LV_COLOR_FORMAT_...`)
 * @return the pixel size in bytes
 * @see lv_color_format_get_size
 */
inline uint8_t color_format_get_size(ColorFormat cf) noexcept { return lv_color_format_get_size(static_cast<lv_color_format_t>(cf)); }

/**
 * Check if a color format has alpha channel or not
 * @param src_cf  a color format (`LV_COLOR_FORMAT_...`)
 * @return true: has alpha channel; false: doesn't have alpha channel
 * @see lv_color_format_has_alpha
 */
inline bool color_format_has_alpha(ColorFormat src_cf) noexcept { return lv_color_format_has_alpha(static_cast<lv_color_format_t>(src_cf)); }

/**
 * Create an ARGB8888 color from RGB888 + alpha
 * @param color  an RGB888 color
 * @param opa  the alpha value
 * @return the ARGB8888 color
 * @see lv_color_to_32
 */
inline lv_color32_t color_to_32(Color color, lv_opa_t opa) noexcept { return lv_color_to_32(color.raw(), opa); }

/**
 * Convert an RGB888 color to an integer
 * @param c  an RGB888 color
 * @return `c` as an integer
 * @see lv_color_to_int
 */
inline uint32_t color_to_int(Color c) noexcept { return lv_color_to_int(c.raw()); }

/**
 * Check if two RGB888 color are equal
 * @param c1  the first color
 * @param c2  the second color
 * @return true: equal
 * @see lv_color_eq
 */
inline bool color_eq(Color c1, Color c2) noexcept { return lv_color_eq(c1.raw(), c2.raw()); }

/**
 * Check if two ARGB8888 color are equal
 * @param c1  the first color
 * @param c2  the second color
 * @return true: equal
 * @see lv_color32_eq
 */
inline bool color32_eq(lv_color32_t c1, lv_color32_t c2) noexcept { return lv_color32_eq(c1, c2); }

/**
 * Create an ARGB8888 color
 * @param r  the red channel (0..255)
 * @param g  the green channel (0..255)
 * @param b  the blue channel (0..255)
 * @param a  the alpha channel (0..255)
 * @return the color
 * @see lv_color32_make
 */
inline lv_color32_t color32_make(uint8_t r, uint8_t g, uint8_t b, uint8_t a) noexcept { return lv_color32_make(r, g, b, a); }

/**
 * Check if a color with an RGB888 color is within the color range defined by l_color and h_color.
 * @param color  the color to check
 * @param l_color  the lower bound color
 * @param h_color  the upper bound color
 * @return true: pixel is within the color range
 * @see lv_color_is_in_range
 */
inline bool color_is_in_range(Color color, Color l_color, Color h_color) noexcept { return lv_color_is_in_range(color.raw(), l_color.raw(), h_color.raw()); }

/**
 * Convert a RGB565 color to RGB888
 * @param c  a RGB565 color on lv_color16_t
 * @return the color
 * @see lv_color16_to_color
 */
inline Color color16_to_color(lv_color16_t c) noexcept { return Color{lv_color16_to_color(c)}; }

/**
 * Convert am RGB888 color to RGB565 stored in `uint16_t`
 * @param color  and RGB888 color
 * @return `color` as RGB565 on `uin16_t`
 * @see lv_color_to_u16
 */
inline uint16_t color_to_u16(Color color) noexcept { return lv_color_to_u16(color.raw()); }

/**
 * Convert am RGB888 color to XRGB8888 stored in `uint32_t`
 * @param color  and RGB888 color
 * @return `color` as XRGB8888 on `uin32_t` (the alpha channel is always set to 0xFF)
 * @see lv_color_to_u32
 */
inline uint32_t color_to_u32(Color color) noexcept { return lv_color_to_u32(color.raw()); }

/**
 * Mix two RGB565 colors
 * @param c1  the first color (typically the foreground color)
 * @param c2  the second color (typically the background color)
 * @param mix  0..255, or LV_OPA_0/10/20...
 * @return mix == 0: c2 mix == 255: c1 mix == 128: 0.5 x c1 + 0.5 x c2
 * @see lv_color_16_16_mix
 */
inline uint16_t color_16_16_mix(uint16_t c1, uint16_t c2, uint8_t mix) noexcept { return lv_color_16_16_mix(c1, c2, mix); }

/**
 * Convert a HSV color to RGB
 * @param h  hue [0..359]
 * @param s  saturation [0..100]
 * @param v  value [0..100]
 * @return the given RGB color in RGB (with LV_COLOR_DEPTH depth)
 * @see lv_color_hsv_to_rgb
 */
inline Color color_hsv_to_rgb(uint16_t h, uint8_t s, uint8_t v) noexcept { return Color{lv_color_hsv_to_rgb(h, s, v)}; }

/**
 * Convert a 32-bit RGB color to HSV
 * @param r8  8-bit red
 * @param g8  8-bit green
 * @param b8  8-bit blue
 * @return the given RGB color in HSV
 * @see lv_color_rgb_to_hsv
 */
inline lv_color_hsv_t color_rgb_to_hsv(uint8_t r8, uint8_t g8, uint8_t b8) noexcept { return lv_color_rgb_to_hsv(r8, g8, b8); }

/**
 * Convert a color to HSV
 * @param color  color
 * @return the given color in HSV
 * @see lv_color_to_hsv
 */
inline lv_color_hsv_t color_to_hsv(Color color) noexcept { return lv_color_to_hsv(color.raw()); }

/** @see lv_color_premultiply */
inline void color_premultiply(lv_color32_t* c) noexcept { lv_color_premultiply(c); }

/**
 * Get the luminance of a color: luminance = 0.3 R + 0.59 G + 0.11 B
 * @param c  a color
 * @return the brightness [0..255]
 * @see lv_color_luminance
 */
inline uint8_t color_luminance(Color c) noexcept { return lv_color_luminance(c.raw()); }

/**
 * Get the luminance of a color16: luminance = 0.3 R + 0.59 G + 0.11 B
 * @param c  a color
 * @return the brightness [0..255]
 * @see lv_color16_luminance
 */
inline uint8_t color16_luminance(const lv_color16_t c) noexcept { return lv_color16_luminance(c); }

/**
 * Get the luminance of a color24: luminance = 0.3 R + 0.59 G + 0.11 B
 * @param c  a color
 * @return the brightness [0..255]
 * @see lv_color24_luminance
 */
inline uint8_t color_color24_luminance(const uint8_t* c) noexcept { return lv_color24_luminance(c); }

/**
 * Get the luminance of a color32: luminance = 0.3 R + 0.59 G + 0.11 B
 * @param c  a color
 * @return the brightness [0..255]
 * @see lv_color32_luminance
 */
inline uint8_t color32_luminance(lv_color32_t c) noexcept { return lv_color32_luminance(c); }

/**
 * Swap the endianness of an rgb565 color
 * @param c  a color
 * @return the swapped color
 * @see lv_color_swap_16
 */
inline uint16_t color_swap_16(uint16_t c) noexcept { return lv_color_swap_16(c); }

inline void Color16::premultiply(lv_opa_t a) const noexcept { lv_color16_premultiply(p_, a); }

} // namespace lv
