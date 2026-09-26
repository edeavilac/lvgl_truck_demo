#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core/obj.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/indev/indev.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_TEST
/**
 * Create a mouse (pointer), keypad, and encoder indevs.
 * They can be controlled via function calls during the test
 * @see lv_test_indev_create_all
 */
inline void test_indev_create_all() noexcept { lv_test_indev_create_all(); }

/**
 * Delete all test input devices
 * @see lv_test_indev_delete_all
 */
inline void test_indev_delete_all() noexcept { lv_test_indev_delete_all(); }

/**
 * Get one of the indev created in `lv_test_indev_create_all`
 * @param type  type of the indev to get
 * @return the indev
 * @see lv_test_indev_get_indev
 */
inline Indev test_indev_get_indev(IndevType type) noexcept { return Indev(lv_test_indev_get_indev(static_cast<lv_indev_type_t>(type))); }

/**
 * Move the mouse to the given coordinates.
 * This function doesn't wait, but just changes the state and returns immediately.
 * @param x  the target absolute X coordinate
 * @param y  the target absolute Y coordinate
 * @see lv_test_mouse_move_to
 */
inline void test_mouse_move_to(int32_t x, int32_t y) noexcept { lv_test_mouse_move_to(x, y); }

/**
 * Move the mouse to the center of a widget
 * This function doesn't wait, but just changes the state and returns immediately.
 * @param obj  pointer to an widget
 * @see lv_test_mouse_move_to_obj
 */
inline void test_mouse_move_to_obj(Obj obj) noexcept { lv_test_mouse_move_to_obj(obj.raw()); }

/**
 * Move the mouse cursor. Keep the pressed or released state
 * This function doesn't wait, but just changes the state and returns immediately.
 * @param x  the difference in X to move
 * @param y  the difference in Y to move
 * @see lv_test_mouse_move_by
 */
inline void test_mouse_move_by(int32_t x, int32_t y) noexcept { lv_test_mouse_move_by(x, y); }

/**
 * Make the mouse button pressed.
 * This function doesn't wait, but just changes the state and returns immediately.
 * @see lv_test_mouse_press
 */
inline void test_mouse_press() noexcept { lv_test_mouse_press(); }

/**
 * Make the mouse button released.
 * This function doesn't wait, but just changes the state and returns immediately.
 * @see lv_test_mouse_release
 */
inline void test_mouse_release() noexcept { lv_test_mouse_release(); }

/**
 * Emulate a click on a given point.
 * First set the released state, wait a little, press, wait, and release again.
 * The wait time is 50ms.
 * Internally `lv_timer_handler` is called, meaning all the events will be fired inside this function.
 * @param x  the target absolute X coordinate
 * @param y  the target absolute Y coordinate
 * @see lv_test_mouse_click_at
 */
inline void test_mouse_click_at(int32_t x, int32_t y) noexcept { lv_test_mouse_click_at(x, y); }

/**
 * Emulate a key press.
 * This function doesn't wait, but just changes the state and returns immediately.
 * @param k  the key to press
 * @see lv_test_key_press
 */
inline void test_key_press(uint32_t k) noexcept { lv_test_key_press(k); }

/**
 * Release the previously press key.
 * This function doesn't wait, but just changes the state and returns immediately.
 * @see lv_test_key_release
 */
inline void test_key_release() noexcept { lv_test_key_release(); }

/**
 * Emulate a key hit.
 * First set the released state, wait a little, press, wait, and release again.
 * The wait time is 50ms.
 * Internally `lv_timer_handler` is called, meaning all the events will be fired inside this function.
 * @param k  the key to hit
 * @see lv_test_key_hit
 */
inline void test_key_hit(uint32_t k) noexcept { lv_test_key_hit(k); }

/**
 * Emulate encoder rotation, use positive parameter to rotate to the right
 * and negative to rotate to the left.
 * This function doesn't wait, but just changes the state and returns immediately.
 * @param d  number of encoder ticks to emulate
 * @see lv_test_encoder_add_diff
 */
inline void test_encoder_add_diff(int32_t d) noexcept { lv_test_encoder_add_diff(d); }

/**
 * Emulate an encoder turn a wait 50ms. Use positive parameter to rotate to the right
 * and negative to rotate to the left.
 * Internally `lv_timer_handler` is called, meaning all the events will be fired inside this function.
 * @param d  number of encoder ticks to emulate
 * @see lv_test_encoder_turn
 */
inline void test_encoder_turn(int32_t d) noexcept { lv_test_encoder_turn(d); }

/**
 * Emulate an encoder press.
 * This function doesn't wait, but just changes the state and returns immediately.
 * @see lv_test_encoder_press
 */
inline void test_encoder_press() noexcept { lv_test_encoder_press(); }

/**
 * Emulate an encoder release.
 * This function doesn't wait, but just changes the state and returns immediately.
 * @see lv_test_encoder_release
 */
inline void test_encoder_release() noexcept { lv_test_encoder_release(); }

/**
 * Emulate am encoder click.
 * First set the released state, wait a little, press, wait, and release again.
 * The wait time is 50ms.
 * Internally `lv_timer_handler` is called, meaning all the events will be fired inside this function.
 * @see lv_test_encoder_click
 */
inline void test_encoder_click() noexcept { lv_test_encoder_click(); }
#endif // LV_USE_TEST

} // namespace lv
