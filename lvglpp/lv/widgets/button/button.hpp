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

#if LV_USE_BUTTON != 0
class Button : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_button_class; }

    /**
     * Create a button object
     * @param parent  pointer to an object, it will be the parent of the new button
     * @return pointer to the created button
     * @see lv_button_create
     */
    static Button create(Obj parent) noexcept;
    #if LVPP_COMPAT_V8
    /** v8 spelling of `create`. */
    static Button btn_create(Obj parent) noexcept;
    #endif // LVPP_COMPAT_V8

};
static_assert(sizeof(Button) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Button));
#endif // LV_USE_BUTTON != 0

} // namespace lv
