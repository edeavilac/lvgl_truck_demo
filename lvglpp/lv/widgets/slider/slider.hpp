#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core.hpp"
#include "lv/core/obj.hpp"
#include "lv/core/observer.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lv/widgets/bar/bar.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if (LV_USE_SLIDER != 0) && (LV_USE_BAR != 0)
class Slider : public Bar {
public:
    using Bar::Bar;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_slider_class; }

    enum class Mode : int {
        Normal = LV_SLIDER_MODE_NORMAL,
        Symmetrical = LV_SLIDER_MODE_SYMMETRICAL,
        Range = LV_SLIDER_MODE_RANGE,
    };

    enum class Orientation : int {
        Auto = LV_SLIDER_ORIENTATION_AUTO,
        Horizontal = LV_SLIDER_ORIENTATION_HORIZONTAL,
        Vertical = LV_SLIDER_ORIENTATION_VERTICAL,
    };

    #if LV_USE_OBSERVER
    /**
     * Bind an integer or float Subject to a Slider's value.
     * @param subject  pointer to Subject
     * @return pointer to newly-created Observer
     * @see lv_slider_bind_value
     */
    Observer bind_value(Subject& subject) const noexcept { return Observer(lv_slider_bind_value(p_, subject.raw())); }
    #endif // LV_USE_OBSERVER

    /**
     * Create a slider object
     * @param parent  pointer to an object, it will be the parent of the new slider.
     * @return pointer to the created slider
     * @see lv_slider_create
     */
    static Slider create(Obj parent) noexcept { return Slider(lv_slider_create(parent.raw())); }
    /**
     * Get the value of the left knob of a slider
     * @return the value of the left knob of the slider
     * @see lv_slider_get_left_value
     */
    int32_t get_left_value() const noexcept { return lv_slider_get_left_value(p_); }
    /**
     * Get the maximum value of a slider
     * @return the maximum value of the slider
     * @see lv_slider_get_max_value
     */
    int32_t get_max_value() const noexcept { return lv_slider_get_max_value(p_); }
    /**
     * Get the minimum value of a slider
     * @return the minimum value of the slider
     * @see lv_slider_get_min_value
     */
    int32_t get_min_value() const noexcept { return lv_slider_get_min_value(p_); }
    /**
     * Get the mode of the slider.
     * @return see `lv_slider_mode_t`
     * @see lv_slider_get_mode
     */
    Slider::Mode get_mode() const noexcept { return static_cast<Slider::Mode>(lv_slider_get_mode(p_)); }
    /**
     * Get the orientation of slider.
     * @return slider orientation from `lv_slider_orientation_t`
     * @see lv_slider_get_orientation
     */
    Slider::Orientation get_orientation() const noexcept { return static_cast<Slider::Orientation>(lv_slider_get_orientation(p_)); }
    /**
     * Get the value of the main knob of a slider
     * @return the value of the main knob of the slider
     * @see lv_slider_get_value
     */
    int32_t get_value() const noexcept { return lv_slider_get_value(p_); }
    /**
     * Give the slider is being dragged or not
     * @return true: drag in progress false: not dragged
     * @see lv_slider_is_dragged
     */
    bool is_dragged() const noexcept { return lv_slider_is_dragged(p_); }
    /**
     * Give the slider is in symmetrical mode or not
     * @return true: in symmetrical mode false : not in
     * @see lv_slider_is_symmetrical
     */
    bool is_symmetrical() const noexcept { return lv_slider_is_symmetrical(p_); }
    /**
     * Set the maximum values of a bar
     * @param max  maximum value
     * @see lv_slider_set_max_value
     */
    void set_max_value(int32_t max) const noexcept { lv_slider_set_max_value(p_, max); }
    /**
     * Set the minimum values of a bar
     * @param min  minimum value
     * @see lv_slider_set_min_value
     */
    void set_min_value(int32_t min) const noexcept { lv_slider_set_min_value(p_, min); }
    /**
     * Set the mode of slider.
     * @param mode  the mode of the slider. See `lv_slider_mode_t`
     * @see lv_slider_set_mode
     */
    void set_mode(Slider::Mode mode) const noexcept { lv_slider_set_mode(p_, static_cast<lv_slider_mode_t>(mode)); }
    /**
     * Set the orientation of slider.
     * @param orientation  slider orientation from `lv_slider_orientation_t`
     * @see lv_slider_set_orientation
     */
    void set_orientation(Slider::Orientation orientation) const noexcept { lv_slider_set_orientation(p_, static_cast<lv_slider_orientation_t>(orientation)); }
    /**
     * Set the minimum and the maximum values of a bar
     * @param min  minimum value
     * @param max  maximum value
     * @see lv_slider_set_range
     */
    void set_range(int32_t min, int32_t max) const noexcept { lv_slider_set_range(p_, min, max); }
    /**
     * Set a new value for the left knob of a slider
     * @param value  new value
     * @param anim  LV_ANIM_ON: set the value with an animation; LV_ANIM_OFF: change the value immediately
     * @see lv_slider_set_start_value
     */
    void set_start_value(int32_t value, lv_anim_enable_t anim) const noexcept { lv_slider_set_start_value(p_, value, anim); }
    /**
     * Set a new value on the slider
     * @param value  the new value
     * @param anim  LV_ANIM_ON: set the value with an animation; LV_ANIM_OFF: change the value immediately
     * @see lv_slider_set_value
     */
    void set_value(int32_t value, lv_anim_enable_t anim) const noexcept { lv_slider_set_value(p_, value, anim); }
};
static_assert(sizeof(Slider) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Slider));
#endif // (LV_USE_SLIDER != 0) && (LV_USE_BAR != 0)

} // namespace lv
