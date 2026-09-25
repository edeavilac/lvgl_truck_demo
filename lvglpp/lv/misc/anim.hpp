#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/misc/timer.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

class Anim {
protected:
    lv_anim_t s_;

public:
    Anim() noexcept { lv_anim_init(&s_); }

    Anim(const Anim&) = delete;
    Anim& operator=(const Anim&) = delete;
    Anim(Anim&&) = delete;
    Anim& operator=(Anim&&) = delete;

    lv_anim_t* raw() noexcept { return &s_; }

    /**
     * Delete an animation by getting the animated variable from `a`.
     * Only animations with `exec_cb` will be deleted.
     * This function exists because it's logical that all anim. functions receives an
     * `lv_anim_t` as their first parameter. It's not practical in C but might make
     * the API more consequent and makes easier to generate bindings.
     * @param exec_cb  a function pointer which is animating 'var', or NULL to ignore it and delete all the animations of 'var
     * @return true: at least 1 animation is deleted, false: no animation is deleted
     * @see lv_anim_custom_delete
     */
    bool custom_delete(lv_anim_custom_exec_cb_t exec_cb) noexcept { return lv_anim_custom_delete(&s_, exec_cb); }
    /**
     * Get the animation of a variable and its `exec_cb`.
     * This function exists because it's logical that all anim. functions receives an
     * `lv_anim_t` as their first parameter. It's not practical in C but might make
     * the API more consequent and makes easier to generate bindings.
     * @param exec_cb  a function pointer which is animating 'var', or NULL to return first matching 'var'
     * @return pointer to the animation.
     * @see lv_anim_custom_get
     */
    lv_anim_t* custom_get(lv_anim_custom_exec_cb_t exec_cb) noexcept { return lv_anim_custom_get(&s_, exec_cb); }
    /**
     * Get a delay before starting the animation
     * @return delay before the animation in milliseconds
     * @see lv_anim_get_delay
     */
    uint32_t get_delay() const noexcept { return lv_anim_get_delay(&s_); }
    /**
     * Get the time used to play the animation.
     * @return the play time in milliseconds.
     * @see lv_anim_get_playtime
     */
    uint32_t get_playtime() const noexcept { return lv_anim_get_playtime(&s_); }
    /**
     * Get the repeat count of the animation.
     * @return the repeat count or `LV_ANIM_REPEAT_INFINITE` for infinite repetition. 0: disabled repetition.
     * @see lv_anim_get_repeat_count
     */
    uint32_t get_repeat_count() const noexcept { return lv_anim_get_repeat_count(&s_); }
    /**
     * Get the duration of an animation
     * @return the duration of the animation in milliseconds
     * @see lv_anim_get_time
     */
    uint32_t get_time() const noexcept { return lv_anim_get_time(&s_); }
    /**
     * Get the user_data field of the animation
     * @return the pointer to the custom user_data of the animation
     * @see lv_anim_get_user_data
     */
    void* get_user_data() const noexcept { return lv_anim_get_user_data(&s_); }
    /**
     * Check if the animation is paused
     * @return true if the animation is paused else false
     * @see lv_anim_is_paused
     */
    bool is_paused() noexcept { return lv_anim_is_paused(&s_); }
    /**
     * Calculate the current value of an animation with 3 bounces
     * @return the current value to set
     * @see lv_anim_path_bounce
     */
    int32_t path_bounce() const noexcept { return lv_anim_path_bounce(&s_); }
    /**
     * A custom cubic bezier animation path, need to specify cubic-parameters in a->parameter.bezier3
     * @return the current value to set
     * @see lv_anim_path_custom_bezier3
     */
    int32_t path_custom_bezier3() const noexcept { return lv_anim_path_custom_bezier3(&s_); }
    /**
     * Calculate the current value of an animation slowing down the start phase
     * @return the current value to set
     * @see lv_anim_path_ease_in
     */
    int32_t path_ease_in() const noexcept { return lv_anim_path_ease_in(&s_); }
    /**
     * Calculate the current value of an animation applying an "S" characteristic (cosine)
     * @return the current value to set
     * @see lv_anim_path_ease_in_out
     */
    int32_t path_ease_in_out() const noexcept { return lv_anim_path_ease_in_out(&s_); }
    /**
     * Calculate the current value of an animation slowing down the end phase
     * @return the current value to set
     * @see lv_anim_path_ease_out
     */
    int32_t path_ease_out() const noexcept { return lv_anim_path_ease_out(&s_); }
    /**
     * Calculate the current value of an animation applying linear characteristic
     * @return the current value to set
     * @see lv_anim_path_linear
     */
    int32_t path_linear() const noexcept { return lv_anim_path_linear(&s_); }
    /**
     * Calculate the current value of an animation with overshoot at the end
     * @return the current value to set
     * @see lv_anim_path_overshoot
     */
    int32_t path_overshoot() const noexcept { return lv_anim_path_overshoot(&s_); }
    /**
     * Calculate the current value of an animation applying step characteristic.
     * (Set end value on the end of the animation)
     * @return the current value to set
     * @see lv_anim_path_step
     */
    int32_t path_step() const noexcept { return lv_anim_path_step(&s_); }
    /**
     * Pauses the animation
     * @see lv_anim_pause
     */
    Anim& pause() noexcept { lv_anim_pause(&s_); return *this; }
    /**
     * Pauses the animation for ms milliseconds
     * @param ms  the pause time in milliseconds
     * @see lv_anim_pause_for
     */
    Anim& pause_for(uint32_t ms) noexcept { lv_anim_pause_for(&s_, ms); return *this; }
    /**
     * Resumes a paused animation
     * @see lv_anim_resume
     */
    Anim& resume() noexcept { lv_anim_resume(&s_); return *this; }
    /**
     * Set parameter for cubic bezier path
     * @param x1  first control point X
     * @param y1  first control point Y
     * @param x2  second control point X
     * @param y2  second control point Y
     * @see lv_anim_set_bezier3_param
     */
    Anim& set_bezier3_param(int16_t x1, int16_t y1, int16_t x2, int16_t y2) noexcept { lv_anim_set_bezier3_param(&s_, x1, y1, x2, y2); return *this; }
    /**
     * Set a function call when the animation is completed
     * @param completed_cb  a function call when the animation is fully completed
     * @see lv_anim_set_completed_cb
     */
    Anim& set_completed_cb(lv_anim_completed_cb_t completed_cb) noexcept { lv_anim_set_completed_cb(&s_, completed_cb); return *this; }
    /**
     * Similar to `lv_anim_set_exec_cb` but `lv_anim_custom_exec_cb_t` receives
     * `lv_anim_t * ` as its first parameter instead of `void *`.
     * This function might be used when LVGL is bound to other languages because
     * it's more consistent to have `lv_anim_t *` as first parameter.
     * @param exec_cb  a function to execute.
     * @see lv_anim_set_custom_exec_cb
     */
    Anim& set_custom_exec_cb(lv_anim_custom_exec_cb_t exec_cb) noexcept { lv_anim_set_custom_exec_cb(&s_, exec_cb); return *this; }
    /**
     * Set a delay before starting the animation
     * @param delay  delay before the animation in milliseconds
     * @see lv_anim_set_delay
     */
    Anim& set_delay(uint32_t delay) noexcept { lv_anim_set_delay(&s_, delay); return *this; }
    /**
     * Set a function call when the animation is deleted.
     * @param deleted_cb  a function call when the animation is deleted
     * @see lv_anim_set_deleted_cb
     */
    Anim& set_deleted_cb(lv_anim_deleted_cb_t deleted_cb) noexcept { lv_anim_set_deleted_cb(&s_, deleted_cb); return *this; }
    /**
     * Set the duration of an animation
     * @param duration  duration of the animation in milliseconds
     * @see lv_anim_set_duration
     */
    Anim& set_duration(uint32_t duration) noexcept { lv_anim_set_duration(&s_, duration); return *this; }
    /**
     * Set a whether the animation's should be applied immediately or only when the delay expired.
     * @param en  true: apply the start value immediately in `lv_anim_start`; false: apply the start value only when `delay` ms is elapsed and the animations really starts
     * @see lv_anim_set_early_apply
     */
    Anim& set_early_apply(bool en) noexcept { lv_anim_set_early_apply(&s_, en); return *this; }
    /**
     * Set a function to animate `var`
     * @param exec_cb  a function to execute during animation LVGL's built-in functions can be used. E.g. lv_obj_set_x
     * @see lv_anim_set_exec_cb
     */
    Anim& set_exec_cb(lv_anim_exec_xcb_t exec_cb) noexcept { lv_anim_set_exec_cb(&s_, exec_cb); return *this; }
    /**
     * Takes the function itself as a template argument, so its real parameter types survive: the C idiom CASTS the pointer, which is undefined whenever they differ, and between the versions they do.
     * Set a function to animate `var`
     * @param exec_cb  a function to execute during animation LVGL's built-in functions can be used. E.g. lv_obj_set_x
     * @see lv_anim_set_exec_cb
     */
    template <auto Fn>
    Anim& set_exec_cb() noexcept { lv_anim_set_exec_cb(&s_, &detail::AnimExecXcbThunk<Fn>::call); return *this; }
    #if LV_USE_EXT_DATA
    /**
     * Associates external user data with an animation instance
     * Attaches arbitrary user-defined data to an LVGL animation object along with an optional
     * destructor callback that will be automatically invoked when the animation completes
     * or is deleted, enabling proper resource cleanup.
     * @param data  User-defined data pointer to associate
     * @see lv_anim_set_external_data
     */
    Anim& set_external_data(void* data, void (*arg)(void*)) noexcept { lv_anim_set_external_data(&s_, data, arg); return *this; }
    /**
     * Takes the function itself as a template argument, so its real parameter types survive: the C idiom CASTS the pointer, which is undefined whenever they differ, and between the versions they do.
     * Associates external user data with an animation instance
     * Attaches arbitrary user-defined data to an LVGL animation object along with an optional
     * destructor callback that will be automatically invoked when the animation completes
     * or is deleted, enabling proper resource cleanup.
     * @param data  User-defined data pointer to associate
     * @see lv_anim_set_external_data
     */
    template <auto Fn>
    Anim& set_external_data(void* data) noexcept { lv_anim_set_external_data(&s_, data, &detail::AnimSetExternalDataThunk<Fn>::call); return *this; }
    #endif // LV_USE_EXT_DATA

