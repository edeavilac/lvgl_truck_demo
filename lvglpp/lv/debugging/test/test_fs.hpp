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
 * Initialize the test file system driver
 * @see lv_test_fs_init
 */
inline void test_fs_init() noexcept { lv_test_fs_init(); }

/**
 * Set whether the test file system is ready
 * @param ready  true: ready, false: not ready
 * @see lv_test_fs_set_ready
 */
inline void test_fs_set_ready(bool ready) noexcept { lv_test_fs_set_ready(ready); }

/**
 * Set whether the open callback of the test file system is cleared
 * @param is_clear  true: clear, false: not clear
 * @see lv_test_fs_clear_open_cb
 */
inline void test_fs_clear_open_cb(bool is_clear) noexcept { lv_test_fs_clear_open_cb(is_clear); }

/**
 * Set whether the close callback of the test file system is cleared
 * @param is_clear  true: clear, false: not clear
 * @see lv_test_fs_clear_close_cb
 */
inline void test_fs_clear_close_cb(bool is_clear) noexcept { lv_test_fs_clear_close_cb(is_clear); }
#endif // LV_USE_TEST

} // namespace lv
