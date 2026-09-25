#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

/**
 * Initialize gradient color map from a table
 * @param grad  pointer to a gradient descriptor
 * @param colors  color array
 * @param fracs  position array (0..255): if NULL, then colors are distributed evenly
 * @param opa  opacity array: if NULL, then LV_OPA_COVER is assumed
 * @param num_stops  number of gradient stops (1..LV_GRADIENT_MAX_STOPS)
 * @see lv_grad_init_stops
 */
inline void grad_init_stops(lv_grad_dsc_t* grad, const Color& colors, const lv_opa_t* opa, const uint8_t* fracs, int32_t num_stops) noexcept { lv_grad_init_stops(grad, colors.ptr(), opa, fracs, num_stops); }

/**
 * Helper function to initialize a horizontal gradient.
 * @param dsc  gradient descriptor
 * @see lv_grad_horizontal_init
 */
inline void grad_horizontal_init(lv_grad_dsc_t* dsc) noexcept { lv_grad_horizontal_init(dsc); }

/**
 * Helper function to initialize a vertical gradient.
 * @param dsc  gradient descriptor
 * @see lv_grad_vertical_init
 */
inline void grad_vertical_init(lv_grad_dsc_t* dsc) noexcept { lv_grad_vertical_init(dsc); }

/**
 * Helper function to initialize linear gradient
 * @param dsc  gradient descriptor
 * @param from_x  start x position: can be a coordinate or an lv_pct() value predefined constants LV_GRAD_LEFT, LV_GRAD_RIGHT, LV_GRAD_TOP, LV_GRAD_BOTTOM, LV_GRAD_CENTER can be used as well
 * @param from_y  start y position
 * @param to_x  end x position
 * @param to_y  end y position
 * @param extend  one of LV_GRAD_EXTEND_PAD, LV_GRAD_EXTEND_REPEAT or LV_GRAD_EXTEND_REFLECT
 * @see lv_grad_linear_init
 */
inline void grad_linear_init(lv_grad_dsc_t* dsc, int32_t from_x, int32_t from_y, int32_t to_x, int32_t to_y, GradExtend extend) noexcept { lv_grad_linear_init(dsc, from_x, from_y, to_x, to_y, static_cast<lv_grad_extend_t>(extend)); }

/**
 * Helper function to initialize radial gradient
 * @param dsc  gradient descriptor
 * @param center_x  center x position: can be a coordinate or an lv_pct() value predefined constants LV_GRAD_LEFT, LV_GRAD_RIGHT, LV_GRAD_TOP, LV_GRAD_BOTTOM, LV_GRAD_CENTER can be used as well
 * @param center_y  center y position
 * @param to_x  point on the end circle x position
 * @param to_y  point on the end circle y position
 * @param extend  one of LV_GRAD_EXTEND_PAD, LV_GRAD_EXTEND_REPEAT or LV_GRAD_EXTEND_REFLECT
 * @see lv_grad_radial_init
 */
inline void grad_radial_init(lv_grad_dsc_t* dsc, int32_t center_x, int32_t center_y, int32_t to_x, int32_t to_y, GradExtend extend) noexcept { lv_grad_radial_init(dsc, center_x, center_y, to_x, to_y, static_cast<lv_grad_extend_t>(extend)); }

/**
 * Set focal (starting) circle of a radial gradient
 * @param dsc  gradient descriptor
 * @param center_x  center x position: can be a coordinate or an lv_pct() value predefined constants LV_GRAD_LEFT, LV_GRAD_RIGHT, LV_GRAD_TOP, LV_GRAD_BOTTOM, LV_GRAD_CENTER can be used as well
 * @param center_y  center y position
 * @param radius  radius of the starting circle (NOTE: this must be a scalar number, not percentage)
 * @see lv_grad_radial_set_focal
 */
inline void grad_radial_set_focal(lv_grad_dsc_t* dsc, int32_t center_x, int32_t center_y, int32_t radius) noexcept { lv_grad_radial_set_focal(dsc, center_x, center_y, radius); }

/**
 * Helper function to initialize conical gradient
 * @param dsc  gradient descriptor
 * @param center_x  center x position: can be a coordinate or an lv_pct() value predefined constants LV_GRAD_LEFT, LV_GRAD_RIGHT, LV_GRAD_TOP, LV_GRAD_BOTTOM, LV_GRAD_CENTER can be used as well
 * @param center_y  center y position
 * @param start_angle  start angle in degrees
 * @param end_angle  end angle in degrees
 * @param extend  one of LV_GRAD_EXTEND_PAD, LV_GRAD_EXTEND_REPEAT or LV_GRAD_EXTEND_REFLECT
 * @see lv_grad_conical_init
 */
inline void grad_conical_init(lv_grad_dsc_t* dsc, int32_t center_x, int32_t center_y, int32_t start_angle, int32_t end_angle, GradExtend extend) noexcept { lv_grad_conical_init(dsc, center_x, center_y, start_angle, end_angle, static_cast<lv_grad_extend_t>(extend)); }

} // namespace lv
