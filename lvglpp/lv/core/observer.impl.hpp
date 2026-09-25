#pragma once
// Bodies of core/observer.hpp, separated because its file cycle needs every type
// complete. Same mechanism as D-C7, applied where the graph asks for it.
// Included by the umbrella and never by a header: it is NOT a translation
// unit and every definition in it is `inline`. The stem says so, not the
// extension, so a glob written for *.hpp still installs it.

#include "lv/lvgl.hpp"

namespace lv {

#if LV_USE_OBSERVER
inline SubjectIncrementDsc Obj::add_subject_increment_event(Subject& subject, EventCode trigger, int32_t step) const noexcept { return SubjectIncrementDsc(p_, lv_obj_add_subject_increment_event(p_, subject.raw(), static_cast<lv_event_code_t>(trigger), step)); }
#endif // LV_USE_OBSERVER

#if (LV_USE_OBSERVER) && (LV_USE_FLOAT)
inline void Obj::add_subject_set_float_event(Subject& subject, EventCode trigger, float value) const noexcept { lv_obj_add_subject_set_float_event(p_, subject.raw(), static_cast<lv_event_code_t>(trigger), value); }
#endif // (LV_USE_OBSERVER) && (LV_USE_FLOAT)

#if LV_USE_OBSERVER
inline void Obj::add_subject_set_int_event(Subject& subject, EventCode trigger, int32_t value) const noexcept { lv_obj_add_subject_set_int_event(p_, subject.raw(), static_cast<lv_event_code_t>(trigger), value); }

inline void Obj::add_subject_set_string_event(Subject& subject, EventCode trigger, const char* value) const noexcept { lv_obj_add_subject_set_string_event(p_, subject.raw(), static_cast<lv_event_code_t>(trigger), value); }

inline void Obj::add_subject_toggle_event(Subject& subject, EventCode trigger) const noexcept { lv_obj_add_subject_toggle_event(p_, subject.raw(), static_cast<lv_event_code_t>(trigger)); }

inline Observer Obj::bind_checked(Subject& subject) const noexcept { return Observer(lv_obj_bind_checked(p_, subject.raw())); }

inline Observer Obj::bind_flag_if_eq(Subject& subject, ObjFlag flag, int32_t ref_value) const noexcept { return Observer(lv_obj_bind_flag_if_eq(p_, subject.raw(), static_cast<lv_obj_flag_t>(flag), ref_value)); }

inline Observer Obj::bind_flag_if_ge(Subject& subject, ObjFlag flag, int32_t ref_value) const noexcept { return Observer(lv_obj_bind_flag_if_ge(p_, subject.raw(), static_cast<lv_obj_flag_t>(flag), ref_value)); }

inline Observer Obj::bind_flag_if_gt(Subject& subject, ObjFlag flag, int32_t ref_value) const noexcept { return Observer(lv_obj_bind_flag_if_gt(p_, subject.raw(), static_cast<lv_obj_flag_t>(flag), ref_value)); }

inline Observer Obj::bind_flag_if_le(Subject& subject, ObjFlag flag, int32_t ref_value) const noexcept { return Observer(lv_obj_bind_flag_if_le(p_, subject.raw(), static_cast<lv_obj_flag_t>(flag), ref_value)); }

inline Observer Obj::bind_flag_if_lt(Subject& subject, ObjFlag flag, int32_t ref_value) const noexcept { return Observer(lv_obj_bind_flag_if_lt(p_, subject.raw(), static_cast<lv_obj_flag_t>(flag), ref_value)); }

inline Observer Obj::bind_flag_if_not_eq(Subject& subject, ObjFlag flag, int32_t ref_value) const noexcept { return Observer(lv_obj_bind_flag_if_not_eq(p_, subject.raw(), static_cast<lv_obj_flag_t>(flag), ref_value)); }

inline Observer Obj::bind_state_if_eq(Subject& subject, State state, int32_t ref_value) const noexcept { return Observer(lv_obj_bind_state_if_eq(p_, subject.raw(), static_cast<lv_state_t>(state), ref_value)); }

inline Observer Obj::bind_state_if_ge(Subject& subject, State state, int32_t ref_value) const noexcept { return Observer(lv_obj_bind_state_if_ge(p_, subject.raw(), static_cast<lv_state_t>(state), ref_value)); }

inline Observer Obj::bind_state_if_gt(Subject& subject, State state, int32_t ref_value) const noexcept { return Observer(lv_obj_bind_state_if_gt(p_, subject.raw(), static_cast<lv_state_t>(state), ref_value)); }

inline Observer Obj::bind_state_if_le(Subject& subject, State state, int32_t ref_value) const noexcept { return Observer(lv_obj_bind_state_if_le(p_, subject.raw(), static_cast<lv_state_t>(state), ref_value)); }

inline Observer Obj::bind_state_if_lt(Subject& subject, State state, int32_t ref_value) const noexcept { return Observer(lv_obj_bind_state_if_lt(p_, subject.raw(), static_cast<lv_state_t>(state), ref_value)); }

inline Observer Obj::bind_state_if_not_eq(Subject& subject, State state, int32_t ref_value) const noexcept { return Observer(lv_obj_bind_state_if_not_eq(p_, subject.raw(), static_cast<lv_state_t>(state), ref_value)); }

inline void Obj::remove_from_subject(Subject& subject) const noexcept { lv_obj_remove_from_subject(p_, subject.raw()); }

inline void* Observer::get_target() const noexcept { return lv_observer_get_target(p_); }

inline Obj Observer::get_target_obj() const noexcept { return Obj(lv_observer_get_target_obj(p_)); }

inline void* Observer::get_user_data() const noexcept { return lv_observer_get_user_data(p_); }

inline void Observer::remove() const noexcept { lv_observer_remove(p_); }

inline void SubjectIncrementDsc::set_subject_increment_event_max_value(int32_t max_value) const noexcept { lv_obj_set_subject_increment_event_max_value(owner_, p_, max_value); }

inline void SubjectIncrementDsc::set_subject_increment_event_min_value(int32_t min_value) const noexcept { lv_obj_set_subject_increment_event_min_value(owner_, p_, min_value); }

inline void SubjectIncrementDsc::set_subject_increment_event_rollover(bool rollover) const noexcept { lv_obj_set_subject_increment_event_rollover(owner_, p_, rollover); }
#endif // LV_USE_OBSERVER

} // namespace lv
