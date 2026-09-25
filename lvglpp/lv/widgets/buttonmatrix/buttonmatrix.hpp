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

#if LV_USE_BUTTONMATRIX != 0
class Buttonmatrix : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_buttonmatrix_class; }

    /**
     * Type to store button control flags (disabled, hidden etc.)
     * The least-significant 4 bits are used to store button-width proportions in range [1..15].
     */
    enum class Ctrl : int {
        /** No extra control, use the default settings */
        None = LV_BUTTONMATRIX_CTRL_NONE,
        /** Set the width to 1 relative to the other buttons in the same row */
        Width1 = LV_BUTTONMATRIX_CTRL_WIDTH_1,
        /** Set the width to 2 relative to the other buttons in the same row */
        Width2 = LV_BUTTONMATRIX_CTRL_WIDTH_2,
        /** Set the width to 3 relative to the other buttons in the same row */
        Width3 = LV_BUTTONMATRIX_CTRL_WIDTH_3,
        /** Set the width to 4 relative to the other buttons in the same row */
        Width4 = LV_BUTTONMATRIX_CTRL_WIDTH_4,
        /** Set the width to 5 relative to the other buttons in the same row */
        Width5 = LV_BUTTONMATRIX_CTRL_WIDTH_5,
        /** Set the width to 6 relative to the other buttons in the same row */
        Width6 = LV_BUTTONMATRIX_CTRL_WIDTH_6,
        /** Set the width to 7 relative to the other buttons in the same row */
        Width7 = LV_BUTTONMATRIX_CTRL_WIDTH_7,
        /** Set the width to 8 relative to the other buttons in the same row */
        Width8 = LV_BUTTONMATRIX_CTRL_WIDTH_8,
        /** Set the width to 9 relative to the other buttons in the same row */
        Width9 = LV_BUTTONMATRIX_CTRL_WIDTH_9,
        /** Set the width to 10 relative to the other buttons in the same row */
        Width10 = LV_BUTTONMATRIX_CTRL_WIDTH_10,
        /** Set the width to 11 relative to the other buttons in the same row */
        Width11 = LV_BUTTONMATRIX_CTRL_WIDTH_11,
        /** Set the width to 12 relative to the other buttons in the same row */
        Width12 = LV_BUTTONMATRIX_CTRL_WIDTH_12,
        /** Set the width to 13 relative to the other buttons in the same row */
        Width13 = LV_BUTTONMATRIX_CTRL_WIDTH_13,
        /** Set the width to 14 relative to the other buttons in the same row */
        Width14 = LV_BUTTONMATRIX_CTRL_WIDTH_14,
        /** Set the width to 15 relative to the other buttons in the same row */
        Width15 = LV_BUTTONMATRIX_CTRL_WIDTH_15,
        /** Hides button; it continues to hold its space in layout. */
        Hidden = LV_BUTTONMATRIX_CTRL_HIDDEN,
        /** Do not emit LV_EVENT_LONG_PRESSED_REPEAT events while button is long-pressed. */
        NoRepeat = LV_BUTTONMATRIX_CTRL_NO_REPEAT,
        /** Disables button like LV_STATE_DISABLED on normal Widgets. */
        Disabled = LV_BUTTONMATRIX_CTRL_DISABLED,
        /** Enable toggling of LV_STATE_CHECKED when clicked. */
        Checkable = LV_BUTTONMATRIX_CTRL_CHECKABLE,
        /** Make the button checked. It will use the :cpp:enumerator:`LV_STATE_CHECHKED` styles. */
        Checked = LV_BUTTONMATRIX_CTRL_CHECKED,
        /** 1: Enables sending LV_EVENT_VALUE_CHANGE on CLICK, 0: sends LV_EVENT_VALUE_CHANGE on PRESS. */
        ClickTrig = LV_BUTTONMATRIX_CTRL_CLICK_TRIG,
        /** Show button text in a pop-over while being pressed. */
        Popover = LV_BUTTONMATRIX_CTRL_POPOVER,
        /** Enable text recoloring with `#color` */
        Recolor = LV_BUTTONMATRIX_CTRL_RECOLOR,
        /** Reserved for later use */
        Reserved1 = LV_BUTTONMATRIX_CTRL_RESERVED_1,
        /** Reserved for later use */
        Reserved2 = LV_BUTTONMATRIX_CTRL_RESERVED_2,
        /** Custom free-to-use flag */
        Custom1 = LV_BUTTONMATRIX_CTRL_CUSTOM_1,
        /** Custom free-to-use flag */
        Custom2 = LV_BUTTONMATRIX_CTRL_CUSTOM_2,
    };
    friend constexpr Ctrl operator|(Ctrl a, Ctrl b) noexcept {
        return static_cast<Ctrl>(static_cast<int>(a) | static_cast<int>(b));
    }
    friend constexpr Ctrl operator&(Ctrl a, Ctrl b) noexcept {
        return static_cast<Ctrl>(static_cast<int>(a) & static_cast<int>(b));
    }
    friend constexpr Ctrl operator^(Ctrl a, Ctrl b) noexcept {
        return static_cast<Ctrl>(static_cast<int>(a) ^ static_cast<int>(b));
    }
    friend constexpr Ctrl& operator|=(Ctrl& a, Ctrl b) noexcept { a = a | b; return a; }

    /**
     * Clear the attributes of a button of the button matrix
     * @param btn_id  0 based index of the button to modify. (Not counting new lines)
     * @param ctrl  OR-ed attributes. E.g. `LV_BUTTONMATRIX_CTRL_NO_REPEAT | LV_BUTTONMATRIX_CTRL_CHECKABLE`
     * @see lv_buttonmatrix_clear_button_ctrl
     */
    void clear_button_ctrl(uint32_t btn_id, Buttonmatrix::Ctrl ctrl) const noexcept { lv_buttonmatrix_clear_button_ctrl(p_, btn_id, static_cast<lv_buttonmatrix_ctrl_t>(ctrl)); }
    /**
     * Clear the attributes of all buttons of a button matrix
     * @param ctrl  attribute(s) to set from `lv_buttonmatrix_ctrl_t`. Values can be ORed.
     * @see lv_buttonmatrix_clear_button_ctrl_all
     */
    void clear_button_ctrl_all(Buttonmatrix::Ctrl ctrl) const noexcept { lv_buttonmatrix_clear_button_ctrl_all(p_, static_cast<lv_buttonmatrix_ctrl_t>(ctrl)); }
    /**
     * Create a button matrix object
     * @param parent  pointer to an object, it will be the parent of the new button matrix
     * @return pointer to the created button matrix
     * @see lv_buttonmatrix_create
     */
    static Buttonmatrix create(Obj parent) noexcept { return Buttonmatrix(lv_buttonmatrix_create(parent.raw())); }
    /**
     * Get the button's text
     * @param btn_id  the index a button not counting new line characters.
     * @return text of btn_index` button
     * @see lv_buttonmatrix_get_button_text
     */
    const char* get_button_text(uint32_t btn_id) const noexcept { return lv_buttonmatrix_get_button_text(p_, btn_id); }
    /**
     * Get the current map of a button matrix
     * @return the current map
     * @see lv_buttonmatrix_get_map
     */
    const char* const* get_map() const noexcept { return lv_buttonmatrix_get_map(p_); }
    /**
     * Tell whether "one check" mode is enabled or not.
     * @return true: "one check" mode is enabled; false: disabled
     * @see lv_buttonmatrix_get_one_checked
     */
    bool get_one_checked() const noexcept { return lv_buttonmatrix_get_one_checked(p_); }
    /**
     * Get the index of the lastly "activated" button by the user (pressed, released, focused etc)
     * Useful in the `event_cb` to get the text of the button, check if hidden etc.
     * @return index of the last released button (LV_BUTTONMATRIX_BUTTON_NONE: if unset)
     * @see lv_buttonmatrix_get_selected_button
     */
    uint32_t get_selected_button() const noexcept { return lv_buttonmatrix_get_selected_button(p_); }
    /**
     * Get the whether a control value is enabled or disabled for button of a button matrix
     * @param btn_id  the index of a button not counting new line characters.
     * @param ctrl  control values to check (ORed value can be used)
     * @return true: the control attribute is enabled false: disabled
     * @see lv_buttonmatrix_has_button_ctrl
     */
    bool has_button_ctrl(uint32_t btn_id, Buttonmatrix::Ctrl ctrl) const noexcept { return lv_buttonmatrix_has_button_ctrl(p_, btn_id, static_cast<lv_buttonmatrix_ctrl_t>(ctrl)); }
    /**
     * Set the attributes of a button of the button matrix
     * @param btn_id  0 based index of the button to modify. (Not counting new lines)
     * @param ctrl  OR-ed attributes. E.g. `LV_BUTTONMATRIX_CTRL_NO_REPEAT | LV_BUTTONMATRIX_CTRL_CHECKABLE`
     * @see lv_buttonmatrix_set_button_ctrl
     */
    void set_button_ctrl(uint32_t btn_id, Buttonmatrix::Ctrl ctrl) const noexcept { lv_buttonmatrix_set_button_ctrl(p_, btn_id, static_cast<lv_buttonmatrix_ctrl_t>(ctrl)); }
    /**
     * Set attributes of all buttons of a button matrix
     * @param ctrl  attribute(s) to set from `lv_buttonmatrix_ctrl_t`. Values can be ORed.
     * @see lv_buttonmatrix_set_button_ctrl_all
     */
    void set_button_ctrl_all(Buttonmatrix::Ctrl ctrl) const noexcept { lv_buttonmatrix_set_button_ctrl_all(p_, static_cast<lv_buttonmatrix_ctrl_t>(ctrl)); }
    /**
     * Set a single button's relative width.
     * This method will cause the matrix be regenerated and is a relatively
     * expensive operation. It is recommended that initial width be specified using
     * `lv_buttonmatrix_set_ctrl_map` and this method only be used for dynamic changes.
     * @param btn_id  0 based index of the button to modify.
     * @param width  relative width compared to the buttons in the same row. [1..15]
     * @see lv_buttonmatrix_set_button_width
     */
    void set_button_width(uint32_t btn_id, uint32_t width) const noexcept { lv_buttonmatrix_set_button_width(p_, btn_id, width); }
    /**
     * Set the button control map (hidden, disabled etc.) for a button matrix.
     * The control map array will be copied and so may be deallocated after this
     * function returns.
     * @param ctrl_map  pointer to an array of `lv_button_ctrl_t` control bytes. The length of the array and position of the elements must match the number and order of the individual buttons (i.e. excludes newline entries). An element of the map should look like e.g.: `ctrl_map[0] = width | LV_BUTTONMATRIX_CTRL_NO_REPEAT | LV_BUTTONMATRIX_CTRL_TGL_ENABLE`
     * @see lv_buttonmatrix_set_ctrl_map
     */
    void set_ctrl_map(const lv_buttonmatrix_ctrl_t* ctrl_map) const noexcept { lv_buttonmatrix_set_ctrl_map(p_, ctrl_map); }
    /**
     * Set a new map. Buttons will be created/deleted according to the map. The
     * button matrix keeps a reference to the map and so the string array must not
     * be deallocated during the life of the matrix.
     * @param map  pointer a string array. The last string has to be: "". Use "\n" to make a line break.
     * @see lv_buttonmatrix_set_map
     */
    void set_map(const char* const* map) const noexcept { lv_buttonmatrix_set_map(p_, map); }
    /**
     * Make the button matrix like a selector widget (only one button may be checked at a time).
     * `LV_BUTTONMATRIX_CTRL_CHECKABLE` must be enabled on the buttons to be selected using
     * `lv_buttonmatrix_set_ctrl()` or `lv_buttonmatrix_set_button_ctrl_all()`.
     * @param en  whether "one check" mode is enabled
     * @see lv_buttonmatrix_set_one_checked
     */
    void set_one_checked(bool en) const noexcept { lv_buttonmatrix_set_one_checked(p_, en); }
    /**
     * Set the selected buttons
     * @param btn_id  0 based index of the button to modify. (Not counting new lines)
     * @see lv_buttonmatrix_set_selected_button
     */
    void set_selected_button(uint32_t btn_id) const noexcept { lv_buttonmatrix_set_selected_button(p_, btn_id); }
    #if LVPP_COMPAT_V8
    /** v8 spelling of `create`. */
    static Buttonmatrix btnmatrix_create(Obj parent) noexcept { return create(parent); }
    /** v8 spelling of `set_map`. */
    void btnmatrix_set_map(const char* const* map) const noexcept { return set_map(map); }
    /** v8 spelling of `set_ctrl_map`. */
    void btnmatrix_set_ctrl_map(const lv_buttonmatrix_ctrl_t* ctrl_map) const noexcept { return set_ctrl_map(ctrl_map); }
    /** v8 spelling of `set_selected_button`. */
    void btnmatrix_set_selected_btn(uint32_t btn_id) const noexcept { return set_selected_button(btn_id); }
    /** v8 spelling of `set_button_ctrl`. */
    void btnmatrix_set_btn_ctrl(uint32_t btn_id, Buttonmatrix::Ctrl ctrl) const noexcept { return set_button_ctrl(btn_id, ctrl); }
    /** v8 spelling of `clear_button_ctrl`. */
    void btnmatrix_clear_btn_ctrl(uint32_t btn_id, Buttonmatrix::Ctrl ctrl) const noexcept { return clear_button_ctrl(btn_id, ctrl); }
    /** v8 spelling of `set_button_ctrl_all`. */
    void btnmatrix_set_btn_ctrl_all(Buttonmatrix::Ctrl ctrl) const noexcept { return set_button_ctrl_all(ctrl); }
    /** v8 spelling of `clear_button_ctrl_all`. */
    void btnmatrix_clear_btn_ctrl_all(Buttonmatrix::Ctrl ctrl) const noexcept { return clear_button_ctrl_all(ctrl); }
    /** v8 spelling of `set_button_width`. */
    void btnmatrix_set_btn_width(uint32_t btn_id, uint32_t width) const noexcept { return set_button_width(btn_id, width); }
    /** v8 spelling of `set_one_checked`. */
    void btnmatrix_set_one_checked(bool en) const noexcept { return set_one_checked(en); }
    /** v8 spelling of `get_map`. */
    const char* const* btnmatrix_get_map() const noexcept { return get_map(); }
    /** v8 spelling of `get_selected_button`. */
    uint32_t btnmatrix_get_selected_btn() const noexcept { return get_selected_button(); }
    /** v8 spelling of `get_button_text`. */
    const char* btnmatrix_get_btn_text(uint32_t btn_id) const noexcept { return get_button_text(btn_id); }
    /** v8 spelling of `has_button_ctrl`. */
    bool btnmatrix_has_button_ctrl(uint32_t btn_id, Buttonmatrix::Ctrl ctrl) const noexcept { return has_button_ctrl(btn_id, ctrl); }
    /** v8 spelling of `get_one_checked`. */
    bool btnmatrix_get_one_checked() const noexcept { return get_one_checked(); }
    #endif // LVPP_COMPAT_V8

};
static_assert(sizeof(Buttonmatrix) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Buttonmatrix));
#endif // LV_USE_BUTTONMATRIX != 0

} // namespace lv
