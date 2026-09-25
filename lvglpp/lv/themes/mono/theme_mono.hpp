#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/display/display.hpp"
#include "lv/enums.hpp"
#include "lv/font/font.hpp"
#include "lv/fwd.hpp"
#include "lv/themes/theme.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_THEME_MONO
/**
 * Initialize the theme
 * @param disp  pointer to display
 * @param dark_bg  
 * @param font  pointer to a font to use.
 * @return a pointer to reference this theme later
 * @see lv_theme_mono_init
 */
inline Theme theme_mono_init(Display disp, bool dark_bg, Font font) noexcept { return Theme(lv_theme_mono_init(disp.raw(), dark_bg, font.raw())); }

/**
 * Check if the theme is initialized
 * @return true if default theme is initialized, false otherwise
 * @see lv_theme_mono_is_inited
 */
inline bool theme_mono_is_inited() noexcept { return lv_theme_mono_is_inited(); }

/**
 * Get mono theme
 * @return a pointer to mono theme, or NULL if this is not initialized
 * @see lv_theme_mono_get
 */
inline Theme theme_mono_get() noexcept { return Theme(lv_theme_mono_get()); }

/**
 * Deinitialize the mono theme
 * @see lv_theme_mono_deinit
 */
inline void theme_mono_deinit() noexcept { lv_theme_mono_deinit(); }
#endif // LV_USE_THEME_MONO

} // namespace lv
