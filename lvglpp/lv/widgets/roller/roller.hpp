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

#if LV_USE_ROLLER != 0
class Roller : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_roller_class; }

    /** Roller mode. */
    enum class Mode : int {
        /** Normal mode (roller ends at the end of the options). */
        Normal = LV_ROLLER_MODE_NORMAL,
        /** Infinite mode (roller can be scrolled forever). */
        Infinite = LV_ROLLER_MODE_INFINITE,
    };

    #if LV_USE_OBSERVER
    /**
     * Bind an integer Subject to a Roller's value.
     * @param subject  pointer to Subject
     * @return pointer to newly-created Observer
     * @see lv_roller_bind_value
     */
    Observer bind_value(Subject& subject) const noexcept { return Observer(lv_roller_bind_value(p_, subject.raw())); }
    #endif // LV_USE_OBSERVER

    /**
     * Create a roller object
     * @param parent  pointer to an object, it will be the parent of the new roller.
     * @return pointer to the created roller
     * @see lv_roller_create
     */
    static Roller create(Obj parent) noexcept { return Roller(lv_roller_create(parent.raw())); }
    /**
     * Get the total number of options
     * @return the total number of options
     * @see lv_roller_get_option_count
     */
    uint32_t get_option_count() const noexcept { return lv_roller_get_option_count(p_); }
    /**
     * Get an option as a string.
     * @param option  index of chosen option
     * @param buf  pointer to an array to store the string
     * @param buf_size  size of `buf` in bytes. 0: to ignore it.
     * @return LV_RESULT_OK if option found
     * @see lv_roller_get_option_str
     */
    Result get_option_str(uint32_t option, char* buf, uint32_t buf_size) const noexcept { return static_cast<Result>(lv_roller_get_option_str(p_, option, buf, buf_size)); }
    /**
     * Get the options of a roller
     * @return the options separated by '\n'-s (E.g. "Option1\nOption2\nOption3")
     * @see lv_roller_get_options
     */
    const char* get_options() const noexcept { return lv_roller_get_options(p_); }
    /**
     * Get the index of the selected option
     * @return index of the selected option (0 ... number of option - 1);
     * @see lv_roller_get_selected
     */
    uint32_t get_selected() const noexcept { return lv_roller_get_selected(p_); }
    /**
     * Get the current selected option as a string.
     * @param buf  pointer to an array to store the string
     * @param buf_size  size of `buf` in bytes. 0: to ignore it.
     * @see lv_roller_get_selected_str
     */
    void get_selected_str(char* buf, uint32_t buf_size) const noexcept { lv_roller_get_selected_str(p_, buf, buf_size); }
    /**
     * Set the options on a roller
     * @param options  a string with '\n' separated options. E.g. "One\nTwo\nThree"
     * @param mode  `LV_ROLLER_MODE_NORMAL` or `LV_ROLLER_MODE_INFINITE`
     * @see lv_roller_set_options
     */
    void set_options(const char* options, Roller::Mode mode) const noexcept { lv_roller_set_options(p_, options, static_cast<lv_roller_mode_t>(mode)); }
    /**
     * Set the selected option
     * @param sel_opt  index of the selected option (0 ... number of option - 1);
     * @param anim  LV_ANIM_ON: set with animation; LV_ANIM_OFF set immediately
     * @see lv_roller_set_selected
     */
    void set_selected(uint32_t sel_opt, lv_anim_enable_t anim) const noexcept { lv_roller_set_selected(p_, sel_opt, anim); }
    /**
     * Sets the given string as the selection on the roller. Does not alter the current selection on failure.
     * @param sel_opt  pointer to the string you want to set as an option
     * @param anim  LV_ANIM_ON: set with animation; LV_ANIM_OFF set immediately
     * @return `true` if set successfully and `false` if the given string does not exist as an option in the roller
     * @see lv_roller_set_selected_str
     */
    bool set_selected_str(const char* sel_opt, lv_anim_enable_t anim) const noexcept { return lv_roller_set_selected_str(p_, sel_opt, anim); }
    /**
     * Set the height to show the given number of rows (options)
     * @param row_cnt  number of desired visible rows
     * @see lv_roller_set_visible_row_count
     */
    void set_visible_row_count(uint32_t row_cnt) const noexcept { lv_roller_set_visible_row_count(p_, row_cnt); }
    #if LVPP_COMPAT_V8
    /** v8 spelling of `set_visible_row_count`. */
    void set_visible_row_cnt(uint32_t row_cnt) const noexcept { return set_visible_row_count(row_cnt); }
    /** v8 spelling of `get_option_count`. */
    uint32_t get_option_cnt() const noexcept { return get_option_count(); }
    #endif // LVPP_COMPAT_V8

};
static_assert(sizeof(Roller) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Roller));
#endif // LV_USE_ROLLER != 0

} // namespace lv
