#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core.hpp"
#include "lv/core/obj.hpp"
#include "lv/core/observer.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_DROPDOWN != 0
class Dropdown : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_dropdown_class; }

    /**
     * Add an options to a drop-down list from a string.  Only works for non-static options.
     * @param option  a string without '\n'. E.g. "Four"
     * @param pos  the insert position, indexed from 0, LV_DROPDOWN_POS_LAST = end of string
     * @see lv_dropdown_add_option
     */
    void add_option(const char* option, uint32_t pos) const noexcept { lv_dropdown_add_option(p_, option, pos); }
    #if LV_USE_OBSERVER
    /**
     * Bind an integer Subject to a Dropdown's value.
     * @param subject  pointer to Subject
     * @return pointer to newly-created Observer
     * @see lv_dropdown_bind_value
     */
    Observer bind_value(Subject& subject) const noexcept { return Observer(lv_dropdown_bind_value(p_, subject.raw())); }
    #endif // LV_USE_OBSERVER

    /**
     * Clear all options in a drop-down list.  Works with both static and dynamic options.
     * @see lv_dropdown_clear_options
     */
    void clear_options() const noexcept { lv_dropdown_clear_options(p_); }
    /**
     * Close (Collapse) the drop-down list
     * @see lv_dropdown_close
     */
    void close() const noexcept { lv_dropdown_close(p_); }
    /**
     * Create a drop-down list object
     * @param parent  pointer to an object, it will be the parent of the new drop-down list
     * @return pointer to the created drop-down list
     * @see lv_dropdown_create
     */
    static Dropdown create(Obj parent) noexcept { return Dropdown(lv_dropdown_create(parent.raw())); }
    /**
     * Get the direction of the drop-down list
     * @return LV_DIR_LEF/RIGHT/TOP/BOTTOM
     * @see lv_dropdown_get_dir
     */
    Dir get_dir() const noexcept { return static_cast<Dir>(lv_dropdown_get_dir(p_)); }
    /**
     * Get the list of a drop-down to allow styling or other modifications
     * @return pointer to the list of the drop-down
     * @see lv_dropdown_get_list
     */
    Obj get_list() const noexcept { return Obj(lv_dropdown_get_list(p_)); }
    /**
     * Get the total number of options
     * @return the total number of options in the list
     * @see lv_dropdown_get_option_count
     */
    uint32_t get_option_count() const noexcept { return lv_dropdown_get_option_count(p_); }
    /**
     * Get the index of an option.
     * @param option  an option as string
     * @return index of `option` in the list of all options. -1 if not found.
     * @see lv_dropdown_get_option_index
     */
    int32_t get_option_index(const char* option) const noexcept { return lv_dropdown_get_option_index(p_, option); }
    /**
     * Get the options of a drop-down list
     * @return the options separated by '\n'-s (E.g. "Option1\nOption2\nOption3")
     * @see lv_dropdown_get_options
     */
    const char* get_options() const noexcept { return lv_dropdown_get_options(p_); }
    /**
     * Get the index of the selected option
     * @return index of the selected option (0 ... number of option - 1);
     * @see lv_dropdown_get_selected
     */
    uint32_t get_selected() const noexcept { return lv_dropdown_get_selected(p_); }
    /**
     * Get whether the selected option in the list should be highlighted or not
     * @return true: highlight enabled; false: disabled
     * @see lv_dropdown_get_selected_highlight
     */
    bool get_selected_highlight() const noexcept { return lv_dropdown_get_selected_highlight(p_); }
    /**
     * Get the current selected option as a string
     * @param buf  pointer to an array to store the string
     * @param buf_size  size of `buf` in bytes. 0: to ignore it.
     * @see lv_dropdown_get_selected_str
     */
    void get_selected_str(char* buf, uint32_t buf_size) const noexcept { lv_dropdown_get_selected_str(p_, buf, buf_size); }
    /**
     * Get the symbol on the drop-down list. Typically a down caret or arrow.
     * @return the symbol or NULL if not enabled
     * @see lv_dropdown_get_symbol
     */
    const char* get_symbol() const noexcept { return lv_dropdown_get_symbol(p_); }
    /**
     * Get text of the drop-down list's button.
     * @return the text as string, `NULL` if no text
     * @see lv_dropdown_get_text
     */
    const char* get_text() const noexcept { return lv_dropdown_get_text(p_); }
    /**
     * Tells whether the list is opened or not
     * @return true if the list os opened
     * @see lv_dropdown_is_open
     */
    bool is_open() const noexcept { return lv_dropdown_is_open(p_); }
    /**
     * Open the drop.down list
     * @see lv_dropdown_open
     */
    void open() const noexcept { lv_dropdown_open(p_); }
    /**
     * Set the direction of the a drop-down list
     * @param dir  LV_DIR_LEFT/RIGHT/TOP/BOTTOM
     * @see lv_dropdown_set_dir
     */
    void set_dir(Dir dir) const noexcept { lv_dropdown_set_dir(p_, static_cast<lv_dir_t>(dir)); }
    /**
     * Set the options in a drop-down list from a string.
     * The options will be copied and saved in the object so the `options` can be destroyed after calling this function
     * @param options  a string with '\n' separated options. E.g. "One\nTwo\nThree"
     * @see lv_dropdown_set_options
     */
    void set_options(const char* options) const noexcept { lv_dropdown_set_options(p_, options); }
    /**
     * LVGL keeps this pointer rather than copying what it points at: it must outlive the object. A string literal is the intended use.
     * Set the options in a drop-down list from a static string (global, static or dynamically allocated).
     * Only the pointer of the option string will be saved.
     * @param options  a static string with '\n' separated options. E.g. "One\nTwo\nThree"
     * @see lv_dropdown_set_options_static
     */
    void set_options_static(const char* options) const noexcept { lv_dropdown_set_options_static(p_, options); }
    /**
     * Set the selected option
     * @param sel_opt  id of the selected option (0 ... number of option - 1);
     * @see lv_dropdown_set_selected
     */
    void set_selected(uint32_t sel_opt) const noexcept { lv_dropdown_set_selected(p_, sel_opt); }
    /**
     * Set whether the selected option in the list should be highlighted or not
     * @param en  true: highlight enabled; false: disabled
     * @see lv_dropdown_set_selected_highlight
     */
    void set_selected_highlight(bool en) const noexcept { lv_dropdown_set_selected_highlight(p_, en); }
    /**
     * Set an arrow or other symbol to display when on drop-down list's button. Typically a down caret or arrow.
     * @param symbol  a text like `LV_SYMBOL_DOWN`, an image (pointer or path) or NULL to not draw symbol icon
     * @see lv_dropdown_set_symbol
     */
    void set_symbol(const void* symbol) const noexcept { lv_dropdown_set_symbol(p_, symbol); }
    /**
     * Set text of the drop-down list's button.
     * If set to `NULL` the selected option's text will be displayed on the button.
     * If set to a specific text then that text will be shown regardless of the selected option.
     * @param text  the text as a string (Copy is saved)
     * @see lv_dropdown_set_text
     */
    void set_text(const char* text) const noexcept { lv_dropdown_set_text(p_, text); }
    /**
     * Set text of the drop-down list's button.
     * If set to `NULL` the selected option's text will be displayed on the button.
     * If set to a specific text then that text will be shown regardless of the selected option.
     * @param text  the text as a string (Only its pointer is saved)
     * @see lv_dropdown_set_text_static
     */
    void set_text_static(const char* text) const noexcept { lv_dropdown_set_text_static(p_, text); }
    #if LVPP_COMPAT_V8
    /** v8 spelling of `get_option_count`. */
    uint32_t get_option_cnt() const noexcept { return get_option_count(); }
    #endif // LVPP_COMPAT_V8

};
static_assert(sizeof(Dropdown) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Dropdown));
#endif // LV_USE_DROPDOWN != 0

} // namespace lv
