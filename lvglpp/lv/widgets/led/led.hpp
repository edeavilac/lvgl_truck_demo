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

#if LV_USE_LED
class Led : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_led_class; }

    /**
     * Create a led object
     * @param parent  pointer to an object, it will be the parent of the new led
     * @return pointer to the created led
     * @see lv_led_create
     */
    static Led create(Obj parent) noexcept { return Led(lv_led_create(parent.raw())); }
    /**
     * Get the brightness of a LED object
     * @return bright 0 (max. dark) ... 255 (max. light)
     * @see lv_led_get_brightness
     */
    uint8_t get_brightness() const noexcept { return lv_led_get_brightness(p_); }
    /**
     * Get the color of a LED object
     * @return color color of the LED
     * @see lv_led_get_color
     */
    Color get_color() const noexcept { return Color{lv_led_get_color(p_)}; }
    /**
     * Light off a LED
     * @see lv_led_off
     */
    void off() const noexcept { lv_led_off(p_); }
    /**
     * Light on a LED
     * @see lv_led_on
     */
    void on() const noexcept { lv_led_on(p_); }
    /**
     * Set the brightness of a LED object
     * @param bright  LV_LED_BRIGHT_MIN (max. dark) ... LV_LED_BRIGHT_MAX (max. light)
     * @see lv_led_set_brightness
     */
    void set_brightness(uint8_t bright) const noexcept { lv_led_set_brightness(p_, bright); }
    /**
     * Set the color of the LED
     * @param color  the color of the LED
     * @see lv_led_set_color
     */
    void set_color(Color color) const noexcept { lv_led_set_color(p_, color.raw()); }
    /**
     * Toggle the state of a LED
     * @see lv_led_toggle
     */
    void toggle() const noexcept { lv_led_toggle(p_); }
};
static_assert(sizeof(Led) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Led));
#endif // LV_USE_LED

} // namespace lv
