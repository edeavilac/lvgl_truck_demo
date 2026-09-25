#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_TEST
/**
 * Emulate a delay. It's not real delay, but it tricks LVGL to think that the
 * required time has been elapsed.
 * `lv_timer_handler` is called after each millisecond, meaning all the events
 * will be fired inside this function.
 * At the end the animations and display will be also updated.
 * @param ms  the number of milliseconds to pass
 * @see lv_test_wait
 */
inline void test_wait(uint32_t ms) noexcept { lv_test_wait(ms); }

/**
 * Emulates some time passing.
 * Update the animations and the display only once at the end.
 * @param ms  the number of milliseconds to pass
 * @see lv_test_fast_forward
 */
inline void test_fast_forward(uint32_t ms) noexcept { lv_test_fast_forward(ms); }
#endif // LV_USE_TEST

#if (LV_USE_TEST) && (!(LV_USE_STDLIB_MALLOC != LV_STDLIB_BUILTIN))
/** @see lv_test_get_free_mem */
inline uint32_t test_get_free_mem() noexcept { return lv_test_get_free_mem(); }
#endif // (LV_USE_TEST) && (!(LV_USE_STDLIB_MALLOC != LV_STDLIB_BUILTIN))

} // namespace lv
