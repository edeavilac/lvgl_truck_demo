#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core/obj.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_GRIDNAV
/**
 * Add grid navigation feature to an object. It expects the children to be arranged
 * into a grid-like layout. Although it's not required to have pixel perfect alignment.
 * This feature makes possible to use keys to navigate among the children and focus them.
 * The keys other than arrows and press/release related events
 * are forwarded to the focused child.
 * @param obj  pointer to an object on which navigation should be applied.
 * @param ctrl  control flags from `lv_gridnav_ctrl_t`.
 * @see lv_gridnav_add
 */
inline void gridnav_add(Obj obj, GridnavCtrl ctrl) noexcept { lv_gridnav_add(obj.raw(), static_cast<lv_gridnav_ctrl_t>(ctrl)); }

/**
 * Remove the grid navigation support from an object
 * @param obj  pointer to an object
 * @see lv_gridnav_remove
 */
inline void gridnav_remove(Obj obj) noexcept { lv_gridnav_remove(obj.raw()); }

/**
 * Manually focus an object on gridnav container
 * @param cont  pointer to a gridnav container
 * @param to_focus  pointer to an object to focus
 * @param anim_en  LV_ANIM_ON/OFF
 * @see lv_gridnav_set_focused
 */
inline void gridnav_set_focused(Obj cont, Obj to_focus, lv_anim_enable_t anim_en) noexcept { lv_gridnav_set_focused(cont.raw(), to_focus.raw(), anim_en); }
#endif // LV_USE_GRIDNAV

} // namespace lv