    /**
     * Set a function to use the current value of the variable and make start and end value
     * relative to the returned current value.
     * @param get_value_cb  a function call when the animation starts
     * @see lv_anim_set_get_value_cb
     */
    Anim& set_get_value_cb(lv_anim_get_value_cb_t get_value_cb) noexcept { lv_anim_set_get_value_cb(&s_, get_value_cb); return *this; }
    /**
     * Set the path (curve) of the animation.
     * @param path_cb  a function to set the current value of the animation.
     * @see lv_anim_set_path_cb
     */
    Anim& set_path_cb(lv_anim_path_cb_t path_cb) noexcept { lv_anim_set_path_cb(&s_, path_cb); return *this; }
    /**
     * Make the animation repeat itself.
     * @param cnt  repeat count or `LV_ANIM_REPEAT_INFINITE` for infinite repetition. 0: to disable repetition.
     * @see lv_anim_set_repeat_count
     */
    Anim& set_repeat_count(uint32_t cnt) noexcept { lv_anim_set_repeat_count(&s_, cnt); return *this; }
    /**
     * Set a delay before repeating the animation.
     * @param delay  delay in milliseconds before repeating the animation.
     * @see lv_anim_set_repeat_delay
     */
    Anim& set_repeat_delay(uint32_t delay) noexcept { lv_anim_set_repeat_delay(&s_, delay); return *this; }
    /**
     * Make the animation to play back to when the forward direction is ready
     * @param delay  delay in milliseconds before starting the playback animation.
     * @see lv_anim_set_reverse_delay
     */
    Anim& set_reverse_delay(uint32_t delay) noexcept { lv_anim_set_reverse_delay(&s_, delay); return *this; }
    /**
     * Make the animation to play back to when the forward direction is ready
     * @param duration  duration of playback animation in milliseconds. 0: disable playback
     * @see lv_anim_set_reverse_duration
     */
    Anim& set_reverse_duration(uint32_t duration) noexcept { lv_anim_set_reverse_duration(&s_, duration); return *this; }
    /**
     * Legacy `lv_anim_set_reverse_time` API will be removed soon, use `lv_anim_set_reverse_duration` instead.
     * @see lv_anim_set_reverse_time
     */
    Anim& set_reverse_time(uint32_t duration) noexcept { lv_anim_set_reverse_time(&s_, duration); return *this; }
    /**
     * Set a function call when the animation really starts (considering `delay`)
     * @param start_cb  a function call when the animation starts
     * @see lv_anim_set_start_cb
     */
    Anim& set_start_cb(lv_anim_start_cb_t start_cb) noexcept { lv_anim_set_start_cb(&s_, start_cb); return *this; }
    /**
     * Set the custom user data field of the animation.
     * @param user_data  pointer to the new user_data.
     * @see lv_anim_set_user_data
     */
    Anim& set_user_data(void* user_data) noexcept { lv_anim_set_user_data(&s_, user_data); return *this; }
    /**
     * Set the start and end values of an animation
     * @param start  the start value
     * @param end  the end value
     * @see lv_anim_set_values
     */
    Anim& set_values(int32_t start, int32_t end) noexcept { lv_anim_set_values(&s_, start, end); return *this; }
    /**
     * Set a variable to animate
     * @param var  pointer to a variable to animate
     * @see lv_anim_set_var
     */
    Anim& set_var(void* var) noexcept { lv_anim_set_var(&s_, var); return *this; }
    /**
     * Create an animation
     * @return pointer to the created animation (different from the `a` parameter)
     * @see lv_anim_start
     */
    lv_anim_t* start() const noexcept { return lv_anim_start(&s_); }
    #if LVPP_COMPAT_V8
    /** v8 spelling of `set_completed_cb`. */
    Anim& set_ready_cb(lv_anim_completed_cb_t completed_cb) noexcept { return set_completed_cb(completed_cb); }
    #endif // LVPP_COMPAT_V8

};

