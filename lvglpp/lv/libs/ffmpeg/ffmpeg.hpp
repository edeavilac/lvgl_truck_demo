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

#if LV_USE_FFMPEG != 0
/** @see lv_ffmpeg_player_class */
inline constexpr ObjClass ffmpeg_player_class = ObjClass(const_cast<lv_obj_class_t*>(&lv_ffmpeg_player_class));

/**
 * Register FFMPEG image decoder
 * @see lv_ffmpeg_init
 */
inline void ffmpeg_init() noexcept { lv_ffmpeg_init(); }

/**
 * De-initialize FFMPEG image decoder
 * @see lv_ffmpeg_deinit
 */
inline void ffmpeg_deinit() noexcept { lv_ffmpeg_deinit(); }

/**
 * Get the number of frames contained in the file
 * @param path  image or video file name
 * @return Number of frames, less than 0 means failed
 * @see lv_ffmpeg_get_frame_num
 */
inline int32_t ffmpeg_get_frame_num(const char* path) noexcept { return lv_ffmpeg_get_frame_num(path); }

/**
 * Create ffmpeg_player object
 * @param parent  pointer to an object, it will be the parent of the new player
 * @return pointer to the created ffmpeg_player
 * @see lv_ffmpeg_player_create
 */
inline Obj ffmpeg_player_create(Obj parent) noexcept { return Obj(lv_ffmpeg_player_create(parent.raw())); }

/**
 * Set the path of the file to be played.
 * @param obj  pointer to a ffmpeg_player object
 * @param path  video file path
 * @return LV_RESULT_OK: no error; LV_RESULT_INVALID: can't get the info.
 * @see lv_ffmpeg_player_set_src
 */
inline Result ffmpeg_player_set_src(Obj obj, const char* path) noexcept { return static_cast<Result>(lv_ffmpeg_player_set_src(obj.raw(), path)); }

/**
 * Set command control video player
 * @param obj  pointer to a ffmpeg_player object
 * @param cmd  control commands
 * @see lv_ffmpeg_player_set_cmd
 */
inline void ffmpeg_player_set_cmd(Obj obj, FfmpegPlayerCmd cmd) noexcept { lv_ffmpeg_player_set_cmd(obj.raw(), static_cast<lv_ffmpeg_player_cmd_t>(cmd)); }

/**
 * Set the video to automatically replay
 * @param obj  pointer to a ffmpeg_player object
 * @param en  true: enable the auto restart
 * @see lv_ffmpeg_player_set_auto_restart
 */
inline void ffmpeg_player_set_auto_restart(Obj obj, bool en) noexcept { lv_ffmpeg_player_set_auto_restart(obj.raw(), en); }

/**
 * Set the video decoder
 * @param obj  pointer to a ffmpeg_player object
 * @param decoder_name  decoder name
 * @see lv_ffmpeg_player_set_decoder
 */
inline void ffmpeg_player_set_decoder(Obj obj, const char* decoder_name) noexcept { lv_ffmpeg_player_set_decoder(obj.raw(), decoder_name); }
#endif // LV_USE_FFMPEG != 0

} // namespace lv
