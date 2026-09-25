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
 * Lock LVGL's general mutex.
 * LVGL is not thread safe, so a mutex is used to avoid executing multiple LVGL functions at the same time
 * from different threads. It shall be called when calling LVGL functions from threads
 * different than lv_timer_handler's thread. It doesn't need to be called in LVGL events because
 * they are called from lv_timer_handler().
 * It is called internally in lv_timer_handler().
 * @see lv_lock
 */
inline void os_lock() noexcept { lv_lock(); }

/**
 * Same as `lv_lock()` but can be called from an interrupt.
 * @return LV_RESULT_OK: success; LV_RESULT_INVALID: failure
 * @see lv_lock_isr
 */
inline Result os_lock_isr() noexcept { return static_cast<Result>(lv_lock_isr()); }

/**
 * The pair of `lv_lock()` and `lv_lock_isr()`.
 * It unlocks LVGL general mutex.
 * It is called internally in lv_timer_handler().
 * @see lv_unlock
 */
inline void os_unlock() noexcept { lv_unlock(); }

/**
 * Sleeps the current thread by an amount of milliseconds.
 * @param ms  amount of milliseconds to sleep the current thread.
 * @see lv_sleep_ms
 */
inline void os_sleep_ms(uint32_t ms) noexcept { lv_sleep_ms(ms); }

} // namespace lv