/**
 * Delete animation(s) of a variable with a given animator function
 * @param var  pointer to variable
 * @param exec_cb  a function pointer which is animating 'var', or NULL to ignore it and delete all the animations of 'var
 * @return true: at least 1 animation is deleted, false: no animation is deleted
 * @see lv_anim_delete
 */
inline bool anim_delete(void* var, lv_anim_exec_xcb_t exec_cb) noexcept { return lv_anim_delete(var, exec_cb); }

/**
 * Delete all the animations
 * @see lv_anim_delete_all
 */
inline void anim_delete_all() noexcept { lv_anim_delete_all(); }

/**
 * Get the animation of a variable and its `exec_cb`.
 * @param var  pointer to variable
 * @param exec_cb  a function pointer which is animating 'var', or NULL to return first matching 'var'
 * @return pointer to the animation.
 * @see lv_anim_get
 */
inline lv_anim_t* anim_get(void* var, lv_anim_exec_xcb_t exec_cb) noexcept { return lv_anim_get(var, exec_cb); }

/**
 * Get global animation refresher timer.
 * @return pointer to the animation refresher timer.
 * @see lv_anim_get_timer
 */
inline Timer anim_get_timer() noexcept { return Timer(lv_anim_get_timer()); }

/**
 * Get the number of currently running animations
 * @return the number of running animations
 * @see lv_anim_count_running
 */
