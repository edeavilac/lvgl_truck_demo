#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/display/display.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/themes/theme.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_THEME_SIMPLE
/**
 * Initialize the theme
 * @param disp  pointer to display
 * @return a pointer to reference this theme later
 * @see lv_theme_simple_init
 */
inline Theme theme_simple_init(Display disp) noexcept { return Theme(lv_theme_simple_init(disp.raw())); }

/**
 * Check if the theme is initialized
 * @return true if default theme is initialized, false otherwise
 * @see lv_theme_simple_is_inited
 */
inline bool theme_simple_is_inited() noexcept { return lv_theme_simple_is_inited(); }

/**
 * Get simple theme
 * @return a pointer to simple theme, or NULL if this is not initialized
 * @see lv_theme_simple_get
 */
inline Theme theme_simple_get() noexcept { return Theme(lv_theme_simple_get()); }

/**
 * Deinitialize the simple theme
 * @see lv_theme_simple_deinit
 */
inline void theme_simple_deinit() noexcept { lv_theme_simple_deinit(); }
#endif // LV_USE_THEME_SIMPLE

} // namespace lv
