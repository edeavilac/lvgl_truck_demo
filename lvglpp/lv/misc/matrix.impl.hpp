#pragma once
// Bodies of misc/matrix.hpp, separated because its file cycle needs every type
// complete. Same mechanism as D-C7, applied where the graph asks for it.
// Included by the umbrella and never by a header: it is NOT a translation
// unit and every definition in it is `inline`. The stem says so, not the
// extension, so a glob written for *.hpp still installs it.

#include "lv/lvgl.hpp"

namespace lv {

#if LV_USE_MATRIX
inline void Matrix::identity() const noexcept { lv_matrix_identity(p_); }

inline bool Matrix::inverse(Matrix m) const noexcept { return lv_matrix_inverse(p_, m.raw()); }

inline bool Matrix::is_identity() const noexcept { return lv_matrix_is_identity(p_); }

inline bool Matrix::is_identity_or_translation() const noexcept { return lv_matrix_is_identity_or_translation(p_); }

inline void Matrix::multiply(Matrix mul) const noexcept { lv_matrix_multiply(p_, mul.raw()); }

inline void Matrix::rotate(float degree) const noexcept { lv_matrix_rotate(p_, degree); }

inline void Matrix::scale(float scale_x, float scale_y) const noexcept { lv_matrix_scale(p_, scale_x, scale_y); }

inline void Matrix::skew(float skew_x, float skew_y) const noexcept { lv_matrix_skew(p_, skew_x, skew_y); }

inline Area Matrix::transform_area(const Area& area) const noexcept { return Area{lv_matrix_transform_area(p_, area.ptr())}; }

inline lv_point_precise_t Matrix::transform_precise_point(PointPrecise point) const noexcept { return lv_matrix_transform_precise_point(p_, point.raw()); }

inline void Matrix::translate(float tx, float ty) const noexcept { lv_matrix_translate(p_, tx, ty); }

inline void Matrix::transpose(Matrix dst) const noexcept { lv_matrix_transpose(p_, dst.raw()); }
#endif // LV_USE_MATRIX

} // namespace lv