inline uint16_t anim_count_running() noexcept { return lv_anim_count_running(); }

/**
 * Store the speed as a special value which can be used as time in animations.
 * It will be converted to time internally based on the start and end values.
 * The return value can be used as a constant with multiple animations
 * and let LVGL convert the speed to time based on the actual values.
 * LIMITATION: the max time stored this way can be 10,000 ms.
 * @param speed  the speed of the animation in with unit / sec resolution in 0..10k range
 * @return a special value which can be used as an animation time
 * @see lv_anim_speed
 */
inline uint32_t anim_speed(uint32_t speed) noexcept { return lv_anim_speed(speed); }

/**
 * Store the speed as a special value which can be used as time in animations.
 * It will be converted to time internally based on the start and end values.
 * The return value can be used as a constant with multiple animations
 * and let LVGL convert the speed to time based on the actual values.
 * @param speed  the speed of the animation in as unit / sec resolution in 0..10k range
 * @param min_time  the minimum time in 0..10k range
 * @param max_time  the maximum time in 0..10k range
 * @return a special value in where all three values are stored and can be used as an animation time
 * @see lv_anim_speed_clamped
 */
inline uint32_t anim_speed_clamped(uint32_t speed, uint32_t min_time, uint32_t max_time) noexcept { return lv_anim_speed_clamped(speed, min_time, max_time); }

/**
 * Resolve the speed (created with `lv_anim_speed` or `lv_anim_speed_clamped`) to time
 * based on start and end values.
 * @param speed  return values of `lv_anim_speed` or `lv_anim_speed_clamped`
 * @param start  the start value of the animation
 * @param end  the end value of the animation
 * @return the time required to get from `start` to `end` with the given `speed` setting
 * @see lv_anim_resolve_speed
 */
inline uint32_t anim_resolve_speed(uint32_t speed, int32_t start, int32_t end) noexcept { return lv_anim_resolve_speed(speed, start, end); }

/**
 * Calculate the time of an animation based on its speed, start and end values.
 * It simpler than `lv_anim_speed` or `lv_anim_speed_clamped` as it converts
 * speed, start, and end to a time immediately.
 * As it's simpler there is no limit on the maximum time.
 * @param speed  the speed of the animation
 * @param start  the start value
 * @param end  the end value
 * @return the time of the animation in milliseconds
 * @see lv_anim_speed_to_time
 */
inline uint32_t anim_speed_to_time(uint32_t speed, int32_t start, int32_t end) noexcept { return lv_anim_speed_to_time(speed, start, end); }

/**
 * Manually refresh the state of the animations.
 * Useful to make the animations running in a blocking process where
 * `lv_timer_handler` can't run for a while.
 * Shouldn't be used directly because it is called in `lv_refr_now()`.
 * @see lv_anim_refr_now
 */
inline void anim_refr_now() noexcept { lv_anim_refr_now(); }

} // namespace lv
