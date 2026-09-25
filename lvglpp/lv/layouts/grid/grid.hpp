#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core/obj.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstddef>
#include <cstdint>

namespace lv {

#if LV_USE_GRID
/** @see lv_grid_init */
inline void grid_init() noexcept { lv_grid_init(); }

/**
 * Just a wrapper to `LV_GRID_FR` for bindings.
 * @see lv_grid_fr
 */
inline int32_t grid_fr(uint8_t x) noexcept { return lv_grid_fr(x); }
#endif // LV_USE_GRID

#if LV_USE_GRID
inline void Obj::set_grid_align(GridAlign column_align, GridAlign row_align) const noexcept { lv_obj_set_grid_align(p_, static_cast<lv_grid_align_t>(column_align), static_cast<lv_grid_align_t>(row_align)); }

inline void Obj::set_grid_cell(GridAlign column_align, int32_t col_pos, int32_t col_span, GridAlign row_align, int32_t row_pos, int32_t row_span) const noexcept { lv_obj_set_grid_cell(p_, static_cast<lv_grid_align_t>(column_align), col_pos, col_span, static_cast<lv_grid_align_t>(row_align), row_pos, row_span); }

template <std::size_t N1, std::size_t N2>
inline void Obj::set_grid_dsc_array(const GridTemplate<N1>& col_dsc, const GridTemplate<N2>& row_dsc) const noexcept { lv_obj_set_grid_dsc_array(p_, col_dsc.raw(), row_dsc.raw()); }
#endif // LV_USE_GRID

} // namespace lv
