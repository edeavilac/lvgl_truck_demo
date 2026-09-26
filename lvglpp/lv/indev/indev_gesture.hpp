#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/indev/indev.hpp"
#include "lv/misc/event.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_GESTURE_RECOGNITION
/**
 * Initialize this indev's recognizers. It specifies their recognizer functions
 * @param indev  pointer to the indev containing the recognizers to initialize
 * @see lv_indev_gesture_init
 */
inline void indev_gesture_init(Indev indev) noexcept { lv_indev_gesture_init(indev.raw()); }

/**
 * Pinch gesture recognizer function
 * Will update the recognizer data
 * @param recognizer  pointer to a gesture recognizer
 * @param touches  pointer to the first element of the collected touch events
 * @param touch_cnt  length of passed touch event array.
 * @see lv_indev_gesture_detect_pinch
 */
inline void indev_gesture_detect_pinch(lv_indev_gesture_recognizer_t* recognizer, lv_indev_touch_data_t* touches, uint16_t touch_cnt) noexcept { lv_indev_gesture_detect_pinch(recognizer, touches, touch_cnt); }

/**
 * Rotation gesture recognizer function
 * Will update the recognizer data
 * @param recognizer  pointer to a gesture recognizer
 * @param touches  pointer to the first element of the collected touch events
 * @param touch_cnt  length of passed touch event array.
 * @see lv_indev_gesture_detect_rotation
 */
inline void indev_gesture_detect_rotation(lv_indev_gesture_recognizer_t* recognizer, lv_indev_touch_data_t* touches, uint16_t touch_cnt) noexcept { lv_indev_gesture_detect_rotation(recognizer, touches, touch_cnt); }

/**
 * Two finger swipe gesture recognizer function
 * Will update the recognizer data
 * @param recognizer  pointer to a gesture recognizer
 * @param touches  pointer to the first element of the collected touch events
 * @param touch_cnt  length of passed touch event array.
 * @see lv_indev_gesture_detect_two_fingers_swipe
 */
inline void indev_gesture_detect_two_fingers_swipe(lv_indev_gesture_recognizer_t* recognizer, lv_indev_touch_data_t* touches, uint16_t touch_cnt) noexcept { lv_indev_gesture_detect_two_fingers_swipe(recognizer, touches, touch_cnt); }

/**
 * Sets the state of the recognizer to a indev data structure,
 * it is usually called from the indev read callback
 * @param data  the indev data
 * @param recognizer  pointer to a gesture recognizer
 * @see lv_indev_set_gesture_data
 */
inline void indev_set_gesture_data(lv_indev_data_t* data, lv_indev_gesture_recognizer_t* recognizer, IndevGestureType type) noexcept { lv_indev_set_gesture_data(data, recognizer, static_cast<lv_indev_gesture_type_t>(type)); }

/**
 * Obtains the center point of a gesture
 * @return pointer to a point
 * @see lv_indev_get_gesture_center_point
 */
inline Point indev_get_gesture_center_point(lv_indev_gesture_recognizer_t* recognizer) noexcept {
    lv_point_t point_out{};
    lv_indev_get_gesture_center_point(recognizer, &point_out);
    return Point{point_out};
}

/**
 * Obtains the coordinates of the current primary point
 * @param recognizer  pointer to a gesture recognizer
 * @return pointer to a point
 * @see lv_indev_get_gesture_primary_point
 */
inline Point indev_get_gesture_primary_point(lv_indev_gesture_recognizer_t* recognizer) noexcept {
    lv_point_t point_out{};
    lv_indev_get_gesture_primary_point(recognizer, &point_out);
    return Point{point_out};
}

/**
 * Allows to determine if there is an are ongoing gesture
 * @param recognizer  pointer to a gesture recognizer
 * @return false if there are no contact points, or the gesture has ended - true otherwise
 * @see lv_indev_recognizer_is_active
 */
inline bool indev_recognizer_is_active(lv_indev_gesture_recognizer_t* recognizer) noexcept { return lv_indev_recognizer_is_active(recognizer); }

/**
 * Update the recognizers. It execute the recognizers functions and checks for
 * LV_GESTURE_STATE_RECOGNIZED or LV_GESTURE_STATE_ENDED gestures.
 * To be called in the indev read_cb.
 * @param indev  pointer to the indev containing from which the reconizer need an update
 * @param touches  indev touch data array, containing the last touch data from indev since the last recognizers update
 * @param touch_cnt  number of indev touch data in touches
 * @see lv_indev_gesture_recognizers_update
 */
inline void indev_gesture_recognizers_update(Indev indev, lv_indev_touch_data_t* touches, uint16_t touch_cnt) noexcept { lv_indev_gesture_recognizers_update(indev.raw(), touches, touch_cnt); }

/**
 * Set the lv_indev_data_t struct from the recognizer data.
 * To be called in the indev read_cb.
 * @see lv_indev_gesture_recognizers_set_data
 */
inline void indev_gesture_recognizers_set_data(Indev indev, lv_indev_data_t* data) noexcept { lv_indev_gesture_recognizers_set_data(indev.raw(), data); }
#endif // LV_USE_GESTURE_RECOGNITION

#if LV_USE_GESTURE_RECOGNITION
inline IndevGestureState Event::get_gesture_state(IndevGestureType type) const noexcept { return static_cast<IndevGestureState>(lv_event_get_gesture_state(p_, static_cast<lv_indev_gesture_type_t>(type))); }

inline IndevGestureType Event::get_gesture_type() const noexcept { return static_cast<IndevGestureType>(lv_event_get_gesture_type(p_)); }

inline float Event::get_pinch_scale() const noexcept { return lv_event_get_pinch_scale(p_); }

inline float Event::get_rotation() const noexcept { return lv_event_get_rotation(p_); }

inline Dir Event::get_two_fingers_swipe_dir() const noexcept { return static_cast<Dir>(lv_event_get_two_fingers_swipe_dir(p_)); }

inline float Event::get_two_fingers_swipe_distance() const noexcept { return lv_event_get_two_fingers_swipe_distance(p_); }

inline void Indev::set_pinch_down_threshold(float threshold) const noexcept { lv_indev_set_pinch_down_threshold(p_, threshold); }

inline void Indev::set_pinch_up_threshold(float threshold) const noexcept { lv_indev_set_pinch_up_threshold(p_, threshold); }

inline void Indev::set_rotation_rad_threshold(float threshold) const noexcept { lv_indev_set_rotation_rad_threshold(p_, threshold); }
#endif // LV_USE_GESTURE_RECOGNITION

} // namespace lv
