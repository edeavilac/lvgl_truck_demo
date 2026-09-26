#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/misc/event.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

class Indev : public detail::EventAliases<Indev, detail::IndevTarget> {
protected:
    lv_indev_t* p_ = nullptr;

public:
    constexpr Indev() noexcept = default;  /**< the "no object" handle */
    constexpr explicit Indev(lv_indev_t* p) noexcept : p_(p) {}

    constexpr lv_indev_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(Indev a, Indev b) noexcept { return a.p_ == b.p_; }

    /**
     * Create an indev
     * @return Pointer to the created indev or NULL when allocation failed
     * @see lv_indev_create
     */
    static Indev create() noexcept;
    /**
     * Remove the provided input device. Make sure not to use the provided input device afterwards anymore.
     * @see lv_indev_delete
     */
    void delete_() const noexcept;
    /**
     * Enable or disable one or all input devices (default enabled)
     * @param enable  true to enable, false to disable
     * @see lv_indev_enable
     */
    void enable(bool enable) const noexcept;
    /**
     * Get the cursor object of an input device (for LV_INDEV_TYPE_POINTER only)
     * @return pointer to the cursor object
     * @see lv_indev_get_cursor
     */
    Obj get_cursor() const noexcept;
    /**
     * Get a pointer to the assigned display of the indev
     * @return pointer to the assigned display or NULL if indev is NULL
     * @see lv_indev_get_display
     */
    Display get_display() const noexcept;
    /**
     * Get a pointer to the driver data of the indev
     * @return pointer to the driver data or NULL if indev is NULL
     * @see lv_indev_get_driver_data
     */
    void* get_driver_data() const noexcept;
    /**
     * Get the number of event attached to an indev
     * @return number of events
     * @see lv_indev_get_event_count
     */
    uint32_t get_event_count() const noexcept;
    /**
     * Get an event descriptor for an event
     * @param index  the index of the event
     * @return the event descriptor
     * @see lv_indev_get_event_dsc
     */
    EventDsc get_event_dsc(uint32_t index) const noexcept;
    /**
     * Get the current gesture direct
     * @return current gesture direct
     * @see lv_indev_get_gesture_dir
     */
    Dir get_gesture_dir() const noexcept;
    /**
     * Get the indev assigned group
     * @return Pointer to indev assigned group or NULL if indev is NULL
     * @see lv_indev_get_group
     */
    Group get_group() const noexcept;
    /**
     * Get the last pressed key of an input device (for LV_INDEV_TYPE_KEYPAD)
     * @return the last pressed key (0 on error)
     * @see lv_indev_get_key
     */
    uint32_t get_key() const noexcept;
    /**
     * Get the input device's running mode.
     * @return the running mode for the specified input device.
     * @see lv_indev_get_mode
     */
    IndevMode get_mode() const noexcept;
    /**
     * Get the next input device.
     * @return the next input device or NULL if there are no more. Provide the first input device when the parameter is NULL
     * @see lv_indev_get_next
     */
    Indev get_next() const noexcept;
    /**
     * Get the last point of an input device (for LV_INDEV_TYPE_POINTER and LV_INDEV_TYPE_BUTTON)
     * @return pointer to a point to store the result
     * @see lv_indev_get_point
     */
    Point get_point() const noexcept;
    /**
     * Get whether indev is moved while pressed
     * @return true: indev is moved while pressed; false: indev is not moved while pressed
     * @see lv_indev_get_press_moved
     */
    bool get_press_moved() const noexcept;
    /**
     * Get the callback function to read input device data to the indev
     * @return Pointer to callback function to read input device data or NULL if indev is NULL
     * @see lv_indev_get_read_cb
     */
    lv_indev_read_cb_t get_read_cb() const noexcept;
    /**
     * Get a pointer to the indev read timer to
     * modify its parameters with `lv_timer_...` functions.
     * @return pointer to the indev read refresher timer. (NULL on error)
     * @see lv_indev_get_read_timer
     */
    Timer get_read_timer() const noexcept;
    /**
     * Check the current scroll direction of an input device (for LV_INDEV_TYPE_POINTER and
     * LV_INDEV_TYPE_BUTTON)
     * @return LV_DIR_NONE: no scrolling now LV_DIR_HOR/VER
     * @see lv_indev_get_scroll_dir
     */
    Dir get_scroll_dir() const noexcept;
    /**
     * Get the currently scrolled object (for LV_INDEV_TYPE_POINTER and
     * LV_INDEV_TYPE_BUTTON)
     * @return pointer to the currently scrolled object or NULL if no scrolling by this indev
     * @see lv_indev_get_scroll_obj
     */
    Obj get_scroll_obj() const noexcept;
    /**
     * Get the counter for consecutive clicks within a short distance and time.
     * The counter is updated before LV_EVENT_SHORT_CLICKED is fired.
     * @return short click streak counter
     * @see lv_indev_get_short_click_streak
     */
    uint8_t get_short_click_streak() const noexcept;
    /**
     * Get the indev state
     * @return Indev state or LV_INDEV_STATE_RELEASED if indev is NULL
     * @see lv_indev_get_state
     */
    IndevState get_state() const noexcept;
    /**
     * Get the type of an input device
     * @return the type of the input device from `lv_hal_indev_type_t` (`LV_INDEV_TYPE_...`)
     * @see lv_indev_get_type
     */
    IndevType get_type() const noexcept;
    /**
     * Get a pointer to the user data of the indev
     * @return pointer to the user data or NULL if indev is NULL
     * @see lv_indev_get_user_data
     */
    void* get_user_data() const noexcept;
    /**
     * Get the movement vector of an input device (for LV_INDEV_TYPE_POINTER and
     * LV_INDEV_TYPE_BUTTON)
     * @return pointer to a point to store the types.pointer.vector
     * @see lv_indev_get_vect
     */
    Point get_vect() const noexcept;
    /**
     * Read data from an input device.
     * @see lv_indev_read
     */
    void read() const noexcept;
    /**
     * Remove an event
     * @param index  the index of the event to remove
     * @return true: and event was removed; false: no event was removed
     * @see lv_indev_remove_event
     */
    bool remove_event(uint32_t index) const noexcept;
    /**
     * Remove an event_cb with user_data
     * @param event_cb  the event_cb of the event to remove
     * @param user_data  user_data
     * @return the count of the event removed
     * @see lv_indev_remove_event_cb_with_user_data
     */
    uint32_t remove_event_cb_with_user_data(lv_event_cb_t event_cb, void* user_data) const noexcept;
    /**
     * Reset one or all input devices
     * @param obj  pointer to an object which triggers the reset.
     * @see lv_indev_reset
     */
    void reset(Obj obj) const noexcept;
    /**
     * Reset the long press state of an input device
     * @see lv_indev_reset_long_press
     */
    void reset_long_press() const noexcept;
    /**
     * Set the an array of points for LV_INDEV_TYPE_BUTTON.
     * These points will be assigned to the buttons to press a specific point on the screen
     * @param points  array of points
     * @see lv_indev_set_button_points
     */
    void set_button_points(const Point& points) const noexcept;
    /**
     * Set a cursor for a pointer input device (for LV_INPUT_TYPE_POINTER and LV_INPUT_TYPE_BUTTON)
     * @param cur_obj  pointer to an object to be used as cursor
     * @see lv_indev_set_cursor
     */
    void set_cursor(Obj cur_obj) const noexcept;
    /**
     * Assign a display to the indev
     * @param disp  pointer to an display
     * @see lv_indev_set_display
     */
    void set_display(struct _lv_display_t* disp) const noexcept;
    /**
     * Set driver data to the indev
     * @param driver_data  pointer to driver data
     * @see lv_indev_set_driver_data
     */
    void set_driver_data(void* driver_data) const noexcept;
    #if LV_USE_EXT_DATA
    /**
     * Attaches external user data and destructor callback to an indev
     * Associates custom user data with an LVGL indev and specifies a destructor function
     * that will be automatically invoked when the indev is deleted to properly clean up
     * the associated resources.
     * @param data  User-defined data pointer to associate with the indev
     * @see lv_indev_set_external_data
     */
    void set_external_data(void* data, void (*arg)(void*)) const noexcept;
    /**
     * Takes the function itself as a template argument, so its real parameter types survive: the C idiom CASTS the pointer, which is undefined whenever they differ, and between the versions they do.
     * Attaches external user data and destructor callback to an indev
     * Associates custom user data with an LVGL indev and specifies a destructor function
     * that will be automatically invoked when the indev is deleted to properly clean up
     * the associated resources.
     * @param data  User-defined data pointer to associate with the indev
     * @see lv_indev_set_external_data
     */
    template <auto Fn>
    void set_external_data(void* data) const noexcept;
    #endif // LV_USE_EXT_DATA

