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

/**
 * Fill an area
 * @param layer  pointer to a layer
 * @param dsc  pointer to an initialized draw descriptor variable
 * @param coords  the coordinates of the rectangle
 * @see lv_draw_fill
 */
inline void draw_fill(Layer& layer, DrawFillDsc& dsc, const Area& coords) noexcept { lv_draw_fill(layer.raw(), dsc.raw(), coords.ptr()); }

/**
 * Draw a border
 * @param layer  pointer to a layer
 * @param dsc  pointer to an initialized draw descriptor variable
 * @param coords  the coordinates of the rectangle
 * @see lv_draw_border
 */
inline void draw_border(Layer& layer, DrawBorderDsc& dsc, const Area& coords) noexcept { lv_draw_border(layer.raw(), dsc.raw(), coords.ptr()); }

/**
 * Draw a box shadow
 * @param layer  pointer to a layer
 * @param dsc  pointer to an initialized draw descriptor variable
 * @param coords  the coordinates of the rectangle
 * @see lv_draw_box_shadow
 */
inline void draw_box_shadow(Layer& layer, DrawBoxShadowDsc& dsc, const Area& coords) noexcept { lv_draw_box_shadow(layer.raw(), dsc.raw(), coords.ptr()); }

/**
 * The rectangle is a wrapper for fill, border, bg. image and box shadow.
 * Internally fill, border, image and box shadow draw tasks will be created.
 * @param layer  pointer to a layer
 * @param dsc  pointer to an initialized draw descriptor variable
 * @param coords  the coordinates of the rectangle
 * @see lv_draw_rect
 */
inline void draw_rect(Layer& layer, DrawRectDsc& dsc, const Area& coords) noexcept { lv_draw_rect(layer.raw(), dsc.raw(), coords.ptr()); }

inline lv_draw_border_dsc_t* DrawTask::get_border_dsc() const noexcept { return lv_draw_task_get_border_dsc(p_); }

inline lv_draw_box_shadow_dsc_t* DrawTask::get_box_shadow_dsc() const noexcept { return lv_draw_task_get_box_shadow_dsc(p_); }

inline lv_draw_fill_dsc_t* DrawTask::get_fill_dsc() const noexcept { return lv_draw_task_get_fill_dsc(p_); }

} // namespace lv
