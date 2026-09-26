#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

class ObjClass {
protected:
    lv_obj_class_t* p_ = nullptr;

public:
    constexpr ObjClass() noexcept = default;  /**< the "no object" handle */
    constexpr explicit ObjClass(lv_obj_class_t* p) noexcept : p_(p) {}

    constexpr lv_obj_class_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(ObjClass a, ObjClass b) noexcept { return a.p_ == b.p_; }

    /**
     * Create an object form a class descriptor
     * @param parent  pointer to an object where the new object should be created
     * @return pointer to the created object
     * @see lv_obj_class_create_obj
     */
    Obj create_obj(Obj parent) const noexcept;
    #if LV_USE_OBJ_PROPERTY
    /**
     * Get property ID by doing a non-recursive search for name directly in Widget class properties.
     * Requires enabling `LV_USE_OBJ_PROPERTY_NAME`.
     * @param name  property name
     * @return property ID found or `LV_PROPERTY_ID_INVALID` if not found.
     * @see lv_obj_class_property_get_id
     */
    lv_prop_id_t property_get_id(const char* name) const noexcept;
    #endif // LV_USE_OBJ_PROPERTY

};
static_assert(sizeof(ObjClass) == sizeof(lv_obj_class_t*));
static_assert(__is_trivially_copyable(ObjClass));

/** @see lv_obj_class_init_obj */
inline void obj_class_init_obj(Obj obj) noexcept;

} // namespace lv
