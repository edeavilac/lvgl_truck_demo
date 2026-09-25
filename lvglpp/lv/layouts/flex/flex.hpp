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

#if LV_USE_FLEX
/**
 * Initialize a flex layout to default values
 * @see lv_flex_init
 */
inline void flex_init() noexcept { lv_flex_init(); }
#endif // LV_USE_FLEX

#if LV_USE_FLEX
inline void Obj::set_flex_align(FlexAlign main_place, FlexAlign cross_place, FlexAlign track_cross_place) const noexcept { lv_obj_set_flex_align(p_, static_cast<lv_flex_align_t>(main_place), static_cast<lv_flex_align_t>(cross_place), static_cast<lv_flex_align_t>(track_cross_place)); }

inline void Obj::set_flex_flow(FlexFlow flow) const noexcept { lv_obj_set_flex_flow(p_, static_cast<lv_flex_flow_t>(flow)); }

inline void Obj::set_flex_grow(uint8_t grow) const noexcept { lv_obj_set_flex_grow(p_, grow); }
#endif // LV_USE_FLEX

} // namespace lv
