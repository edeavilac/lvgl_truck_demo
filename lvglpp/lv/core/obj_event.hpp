#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core.hpp"
#include "lv/core/obj.hpp"
#include "lv/core/obj_class.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/indev/indev.hpp"
#include "lv/misc/event.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

/**
 * Used by the widgets internally to call the ancestor widget types's event handler
 * @param class_p  pointer to the class of the widget (NOT the ancestor class)
 * @param e  pointer to the event descriptor
 * @return LV_RESULT_OK: the target object was not deleted in the event; LV_RESULT_INVALID: it was deleted in the event_code
 * @see lv_obj_event_base
 */
inline Result obj_event_base(ObjClass class_p, Event& e) noexcept { return static_cast<Result>(lv_obj_event_base(class_p.raw(), e.raw())); }

inline const lv_area_t* Event::get_cover_area() const noexcept { return lv_event_get_cover_area(p_); }

inline Obj Event::get_current_target_obj() const noexcept { return Obj(lv_event_get_current_target_obj(p_)); }

inline DrawTask Event::get_draw_task() const noexcept { return DrawTask(lv_event_get_draw_task(p_)); }

inline lv_hit_test_info_t* Event::get_hit_test_info() const noexcept { return lv_event_get_hit_test_info(p_); }

inline Indev Event::get_indev() const noexcept { return Indev(lv_event_get_indev(p_)); }

inline uint32_t Event::get_key() const noexcept { return lv_event_get_key(p_); }

inline lv_layer_t* Event::get_layer() const noexcept { return lv_event_get_layer(p_); }

inline const lv_area_t* Event::get_old_size() const noexcept { return lv_event_get_old_size(p_); }

inline State Event::get_prev_state() const noexcept { return static_cast<State>(lv_event_get_prev_state(p_)); }

inline int32_t Event::get_rotary_diff() const noexcept { return lv_event_get_rotary_diff(p_); }

inline lv_anim_t* Event::get_scroll_anim() const noexcept { return lv_event_get_scroll_anim(p_); }

inline lv_point_t* Event::get_self_size_info() const noexcept { return lv_event_get_self_size_info(p_); }

inline Obj Event::get_target_obj() const noexcept { return Obj(lv_event_get_target_obj(p_)); }

inline void Event::set_cover_res(CoverRes res) const noexcept { lv_event_set_cover_res(p_, static_cast<lv_cover_res_t>(res)); }

inline void Event::set_ext_draw_size(int32_t size) const noexcept { lv_event_set_ext_draw_size(p_, size); }

inline uint32_t Obj::get_event_count() const noexcept { return lv_obj_get_event_count(p_); }

inline EventDsc Obj::get_event_dsc(uint32_t index) const noexcept { return EventDsc(lv_obj_get_event_dsc(p_, index)); }

inline bool Obj::remove_event(uint32_t index) const noexcept { return lv_obj_remove_event(p_, index); }

inline uint32_t Obj::remove_event_cb(lv_event_cb_t event_cb) const noexcept { return lv_obj_remove_event_cb(p_, event_cb); }

inline uint32_t Obj::remove_event_cb_with_user_data(lv_event_cb_t event_cb, void* user_data) const noexcept { return lv_obj_remove_event_cb_with_user_data(p_, event_cb, user_data); }

inline bool Obj::remove_event_dsc(EventDsc dsc) const noexcept { return lv_obj_remove_event_dsc(p_, dsc.raw()); }

} // namespace lv
