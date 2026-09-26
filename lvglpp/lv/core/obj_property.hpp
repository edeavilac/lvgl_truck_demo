#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core/obj.hpp"
#include "lv/core/obj_class.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_OBJ_PROPERTY
/**
 * Get property ID by recursively searching for name in Widget's class hierarchy, and
 * if still not found, then search style properties.
 * Requires to enabling `LV_USE_OBJ_PROPERTY_NAME`.
 * @param obj  pointer to Widget whose class and base-class hierarchy are to be searched.
 * @param name  property name
 * @return property ID found or `LV_PROPERTY_ID_INVALID` if not found.
 * @see lv_obj_property_get_id
 */
inline lv_prop_id_t obj_property_get_id(Obj obj, const char* name) noexcept { return lv_obj_property_get_id(obj.raw(), name); }

/**
 * Get style property ID by name. Requires enabling `LV_USE_OBJ_PROPERTY_NAME`.
 * @param name  property name
 * @return property ID found or `LV_PROPERTY_ID_INVALID` if not found.
 * @see lv_style_property_get_id
 */
inline lv_prop_id_t style_property_get_id(const char* name) noexcept { return lv_style_property_get_id(name); }
#endif // LV_USE_OBJ_PROPERTY

#if LV_USE_OBJ_PROPERTY
inline lv_prop_id_t ObjClass::property_get_id(const char* name) const noexcept { return lv_obj_class_property_get_id(p_, name); }

inline lv_property_t Obj::get_property(lv_prop_id_t id) const noexcept { return lv_obj_get_property(p_, id); }

inline Result Obj::set_properties(const lv_property_t* value, uint32_t count) const noexcept { return static_cast<Result>(lv_obj_set_properties(p_, value, count)); }

inline Result Obj::set_property(const lv_property_t* value) const noexcept { return static_cast<Result>(lv_obj_set_property(p_, value)); }
#endif // LV_USE_OBJ_PROPERTY

} // namespace lv
