#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core.hpp"
#include "lv/core/obj.hpp"
#include "lv/core/observer.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lv/widgets/textarea/textarea.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if (LV_USE_SPINBOX) && (LV_USE_TEXTAREA != 0)
class Spinbox : public Textarea {
public:
    using Textarea::Textarea;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_spinbox_class; }

    #if LV_USE_OBSERVER
    /**
     * Bind an integer subject to a Spinbox's value.
     * @param subject  pointer to Subject
     * @return pointer to newly-created Observer
     * @see lv_spinbox_bind_value
     */
    Observer bind_value(Subject& subject) const noexcept { return Observer(lv_spinbox_bind_value(p_, subject.raw())); }
    #endif // LV_USE_OBSERVER

    /**
     * Create a spinbox object
     * @param parent  pointer to an object, it will be the parent of the new spinbox
     * @return pointer to the created spinbox
     * @see lv_spinbox_create
     */
    static Spinbox create(Obj parent) noexcept { return Spinbox(lv_spinbox_create(parent.raw())); }
    /**
     * Decrement spinbox value by one step
     * @see lv_spinbox_decrement
     */
    void decrement() const noexcept { lv_spinbox_decrement(p_); }
    /**
     * Get the decimal point position
     * @return decimal point position
     * @see lv_spinbox_get_dec_point_pos
     */
    uint32_t get_dec_point_pos() const noexcept { return lv_spinbox_get_dec_point_pos(p_); }
    /**
     * Get the spinbox digit count
     * @return number of digits
     * @see lv_spinbox_get_digit_count
     */
    uint32_t get_digit_count() const noexcept { return lv_spinbox_get_digit_count(p_); }
    /**
     * Get the digit step direction
     * @return direction (LV_DIR_RIGHT or LV_DIR_LEFT)
     * @see lv_spinbox_get_digit_step_direction
     */
    Dir get_digit_step_direction() const noexcept { return static_cast<Dir>(lv_spinbox_get_digit_step_direction(p_)); }
    /**
     * Get the spinbox maximum value
     * @return maximum value
     * @see lv_spinbox_get_max_value
     */
    int32_t get_max_value() const noexcept { return lv_spinbox_get_max_value(p_); }
    /**
     * Get the spinbox minimum value
     * @return minimum value
     * @see lv_spinbox_get_min_value
     */
    int32_t get_min_value() const noexcept { return lv_spinbox_get_min_value(p_); }
    /**
     * Get spinbox rollover function status
     * @see lv_spinbox_get_rollover
     */
    bool get_rollover() const noexcept { return lv_spinbox_get_rollover(p_); }
    /**
     * Get the spinbox step value (user has to convert to float according to its digit format)
     * @return value integer step value of the spinbox
     * @see lv_spinbox_get_step
     */
    int32_t get_step() const noexcept { return lv_spinbox_get_step(p_); }
    /**
     * Get the spinbox numeral value (user has to convert to float according to its digit format)
     * @return value integer value of the spinbox
     * @see lv_spinbox_get_value
     */
    int32_t get_value() const noexcept { return lv_spinbox_get_value(p_); }
    /**
     * Increment spinbox value by one step
     * @see lv_spinbox_increment
     */
    void increment() const noexcept { lv_spinbox_increment(p_); }
    /**
     * Set cursor position to a specific digit for edition
     * @param pos  selected position in spinbox
     * @see lv_spinbox_set_cursor_pos
     */
    void set_cursor_pos(uint32_t pos) const noexcept { lv_spinbox_set_cursor_pos(p_, pos); }
    /**
     * Set the position of the decimal point
     * @param dec_point_pos  0: there is no separator, 2: two integer digits
     * @see lv_spinbox_set_dec_point_pos
     */
    void set_dec_point_pos(uint32_t dec_point_pos) const noexcept { lv_spinbox_set_dec_point_pos(p_, dec_point_pos); }
    /**
     * Set the number of digits
     * @param digit_count  number of digits
     * @see lv_spinbox_set_digit_count
     */
    void set_digit_count(uint32_t digit_count) const noexcept { lv_spinbox_set_digit_count(p_, digit_count); }
    /**
     * Set spinbox digit format (digit count and decimal format)
     * @param digit_count  number of digit excluding the decimal separator and the sign
     * @param sep_pos  number of digit before the decimal point. If 0, decimal point is not shown
     * @see lv_spinbox_set_digit_format
     */
    void set_digit_format(uint32_t digit_count, uint32_t sep_pos) const noexcept { lv_spinbox_set_digit_format(p_, digit_count, sep_pos); }
    /**
     * Set direction of digit step when clicking an encoder button while in editing mode
     * @param direction  the direction (LV_DIR_RIGHT or LV_DIR_LEFT)
     * @see lv_spinbox_set_digit_step_direction
     */
    void set_digit_step_direction(Dir direction) const noexcept { lv_spinbox_set_digit_step_direction(p_, static_cast<lv_dir_t>(direction)); }
    /**
     * Set the maximum value
     * @param max_value  the maximum value
     * @see lv_spinbox_set_max_value
     */
    void set_max_value(int32_t max_value) const noexcept { lv_spinbox_set_max_value(p_, max_value); }
    /**
     * Set the minimum value
     * @param min_value  the minimum value
     * @see lv_spinbox_set_min_value
     */
    void set_min_value(int32_t min_value) const noexcept { lv_spinbox_set_min_value(p_, min_value); }
    /**
     * Set spinbox value range
     * @param min_value  minimum value, inclusive
     * @param max_value  maximum value, inclusive
     * @see lv_spinbox_set_range
     */
    void set_range(int32_t min_value, int32_t max_value) const noexcept { lv_spinbox_set_range(p_, min_value, max_value); }
    /**
     * Set spinbox rollover function
     * @param rollover  true or false to enable or disable (default)
     * @see lv_spinbox_set_rollover
     */
    void set_rollover(bool rollover) const noexcept { lv_spinbox_set_rollover(p_, rollover); }
    /**
     * Set spinbox step
     * @param step  steps on increment/decrement. Can be 1, 10, 100, 1000, etc the digit that will change.
     * @see lv_spinbox_set_step
     */
    void set_step(uint32_t step) const noexcept { lv_spinbox_set_step(p_, step); }
    /**
     * Set spinbox value
     * @param v  value to be set
     * @see lv_spinbox_set_value
     */
    void set_value(int32_t v) const noexcept { lv_spinbox_set_value(p_, v); }
    /**
     * Select next lower digit for edition by dividing the step by 10
     * @see lv_spinbox_step_next
     */
    void step_next() const noexcept { lv_spinbox_step_next(p_); }
    /**
     * Select next higher digit for edition by multiplying the step by 10
     * @see lv_spinbox_step_prev
     */
    void step_prev() const noexcept { lv_spinbox_step_prev(p_); }
};
static_assert(sizeof(Spinbox) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Spinbox));
#endif // (LV_USE_SPINBOX) && (LV_USE_TEXTAREA != 0)

} // namespace lv
