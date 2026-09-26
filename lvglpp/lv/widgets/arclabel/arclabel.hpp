#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core/obj.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_ARCLABEL != 0
/** @see lv_arclabel_class */
inline constexpr ObjClass arclabel_class = ObjClass(const_cast<lv_obj_class_t*>(&lv_arclabel_class));

/**
 * Create an arc label object
 * @param parent  pointer to an object, it will be the parent of the new arc label
 * @return pointer to the created arc label
 * @see lv_arclabel_create
 */
inline Obj arclabel_create(Obj parent) noexcept { return Obj(lv_arclabel_create(parent.raw())); }

/**
 * Set the text of the arc label.
 * This function sets the text displayed by an arc label object.
 * @param obj  Pointer to the arc label object.
 * @param text  Pointer to a null-terminated string containing the new text for the label.
 * @see lv_arclabel_set_text
 */
inline void arclabel_set_text(Obj obj, const char* text) noexcept { lv_arclabel_set_text(obj.raw(), text); }

/**
 * Set the formatted text of an arc label object.
 * This function sets the text of an arc label object with support for
 * variable arguments formatting, similar to `printf`.
 * @param obj  The arc label object to set the text for.
 * @param fmt  A format string that specifies how subsequent arguments are converted to text.
 * @see lv_arclabel_set_text_fmt
 */
template <typename... A>
inline void arclabel_set_text_fmt(Obj obj, const char* fmt, A... args) noexcept { lv_arclabel_set_text_fmt(obj.raw(), fmt, args...); }

/**
 * Sets a new static text for the arc label or refreshes it with the current text.
 * The 'text' must remain valid in memory; the arc label does not manage its lifecycle.
 * @param obj  Pointer to the arc label object.
 * @param text  Pointer to the new text. If NULL, the label is refreshed with its current text.
 * @see lv_arclabel_set_text_static
 */
inline void arclabel_set_text_static(Obj obj, const char* text) noexcept { lv_arclabel_set_text_static(obj.raw(), text); }

/**
 * Set the start angle of an arc. 0 deg: right, 90 bottom, etc.
 * @param obj  pointer to an arc label object
 * @param start  the start angle. (if `LV_USE_FLOAT` is enabled it can be fractional too.)
 * @see lv_arclabel_set_angle_start
 */
inline void arclabel_set_angle_start(Obj obj, lv_value_precise_t start) noexcept { lv_arclabel_set_angle_start(obj.raw(), start); }

/**
 * Set the end angle of an arc. 0 deg: right, 90 bottom, etc.
 * @param obj  pointer to an arc label object
 * @param size  the angle size (if `LV_USE_FLOAT` is enabled it can be fractional too.)
 * @see lv_arclabel_set_angle_size
 */
inline void arclabel_set_angle_size(Obj obj, lv_value_precise_t size) noexcept { lv_arclabel_set_angle_size(obj.raw(), size); }

/**
 * Set the rotation for the whole arc
 * @param obj  pointer to an arc label object
 * @param offset  rotation angle
 * @see lv_arclabel_set_offset
 */
inline void arclabel_set_offset(Obj obj, int32_t offset) noexcept { lv_arclabel_set_offset(obj.raw(), offset); }

/**
 * Set the type of arc.
 * @param obj  pointer to and arc label object
 * @param dir  arc label's direction
 * @see lv_arclabel_set_dir
 */
inline void arclabel_set_dir(Obj obj, ArclabelDir dir) noexcept { lv_arclabel_set_dir(obj.raw(), static_cast<lv_arclabel_dir_t>(dir)); }

/**
 * Enable the recoloring by in-line commands
 * @param obj  pointer to an arc label object
 * @param en  true: enable recoloring, false: disable Example: "This is a #ff0000 red# word"
 * @see lv_arclabel_set_recolor
 */
inline void arclabel_set_recolor(Obj obj, bool en) noexcept { lv_arclabel_set_recolor(obj.raw(), en); }

/**
 * Set the radius for an arc label object.
 * @param obj  pointer to the arc label object.
 * @param radius  The radius value to set for the label's curvature, in pixels.
 * @see lv_arclabel_set_radius
 */
inline void arclabel_set_radius(Obj obj, uint32_t radius) noexcept { lv_arclabel_set_radius(obj.raw(), radius); }

/**
 * Set the center offset x for an arc label object.
 * @param obj  pointer to an arc label object
 * @param x  the x offset
 * @see lv_arclabel_set_center_offset_x
 */
inline void arclabel_set_center_offset_x(Obj obj, uint32_t x) noexcept { lv_arclabel_set_center_offset_x(obj.raw(), x); }

/**
 * Set the center offset y for an arc label object.
 * @param obj  pointer to an arc label object
 * @param y  the y offset
 * @see lv_arclabel_set_center_offset_y
 */
inline void arclabel_set_center_offset_y(Obj obj, uint32_t y) noexcept { lv_arclabel_set_center_offset_y(obj.raw(), y); }

/**
 * Set the text vertical alignment for an arc label object.
 * @param obj  pointer to an arc label object
 * @param align  the vertical alignment
 * @see lv_arclabel_set_text_vertical_align
 */
inline void arclabel_set_text_vertical_align(Obj obj, ArclabelTextAlign align) noexcept { lv_arclabel_set_text_vertical_align(obj.raw(), static_cast<lv_arclabel_text_align_t>(align)); }

/**
 * Set the text horizontal alignment for an arc label object.
 * @param obj  pointer to an arc label object
 * @param align  the horizontal alignment
 * @see lv_arclabel_set_text_horizontal_align
 */
