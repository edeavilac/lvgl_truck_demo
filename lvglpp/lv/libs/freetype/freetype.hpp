#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core.hpp"
#include "lv/enums.hpp"
#include "lv/font/font.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_FREETYPE
/** @see lv_freetype_font_class */
inline constexpr const lv_font_class_t* freetype_font_class = &lv_freetype_font_class;

/**
 * Initialize the freetype library.
 * @return LV_RESULT_OK on success, otherwise LV_RESULT_INVALID.
 * @see lv_freetype_init
 */
inline Result freetype_init(uint32_t max_glyph_cnt) noexcept { return static_cast<Result>(lv_freetype_init(max_glyph_cnt)); }

/**
 * Uninitialize the freetype library
 * @see lv_freetype_uninit
 */
inline void freetype_uninit() noexcept { lv_freetype_uninit(); }

/**
 * Initialize a font info structure.
 * @param font_info  font info structure to be initialized.
 * @see lv_freetype_init_font_info
 */
inline void freetype_init_font_info(FontInfo font_info) noexcept { lv_freetype_init_font_info(font_info.raw()); }

/**
 * Create a freetype font with a font info structure.
 * @param font_info  font info structure.
 * @return Created font, or NULL on failure.
 * @see lv_freetype_font_create_with_info
 */
inline Font freetype_font_create_with_info(FontInfo font_info) noexcept { return Font(lv_freetype_font_create_with_info(font_info.raw())); }

/**
 * Create a freetype font.
 * @param pathname  font file path.
 * @param render_mode  font render mode(see @lv_freetype_font_render_mode_t for details).
 * @param size  font size.
 * @param style  font style(see lv_freetype_font_style_t for details).
 * @return Created font, or NULL on failure.
 * @see lv_freetype_font_create
 */
inline Font freetype_font_create(const char* pathname, FreetypeFontRenderMode render_mode, uint32_t size, FreetypeFontStyle style) noexcept { return Font(lv_freetype_font_create(pathname, static_cast<lv_freetype_font_render_mode_t>(render_mode), size, static_cast<lv_freetype_font_style_t>(style))); }

/**
 * Delete a freetype font.
 * @param font  freetype font to be deleted.
 * @see lv_freetype_font_delete
 */
inline void freetype_font_delete(Font font) noexcept { lv_freetype_font_delete(font.raw()); }

/**
 * Register a callback function to generate outlines for FreeType fonts.
 * @param user_data  User data to be passed to the callback function.
 * @see lv_freetype_outline_add_event
 */
inline void freetype_outline_add_event(lv_event_cb_t event_cb, EventCode filter, void* user_data) noexcept { lv_freetype_outline_add_event(event_cb, static_cast<lv_event_code_t>(filter), user_data); }

/**
 * Get the scale of a FreeType font.
 * @param font  The FreeType font to get the scale of.
 * @return The scale of the FreeType font.
 * @see lv_freetype_outline_get_scale
 */
inline uint32_t freetype_outline_get_scale(Font font) noexcept { return lv_freetype_outline_get_scale(font.raw()); }

/**
 * Check if the font is an outline font.
 * @param font  The FreeType font.
 * @return Is outline font on success, otherwise false.
 * @see lv_freetype_is_outline_font
 */
inline bool freetype_is_outline_font(Font font) noexcept { return lv_freetype_is_outline_font(font.raw()); }
#endif // LV_USE_FREETYPE

} // namespace lv
