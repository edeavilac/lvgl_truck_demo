#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

/**
 * Convert a percentage value to `int32_t`.
 * Percentage values are stored in special range
 * @param x  the percentage (0..1000)
 * @return a coordinate that stores the percentage
 * @see lv_pct
 */
inline int32_t area_pct(int32_t x) noexcept { return lv_pct(x); }

/** @see lv_pct_to_px */
inline int32_t area_pct_to_px(int32_t v, int32_t base) noexcept { return lv_pct_to_px(v, base); }

inline void PointPrecise::set(lv_value_precise_t x, lv_value_precise_t y) const noexcept { lv_point_precise_set(p_, x, y); }

inline void PointPrecise::swap(PointPrecise p2) const noexcept { lv_point_precise_swap(p_, p2.raw()); }

} // namespace lv
