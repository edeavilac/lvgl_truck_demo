#pragma once
// Bodies of themes/theme.hpp, separated because its file cycle needs every type
// complete. Same mechanism as D-C7, applied where the graph asks for it.
// Included by the umbrella and never by a header: it is NOT a translation
// unit and every definition in it is `inline`. The stem says so, not the
// extension, so a glob written for *.hpp still installs it.

#include "lv/lvgl.hpp"

namespace lv {

inline void Theme::copy(Theme src) const noexcept { lv_theme_copy(p_, src.raw()); }

inline Theme Theme::create() noexcept { return Theme(lv_theme_create()); }

inline void Theme::delete_() const noexcept { lv_theme_delete(p_); }

inline void Theme::set_apply_cb(lv_theme_apply_cb_t apply_cb) const noexcept { lv_theme_set_apply_cb(p_, apply_cb); }

#if LV_USE_EXT_DATA
inline void Theme::set_external_data(void* data, void (*arg)(void*)) const noexcept { lv_theme_set_external_data(p_, data, arg); }

template <auto Fn>
inline void Theme::set_external_data(void* data) const noexcept { lv_theme_set_external_data(p_, data, &detail::ThemeSetExternalDataThunk<Fn>::call); }
#endif // LV_USE_EXT_DATA

inline void Theme::set_parent(Theme parent) const noexcept { lv_theme_set_parent(p_, parent.raw()); }

inline Theme theme_get_from_obj(Obj obj) noexcept { return Theme(lv_theme_get_from_obj(obj.raw())); }

inline void theme_apply(Obj obj) noexcept { lv_theme_apply(obj.raw()); }

inline Font theme_get_font_small(Obj obj) noexcept { return Font(const_cast<lv_font_t*>(lv_theme_get_font_small(obj.raw()))); }

inline Font theme_get_font_normal(Obj obj) noexcept { return Font(const_cast<lv_font_t*>(lv_theme_get_font_normal(obj.raw()))); }

inline Font theme_get_font_large(Obj obj) noexcept { return Font(const_cast<lv_font_t*>(lv_theme_get_font_large(obj.raw()))); }

inline Color theme_get_color_primary(Obj obj) noexcept { return Color{lv_theme_get_color_primary(obj.raw())}; }

inline Color theme_get_color_secondary(Obj obj) noexcept { return Color{lv_theme_get_color_secondary(obj.raw())}; }

} // namespace lv
