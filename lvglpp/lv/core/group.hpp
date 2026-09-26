#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

class Group {
protected:
    lv_group_t* p_ = nullptr;

public:
    constexpr Group() noexcept = default;  /**< the "no object" handle */
    constexpr explicit Group(lv_group_t* p) noexcept : p_(p) {}

    constexpr lv_group_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(Group a, Group b) noexcept { return a.p_ == b.p_; }

    /**
     * Add an Widget to group.
     * @param obj  pointer to a Widget to add
     * @see lv_group_add_obj
     */
    void add_obj(Obj obj) const noexcept;
    /**
     * Create new Widget group.
     * @return pointer to the new Widget group
     * @see lv_group_create
     */
    static Group create() noexcept;
    /**
     * Delete group object.
     * @see lv_group_delete
     */
    void delete_() const noexcept;
    /**
     * Do not allow changing focus from current Widget.
     * @param en  true: freeze, false: release freezing (normal mode)
     * @see lv_group_focus_freeze
     */
    void focus_freeze(bool en) const noexcept;
    /**
     * Focus on next Widget in a group (defocus the current).
     * @see lv_group_focus_next
     */
    void focus_next() const noexcept;
    /**
     * Focus on previous Widget in a group (defocus the current).
     * @see lv_group_focus_prev
     */
    void focus_prev() const noexcept;
    /**
     * Get edge callback function of a group.
     * @return the call back function or NULL if not set
     * @see lv_group_get_edge_cb
     */
    lv_group_edge_cb_t get_edge_cb() const noexcept;
    /**
     * Get current mode (edit or navigate).
     * @return true: edit mode; false: navigate mode
     * @see lv_group_get_editing
     */
    bool get_editing() const noexcept;
    /**
     * Get focus callback function of a group.
     * @return the call back function or NULL if not set
     * @see lv_group_get_focus_cb
     */
    lv_group_focus_cb_t get_focus_cb() const noexcept;
    /**
     * Get Widget that has focus, or NULL if there isn't one.
     * @return pointer to Widget with focus
     * @see lv_group_get_focused
     */
    Obj get_focused() const noexcept;
    /**
     * Get nth Widget within group.
     * @param index  index of Widget within the group
     * @return pointer to Widget
     * @see lv_group_get_obj_by_index
     */
    Obj get_obj_by_index(uint32_t index) const noexcept;
    /**
     * Get number of Widgets in group.
     * @return number of Widgets in the group
     * @see lv_group_get_obj_count
     */
    uint32_t get_obj_count() const noexcept;
    /**
     * Get a pointer to the user data of the group
     * @return pointer to the user data or NULL if group is NULL
     * @see lv_group_get_user_data
     */
    void* get_user_data() const noexcept;
    /**
     * Get whether moving focus to next/previous Widget will allow wrapping from
     * first->last or last->first Widget.
     * @see lv_group_get_wrap
     */
    bool get_wrap() const noexcept;
    /**
     * Remove all Widgets from a group.
     * @see lv_group_remove_all_objs
     */
    void remove_all_objs() const noexcept;
    /**
     * Send a control character to Widget that has focus in a group.
     * @param c  a character (use LV_KEY_.. to navigate)
     * @return result of Widget with focus in group.
     * @see lv_group_send_data
     */
    Result send_data(uint32_t c) const noexcept;
    /**
     * Set default group. New Widgets will be added to this group if it's enabled in
     * their class with `add_to_def_group = true`.
     * @see lv_group_set_default
     */
    void set_default() const noexcept;
    /**
     * Set a function for a group which will be called when a focus edge is reached
     * @param edge_cb  the call back function or NULL if unused
     * @see lv_group_set_edge_cb
     */
    void set_edge_cb(lv_group_edge_cb_t edge_cb) const noexcept;
    /**
     * Manually set the current mode (edit or navigate).
     * @param edit  true: edit mode; false: navigate mode
     * @see lv_group_set_editing
     */
    void set_editing(bool edit) const noexcept;
    #if LV_USE_EXT_DATA
    /**
     * Attaches external user data and destructor callback to a group
     * Associates custom user data with an LVGL group and specifies a destructor function
     * that will be automatically invoked when the group is deleted to properly clean up
     * the associated resources.
     * @param data  User-defined data pointer to associate with a group
     * @see lv_group_set_external_data
     */
    void set_external_data(void* data, void (*arg)(void*)) const noexcept;
    /**
     * Takes the function itself as a template argument, so its real parameter types survive: the C idiom CASTS the pointer, which is undefined whenever they differ, and between the versions they do.
     * Attaches external user data and destructor callback to a group
     * Associates custom user data with an LVGL group and specifies a destructor function
     * that will be automatically invoked when the group is deleted to properly clean up
     * the associated resources.
     * @param data  User-defined data pointer to associate with a group
     * @see lv_group_set_external_data
     */
    template <auto Fn>
    void set_external_data(void* data) const noexcept;
    #endif // LV_USE_EXT_DATA

    /**
     * Set a function for a group which will be called when a new Widget has focus.
     * @param focus_cb  the call back function or NULL if unused
     * @see lv_group_set_focus_cb
     */
    void set_focus_cb(lv_group_focus_cb_t focus_cb) const noexcept;
    /**
     * Set whether the next or previous Widget in a group gets focus when Widget that has
     * focus is deleted.
     * @param policy  new refocus policy enum
     * @see lv_group_set_refocus_policy
     */
    void set_refocus_policy(GroupRefocusPolicy policy) const noexcept;
    /**
     * Set user data to the group
     * @param user_data  pointer to user data
     * @see lv_group_set_user_data
     */
    void set_user_data(void* user_data) const noexcept;
    /**
     * Set whether moving focus to next/previous Widget will allow wrapping from
     * first->last or last->first Widget.
     * @param en  true: wrapping enabled; false: wrapping disabled
     * @see lv_group_set_wrap
     */
    void set_wrap(bool en) const noexcept;
    #if LVPP_COMPAT_V8
    /** v8 spelling of `delete_`. */
    void del() const noexcept;
    #endif // LVPP_COMPAT_V8

};
static_assert(sizeof(Group) == sizeof(lv_group_t*));
static_assert(__is_trivially_copyable(Group));

/**
 * Get default group.
 * @return pointer to the default group
 * @see lv_group_get_default
 */
inline Group group_get_default() noexcept;

/**
 * Swap 2 Widgets in group.  Widgets must be in the same group.
 * @param obj1  pointer to a Widget
 * @param obj2  pointer to another Widget
 * @see lv_group_swap_obj
 */
inline void group_swap_obj(Obj obj1, Obj obj2) noexcept;

/**
 * Remove a Widget from its group.
 * @param obj  pointer to Widget to remove
 * @see lv_group_remove_obj
 */
inline void group_remove_obj(Obj obj) noexcept;

/**
 * Focus on a Widget (defocus the current).
 * @param obj  pointer to Widget to focus on
 * @see lv_group_focus_obj
 */
inline void group_focus_obj(Obj obj) noexcept;

/**
 * Get the number of groups.
 * @return number of groups
 * @see lv_group_get_count
 */
inline uint32_t group_get_count() noexcept;

/**
 * Get a group by its index.
 * @param index  index of the group
 * @return pointer to the group
 * @see lv_group_by_index
 */
inline Group group_by_index(uint32_t index) noexcept;

} // namespace lv
