#pragma once
// Bodies of core/obj_class.hpp, separated because its file cycle needs every type
// complete. Same mechanism as D-C7, applied where the graph asks for it.
// Included by the umbrella and never by a header: it is NOT a translation
// unit and every definition in it is `inline`. The stem says so, not the
// extension, so a glob written for *.hpp still installs it.

#include "lv/lvgl.hpp"

namespace lv {

inline bool Obj::is_editable() const noexcept { return lv_obj_is_editable(p_); }

inline bool Obj::is_group_def() const noexcept { return lv_obj_is_group_def(p_); }

#if LV_USE_EXT_DATA
inline void Obj::set_external_data(void* data, void (*arg)(void*)) const noexcept { lv_obj_set_external_data(p_, data, arg); }
#endif // LV_USE_EXT_DATA

inline Obj ObjClass::create_obj(Obj parent) const noexcept { return Obj(lv_obj_class_create_obj(p_, parent.raw())); }

inline void obj_class_init_obj(Obj obj) noexcept { lv_obj_class_init_obj(obj.raw()); }

} // namespace lv
