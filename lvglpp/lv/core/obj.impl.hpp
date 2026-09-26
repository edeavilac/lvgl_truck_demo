#pragma once
// Bodies of core/obj.hpp, separated because its file cycle needs every type
// complete. Same mechanism as D-C7, applied where the graph asks for it.
// Included by the umbrella and never by a header: it is NOT a translation
// unit and every definition in it is `inline`. The stem says so, not the
// extension, so a glob written for *.hpp still installs it.

#include "lv/lvgl.hpp"

namespace lv {

inline ChildRange Obj::children() const noexcept { return ChildRange(p_, lv_obj_get_child_count(p_)); }

inline void Obj::add_flag(ObjFlag f) const noexcept { lv_obj_add_flag(p_, static_cast<lv_obj_flag_t>(f)); }

inline void Obj::add_play_timeline_event(EventCode trigger, AnimTimeline at, uint32_t delay, bool reverse) const noexcept { lv_obj_add_play_timeline_event(p_, static_cast<lv_event_code_t>(trigger), at.raw(), delay, reverse); }

inline void Obj::add_screen_create_event(EventCode trigger, lv_screen_create_cb_t screen_create_cb, ScreenLoadAnim anim_type, uint32_t duration, uint32_t delay) const noexcept { lv_obj_add_screen_create_event(p_, static_cast<lv_event_code_t>(trigger), screen_create_cb, static_cast<lv_screen_load_anim_t>(anim_type), duration, delay); }

inline void Obj::add_screen_load_event(EventCode trigger, Obj screen, ScreenLoadAnim anim_type, uint32_t duration, uint32_t delay) const noexcept { lv_obj_add_screen_load_event(p_, static_cast<lv_event_code_t>(trigger), screen.raw(), static_cast<lv_screen_load_anim_t>(anim_type), duration, delay); }

inline void Obj::add_state(State state) const noexcept { lv_obj_add_state(p_, static_cast<lv_state_t>(state)); }

inline void Obj::allocate_spec_attr() const noexcept { lv_obj_allocate_spec_attr(p_); }

inline bool Obj::check_type(ObjClass class_p) const noexcept { return lv_obj_check_type(p_, class_p.raw()); }

inline Obj Obj::create(Obj parent) noexcept { return Obj(lv_obj_create(parent.raw())); }

#if LV_USE_OBJ_ID
inline Obj Obj::find_by_id(const void* id) const noexcept { return Obj(lv_obj_find_by_id(p_, id)); }

inline void Obj::free_id() const noexcept { lv_obj_free_id(p_); }
#endif // LV_USE_OBJ_ID

inline ObjClass Obj::get_class() const noexcept { return ObjClass(const_cast<lv_obj_class_t*>(lv_obj_get_class(p_))); }

inline Group Obj::get_group() const noexcept { return Group(lv_obj_get_group(p_)); }

#if LV_USE_OBJ_ID
inline void* Obj::get_id() const noexcept { return lv_obj_get_id(p_); }
#endif // LV_USE_OBJ_ID

inline State Obj::get_state() const noexcept { return static_cast<State>(lv_obj_get_state(p_)); }

inline void* Obj::get_user_data() const noexcept { return lv_obj_get_user_data(p_); }

inline bool Obj::has_class(ObjClass class_p) const noexcept { return lv_obj_has_class(p_, class_p.raw()); }

inline bool Obj::has_flag(ObjFlag f) const noexcept { return lv_obj_has_flag(p_, static_cast<lv_obj_flag_t>(f)); }

inline bool Obj::has_flag_any(ObjFlag f) const noexcept { return lv_obj_has_flag_any(p_, static_cast<lv_obj_flag_t>(f)); }

inline bool Obj::has_state(State state) const noexcept { return lv_obj_has_state(p_, static_cast<lv_state_t>(state)); }

inline bool Obj::is_radio_button() const noexcept { return lv_obj_is_radio_button(p_); }

inline bool Obj::is_valid() const noexcept { return lv_obj_is_valid(p_); }

inline void Obj::remove_flag(ObjFlag f) const noexcept { lv_obj_remove_flag(p_, static_cast<lv_obj_flag_t>(f)); }

inline void Obj::remove_state(State state) const noexcept { lv_obj_remove_state(p_, static_cast<lv_state_t>(state)); }

#if LV_USE_EXT_DATA
template <auto Fn>
inline void Obj::set_external_data(void* data) const noexcept { lv_obj_set_external_data(p_, data, &detail::ObjSetExternalDataThunk<Fn>::call); }
#endif // LV_USE_EXT_DATA

inline void Obj::set_flag(ObjFlag f, bool v) const noexcept { lv_obj_set_flag(p_, static_cast<lv_obj_flag_t>(f), v); }

#if LV_USE_OBJ_ID
inline void Obj::set_id(void* id) const noexcept { lv_obj_set_id(p_, id); }
#endif // LV_USE_OBJ_ID

inline void Obj::set_radio_button(bool en) const noexcept { lv_obj_set_radio_button(p_, en); }

inline void Obj::set_state(State state, bool v) const noexcept { lv_obj_set_state(p_, static_cast<lv_state_t>(state), v); }

inline void Obj::set_user_data(void* user_data) const noexcept { lv_obj_set_user_data(p_, user_data); }

#if LV_USE_OBJ_ID
inline const char* Obj::stringify_id(char* buf, uint32_t len) const noexcept { return lv_obj_stringify_id(p_, buf, len); }
#endif // LV_USE_OBJ_ID

inline LocalStyle Obj::style(Selector sel) const noexcept { return LocalStyle(p_, sel); }

inline int32_t Obj::get_style_clamped_width() const noexcept { return lv_obj_get_style_clamped_width(p_); }

inline int32_t Obj::get_style_clamped_height() const noexcept { return lv_obj_get_style_clamped_height(p_); }

#if LV_USE_OBJ_PROPERTY
inline lv_property_t Obj::get_style_property(lv_prop_id_t id, Part part) const noexcept { return lv_obj_get_style_property(p_, id, static_cast<lv_part_t>(part)); }
#endif // LV_USE_OBJ_PROPERTY

inline lv_style_value_t Obj::get_style_prop(Part part, lv_style_prop_t prop) const noexcept { return lv_obj_get_style_prop(p_, static_cast<lv_part_t>(part), prop); }

inline int32_t Obj::get_style_space_left(Part part) const noexcept { return lv_obj_get_style_space_left(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_space_right(Part part) const noexcept { return lv_obj_get_style_space_right(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_space_top(Part part) const noexcept { return lv_obj_get_style_space_top(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_space_bottom(Part part) const noexcept { return lv_obj_get_style_space_bottom(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_transform_scale_x_safe(Part part) const noexcept { return lv_obj_get_style_transform_scale_x_safe(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_transform_scale_y_safe(Part part) const noexcept { return lv_obj_get_style_transform_scale_y_safe(p_, static_cast<lv_part_t>(part)); }

inline lv_opa_t Obj::get_style_opa_recursive(Part part) const noexcept { return lv_obj_get_style_opa_recursive(p_, static_cast<lv_part_t>(part)); }

inline lv_color32_t Obj::get_style_recolor_recursive(Part part) const noexcept { return lv_obj_get_style_recolor_recursive(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_width(Part part) const noexcept { return lv_obj_get_style_width(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_min_width(Part part) const noexcept { return lv_obj_get_style_min_width(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_max_width(Part part) const noexcept { return lv_obj_get_style_max_width(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_height(Part part) const noexcept { return lv_obj_get_style_height(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_min_height(Part part) const noexcept { return lv_obj_get_style_min_height(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_max_height(Part part) const noexcept { return lv_obj_get_style_max_height(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_length(Part part) const noexcept { return lv_obj_get_style_length(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_x(Part part) const noexcept { return lv_obj_get_style_x(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_y(Part part) const noexcept { return lv_obj_get_style_y(p_, static_cast<lv_part_t>(part)); }

inline Align Obj::get_style_align(Part part) const noexcept { return static_cast<Align>(lv_obj_get_style_align(p_, static_cast<lv_part_t>(part))); }

inline int32_t Obj::get_style_transform_width(Part part) const noexcept { return lv_obj_get_style_transform_width(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_transform_height(Part part) const noexcept { return lv_obj_get_style_transform_height(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_translate_x(Part part) const noexcept { return lv_obj_get_style_translate_x(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_translate_y(Part part) const noexcept { return lv_obj_get_style_translate_y(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_translate_radial(Part part) const noexcept { return lv_obj_get_style_translate_radial(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_transform_scale_x(Part part) const noexcept { return lv_obj_get_style_transform_scale_x(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_transform_scale_y(Part part) const noexcept { return lv_obj_get_style_transform_scale_y(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_transform_rotation(Part part) const noexcept { return lv_obj_get_style_transform_rotation(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_transform_pivot_x(Part part) const noexcept { return lv_obj_get_style_transform_pivot_x(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_transform_pivot_y(Part part) const noexcept { return lv_obj_get_style_transform_pivot_y(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_transform_skew_x(Part part) const noexcept { return lv_obj_get_style_transform_skew_x(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_transform_skew_y(Part part) const noexcept { return lv_obj_get_style_transform_skew_y(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_pad_top(Part part) const noexcept { return lv_obj_get_style_pad_top(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_pad_bottom(Part part) const noexcept { return lv_obj_get_style_pad_bottom(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_pad_left(Part part) const noexcept { return lv_obj_get_style_pad_left(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_pad_right(Part part) const noexcept { return lv_obj_get_style_pad_right(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_pad_row(Part part) const noexcept { return lv_obj_get_style_pad_row(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_pad_column(Part part) const noexcept { return lv_obj_get_style_pad_column(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_pad_radial(Part part) const noexcept { return lv_obj_get_style_pad_radial(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_margin_top(Part part) const noexcept { return lv_obj_get_style_margin_top(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_margin_bottom(Part part) const noexcept { return lv_obj_get_style_margin_bottom(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_margin_left(Part part) const noexcept { return lv_obj_get_style_margin_left(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_margin_right(Part part) const noexcept { return lv_obj_get_style_margin_right(p_, static_cast<lv_part_t>(part)); }

inline Color Obj::get_style_bg_color(Part part) const noexcept { return Color{lv_obj_get_style_bg_color(p_, static_cast<lv_part_t>(part))}; }

inline Color Obj::get_style_bg_color_filtered(Part part) const noexcept { return Color{lv_obj_get_style_bg_color_filtered(p_, static_cast<lv_part_t>(part))}; }

inline lv_opa_t Obj::get_style_bg_opa(Part part) const noexcept { return lv_obj_get_style_bg_opa(p_, static_cast<lv_part_t>(part)); }

inline Color Obj::get_style_bg_grad_color(Part part) const noexcept { return Color{lv_obj_get_style_bg_grad_color(p_, static_cast<lv_part_t>(part))}; }

inline Color Obj::get_style_bg_grad_color_filtered(Part part) const noexcept { return Color{lv_obj_get_style_bg_grad_color_filtered(p_, static_cast<lv_part_t>(part))}; }

inline GradDir Obj::get_style_bg_grad_dir(Part part) const noexcept { return static_cast<GradDir>(lv_obj_get_style_bg_grad_dir(p_, static_cast<lv_part_t>(part))); }

inline int32_t Obj::get_style_bg_main_stop(Part part) const noexcept { return lv_obj_get_style_bg_main_stop(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_bg_grad_stop(Part part) const noexcept { return lv_obj_get_style_bg_grad_stop(p_, static_cast<lv_part_t>(part)); }

inline lv_opa_t Obj::get_style_bg_main_opa(Part part) const noexcept { return lv_obj_get_style_bg_main_opa(p_, static_cast<lv_part_t>(part)); }

inline lv_opa_t Obj::get_style_bg_grad_opa(Part part) const noexcept { return lv_obj_get_style_bg_grad_opa(p_, static_cast<lv_part_t>(part)); }

inline const lv_grad_dsc_t* Obj::get_style_bg_grad(Part part) const noexcept { return lv_obj_get_style_bg_grad(p_, static_cast<lv_part_t>(part)); }

inline const void* Obj::get_style_bg_image_src(Part part) const noexcept { return lv_obj_get_style_bg_image_src(p_, static_cast<lv_part_t>(part)); }

inline lv_opa_t Obj::get_style_bg_image_opa(Part part) const noexcept { return lv_obj_get_style_bg_image_opa(p_, static_cast<lv_part_t>(part)); }

inline Color Obj::get_style_bg_image_recolor(Part part) const noexcept { return Color{lv_obj_get_style_bg_image_recolor(p_, static_cast<lv_part_t>(part))}; }

inline Color Obj::get_style_bg_image_recolor_filtered(Part part) const noexcept { return Color{lv_obj_get_style_bg_image_recolor_filtered(p_, static_cast<lv_part_t>(part))}; }

inline lv_opa_t Obj::get_style_bg_image_recolor_opa(Part part) const noexcept { return lv_obj_get_style_bg_image_recolor_opa(p_, static_cast<lv_part_t>(part)); }

inline bool Obj::get_style_bg_image_tiled(Part part) const noexcept { return lv_obj_get_style_bg_image_tiled(p_, static_cast<lv_part_t>(part)); }

inline Color Obj::get_style_border_color(Part part) const noexcept { return Color{lv_obj_get_style_border_color(p_, static_cast<lv_part_t>(part))}; }

inline Color Obj::get_style_border_color_filtered(Part part) const noexcept { return Color{lv_obj_get_style_border_color_filtered(p_, static_cast<lv_part_t>(part))}; }

inline lv_opa_t Obj::get_style_border_opa(Part part) const noexcept { return lv_obj_get_style_border_opa(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_border_width(Part part) const noexcept { return lv_obj_get_style_border_width(p_, static_cast<lv_part_t>(part)); }

inline BorderSide Obj::get_style_border_side(Part part) const noexcept { return static_cast<BorderSide>(lv_obj_get_style_border_side(p_, static_cast<lv_part_t>(part))); }

inline bool Obj::get_style_border_post(Part part) const noexcept { return lv_obj_get_style_border_post(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_outline_width(Part part) const noexcept { return lv_obj_get_style_outline_width(p_, static_cast<lv_part_t>(part)); }

inline Color Obj::get_style_outline_color(Part part) const noexcept { return Color{lv_obj_get_style_outline_color(p_, static_cast<lv_part_t>(part))}; }

inline Color Obj::get_style_outline_color_filtered(Part part) const noexcept { return Color{lv_obj_get_style_outline_color_filtered(p_, static_cast<lv_part_t>(part))}; }

inline lv_opa_t Obj::get_style_outline_opa(Part part) const noexcept { return lv_obj_get_style_outline_opa(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_outline_pad(Part part) const noexcept { return lv_obj_get_style_outline_pad(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_shadow_width(Part part) const noexcept { return lv_obj_get_style_shadow_width(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_shadow_offset_x(Part part) const noexcept { return lv_obj_get_style_shadow_offset_x(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_shadow_offset_y(Part part) const noexcept { return lv_obj_get_style_shadow_offset_y(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_shadow_spread(Part part) const noexcept { return lv_obj_get_style_shadow_spread(p_, static_cast<lv_part_t>(part)); }

inline Color Obj::get_style_shadow_color(Part part) const noexcept { return Color{lv_obj_get_style_shadow_color(p_, static_cast<lv_part_t>(part))}; }

inline Color Obj::get_style_shadow_color_filtered(Part part) const noexcept { return Color{lv_obj_get_style_shadow_color_filtered(p_, static_cast<lv_part_t>(part))}; }

inline lv_opa_t Obj::get_style_shadow_opa(Part part) const noexcept { return lv_obj_get_style_shadow_opa(p_, static_cast<lv_part_t>(part)); }

inline lv_opa_t Obj::get_style_image_opa(Part part) const noexcept { return lv_obj_get_style_image_opa(p_, static_cast<lv_part_t>(part)); }

inline Color Obj::get_style_image_recolor(Part part) const noexcept { return Color{lv_obj_get_style_image_recolor(p_, static_cast<lv_part_t>(part))}; }

inline Color Obj::get_style_image_recolor_filtered(Part part) const noexcept { return Color{lv_obj_get_style_image_recolor_filtered(p_, static_cast<lv_part_t>(part))}; }

inline lv_opa_t Obj::get_style_image_recolor_opa(Part part) const noexcept { return lv_obj_get_style_image_recolor_opa(p_, static_cast<lv_part_t>(part)); }

inline const lv_image_colorkey_t* Obj::get_style_image_colorkey(Part part) const noexcept { return lv_obj_get_style_image_colorkey(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_line_width(Part part) const noexcept { return lv_obj_get_style_line_width(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_line_dash_width(Part part) const noexcept { return lv_obj_get_style_line_dash_width(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_line_dash_gap(Part part) const noexcept { return lv_obj_get_style_line_dash_gap(p_, static_cast<lv_part_t>(part)); }

inline bool Obj::get_style_line_rounded(Part part) const noexcept { return lv_obj_get_style_line_rounded(p_, static_cast<lv_part_t>(part)); }

inline Color Obj::get_style_line_color(Part part) const noexcept { return Color{lv_obj_get_style_line_color(p_, static_cast<lv_part_t>(part))}; }

inline Color Obj::get_style_line_color_filtered(Part part) const noexcept { return Color{lv_obj_get_style_line_color_filtered(p_, static_cast<lv_part_t>(part))}; }

inline lv_opa_t Obj::get_style_line_opa(Part part) const noexcept { return lv_obj_get_style_line_opa(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_arc_width(Part part) const noexcept { return lv_obj_get_style_arc_width(p_, static_cast<lv_part_t>(part)); }

inline bool Obj::get_style_arc_rounded(Part part) const noexcept { return lv_obj_get_style_arc_rounded(p_, static_cast<lv_part_t>(part)); }

inline Color Obj::get_style_arc_color(Part part) const noexcept { return Color{lv_obj_get_style_arc_color(p_, static_cast<lv_part_t>(part))}; }

inline Color Obj::get_style_arc_color_filtered(Part part) const noexcept { return Color{lv_obj_get_style_arc_color_filtered(p_, static_cast<lv_part_t>(part))}; }

inline lv_opa_t Obj::get_style_arc_opa(Part part) const noexcept { return lv_obj_get_style_arc_opa(p_, static_cast<lv_part_t>(part)); }

inline const void* Obj::get_style_arc_image_src(Part part) const noexcept { return lv_obj_get_style_arc_image_src(p_, static_cast<lv_part_t>(part)); }

inline Color Obj::get_style_text_color(Part part) const noexcept { return Color{lv_obj_get_style_text_color(p_, static_cast<lv_part_t>(part))}; }

inline Color Obj::get_style_text_color_filtered(Part part) const noexcept { return Color{lv_obj_get_style_text_color_filtered(p_, static_cast<lv_part_t>(part))}; }

inline lv_opa_t Obj::get_style_text_opa(Part part) const noexcept { return lv_obj_get_style_text_opa(p_, static_cast<lv_part_t>(part)); }

inline Font Obj::get_style_text_font(Part part) const noexcept { return Font(const_cast<lv_font_t*>(lv_obj_get_style_text_font(p_, static_cast<lv_part_t>(part)))); }

inline int32_t Obj::get_style_text_letter_space(Part part) const noexcept { return lv_obj_get_style_text_letter_space(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_text_line_space(Part part) const noexcept { return lv_obj_get_style_text_line_space(p_, static_cast<lv_part_t>(part)); }

inline TextDecor Obj::get_style_text_decor(Part part) const noexcept { return static_cast<TextDecor>(lv_obj_get_style_text_decor(p_, static_cast<lv_part_t>(part))); }

inline TextAlign Obj::get_style_text_align(Part part) const noexcept { return static_cast<TextAlign>(lv_obj_get_style_text_align(p_, static_cast<lv_part_t>(part))); }

inline Color Obj::get_style_text_outline_stroke_color(Part part) const noexcept { return Color{lv_obj_get_style_text_outline_stroke_color(p_, static_cast<lv_part_t>(part))}; }

inline Color Obj::get_style_text_outline_stroke_color_filtered(Part part) const noexcept { return Color{lv_obj_get_style_text_outline_stroke_color_filtered(p_, static_cast<lv_part_t>(part))}; }

inline int32_t Obj::get_style_text_outline_stroke_width(Part part) const noexcept { return lv_obj_get_style_text_outline_stroke_width(p_, static_cast<lv_part_t>(part)); }

inline lv_opa_t Obj::get_style_text_outline_stroke_opa(Part part) const noexcept { return lv_obj_get_style_text_outline_stroke_opa(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_blur_radius(Part part) const noexcept { return lv_obj_get_style_blur_radius(p_, static_cast<lv_part_t>(part)); }

inline bool Obj::get_style_blur_backdrop(Part part) const noexcept { return lv_obj_get_style_blur_backdrop(p_, static_cast<lv_part_t>(part)); }

inline BlurQuality Obj::get_style_blur_quality(Part part) const noexcept { return static_cast<BlurQuality>(lv_obj_get_style_blur_quality(p_, static_cast<lv_part_t>(part))); }

inline int32_t Obj::get_style_drop_shadow_radius(Part part) const noexcept { return lv_obj_get_style_drop_shadow_radius(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_drop_shadow_offset_x(Part part) const noexcept { return lv_obj_get_style_drop_shadow_offset_x(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_drop_shadow_offset_y(Part part) const noexcept { return lv_obj_get_style_drop_shadow_offset_y(p_, static_cast<lv_part_t>(part)); }

inline Color Obj::get_style_drop_shadow_color(Part part) const noexcept { return Color{lv_obj_get_style_drop_shadow_color(p_, static_cast<lv_part_t>(part))}; }

inline Color Obj::get_style_drop_shadow_color_filtered(Part part) const noexcept { return Color{lv_obj_get_style_drop_shadow_color_filtered(p_, static_cast<lv_part_t>(part))}; }

inline lv_opa_t Obj::get_style_drop_shadow_opa(Part part) const noexcept { return lv_obj_get_style_drop_shadow_opa(p_, static_cast<lv_part_t>(part)); }

inline BlurQuality Obj::get_style_drop_shadow_quality(Part part) const noexcept { return static_cast<BlurQuality>(lv_obj_get_style_drop_shadow_quality(p_, static_cast<lv_part_t>(part))); }

inline int32_t Obj::get_style_radius(Part part) const noexcept { return lv_obj_get_style_radius(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_radial_offset(Part part) const noexcept { return lv_obj_get_style_radial_offset(p_, static_cast<lv_part_t>(part)); }

inline bool Obj::get_style_clip_corner(Part part) const noexcept { return lv_obj_get_style_clip_corner(p_, static_cast<lv_part_t>(part)); }

inline lv_opa_t Obj::get_style_opa(Part part) const noexcept { return lv_obj_get_style_opa(p_, static_cast<lv_part_t>(part)); }

inline lv_opa_t Obj::get_style_opa_layered(Part part) const noexcept { return lv_obj_get_style_opa_layered(p_, static_cast<lv_part_t>(part)); }

inline const lv_color_filter_dsc_t* Obj::get_style_color_filter_dsc(Part part) const noexcept { return lv_obj_get_style_color_filter_dsc(p_, static_cast<lv_part_t>(part)); }

inline lv_opa_t Obj::get_style_color_filter_opa(Part part) const noexcept { return lv_obj_get_style_color_filter_opa(p_, static_cast<lv_part_t>(part)); }

inline Color Obj::get_style_recolor(Part part) const noexcept { return Color{lv_obj_get_style_recolor(p_, static_cast<lv_part_t>(part))}; }

inline lv_opa_t Obj::get_style_recolor_opa(Part part) const noexcept { return lv_obj_get_style_recolor_opa(p_, static_cast<lv_part_t>(part)); }

inline const lv_anim_t* Obj::get_style_anim(Part part) const noexcept { return lv_obj_get_style_anim(p_, static_cast<lv_part_t>(part)); }

inline uint32_t Obj::get_style_anim_duration(Part part) const noexcept { return lv_obj_get_style_anim_duration(p_, static_cast<lv_part_t>(part)); }

inline const lv_style_transition_dsc_t* Obj::get_style_transition(Part part) const noexcept { return lv_obj_get_style_transition(p_, static_cast<lv_part_t>(part)); }

inline BlendMode Obj::get_style_blend_mode(Part part) const noexcept { return static_cast<BlendMode>(lv_obj_get_style_blend_mode(p_, static_cast<lv_part_t>(part))); }

inline uint16_t Obj::get_style_layout(Part part) const noexcept { return lv_obj_get_style_layout(p_, static_cast<lv_part_t>(part)); }

inline BaseDir Obj::get_style_base_dir(Part part) const noexcept { return static_cast<BaseDir>(lv_obj_get_style_base_dir(p_, static_cast<lv_part_t>(part))); }

inline const void* Obj::get_style_bitmap_mask_src(Part part) const noexcept { return lv_obj_get_style_bitmap_mask_src(p_, static_cast<lv_part_t>(part)); }

inline uint32_t Obj::get_style_rotary_sensitivity(Part part) const noexcept { return lv_obj_get_style_rotary_sensitivity(p_, static_cast<lv_part_t>(part)); }

#if LV_USE_FLEX
inline FlexFlow Obj::get_style_flex_flow(Part part) const noexcept { return static_cast<FlexFlow>(lv_obj_get_style_flex_flow(p_, static_cast<lv_part_t>(part))); }

inline FlexAlign Obj::get_style_flex_main_place(Part part) const noexcept { return static_cast<FlexAlign>(lv_obj_get_style_flex_main_place(p_, static_cast<lv_part_t>(part))); }

inline FlexAlign Obj::get_style_flex_cross_place(Part part) const noexcept { return static_cast<FlexAlign>(lv_obj_get_style_flex_cross_place(p_, static_cast<lv_part_t>(part))); }

inline FlexAlign Obj::get_style_flex_track_place(Part part) const noexcept { return static_cast<FlexAlign>(lv_obj_get_style_flex_track_place(p_, static_cast<lv_part_t>(part))); }

inline uint8_t Obj::get_style_flex_grow(Part part) const noexcept { return lv_obj_get_style_flex_grow(p_, static_cast<lv_part_t>(part)); }
#endif // LV_USE_FLEX

#if LV_USE_GRID
inline const int32_t* Obj::get_style_grid_column_dsc_array(Part part) const noexcept { return lv_obj_get_style_grid_column_dsc_array(p_, static_cast<lv_part_t>(part)); }

inline GridAlign Obj::get_style_grid_column_align(Part part) const noexcept { return static_cast<GridAlign>(lv_obj_get_style_grid_column_align(p_, static_cast<lv_part_t>(part))); }

inline const int32_t* Obj::get_style_grid_row_dsc_array(Part part) const noexcept { return lv_obj_get_style_grid_row_dsc_array(p_, static_cast<lv_part_t>(part)); }

inline GridAlign Obj::get_style_grid_row_align(Part part) const noexcept { return static_cast<GridAlign>(lv_obj_get_style_grid_row_align(p_, static_cast<lv_part_t>(part))); }

inline int32_t Obj::get_style_grid_cell_column_pos(Part part) const noexcept { return lv_obj_get_style_grid_cell_column_pos(p_, static_cast<lv_part_t>(part)); }

inline GridAlign Obj::get_style_grid_cell_x_align(Part part) const noexcept { return static_cast<GridAlign>(lv_obj_get_style_grid_cell_x_align(p_, static_cast<lv_part_t>(part))); }

inline int32_t Obj::get_style_grid_cell_column_span(Part part) const noexcept { return lv_obj_get_style_grid_cell_column_span(p_, static_cast<lv_part_t>(part)); }

inline int32_t Obj::get_style_grid_cell_row_pos(Part part) const noexcept { return lv_obj_get_style_grid_cell_row_pos(p_, static_cast<lv_part_t>(part)); }

inline GridAlign Obj::get_style_grid_cell_y_align(Part part) const noexcept { return static_cast<GridAlign>(lv_obj_get_style_grid_cell_y_align(p_, static_cast<lv_part_t>(part))); }

inline int32_t Obj::get_style_grid_cell_row_span(Part part) const noexcept { return lv_obj_get_style_grid_cell_row_span(p_, static_cast<lv_part_t>(part)); }
#endif // LV_USE_GRID

#if LVPP_COMPAT_V8
inline void Obj::del() const noexcept { return delete_(); }

inline void Obj::del_async() const noexcept { return delete_async(); }

inline void Obj::clear_flag(ObjFlag f) const noexcept { return remove_flag(f); }

inline void Obj::clear_state(State state) const noexcept { return remove_state(state); }

inline uint32_t Obj::get_child_cnt() const noexcept { return get_child_count(); }

inline Display Obj::get_disp() const noexcept { return get_display(); }

inline uint32_t Obj::get_style_anim_time(Part part) const noexcept { return get_style_anim_duration(part); }

inline lv_opa_t Obj::get_style_img_opa(Part part) const noexcept { return get_style_image_opa(part); }

inline Color Obj::get_style_img_recolor(Part part) const noexcept { return get_style_image_recolor(part); }

inline Color Obj::get_style_img_recolor_filtered(Part part) const noexcept { return get_style_image_recolor_filtered(part); }

inline lv_opa_t Obj::get_style_img_recolor_opa(Part part) const noexcept { return get_style_image_recolor_opa(part); }

inline int32_t Obj::get_style_shadow_ofs_x(Part part) const noexcept { return get_style_shadow_offset_x(part); }

inline int32_t Obj::get_style_shadow_ofs_y(Part part) const noexcept { return get_style_shadow_offset_y(part); }

inline int32_t Obj::get_style_transform_angle(Part part) const noexcept { return get_style_transform_rotation(part); }

inline const void* Obj::get_style_bg_img_src(Part part) const noexcept { return get_style_bg_image_src(part); }

inline Color Obj::get_style_bg_img_recolor(Part part) const noexcept { return get_style_bg_image_recolor(part); }

inline lv_opa_t Obj::get_style_bg_img_recolor_opa(Part part) const noexcept { return get_style_bg_image_recolor_opa(part); }
#endif // LVPP_COMPAT_V8

inline void obj_null_on_delete(lv_obj_t** obj_ptr) noexcept { lv_obj_null_on_delete(obj_ptr); }

#if LV_USE_OBJ_ID
inline void obj_assign_id(ObjClass class_p, Obj obj) noexcept { lv_obj_assign_id(class_p.raw(), obj.raw()); }

inline int32_t obj_id_compare(const void* id1, const void* id2) noexcept { return lv_obj_id_compare(id1, id2); }
#endif // LV_USE_OBJ_ID

#if (LV_USE_OBJ_ID) && (LV_USE_OBJ_ID_BUILTIN)
inline void obj_objid_builtin_destroy() noexcept { lv_objid_builtin_destroy(); }
#endif // (LV_USE_OBJ_ID) && (LV_USE_OBJ_ID_BUILTIN)

} // namespace lv
