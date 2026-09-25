#pragma once
// Bodies of display/display.hpp, separated because its file cycle needs every type
// complete. Same mechanism as D-C7, applied where the graph asks for it.
// Included by the umbrella and never by a header: it is NOT a translation
// unit and every definition in it is `inline`. The stem says so, not the
// extension, so a glob written for *.hpp still installs it.

#include "lv/lvgl.hpp"

namespace lv {

inline lv_area_t* Event::get_invalidated_area() const noexcept { return lv_event_get_invalidated_area(p_); }

inline Display Display::create(int32_t hor_res, int32_t ver_res) noexcept { return Display(lv_display_create(hor_res, ver_res)); }

inline void Display::delete_() const noexcept { lv_display_delete(p_); }

inline bool Display::delete_event(uint32_t index) const noexcept { return lv_display_delete_event(p_, index); }

inline void Display::delete_refr_timer() const noexcept { lv_display_delete_refr_timer(p_); }

inline int32_t Display::dpx(int32_t n) const noexcept { return lv_display_dpx(p_, n); }

inline void Display::enable_invalidation(bool en) const noexcept { lv_display_enable_invalidation(p_, en); }

inline bool Display::flush_is_last() const noexcept { return lv_display_flush_is_last(p_); }

inline void Display::flush_ready() const noexcept { lv_display_flush_ready(p_); }

inline bool Display::get_antialiasing() const noexcept { return lv_display_get_antialiasing(p_); }

inline DrawBuf Display::get_buf_active() const noexcept { return DrawBuf(lv_display_get_buf_active(p_)); }

inline ColorFormat Display::get_color_format() const noexcept { return static_cast<ColorFormat>(lv_display_get_color_format(p_)); }

inline int32_t Display::get_dpi() const noexcept { return lv_display_get_dpi(p_); }

inline uint32_t Display::get_draw_buf_size() const noexcept { return lv_display_get_draw_buf_size(p_); }

inline void* Display::get_driver_data() const noexcept { return lv_display_get_driver_data(p_); }

inline uint32_t Display::get_event_count() const noexcept { return lv_display_get_event_count(p_); }

inline EventDsc Display::get_event_dsc(uint32_t index) const noexcept { return EventDsc(lv_display_get_event_dsc(p_, index)); }

inline int32_t Display::get_horizontal_resolution() const noexcept { return lv_display_get_horizontal_resolution(p_); }

inline uint32_t Display::get_inactive_time() const noexcept { return lv_display_get_inactive_time(p_); }

inline uint32_t Display::get_invalidated_draw_buf_size(uint32_t width, uint32_t height) const noexcept { return lv_display_get_invalidated_draw_buf_size(p_, width, height); }

inline Obj Display::get_layer_bottom() const noexcept { return Obj(lv_display_get_layer_bottom(p_)); }

inline Obj Display::get_layer_sys() const noexcept { return Obj(lv_display_get_layer_sys(p_)); }

inline Obj Display::get_layer_top() const noexcept { return Obj(lv_display_get_layer_top(p_)); }

inline bool Display::get_matrix_rotation() const noexcept { return lv_display_get_matrix_rotation(p_); }

inline Display Display::get_next() const noexcept { return Display(lv_display_get_next(p_)); }

inline int32_t Display::get_offset_x() const noexcept { return lv_display_get_offset_x(p_); }

inline int32_t Display::get_offset_y() const noexcept { return lv_display_get_offset_y(p_); }

inline int32_t Display::get_original_horizontal_resolution() const noexcept { return lv_display_get_original_horizontal_resolution(p_); }

inline int32_t Display::get_original_vertical_resolution() const noexcept { return lv_display_get_original_vertical_resolution(p_); }

inline int32_t Display::get_physical_horizontal_resolution() const noexcept { return lv_display_get_physical_horizontal_resolution(p_); }

inline int32_t Display::get_physical_vertical_resolution() const noexcept { return lv_display_get_physical_vertical_resolution(p_); }

inline Timer Display::get_refr_timer() const noexcept { return Timer(lv_display_get_refr_timer(p_)); }

inline DisplayRenderMode Display::get_render_mode() const noexcept { return static_cast<DisplayRenderMode>(lv_display_get_render_mode(p_)); }

inline DisplayRotation Display::get_rotation() const noexcept { return static_cast<DisplayRotation>(lv_display_get_rotation(p_)); }

inline Obj Display::get_screen_active() const noexcept { return Obj(lv_display_get_screen_active(p_)); }

#if LV_USE_OBJ_NAME
inline Obj Display::get_screen_by_name(const char* screen_name) const noexcept { return Obj(lv_display_get_screen_by_name(p_, screen_name)); }
#endif // LV_USE_OBJ_NAME

inline Obj Display::get_screen_loading() const noexcept { return Obj(lv_display_get_screen_loading(p_)); }

inline Obj Display::get_screen_prev() const noexcept { return Obj(lv_display_get_screen_prev(p_)); }

inline Theme Display::get_theme() const noexcept { return Theme(lv_display_get_theme(p_)); }

inline uint32_t Display::get_tile_cnt() const noexcept { return lv_display_get_tile_cnt(p_); }

inline void* Display::get_user_data() const noexcept { return lv_display_get_user_data(p_); }

inline int32_t Display::get_vertical_resolution() const noexcept { return lv_display_get_vertical_resolution(p_); }

inline bool Display::is_double_buffered() const noexcept { return lv_display_is_double_buffered(p_); }

inline bool Display::is_invalidation_enabled() const noexcept { return lv_display_is_invalidation_enabled(p_); }

inline bool Display::register_vsync_event(lv_event_cb_t event_cb, void* user_data) const noexcept { return lv_display_register_vsync_event(p_, event_cb, user_data); }

inline uint32_t Display::remove_event_cb_with_user_data(lv_event_cb_t event_cb, void* user_data) const noexcept { return lv_display_remove_event_cb_with_user_data(p_, event_cb, user_data); }

inline void Display::rotate_area(Area& area) const noexcept { lv_display_rotate_area(p_, area.ptr()); }

inline void Display::rotate_point(Point& point) const noexcept { lv_display_rotate_point(p_, point.ptr()); }

inline Result Display::send_vsync_event(void* param) const noexcept { return static_cast<Result>(lv_display_send_vsync_event(p_, param)); }

inline void Display::set_3rd_draw_buffer(DrawBuf buf3) const noexcept { lv_display_set_3rd_draw_buffer(p_, buf3.raw()); }

inline void Display::set_antialiasing(bool en) const noexcept { lv_display_set_antialiasing(p_, en); }

inline void Display::set_buffers(void* buf1, void* buf2, uint32_t buf_size, DisplayRenderMode render_mode) const noexcept { lv_display_set_buffers(p_, buf1, buf2, buf_size, static_cast<lv_display_render_mode_t>(render_mode)); }

inline void Display::set_buffers_with_stride(void* buf1, void* buf2, uint32_t buf_size, uint32_t stride, DisplayRenderMode render_mode) const noexcept { lv_display_set_buffers_with_stride(p_, buf1, buf2, buf_size, stride, static_cast<lv_display_render_mode_t>(render_mode)); }

inline void Display::set_color_format(ColorFormat color_format) const noexcept { lv_display_set_color_format(p_, static_cast<lv_color_format_t>(color_format)); }

inline void Display::set_default() const noexcept { lv_display_set_default(p_); }

inline void Display::set_dpi(int32_t dpi) const noexcept { lv_display_set_dpi(p_, dpi); }

inline void Display::set_draw_buffers(DrawBuf buf1, DrawBuf buf2) const noexcept { lv_display_set_draw_buffers(p_, buf1.raw(), buf2.raw()); }

inline void Display::set_driver_data(void* driver_data) const noexcept { lv_display_set_driver_data(p_, driver_data); }

#if LV_USE_EXT_DATA
inline void Display::set_external_data(void* data, void (*arg)(void*)) const noexcept { lv_display_set_external_data(p_, data, arg); }

template <auto Fn>
inline void Display::set_external_data(void* data) const noexcept { lv_display_set_external_data(p_, data, &detail::DisplaySetExternalDataThunk<Fn>::call); }
#endif // LV_USE_EXT_DATA

inline void Display::set_flush_cb(lv_display_flush_cb_t flush_cb) const noexcept { lv_display_set_flush_cb(p_, flush_cb); }

inline void Display::set_flush_wait_cb(lv_display_flush_wait_cb_t wait_cb) const noexcept { lv_display_set_flush_wait_cb(p_, wait_cb); }

inline void Display::set_matrix_rotation(bool enable) const noexcept { lv_display_set_matrix_rotation(p_, enable); }

inline void Display::set_offset(int32_t x, int32_t y) const noexcept { lv_display_set_offset(p_, x, y); }

inline void Display::set_physical_resolution(int32_t hor_res, int32_t ver_res) const noexcept { lv_display_set_physical_resolution(p_, hor_res, ver_res); }

inline void Display::set_render_mode(DisplayRenderMode render_mode) const noexcept { lv_display_set_render_mode(p_, static_cast<lv_display_render_mode_t>(render_mode)); }

inline void Display::set_resolution(int32_t hor_res, int32_t ver_res) const noexcept { lv_display_set_resolution(p_, hor_res, ver_res); }

inline void Display::set_rotation(DisplayRotation rotation) const noexcept { lv_display_set_rotation(p_, static_cast<lv_display_rotation_t>(rotation)); }

inline void Display::set_sync_cb(lv_display_sync_cb_t sync_cb) const noexcept { lv_display_set_sync_cb(p_, sync_cb); }

inline void Display::set_sync_wait_cb(lv_display_sync_wait_cb_t wait_cb) const noexcept { lv_display_set_sync_wait_cb(p_, wait_cb); }

inline void Display::set_theme(Theme th) const noexcept { lv_display_set_theme(p_, th.raw()); }

inline void Display::set_tile_cnt(uint32_t tile_cnt) const noexcept { lv_display_set_tile_cnt(p_, tile_cnt); }

inline void Display::set_user_data(void* user_data) const noexcept { lv_display_set_user_data(p_, user_data); }

inline bool Display::sync_is_last() const noexcept { return lv_display_sync_is_last(p_); }

inline void Display::sync_ready() const noexcept { lv_display_sync_ready(p_); }

inline void Display::trigger_activity() const noexcept { lv_display_trigger_activity(p_); }

inline bool Display::unregister_vsync_event(lv_event_cb_t event_cb, void* user_data) const noexcept { return lv_display_unregister_vsync_event(p_, event_cb, user_data); }

#if LVPP_COMPAT_V8
inline void Display::remove() const noexcept { return delete_(); }

inline int32_t Display::get_hor_res() const noexcept { return get_horizontal_resolution(); }

inline int32_t Display::get_ver_res() const noexcept { return get_vertical_resolution(); }

inline int32_t Display::get_physical_hor_res() const noexcept { return get_physical_horizontal_resolution(); }

inline int32_t Display::get_physical_ver_res() const noexcept { return get_physical_vertical_resolution(); }

inline Obj Display::get_scr_act() const noexcept { return get_screen_active(); }

inline Obj Display::get_scr_prev() const noexcept { return get_screen_prev(); }

inline void Display::trig_activity() const noexcept { return trigger_activity(); }
#endif // LVPP_COMPAT_V8

inline Display display_get_default() noexcept { return Display(lv_display_get_default()); }

inline void display_screen_load(Obj scr) noexcept { lv_screen_load(scr.raw()); }

inline void display_screen_load_anim(Obj scr, ScreenLoadAnim anim_type, uint32_t time, uint32_t delay, bool auto_del) noexcept { lv_screen_load_anim(scr.raw(), static_cast<lv_screen_load_anim_t>(anim_type), time, delay, auto_del); }

inline Obj display_screen_active() noexcept { return Obj(lv_screen_active()); }

inline Obj layer_top() noexcept { return Obj(lv_layer_top()); }

inline Obj layer_sys() noexcept { return Obj(lv_layer_sys()); }

inline Obj layer_bottom() noexcept { return Obj(lv_layer_bottom()); }

inline int32_t display_dpx(int32_t n) noexcept { return lv_dpx(n); }

} // namespace lv
