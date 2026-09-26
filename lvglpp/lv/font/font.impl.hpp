#pragma once
// Bodies of font/font.hpp, separated because its file cycle needs every type
// complete. Same mechanism as D-C7, applied where the graph asks for it.
// Included by the umbrella and never by a header: it is NOT a translation
// unit and every definition in it is `inline`. The stem says so, not the
// extension, so a glob written for *.hpp still installs it.

#include "lv/lvgl.hpp"

namespace lv {

inline bool FontInfo::is_equal(FontInfo ft_info_2) const noexcept { return lv_font_info_is_equal(p_, ft_info_2.raw()); }

inline bool Font::get_glyph_dsc(lv_font_glyph_dsc_t* dsc_out, uint32_t letter, uint32_t letter_next) const noexcept { return lv_font_get_glyph_dsc(p_, dsc_out, letter, letter_next); }

inline uint16_t Font::get_glyph_width(uint32_t letter, uint32_t letter_next) const noexcept { return lv_font_get_glyph_width(p_, letter, letter_next); }

inline int32_t Font::get_line_height() const noexcept { return lv_font_get_line_height(p_); }

inline bool Font::has_static_bitmap() const noexcept { return lv_font_has_static_bitmap(p_); }

inline void Font::set_kerning(FontKerning kerning) const noexcept { lv_font_set_kerning(p_, static_cast<lv_font_kerning_t>(kerning)); }

inline const void* font_get_glyph_bitmap(lv_font_glyph_dsc_t* g_dsc, DrawBuf draw_buf) noexcept { return lv_font_get_glyph_bitmap(g_dsc, draw_buf.raw()); }

inline const void* font_get_glyph_static_bitmap(lv_font_glyph_dsc_t* g_dsc) noexcept { return lv_font_get_glyph_static_bitmap(g_dsc); }

inline void font_glyph_release_draw_data(lv_font_glyph_dsc_t* g_dsc) noexcept { lv_font_glyph_release_draw_data(g_dsc); }

inline Font font_get_default() noexcept { return Font(const_cast<lv_font_t*>(lv_font_get_default())); }

} // namespace lv
