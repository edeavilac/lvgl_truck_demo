#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core/obj.hpp"
#include "lv/display/display.hpp"
#include "lv/draw/image_decoder.hpp"
#include "lv/enums.hpp"
#include "lv/font/font.hpp"
#include "lv/fwd.hpp"
#include "lv/indev/indev.hpp"
#include "lv/misc/anim.hpp"
#include "lv/misc/timer.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LVPP_COMPAT_V8
/** @see lv_task_handler */
inline uint32_t task_handler() noexcept { return lv_task_handler(); }

// The names of the previous version, offered by this one.
//
// The gate is OFF by default, unlike LVGL's own map, which lvgl.h includes
// unconditionally. That default is the point: an always-on map lets a binding
// mis-emitted with the old vocabulary compile clean.
//
// Nothing here names a C symbol -- every forwarder goes through the C++ API --
// so the layer survives the library dropping its own map. And the alias IS the
// type: `__is_same(lv::Disp, lv::Display)` holds, so there is no second
// hierarchy and `void f(Display&)` takes a `Disp`.
using Disp = Display;
using DispRenderMode = DisplayRenderMode;
using DispRotation = DisplayRotation;
using Res = Result;

/** v8 spelling of `indev_active`. */
inline Indev indev_get_act() noexcept { return indev_active(); }
/** v8 spelling of `display_screen_active`. */
inline Obj scr_act() noexcept { return display_screen_active(); }
/** v8 spelling of `display_get_default`. */
inline Display disp_get_default() noexcept { return display_get_default(); }
/** v8 spelling of `display_screen_load`. */
inline void disp_load_scr(Obj scr) noexcept { display_screen_load(scr); }
/** v8 spelling of `display_screen_load`. */
inline void scr_load(Obj scr) noexcept { display_screen_load(scr); }
/** v8 spelling of `display_screen_load_anim`. */
inline void scr_load_anim(Obj scr, ScreenLoadAnim anim_type, uint32_t time, uint32_t delay, bool auto_del) noexcept { display_screen_load_anim(scr, anim_type, time, delay, auto_del); }
/** v8 spelling of `display_refr_timer`. */
inline void disp_refr_timer(Timer timer) noexcept { display_refr_timer(timer); }
/** v8 spelling of `anim_delete`. */
inline bool anim_del(void* var, lv_anim_exec_xcb_t exec_cb) noexcept { return anim_delete(var, exec_cb); }
/** v8 spelling of `anim_delete_all`. */
inline void anim_del_all() noexcept { anim_delete_all(); }
/** v8 spelling of `text_get_size`. */
inline void txt_get_size(Point& size_res, const char* text, Font font, int32_t letter_space, int32_t line_space, int32_t max_width, TextFlag flag) noexcept { text_get_size(size_res, text, font, letter_space, line_space, max_width, flag); }
/** v8 spelling of `obj_delete_anim_completed_cb`. */
inline void obj_delete_anim_ready_cb(Anim& a) noexcept { obj_delete_anim_completed_cb(a); }
/** v8 spelling of `bin_decoder_open`. */
inline Result image_decoder_built_in_open(ImageDecoder decoder, lv_image_decoder_dsc_t* dsc) noexcept { return bin_decoder_open(decoder, dsc); }
/** v8 spelling of `bin_decoder_close`. */
inline void image_decoder_built_in_close(ImageDecoder decoder, lv_image_decoder_dsc_t* dsc) noexcept { bin_decoder_close(decoder, dsc); }
#endif // LVPP_COMPAT_V8

#if LVPP_COMPAT_V8
inline void Obj::move_background() const noexcept { lv_obj_move_background(p_); }

inline void Obj::move_foreground() const noexcept { lv_obj_move_foreground(p_); }
#endif // LVPP_COMPAT_V8

} // namespace lv
