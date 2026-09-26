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

#if LV_USE_SWITCH != 0
class Switch : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_switch_class; }

    enum class Orientation : int {
        Auto = LV_SWITCH_ORIENTATION_AUTO,
        Horizontal = LV_SWITCH_ORIENTATION_HORIZONTAL,
        Vertical = LV_SWITCH_ORIENTATION_VERTICAL,
    };

    /**
     * Create a switch object
     * @param parent  pointer to an object, it will be the parent of the new switch
     * @return pointer to the created switch
     * @see lv_switch_create
     */
    static Switch create(Obj parent) noexcept { return Switch(lv_switch_create(parent.raw())); }
    /**
     * Get the orientation of switch.
     * @return switch orientation from ::lv_switch_orientation_t
     * @see lv_switch_get_orientation
     */
    Switch::Orientation get_orientation() const noexcept { return static_cast<Switch::Orientation>(lv_switch_get_orientation(p_)); }
    /**
     * Set the orientation of switch.
     * @param orientation  switch orientation from `lv_switch_orientation_t`
     * @see lv_switch_set_orientation
     */
    void set_orientation(Switch::Orientation orientation) const noexcept { lv_switch_set_orientation(p_, static_cast<lv_switch_orientation_t>(orientation)); }
};
static_assert(sizeof(Switch) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Switch));
#endif // LV_USE_SWITCH != 0

} // namespace lv
