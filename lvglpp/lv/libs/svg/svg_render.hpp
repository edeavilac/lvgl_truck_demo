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

#if LV_USE_SVG
/**
 * Initialize the SVG render
 * @param hal  pointer to a structure with rendering functions
 * @see lv_svg_render_init
 */
inline void svg_render_init(const lv_svg_render_hal_t* hal) noexcept { lv_svg_render_init(hal); }

/**
 * Create a new SVG render from an SVG document
 * @param svg_doc  pointer to the SVG document
 * @return pointer to the new SVG render object
 * @see lv_svg_render_create
 */
inline lv_svg_render_obj_t* svg_render_create(SvgNode svg_doc) noexcept { return lv_svg_render_create(svg_doc.raw()); }

/**
 * Delete an SVG render object
 * @param render  pointer to the SVG render object to delete
 * @see lv_svg_render_delete
 */
inline void svg_render_delete(lv_svg_render_obj_t* render) noexcept { lv_svg_render_delete(render); }

/**
 * Get size of render objects
 * @param render  pointer to the SVG render object
 * @return the bytes of SVG render objects
 * @see lv_svg_render_get_size
 */
inline uint32_t svg_render_get_size(const lv_svg_render_obj_t* render) noexcept { return lv_svg_render_get_size(render); }

/**
 * Get viewport's width and height of the render object
 * @param render  pointer to the SVG render object
 * @param width  pointer to save the width of the viewport of the SVG render object
 * @param height  pointer to save the height of the viewport of the SVG render object
 * @return lv_result_t, LV_RESULT_OK if success, LV_RESULT_INVALID if fail
 * @see lv_svg_render_get_viewport_size
 */
inline Result svg_render_get_viewport_size(const lv_svg_render_obj_t* render, float* width, float* height) noexcept { return static_cast<Result>(lv_svg_render_get_viewport_size(render, width, height)); }
#endif // LV_USE_SVG

#if (LV_USE_SVG) && (LV_USE_VECTOR_GRAPHIC)
/**
 * Render an SVG object to a vector graphics
 * @param dsc  pointer to the vector graphics descriptor
 * @param render  pointer to the SVG render object to render
 * @see lv_draw_svg_render
 */
inline void draw_svg_render(DrawVectorDsc dsc, const lv_svg_render_obj_t* render) noexcept { lv_draw_svg_render(dsc.raw(), render); }
#endif // (LV_USE_SVG) && (LV_USE_VECTOR_GRAPHIC)

#if LV_USE_SVG
/**
 * Draw an SVG document to a layer
 * @param layer  pointer to the target layer
 * @param svg_doc  pointer to the SVG document to draw
 * @see lv_draw_svg
 */
inline void draw_svg(Layer& layer, SvgNode svg_doc) noexcept { lv_draw_svg(layer.raw(), svg_doc.raw()); }
#endif // LV_USE_SVG

} // namespace lv
