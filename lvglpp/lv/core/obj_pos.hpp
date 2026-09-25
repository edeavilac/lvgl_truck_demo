#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core/obj.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/misc/matrix.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

/**
 * Clamp a width between min and max width. If the min/max width is in percentage value use the ref_width
 * @param width  width to clamp
 * @param min_width  the minimal width
 * @param max_width  the maximal width
 * @param ref_width  the reference width used when min/max width is in percentage
 * @return the clamped width
 * @see lv_clamp_width
 */
inline int32_t obj_pos_clamp_width(int32_t width, int32_t min_width, int32_t max_width, int32_t ref_width) noexcept { return lv_clamp_width(width, min_width, max_width, ref_width); }

/**
 * Clamp a height between min and max height. If the min/max height is in percentage value use the ref_height
 * @param height  height to clamp
 * @param min_height  the minimal height
 * @param max_height  the maximal height
 * @param ref_height  the reference height used when min/max height is in percentage
 * @return the clamped height
 * @see lv_clamp_height
 */
inline int32_t obj_pos_clamp_height(int32_t height, int32_t min_height, int32_t max_height, int32_t ref_height) noexcept { return lv_clamp_height(height, min_height, max_height, ref_height); }

inline void Obj::align(Align align, int32_t x_ofs, int32_t y_ofs) const noexcept { lv_obj_align(p_, static_cast<lv_align_t>(align), x_ofs, y_ofs); }

inline void Obj::align_to(Obj base, Align align, int32_t x_ofs, int32_t y_ofs) const noexcept { lv_obj_align_to(p_, base.raw(), static_cast<lv_align_t>(align), x_ofs, y_ofs); }

inline bool Obj::area_is_visible(Area& area) const noexcept { return lv_obj_area_is_visible(p_, area.ptr()); }

inline int32_t Obj::calc_dynamic_height(lv_style_prop_t prop) const noexcept { return lv_obj_calc_dynamic_height(p_, prop); }

inline int32_t Obj::calc_dynamic_width(lv_style_prop_t prop) const noexcept { return lv_obj_calc_dynamic_width(p_, prop); }

inline void Obj::center() const noexcept { lv_obj_center(p_); }

inline Area Obj::get_click_area() const noexcept {
    lv_area_t area_out{};
    lv_obj_get_click_area(p_, &area_out);
    return Area{area_out};
}

inline Area Obj::get_content_coords() const noexcept {
    lv_area_t area_out{};
    lv_obj_get_content_coords(p_, &area_out);
    return Area{area_out};
}

inline int32_t Obj::get_content_height() const noexcept { return lv_obj_get_content_height(p_); }

inline int32_t Obj::get_content_width() const noexcept { return lv_obj_get_content_width(p_); }

inline Area Obj::get_coords() const noexcept {
    lv_area_t coords_out{};
    lv_obj_get_coords(p_, &coords_out);
    return Area{coords_out};
}

inline int32_t Obj::get_height() const noexcept { return lv_obj_get_height(p_); }

inline int32_t Obj::get_self_height() const noexcept { return lv_obj_get_self_height(p_); }

inline int32_t Obj::get_self_width() const noexcept { return lv_obj_get_self_width(p_); }

#if LV_USE_MATRIX
inline Matrix Obj::get_transform() const noexcept { return Matrix(const_cast<lv_matrix_t*>(lv_obj_get_transform(p_))); }
#endif // LV_USE_MATRIX

inline void Obj::get_transformed_area(Area& area, ObjPointTransformFlag flags) const noexcept { lv_obj_get_transformed_area(p_, area.ptr(), static_cast<lv_obj_point_transform_flag_t>(flags)); }

inline int32_t Obj::get_width() const noexcept { return lv_obj_get_width(p_); }

inline int32_t Obj::get_x() const noexcept { return lv_obj_get_x(p_); }

inline int32_t Obj::get_x2() const noexcept { return lv_obj_get_x2(p_); }

inline int32_t Obj::get_x_aligned() const noexcept { return lv_obj_get_x_aligned(p_); }

inline int32_t Obj::get_y() const noexcept { return lv_obj_get_y(p_); }

inline int32_t Obj::get_y2() const noexcept { return lv_obj_get_y2(p_); }

