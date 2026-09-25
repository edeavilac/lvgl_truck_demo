#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core.hpp"
#include "lv/core/obj.hpp"
#include "lv/core/observer.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_BAR != 0
class Bar : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_bar_class; }

    enum class Mode : int {
        Normal = LV_BAR_MODE_NORMAL,
        Symmetrical = LV_BAR_MODE_SYMMETRICAL,
        Range = LV_BAR_MODE_RANGE,
    };

    enum class Orientation : int {
        Auto = LV_BAR_ORIENTATION_AUTO,
        Horizontal = LV_BAR_ORIENTATION_HORIZONTAL,
        Vertical = LV_BAR_ORIENTATION_VERTICAL,
    };

    #if LV_USE_OBSERVER
    /**
     * Bind an integer or float Subject to a Bar's value.
     * @param subject  pointer to Subject
     * @return pointer to newly-created Observer
     * @see lv_bar_bind_value
     */
    Observer bind_value(Subject& subject) const noexcept { return Observer(lv_bar_bind_value(p_, subject.raw())); }
    #endif // LV_USE_OBSERVER

    /**
     * Create a bar object
     * @param parent  pointer to an object, it will be the parent of the new bar
     * @return pointer to the created bar
     * @see lv_bar_create
     */
    static Bar create(Obj parent) noexcept { return Bar(lv_bar_create(parent.raw())); }
    /**
     * Get the maximum value of a bar
     * @return the maximum value of the bar
     * @see lv_bar_get_max_value
     */
    int32_t get_max_value() const noexcept { return lv_bar_get_max_value(p_); }
    /**
     * Get the minimum value of a bar
     * @return the minimum value of the bar
     * @see lv_bar_get_min_value
     */
    int32_t get_min_value() const noexcept { return lv_bar_get_min_value(p_); }
    /**
     * Get the type of bar.
     * @return bar type from `lv_bar_mode_t`
     * @see lv_bar_get_mode
     */
    Bar::Mode get_mode() const noexcept { return static_cast<Bar::Mode>(lv_bar_get_mode(p_)); }
    /**
     * Get the orientation of bar.
     * @return bar orientation from `lv_bar_orientation_t`
     * @see lv_bar_get_orientation
     */
    Bar::Orientation get_orientation() const noexcept { return static_cast<Bar::Orientation>(lv_bar_get_orientation(p_)); }
    /**
     * Get the start value of a bar
     * @return the start value of the bar
     * @see lv_bar_get_start_value
     */
    int32_t get_start_value() const noexcept { return lv_bar_get_start_value(p_); }
    /**
     * Get the value of a bar
     * @return the value of the bar
     * @see lv_bar_get_value
     */
    int32_t get_value() const noexcept { return lv_bar_get_value(p_); }
    /**
     * Give the bar is in symmetrical mode or not
     * @return true: in symmetrical mode false : not in
     * @see lv_bar_is_symmetrical
     */
    bool is_symmetrical() const noexcept { return lv_bar_is_symmetrical(p_); }
    /**
     * Set maximum value of a bar
     * @param max  maximum value
     * @see lv_bar_set_max_value
     */
    void set_max_value(int32_t max) const noexcept { lv_bar_set_max_value(p_, max); }
    /**
     * Set minimum value of a bar
     * @param min  minimum value
     * @see lv_bar_set_min_value
     */
    void set_min_value(int32_t min) const noexcept { lv_bar_set_min_value(p_, min); }
    /**
     * Set the type of bar.
     * @param mode  bar type from `lv_bar_mode_t`
     * @see lv_bar_set_mode
     */
    void set_mode(Bar::Mode mode) const noexcept { lv_bar_set_mode(p_, static_cast<lv_bar_mode_t>(mode)); }
    /**
     * Set the orientation of bar.
     * @param orientation  bar orientation from `lv_bar_orientation_t`
     * @see lv_bar_set_orientation
     */
    void set_orientation(Bar::Orientation orientation) const noexcept { lv_bar_set_orientation(p_, static_cast<lv_bar_orientation_t>(orientation)); }
    /**
     * Set minimum and the maximum values of a bar
     * @param min  minimum value
     * @param max  maximum value
     * @see lv_bar_set_range
     */
    void set_range(int32_t min, int32_t max) const noexcept { lv_bar_set_range(p_, min, max); }
    /**
     * Set a new start value on the bar
     * @param start_value  new start value
     * @param anim  LV_ANIM_ON: set the value with an animation; LV_ANIM_OFF: change the value immediately
     * @see lv_bar_set_start_value
     */
    void set_start_value(int32_t start_value, lv_anim_enable_t anim) const noexcept { lv_bar_set_start_value(p_, start_value, anim); }
    /**
     * Set a new value on the bar
     * @param value  new value
     * @param anim  LV_ANIM_ON: set the value with an animation; LV_ANIM_OFF: change the value immediately
     * @see lv_bar_set_value
     */
    void set_value(int32_t value, lv_anim_enable_t anim) const noexcept { lv_bar_set_value(p_, value, anim); }
};
static_assert(sizeof(Bar) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Bar));
#endif // LV_USE_BAR != 0

} // namespace lv
