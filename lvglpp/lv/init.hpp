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
 * Initialize LVGL library.
 * Should be called before any other LVGL related function.
 * @see lv_init
 */
inline void init() noexcept { lv_init(); }

/**
 * Deinit the 'lv' library
 * @see lv_deinit
 */
inline void deinit() noexcept { lv_deinit(); }

/**
 * Returns whether the 'lv' library is currently initialized
 * @see lv_is_initialized
 */
inline bool is_initialized() noexcept { return lv_is_initialized(); }

} // namespace lv
