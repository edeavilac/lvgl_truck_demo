#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/indev/indev.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_TEST && LV_USE_GESTURE_RECOGNITION
/**
 * Create a touch (pointer) indevs.
 * They can be controlled via function calls during the test
 * @see lv_test_indev_gesture_create
 */
inline void test_indev_gesture_create() noexcept { lv_test_indev_gesture_create(); }

/**
 * Delete the touch (pointer) indevs.
 * @see lv_test_indev_gesture_delete
 */
inline void test_indev_gesture_delete() noexcept { lv_test_indev_gesture_delete(); }

/**
 * Get one of the indev created in `lv_test_indev_gesture_create`
 * @param type  type of the indev to get
 * @return the indev
 * @see lv_test_indev_get_gesture_indev
 */
inline Indev test_indev_get_gesture_indev(IndevType type) noexcept { return Indev(lv_test_indev_get_gesture_indev(static_cast<lv_indev_type_t>(type))); }

/**
 * Set two touch points data for pinch gesture
 * @param point_0  First touch point coordinates
 * @param point_1  Second touch point coordinates
 * @see lv_test_gesture_set_pinch_data
 */
inline void test_gesture_set_pinch_data(Point point_0, Point point_1) noexcept { lv_test_gesture_set_pinch_data(point_0.raw(), point_1.raw()); }

/**
 * Trigger press state of pinch gesture (both touch points pressed)
 * @see lv_test_gesture_pinch_press
 */
inline void test_gesture_pinch_press() noexcept { lv_test_gesture_pinch_press(); }

/**
 * Trigger release state of pinch gesture (both touch points released)
 * @see lv_test_gesture_pinch_release
 */
inline void test_gesture_pinch_release() noexcept { lv_test_gesture_pinch_release(); }

/**
 * Simulate a complete pinch gesture operation
 * @param point_begin_0  Starting coordinates of first touch point
 * @param point_begin_1  Starting coordinates of second touch point
 * @param point_end_0  Ending coordinates of first touch point
 * @param point_end_1  Ending coordinates of second touch point
 * @see lv_test_gesture_pinch
 */
inline void test_gesture_pinch(Point point_begin_0, Point point_begin_1, Point point_end_0, Point point_end_1) noexcept { lv_test_gesture_pinch(point_begin_0.raw(), point_begin_1.raw(), point_end_0.raw(), point_end_1.raw()); }
#endif // LV_USE_TEST && LV_USE_GESTURE_RECOGNITION

} // namespace lv
