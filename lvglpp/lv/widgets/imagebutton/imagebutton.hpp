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

#if LV_USE_IMAGEBUTTON != 0
class Imagebutton : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_imagebutton_class; }

    enum class State : int {
        Released = LV_IMAGEBUTTON_STATE_RELEASED,
        Pressed = LV_IMAGEBUTTON_STATE_PRESSED,
        Disabled = LV_IMAGEBUTTON_STATE_DISABLED,
        CheckedReleased = LV_IMAGEBUTTON_STATE_CHECKED_RELEASED,
        CheckedPressed = LV_IMAGEBUTTON_STATE_CHECKED_PRESSED,
        CheckedDisabled = LV_IMAGEBUTTON_STATE_CHECKED_DISABLED,
        Num = LV_IMAGEBUTTON_STATE_NUM,
    };

    /**
     * Create an image button object
     * @param parent  pointer to an object, it will be the parent of the new image button
     * @return pointer to the created image button
     * @see lv_imagebutton_create
     */
    static Imagebutton create(Obj parent) noexcept { return Imagebutton(lv_imagebutton_create(parent.raw())); }
    /**
     * Get the left image in a given state
     * @param state  the state where to get the image (from `lv_button_state_t`) `
     * @return pointer to the left image source (a C array or path to a file)
     * @see lv_imagebutton_get_src_left
     */
    const void* get_src_left(Imagebutton::State state) const noexcept { return lv_imagebutton_get_src_left(p_, static_cast<lv_imagebutton_state_t>(state)); }
    /**
     * Get the middle image in a given state
     * @param state  the state where to get the image (from `lv_button_state_t`) `
     * @return pointer to the middle image source (a C array or path to a file)
     * @see lv_imagebutton_get_src_middle
     */
    const void* get_src_middle(Imagebutton::State state) const noexcept { return lv_imagebutton_get_src_middle(p_, static_cast<lv_imagebutton_state_t>(state)); }
    /**
     * Get the right image in a given state
     * @param state  the state where to get the image (from `lv_button_state_t`) `
     * @return pointer to the left image source (a C array or path to a file)
     * @see lv_imagebutton_get_src_right
     */
    const void* get_src_right(Imagebutton::State state) const noexcept { return lv_imagebutton_get_src_right(p_, static_cast<lv_imagebutton_state_t>(state)); }
    /**
     * Set images for a state of the image button
     * @param state  for which state set the new image
     * @param src_left  pointer to an image source for the left side of the button (a C array or path to a file)
     * @param src_mid  pointer to an image source for the middle of the button (ideally 1px wide) (a C array or path to a file)
     * @param src_right  pointer to an image source for the right side of the button (a C array or path to a file)
     * @see lv_imagebutton_set_src
     */
    void set_src(Imagebutton::State state, const void* src_left, const void* src_mid, const void* src_right) const noexcept { lv_imagebutton_set_src(p_, static_cast<lv_imagebutton_state_t>(state), src_left, src_mid, src_right); }
    /**
     * Set the left image for a state of the image button
     * @param state  for which state set the new image
     * @param src_left  pointer to an image source for the left side of the button (a C array or path to a file)
     * @see lv_imagebutton_set_src_left
     */
    void set_src_left(Imagebutton::State state, const void* src_left) const noexcept { lv_imagebutton_set_src_left(p_, static_cast<lv_imagebutton_state_t>(state), src_left); }
    /**
     * Set the middle image for a state of the image button
     * @param state  for which state set the new image
     * @param src_mid  pointer to an image source for the middle of the button (a C array or path to a file)
     * @see lv_imagebutton_set_src_mid
     */
    void set_src_mid(Imagebutton::State state, const void* src_mid) const noexcept { lv_imagebutton_set_src_mid(p_, static_cast<lv_imagebutton_state_t>(state), src_mid); }
    /**
     * Set the right image for a state of the image button
     * @param state  for which state set the new image
     * @param src_right  pointer to an image source for the right side of the button (a C array or path to a file)
     * @see lv_imagebutton_set_src_right
     */
    void set_src_right(Imagebutton::State state, const void* src_right) const noexcept { lv_imagebutton_set_src_right(p_, static_cast<lv_imagebutton_state_t>(state), src_right); }
    /**
     * Use this function instead of `lv_obj_add/remove_state` to set a state manually
     * @param state  the new state
     * @see lv_imagebutton_set_state
     */
    void set_state(Imagebutton::State state) const noexcept { lv_imagebutton_set_state(p_, static_cast<lv_imagebutton_state_t>(state)); }
    #if LVPP_COMPAT_V8
    /** v8 spelling of `create`. */
    static Imagebutton imgbtn_create(Obj parent) noexcept { return create(parent); }
    /** v8 spelling of `set_src`. */
    void imgbtn_set_src(Imagebutton::State state, const void* src_left, const void* src_mid, const void* src_right) const noexcept { return set_src(state, src_left, src_mid, src_right); }
    /** v8 spelling of `set_state`. */
    void imgbtn_set_state(Imagebutton::State state) const noexcept { return set_state(state); }
    /** v8 spelling of `get_src_left`. */
    const void* imgbtn_get_src_left(Imagebutton::State state) const noexcept { return get_src_left(state); }
    /** v8 spelling of `get_src_middle`. */
    const void* imgbtn_get_src_middle(Imagebutton::State state) const noexcept { return get_src_middle(state); }
    /** v8 spelling of `get_src_right`. */
    const void* imgbtn_get_src_right(Imagebutton::State state) const noexcept { return get_src_right(state); }
    #endif // LVPP_COMPAT_V8

};
static_assert(sizeof(Imagebutton) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Imagebutton));
#endif // LV_USE_IMAGEBUTTON != 0

} // namespace lv
