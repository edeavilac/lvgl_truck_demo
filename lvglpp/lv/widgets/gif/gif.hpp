#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core/obj.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_GIF
/** @see lv_gif_class */
inline constexpr ObjClass gif_class = ObjClass(const_cast<lv_obj_class_t*>(&lv_gif_class));

/**
 * Create a gif object
 * @param parent  pointer to an object, it will be the parent of the new gif.
 * @return pointer to the gif obj
 * @see lv_gif_create
 */
inline Obj gif_create(Obj parent) noexcept { return Obj(lv_gif_create(parent.raw())); }

/**
 * Set the color format of the internally allocated framebuffer that the gif
 * will be decoded to. The default is LV_COLOR_FORMAT_ARGB8888.
 * Call this before `lv_gif_set_src` to avoid reallocating the framebuffer.
 * @param obj  pointer to a gif object
 * @param color_format  the color format of the gif framebuffer
 * @see lv_gif_set_color_format
 */
inline void gif_set_color_format(Obj obj, ColorFormat color_format) noexcept { lv_gif_set_color_format(obj.raw(), static_cast<lv_color_format_t>(color_format)); }

/**
 * Set the gif data to display on the object
 * @param obj  pointer to a gif object
 * @param src  1) pointer to an ::lv_image_dsc_t descriptor (which contains gif raw data) or 2) path to a gif file (e.g. "S:/dir/anim.gif")
 * @see lv_gif_set_src
 */
inline void gif_set_src(Obj obj, const void* src) noexcept { lv_gif_set_src(obj.raw(), src); }

/**
 * Restart a gif animation.
 * @param obj  pointer to a gif obj
 * @see lv_gif_restart
 */
inline void gif_restart(Obj obj) noexcept { lv_gif_restart(obj.raw()); }

/**
 * Pause a gif animation.
 * @param obj  pointer to a gif obj
 * @see lv_gif_pause
 */
inline void gif_pause(Obj obj) noexcept { lv_gif_pause(obj.raw()); }

/**
 * Resume a gif animation.
 * @param obj  pointer to a gif obj
 * @see lv_gif_resume
 */
inline void gif_resume(Obj obj) noexcept { lv_gif_resume(obj.raw()); }

/**
 * Checks if the GIF was loaded correctly.
 * @param obj  pointer to a gif obj
 * @see lv_gif_is_loaded
 */
inline bool gif_is_loaded(Obj obj) noexcept { return lv_gif_is_loaded(obj.raw()); }

/**
 * Get the loop count for the GIF.
 * @param obj  pointer to a gif obj
 * @see lv_gif_get_loop_count
 */
inline int32_t gif_get_loop_count(Obj obj) noexcept { return lv_gif_get_loop_count(obj.raw()); }

/**
 * Set the loop count for the GIF.
 * @param obj  pointer to a gif obj
 * @param count  the loop count to set
 * @see lv_gif_set_loop_count
 */
inline void gif_set_loop_count(Obj obj, int32_t count) noexcept { lv_gif_set_loop_count(obj.raw(), count); }

/**
 * Set whether to decode invisible object.
 * @param obj  pointer to a gif object
 * @param auto_pause  true: auto pause when invisible, false: don't auto pause
 * @see lv_gif_set_auto_pause_invisible
 */
inline void gif_set_auto_pause_invisible(Obj obj, bool auto_pause) noexcept { lv_gif_set_auto_pause_invisible(obj.raw(), auto_pause); }

/**
 * Get gif width & height
 * @param src  pointer to a gif file
 * @param w  pointer to store width
 * @param h  pointer to store height
 * @return true: success; false: failed
 * @see lv_gif_get_size
 */
inline bool gif_get_size(const char* src, uint16_t* w, uint16_t* h) noexcept { return lv_gif_get_size(src, w, h); }

/**
 * Get frame count of the GIF.
 * @param obj  pointer to a gif object
 * @return frame count of the GIF
 * @see lv_gif_get_frame_count
 */
inline int32_t gif_get_frame_count(Obj obj) noexcept { return lv_gif_get_frame_count(obj.raw()); }

/**
 * Get the current frame index of the GIF.
 * @param obj  pointer to a gif object
 * @return current frame index of the GIF
 * @see lv_gif_get_current_frame_index
 */
inline int32_t gif_get_current_frame_index(Obj obj) noexcept { return lv_gif_get_current_frame_index(obj.raw()); }
#endif // LV_USE_GIF

} // namespace lv
