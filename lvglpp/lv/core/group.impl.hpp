#pragma once
// Bodies of core/group.hpp, separated because its file cycle needs every type
// complete. Same mechanism as D-C7, applied where the graph asks for it.
// Included by the umbrella and never by a header: it is NOT a translation
// unit and every definition in it is `inline`. The stem says so, not the
// extension, so a glob written for *.hpp still installs it.

#include "lv/lvgl.hpp"

namespace lv {

inline void Group::add_obj(Obj obj) const noexcept { lv_group_add_obj(p_, obj.raw()); }

inline Group Group::create() noexcept { return Group(lv_group_create()); }

inline void Group::delete_() const noexcept { lv_group_delete(p_); }

inline void Group::focus_freeze(bool en) const noexcept { lv_group_focus_freeze(p_, en); }

inline void Group::focus_next() const noexcept { lv_group_focus_next(p_); }

inline void Group::focus_prev() const noexcept { lv_group_focus_prev(p_); }

inline lv_group_edge_cb_t Group::get_edge_cb() const noexcept { return lv_group_get_edge_cb(p_); }

inline bool Group::get_editing() const noexcept { return lv_group_get_editing(p_); }

inline lv_group_focus_cb_t Group::get_focus_cb() const noexcept { return lv_group_get_focus_cb(p_); }

inline Obj Group::get_focused() const noexcept { return Obj(lv_group_get_focused(p_)); }

inline Obj Group::get_obj_by_index(uint32_t index) const noexcept { return Obj(lv_group_get_obj_by_index(p_, index)); }

inline uint32_t Group::get_obj_count() const noexcept { return lv_group_get_obj_count(p_); }

inline void* Group::get_user_data() const noexcept { return lv_group_get_user_data(p_); }

inline bool Group::get_wrap() const noexcept { return lv_group_get_wrap(p_); }

inline void Group::remove_all_objs() const noexcept { lv_group_remove_all_objs(p_); }

inline Result Group::send_data(uint32_t c) const noexcept { return static_cast<Result>(lv_group_send_data(p_, c)); }

inline void Group::set_default() const noexcept { lv_group_set_default(p_); }

inline void Group::set_edge_cb(lv_group_edge_cb_t edge_cb) const noexcept { lv_group_set_edge_cb(p_, edge_cb); }

inline void Group::set_editing(bool edit) const noexcept { lv_group_set_editing(p_, edit); }

#if LV_USE_EXT_DATA
inline void Group::set_external_data(void* data, void (*arg)(void*)) const noexcept { lv_group_set_external_data(p_, data, arg); }

template <auto Fn>
inline void Group::set_external_data(void* data) const noexcept { lv_group_set_external_data(p_, data, &detail::GroupSetExternalDataThunk<Fn>::call); }
#endif // LV_USE_EXT_DATA

inline void Group::set_focus_cb(lv_group_focus_cb_t focus_cb) const noexcept { lv_group_set_focus_cb(p_, focus_cb); }

inline void Group::set_refocus_policy(GroupRefocusPolicy policy) const noexcept { lv_group_set_refocus_policy(p_, static_cast<lv_group_refocus_policy_t>(policy)); }

inline void Group::set_user_data(void* user_data) const noexcept { lv_group_set_user_data(p_, user_data); }

inline void Group::set_wrap(bool en) const noexcept { lv_group_set_wrap(p_, en); }

#if LVPP_COMPAT_V8
inline void Group::del() const noexcept { return delete_(); }
#endif // LVPP_COMPAT_V8

inline Group group_get_default() noexcept { return Group(lv_group_get_default()); }

inline void group_swap_obj(Obj obj1, Obj obj2) noexcept { lv_group_swap_obj(obj1.raw(), obj2.raw()); }

inline void group_remove_obj(Obj obj) noexcept { lv_group_remove_obj(obj.raw()); }

inline void group_focus_obj(Obj obj) noexcept { lv_group_focus_obj(obj.raw()); }

inline uint32_t group_get_count() noexcept { return lv_group_get_count(); }

inline Group group_by_index(uint32_t index) noexcept { return Group(lv_group_by_index(index)); }

} // namespace lv
