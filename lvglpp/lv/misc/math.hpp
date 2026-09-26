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
 * Return with sinus of an angle
 * @param angle  
 * @return sinus of 'angle'. sin(-90) = -32767, sin(90) = 32767
 * @see lv_trigo_sin
 */
inline int32_t math_trigo_sin(int16_t angle) noexcept { return lv_trigo_sin(angle); }

/** @see lv_trigo_cos */
inline int32_t math_trigo_cos(int16_t angle) noexcept { return lv_trigo_cos(angle); }

/**
 * Calculate the y value of cubic-bezier(x1, y1, x2, y2) function as specified x.
 * @param x  time in range of [0..LV_BEZIER_VAL_MAX]
 * @param x1  x of control point 1 in range of [0..LV_BEZIER_VAL_MAX]
 * @param y1  y of control point 1 in range of [0..LV_BEZIER_VAL_MAX]
 * @param x2  x of control point 2 in range of [0..LV_BEZIER_VAL_MAX]
 * @param y2  y of control point 2 in range of [0..LV_BEZIER_VAL_MAX]
 * @return the value calculated
 * @see lv_cubic_bezier
 */
inline int32_t math_cubic_bezier(int32_t x, int32_t x1, int32_t y1, int32_t x2, int32_t y2) noexcept { return lv_cubic_bezier(x, x1, y1, x2, y2); }

/**
 * Calculate a value of a Cubic Bezier function.
 * @param t  time in range of [0..LV_BEZIER_VAL_MAX]
 * @param u0  must be 0
 * @param u1  control value 1 values in range of [0..LV_BEZIER_VAL_MAX]
 * @param u2  control value 2 in range of [0..LV_BEZIER_VAL_MAX]
 * @param u3  must be LV_BEZIER_VAL_MAX
 * @return the value calculated from the given parameters in range of [0..LV_BEZIER_VAL_MAX]
 * @see lv_bezier3
 */
inline int32_t math_bezier3(int32_t t, int32_t u0, uint32_t u1, int32_t u2, int32_t u3) noexcept { return lv_bezier3(t, u0, u1, u2, u3); }

/**
 * Calculate the atan2 of a vector.
 * @param x  
 * @param y  
 * @return the angle in degree calculated from the given parameters in range of [0..360]
 * @see lv_atan2
 */
inline uint16_t math_atan2(int32_t x, int32_t y) noexcept { return lv_atan2(x, y); }

/**
 * Get the square root of a number
 * @param x  integer which square root should be calculated
 * @param q  store the result here. q->i: integer part, q->f: fractional part in 1/256 unit
 * @param mask  optional to skip some iterations if the magnitude of the root is known. Set to 0x8000 by default. If root < 16: mask = 0x80 If root < 256: mask = 0x800 Else: mask = 0x8000
 * @see lv_sqrt
 */
inline void math_sqrt(uint32_t x, lv_sqrt_res_t* q, uint32_t mask) noexcept { lv_sqrt(x, q, mask); }

/**
 * Alternative (fast, approximate) implementation for getting the square root of an integer.
 * @param x  integer which square root should be calculated
 * @see lv_sqrt32
 */
inline int32_t math_sqrt32(uint32_t x) noexcept { return lv_sqrt32(x); }

/**
 * Calculate the square of an integer (input range is 0..32767).
 * @param x  input
 * @return square
 * @see lv_sqr
 */
inline int32_t math_sqr(int32_t x) noexcept { return lv_sqr(x); }

/**
 * Calculate the integer exponents.
 * @param base  
 * @param exp  
 * @return base raised to the power exponent
 * @see lv_pow
 */
inline int64_t math_pow(int64_t base, int8_t exp) noexcept { return lv_pow(base, exp); }

/**
 * Get the mapped of a number given an input and output range
 * @param x  integer which mapped value should be calculated
 * @param min_in  min input range
 * @param max_in  max input range
 * @param min_out  max output range
 * @param max_out  max output range
 * @return the mapped number
 * @see lv_map
 */
inline int32_t math_map(int32_t x, int32_t min_in, int32_t max_in, int32_t min_out, int32_t max_out) noexcept { return lv_map(x, min_in, max_in, min_out, max_out); }

/**
 * Set the seed of the pseudo random number generator
 * @param seed  a number to initialize the random generator
 * @see lv_rand_set_seed
 */
inline void math_rand_set_seed(uint32_t seed) noexcept { lv_rand_set_seed(seed); }

/**
 * Get a pseudo random number in the given range
 * @param min  the minimum value
 * @param max  the maximum value
 * @return return the random number. min <= return_value <= max
 * @see lv_rand
 */
inline uint32_t math_rand(uint32_t min, uint32_t max) noexcept { return lv_rand(min, max); }

} // namespace lv
