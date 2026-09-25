#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_LIBWEBP
/**
 * Register the WEBP decoder functions in LVGL
 * @see lv_libwebp_init
 */
inline void libwebp_init() noexcept { lv_libwebp_init(); }

/** @see lv_libwebp_deinit */
inline void libwebp_deinit() noexcept { lv_libwebp_deinit(); }
#endif // LV_USE_LIBWEBP

} // namespace lv
