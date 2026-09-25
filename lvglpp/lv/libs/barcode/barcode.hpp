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

#if LV_USE_BARCODE
/** @see lv_barcode_class */
inline constexpr ObjClass barcode_class = ObjClass(const_cast<lv_obj_class_t*>(&lv_barcode_class));

/**
 * Create an empty barcode (an `lv_canvas`) object.
 * @param parent  point to an object where to create the barcode
 * @return pointer to the created barcode object
 * @see lv_barcode_create
 */
inline Obj barcode_create(Obj parent) noexcept { return Obj(lv_barcode_create(parent.raw())); }

/**
 * Set the dark color of a barcode object
 * @param obj  pointer to barcode object
 * @param color  dark color of the barcode
 * @see lv_barcode_set_dark_color
 */
inline void barcode_set_dark_color(Obj obj, Color color) noexcept { lv_barcode_set_dark_color(obj.raw(), color.raw()); }

/**
 * Set the light color of a barcode object
 * @param obj  pointer to barcode object
 * @param color  light color of the barcode
 * @see lv_barcode_set_light_color
 */
inline void barcode_set_light_color(Obj obj, Color color) noexcept { lv_barcode_set_light_color(obj.raw(), color.raw()); }

/**
 * Set the scale of a barcode object
 * @param obj  pointer to barcode object
 * @param scale  scale factor
 * @see lv_barcode_set_scale
 */
inline void barcode_set_scale(Obj obj, uint16_t scale) noexcept { lv_barcode_set_scale(obj.raw(), scale); }

/**
 * Set the direction of a barcode object
 * @param obj  pointer to barcode object
 * @param direction  draw direction (`LV_DIR_HOR` or `LB_DIR_VER`)
 * @see lv_barcode_set_direction
 */
inline void barcode_set_direction(Obj obj, Dir direction) noexcept { lv_barcode_set_direction(obj.raw(), static_cast<lv_dir_t>(direction)); }

/**
 * Set the tiled mode of a barcode object
 * @param obj  pointer to barcode object
 * @param tiled  true: tiled mode, false: normal mode (default)
 * @see lv_barcode_set_tiled
 */
inline void barcode_set_tiled(Obj obj, bool tiled) noexcept { lv_barcode_set_tiled(obj.raw(), tiled); }

/**
 * Set the encoding of a barcode object
 * @param obj  pointer to barcode object
 * @param encoding  encoding (default is `LV_BARCODE_CODE128_GS1`)
 * @see lv_barcode_set_encoding
 */
inline void barcode_set_encoding(Obj obj, BarcodeEncoding encoding) noexcept { lv_barcode_set_encoding(obj.raw(), static_cast<lv_barcode_encoding_t>(encoding)); }

/**
 * Set the data of a barcode object
 * @param obj  pointer to barcode object
 * @param data  data to display
 * @return LV_RESULT_OK: if no error; LV_RESULT_INVALID: on error
 * @see lv_barcode_update
 */
inline Result barcode_update(Obj obj, const char* data) noexcept { return static_cast<Result>(lv_barcode_update(obj.raw(), data)); }

/**
 * Get the dark color of a barcode object
 * @param obj  pointer to barcode object
 * @return dark color of the barcode
 * @see lv_barcode_get_dark_color
 */
inline Color barcode_get_dark_color(Obj obj) noexcept { return Color{lv_barcode_get_dark_color(obj.raw())}; }

/**
 * Get the light color of a barcode object
 * @param obj  pointer to barcode object
 * @return light color of the barcode
 * @see lv_barcode_get_light_color
 */
inline Color barcode_get_light_color(Obj obj) noexcept { return Color{lv_barcode_get_light_color(obj.raw())}; }

/**
 * Get the scale of a barcode object
 * @param obj  pointer to barcode object
 * @return scale factor
 * @see lv_barcode_get_scale
 */
inline uint16_t barcode_get_scale(Obj obj) noexcept { return lv_barcode_get_scale(obj.raw()); }

/**
 * Get the encoding of a barcode object
 * @param obj  pointer to barcode object
 * @return encoding
 * @see lv_barcode_get_encoding
 */
inline BarcodeEncoding barcode_get_encoding(Obj obj) noexcept { return static_cast<BarcodeEncoding>(lv_barcode_get_encoding(obj.raw())); }
#endif // LV_USE_BARCODE

} // namespace lv
