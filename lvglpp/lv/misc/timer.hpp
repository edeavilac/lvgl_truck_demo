#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

class Timer {
protected:
    lv_timer_t* p_ = nullptr;

public:
    constexpr Timer() noexcept = default;  /**< the "no object" handle */
    constexpr explicit Timer(lv_timer_t* p) noexcept : p_(p) {}

    constexpr lv_timer_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(Timer a, Timer b) noexcept { return a.p_ == b.p_; }

    /**
     * Create a new lv_timer
     * @param timer_xcb  a callback to call periodically. (the 'x' in the argument name indicates that it's not a fully generic function because it not follows the `func_name(object, callback, ...)` convention)
     * @param period  call period in ms unit
     * @param user_data  custom parameter
     * @return pointer to the new timer
     * @see lv_timer_create
     */
    static Timer create(lv_timer_cb_t timer_xcb, uint32_t period, void* user_data) noexcept { return Timer(lv_timer_create(timer_xcb, period, user_data)); }
    /**
     * Takes any callable instead of the C pair: the closure travels in the single void* LVGL stores, and the trampoline is chosen by its type.
     * Create a new lv_timer
     * @param timer_xcb  a callback to call periodically. (the 'x' in the argument name indicates that it's not a fully generic function because it not follows the `func_name(object, callback, ...)` convention)
     * @param period  call period in ms unit
     * @param user_data  custom parameter
     * @return pointer to the new timer
     * @see lv_timer_create
     */
    template <class F>
    static Timer create(uint32_t period, F&& f) noexcept { return Timer(lv_timer_create(detail::TimerCbClosure<std::decay_t<F>>::fn(f), period, detail::TimerCbClosure<std::decay_t<F>>::state(f))); }
    /**
     * Delete a lv_timer
     * @see lv_timer_delete
     */
    void delete_() const noexcept { lv_timer_delete(p_); }
    /**
     * Iterate through the timers
     * @return the next timer or NULL if there is no more timer
     * @see lv_timer_get_next
     */
    Timer get_next() const noexcept { return Timer(lv_timer_get_next(p_)); }
    /**
     * Get the pause state of a timer
     * @return true: timer is paused; false: timer is running
     * @see lv_timer_get_paused
     */
    bool get_paused() const noexcept { return lv_timer_get_paused(p_); }
    /**
     * Get the user_data passed when the timer was created
     * @return pointer to the user_data
     * @see lv_timer_get_user_data
     */
    void* get_user_data() const noexcept { return lv_timer_get_user_data(p_); }
    /**
     * Pause a timer.
     * It is typically safe to call from an interrupt handler or a different thread.
     * @see lv_timer_pause
     */
    void pause() const noexcept { lv_timer_pause(p_); }
    /**
     * Make a lv_timer ready. It will not wait its period.
     * @see lv_timer_ready
     */
    void ready() const noexcept { lv_timer_ready(p_); }
    /**
     * Reset a lv_timer.
     * It will be called the previously set period milliseconds later.
     * @see lv_timer_reset
     */
    void reset() const noexcept { lv_timer_reset(p_); }
    /**
     * Resume a timer.
     * @see lv_timer_resume
     */
    void resume() const noexcept { lv_timer_resume(p_); }
    /**
     * Set whether a lv_timer will be deleted automatically when it is called `repeat_count` times.
     * @param auto_delete  true: auto delete; false: timer will be paused when it is called `repeat_count` times.
     * @see lv_timer_set_auto_delete
     */
    void set_auto_delete(bool auto_delete) const noexcept { lv_timer_set_auto_delete(p_, auto_delete); }
    /**
     * Set the callback to the timer (the function to call periodically)
     * @param timer_cb  the function to call periodically
     * @see lv_timer_set_cb
     */
    void set_cb(lv_timer_cb_t timer_cb) const noexcept { lv_timer_set_cb(p_, timer_cb); }
    #if LV_USE_EXT_DATA
    /**
     * Attaches external user data and destructor callback to a timer object
     * Associates custom user data with an LVGL timer and specifies a destructor function
     * that will be automatically invoked when the timer is deleted to properly clean up
     * the associated resources.
     * @param data  User-defined data pointer to associate with the timer
     * @see lv_timer_set_external_data
     */
    void set_external_data(void* data, void (*arg)(void*)) const noexcept { lv_timer_set_external_data(p_, data, arg); }
    /**
     * Takes the function itself as a template argument, so its real parameter types survive: the C idiom CASTS the pointer, which is undefined whenever they differ, and between the versions they do.
     * Attaches external user data and destructor callback to a timer object
     * Associates custom user data with an LVGL timer and specifies a destructor function
     * that will be automatically invoked when the timer is deleted to properly clean up
     * the associated resources.
     * @param data  User-defined data pointer to associate with the timer
     * @see lv_timer_set_external_data
     */
    template <auto Fn>
    void set_external_data(void* data) const noexcept { lv_timer_set_external_data(p_, data, &detail::TimerSetExternalDataThunk<Fn>::call); }
    #endif // LV_USE_EXT_DATA

