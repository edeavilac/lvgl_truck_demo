#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core/obj.hpp"
#include "lv/core/obj_class.hpp"
#include "lv/display/display.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/misc/anim.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

/**
 * A function to be easily used in animation ready callback to delete an object when the animation is ready
 * @param a  pointer to the animation
 * @see lv_obj_delete_anim_completed_cb
 */
inline void obj_delete_anim_completed_cb(Anim& a) noexcept { lv_obj_delete_anim_completed_cb(a.raw()); }

/**
 * Iterate through all children of any object.
 * @param start_obj  start integrating from this object
 * @param cb  call this callback on the objects
 * @param user_data  pointer to any user related data (will be passed to `cb`)
 * @see lv_obj_tree_walk
 */
inline void obj_tree_walk(Obj start_obj, lv_obj_tree_walk_cb_t cb, void* user_data) noexcept { lv_obj_tree_walk(start_obj.raw(), cb, user_data); }

/**
 * Takes any callable instead of the C pair.
 * Iterate through all children of any object.
 * @param start_obj  start integrating from this object
 * @param cb  call this callback on the objects
 * @param user_data  pointer to any user related data (will be passed to `cb`)
 * @see lv_obj_tree_walk
 */
template <class F>
inline void obj_tree_walk(Obj start_obj, F&& f) noexcept { lv_obj_tree_walk(start_obj.raw(), detail::ObjTreeWalkCbClosure<std::decay_t<F>>::fn(f), detail::ObjTreeWalkCbClosure<std::decay_t<F>>::state(f)); }

inline void Obj::clean() const noexcept { lv_obj_clean(p_); }

inline void Obj::delete_() const noexcept { lv_obj_delete(p_); }

inline void Obj::delete_async() const noexcept { lv_obj_delete_async(p_); }

inline void Obj::delete_delayed(uint32_t delay_ms) const noexcept { lv_obj_delete_delayed(p_, delay_ms); }

inline void Obj::dump_tree() const noexcept { lv_obj_dump_tree(p_); }

#if LV_USE_OBJ_NAME
inline Obj Obj::find_by_name(const char* name) const noexcept { return Obj(lv_obj_find_by_name(p_, name)); }
#endif // LV_USE_OBJ_NAME

inline Obj Obj::get_child(int32_t idx) const noexcept { return Obj(lv_obj_get_child(p_, idx)); }

#if LV_USE_OBJ_NAME
inline Obj Obj::get_child_by_name(const char* name_path) const noexcept { return Obj(lv_obj_get_child_by_name(p_, name_path)); }
#endif // LV_USE_OBJ_NAME

inline Obj Obj::get_child_by_type(int32_t idx, ObjClass class_p) const noexcept { return Obj(lv_obj_get_child_by_type(p_, idx, class_p.raw())); }

inline uint32_t Obj::get_child_count() const noexcept { return lv_obj_get_child_count(p_); }

inline uint32_t Obj::get_child_count_by_type(ObjClass class_p) const noexcept { return lv_obj_get_child_count_by_type(p_, class_p.raw()); }

inline Display Obj::get_display() const noexcept { return Display(lv_obj_get_display(p_)); }

inline int32_t Obj::get_index() const noexcept { return lv_obj_get_index(p_); }

inline int32_t Obj::get_index_by_type(ObjClass class_p) const noexcept { return lv_obj_get_index_by_type(p_, class_p.raw()); }

#if LV_USE_OBJ_NAME
inline const char* Obj::get_name() const noexcept { return lv_obj_get_name(p_); }

inline void Obj::get_name_resolved(char* buf, size_t buf_size) const noexcept { lv_obj_get_name_resolved(p_, buf, buf_size); }
#endif // LV_USE_OBJ_NAME

inline Obj Obj::get_parent() const noexcept { return Obj(lv_obj_get_parent(p_)); }

inline Obj Obj::get_screen() const noexcept { return Obj(lv_obj_get_screen(p_)); }

inline Obj Obj::get_sibling(int32_t idx) const noexcept { return Obj(lv_obj_get_sibling(p_, idx)); }

inline Obj Obj::get_sibling_by_type(int32_t idx, ObjClass class_p) const noexcept { return Obj(lv_obj_get_sibling_by_type(p_, idx, class_p.raw())); }

inline void Obj::move_to_index(int32_t index) const noexcept { lv_obj_move_to_index(p_, index); }

#if LV_USE_OBJ_NAME
inline void Obj::set_name(const char* name) const noexcept { lv_obj_set_name(p_, name); }

inline void Obj::set_name_static(const char* name) const noexcept { lv_obj_set_name_static(p_, name); }
#endif // LV_USE_OBJ_NAME

inline void Obj::set_parent(Obj parent) const noexcept { lv_obj_set_parent(p_, parent.raw()); }

inline void Obj::swap(Obj obj2) const noexcept { lv_obj_swap(p_, obj2.raw()); }

} // namespace lv
