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
 * Create a triangle draw task
 * @param layer  pointer to a layer
 * @param draw_dsc  pointer to an initialized `lv_draw_triangle_dsc_t` object
 * @see lv_draw_triangle
 */
inline void draw_triangle(Layer& layer, DrawTriangleDsc& draw_dsc) noexcept { lv_draw_triangle(layer.raw(), draw_dsc.raw()); }

inline lv_draw_triangle_dsc_t* DrawTask::get_triangle_dsc() const noexcept { return lv_draw_task_get_triangle_dsc(p_); }

} // namespace lv