    /**
     * Set new period for a lv_timer
     * @param period  the new period
     * @see lv_timer_set_period
     */
    void set_period(uint32_t period) const noexcept { lv_timer_set_period(p_, period); }
    /**
     * Set the number of times a timer will repeat.
     * @param repeat_count  -1 : infinity; 0 : stop ; n>0: residual times
     * @see lv_timer_set_repeat_count
     */
    void set_repeat_count(int32_t repeat_count) const noexcept { lv_timer_set_repeat_count(p_, repeat_count); }
    /**
     * Set custom parameter to the lv_timer.
     * @param user_data  custom parameter
     * @see lv_timer_set_user_data
     */
    void set_user_data(void* user_data) const noexcept { lv_timer_set_user_data(p_, user_data); }
    #if LVPP_COMPAT_V8
    /** v8 spelling of `delete_`. */
    void del() const noexcept { return delete_(); }
    #endif // LVPP_COMPAT_V8

};
static_assert(sizeof(Timer) == sizeof(lv_timer_t*));
static_assert(__is_trivially_copyable(Timer));

/**
 * Call it periodically to handle lv_timers.
 * @return time till it needs to be run next (in ms)
 * @see lv_timer_handler
 */
inline uint32_t timer_handler() noexcept { return lv_timer_handler(); }

/**
 * Call it in the super-loop of main() or threads. It will run lv_timer_handler()
 * with a given period in ms. You can use it with sleep or delay in OS environment.
 * This function is used to simplify the porting.
 * @param period  the period for running lv_timer_handler()
 * @return the time after which it must be called again
 * @see lv_timer_handler_run_in_period
 */
inline uint32_t timer_handler_run_in_period(uint32_t period) noexcept { return lv_timer_handler_run_in_period(period); }

/**
 * Call it in the super-loop of main() or threads. It will automatically call lv_timer_handler() at the right time.
 * This function is used to simplify the porting.
 * @see lv_timer_periodic_handler
 */
inline void timer_periodic_handler() noexcept { lv_timer_periodic_handler(); }

/**
 * Set the resume callback to the timer handler
 * @param cb  the function to call when timer handler is resumed
 * @param data  pointer to a resume data
 * @see lv_timer_handler_set_resume_cb
 */
inline void timer_handler_set_resume_cb(lv_timer_handler_resume_cb_t cb, void* data) noexcept { lv_timer_handler_set_resume_cb(cb, data); }

/**
 * Takes any callable instead of the C pair.
 * Set the resume callback to the timer handler
 * @param cb  the function to call when timer handler is resumed
 * @param data  pointer to a resume data
 * @see lv_timer_handler_set_resume_cb
 */
template <class F>
inline void timer_handler_set_resume_cb(F&& f) noexcept { lv_timer_handler_set_resume_cb(detail::TimerHandlerResumeCbClosure<std::decay_t<F>>::fn(f), detail::TimerHandlerResumeCbClosure<std::decay_t<F>>::state(f)); }

/**
 * Create an "empty" timer. It needs to be initialized with at least
 * `lv_timer_set_cb` and `lv_timer_set_period`
 * @return pointer to the created timer
 * @see lv_timer_create_basic
 */
inline Timer timer_create_basic() noexcept { return Timer(lv_timer_create_basic()); }

/**
 * Enable or disable the whole lv_timer handling
 * @param en  true: lv_timer handling is running, false: lv_timer handling is suspended
 * @see lv_timer_enable
 */
inline void timer_enable(bool en) noexcept { lv_timer_enable(en); }

/**
 * Get idle percentage
 * @return the lv_timer idle in percentage
 * @see lv_timer_get_idle
 */
inline uint32_t timer_get_idle() noexcept { return lv_timer_get_idle(); }

/**
 * Get the time remaining until the next timer will run
 * @return the time remaining in ms
 * @see lv_timer_get_time_until_next
 */
inline uint32_t timer_get_time_until_next() noexcept { return lv_timer_get_time_until_next(); }

} // namespace lv
