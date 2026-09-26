#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core.hpp"
#include "lv/core/obj.hpp"
#include "lv/display/display.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/misc/timer.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

/**
 * Redraw the invalidated areas now.
 * Normally the redrawing is periodically executed in `lv_timer_handler` but a long blocking process
 * can prevent the call of `lv_timer_handler`. In this case if the GUI is updated in the process
 * (e.g. progress bar) this function can be called when the screen should be updated.
 * @param disp  pointer to display to refresh. NULL to refresh all displays.
 * @see lv_refr_now
 */
inline void refr_now(Display disp) noexcept { lv_refr_now(disp.raw()); }

/**
 * Redrawn on object and all its children using the passed draw context
 * @param layer  pointer to a layer where to draw.
 * @param obj  the start object from the redraw should start
 * @see lv_obj_redraw
 */
inline void obj_redraw(Layer& layer, Obj obj) noexcept { lv_obj_redraw(layer.raw(), obj.raw()); }

/**
 * Called periodically to handle the refreshing
 * @param timer  pointer to the timer itself, or `NULL`
 * @see lv_display_refr_timer
 */
inline void display_refr_timer(Timer timer) noexcept { lv_display_refr_timer(timer.raw()); }

} // namespace lv
