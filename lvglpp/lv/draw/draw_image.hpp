#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lv/widgets/image/image.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

/**
 * Create an image draw task
 * @param layer  pointer to a layer
 * @param dsc  pointer to an initialized draw descriptor
 * @param coords  the coordinates of the image
 * @see lv_draw_image
 */
inline void draw_image(Layer& layer, DrawImageDsc& dsc, const Area& coords) noexcept { lv_draw_image(layer.raw(), dsc.raw(), coords.ptr()); }

/**
 * Create a draw task to blend a layer to another layer
 * @param layer  pointer to a layer
 * @param dsc  pointer to an initialized draw descriptor. `src` must be set to the layer to blend
 * @param coords  the coordinates of the layer.
 * @see lv_draw_layer
 */
inline void draw_layer(Layer& layer, DrawImageDsc& dsc, const Area& coords) noexcept { lv_draw_layer(layer.raw(), dsc.raw(), coords.ptr()); }

/**
 * Get the type of an image source
 * @param src  pointer to an image source: - pointer to an 'lv_image_t' variable (image stored internally and compiled into the code) - a path to a file (e.g. "S:/folder/image.bin") - or a symbol (e.g. LV_SYMBOL_CLOSE)
 * @return type of the image source LV_IMAGE_SRC_VARIABLE/FILE/SYMBOL/UNKNOWN
 * @see lv_image_src_get_type
 */
inline Image::Src image_src_get_type(const void* src) noexcept { return static_cast<Image::Src>(lv_image_src_get_type(src)); }

inline lv_draw_image_dsc_t* DrawTask::get_image_dsc() const noexcept { return lv_draw_task_get_image_dsc(p_); }

} // namespace lv
