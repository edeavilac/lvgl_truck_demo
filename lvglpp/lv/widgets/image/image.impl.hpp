#pragma once
// Bodies of widgets/image/image.hpp, separated because its file cycle needs every type
// complete. Same mechanism as D-C7, applied where the graph asks for it.
// Included by the umbrella and never by a header: it is NOT a translation
// unit and every definition in it is `inline`. The stem says so, not the
// extension, so a glob written for *.hpp still installs it.

#include "lv/lvgl.hpp"

namespace lv {

#if (LV_USE_IMAGE != 0) && (LV_USE_OBSERVER)
inline Observer Image::bind_src(Subject& subject) const noexcept { return Observer(lv_image_bind_src(p_, subject.raw())); }
#endif // (LV_USE_IMAGE != 0) && (LV_USE_OBSERVER)

#if LV_USE_IMAGE != 0
inline Image Image::create(Obj parent) noexcept { return Image(lv_image_create(parent.raw())); }

inline bool Image::get_antialias() const noexcept { return lv_image_get_antialias(p_); }

inline const lv_image_dsc_t* Image::get_bitmap_map_src() const noexcept { return lv_image_get_bitmap_map_src(p_); }

inline BlendMode Image::get_blend_mode() const noexcept { return static_cast<BlendMode>(lv_image_get_blend_mode(p_)); }

inline Image::Align Image::get_inner_align() const noexcept { return static_cast<Image::Align>(lv_image_get_inner_align(p_)); }

inline int32_t Image::get_offset_x() const noexcept { return lv_image_get_offset_x(p_); }

inline int32_t Image::get_offset_y() const noexcept { return lv_image_get_offset_y(p_); }

inline Point Image::get_pivot() const noexcept {
    lv_point_t pivot_out{};
    lv_image_get_pivot(p_, &pivot_out);
    return Point{pivot_out};
}

inline int32_t Image::get_rotation() const noexcept { return lv_image_get_rotation(p_); }

inline int32_t Image::get_scale() const noexcept { return lv_image_get_scale(p_); }

inline int32_t Image::get_scale_x() const noexcept { return lv_image_get_scale_x(p_); }

inline int32_t Image::get_scale_y() const noexcept { return lv_image_get_scale_y(p_); }

inline const void* Image::get_src() const noexcept { return lv_image_get_src(p_); }

inline int32_t Image::get_src_height() const noexcept { return lv_image_get_src_height(p_); }

inline int32_t Image::get_src_width() const noexcept { return lv_image_get_src_width(p_); }

inline int32_t Image::get_transformed_height() const noexcept { return lv_image_get_transformed_height(p_); }

inline int32_t Image::get_transformed_width() const noexcept { return lv_image_get_transformed_width(p_); }

inline void Image::set_antialias(bool antialias) const noexcept { lv_image_set_antialias(p_, antialias); }

inline void Image::set_bitmap_map_src(const lv_image_dsc_t* src) const noexcept { lv_image_set_bitmap_map_src(p_, src); }

inline void Image::set_blend_mode(BlendMode blend_mode) const noexcept { lv_image_set_blend_mode(p_, static_cast<lv_blend_mode_t>(blend_mode)); }

inline void Image::set_inner_align(Image::Align align) const noexcept { lv_image_set_inner_align(p_, static_cast<lv_image_align_t>(align)); }

inline void Image::set_offset_x(int32_t x) const noexcept { lv_image_set_offset_x(p_, x); }

inline void Image::set_offset_y(int32_t y) const noexcept { lv_image_set_offset_y(p_, y); }

inline void Image::set_pivot(int32_t x, int32_t y) const noexcept { lv_image_set_pivot(p_, x, y); }

inline void Image::set_pivot_x(int32_t x) const noexcept { lv_image_set_pivot_x(p_, x); }

inline void Image::set_pivot_y(int32_t y) const noexcept { lv_image_set_pivot_y(p_, y); }

inline void Image::set_rotation(int32_t angle) const noexcept { lv_image_set_rotation(p_, angle); }

inline void Image::set_scale(uint32_t zoom) const noexcept { lv_image_set_scale(p_, zoom); }

inline void Image::set_scale_x(uint32_t zoom) const noexcept { lv_image_set_scale_x(p_, zoom); }

inline void Image::set_scale_y(uint32_t zoom) const noexcept { lv_image_set_scale_y(p_, zoom); }

inline void Image::set_src(const void* src) const noexcept { lv_image_set_src(p_, src); }
#endif // LV_USE_IMAGE != 0

#if (LV_USE_IMAGE != 0) && (LVPP_COMPAT_V8)
inline Image Image::img_create(Obj parent) noexcept { return create(parent); }

inline void Image::img_set_src(const void* src) const noexcept { return set_src(src); }

inline void Image::img_set_offset_x(int32_t x) const noexcept { return set_offset_x(x); }

inline void Image::img_set_offset_y(int32_t y) const noexcept { return set_offset_y(y); }

inline void Image::img_set_angle(int32_t angle) const noexcept { return set_rotation(angle); }

inline void Image::img_set_pivot(int32_t x, int32_t y) const noexcept { return set_pivot(x, y); }

inline void Image::img_set_zoom(uint32_t zoom) const noexcept { return set_scale(zoom); }

inline void Image::img_set_antialias(bool antialias) const noexcept { return set_antialias(antialias); }

inline const void* Image::img_get_src() const noexcept { return get_src(); }

inline int32_t Image::img_get_offset_x() const noexcept { return get_offset_x(); }

inline int32_t Image::img_get_offset_y() const noexcept { return get_offset_y(); }

inline int32_t Image::img_get_angle() const noexcept { return get_rotation(); }

inline Point Image::img_get_pivot() const noexcept { return get_pivot(); }

inline int32_t Image::img_get_zoom() const noexcept { return get_scale(); }

inline bool Image::img_get_antialias() const noexcept { return get_antialias(); }
#endif // (LV_USE_IMAGE != 0) && (LVPP_COMPAT_V8)

} // namespace lv
