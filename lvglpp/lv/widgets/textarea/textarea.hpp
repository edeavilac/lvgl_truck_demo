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

#if LV_USE_TEXTAREA != 0
class Textarea : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_textarea_class; }

    /**
     * Insert a character to the current cursor position.
     * To add a wide char, e.g. 'Á' use `lv_text_encoded_conv_wc('Á')`
     * @param c  a character (e.g. 'a')
     * @see lv_textarea_add_char
     */
    void add_char(uint32_t c) const noexcept { lv_textarea_add_char(p_, c); }
    /**
     * Insert a text to the current cursor position
     * @param txt  a '\0' terminated string to insert
     * @see lv_textarea_add_text
     */
    void add_text(const char* txt) const noexcept { lv_textarea_add_text(p_, txt); }
    /**
     * Clear the selection on the text area.
     * @see lv_textarea_clear_selection
     */
    void clear_selection() const noexcept { lv_textarea_clear_selection(p_); }
    /**
     * Create a text area object
     * @param parent  pointer to an object, it will be the parent of the new text area
     * @return pointer to the created text area
     * @see lv_textarea_create
     */
    static Textarea create(Obj parent) noexcept { return Textarea(lv_textarea_create(parent.raw())); }
    /**
     * Move the cursor one line down
     * @see lv_textarea_cursor_down
     */
    void cursor_down() const noexcept { lv_textarea_cursor_down(p_); }
    /**
     * Move the cursor one character left
     * @see lv_textarea_cursor_left
     */
    void cursor_left() const noexcept { lv_textarea_cursor_left(p_); }
    /**
     * Move the cursor one character right
     * @see lv_textarea_cursor_right
     */
    void cursor_right() const noexcept { lv_textarea_cursor_right(p_); }
    /**
     * Move the cursor one line up
     * @see lv_textarea_cursor_up
     */
    void cursor_up() const noexcept { lv_textarea_cursor_up(p_); }
    /**
     * Delete a the left character from the current cursor position
     * @see lv_textarea_delete_char
     */
    void delete_char() const noexcept { lv_textarea_delete_char(p_); }
    /**
     * Delete the right character from the current cursor position
     * @see lv_textarea_delete_char_forward
     */
    void delete_char_forward() const noexcept { lv_textarea_delete_char_forward(p_); }
    /**
     * Get a list of accepted characters.
     * @return list of accented characters.
     * @see lv_textarea_get_accepted_chars
     */
    const char* get_accepted_chars() const noexcept { return lv_textarea_get_accepted_chars(p_); }
    /**
     * Get a the character from the current cursor position
     * @return a the character or 0
     * @see lv_textarea_get_current_char
     */
    uint32_t get_current_char() const noexcept { return lv_textarea_get_current_char(p_); }
    /**
     * Get whether the cursor click positioning is enabled or not.
     * @return true: enable click positions; false: disable
     * @see lv_textarea_get_cursor_click_pos
     */
    bool get_cursor_click_pos() const noexcept { return lv_textarea_get_cursor_click_pos(p_); }
    /**
     * Get the current cursor position in character index
     * @return the cursor position
     * @see lv_textarea_get_cursor_pos
     */
    uint32_t get_cursor_pos() const noexcept { return lv_textarea_get_cursor_pos(p_); }
    /**
     * Get the label of a text area
     * @return pointer to the label object
     * @see lv_textarea_get_label
     */
    Obj get_label() const noexcept { return Obj(lv_textarea_get_label(p_)); }
    /**
     * Get max length of a Text Area.
     * @return the maximal number of characters to be add
     * @see lv_textarea_get_max_length
     */
    uint32_t get_max_length() const noexcept { return lv_textarea_get_max_length(p_); }
    /**
     * Get the one line configuration attribute
     * @return true: one line configuration is enabled, false: disabled
     * @see lv_textarea_get_one_line
     */
    bool get_one_line() const noexcept { return lv_textarea_get_one_line(p_); }
    /**
     * Get the replacement characters to show in password mode
     * @return pointer to the replacement text
     * @see lv_textarea_get_password_bullet
     */
    const char* get_password_bullet() const noexcept { return lv_textarea_get_password_bullet(p_); }
    /**
     * Get the password mode attribute
     * @return true: password mode is enabled, false: disabled
     * @see lv_textarea_get_password_mode
     */
    bool get_password_mode() const noexcept { return lv_textarea_get_password_mode(p_); }
    /**
     * Set how long show the password before changing it to '*'
     * @return show time in milliseconds. 0: hide immediately.
     * @see lv_textarea_get_password_show_time
     */
    uint32_t get_password_show_time() const noexcept { return lv_textarea_get_password_show_time(p_); }
    /**
     * Get the placeholder text of a text area
     * @return pointer to the text
     * @see lv_textarea_get_placeholder_text
     */
    const char* get_placeholder_text() const noexcept { return lv_textarea_get_placeholder_text(p_); }
    /**
     * Get the text of a text area. In password mode it gives the real text (not '*'s).
     * @return pointer to the text
     * @see lv_textarea_get_text
     */
    const char* get_text() const noexcept { return lv_textarea_get_text(p_); }
    /**
     * Find whether selection mode is enabled.
     * @return true: selection mode is enabled, false: disabled
     * @see lv_textarea_get_text_selection
     */
    bool get_text_selection() const noexcept { return lv_textarea_get_text_selection(p_); }
    /**
     * Set a list of characters. Only these characters will be accepted by the text area
     * @param list  list of characters. A copy is saved. Example: "+-.,0123456789"
     * @see lv_textarea_set_accepted_chars
     */
    void set_accepted_chars(const char* list) const noexcept { lv_textarea_set_accepted_chars(p_, list); }
    /**
     * Set a list of characters. Only these characters will be accepted by the text area
     * @param list  list of characters. Only the pointer is saved. Example: "+-.,0123456789"
     * @see lv_textarea_set_accepted_chars_static
     */
    void set_accepted_chars_static(const char* list) const noexcept { lv_textarea_set_accepted_chars_static(p_, list); }
    /**
     * @param align  the align mode from ::lv_text_align_t
     * @see lv_textarea_set_align
     */
    void set_align(TextAlign align) const noexcept { lv_textarea_set_align(p_, static_cast<lv_text_align_t>(align)); }
    /**
     * Enable/Disable the positioning of the cursor by clicking the text on the text area.
     * @param en  true: enable click positions; false: disable
     * @see lv_textarea_set_cursor_click_pos
     */
    void set_cursor_click_pos(bool en) const noexcept { lv_textarea_set_cursor_click_pos(p_, en); }
    /**
     * Set the cursor position
     * @param pos  the new cursor position in character index < 0 : index from the end of the text LV_TEXTAREA_CURSOR_LAST: go after the last character
     * @see lv_textarea_set_cursor_pos
     */
    void set_cursor_pos(int32_t pos) const noexcept { lv_textarea_set_cursor_pos(p_, pos); }
    /**
     * In `LV_EVENT_INSERT` the text which planned to be inserted can be replaced by another text.
     * It can be used to add automatic formatting to the text area.
     * @param txt  pointer to a new string to insert. If `""` no text will be added. The variable must be live after the `event_cb` exists. (Should be `global` or `static`)
     * @see lv_textarea_set_insert_replace
     */
    void set_insert_replace(const char* txt) const noexcept { lv_textarea_set_insert_replace(p_, txt); }
    /**
     * Set max length of a Text Area.
     * @param num  the maximal number of characters can be added (`lv_textarea_set_text` ignores it)
     * @see lv_textarea_set_max_length
     */
    void set_max_length(uint32_t num) const noexcept { lv_textarea_set_max_length(p_, num); }
    /**
     * Configure the text area to one line or back to normal
     * @param en  true: one line, false: normal
     * @see lv_textarea_set_one_line
     */
    void set_one_line(bool en) const noexcept { lv_textarea_set_one_line(p_, en); }
    /**
     * Set the replacement characters to show in password mode
     * @param bullet  pointer to the replacement text
     * @see lv_textarea_set_password_bullet
     */
    void set_password_bullet(const char* bullet) const noexcept { lv_textarea_set_password_bullet(p_, bullet); }
    /**
     * Enable/Disable password mode
     * @param en  true: enable, false: disable
     * @see lv_textarea_set_password_mode
     */
    void set_password_mode(bool en) const noexcept { lv_textarea_set_password_mode(p_, en); }
    /**
     * Set how long show the password before changing it to '*'
     * @param time  show time in milliseconds. 0: hide immediately.
     * @see lv_textarea_set_password_show_time
     */
    void set_password_show_time(uint32_t time) const noexcept { lv_textarea_set_password_show_time(p_, time); }
    /**
     * Set the placeholder text of a text area
     * @param txt  pointer to the text
     * @see lv_textarea_set_placeholder_text
     */
    void set_placeholder_text(const char* txt) const noexcept { lv_textarea_set_placeholder_text(p_, txt); }
    /**
     * Set the text of a text area
     * @param txt  pointer to the text
     * @see lv_textarea_set_text
     */
    void set_text(const char* txt) const noexcept { lv_textarea_set_text(p_, txt); }
    /**
     * Enable/disable selection mode.
     * @param en  true or false to enable/disable selection mode
     * @see lv_textarea_set_text_selection
     */
    void set_text_selection(bool en) const noexcept { lv_textarea_set_text_selection(p_, en); }
    /**
     * Find whether text is selected or not.
     * @return whether text is selected or not
     * @see lv_textarea_text_is_selected
     */
    bool text_is_selected() const noexcept { return lv_textarea_text_is_selected(p_); }
};
static_assert(sizeof(Textarea) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Textarea));
#endif // LV_USE_TEXTAREA != 0

} // namespace lv
