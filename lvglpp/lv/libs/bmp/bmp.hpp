#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_BMP
/** @see lv_bmp_init */
inline void bmp_init() noexcept { lv_bmp_init(); }

/** @see lv_bmp_deinit */
inline void bmp_deinit() noexcept { lv_bmp_deinit(); }
#endif // LV_USE_BMP

} // namespace lv
