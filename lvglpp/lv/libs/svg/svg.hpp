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

#if LV_USE_SVG
/**
 * Loading SVG data and creating the DOM tree
 * @param svg_data  pointer to the SVG data
 * @param data_len  the SVG data length
 * @see lv_svg_load_data
 */
inline SvgNode svg_load_data(const char* svg_data, uint32_t data_len) noexcept { return SvgNode(lv_svg_load_data(svg_data, data_len)); }
#endif // LV_USE_SVG

#if LV_USE_SVG
inline SvgNode SvgNode::create(SvgNode parent) noexcept { return SvgNode(lv_svg_node_create(parent.raw())); }

inline void SvgNode::delete_() const noexcept { lv_svg_node_delete(p_); }
#endif // LV_USE_SVG

} // namespace lv
