#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/draw/draw_buf.hpp"
#include "lv/enums.hpp"
#include "lv/font/font.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

/** @see lv_builtin_font_class */
inline constexpr const lv_font_class_t* font_fmt_txt_builtin_font_class = &lv_builtin_font_class;

/**
 * Used as `get_glyph_bitmap` callback in lvgl's native font format if the font is uncompressed.
 * @param g_dsc  the glyph descriptor including which font to use, which supply the glyph_index and format.
 * @param draw_buf  a draw buffer that can be used to store the bitmap of the glyph, it's OK not to use it.
 * @return pointer to an A8 bitmap (not necessarily bitmap_out) or NULL if `unicode_letter` not found
 * @see lv_font_get_bitmap_fmt_txt
 */
inline const void* font_get_bitmap_fmt_txt(lv_font_glyph_dsc_t* g_dsc, DrawBuf draw_buf) noexcept { return lv_font_get_bitmap_fmt_txt(g_dsc, draw_buf.raw()); }

inline bool Font::get_glyph_dsc_fmt_txt(lv_font_glyph_dsc_t* dsc_out, uint32_t unicode_letter, uint32_t unicode_letter_next) const noexcept { return lv_font_get_glyph_dsc_fmt_txt(p_, dsc_out, unicode_letter, unicode_letter_next); }

} // namespace lv
