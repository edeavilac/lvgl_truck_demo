#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_LIBJPEG_TURBO
/**
 * Register the JPEG-Turbo decoder functions in LVGL
 * @see lv_libjpeg_turbo_init
 */
inline void libjpeg_turbo_init() noexcept { lv_libjpeg_turbo_init(); }

/** @see lv_libjpeg_turbo_deinit */
inline void libjpeg_turbo_deinit() noexcept { lv_libjpeg_turbo_deinit(); }
#endif // LV_USE_LIBJPEG_TURBO

} // namespace lv
