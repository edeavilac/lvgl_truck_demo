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

#if LV_USE_QRCODE
/** @see lv_qrcode_class */
inline constexpr ObjClass qrcode_class = ObjClass(const_cast<lv_obj_class_t*>(&lv_qrcode_class));

/**
 * Create an empty QR code (an `lv_canvas`) object.
 * @param parent  point to an object where to create the QR code
 * @return pointer to the created QR code object
 * @see lv_qrcode_create
 */
inline Obj qrcode_create(Obj parent) noexcept { return Obj(lv_qrcode_create(parent.raw())); }

/**
 * Set QR code size.
 * @param obj  pointer to a QR code object
 * @param size  width and height of the QR code
 * @see lv_qrcode_set_size
 */
inline void qrcode_set_size(Obj obj, int32_t size) noexcept { lv_qrcode_set_size(obj.raw(), size); }

/**
 * Set QR code dark color.
 * @param obj  pointer to a QR code object
 * @param color  dark color of the QR code
 * @see lv_qrcode_set_dark_color
 */
inline void qrcode_set_dark_color(Obj obj, Color color) noexcept { lv_qrcode_set_dark_color(obj.raw(), color.raw()); }

/**
 * Set QR code light color.
 * @param obj  pointer to a QR code object
 * @param color  light color of the QR code
 * @see lv_qrcode_set_light_color
 */
inline void qrcode_set_light_color(Obj obj, Color color) noexcept { lv_qrcode_set_light_color(obj.raw(), color.raw()); }

/**
 * Set the data of a QR code object
 * @param obj  pointer to a QR code object
 * @param data  data to display
 * @param data_len  length of data in bytes
 * @return LV_RESULT_OK: if no error; LV_RESULT_INVALID: on error
 * @see lv_qrcode_update
 */
inline Result qrcode_update(Obj obj, const void* data, uint32_t data_len) noexcept { return static_cast<Result>(lv_qrcode_update(obj.raw(), data, data_len)); }

/**
 * Helper function to set the data of a QR code object
 * @param obj  pointer to a QR code object
 * @param data  data to display as a string
 * @see lv_qrcode_set_data
 */
inline void qrcode_set_data(Obj obj, const char* data) noexcept { lv_qrcode_set_data(obj.raw(), data); }

/**
 * Enable or disable quiet zone.
 * Quiet zone is the area around the QR code where no data is encoded.
 * @param obj  pointer to a QR code object
 * @param enable  true: enable quiet zone; false: disable quiet zone
 * @see lv_qrcode_set_quiet_zone
 */
inline void qrcode_set_quiet_zone(Obj obj, bool enable) noexcept { lv_qrcode_set_quiet_zone(obj.raw(), enable); }
#endif // LV_USE_QRCODE

} // namespace lv
