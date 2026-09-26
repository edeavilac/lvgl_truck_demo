#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_MATRIX
class Matrix {
protected:
    lv_matrix_t* p_ = nullptr;

public:
    constexpr Matrix() noexcept = default;  /**< the "no object" handle */
    constexpr explicit Matrix(lv_matrix_t* p) noexcept : p_(p) {}

    constexpr lv_matrix_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(Matrix a, Matrix b) noexcept { return a.p_ == b.p_; }

    /**
     * Set matrix to identity matrix
     * @see lv_matrix_identity
     */
    void identity() const noexcept;
    /**
     * Invert the matrix
     * @param m  pointer to another matrix (optional)
     * @return true: the matrix is invertible, false: the matrix is singular and cannot be inverted
     * @see lv_matrix_inverse
     */
    bool inverse(Matrix m) const noexcept;
    /**
     * Check if the matrix is identity
     * @return true: the matrix is identity , false: the matrix is not identity
     * @see lv_matrix_is_identity
     */
    bool is_identity() const noexcept;
    /**
     * Check if the matrix is identity or translation matrix
     * @return true: the matrix is identity or translation matrix, false: the matrix is not identity or translation matrix
     * @see lv_matrix_is_identity_or_translation
     */
    bool is_identity_or_translation() const noexcept;
    /**
     * Multiply two matrix and store the result to the first one
     * @see lv_matrix_multiply
     */
    void multiply(Matrix mul) const noexcept;
    /**
     * Rotate the matrix with origin
     * @param degree  angle to rotate
     * @see lv_matrix_rotate
     */
    void rotate(float degree) const noexcept;
    /**
     * Change the scale factor of the matrix
     * @param scale_x  the scale factor for the X direction
     * @param scale_y  the scale factor for the Y direction
     * @see lv_matrix_scale
     */
    void scale(float scale_x, float scale_y) const noexcept;
    /**
     * Change the skew factor of the matrix
     * @param skew_x  the skew factor for x direction
     * @param skew_y  the skew factor for y direction
     * @see lv_matrix_skew
     */
    void skew(float skew_x, float skew_y) const noexcept;
    /**
     * Transform an area by a matrix
     * @param area  pointer to an area
     * @return the transformed area
     * @see lv_matrix_transform_area
     */
    Area transform_area(const Area& area) const noexcept;
    #if LV_USE_VECTOR_GRAPHIC
    /**
     * Transform all the coordinates of a path using given matrix
     * @param path  pointer to a path
     * @see lv_matrix_transform_path
     */
    void transform_path(VectorPath path) const noexcept;
    /**
     * Transform the coordinates of a point using given matrix
     * @param point  pointer to a point
     * @see lv_matrix_transform_point
     */
    void transform_point(lv_fpoint_t* point) const noexcept;
    #endif // LV_USE_VECTOR_GRAPHIC

    /**
     * Transform a point by a matrix
     * @param point  pointer to a point
     * @return the transformed point
     * @see lv_matrix_transform_precise_point
     */
    lv_point_precise_t transform_precise_point(PointPrecise point) const noexcept;
    /**
     * Translate the matrix to new position
     * @param tx  the amount of translate in x direction
     * @param tx  the amount of translate in y direction
     * @see lv_matrix_translate
     */
    void translate(float tx, float ty) const noexcept;
    /**
     * Transpose a matrix.
     * @param dst  pointer to the destination matrix. If NULL, the function returns. Note: src and dst may point to the same matrix for in-place transposition.
     * @see lv_matrix_transpose
     */
    void transpose(Matrix dst) const noexcept;
};
static_assert(sizeof(Matrix) == sizeof(lv_matrix_t*));
static_assert(__is_trivially_copyable(Matrix));
#endif // LV_USE_MATRIX

} // namespace lv
