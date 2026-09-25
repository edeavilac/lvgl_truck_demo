#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_LODEPNG
/**
 * Register the PNG decoder functions in LVGL
 * @see lv_lodepng_init
 */
inline void lodepng_init() noexcept { lv_lodepng_init(); }

/** @see lv_lodepng_deinit */
inline void lodepng_deinit() noexcept { lv_lodepng_deinit(); }
#endif // LV_USE_LODEPNG

} // namespace lv
