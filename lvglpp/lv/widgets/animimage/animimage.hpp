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

#if (LV_USE_ANIMIMG) && (LV_USE_ANIMIMG != 0) && (LV_USE_IMAGE != 0)
inline Animimg Animimg::create(Obj parent) noexcept { return Animimg(lv_animimg_create(parent.raw())); }

inline bool Animimg::delete_() const noexcept { return lv_animimg_delete(p_); }

inline lv_anim_t* Animimg::get_anim() const noexcept { return lv_animimg_get_anim(p_); }

inline uint32_t Animimg::get_duration() const noexcept { return lv_animimg_get_duration(p_); }

inline uint32_t Animimg::get_repeat_count() const noexcept { return lv_animimg_get_repeat_count(p_); }

inline const void** Animimg::get_src() const noexcept { return lv_animimg_get_src(p_); }

inline uint8_t Animimg::get_src_count() const noexcept { return lv_animimg_get_src_count(p_); }

inline void Animimg::set_completed_cb(lv_anim_completed_cb_t completed_cb) const noexcept { lv_animimg_set_completed_cb(p_, completed_cb); }

inline void Animimg::set_duration(uint32_t duration) const noexcept { lv_animimg_set_duration(p_, duration); }

inline void Animimg::set_repeat_count(uint32_t count) const noexcept { lv_animimg_set_repeat_count(p_, count); }

inline void Animimg::set_reverse_delay(uint32_t duration) const noexcept { lv_animimg_set_reverse_delay(p_, duration); }

inline void Animimg::set_reverse_duration(uint32_t duration) const noexcept { lv_animimg_set_reverse_duration(p_, duration); }

inline void Animimg::set_src(const void** dsc, size_t num) const noexcept { lv_animimg_set_src(p_, dsc, num); }

inline void Animimg::set_src_reverse(const void** dsc, size_t num) const noexcept { lv_animimg_set_src_reverse(p_, dsc, num); }

inline void Animimg::set_start_cb(lv_anim_start_cb_t start_cb) const noexcept { lv_animimg_set_start_cb(p_, start_cb); }

inline void Animimg::start() const noexcept { lv_animimg_start(p_); }
#endif // (LV_USE_ANIMIMG) && (LV_USE_ANIMIMG != 0) && (LV_USE_IMAGE != 0)

} // namespace lv
