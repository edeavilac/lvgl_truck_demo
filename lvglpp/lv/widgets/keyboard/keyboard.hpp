#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core/obj.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/misc/event.hpp"
#include "lv/types.hpp"
#include "lv/widgets/buttonmatrix/buttonmatrix.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if (LV_USE_KEYBOARD) && (LV_USE_BUTTONMATRIX != 0)
class Keyboard : public Buttonmatrix {
public:
    using Buttonmatrix::Buttonmatrix;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_keyboard_class; }

    /** Current keyboard mode. */
    enum class Mode : int {
        TextLower = LV_KEYBOARD_MODE_TEXT_LOWER,
        TextUpper = LV_KEYBOARD_MODE_TEXT_UPPER,
        Special = LV_KEYBOARD_MODE_SPECIAL,
        Number = LV_KEYBOARD_MODE_NUMBER,
        User1 = LV_KEYBOARD_MODE_USER_1,
        User2 = LV_KEYBOARD_MODE_USER_2,
        User3 = LV_KEYBOARD_MODE_USER_3,
        User4 = LV_KEYBOARD_MODE_USER_4,
        #if LV_USE_ARABIC_PERSIAN_CHARS == 1
        TextArabic = LV_KEYBOARD_MODE_TEXT_ARABIC,
        #endif // LV_USE_ARABIC_PERSIAN_CHARS == 1

    };

    /**
     * Create a Keyboard object
     * @param parent  pointer to an object, it will be the parent of the new keyboard
     * @return pointer to the created keyboard object
     * @see lv_keyboard_create
     */
    static Keyboard create(Obj parent) noexcept { return Keyboard(lv_keyboard_create(parent.raw())); }
    /**
     * Get the text of a button by index.
     * @param btn_id  index of the button (excluding newline characters)
     * @return pointer to the text of the button
     * @see lv_keyboard_get_button_text
     */
    const char* get_button_text(uint32_t btn_id) const noexcept { return lv_keyboard_get_button_text(p_, btn_id); }
    /**
     * Get the current button map of the keyboard.
     * @return pointer to the map array
     * @see lv_keyboard_get_map_array
     */
    const char* const* get_map_array() const noexcept { return lv_keyboard_get_map_array(p_); }
    /**
     * Get the current mode of the keyboard.
     * @return the current mode (see 'lv_keyboard_mode_t')
     * @see lv_keyboard_get_mode
     */
    Keyboard::Mode get_mode() const noexcept { return static_cast<Keyboard::Mode>(lv_keyboard_get_mode(p_)); }
    /**
     * Check whether popovers are enabled on the keyboard.
     * @return true if popovers are enabled; false otherwise
     * @see lv_keyboard_get_popovers
     */
    bool get_popovers() const noexcept { return lv_keyboard_get_popovers(p_); }
    /**
     * Get the index of the last selected button (pressed, released, focused, etc.).
     * Useful in the `event_cb` to retrieve button text or properties.
     * @return index of the last interacted button returns LV_BUTTONMATRIX_BUTTON_NONE if not set
     * @see lv_keyboard_get_selected_button
     */
    uint32_t get_selected_button() const noexcept { return lv_keyboard_get_selected_button(p_); }
    /**
     * Get the text area currently assigned to the keyboard.
     * @return pointer to the assigned text area object
     * @see lv_keyboard_get_textarea
     */
    Obj get_textarea() const noexcept { return Obj(lv_keyboard_get_textarea(p_)); }
    /**
     * Set a custom button map for the keyboard.
     * @param mode  the mode to assign the new map to (see 'lv_keyboard_mode_t')
     * @param map  pointer to a string array describing the button map see 'lv_buttonmatrix_set_map()' for more details
     * @param ctrl_map  pointer to the control map. See 'lv_buttonmatrix_set_ctrl_map()'
     * @see lv_keyboard_set_map
     */
    void set_map(Keyboard::Mode mode, const char* const* map, const lv_buttonmatrix_ctrl_t* ctrl_map) const noexcept { lv_keyboard_set_map(p_, static_cast<lv_keyboard_mode_t>(mode), map, ctrl_map); }
    /**
     * Set a new mode (e.g., text, number, special characters).
     * @param mode  the desired mode (see 'lv_keyboard_mode_t')
     * @see lv_keyboard_set_mode
     */
    void set_mode(Keyboard::Mode mode) const noexcept { lv_keyboard_set_mode(p_, static_cast<lv_keyboard_mode_t>(mode)); }
    /**
     * Enable or disable popovers showing button titles on press.
     * @param en  true to enable popovers; false to disable
     * @see lv_keyboard_set_popovers
     */
    void set_popovers(bool en) const noexcept { lv_keyboard_set_popovers(p_, en); }
    /**
     * Assign a text area to the keyboard. Pressed characters will be inserted there.
     * @param ta  pointer to a text area object to write into
     * @see lv_keyboard_set_textarea
     */
    void set_textarea(Obj ta) const noexcept { lv_keyboard_set_textarea(p_, ta.raw()); }
    #if LVPP_COMPAT_V8
    /** v8 spelling of `get_selected_button`. */
    uint32_t get_selected_btn() const noexcept { return get_selected_button(); }
    /** v8 spelling of `get_button_text`. */
    const char* get_btn_text(uint32_t btn_id) const noexcept { return get_button_text(btn_id); }
    #endif // LVPP_COMPAT_V8

};
static_assert(sizeof(Keyboard) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Keyboard));
#endif // (LV_USE_KEYBOARD) && (LV_USE_BUTTONMATRIX != 0)

#if LV_USE_KEYBOARD
/**
 * Default keyboard event callback to handle button presses.
 * Adds characters to the text area and switches map if needed.
 * If a custom `event_cb` is used, this function can be called within it.
 * @param e  the triggering event
 * @see lv_keyboard_def_event_cb
 */
inline void keyboard_def_event_cb(Event& e) noexcept { lv_keyboard_def_event_cb(e.raw()); }
#endif // LV_USE_KEYBOARD

} // namespace lv
