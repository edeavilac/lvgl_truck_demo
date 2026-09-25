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
 * Create a line draw task
 * @param layer  pointer to a layer
 * @param dsc  pointer to an initialized `lv_draw_line_dsc_t` variable
 * @see lv_draw_line
 */
inline void draw_line(Layer& layer, DrawLineDsc& dsc) noexcept { lv_draw_line(layer.raw(), dsc.raw()); }

/**
 * A helper function to call a callback which draws a line between two points.
 * This way it doesn't matter if ``p1, p2`` or ``points`` were used as it calls the
 * ``callback`` as needed.
 * @param t  draw task
 * @param dsc  pointer to a draw descriptor
 * @see lv_draw_line_iterate
 */
inline void draw_line_iterate(DrawTask t, DrawLineDsc& dsc, void (*arg)(lv_draw_task_t*, const lv_draw_line_dsc_t*)) noexcept { lv_draw_line_iterate(t.raw(), dsc.raw(), arg); }

inline lv_draw_line_dsc_t* DrawTask::get_line_dsc() const noexcept { return lv_draw_task_get_line_dsc(p_); }

} // namespace lv