    /**
     * Set the minimum distance threshold for gesture detection.
     * The total distance from the first point to the current point must exceed
     * this value (in pixels) for the movement to be considered large enough
     * to trigger a gesture.
     * @param min_distance  minimum distance threshold in pixels (default: 50)
     * @see lv_indev_set_gesture_min_distance
     */
    void set_gesture_min_distance(uint8_t min_distance) const noexcept;
    /**
     * Set the minimum velocity threshold for gesture detection.
     * The difference between consecutive points must exceed this value (in pixels)
     * for the movement to be considered fast enough to trigger a gesture.
     * @param min_velocity  minimum velocity threshold in pixels (default: 3)
     * @see lv_indev_set_gesture_min_velocity
     */
    void set_gesture_min_velocity(uint8_t min_velocity) const noexcept;
    /**
     * Set a destination group for a keypad input device (for LV_INDEV_TYPE_KEYPAD)
     * @param group  pointer to a group
     * @see lv_indev_set_group
     */
    void set_group(Group group) const noexcept;
    /**
     * Set key remapping callback (LV_INDEV_TYPE_KEYPAD)
     * @param remap_cb  remapping function callback. Use NULL to disable callback.
     * @see lv_indev_set_key_remap_cb
     */
    void set_key_remap_cb(lv_indev_key_remap_cb_t remap_cb) const noexcept;
    /**
     * Set long press repeat time to indev
     * @param long_press_repeat_time  long press repeat time in ms
     * @see lv_indev_set_long_press_repeat_time
     */
    void set_long_press_repeat_time(uint16_t long_press_repeat_time) const noexcept;
    /**
     * Set long press time to indev
     * @param long_press_time  time long press time in ms
     * @see lv_indev_set_long_press_time
     */
    void set_long_press_time(uint16_t long_press_time) const noexcept;
    /**
     * Set the input device's event model: event-driven mode or timer mode.
     * @param mode  the mode of input device
     * @see lv_indev_set_mode
     */
    void set_mode(IndevMode mode) const noexcept;
    #if LV_USE_GESTURE_RECOGNITION
    /**
     * Set the threshold for the pinch gesture scale down, when the scale factor of gesture
     * reaches the threshold events get sent
     * @param threshold  threshold for a pinch down gesture to be recognized
     * @see lv_indev_set_pinch_down_threshold
     */
    void set_pinch_down_threshold(float threshold) const noexcept;
    /**
     * Set the threshold for the pinch gesture scale up, when the scale factor of gesture
     * reaches the threshold events get sent
     * @param threshold  threshold for a pinch up gesture to be recognized
     * @see lv_indev_set_pinch_up_threshold
     */
    void set_pinch_up_threshold(float threshold) const noexcept;
    #endif // LV_USE_GESTURE_RECOGNITION

