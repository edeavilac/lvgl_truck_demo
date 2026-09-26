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

#if LV_USE_RLOTTIE
/** @see lv_rlottie_class */
inline constexpr ObjClass rlottie_class = ObjClass(const_cast<lv_obj_class_t*>(&lv_rlottie_class));

/** @see lv_rlottie_create_from_file */
inline Obj rlottie_create_from_file(Obj parent, int32_t width, int32_t height, const char* path) noexcept { return Obj(lv_rlottie_create_from_file(parent.raw(), width, height, path)); }

/** @see lv_rlottie_create_from_raw */
inline Obj rlottie_create_from_raw(Obj parent, int32_t width, int32_t height, const char* rlottie_desc) noexcept { return Obj(lv_rlottie_create_from_raw(parent.raw(), width, height, rlottie_desc)); }

/** @see lv_rlottie_set_play_mode */
inline void rlottie_set_play_mode(Obj rlottie, RlottieCtrl ctrl) noexcept { lv_rlottie_set_play_mode(rlottie.raw(), static_cast<lv_rlottie_ctrl_t>(ctrl)); }

/** @see lv_rlottie_set_current_frame */
inline void rlottie_set_current_frame(Obj rlottie, const size_t goto_frame) noexcept { lv_rlottie_set_current_frame(rlottie.raw(), goto_frame); }
#endif // LV_USE_RLOTTIE

} // namespace lv
