#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core.hpp"
#include "lv/core/obj.hpp"
#include "lv/core/observer.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/style.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

/**
 * Notify all object if a style is modified
 * @param style  pointer to a style. Only the objects with this style will be notified (NULL to notify all objects)
 * @see lv_obj_report_style_change
 */
inline void obj_report_style_change(Style& style) noexcept { lv_obj_report_style_change(style.raw()); }

/**
 * Temporary disable a style for a selector. It will look like is the style wasn't added
 * @param obj  pointer to an object
 * @param style  pointer to a style
 * @param selector  the selector of a style (e.g. LV_STATE_PRESSED | LV_PART_KNOB)
 * @param dis  true: disable the style, false: enable the style
 * @see lv_obj_style_set_disabled
 */
inline void obj_style_set_disabled(Obj obj, Style& style, lv_style_selector_t selector, bool dis) noexcept { lv_obj_style_set_disabled(obj.raw(), style.raw(), selector, dis); }

/**
 * Get if a given style is disabled on an object.
 * @param obj  pointer to an object
 * @param style  pointer to a style
 * @param selector  the selector of a style (e.g. LV_STATE_PRESSED | LV_PART_KNOB)
 * @return true: disable the style, false: enable the style
 * @see lv_obj_style_get_disabled
 */
inline bool obj_style_get_disabled(Obj obj, Style& style, lv_style_selector_t selector) noexcept { return lv_obj_style_get_disabled(obj.raw(), style.raw(), selector); }

/**
 * Enable or disable automatic style refreshing when a new style is added/removed to/from an object
 * or any other style change happens.
 * @param en  true: enable refreshing; false: disable refreshing
 * @see lv_obj_enable_style_refresh
 */
inline void obj_enable_style_refresh(bool en) noexcept { lv_obj_enable_style_refresh(en); }

/**
 * Used internally for color filtering
 * @see lv_obj_style_apply_color_filter
 */
inline lv_style_value_t obj_style_apply_color_filter(Obj obj, Part part, lv_style_value_t v) noexcept { return lv_obj_style_apply_color_filter(obj.raw(), static_cast<lv_part_t>(part), v); }

/** @see lv_obj_style_get_selector_state */
inline State obj_style_get_selector_state(lv_style_selector_t selector) noexcept { return static_cast<State>(lv_obj_style_get_selector_state(selector)); }

/** @see lv_obj_style_get_selector_part */
inline Part obj_style_get_selector_part(lv_style_selector_t selector) noexcept { return static_cast<Part>(lv_obj_style_get_selector_part(selector)); }

/**
 * Apply recolor effect to the input color based on the object's style properties.
 * @param obj  the target object containing recolor style properties
 * @param part  the part to retrieve recolor styles.
 * @param color  the original color to be modified
 * @return the blended color after applying recolor and opacity
 * @see lv_obj_style_apply_recolor
 */
inline lv_color32_t obj_style_apply_recolor(Obj obj, Part part, lv_color32_t color) noexcept { return lv_obj_style_apply_recolor(obj.raw(), static_cast<lv_part_t>(part), color); }

inline void Obj::add_style(Style& style, lv_style_selector_t selector) const noexcept { lv_obj_add_style(p_, style.raw(), selector); }

#if LV_USE_OBSERVER
inline Observer Obj::bind_style(Style& style, lv_style_selector_t selector, Subject& subject, int32_t ref_value) const noexcept { return Observer(lv_obj_bind_style(p_, style.raw(), selector, subject.raw(), ref_value)); }

inline Observer Obj::bind_style_prop(lv_style_prop_t prop, lv_style_selector_t selector, Subject& subject) const noexcept { return Observer(lv_obj_bind_style_prop(p_, prop, selector, subject.raw())); }
#endif // LV_USE_OBSERVER

inline TextAlign Obj::calculate_style_text_align(Part part, const char* txt) const noexcept { return static_cast<TextAlign>(lv_obj_calculate_style_text_align(p_, static_cast<lv_part_t>(part), txt)); }

inline void Obj::fade_in(uint32_t time, uint32_t delay) const noexcept { lv_obj_fade_in(p_, time, delay); }

inline void Obj::fade_out(uint32_t time, uint32_t delay) const noexcept { lv_obj_fade_out(p_, time, delay); }

inline StyleRes Obj::get_local_style_prop(lv_style_prop_t prop, lv_style_value_t* value, lv_style_selector_t selector) const noexcept { return static_cast<StyleRes>(lv_obj_get_local_style_prop(p_, prop, value, selector)); }

inline bool Obj::has_style_prop(lv_style_selector_t selector, lv_style_prop_t prop) const noexcept { return lv_obj_has_style_prop(p_, selector, prop); }

inline void Obj::refresh_style(Part part, lv_style_prop_t prop) const noexcept { lv_obj_refresh_style(p_, static_cast<lv_part_t>(part), prop); }

inline bool Obj::remove_local_style_prop(lv_style_prop_t prop, lv_style_selector_t selector) const noexcept { return lv_obj_remove_local_style_prop(p_, prop, selector); }

inline void Obj::remove_style(Style& style, lv_style_selector_t selector) const noexcept { lv_obj_remove_style(p_, style.raw(), selector); }

inline void Obj::remove_style_all() const noexcept { lv_obj_remove_style_all(p_); }

inline void Obj::remove_theme(lv_style_selector_t selector) const noexcept { lv_obj_remove_theme(p_, selector); }

inline bool Obj::replace_style(Style& old_style, Style& new_style, lv_style_selector_t selector) const noexcept { return lv_obj_replace_style(p_, old_style.raw(), new_style.raw(), selector); }

inline void Obj::set_local_style_prop(lv_style_prop_t prop, lv_style_value_t value, lv_style_selector_t selector) const noexcept { lv_obj_set_local_style_prop(p_, prop, value, selector); }

} // namespace lv
