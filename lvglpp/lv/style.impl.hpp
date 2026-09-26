#pragma once
// Bodies of style.hpp, separated because its file cycle needs every type
// complete. Same mechanism as D-C7, applied where the graph asks for it.
// Included by the umbrella and never by a header: it is NOT a translation
// unit and every definition in it is `inline`. The stem says so, not the
// extension, so a glob written for *.hpp still installs it.

#include "lv/lvgl.hpp"

namespace lv {

inline LocalStyle& LocalStyle::pad_all(int32_t value) noexcept { lv_obj_set_style_pad_all(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::pad_hor(int32_t value) noexcept { lv_obj_set_style_pad_hor(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::pad_ver(int32_t value) noexcept { lv_obj_set_style_pad_ver(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::margin_all(int32_t value) noexcept { lv_obj_set_style_margin_all(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::margin_hor(int32_t value) noexcept { lv_obj_set_style_margin_hor(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::margin_ver(int32_t value) noexcept { lv_obj_set_style_margin_ver(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::pad_gap(int32_t value) noexcept { lv_obj_set_style_pad_gap(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::size(int32_t width, int32_t height) noexcept { lv_obj_set_style_size(p_, width, height, sel_); return *this; }

inline LocalStyle& LocalStyle::transform_scale(int32_t value) noexcept { lv_obj_set_style_transform_scale(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::width(int32_t value) noexcept { lv_obj_set_style_width(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::min_width(int32_t value) noexcept { lv_obj_set_style_min_width(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::max_width(int32_t value) noexcept { lv_obj_set_style_max_width(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::height(int32_t value) noexcept { lv_obj_set_style_height(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::min_height(int32_t value) noexcept { lv_obj_set_style_min_height(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::max_height(int32_t value) noexcept { lv_obj_set_style_max_height(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::length(int32_t value) noexcept { lv_obj_set_style_length(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::x(int32_t value) noexcept { lv_obj_set_style_x(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::y(int32_t value) noexcept { lv_obj_set_style_y(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::align(Align value) noexcept { lv_obj_set_style_align(p_, static_cast<lv_align_t>(value), sel_); return *this; }

inline LocalStyle& LocalStyle::transform_width(int32_t value) noexcept { lv_obj_set_style_transform_width(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::transform_height(int32_t value) noexcept { lv_obj_set_style_transform_height(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::translate_x(int32_t value) noexcept { lv_obj_set_style_translate_x(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::translate_y(int32_t value) noexcept { lv_obj_set_style_translate_y(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::translate_radial(int32_t value) noexcept { lv_obj_set_style_translate_radial(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::transform_scale_x(int32_t value) noexcept { lv_obj_set_style_transform_scale_x(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::transform_scale_y(int32_t value) noexcept { lv_obj_set_style_transform_scale_y(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::transform_rotation(int32_t value) noexcept { lv_obj_set_style_transform_rotation(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::transform_pivot_x(int32_t value) noexcept { lv_obj_set_style_transform_pivot_x(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::transform_pivot_y(int32_t value) noexcept { lv_obj_set_style_transform_pivot_y(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::transform_skew_x(int32_t value) noexcept { lv_obj_set_style_transform_skew_x(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::transform_skew_y(int32_t value) noexcept { lv_obj_set_style_transform_skew_y(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::pad_top(int32_t value) noexcept { lv_obj_set_style_pad_top(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::pad_bottom(int32_t value) noexcept { lv_obj_set_style_pad_bottom(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::pad_left(int32_t value) noexcept { lv_obj_set_style_pad_left(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::pad_right(int32_t value) noexcept { lv_obj_set_style_pad_right(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::pad_row(int32_t value) noexcept { lv_obj_set_style_pad_row(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::pad_column(int32_t value) noexcept { lv_obj_set_style_pad_column(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::pad_radial(int32_t value) noexcept { lv_obj_set_style_pad_radial(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::margin_top(int32_t value) noexcept { lv_obj_set_style_margin_top(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::margin_bottom(int32_t value) noexcept { lv_obj_set_style_margin_bottom(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::margin_left(int32_t value) noexcept { lv_obj_set_style_margin_left(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::margin_right(int32_t value) noexcept { lv_obj_set_style_margin_right(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::bg_color(Color value) noexcept { lv_obj_set_style_bg_color(p_, value.raw(), sel_); return *this; }

inline LocalStyle& LocalStyle::bg_opa(lv_opa_t value) noexcept { lv_obj_set_style_bg_opa(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::bg_grad_color(Color value) noexcept { lv_obj_set_style_bg_grad_color(p_, value.raw(), sel_); return *this; }

inline LocalStyle& LocalStyle::bg_grad_dir(GradDir value) noexcept { lv_obj_set_style_bg_grad_dir(p_, static_cast<lv_grad_dir_t>(value), sel_); return *this; }

inline LocalStyle& LocalStyle::bg_main_stop(int32_t value) noexcept { lv_obj_set_style_bg_main_stop(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::bg_grad_stop(int32_t value) noexcept { lv_obj_set_style_bg_grad_stop(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::bg_main_opa(lv_opa_t value) noexcept { lv_obj_set_style_bg_main_opa(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::bg_grad_opa(lv_opa_t value) noexcept { lv_obj_set_style_bg_grad_opa(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::bg_grad(const lv_grad_dsc_t* value) noexcept { lv_obj_set_style_bg_grad(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::bg_image_src(const void* value) noexcept { lv_obj_set_style_bg_image_src(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::bg_image_opa(lv_opa_t value) noexcept { lv_obj_set_style_bg_image_opa(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::bg_image_recolor(Color value) noexcept { lv_obj_set_style_bg_image_recolor(p_, value.raw(), sel_); return *this; }

inline LocalStyle& LocalStyle::bg_image_recolor_opa(lv_opa_t value) noexcept { lv_obj_set_style_bg_image_recolor_opa(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::bg_image_tiled(bool value) noexcept { lv_obj_set_style_bg_image_tiled(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::border_color(Color value) noexcept { lv_obj_set_style_border_color(p_, value.raw(), sel_); return *this; }

inline LocalStyle& LocalStyle::border_opa(lv_opa_t value) noexcept { lv_obj_set_style_border_opa(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::border_width(int32_t value) noexcept { lv_obj_set_style_border_width(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::border_side(BorderSide value) noexcept { lv_obj_set_style_border_side(p_, static_cast<lv_border_side_t>(value), sel_); return *this; }

inline LocalStyle& LocalStyle::border_post(bool value) noexcept { lv_obj_set_style_border_post(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::outline_width(int32_t value) noexcept { lv_obj_set_style_outline_width(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::outline_color(Color value) noexcept { lv_obj_set_style_outline_color(p_, value.raw(), sel_); return *this; }

inline LocalStyle& LocalStyle::outline_opa(lv_opa_t value) noexcept { lv_obj_set_style_outline_opa(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::outline_pad(int32_t value) noexcept { lv_obj_set_style_outline_pad(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::shadow_width(int32_t value) noexcept { lv_obj_set_style_shadow_width(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::shadow_offset_x(int32_t value) noexcept { lv_obj_set_style_shadow_offset_x(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::shadow_offset_y(int32_t value) noexcept { lv_obj_set_style_shadow_offset_y(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::shadow_spread(int32_t value) noexcept { lv_obj_set_style_shadow_spread(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::shadow_color(Color value) noexcept { lv_obj_set_style_shadow_color(p_, value.raw(), sel_); return *this; }

inline LocalStyle& LocalStyle::shadow_opa(lv_opa_t value) noexcept { lv_obj_set_style_shadow_opa(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::image_opa(lv_opa_t value) noexcept { lv_obj_set_style_image_opa(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::image_recolor(Color value) noexcept { lv_obj_set_style_image_recolor(p_, value.raw(), sel_); return *this; }

inline LocalStyle& LocalStyle::image_recolor_opa(lv_opa_t value) noexcept { lv_obj_set_style_image_recolor_opa(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::image_colorkey(const lv_image_colorkey_t* value) noexcept { lv_obj_set_style_image_colorkey(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::line_width(int32_t value) noexcept { lv_obj_set_style_line_width(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::line_dash_width(int32_t value) noexcept { lv_obj_set_style_line_dash_width(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::line_dash_gap(int32_t value) noexcept { lv_obj_set_style_line_dash_gap(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::line_rounded(bool value) noexcept { lv_obj_set_style_line_rounded(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::line_color(Color value) noexcept { lv_obj_set_style_line_color(p_, value.raw(), sel_); return *this; }

inline LocalStyle& LocalStyle::line_opa(lv_opa_t value) noexcept { lv_obj_set_style_line_opa(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::arc_width(int32_t value) noexcept { lv_obj_set_style_arc_width(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::arc_rounded(bool value) noexcept { lv_obj_set_style_arc_rounded(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::arc_color(Color value) noexcept { lv_obj_set_style_arc_color(p_, value.raw(), sel_); return *this; }

inline LocalStyle& LocalStyle::arc_opa(lv_opa_t value) noexcept { lv_obj_set_style_arc_opa(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::arc_image_src(const void* value) noexcept { lv_obj_set_style_arc_image_src(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::text_color(Color value) noexcept { lv_obj_set_style_text_color(p_, value.raw(), sel_); return *this; }

inline LocalStyle& LocalStyle::text_opa(lv_opa_t value) noexcept { lv_obj_set_style_text_opa(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::text_font(Font value) noexcept { lv_obj_set_style_text_font(p_, value.raw(), sel_); return *this; }

inline LocalStyle& LocalStyle::text_letter_space(int32_t value) noexcept { lv_obj_set_style_text_letter_space(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::text_line_space(int32_t value) noexcept { lv_obj_set_style_text_line_space(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::text_decor(TextDecor value) noexcept { lv_obj_set_style_text_decor(p_, static_cast<lv_text_decor_t>(value), sel_); return *this; }

inline LocalStyle& LocalStyle::text_align(TextAlign value) noexcept { lv_obj_set_style_text_align(p_, static_cast<lv_text_align_t>(value), sel_); return *this; }

inline LocalStyle& LocalStyle::text_outline_stroke_color(Color value) noexcept { lv_obj_set_style_text_outline_stroke_color(p_, value.raw(), sel_); return *this; }

inline LocalStyle& LocalStyle::text_outline_stroke_width(int32_t value) noexcept { lv_obj_set_style_text_outline_stroke_width(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::text_outline_stroke_opa(lv_opa_t value) noexcept { lv_obj_set_style_text_outline_stroke_opa(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::blur_radius(int32_t value) noexcept { lv_obj_set_style_blur_radius(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::blur_backdrop(bool value) noexcept { lv_obj_set_style_blur_backdrop(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::blur_quality(BlurQuality value) noexcept { lv_obj_set_style_blur_quality(p_, static_cast<lv_blur_quality_t>(value), sel_); return *this; }

inline LocalStyle& LocalStyle::drop_shadow_radius(int32_t value) noexcept { lv_obj_set_style_drop_shadow_radius(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::drop_shadow_offset_x(int32_t value) noexcept { lv_obj_set_style_drop_shadow_offset_x(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::drop_shadow_offset_y(int32_t value) noexcept { lv_obj_set_style_drop_shadow_offset_y(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::drop_shadow_color(Color value) noexcept { lv_obj_set_style_drop_shadow_color(p_, value.raw(), sel_); return *this; }

inline LocalStyle& LocalStyle::drop_shadow_opa(lv_opa_t value) noexcept { lv_obj_set_style_drop_shadow_opa(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::drop_shadow_quality(BlurQuality value) noexcept { lv_obj_set_style_drop_shadow_quality(p_, static_cast<lv_blur_quality_t>(value), sel_); return *this; }

inline LocalStyle& LocalStyle::radius(int32_t value) noexcept { lv_obj_set_style_radius(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::radial_offset(int32_t value) noexcept { lv_obj_set_style_radial_offset(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::clip_corner(bool value) noexcept { lv_obj_set_style_clip_corner(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::opa(lv_opa_t value) noexcept { lv_obj_set_style_opa(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::opa_layered(lv_opa_t value) noexcept { lv_obj_set_style_opa_layered(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::color_filter_dsc(ColorFilterDsc& value) noexcept { lv_obj_set_style_color_filter_dsc(p_, value.raw(), sel_); return *this; }

inline LocalStyle& LocalStyle::color_filter_opa(lv_opa_t value) noexcept { lv_obj_set_style_color_filter_opa(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::recolor(Color value) noexcept { lv_obj_set_style_recolor(p_, value.raw(), sel_); return *this; }

inline LocalStyle& LocalStyle::recolor_opa(lv_opa_t value) noexcept { lv_obj_set_style_recolor_opa(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::anim(Anim& value) noexcept { lv_obj_set_style_anim(p_, value.raw(), sel_); return *this; }

inline LocalStyle& LocalStyle::anim_duration(uint32_t value) noexcept { lv_obj_set_style_anim_duration(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::transition(StyleTransitionDsc& value) noexcept { lv_obj_set_style_transition(p_, value.raw(), sel_); return *this; }

inline LocalStyle& LocalStyle::blend_mode(BlendMode value) noexcept { lv_obj_set_style_blend_mode(p_, static_cast<lv_blend_mode_t>(value), sel_); return *this; }

inline LocalStyle& LocalStyle::layout(uint16_t value) noexcept { lv_obj_set_style_layout(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::base_dir(BaseDir value) noexcept { lv_obj_set_style_base_dir(p_, static_cast<lv_base_dir_t>(value), sel_); return *this; }

inline LocalStyle& LocalStyle::bitmap_mask_src(const void* value) noexcept { lv_obj_set_style_bitmap_mask_src(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::rotary_sensitivity(uint32_t value) noexcept { lv_obj_set_style_rotary_sensitivity(p_, value, sel_); return *this; }

#if LV_USE_FLEX
inline LocalStyle& LocalStyle::flex_flow(FlexFlow value) noexcept { lv_obj_set_style_flex_flow(p_, static_cast<lv_flex_flow_t>(value), sel_); return *this; }

inline LocalStyle& LocalStyle::flex_main_place(FlexAlign value) noexcept { lv_obj_set_style_flex_main_place(p_, static_cast<lv_flex_align_t>(value), sel_); return *this; }

inline LocalStyle& LocalStyle::flex_cross_place(FlexAlign value) noexcept { lv_obj_set_style_flex_cross_place(p_, static_cast<lv_flex_align_t>(value), sel_); return *this; }

inline LocalStyle& LocalStyle::flex_track_place(FlexAlign value) noexcept { lv_obj_set_style_flex_track_place(p_, static_cast<lv_flex_align_t>(value), sel_); return *this; }

inline LocalStyle& LocalStyle::flex_grow(uint8_t value) noexcept { lv_obj_set_style_flex_grow(p_, value, sel_); return *this; }
#endif // LV_USE_FLEX

#if LV_USE_GRID
template <std::size_t N1>
inline LocalStyle& LocalStyle::grid_column_dsc_array(const GridTemplate<N1>& value) noexcept { lv_obj_set_style_grid_column_dsc_array(p_, value.raw(), sel_); return *this; }

inline LocalStyle& LocalStyle::grid_column_align(GridAlign value) noexcept { lv_obj_set_style_grid_column_align(p_, static_cast<lv_grid_align_t>(value), sel_); return *this; }

template <std::size_t N1>
inline LocalStyle& LocalStyle::grid_row_dsc_array(const GridTemplate<N1>& value) noexcept { lv_obj_set_style_grid_row_dsc_array(p_, value.raw(), sel_); return *this; }

inline LocalStyle& LocalStyle::grid_row_align(GridAlign value) noexcept { lv_obj_set_style_grid_row_align(p_, static_cast<lv_grid_align_t>(value), sel_); return *this; }

inline LocalStyle& LocalStyle::grid_cell_column_pos(int32_t value) noexcept { lv_obj_set_style_grid_cell_column_pos(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::grid_cell_x_align(GridAlign value) noexcept { lv_obj_set_style_grid_cell_x_align(p_, static_cast<lv_grid_align_t>(value), sel_); return *this; }

inline LocalStyle& LocalStyle::grid_cell_column_span(int32_t value) noexcept { lv_obj_set_style_grid_cell_column_span(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::grid_cell_row_pos(int32_t value) noexcept { lv_obj_set_style_grid_cell_row_pos(p_, value, sel_); return *this; }

inline LocalStyle& LocalStyle::grid_cell_y_align(GridAlign value) noexcept { lv_obj_set_style_grid_cell_y_align(p_, static_cast<lv_grid_align_t>(value), sel_); return *this; }

inline LocalStyle& LocalStyle::grid_cell_row_span(int32_t value) noexcept { lv_obj_set_style_grid_cell_row_span(p_, value, sel_); return *this; }
#endif // LV_USE_GRID

inline Style& Style::prop(lv_style_prop_t prop, lv_style_value_t value) noexcept { lv_style_set_prop(&s_, prop, value); return *this; }

inline Style& Style::pad_all(int32_t value) noexcept { lv_style_set_pad_all(&s_, value); return *this; }

inline Style& Style::pad_hor(int32_t value) noexcept { lv_style_set_pad_hor(&s_, value); return *this; }

inline Style& Style::pad_ver(int32_t value) noexcept { lv_style_set_pad_ver(&s_, value); return *this; }

inline Style& Style::margin_all(int32_t value) noexcept { lv_style_set_margin_all(&s_, value); return *this; }

inline Style& Style::margin_hor(int32_t value) noexcept { lv_style_set_margin_hor(&s_, value); return *this; }

inline Style& Style::margin_ver(int32_t value) noexcept { lv_style_set_margin_ver(&s_, value); return *this; }

inline Style& Style::pad_gap(int32_t value) noexcept { lv_style_set_pad_gap(&s_, value); return *this; }

inline Style& Style::size(int32_t width, int32_t height) noexcept { lv_style_set_size(&s_, width, height); return *this; }

inline Style& Style::transform_scale(int32_t value) noexcept { lv_style_set_transform_scale(&s_, value); return *this; }

inline Style& Style::width(int32_t value) noexcept { lv_style_set_width(&s_, value); return *this; }

inline Style& Style::min_width(int32_t value) noexcept { lv_style_set_min_width(&s_, value); return *this; }

inline Style& Style::max_width(int32_t value) noexcept { lv_style_set_max_width(&s_, value); return *this; }

inline Style& Style::height(int32_t value) noexcept { lv_style_set_height(&s_, value); return *this; }

inline Style& Style::min_height(int32_t value) noexcept { lv_style_set_min_height(&s_, value); return *this; }

inline Style& Style::max_height(int32_t value) noexcept { lv_style_set_max_height(&s_, value); return *this; }

inline Style& Style::length(int32_t value) noexcept { lv_style_set_length(&s_, value); return *this; }

inline Style& Style::x(int32_t value) noexcept { lv_style_set_x(&s_, value); return *this; }

inline Style& Style::y(int32_t value) noexcept { lv_style_set_y(&s_, value); return *this; }

inline Style& Style::align(Align value) noexcept { lv_style_set_align(&s_, static_cast<lv_align_t>(value)); return *this; }

inline Style& Style::transform_width(int32_t value) noexcept { lv_style_set_transform_width(&s_, value); return *this; }

inline Style& Style::transform_height(int32_t value) noexcept { lv_style_set_transform_height(&s_, value); return *this; }

inline Style& Style::translate_x(int32_t value) noexcept { lv_style_set_translate_x(&s_, value); return *this; }

inline Style& Style::translate_y(int32_t value) noexcept { lv_style_set_translate_y(&s_, value); return *this; }

inline Style& Style::translate_radial(int32_t value) noexcept { lv_style_set_translate_radial(&s_, value); return *this; }

inline Style& Style::transform_scale_x(int32_t value) noexcept { lv_style_set_transform_scale_x(&s_, value); return *this; }

inline Style& Style::transform_scale_y(int32_t value) noexcept { lv_style_set_transform_scale_y(&s_, value); return *this; }

inline Style& Style::transform_rotation(int32_t value) noexcept { lv_style_set_transform_rotation(&s_, value); return *this; }

inline Style& Style::transform_pivot_x(int32_t value) noexcept { lv_style_set_transform_pivot_x(&s_, value); return *this; }

inline Style& Style::transform_pivot_y(int32_t value) noexcept { lv_style_set_transform_pivot_y(&s_, value); return *this; }

inline Style& Style::transform_skew_x(int32_t value) noexcept { lv_style_set_transform_skew_x(&s_, value); return *this; }

inline Style& Style::transform_skew_y(int32_t value) noexcept { lv_style_set_transform_skew_y(&s_, value); return *this; }

inline Style& Style::pad_top(int32_t value) noexcept { lv_style_set_pad_top(&s_, value); return *this; }

inline Style& Style::pad_bottom(int32_t value) noexcept { lv_style_set_pad_bottom(&s_, value); return *this; }

inline Style& Style::pad_left(int32_t value) noexcept { lv_style_set_pad_left(&s_, value); return *this; }

inline Style& Style::pad_right(int32_t value) noexcept { lv_style_set_pad_right(&s_, value); return *this; }

inline Style& Style::pad_row(int32_t value) noexcept { lv_style_set_pad_row(&s_, value); return *this; }

inline Style& Style::pad_column(int32_t value) noexcept { lv_style_set_pad_column(&s_, value); return *this; }

inline Style& Style::pad_radial(int32_t value) noexcept { lv_style_set_pad_radial(&s_, value); return *this; }

inline Style& Style::margin_top(int32_t value) noexcept { lv_style_set_margin_top(&s_, value); return *this; }

inline Style& Style::margin_bottom(int32_t value) noexcept { lv_style_set_margin_bottom(&s_, value); return *this; }

inline Style& Style::margin_left(int32_t value) noexcept { lv_style_set_margin_left(&s_, value); return *this; }

inline Style& Style::margin_right(int32_t value) noexcept { lv_style_set_margin_right(&s_, value); return *this; }

inline Style& Style::bg_color(Color value) noexcept { lv_style_set_bg_color(&s_, value.raw()); return *this; }

inline Style& Style::bg_opa(lv_opa_t value) noexcept { lv_style_set_bg_opa(&s_, value); return *this; }

inline Style& Style::bg_grad_color(Color value) noexcept { lv_style_set_bg_grad_color(&s_, value.raw()); return *this; }

inline Style& Style::bg_grad_dir(GradDir value) noexcept { lv_style_set_bg_grad_dir(&s_, static_cast<lv_grad_dir_t>(value)); return *this; }

inline Style& Style::bg_main_stop(int32_t value) noexcept { lv_style_set_bg_main_stop(&s_, value); return *this; }

inline Style& Style::bg_grad_stop(int32_t value) noexcept { lv_style_set_bg_grad_stop(&s_, value); return *this; }

inline Style& Style::bg_main_opa(lv_opa_t value) noexcept { lv_style_set_bg_main_opa(&s_, value); return *this; }

inline Style& Style::bg_grad_opa(lv_opa_t value) noexcept { lv_style_set_bg_grad_opa(&s_, value); return *this; }

inline Style& Style::bg_grad(const lv_grad_dsc_t* value) noexcept { lv_style_set_bg_grad(&s_, value); return *this; }

inline Style& Style::bg_image_src(const void* value) noexcept { lv_style_set_bg_image_src(&s_, value); return *this; }

inline Style& Style::bg_image_opa(lv_opa_t value) noexcept { lv_style_set_bg_image_opa(&s_, value); return *this; }

inline Style& Style::bg_image_recolor(Color value) noexcept { lv_style_set_bg_image_recolor(&s_, value.raw()); return *this; }

inline Style& Style::bg_image_recolor_opa(lv_opa_t value) noexcept { lv_style_set_bg_image_recolor_opa(&s_, value); return *this; }

inline Style& Style::bg_image_tiled(bool value) noexcept { lv_style_set_bg_image_tiled(&s_, value); return *this; }

inline Style& Style::border_color(Color value) noexcept { lv_style_set_border_color(&s_, value.raw()); return *this; }

inline Style& Style::border_opa(lv_opa_t value) noexcept { lv_style_set_border_opa(&s_, value); return *this; }

inline Style& Style::border_width(int32_t value) noexcept { lv_style_set_border_width(&s_, value); return *this; }

inline Style& Style::border_side(BorderSide value) noexcept { lv_style_set_border_side(&s_, static_cast<lv_border_side_t>(value)); return *this; }

inline Style& Style::border_post(bool value) noexcept { lv_style_set_border_post(&s_, value); return *this; }

inline Style& Style::outline_width(int32_t value) noexcept { lv_style_set_outline_width(&s_, value); return *this; }

inline Style& Style::outline_color(Color value) noexcept { lv_style_set_outline_color(&s_, value.raw()); return *this; }

inline Style& Style::outline_opa(lv_opa_t value) noexcept { lv_style_set_outline_opa(&s_, value); return *this; }

inline Style& Style::outline_pad(int32_t value) noexcept { lv_style_set_outline_pad(&s_, value); return *this; }

inline Style& Style::shadow_width(int32_t value) noexcept { lv_style_set_shadow_width(&s_, value); return *this; }

inline Style& Style::shadow_offset_x(int32_t value) noexcept { lv_style_set_shadow_offset_x(&s_, value); return *this; }

inline Style& Style::shadow_offset_y(int32_t value) noexcept { lv_style_set_shadow_offset_y(&s_, value); return *this; }

inline Style& Style::shadow_spread(int32_t value) noexcept { lv_style_set_shadow_spread(&s_, value); return *this; }

inline Style& Style::shadow_color(Color value) noexcept { lv_style_set_shadow_color(&s_, value.raw()); return *this; }

inline Style& Style::shadow_opa(lv_opa_t value) noexcept { lv_style_set_shadow_opa(&s_, value); return *this; }

inline Style& Style::image_opa(lv_opa_t value) noexcept { lv_style_set_image_opa(&s_, value); return *this; }

inline Style& Style::image_recolor(Color value) noexcept { lv_style_set_image_recolor(&s_, value.raw()); return *this; }

inline Style& Style::image_recolor_opa(lv_opa_t value) noexcept { lv_style_set_image_recolor_opa(&s_, value); return *this; }

inline Style& Style::image_colorkey(const lv_image_colorkey_t* value) noexcept { lv_style_set_image_colorkey(&s_, value); return *this; }

inline Style& Style::line_width(int32_t value) noexcept { lv_style_set_line_width(&s_, value); return *this; }

inline Style& Style::line_dash_width(int32_t value) noexcept { lv_style_set_line_dash_width(&s_, value); return *this; }

inline Style& Style::line_dash_gap(int32_t value) noexcept { lv_style_set_line_dash_gap(&s_, value); return *this; }

inline Style& Style::line_rounded(bool value) noexcept { lv_style_set_line_rounded(&s_, value); return *this; }

inline Style& Style::line_color(Color value) noexcept { lv_style_set_line_color(&s_, value.raw()); return *this; }

inline Style& Style::line_opa(lv_opa_t value) noexcept { lv_style_set_line_opa(&s_, value); return *this; }

inline Style& Style::arc_width(int32_t value) noexcept { lv_style_set_arc_width(&s_, value); return *this; }

inline Style& Style::arc_rounded(bool value) noexcept { lv_style_set_arc_rounded(&s_, value); return *this; }

inline Style& Style::arc_color(Color value) noexcept { lv_style_set_arc_color(&s_, value.raw()); return *this; }

inline Style& Style::arc_opa(lv_opa_t value) noexcept { lv_style_set_arc_opa(&s_, value); return *this; }

inline Style& Style::arc_image_src(const void* value) noexcept { lv_style_set_arc_image_src(&s_, value); return *this; }

inline Style& Style::text_color(Color value) noexcept { lv_style_set_text_color(&s_, value.raw()); return *this; }

inline Style& Style::text_opa(lv_opa_t value) noexcept { lv_style_set_text_opa(&s_, value); return *this; }

inline Style& Style::text_font(Font value) noexcept { lv_style_set_text_font(&s_, value.raw()); return *this; }

inline Style& Style::text_letter_space(int32_t value) noexcept { lv_style_set_text_letter_space(&s_, value); return *this; }

inline Style& Style::text_line_space(int32_t value) noexcept { lv_style_set_text_line_space(&s_, value); return *this; }

inline Style& Style::text_decor(TextDecor value) noexcept { lv_style_set_text_decor(&s_, static_cast<lv_text_decor_t>(value)); return *this; }

inline Style& Style::text_align(TextAlign value) noexcept { lv_style_set_text_align(&s_, static_cast<lv_text_align_t>(value)); return *this; }

inline Style& Style::text_outline_stroke_color(Color value) noexcept { lv_style_set_text_outline_stroke_color(&s_, value.raw()); return *this; }

inline Style& Style::text_outline_stroke_width(int32_t value) noexcept { lv_style_set_text_outline_stroke_width(&s_, value); return *this; }

inline Style& Style::text_outline_stroke_opa(lv_opa_t value) noexcept { lv_style_set_text_outline_stroke_opa(&s_, value); return *this; }

inline Style& Style::blur_radius(int32_t value) noexcept { lv_style_set_blur_radius(&s_, value); return *this; }

inline Style& Style::blur_backdrop(bool value) noexcept { lv_style_set_blur_backdrop(&s_, value); return *this; }

inline Style& Style::blur_quality(BlurQuality value) noexcept { lv_style_set_blur_quality(&s_, static_cast<lv_blur_quality_t>(value)); return *this; }

inline Style& Style::drop_shadow_radius(int32_t value) noexcept { lv_style_set_drop_shadow_radius(&s_, value); return *this; }

inline Style& Style::drop_shadow_offset_x(int32_t value) noexcept { lv_style_set_drop_shadow_offset_x(&s_, value); return *this; }

inline Style& Style::drop_shadow_offset_y(int32_t value) noexcept { lv_style_set_drop_shadow_offset_y(&s_, value); return *this; }

inline Style& Style::drop_shadow_color(Color value) noexcept { lv_style_set_drop_shadow_color(&s_, value.raw()); return *this; }

inline Style& Style::drop_shadow_opa(lv_opa_t value) noexcept { lv_style_set_drop_shadow_opa(&s_, value); return *this; }

inline Style& Style::drop_shadow_quality(BlurQuality value) noexcept { lv_style_set_drop_shadow_quality(&s_, static_cast<lv_blur_quality_t>(value)); return *this; }

inline Style& Style::radius(int32_t value) noexcept { lv_style_set_radius(&s_, value); return *this; }

inline Style& Style::radial_offset(int32_t value) noexcept { lv_style_set_radial_offset(&s_, value); return *this; }

inline Style& Style::clip_corner(bool value) noexcept { lv_style_set_clip_corner(&s_, value); return *this; }

inline Style& Style::opa(lv_opa_t value) noexcept { lv_style_set_opa(&s_, value); return *this; }

inline Style& Style::opa_layered(lv_opa_t value) noexcept { lv_style_set_opa_layered(&s_, value); return *this; }

inline Style& Style::color_filter_dsc(ColorFilterDsc& value) noexcept { lv_style_set_color_filter_dsc(&s_, value.raw()); return *this; }

inline Style& Style::color_filter_opa(lv_opa_t value) noexcept { lv_style_set_color_filter_opa(&s_, value); return *this; }

inline Style& Style::recolor(Color value) noexcept { lv_style_set_recolor(&s_, value.raw()); return *this; }

inline Style& Style::recolor_opa(lv_opa_t value) noexcept { lv_style_set_recolor_opa(&s_, value); return *this; }

inline Style& Style::anim(Anim& value) noexcept { lv_style_set_anim(&s_, value.raw()); return *this; }

inline Style& Style::anim_duration(uint32_t value) noexcept { lv_style_set_anim_duration(&s_, value); return *this; }

inline Style& Style::transition(StyleTransitionDsc& value) noexcept { lv_style_set_transition(&s_, value.raw()); return *this; }

inline Style& Style::blend_mode(BlendMode value) noexcept { lv_style_set_blend_mode(&s_, static_cast<lv_blend_mode_t>(value)); return *this; }

inline Style& Style::layout(uint16_t value) noexcept { lv_style_set_layout(&s_, value); return *this; }

inline Style& Style::base_dir(BaseDir value) noexcept { lv_style_set_base_dir(&s_, static_cast<lv_base_dir_t>(value)); return *this; }

inline Style& Style::bitmap_mask_src(const void* value) noexcept { lv_style_set_bitmap_mask_src(&s_, value); return *this; }

inline Style& Style::rotary_sensitivity(uint32_t value) noexcept { lv_style_set_rotary_sensitivity(&s_, value); return *this; }

#if LV_USE_FLEX
inline Style& Style::flex_flow(FlexFlow value) noexcept { lv_style_set_flex_flow(&s_, static_cast<lv_flex_flow_t>(value)); return *this; }

inline Style& Style::flex_main_place(FlexAlign value) noexcept { lv_style_set_flex_main_place(&s_, static_cast<lv_flex_align_t>(value)); return *this; }

inline Style& Style::flex_cross_place(FlexAlign value) noexcept { lv_style_set_flex_cross_place(&s_, static_cast<lv_flex_align_t>(value)); return *this; }

inline Style& Style::flex_track_place(FlexAlign value) noexcept { lv_style_set_flex_track_place(&s_, static_cast<lv_flex_align_t>(value)); return *this; }

inline Style& Style::flex_grow(uint8_t value) noexcept { lv_style_set_flex_grow(&s_, value); return *this; }
#endif // LV_USE_FLEX

#if LV_USE_GRID
template <std::size_t N1>
inline Style& Style::grid_column_dsc_array(const GridTemplate<N1>& value) noexcept { lv_style_set_grid_column_dsc_array(&s_, value.raw()); return *this; }

inline Style& Style::grid_column_align(GridAlign value) noexcept { lv_style_set_grid_column_align(&s_, static_cast<lv_grid_align_t>(value)); return *this; }

template <std::size_t N1>
inline Style& Style::grid_row_dsc_array(const GridTemplate<N1>& value) noexcept { lv_style_set_grid_row_dsc_array(&s_, value.raw()); return *this; }

inline Style& Style::grid_row_align(GridAlign value) noexcept { lv_style_set_grid_row_align(&s_, static_cast<lv_grid_align_t>(value)); return *this; }

inline Style& Style::grid_cell_column_pos(int32_t value) noexcept { lv_style_set_grid_cell_column_pos(&s_, value); return *this; }

inline Style& Style::grid_cell_x_align(GridAlign value) noexcept { lv_style_set_grid_cell_x_align(&s_, static_cast<lv_grid_align_t>(value)); return *this; }

inline Style& Style::grid_cell_column_span(int32_t value) noexcept { lv_style_set_grid_cell_column_span(&s_, value); return *this; }

inline Style& Style::grid_cell_row_pos(int32_t value) noexcept { lv_style_set_grid_cell_row_pos(&s_, value); return *this; }

inline Style& Style::grid_cell_y_align(GridAlign value) noexcept { lv_style_set_grid_cell_y_align(&s_, static_cast<lv_grid_align_t>(value)); return *this; }

inline Style& Style::grid_cell_row_span(int32_t value) noexcept { lv_style_set_grid_cell_row_span(&s_, value); return *this; }
#endif // LV_USE_GRID

inline void Style::copy(Style& src) noexcept { lv_style_copy(&s_, src.raw()); }

inline StyleRes Style::get_prop(lv_style_prop_t prop, lv_style_value_t* value) const noexcept { return static_cast<StyleRes>(lv_style_get_prop(&s_, prop, value)); }

inline StyleRes Style::get_prop_inlined(lv_style_prop_t prop, lv_style_value_t* value) const noexcept { return static_cast<StyleRes>(lv_style_get_prop_inlined(&s_, prop, value)); }

inline void Style::init() noexcept { lv_style_init(&s_); }

inline bool Style::is_const() const noexcept { return lv_style_is_const(&s_); }

inline bool Style::is_empty() const noexcept { return lv_style_is_empty(&s_); }

inline void Style::merge(Style& src) noexcept { lv_style_merge(&s_, src.raw()); }

inline bool Style::remove_prop(lv_style_prop_t prop) noexcept { return lv_style_remove_prop(&s_, prop); }

inline void Style::reset() noexcept { lv_style_reset(&s_); }

} // namespace lv
