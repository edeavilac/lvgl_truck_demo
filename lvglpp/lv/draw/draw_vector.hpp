#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/misc/matrix.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_VECTOR_GRAPHIC
/**
 * Draw all the vector graphic paths
 * @param dsc  pointer to a vector graphic descriptor
 * @see lv_draw_vector
 */
inline void draw_vector(DrawVectorDsc dsc) noexcept { lv_draw_vector(dsc.raw()); }
#endif // LV_USE_VECTOR_GRAPHIC

#if LV_USE_VECTOR_GRAPHIC
inline DrawVectorDsc DrawTask::get_vector_dsc() const noexcept { return DrawVectorDsc(lv_draw_task_get_vector_dsc(p_)); }

inline void DrawVectorDsc::add_path(VectorPath path) const noexcept { lv_draw_vector_dsc_add_path(p_, path.raw()); }

inline void DrawVectorDsc::clear_area(const Area& rect) const noexcept { lv_draw_vector_dsc_clear_area(p_, rect.ptr()); }

inline DrawVectorDsc DrawVectorDsc::create(Layer& layer) noexcept { return DrawVectorDsc(lv_draw_vector_dsc_create(layer.raw())); }

inline void DrawVectorDsc::delete_() const noexcept { lv_draw_vector_dsc_delete(p_); }

inline void DrawVectorDsc::identity() const noexcept { lv_draw_vector_dsc_identity(p_); }

inline void DrawVectorDsc::rotate(float degree) const noexcept { lv_draw_vector_dsc_rotate(p_, degree); }

inline void DrawVectorDsc::scale(float scale_x, float scale_y) const noexcept { lv_draw_vector_dsc_scale(p_, scale_x, scale_y); }

inline void DrawVectorDsc::set_blend_mode(VectorBlend blend) const noexcept { lv_draw_vector_dsc_set_blend_mode(p_, static_cast<lv_vector_blend_t>(blend)); }

inline void DrawVectorDsc::set_fill_color(Color color) const noexcept { lv_draw_vector_dsc_set_fill_color(p_, color.raw()); }

inline void DrawVectorDsc::set_fill_color32(lv_color32_t color) const noexcept { lv_draw_vector_dsc_set_fill_color32(p_, color); }

inline void DrawVectorDsc::set_fill_gradient_color_stops(const lv_grad_stop_t* stops, uint16_t count) const noexcept { lv_draw_vector_dsc_set_fill_gradient_color_stops(p_, stops, count); }

inline void DrawVectorDsc::set_fill_gradient_spread(VectorGradientSpread spread) const noexcept { lv_draw_vector_dsc_set_fill_gradient_spread(p_, static_cast<lv_vector_gradient_spread_t>(spread)); }

inline void DrawVectorDsc::set_fill_image(DrawImageDsc& img_dsc) const noexcept { lv_draw_vector_dsc_set_fill_image(p_, img_dsc.raw()); }

inline void DrawVectorDsc::set_fill_linear_gradient(float x1, float y1, float x2, float y2) const noexcept { lv_draw_vector_dsc_set_fill_linear_gradient(p_, x1, y1, x2, y2); }

inline void DrawVectorDsc::set_fill_opa(lv_opa_t opa) const noexcept { lv_draw_vector_dsc_set_fill_opa(p_, opa); }

inline void DrawVectorDsc::set_fill_radial_gradient(float cx, float cy, float radius) const noexcept { lv_draw_vector_dsc_set_fill_radial_gradient(p_, cx, cy, radius); }

inline void DrawVectorDsc::set_fill_rule(VectorFill rule) const noexcept { lv_draw_vector_dsc_set_fill_rule(p_, static_cast<lv_vector_fill_t>(rule)); }
#endif // LV_USE_VECTOR_GRAPHIC

#if (LV_USE_VECTOR_GRAPHIC) && (LV_USE_MATRIX)
inline void DrawVectorDsc::set_fill_transform(Matrix matrix) const noexcept { lv_draw_vector_dsc_set_fill_transform(p_, matrix.raw()); }
#endif // (LV_USE_VECTOR_GRAPHIC) && (LV_USE_MATRIX)

#if LV_USE_VECTOR_GRAPHIC
inline void DrawVectorDsc::set_fill_units(VectorFillUnits units) const noexcept { lv_draw_vector_dsc_set_fill_units(p_, static_cast<lv_vector_fill_units_t>(units)); }

inline void DrawVectorDsc::set_stroke_cap(VectorStrokeCap cap) const noexcept { lv_draw_vector_dsc_set_stroke_cap(p_, static_cast<lv_vector_stroke_cap_t>(cap)); }

inline void DrawVectorDsc::set_stroke_color(Color color) const noexcept { lv_draw_vector_dsc_set_stroke_color(p_, color.raw()); }

inline void DrawVectorDsc::set_stroke_color32(lv_color32_t color) const noexcept { lv_draw_vector_dsc_set_stroke_color32(p_, color); }

inline void DrawVectorDsc::set_stroke_dash(float* dash_pattern, uint16_t dash_count) const noexcept { lv_draw_vector_dsc_set_stroke_dash(p_, dash_pattern, dash_count); }

inline void DrawVectorDsc::set_stroke_gradient_color_stops(const lv_grad_stop_t* stops, uint16_t count) const noexcept { lv_draw_vector_dsc_set_stroke_gradient_color_stops(p_, stops, count); }

inline void DrawVectorDsc::set_stroke_gradient_spread(VectorGradientSpread spread) const noexcept { lv_draw_vector_dsc_set_stroke_gradient_spread(p_, static_cast<lv_vector_gradient_spread_t>(spread)); }

