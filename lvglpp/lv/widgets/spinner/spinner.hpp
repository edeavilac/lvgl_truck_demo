#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core/obj.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lv/widgets/arc/arc.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if (LV_USE_SPINNER) && (LV_USE_ARC != 0)
class Spinner : public Arc {
public:
    using Arc::Arc;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_spinner_class; }

    /**
     * Create a spinner widget
     * @param parent  pointer to an object, it will be the parent of the new spinner.
     * @return the created spinner
     * @see lv_spinner_create
     */
    static Spinner create(Obj parent) noexcept { return Spinner(lv_spinner_create(parent.raw())); }
    /**
     * Get the animation duration of the spinner
     * @return the animation time in milliseconds
     * @see lv_spinner_get_anim_duration
     */
    uint32_t get_anim_duration() const noexcept { return lv_spinner_get_anim_duration(p_); }
    /**
     * Get the animation arc length of the spinner
     * @return the angle of the arc in degrees
     * @see lv_spinner_get_arc_sweep
     */
    uint32_t get_arc_sweep() const noexcept { return lv_spinner_get_arc_sweep(p_); }
    /**
     * Set the animation time of the spinner
     * @param t  the animation time in milliseconds
     * @see lv_spinner_set_anim_duration
     */
    void set_anim_duration(uint32_t t) const noexcept { lv_spinner_set_anim_duration(p_, t); }
    /**
     * Set the animation time and arc length of the spinner
     * The animation is suited for angle values between 180 and 360.
     * @param t  the animation time in milliseconds
     * @param angle  the angle of the arc in degrees
     * @see lv_spinner_set_anim_params
     */
    void set_anim_params(uint32_t t, uint32_t angle) const noexcept { lv_spinner_set_anim_params(p_, t, angle); }
    /**
     * Set the animation arc length of the spinner.
     * The animation is suited to values between 180 and 360.
     * @param angle  the angle of the arc in degrees
     * @see lv_spinner_set_arc_sweep
     */
    void set_arc_sweep(uint32_t angle) const noexcept { lv_spinner_set_arc_sweep(p_, angle); }
};
static_assert(sizeof(Spinner) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Spinner));
#endif // (LV_USE_SPINNER) && (LV_USE_ARC != 0)

} // namespace lv
