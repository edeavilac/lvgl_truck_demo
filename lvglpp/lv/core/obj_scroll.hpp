#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core/obj.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>
#include <utility>

namespace lv {

/**
 * Scroll by given amount of pixels.
 * @param obj  pointer to scrollable Widget to scroll
 * @param dx  pixels to scroll horizontally
 * @param dy  pixels to scroll vertically
 * @param anim_en  LV_ANIM_ON: scroll with animation; LV_ANIM_OFF: scroll immediately
 * @see lv_obj_scroll_by
 */
inline void obj_scroll_by(Obj obj, int32_t dx, int32_t dy, lv_anim_enable_t anim_en) noexcept { lv_obj_scroll_by(obj.raw(), dx, dy, anim_en); }

/**
 * Scroll by given amount of pixels.
 * `dx` and `dy` will be limited internally to allow scrolling only on the content area.
 * @param obj  pointer to scrollable Widget to scroll
 * @param dx  pixels to scroll horizontally
 * @param dy  pixels to scroll vertically
 * @param anim_en  LV_ANIM_ON: scroll with animation; LV_ANIM_OFF: scroll immediately
 * @see lv_obj_scroll_by_bounded
 */
inline void obj_scroll_by_bounded(Obj obj, int32_t dx, int32_t dy, lv_anim_enable_t anim_en) noexcept { lv_obj_scroll_by_bounded(obj.raw(), dx, dy, anim_en); }

/**
 * Scroll to given coordinate on Widget.
 * `x` and `y` will be limited internally to allow scrolling only on the content area.
 * @param obj  pointer to scrollable Widget to scroll
 * @param x  pixels to scroll horizontally
 * @param y  pixels to scroll vertically
 * @param anim_en  LV_ANIM_ON: scroll with animation; LV_ANIM_OFF: scroll immediately
 * @see lv_obj_scroll_to
 */
inline void obj_scroll_to(Obj obj, int32_t x, int32_t y, lv_anim_enable_t anim_en) noexcept { lv_obj_scroll_to(obj.raw(), x, y, anim_en); }

/**
 * Scroll to X coordinate on Widget.
 * `x` will be limited internally to allow scrolling only on the content area.
 * @param obj  pointer to scrollable Widget to scroll
 * @param x  pixels to scroll horizontally
 * @param anim_en  LV_ANIM_ON: scroll with animation; LV_ANIM_OFF: scroll immediately
 * @see lv_obj_scroll_to_x
 */
inline void obj_scroll_to_x(Obj obj, int32_t x, lv_anim_enable_t anim_en) noexcept { lv_obj_scroll_to_x(obj.raw(), x, anim_en); }

/**
 * Scroll to Y coordinate on Widget.
 * `y` will be limited internally to allow scrolling only on the content area.
 * @param obj  pointer to scrollable Widget to scroll
 * @param y  pixels to scroll vertically
 * @param anim_en  LV_ANIM_ON: scroll with animation; LV_ANIM_OFF: scroll immediately
 * @see lv_obj_scroll_to_y
 */
inline void obj_scroll_to_y(Obj obj, int32_t y, lv_anim_enable_t anim_en) noexcept { lv_obj_scroll_to_y(obj.raw(), y, anim_en); }

/**
 * Scroll `obj`'s parent Widget until `obj` becomes visible.
 * @param obj  pointer to Widget to scroll into view
 * @param anim_en  LV_ANIM_ON: scroll with animation; LV_ANIM_OFF: scroll immediately
 * @see lv_obj_scroll_to_view
 */
inline void obj_scroll_to_view(Obj obj, lv_anim_enable_t anim_en) noexcept { lv_obj_scroll_to_view(obj.raw(), anim_en); }

/**
 * Scroll `obj`'s parent Widgets recursively until `obj` becomes visible.
 * Widget will be scrolled into view even it has nested scrollable parents.
 * @param obj  pointer to Widget to scroll into view
 * @param anim_en  LV_ANIM_ON: scroll with animation; LV_ANIM_OFF: scroll immediately
 * @see lv_obj_scroll_to_view_recursive
 */
inline void obj_scroll_to_view_recursive(Obj obj, lv_anim_enable_t anim_en) noexcept { lv_obj_scroll_to_view_recursive(obj.raw(), anim_en); }

inline int32_t Obj::get_scroll_bottom() const noexcept { return lv_obj_get_scroll_bottom(p_); }

inline Dir Obj::get_scroll_dir() const noexcept { return static_cast<Dir>(lv_obj_get_scroll_dir(p_)); }

inline Point Obj::get_scroll_end() const noexcept {
    lv_point_t end_out{};
    lv_obj_get_scroll_end(p_, &end_out);
    return Point{end_out};
}

inline int32_t Obj::get_scroll_left() const noexcept { return lv_obj_get_scroll_left(p_); }

inline int32_t Obj::get_scroll_right() const noexcept { return lv_obj_get_scroll_right(p_); }

inline ScrollSnap Obj::get_scroll_snap_x() const noexcept { return static_cast<ScrollSnap>(lv_obj_get_scroll_snap_x(p_)); }

inline ScrollSnap Obj::get_scroll_snap_y() const noexcept { return static_cast<ScrollSnap>(lv_obj_get_scroll_snap_y(p_)); }

inline int32_t Obj::get_scroll_top() const noexcept { return lv_obj_get_scroll_top(p_); }

inline int32_t Obj::get_scroll_x() const noexcept { return lv_obj_get_scroll_x(p_); }

inline int32_t Obj::get_scroll_y() const noexcept { return lv_obj_get_scroll_y(p_); }

inline std::pair<Area, Area> Obj::get_scrollbar_area() const noexcept {
    lv_area_t hor_out{};
    lv_area_t ver_out{};
    lv_obj_get_scrollbar_area(p_, &hor_out, &ver_out);
    return std::pair<Area, Area>{Area{hor_out}, Area{ver_out}};
}

inline ScrollbarMode Obj::get_scrollbar_mode() const noexcept { return static_cast<ScrollbarMode>(lv_obj_get_scrollbar_mode(p_)); }

inline bool Obj::is_scrolling() const noexcept { return lv_obj_is_scrolling(p_); }

inline void Obj::readjust_scroll(lv_anim_enable_t anim_en) const noexcept { lv_obj_readjust_scroll(p_, anim_en); }

inline void Obj::scrollbar_invalidate() const noexcept { lv_obj_scrollbar_invalidate(p_); }

inline void Obj::set_scroll_dir(Dir dir) const noexcept { lv_obj_set_scroll_dir(p_, static_cast<lv_dir_t>(dir)); }

inline void Obj::set_scroll_snap_x(ScrollSnap align) const noexcept { lv_obj_set_scroll_snap_x(p_, static_cast<lv_scroll_snap_t>(align)); }

inline void Obj::set_scroll_snap_y(ScrollSnap align) const noexcept { lv_obj_set_scroll_snap_y(p_, static_cast<lv_scroll_snap_t>(align)); }

inline void Obj::set_scrollbar_mode(ScrollbarMode mode) const noexcept { lv_obj_set_scrollbar_mode(p_, static_cast<lv_scrollbar_mode_t>(mode)); }

inline void Obj::stop_scroll_anim() const noexcept { lv_obj_stop_scroll_anim(p_); }

inline void Obj::update_snap(lv_anim_enable_t anim_en) const noexcept { lv_obj_update_snap(p_, anim_en); }

} // namespace lv
