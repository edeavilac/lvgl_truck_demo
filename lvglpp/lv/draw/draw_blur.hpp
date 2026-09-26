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
 * Create a blur draw task
 * @param layer  pointer to a layer
 * @param dsc  pointer to an initialized `lv_draw_blur_dsc_t` variable
 * @param coords  coordinates of the character
 * @see lv_draw_blur
 */
inline void draw_blur(Layer& layer, DrawBlurDsc& dsc, const Area& coords) noexcept { lv_draw_blur(layer.raw(), dsc.raw(), coords.ptr()); }

inline lv_draw_blur_dsc_t* DrawTask::get_blur_dsc() const noexcept { return lv_draw_task_get_blur_dsc(p_); }

} // namespace lv
