#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

/**
 * You have to call this function periodically.
 * It is typically safe to call from an interrupt handler or a different thread.
 * @param tick_period  the call period of this function in milliseconds
 * @see lv_tick_inc
 */
inline void tick_inc(uint32_t tick_period) noexcept { lv_tick_inc(tick_period); }

/**
 * Get the elapsed milliseconds since start up
 * @return the elapsed milliseconds
 * @see lv_tick_get
 */
inline uint32_t tick_get() noexcept { return lv_tick_get(); }

/**
 * Get the elapsed milliseconds since a previous time stamp
 * @param prev_tick  a previous time stamp (return value of lv_tick_get() )
 * @return the elapsed milliseconds since 'prev_tick'
 * @see lv_tick_elaps
 */
inline uint32_t tick_elaps(uint32_t prev_tick) noexcept { return lv_tick_elaps(prev_tick); }

/**
 * Get the elapsed milliseconds between two time stamps
 * @param tick  a time stamp
 * @param prev_tick  a time stamp before `tick`
 * @return the elapsed milliseconds between `prev_tick` and `tick`
 * @see lv_tick_diff
 */
inline uint32_t tick_diff(uint32_t tick, uint32_t prev_tick) noexcept { return lv_tick_diff(tick, prev_tick); }

/**
 * Delay for the given milliseconds.
 * By default it's a blocking delay, but with `lv_delay_set_cb()`
 * a custom delay function can be set too
 * @param ms  the number of milliseconds to delay
 * @see lv_delay_ms
 */
inline void tick_delay_ms(uint32_t ms) noexcept { lv_delay_ms(ms); }

/**
 * Set a callback for a blocking delay
 * @param cb  pointer to a callback
 * @see lv_delay_set_cb
 */
inline void tick_delay_set_cb(lv_delay_cb_t cb) noexcept { lv_delay_set_cb(cb); }

/**
 * Set the custom callback for 'lv_tick_get'
 * @param cb  call this callback on 'lv_tick_get'
 * @see lv_tick_set_cb
 */
inline void tick_set_cb(lv_tick_get_cb_t cb) noexcept { lv_tick_set_cb(cb); }

/**
 * Get the custom callback for 'lv_tick_get'
 * @return call this callback on 'lv_tick_get'
 * @see lv_tick_get_cb
 */
inline lv_tick_get_cb_t tick_get_cb() noexcept { return lv_tick_get_cb(); }

} // namespace lv
