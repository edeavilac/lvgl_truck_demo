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

#if LV_USE_THEME_DEFAULT
/**
 * Initialize the theme
 * @param disp  pointer to display
 * @param color_primary  the primary color of the theme
 * @param color_secondary  the secondary color for the theme
 * @param dark  
 * @param font  pointer to a font to use.
 * @return a pointer to reference this theme later
 * @see lv_theme_default_init
 */
inline Theme theme_default_init(Display disp, Color color_primary, Color color_secondary, bool dark, Font font) noexcept { return Theme(lv_theme_default_init(disp.raw(), color_primary.raw(), color_secondary.raw(), dark, font.raw())); }

/**
 * Check if default theme is initialized
 * @return true if default theme is initialized, false otherwise
 * @see lv_theme_default_is_inited
 */
inline bool theme_default_is_inited() noexcept { return lv_theme_default_is_inited(); }

/**
 * Get default theme
 * @return a pointer to default theme, or NULL if this is not initialized
 * @see lv_theme_default_get
 */
inline Theme theme_default_get() noexcept { return Theme(lv_theme_default_get()); }

/**
 * Deinitialize the default theme
 * @see lv_theme_default_deinit
 */
inline void theme_default_deinit() noexcept { lv_theme_default_deinit(); }
#endif // LV_USE_THEME_DEFAULT

} // namespace lv