inline void arclabel_set_text_horizontal_align(Obj obj, ArclabelTextAlign align) noexcept { lv_arclabel_set_text_horizontal_align(obj.raw(), static_cast<lv_arclabel_text_align_t>(align)); }

/**
 * Set the overflow behavior for an arc label object.
 * @param obj  pointer to an arc label object
 * @param overflow  the overflow mode (visible, ellipsis, clip)
 * @see lv_arclabel_set_overflow
 */
inline void arclabel_set_overflow(Obj obj, ArclabelOverflow overflow) noexcept { lv_arclabel_set_overflow(obj.raw(), static_cast<lv_arclabel_overflow_t>(overflow)); }

/**
 * Set the end overlap behavior for an arc label object.
 * This controls how text is handled when it would overlap at the end of a 360-degree arc.
 * @param obj  pointer to an arc label object
 * @param overlap  set the arc label's end overlap behavior
 * @see lv_arclabel_set_end_overlap
 */
inline void arclabel_set_end_overlap(Obj obj, bool overlap) noexcept { lv_arclabel_set_end_overlap(obj.raw(), overlap); }

/**
 * Get the start angle of an arc label.
 * @param obj  pointer to an arc label object
 * @return the start angle [0..360] (if `LV_USE_FLOAT` is enabled it can be fractional too.)
 * @see lv_arclabel_get_angle_start
 */
inline float arclabel_get_angle_start(Obj obj) noexcept { return lv_arclabel_get_angle_start(obj.raw()); }

/**
 * Get the angle size of an arc label.
 * @param obj  pointer to an arc label object
 * @return the end angle [0..360] (if `LV_USE_FLOAT` is enabled it can be fractional too.)
 * @see lv_arclabel_get_angle_size
 */
inline float arclabel_get_angle_size(Obj obj) noexcept { return lv_arclabel_get_angle_size(obj.raw()); }

/**
 * Get whether the arc label is type or not.
 * @param obj  pointer to an arc label object
 * @return arc label's direction
 * @see lv_arclabel_get_dir
 */
inline ArclabelDir arclabel_get_dir(Obj obj) noexcept { return static_cast<ArclabelDir>(lv_arclabel_get_dir(obj.raw())); }

/**
 * Enable the recoloring by in-line commands
 * @param obj  pointer to a label object
 * @return true: enable recoloring, false: disable
 * @see lv_arclabel_get_recolor
 */
inline bool arclabel_get_recolor(Obj obj) noexcept { return lv_arclabel_get_recolor(obj.raw()); }

/**
 * Get the text of the arc label.
 * @param obj  pointer to an arc label object
 * @return the radius of the arc label
 * @see lv_arclabel_get_radius
 */
inline uint32_t arclabel_get_radius(Obj obj) noexcept { return lv_arclabel_get_radius(obj.raw()); }

/**
 * Get the center offset x for an arc label object.
 * @param obj  pointer to an arc label object
 * @return the x offset
 * @see lv_arclabel_get_center_offset_x
 */
inline uint32_t arclabel_get_center_offset_x(Obj obj) noexcept { return lv_arclabel_get_center_offset_x(obj.raw()); }

/**
 * Get the center offset y for an arc label object.
 * @param obj  pointer to an arc label object
 * @return the y offset
 * @see lv_arclabel_get_center_offset_y
 */
inline uint32_t arclabel_get_center_offset_y(Obj obj) noexcept { return lv_arclabel_get_center_offset_y(obj.raw()); }

/**
 * Get the text vertical alignment for an arc label object.
 * @param obj  pointer to an arc label object
 * @return the vertical alignment
 * @see lv_arclabel_get_text_vertical_align
 */
inline ArclabelTextAlign arclabel_get_text_vertical_align(Obj obj) noexcept { return static_cast<ArclabelTextAlign>(lv_arclabel_get_text_vertical_align(obj.raw())); }

/**
 * Get the text horizontal alignment for an arc label object.
 * @param obj  pointer to an arc label object
 * @return the horizontal alignment
 * @see lv_arclabel_get_text_horizontal_align
 */
inline ArclabelTextAlign arclabel_get_text_horizontal_align(Obj obj) noexcept { return static_cast<ArclabelTextAlign>(lv_arclabel_get_text_horizontal_align(obj.raw())); }

/**
 * Get the overflow behavior for an arc label object.
 * @param obj  pointer to an arc label object
 * @return the overflow mode
 * @see lv_arclabel_get_overflow
 */
inline ArclabelOverflow arclabel_get_overflow(Obj obj) noexcept { return static_cast<ArclabelOverflow>(lv_arclabel_get_overflow(obj.raw())); }

/**
 * Get the end overlap behavior for an arc label object.
 * @param obj  pointer to an arc label object
 * @return the end overlap mode
 * @see lv_arclabel_get_end_overlap
 */
inline bool arclabel_get_end_overlap(Obj obj) noexcept { return lv_arclabel_get_end_overlap(obj.raw()); }

/**
 * Get the text angle for an arc label object.
 * @param obj  pointer to an arc label object
 * @return the text angle (if `LV_USE_FLOAT` is enabled it can be fractional too.)
 * @see lv_arclabel_get_text_angle
 */
inline float arclabel_get_text_angle(Obj obj) noexcept { return lv_arclabel_get_text_angle(obj.raw()); }
#endif // LV_USE_ARCLABEL != 0

} // namespace lv