    /**
     * Set a callback function to read input device data to the indev
     * @param read_cb  pointer to callback function to read input device data
     * @see lv_indev_set_read_cb
     */
    void set_read_cb(lv_indev_read_cb_t read_cb) const noexcept;
    #if LV_USE_GESTURE_RECOGNITION
    /**
     * Set the rotation threshold in radian for the rotation gesture
     * @param threshold  threshold in radian for a rotation gesture to be recognized
     * @see lv_indev_set_rotation_rad_threshold
     */
    void set_rotation_rad_threshold(float threshold) const noexcept;
    #endif // LV_USE_GESTURE_RECOGNITION

    /**
     * Set scroll limit to the input device
     * @param scroll_limit  the number of pixels to slide before actually drag the object
     * @see lv_indev_set_scroll_limit
     */
    void set_scroll_limit(uint8_t scroll_limit) const noexcept;
    /**
     * Set scroll throw slow-down to the indev. Greater value means faster slow-down
     * @param scroll_throw  the slow-down in [%]
     * @see lv_indev_set_scroll_throw
     */
    void set_scroll_throw(uint8_t scroll_throw) const noexcept;
    /**
     * Set the type of an input device
     * @param indev_type  the type of the input device from `lv_indev_type_t` (`LV_INDEV_TYPE_...`)
     * @see lv_indev_set_type
     */
    void set_type(IndevType indev_type) const noexcept;
    /**
     * Set user data to the indev
     * @param user_data  pointer to user data
     * @see lv_indev_set_user_data
     */
    void set_user_data(void* user_data) const noexcept;
    /**
     * Touch and key related events are sent to the input device first and to the widget after that.
     * If this functions called in an indev event, the event won't be sent to the widget.
     * @see lv_indev_stop_processing
     */
    void stop_processing() const noexcept;
    /**
     * Do nothing until the next release
     * @see lv_indev_wait_release
     */
    void wait_release() const noexcept;
    #if LVPP_COMPAT_V8
    /** v8 spelling of `set_display`. */
    void set_disp(struct _lv_display_t* disp) const noexcept;
    #endif // LVPP_COMPAT_V8

};
static_assert(sizeof(Indev) == sizeof(lv_indev_t*));
static_assert(__is_trivially_copyable(Indev));

/**
 * Called periodically to read the input devices
 * @param timer  pointer to a timer to read
 * @see lv_indev_read_timer_cb
 */
inline void indev_read_timer_cb(Timer timer) noexcept;

/**
 * Get the currently processed input device. Can be used in action functions too.
 * @return pointer to the currently processed input device or NULL if no input device processing right now
 * @see lv_indev_active
 */
inline Indev indev_active() noexcept;

/**
 * Gets a pointer to the currently active object in the currently processed input device.
 * @return pointer to currently active object or NULL if no active object
 * @see lv_indev_get_active_obj
 */
inline Obj indev_get_active_obj() noexcept;

/**
 * Search the most top, clickable object by a point
 * @param obj  pointer to a start object, typically the screen
 * @param point  pointer to a point for searching the most top child
 * @return pointer to the found object or NULL if there was no suitable object
 * @see lv_indev_search_obj
 */
inline Obj indev_search_obj(Obj obj, Point& point) noexcept;

} // namespace lv
