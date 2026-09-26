#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/display/display.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_TEST
/**
 * Create a dummy display for for the tests
 * @param hor_res  the maximal horizontal resolution
 * @param ver_res  the maximal vertical resolution
 * @return the created display
 * @see lv_test_display_create
 */
inline Display test_display_create(int32_t hor_res, int32_t ver_res) noexcept { return Display(lv_test_display_create(hor_res, ver_res)); }
#endif // LV_USE_TEST

} // namespace lv
