#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_LIBPNG
/**
 * Register the PNG decoder functions in LVGL
 * @see lv_libpng_init
 */
inline void libpng_init() noexcept { lv_libpng_init(); }

/** @see lv_libpng_deinit */
inline void libpng_deinit() noexcept { lv_libpng_deinit(); }
#endif // LV_USE_LIBPNG

} // namespace lv