inline void DrawVectorDsc::set_stroke_join(VectorStrokeJoin join) const noexcept { lv_draw_vector_dsc_set_stroke_join(p_, static_cast<lv_vector_stroke_join_t>(join)); }

inline void DrawVectorDsc::set_stroke_linear_gradient(float x1, float y1, float x2, float y2) const noexcept { lv_draw_vector_dsc_set_stroke_linear_gradient(p_, x1, y1, x2, y2); }

inline void DrawVectorDsc::set_stroke_miter_limit(uint16_t miter_limit) const noexcept { lv_draw_vector_dsc_set_stroke_miter_limit(p_, miter_limit); }

inline void DrawVectorDsc::set_stroke_opa(lv_opa_t opa) const noexcept { lv_draw_vector_dsc_set_stroke_opa(p_, opa); }

inline void DrawVectorDsc::set_stroke_radial_gradient(float cx, float cy, float radius) const noexcept { lv_draw_vector_dsc_set_stroke_radial_gradient(p_, cx, cy, radius); }
#endif // LV_USE_VECTOR_GRAPHIC

#if (LV_USE_VECTOR_GRAPHIC) && (LV_USE_MATRIX)
inline void DrawVectorDsc::set_stroke_transform(Matrix matrix) const noexcept { lv_draw_vector_dsc_set_stroke_transform(p_, matrix.raw()); }
#endif // (LV_USE_VECTOR_GRAPHIC) && (LV_USE_MATRIX)

#if LV_USE_VECTOR_GRAPHIC
inline void DrawVectorDsc::set_stroke_width(float width) const noexcept { lv_draw_vector_dsc_set_stroke_width(p_, width); }
#endif // LV_USE_VECTOR_GRAPHIC

#if (LV_USE_VECTOR_GRAPHIC) && (LV_USE_MATRIX)
inline void DrawVectorDsc::set_transform(Matrix matrix) const noexcept { lv_draw_vector_dsc_set_transform(p_, matrix.raw()); }
#endif // (LV_USE_VECTOR_GRAPHIC) && (LV_USE_MATRIX)

#if LV_USE_VECTOR_GRAPHIC
inline void DrawVectorDsc::skew(float skew_x, float skew_y) const noexcept { lv_draw_vector_dsc_skew(p_, skew_x, skew_y); }

inline void DrawVectorDsc::translate(float tx, float ty) const noexcept { lv_draw_vector_dsc_translate(p_, tx, ty); }
#endif // LV_USE_VECTOR_GRAPHIC

#if (LV_USE_MATRIX) && (LV_USE_VECTOR_GRAPHIC)
inline void Matrix::transform_path(VectorPath path) const noexcept { lv_matrix_transform_path(p_, path.raw()); }

inline void Matrix::transform_point(lv_fpoint_t* point) const noexcept { lv_matrix_transform_point(p_, point); }
#endif // (LV_USE_MATRIX) && (LV_USE_VECTOR_GRAPHIC)

#if LV_USE_VECTOR_GRAPHIC
inline void VectorPath::append_arc(const lv_fpoint_t* c, float radius, float start_angle, float sweep, bool pie) const noexcept { lv_vector_path_append_arc(p_, c, radius, start_angle, sweep, pie); }

inline void VectorPath::append_circle(const lv_fpoint_t* c, float rx, float ry) const noexcept { lv_vector_path_append_circle(p_, c, rx, ry); }

inline void VectorPath::append_path(VectorPath subpath) const noexcept { lv_vector_path_append_path(p_, subpath.raw()); }

inline void VectorPath::append_rect(const Area& rect, float rx, float ry) const noexcept { lv_vector_path_append_rect(p_, rect.ptr(), rx, ry); }

inline void VectorPath::append_rectangle(float x, float y, float w, float h, float rx, float ry) const noexcept { lv_vector_path_append_rectangle(p_, x, y, w, h, rx, ry); }

inline void VectorPath::arc_to(float radius_x, float radius_y, float rotate_angle, bool large_arc, bool clockwise, const lv_fpoint_t* p) const noexcept { lv_vector_path_arc_to(p_, radius_x, radius_y, rotate_angle, large_arc, clockwise, p); }

inline void VectorPath::clear() const noexcept { lv_vector_path_clear(p_); }

inline void VectorPath::close() const noexcept { lv_vector_path_close(p_); }

inline void VectorPath::copy(VectorPath path) const noexcept { lv_vector_path_copy(p_, path.raw()); }

inline VectorPath VectorPath::create(VectorPathQuality quality) noexcept { return VectorPath(lv_vector_path_create(static_cast<lv_vector_path_quality_t>(quality))); }

inline void VectorPath::cubic_to(const lv_fpoint_t* p1, const lv_fpoint_t* p2, const lv_fpoint_t* p3) const noexcept { lv_vector_path_cubic_to(p_, p1, p2, p3); }

inline void VectorPath::delete_() const noexcept { lv_vector_path_delete(p_); }

inline Area VectorPath::get_bounding() const noexcept {
    lv_area_t area_out{};
    lv_vector_path_get_bounding(p_, &area_out);
    return Area{area_out};
}

inline void VectorPath::line_to(const lv_fpoint_t* p) const noexcept { lv_vector_path_line_to(p_, p); }

inline void VectorPath::move_to(const lv_fpoint_t* p) const noexcept { lv_vector_path_move_to(p_, p); }

inline void VectorPath::quad_to(const lv_fpoint_t* p1, const lv_fpoint_t* p2) const noexcept { lv_vector_path_quad_to(p_, p1, p2); }
#endif // LV_USE_VECTOR_GRAPHIC

} // namespace lv
