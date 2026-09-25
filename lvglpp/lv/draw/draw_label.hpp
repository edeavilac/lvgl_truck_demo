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

/**
 * Create a draw task to render a text
 * @param layer  pointer to a layer
 * @param dsc  pointer to draw descriptor
 * @param coords  coordinates of the character
 * @see lv_draw_label
 */
inline void draw_label(Layer& layer, DrawLabelDsc& dsc, const Area& coords) noexcept { lv_draw_label(layer.raw(), dsc.raw(), coords.ptr()); }

/**
 * Create a draw task to render a single character
 * @param layer  pointer to a layer
 * @param dsc  pointer to draw descriptor
 * @param point  position of the label
 * @param unicode_letter  the letter to draw
 * @see lv_draw_character
 */
inline void draw_character(Layer& layer, DrawLabelDsc& dsc, const Point& point, uint32_t unicode_letter) noexcept { lv_draw_character(layer.raw(), dsc.raw(), point.ptr(), unicode_letter); }

/**
 * Draw a single letter
 * @param layer  pointer to a layer
 * @param dsc  pointer to draw descriptor
 * @param point  position of the label
 * @see lv_draw_letter
 */
inline void draw_letter(Layer& layer, DrawLetterDsc& dsc, const Point& point) noexcept { lv_draw_letter(layer.raw(), dsc.raw(), point.ptr()); }

/**
 * Should be used during rendering the characters to get the position and other
 * parameters of the characters
 * @param t  pointer to a draw task
 * @param dsc  pointer to draw descriptor
 * @param coords  coordinates of the label
 * @param cb  a callback to call to draw each glyphs one by one
 * @see lv_draw_label_iterate_characters
 */
inline void draw_label_iterate_characters(DrawTask t, DrawLabelDsc& dsc, const Area& coords, lv_draw_glyph_cb_t cb) noexcept { lv_draw_label_iterate_characters(t.raw(), dsc.raw(), coords.ptr(), cb); }

/**
 * Draw a single letter using the provided draw unit, glyph descriptor, position, font, and callback.
 * This function is responsible for rendering a single character from a text string,
 * applying the necessary styling described by the glyph descriptor (`dsc`). It handles
 * the retrieval of the glyph's description, checks its visibility within the clipping area,
 * and invokes the callback (`cb`) to render the glyph at the specified position (`pos`)
 * using the given font (`font`).
 * @param t  Pointer to the drawing task.
 * @param dsc  Pointer to the descriptor containing styling for the glyph to be drawn.
 * @param pos  Pointer to the point coordinates where the letter should be drawn.
 * @param font  Pointer to the font containing the glyph.
 * @param letter  The Unicode code point of the letter to be drawn.
 * @param cb  Callback function to execute the actual rendering of the glyph.
 * @see lv_draw_unit_draw_letter
 */
inline void draw_unit_draw_letter(DrawTask t, DrawGlyphDsc dsc, const Point& pos, Font font, uint32_t letter, lv_draw_glyph_cb_t cb) noexcept { lv_draw_unit_draw_letter(t.raw(), dsc.raw(), pos.ptr(), font.raw(), letter, cb); }

inline void DrawGlyphDsc::init() const noexcept { lv_draw_glyph_dsc_init(p_); }

inline lv_draw_label_dsc_t* DrawTask::get_label_dsc() const noexcept { return lv_draw_task_get_label_dsc(p_); }

} // namespace lv
