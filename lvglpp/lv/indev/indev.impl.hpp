#pragma once
// Bodies of indev/indev.hpp, separated because its file cycle needs every type
// complete. Same mechanism as D-C7, applied where the graph asks for it.
// Included by the umbrella and never by a header: it is NOT a translation
// unit and every definition in it is `inline`. The stem says so, not the
// extension, so a glob written for *.hpp still installs it.

#include "lv/lvgl.hpp"

namespace lv {

inline Indev Indev::create() noexcept { return Indev(lv_indev_create()); }

inline void Indev::delete_() const noexcept { lv_indev_delete(p_); }

inline void Indev::enable(bool enable) const noexcept { lv_indev_enable(p_, enable); }

inline Obj Indev::get_cursor() const noexcept { return Obj(lv_indev_get_cursor(p_)); }

inline Display Indev::get_display() const noexcept { return Display(lv_indev_get_display(p_)); }

inline void* Indev::get_driver_data() const noexcept { return lv_indev_get_driver_data(p_); }

inline uint32_t Indev::get_event_count() const noexcept { return lv_indev_get_event_count(p_); }

inline EventDsc Indev::get_event_dsc(uint32_t index) const noexcept { return EventDsc(lv_indev_get_event_dsc(p_, index)); }

inline Dir Indev::get_gesture_dir() const noexcept { return static_cast<Dir>(lv_indev_get_gesture_dir(p_)); }

inline Group Indev::get_group() const noexcept { return Group(lv_indev_get_group(p_)); }

inline uint32_t Indev::get_key() const noexcept { return lv_indev_get_key(p_); }

inline IndevMode Indev::get_mode() const noexcept { return static_cast<IndevMode>(lv_indev_get_mode(p_)); }

inline Indev Indev::get_next() const noexcept { return Indev(lv_indev_get_next(p_)); }

inline Point Indev::get_point() const noexcept {
    lv_point_t point_out{};
    lv_indev_get_point(p_, &point_out);
    return Point{point_out};
}

inline bool Indev::get_press_moved() const noexcept { return lv_indev_get_press_moved(p_); }

inline lv_indev_read_cb_t Indev::get_read_cb() const noexcept { return lv_indev_get_read_cb(p_); }

inline Timer Indev::get_read_timer() const noexcept { return Timer(lv_indev_get_read_timer(p_)); }

inline Dir Indev::get_scroll_dir() const noexcept { return static_cast<Dir>(lv_indev_get_scroll_dir(p_)); }

inline Obj Indev::get_scroll_obj() const noexcept { return Obj(lv_indev_get_scroll_obj(p_)); }

inline uint8_t Indev::get_short_click_streak() const noexcept { return lv_indev_get_short_click_streak(p_); }

inline IndevState Indev::get_state() const noexcept { return static_cast<IndevState>(lv_indev_get_state(p_)); }

inline IndevType Indev::get_type() const noexcept { return static_cast<IndevType>(lv_indev_get_type(p_)); }

inline void* Indev::get_user_data() const noexcept { return lv_indev_get_user_data(p_); }

inline Point Indev::get_vect() const noexcept {
    lv_point_t point_out{};
    lv_indev_get_vect(p_, &point_out);
    return Point{point_out};
}

inline void Indev::read() const noexcept { lv_indev_read(p_); }

inline bool Indev::remove_event(uint32_t index) const noexcept { return lv_indev_remove_event(p_, index); }

inline uint32_t Indev::remove_event_cb_with_user_data(lv_event_cb_t event_cb, void* user_data) const noexcept { return lv_indev_remove_event_cb_with_user_data(p_, event_cb, user_data); }

inline void Indev::reset(Obj obj) const noexcept { lv_indev_reset(p_, obj.raw()); }

inline void Indev::reset_long_press() const noexcept { lv_indev_reset_long_press(p_); }

inline void Indev::set_button_points(const Point& points) const noexcept { lv_indev_set_button_points(p_, points.ptr()); }

inline void Indev::set_cursor(Obj cur_obj) const noexcept { lv_indev_set_cursor(p_, cur_obj.raw()); }

inline void Indev::set_display(struct _lv_display_t* disp) const noexcept { lv_indev_set_display(p_, disp); }

inline void Indev::set_driver_data(void* driver_data) const noexcept { lv_indev_set_driver_data(p_, driver_data); }

#if LV_USE_EXT_DATA
inline void Indev::set_external_data(void* data, void (*arg)(void*)) const noexcept { lv_indev_set_external_data(p_, data, arg); }

template <auto Fn>
inline void Indev::set_external_data(void* data) const noexcept { lv_indev_set_external_data(p_, data, &detail::IndevSetExternalDataThunk<Fn>::call); }
#endif // LV_USE_EXT_DATA

inline void Indev::set_gesture_min_distance(uint8_t min_distance) const noexcept { lv_indev_set_gesture_min_distance(p_, min_distance); }

inline void Indev::set_gesture_min_velocity(uint8_t min_velocity) const noexcept { lv_indev_set_gesture_min_velocity(p_, min_velocity); }

inline void Indev::set_group(Group group) const noexcept { lv_indev_set_group(p_, group.raw()); }

inline void Indev::set_key_remap_cb(lv_indev_key_remap_cb_t remap_cb) const noexcept { lv_indev_set_key_remap_cb(p_, remap_cb); }

inline void Indev::set_long_press_repeat_time(uint16_t long_press_repeat_time) const noexcept { lv_indev_set_long_press_repeat_time(p_, long_press_repeat_time); }

inline void Indev::set_long_press_time(uint16_t long_press_time) const noexcept { lv_indev_set_long_press_time(p_, long_press_time); }

inline void Indev::set_mode(IndevMode mode) const noexcept { lv_indev_set_mode(p_, static_cast<lv_indev_mode_t>(mode)); }

inline void Indev::set_read_cb(lv_indev_read_cb_t read_cb) const noexcept { lv_indev_set_read_cb(p_, read_cb); }

inline void Indev::set_scroll_limit(uint8_t scroll_limit) const noexcept { lv_indev_set_scroll_limit(p_, scroll_limit); }

inline void Indev::set_scroll_throw(uint8_t scroll_throw) const noexcept { lv_indev_set_scroll_throw(p_, scroll_throw); }

inline void Indev::set_type(IndevType indev_type) const noexcept { lv_indev_set_type(p_, static_cast<lv_indev_type_t>(indev_type)); }

inline void Indev::set_user_data(void* user_data) const noexcept { lv_indev_set_user_data(p_, user_data); }

inline void Indev::stop_processing() const noexcept { lv_indev_stop_processing(p_); }

inline void Indev::wait_release() const noexcept { lv_indev_wait_release(p_); }

#if LVPP_COMPAT_V8
inline void Indev::set_disp(struct _lv_display_t* disp) const noexcept { return set_display(disp); }
#endif // LVPP_COMPAT_V8

inline void indev_read_timer_cb(Timer timer) noexcept { lv_indev_read_timer_cb(timer.raw()); }

inline Indev indev_active() noexcept { return Indev(lv_indev_active()); }

inline Obj indev_get_active_obj() noexcept { return Obj(lv_indev_get_active_obj()); }

inline Obj indev_search_obj(Obj obj, Point& point) noexcept { return Obj(lv_indev_search_obj(obj.raw(), point.ptr())); }

} // namespace lv