inline int32_t Obj::get_y_aligned() const noexcept { return lv_obj_get_y_aligned(p_); }

inline bool Obj::hit_test(const Point& point) const noexcept { return lv_obj_hit_test(p_, point.ptr()); }

inline Result Obj::invalidate() const noexcept { return static_cast<Result>(lv_obj_invalidate(p_)); }

inline Result Obj::invalidate_area(const Area& area) const noexcept { return static_cast<Result>(lv_obj_invalidate_area(p_, area.ptr())); }

inline bool Obj::is_height_max() const noexcept { return lv_obj_is_height_max(p_); }

inline bool Obj::is_height_min() const noexcept { return lv_obj_is_height_min(p_); }

inline bool Obj::is_layout_positioned() const noexcept { return lv_obj_is_layout_positioned(p_); }

inline bool Obj::is_style_any_height_content() const noexcept { return lv_obj_is_style_any_height_content(p_); }

inline bool Obj::is_style_any_width_content() const noexcept { return lv_obj_is_style_any_width_content(p_); }

inline bool Obj::is_visible() const noexcept { return lv_obj_is_visible(p_); }

inline bool Obj::is_width_max() const noexcept { return lv_obj_is_width_max(p_); }

inline bool Obj::is_width_min() const noexcept { return lv_obj_is_width_min(p_); }

inline void Obj::mark_layout_as_dirty() const noexcept { lv_obj_mark_layout_as_dirty(p_); }

inline void Obj::move_children_by(int32_t x_diff, int32_t y_diff, bool ignore_floating) const noexcept { lv_obj_move_children_by(p_, x_diff, y_diff, ignore_floating); }

inline void Obj::move_to(int32_t x, int32_t y) const noexcept { lv_obj_move_to(p_, x, y); }

inline void Obj::refr_pos() const noexcept { lv_obj_refr_pos(p_); }

inline bool Obj::refr_size() const noexcept { return lv_obj_refr_size(p_); }

inline bool Obj::refresh_self_size() const noexcept { return lv_obj_refresh_self_size(p_); }

inline void Obj::reset_transform() const noexcept { lv_obj_reset_transform(p_); }

inline void Obj::set_align(Align align) const noexcept { lv_obj_set_align(p_, static_cast<lv_align_t>(align)); }

inline void Obj::set_content_height(int32_t h) const noexcept { lv_obj_set_content_height(p_, h); }

inline void Obj::set_content_width(int32_t w) const noexcept { lv_obj_set_content_width(p_, w); }

inline void Obj::set_ext_click_area(int32_t size) const noexcept { lv_obj_set_ext_click_area(p_, size); }

inline void Obj::set_height(int32_t h) const noexcept { lv_obj_set_height(p_, h); }

inline void Obj::set_layout(uint32_t layout) const noexcept { lv_obj_set_layout(p_, layout); }

inline void Obj::set_pos(int32_t x, int32_t y) const noexcept { lv_obj_set_pos(p_, x, y); }

inline void Obj::set_size(int32_t w, int32_t h) const noexcept { lv_obj_set_size(p_, w, h); }

#if LV_USE_MATRIX
inline void Obj::set_transform(Matrix matrix) const noexcept { lv_obj_set_transform(p_, matrix.raw()); }
#endif // LV_USE_MATRIX

inline void Obj::set_width(int32_t w) const noexcept { lv_obj_set_width(p_, w); }

inline void Obj::set_x(int32_t x) const noexcept { lv_obj_set_x(p_, x); }

inline void Obj::set_y(int32_t y) const noexcept { lv_obj_set_y(p_, y); }

inline void Obj::transform_point(Point& p, ObjPointTransformFlag flags) const noexcept { lv_obj_transform_point(p_, p.ptr(), static_cast<lv_obj_point_transform_flag_t>(flags)); }

inline void Obj::transform_point_array(Point& points, size_t count, ObjPointTransformFlag flags) const noexcept { lv_obj_transform_point_array(p_, points.ptr(), count, static_cast<lv_obj_point_transform_flag_t>(flags)); }

inline void Obj::update_layout() const noexcept { lv_obj_update_layout(p_); }

} // namespace lv
