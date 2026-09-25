#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

class Theme {
protected:
    lv_theme_t* p_ = nullptr;

public:
    constexpr Theme() noexcept = default;  /**< the "no object" handle */
    constexpr explicit Theme(lv_theme_t* p) noexcept : p_(p) {}

    constexpr lv_theme_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(Theme a, Theme b) noexcept { return a.p_ == b.p_; }

    /**
     * Copy 'src' theme into 'dst'
     * @param src  pointer to the source theme
     * @see lv_theme_copy
     */
    void copy(Theme src) const noexcept;
    /**
     * Creates a new theme
     * @return the new theme or NULL if allocation failed
     * @see lv_theme_create
     */
    static Theme create() noexcept;
    /**
     * Delete a theme
     * @see lv_theme_delete
     */
    void delete_() const noexcept;
    /**
     * Set an apply callback for a theme.
     * The apply callback is used to add styles to different objects
     * @param apply_cb  pointer to the callback
     * @see lv_theme_set_apply_cb
     */
    void set_apply_cb(lv_theme_apply_cb_t apply_cb) const noexcept;
    #if LV_USE_EXT_DATA
    /**
     * Attaches external user data and destructor callback to the theme
     * Associates custom user data with an LVGL theme and specifies a destructor function
     * that will be automatically invoked when the theme is deleted to properly clean up
     * the associated resources.
     * @param data  User-defined data pointer to associate with the theme
     * @see lv_theme_set_external_data
     */
    void set_external_data(void* data, void (*arg)(void*)) const noexcept;
    /**
     * Takes the function itself as a template argument, so its real parameter types survive: the C idiom CASTS the pointer, which is undefined whenever they differ, and between the versions they do.
     * Attaches external user data and destructor callback to the theme
     * Associates custom user data with an LVGL theme and specifies a destructor function
     * that will be automatically invoked when the theme is deleted to properly clean up
     * the associated resources.
     * @param data  User-defined data pointer to associate with the theme
     * @see lv_theme_set_external_data
     */
    template <auto Fn>
    void set_external_data(void* data) const noexcept;
    #endif // LV_USE_EXT_DATA

    /**
     * Set a base theme for a theme.
     * The styles from the base them will be added before the styles of the current theme.
     * Arbitrary long chain of themes can be created by setting base themes.
     * @param parent  pointer to the base theme
     * @see lv_theme_set_parent
     */
    void set_parent(Theme parent) const noexcept;
};
static_assert(sizeof(Theme) == sizeof(lv_theme_t*));
static_assert(__is_trivially_copyable(Theme));

/**
 * Get the theme assigned to the display of the object
 * @param obj  pointer to a theme object
 * @return the theme of the object's display (can be NULL)
 * @see lv_theme_get_from_obj
 */
inline Theme theme_get_from_obj(Obj obj) noexcept;

/**
 * Apply the active theme on an object
 * @param obj  pointer to an object
 * @see lv_theme_apply
 */
inline void theme_apply(Obj obj) noexcept;

/**
 * Get the small font of the theme
 * @param obj  pointer to an object
 * @return pointer to the font
 * @see lv_theme_get_font_small
 */
inline Font theme_get_font_small(Obj obj) noexcept;

/**
 * Get the normal font of the theme
 * @param obj  pointer to an object
 * @return pointer to the font
 * @see lv_theme_get_font_normal
 */
inline Font theme_get_font_normal(Obj obj) noexcept;

/**
 * Get the subtitle font of the theme
 * @param obj  pointer to an object
 * @return pointer to the font
 * @see lv_theme_get_font_large
 */
inline Font theme_get_font_large(Obj obj) noexcept;

/**
 * Get the primary color of the theme
 * @param obj  pointer to an object
 * @return the color
 * @see lv_theme_get_color_primary
 */
inline Color theme_get_color_primary(Obj obj) noexcept;

/**
 * Get the secondary color of the theme
 * @param obj  pointer to an object
 * @return the color
 * @see lv_theme_get_color_secondary
 */
inline Color theme_get_color_secondary(Obj obj) noexcept;

} // namespace lv
