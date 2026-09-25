#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core.hpp"
#include "lv/core/obj.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

inline int32_t Obj::calculate_ext_draw_size(Part part) const noexcept { return lv_obj_calculate_ext_draw_size(p_, static_cast<lv_part_t>(part)); }

inline void Obj::init_draw_arc_dsc(Part part, DrawArcDsc& draw_dsc) const noexcept { lv_obj_init_draw_arc_dsc(p_, static_cast<lv_part_t>(part), draw_dsc.raw()); }

inline void Obj::init_draw_blur_dsc(Part part, DrawBlurDsc& draw_dsc) const noexcept { lv_obj_init_draw_blur_dsc(p_, static_cast<lv_part_t>(part), draw_dsc.raw()); }

inline void Obj::init_draw_image_dsc(Part part, DrawImageDsc& draw_dsc) const noexcept { lv_obj_init_draw_image_dsc(p_, static_cast<lv_part_t>(part), draw_dsc.raw()); }

inline void Obj::init_draw_label_dsc(Part part, DrawLabelDsc& draw_dsc) const noexcept { lv_obj_init_draw_label_dsc(p_, static_cast<lv_part_t>(part), draw_dsc.raw()); }

inline void Obj::init_draw_line_dsc(Part part, DrawLineDsc& draw_dsc) const noexcept { lv_obj_init_draw_line_dsc(p_, static_cast<lv_part_t>(part), draw_dsc.raw()); }

inline void Obj::init_draw_rect_dsc(Part part, DrawRectDsc& draw_dsc) const noexcept { lv_obj_init_draw_rect_dsc(p_, static_cast<lv_part_t>(part), draw_dsc.raw()); }

inline void Obj::refresh_ext_draw_size() const noexcept { lv_obj_refresh_ext_draw_size(p_); }

} // namespace lv
