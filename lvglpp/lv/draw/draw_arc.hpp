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
 * Create an arc draw task.
 * @param layer  pointer to a layer
 * @param dsc  pointer to an initialized draw descriptor variable
 * @see lv_draw_arc
 */
inline void draw_arc(Layer& layer, DrawArcDsc& dsc) noexcept { lv_draw_arc(layer.raw(), dsc.raw()); }

/**
 * Get an area the should be invalidated when the arcs angle changed between start_angle and end_ange
 * @param x  the x coordinate of the center of the arc
 * @param y  the y coordinate of the center of the arc
 * @param radius  the radius of the arc
 * @param start_angle  the start angle of the arc (0 deg on the bottom, 90 deg on the right)
 * @param end_angle  the end angle of the arc
 * @param w  width of the arc
 * @param rounded  true: the arc is rounded
 * @return store the area to invalidate here
 * @see lv_draw_arc_get_area
 */
inline Area draw_arc_get_area(int32_t x, int32_t y, uint16_t radius, lv_value_precise_t start_angle, lv_value_precise_t end_angle, int32_t w, bool rounded) noexcept {
    lv_area_t area_out{};
    lv_draw_arc_get_area(x, y, radius, start_angle, end_angle, w, rounded, &area_out);
    return Area{area_out};
}

inline lv_draw_arc_dsc_t* DrawTask::get_arc_dsc() const noexcept { return lv_draw_task_get_arc_dsc(p_); }

} // namespace lv
