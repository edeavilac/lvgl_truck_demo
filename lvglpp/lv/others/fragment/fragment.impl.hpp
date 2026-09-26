#pragma once
// Bodies of others/fragment/fragment.hpp, separated because its file cycle needs every type
// complete. Same mechanism as D-C7, applied where the graph asks for it.
// Included by the umbrella and never by a header: it is NOT a translation
// unit and every definition in it is `inline`. The stem says so, not the
// extension, so a glob written for *.hpp still installs it.

#include "lv/lvgl.hpp"

namespace lv {

#if LV_USE_FRAGMENT
inline void FragmentManager::add(Fragment fragment, lv_obj_t* const* container) const noexcept { lv_fragment_manager_add(p_, fragment.raw(), container); }

inline FragmentManager FragmentManager::create(Fragment parent) noexcept { return FragmentManager(lv_fragment_manager_create(parent.raw())); }

inline void FragmentManager::create_obj() const noexcept { lv_fragment_manager_create_obj(p_); }

inline void FragmentManager::delete_() const noexcept { lv_fragment_manager_delete(p_); }

inline void FragmentManager::delete_obj() const noexcept { lv_fragment_manager_delete_obj(p_); }

inline Fragment FragmentManager::find_by_container(Obj container) const noexcept { return Fragment(lv_fragment_manager_find_by_container(p_, container.raw())); }

inline Fragment FragmentManager::get_parent_fragment() const noexcept { return Fragment(lv_fragment_manager_get_parent_fragment(p_)); }

inline uint32_t FragmentManager::get_stack_size() const noexcept { return lv_fragment_manager_get_stack_size(p_); }

inline Fragment FragmentManager::get_top() const noexcept { return Fragment(lv_fragment_manager_get_top(p_)); }

inline bool FragmentManager::pop() const noexcept { return lv_fragment_manager_pop(p_); }

inline void FragmentManager::push(Fragment fragment, lv_obj_t* const* container) const noexcept { lv_fragment_manager_push(p_, fragment.raw(), container); }

inline void FragmentManager::remove(Fragment fragment) const noexcept { lv_fragment_manager_remove(p_, fragment.raw()); }

inline void FragmentManager::replace(Fragment fragment, lv_obj_t* const* container) const noexcept { lv_fragment_manager_replace(p_, fragment.raw(), container); }

inline bool FragmentManager::send_event(int32_t code, void* userdata) const noexcept { return lv_fragment_manager_send_event(p_, code, userdata); }

inline Fragment Fragment::create(const lv_fragment_class_t* cls, void* args) noexcept { return Fragment(lv_fragment_create(cls, args)); }

inline Obj Fragment::create_obj(Obj container) const noexcept { return Obj(lv_fragment_create_obj(p_, container.raw())); }

inline void Fragment::delete_() const noexcept { lv_fragment_delete(p_); }

inline void Fragment::delete_obj() const noexcept { lv_fragment_delete_obj(p_); }

inline lv_obj_t* const* Fragment::get_container() const noexcept { return lv_fragment_get_container(p_); }

inline FragmentManager Fragment::get_manager() const noexcept { return FragmentManager(lv_fragment_get_manager(p_)); }

inline Fragment Fragment::get_parent() const noexcept { return Fragment(lv_fragment_get_parent(p_)); }

inline void Fragment::recreate_obj() const noexcept { lv_fragment_recreate_obj(p_); }
#endif // LV_USE_FRAGMENT

} // namespace lv
