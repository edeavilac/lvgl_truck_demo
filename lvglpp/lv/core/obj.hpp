#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/misc/event.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstddef>
#include <cstdint>
#include <utility>

namespace lv {

class Obj : public detail::EventAliases<Obj, detail::ObjTarget> {
protected:
    lv_obj_t* p_ = nullptr;

public:
    constexpr Obj() noexcept = default;  /**< the "no object" handle */
    constexpr explicit Obj(lv_obj_t* p) noexcept : p_(p) {}

    constexpr lv_obj_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(Obj a, Obj b) noexcept { return a.p_ == b.p_; }
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_obj_class; }

    template <class T> bool is() const noexcept {
        return p_ != nullptr && lv_obj_has_class(p_, T::class_ptr());
    }
    /** Unchecked in release, asserted in debug. */
    template <class T> T as() const noexcept {
        LVPP_ASSERT(is<T>(), "lv::Obj::as<T>() on an incompatible object");
        return T(p_);
    }
    /** Returns a null handle instead of asserting. */
    template <class T> T try_as() const noexcept { return is<T>() ? T(p_) : T(); }

    /**
     * Set one or more flags
     * @param f  OR-ed values from `lv_obj_flag_t` to set.
     * @see lv_obj_add_flag
     */
    void add_flag(ObjFlag f) const noexcept;
    /**
     * Play a timeline animation on a trigger
     * @param trigger  an event code, e.g. `LV_EVENT_CLICKED`
     * @param at  pointer to an animation timeline
     * @param delay  wait time before starting the animation
     * @param reverse  true: play in reverse
     * @see lv_obj_add_play_timeline_event
     */
    void add_play_timeline_event(EventCode trigger, AnimTimeline at, uint32_t delay, bool reverse) const noexcept;
    /**
     * Add an event handler to a widget that will create a screen on a trigger.
     * The created screen will be deleted when it's unloaded
     * @param trigger  an event code, e.g. `LV_EVENT_CLICKED`
     * @param screen_create_cb  a callback to create the screen, e.g. `lv_obj_t * myscreen_create(void)`
     * @param anim_type  element of `lv_screen_load_anim_t` the screen load animation
     * @param duration  duration of the animation in milliseconds
     * @param delay  delay before the screen load in milliseconds
     * @see lv_obj_add_screen_create_event
     */
    void add_screen_create_event(EventCode trigger, lv_screen_create_cb_t screen_create_cb, ScreenLoadAnim anim_type, uint32_t duration, uint32_t delay) const noexcept;
    /**
     * Add an event handler to a widget that will load a screen on a trigger.
     * @param trigger  an event code, e.g. `LV_EVENT_CLICKED`
     * @param screen  the screen to load (must be a valid widget)
     * @param anim_type  element of `lv_screen_load_anim_t` the screen load animation
     * @param duration  duration of the animation in milliseconds
     * @param delay  delay before the screen load in milliseconds
     * @see lv_obj_add_screen_load_event
     */
    void add_screen_load_event(EventCode trigger, Obj screen, ScreenLoadAnim anim_type, uint32_t duration, uint32_t delay) const noexcept;
    /**
     * Add one or more states to the object. The other state bits will remain unchanged.
     * If specified in the styles, transition animation will be started from the previous state to the current.
     * @param state  the states to add. E.g `LV_STATE_PRESSED | LV_STATE_FOCUSED`
     * @see lv_obj_add_state
     */
    void add_state(State state) const noexcept;
    /**
     * Add a style to an object.
     * @param style  pointer to a style to add
     * @see lv_obj_add_style
     */
    void add_style(Style& style, lv_style_selector_t selector) const noexcept;
    #if LV_USE_OBSERVER
    /**
     * Add an event handler to increment (or decrement) the value of a subject on a trigger.
     * @param subject  pointer to a subject to change
     * @param trigger  the trigger on which the subject should be changed
     * @param step  value to add on trigger if the minimum value is reached, the maximum value will be set on rollover.
     * @see lv_obj_add_subject_increment_event
     */
    SubjectIncrementDsc add_subject_increment_event(Subject& subject, EventCode trigger, int32_t step) const noexcept;
    #endif // LV_USE_OBSERVER

    #if (LV_USE_OBSERVER) && (LV_USE_FLOAT)
    /**
     * Set the value of a float subject.
     * @param subject  pointer to a subject to change
     * @param trigger  the trigger on which the subject should be changed
     * @param value  the value to set
     * @see lv_obj_add_subject_set_float_event
     */
    void add_subject_set_float_event(Subject& subject, EventCode trigger, float value) const noexcept;
    #endif // (LV_USE_OBSERVER) && (LV_USE_FLOAT)

    #if LV_USE_OBSERVER
    /**
     * Set the value of an integer subject.
     * @param subject  pointer to a subject to change
     * @param trigger  the trigger on which the subject should be changed
     * @param value  the value to set
     * @see lv_obj_add_subject_set_int_event
     */
    void add_subject_set_int_event(Subject& subject, EventCode trigger, int32_t value) const noexcept;
    /**
     * Set the value of a string subject.
     * @param subject  pointer to a subject to change
     * @param trigger  the trigger on which the subject should be changed
     * @param value  the value to set
     * @see lv_obj_add_subject_set_string_event
     */
    void add_subject_set_string_event(Subject& subject, EventCode trigger, const char* value) const noexcept;
    /**
     * Toggle the value of an integer subject on an event. If it was != 0 it will be 0.
     * If it was 0, it will be 1.
     * @param subject  pointer to a subject to toggle
     * @param trigger  the trigger on which the subject should be changed
     * @see lv_obj_add_subject_toggle_event
     */
    void add_subject_toggle_event(Subject& subject, EventCode trigger) const noexcept;
    #endif // LV_USE_OBSERVER

    /**
     * Change the alignment of an object and set new coordinates.
     * Equivalent to:
     * lv_obj_set_align(obj, align);
     * lv_obj_set_pos(obj, x_ofs, y_ofs);
     * @param align  type of alignment (see 'lv_align_t' enum) `LV_ALIGN_OUT_...` can't be used.
     * @param x_ofs  x coordinate offset after alignment
     * @param y_ofs  y coordinate offset after alignment
     * @see lv_obj_align
     */
    void align(Align align, int32_t x_ofs, int32_t y_ofs) const noexcept;
    /**
     * Align an object to another object.
     * @param base  pointer to another object (if NULL `obj`s parent is used). 'obj' will be aligned to it.
     * @param align  type of alignment (see 'lv_align_t' enum)
     * @param x_ofs  x coordinate offset after alignment
     * @param y_ofs  y coordinate offset after alignment
     * @see lv_obj_align_to
     */
    void align_to(Obj base, Align align, int32_t x_ofs, int32_t y_ofs) const noexcept;
    /**
     * Allocate special data for an object if not allocated yet.
     * @see lv_obj_allocate_spec_attr
     */
    void allocate_spec_attr() const noexcept;
    /**
     * Tell whether an area of an object is visible (even partially) now or not
     * @param area  the are to check. The visible part of the area will be written back here.
     * @return true visible; false not visible (hidden, out of parent, on other screen, etc)
     * @see lv_obj_area_is_visible
     */
    bool area_is_visible(Area& area) const noexcept;
    #if LV_USE_OBSERVER
    /**
     * Set an integer Subject to 1 when a Widget is checked and set it 0 when unchecked, and
     * clear Widget's checked state when Subject's value changes to 0 and set it when non-zero.
     * @param subject  pointer to a Subject
     * @return pointer to newly-created Observer
     * @see lv_obj_bind_checked
     */
    Observer bind_checked(Subject& subject) const noexcept;
    /**
     * Set Widget's flag(s) if an integer Subject's value is equal to a reference value, clear flag otherwise.
     * @param subject  pointer to Subject
     * @param flag  flag(s) (can be bit-wise OR-ed) to set or clear (e.g. `LV_OBJ_FLAG_HIDDEN`)
     * @param ref_value  reference value to compare Subject's value with
     * @return pointer to newly-created Observer
     * @see lv_obj_bind_flag_if_eq
     */
    Observer bind_flag_if_eq(Subject& subject, ObjFlag flag, int32_t ref_value) const noexcept;
    /**
     * Set Widget's flag(s) if an integer Subject's value is greater than or equal to a reference value, clear flag otherwise.
     * @param subject  pointer to Subject
     * @param flag  flag(s) (can be bit-wise OR-ed) to set or clear (e.g. `LV_OBJ_FLAG_HIDDEN`)
     * @param ref_value  reference value to compare Subject's value with
     * @return pointer to newly-created Observer
     * @see lv_obj_bind_flag_if_ge
     */
    Observer bind_flag_if_ge(Subject& subject, ObjFlag flag, int32_t ref_value) const noexcept;
    /**
     * Set Widget's flag(s) if an integer Subject's value is greater than a reference value, clear flag otherwise.
     * @param subject  pointer to Subject
     * @param flag  flag(s) (can be bit-wise OR-ed) to set or clear (e.g. `LV_OBJ_FLAG_HIDDEN`)
     * @param ref_value  reference value to compare Subject's value with
     * @return pointer to newly-created Observer
     * @see lv_obj_bind_flag_if_gt
     */
    Observer bind_flag_if_gt(Subject& subject, ObjFlag flag, int32_t ref_value) const noexcept;
    /**
     * Set Widget's flag(s) if an integer Subject's value is less than or equal to a reference value, clear flag otherwise.
     * @param subject  pointer to Subject
     * @param flag  flag(s) (can be bit-wise OR-ed) to set or clear (e.g. `LV_OBJ_FLAG_HIDDEN`)
     * @param ref_value  reference value to compare Subject's value with
     * @return pointer to newly-created Observer
     * @see lv_obj_bind_flag_if_le
     */
    Observer bind_flag_if_le(Subject& subject, ObjFlag flag, int32_t ref_value) const noexcept;
    /**
     * Set Widget's flag(s) if an integer Subject's value is less than a reference value, clear flag otherwise.
     * @param subject  pointer to Subject
     * @param flag  flag(s) (can be bit-wise OR-ed) to set or clear (e.g. `LV_OBJ_FLAG_HIDDEN`)
     * @param ref_value  reference value to compare Subject's value with
     * @return pointer to newly-created Observer
     * @see lv_obj_bind_flag_if_lt
     */
    Observer bind_flag_if_lt(Subject& subject, ObjFlag flag, int32_t ref_value) const noexcept;
    /**
     * Set Widget's flag(s) if an integer Subject's value is not equal to a reference value, clear flag otherwise.
     * @param subject  pointer to Subject
     * @param flag  flag(s) (can be bit-wise OR-ed) to set or clear (e.g. `LV_OBJ_FLAG_HIDDEN`)
     * @param ref_value  reference value to compare Subject's value with
     * @return pointer to newly-created Observer
     * @see lv_obj_bind_flag_if_not_eq
     */
    Observer bind_flag_if_not_eq(Subject& subject, ObjFlag flag, int32_t ref_value) const noexcept;
    /**
     * Set Widget's state(s) if an integer Subject's value is equal to a reference value, clear flag otherwise.
     * @param subject  pointer to Subject
     * @param state  state(s) (can be bit-wise OR-ed) to set or clear (e.g. `LV_STATE_CHECKED`)
     * @param ref_value  reference value to compare Subject's value with
     * @return pointer to newly-created Observer
     * @see lv_obj_bind_state_if_eq
     */
    Observer bind_state_if_eq(Subject& subject, State state, int32_t ref_value) const noexcept;
    /**
     * Set Widget's state(s) if an integer Subject's value is greater than or equal to a reference value, clear flag otherwise.
     * @param subject  pointer to Subject
     * @param state  state(s) (can be bit-wise OR-ed) to set or clear (e.g. `LV_STATE_CHECKED`)
     * @param ref_value  reference value to compare Subject's value with
     * @return pointer to newly-created Observer
     * @see lv_obj_bind_state_if_ge
     */
    Observer bind_state_if_ge(Subject& subject, State state, int32_t ref_value) const noexcept;
    /**
     * Set Widget's state(s) if an integer Subject's value is greater than a reference value, clear flag otherwise.
     * @param subject  pointer to Subject
     * @param state  state(s) (can be bit-wise OR-ed) to set or clear (e.g. `LV_STATE_CHECKED`)
     * @param ref_value  reference value to compare Subject's value with
     * @return pointer to newly-created Observer
     * @see lv_obj_bind_state_if_gt
     */
    Observer bind_state_if_gt(Subject& subject, State state, int32_t ref_value) const noexcept;
    /**
     * Set Widget's state(s) if an integer Subject's value is less than or equal to a reference value, clear flag otherwise.
     * @param subject  pointer to Subject
     * @param state  state(s) (can be bit-wise OR-ed) to set or clear (e.g. `LV_STATE_CHECKED`)
     * @param ref_value  reference value to compare Subject's value with
     * @return pointer to newly-created Observer
     * @see lv_obj_bind_state_if_le
     */
    Observer bind_state_if_le(Subject& subject, State state, int32_t ref_value) const noexcept;
    /**
     * Set Widget's state(s) if an integer Subject's value is less than a reference value, clear flag otherwise.
     * @param subject  pointer to Subject
     * @param state  state(s) (can be bit-wise OR-ed) to set or clear (e.g. `LV_STATE_CHECKED`)
     * @param ref_value  reference value to compare Subject's value with
     * @return pointer to newly-created Observer
     * @see lv_obj_bind_state_if_lt
     */
    Observer bind_state_if_lt(Subject& subject, State state, int32_t ref_value) const noexcept;
    /**
     * Set a Widget's state(s) if an integer Subject's value is not equal to a reference value, clear flag otherwise
     * @param subject  pointer to Subject
     * @param state  state(s) (can be bit-wise OR-ed) to set or clear (e.g. `LV_STATE_CHECKED`)
     * @param ref_value  reference value to compare Subject's value with
     * @return pointer to newly-created Observer
     * @see lv_obj_bind_state_if_not_eq
     */
    Observer bind_state_if_not_eq(Subject& subject, State state, int32_t ref_value) const noexcept;
    /**
     * Disable a style if a subject's value is not equal to a reference value
     * @param style  pointer to a style
     * @param selector  pointer to a selector
     * @param subject  pointer to Subject
     * @param ref_value  reference value to compare Subject's value with
     * @return pointer to newly-created Observer
     * @see lv_obj_bind_style
     */
    Observer bind_style(Style& style, lv_style_selector_t selector, Subject& subject, int32_t ref_value) const noexcept;
    /**
     * Connect a subject's value to a style property of a widget.
     * @param prop  a style property
     * @param selector  a selector for which the property should be added, e.g. `LV_PART_KNOB | LV_STATE_PRESSED`
     * @param subject  pointer a Subject to which value the property should be bound
     * @return pointer to newly-created Observer
     * @see lv_obj_bind_style_prop
     */
    Observer bind_style_prop(lv_style_prop_t prop, lv_style_selector_t selector, Subject& subject) const noexcept;
    #endif // LV_USE_OBSERVER

    /**
     * Calculates the height in pixels of an LVGL object based on its style and parent for a given height `prop`.
     * @param prop  Which style height to calculate for. Valid values are: LV_STYLE_HEIGHT, LV_STYLE_MIN_HEIGHT, or LV_STYLE_MAX_HEIGHT.
     * @return The computed height for the object:
     * @see lv_obj_calc_dynamic_height
     */
    int32_t calc_dynamic_height(lv_style_prop_t prop) const noexcept;
    /**
     * Calculates the width in pixels of an LVGL object based on its style and parent for a given width `prop`.
     * @param prop  Which style width to calculate for. Valid values are: LV_STYLE_WIDTH, LV_STYLE_MIN_WIDTH, or LV_STYLE_MAX_WIDTH.
     * @return The computed width for the object:
     * @see lv_obj_calc_dynamic_width
     */
    int32_t calc_dynamic_width(lv_style_prop_t prop) const noexcept;
    /**
     * Get the required extra size (around the object's part) to draw shadow, outline, value etc.
     * @param part  part of the object
     * @return the extra size required around the object
     * @see lv_obj_calculate_ext_draw_size
     */
    int32_t calculate_ext_draw_size(Part part) const noexcept;
    /** @see lv_obj_calculate_style_text_align */
    TextAlign calculate_style_text_align(Part part, const char* txt) const noexcept;
    /**
     * Align an object to the center on its parent.
     * @see lv_obj_center
     */
    void center() const noexcept;
    /**
     * Check the type of obj.
     * @param class_p  a class to check (e.g. `lv_slider_class`)
     * @return true: `class_p` is the `obj` class.
     * @see lv_obj_check_type
     */
    bool check_type(ObjClass class_p) const noexcept;
    /**
     * Delete all children of an object.
     * Also remove the objects from their group and remove all animations (if any).
     * Send `LV_EVENT_DELETE` to deleted objects.
     * @see lv_obj_clean
     */
    void clean() const noexcept;
    /**
     * Create a base object (a rectangle)
     * @param parent  pointer to a parent object. If NULL then a screen will be created.
     * @return pointer to the new object
     * @see lv_obj_create
     */
    static Obj create(Obj parent) noexcept;
    /**
     * Delete an object and all of its children.
     * Also remove the objects from their group and remove all animations (if any).
     * Send `LV_EVENT_DELETE` to deleted objects.
     * @see lv_obj_delete
     */
    void delete_() const noexcept;
    /**
     * Helper function for asynchronously deleting objects.
     * Useful for cases where you can't delete an object directly in an `LV_EVENT_DELETE` handler (i.e. parent).
     * @see lv_obj_delete_async
     */
    void delete_async() const noexcept;
    /**
     * Delete an object after some delay
     * @param delay_ms  time to wait before delete in milliseconds
     * @see lv_obj_delete_delayed
     */
    void delete_delayed(uint32_t delay_ms) const noexcept;
    /**
     * Iterate through all children of any object and print their ID.
     * @see lv_obj_dump_tree
     */
    void dump_tree() const noexcept;
    /**
     * Fade in an an object and all its children.
     * @param time  time of fade
     * @param delay  delay to start the animation
     * @see lv_obj_fade_in
     */
    void fade_in(uint32_t time, uint32_t delay) const noexcept;
    /**
     * Fade out an an object and all its children.
     * @param time  time of fade
     * @param delay  delay to start the animation
     * @see lv_obj_fade_out
     */
    void fade_out(uint32_t time, uint32_t delay) const noexcept;
    #if LV_USE_OBJ_ID
    /**
     * DEPRECATED IDs are used only to print the widget trees.
     * To find a widget use `lv_obj_find_by_name`
     * Get the child object by its id.
     * It will check children and grandchildren recursively.
     * Function `lv_obj_id_compare` is used to matched obj id with given id.
     * @param id  the id of the child object
     * @return pointer to the child object or NULL if not found
     * @see lv_obj_find_by_id
     */
    Obj find_by_id(const void* id) const noexcept;
    #endif // LV_USE_OBJ_ID

    #if LV_USE_OBJ_NAME
    /**
     * Find a child with a given name on a parent. This child doesn't have to be the
     * direct child of the parent. First direct children of the parent will be checked,
     * and the direct children of the first child, etc. (Breadth-first search).
     * If the name of a widget was not set a name like "lv_button_1" will
     * be created for it using `lv_obj_get_name_resolved`.
     * @return the found widget or NULL if not found.
     * @see lv_obj_find_by_name
     */
    Obj find_by_name(const char* name) const noexcept;
    #endif // LV_USE_OBJ_NAME

    #if LV_USE_OBJ_ID
    /**
     * Free resources allocated by `lv_obj_assign_id` or `lv_obj_set_id`.
     * This function is also called automatically when object is deleted.
     * @see lv_obj_free_id
     */
    void free_id() const noexcept;
    #endif // LV_USE_OBJ_ID

    /**
     * Get the child of an object by the child's index.
     * @param idx  the index of the child. 0: the oldest (firstly created) child 1: the second oldest child count-1: the youngest -1: the youngest -2: the second youngest
     * @return pointer to the child or NULL if the index was invalid
     * @see lv_obj_get_child
     */
    Obj get_child(int32_t idx) const noexcept;
    #if LV_USE_OBJ_NAME
    /**
     * Get an object by name. The name can be a path too, for example
     * "main_container/lv_button_1/label".
     * In this case the first part of the name-path should be the direct child of the parent,
     * the second part, should the direct child of first one, etc.
     * If the name of a widget was not set a name like "lv_button_1" will
     * be created for it using `lv_obj_get_name_resolved`.
     * @return the found widget or NULL if not found.
     * @see lv_obj_get_child_by_name
     */
    Obj get_child_by_name(const char* name_path) const noexcept;
    #endif // LV_USE_OBJ_NAME

    /**
     * Get the child of an object by the child's index. Consider the children only with a given type.
     * @param idx  the index of the child. 0: the oldest (firstly created) child 1: the second oldest child count-1: the youngest -1: the youngest -2: the second youngest
     * @param class_p  the type of the children to check
     * @return pointer to the child or NULL if the index was invalid
     * @see lv_obj_get_child_by_type
     */
    Obj get_child_by_type(int32_t idx, ObjClass class_p) const noexcept;
    /**
     * Get the number of children
     * @return the number of children
     * @see lv_obj_get_child_count
     */
    uint32_t get_child_count() const noexcept;
    /**
     * Get the number of children having a given type.
     * @param class_p  the type of the children to check
     * @return the number of children
     * @see lv_obj_get_child_count_by_type
     */
    uint32_t get_child_count_by_type(ObjClass class_p) const noexcept;
    /**
     * Get the class (type) of the object
     * @return the class (type) of the object
     * @see lv_obj_get_class
     */
    ObjClass get_class() const noexcept;
    /**
     * Get the an area where to object can be clicked.
     * It's the object's normal area plus the extended click area.
     * @return store the result area here
     * @see lv_obj_get_click_area
     */
    Area get_click_area() const noexcept;
    /**
     * Get the area reduced by the paddings and the border width.
     * @return the area which still fits into the parent without causing overflow (making the parent scrollable)
     * @see lv_obj_get_content_coords
     */
    Area get_content_coords() const noexcept;
    /**
     * Get the height reduced by the top and bottom padding and the border width.
     * @return the height which still fits into the parent without causing overflow (making the parent scrollable)
     * @see lv_obj_get_content_height
     */
    int32_t get_content_height() const noexcept;
    /**
     * Get the width reduced by the left and right padding and the border width.
     * @return the width which still fits into its parent without causing overflow (making the parent scrollable)
     * @see lv_obj_get_content_width
     */
    int32_t get_content_width() const noexcept;
    /**
     * Copy the coordinates of an object to an area
     * @return pointer to an area to store the coordinates
     * @see lv_obj_get_coords
     */
    Area get_coords() const noexcept;
    /**
     * Get the display of the object
     * @return pointer to the object's display
     * @see lv_obj_get_display
     */
    Display get_display() const noexcept;
    /** @see lv_obj_get_event_count */
    uint32_t get_event_count() const noexcept;
    /** @see lv_obj_get_event_dsc */
    EventDsc get_event_dsc(uint32_t index) const noexcept;
    /**
     * Get the group of the object
     * @return the pointer to group of the object
     * @see lv_obj_get_group
     */
    Group get_group() const noexcept;
    /**
     * Get the height of an object
     * @return the height in pixels
     * @see lv_obj_get_height
     */
    int32_t get_height() const noexcept;
    #if LV_USE_OBJ_ID
    /**
     * Get the id of an object.
     * @return the id of the object
     * @see lv_obj_get_id
     */
    void* get_id() const noexcept;
    #endif // LV_USE_OBJ_ID

    /**
     * Get the index of a child.
     * @return the child index of the object. E.g. 0: the oldest (firstly created child). (-1 if child could not be found or no parent exists)
     * @see lv_obj_get_index
     */
    int32_t get_index() const noexcept;
    /**
     * Get the index of a child. Consider the children only with a given type.
     * @param class_p  the type of the children to check
     * @return the child index of the object. E.g. 0: the oldest (firstly created child with the given class). (-1 if child could not be found or no parent exists)
     * @see lv_obj_get_index_by_type
     */
    int32_t get_index_by_type(ObjClass class_p) const noexcept;
    /** @see lv_obj_get_local_style_prop */
    StyleRes get_local_style_prop(lv_style_prop_t prop, lv_style_value_t* value, lv_style_selector_t selector) const noexcept;
    #if LV_USE_OBJ_NAME
    /**
     * Get the set name as it was set.
     * @return get the set name or NULL if it wasn't set yet
     * @see lv_obj_get_name
     */
    const char* get_name() const noexcept;
    /**
     * Get the set name or craft a name automatically.
     * @param buf  buffer to store the name
     * @param buf_size  the size of the buffer in bytes
     * @see lv_obj_get_name_resolved
     */
    void get_name_resolved(char* buf, size_t buf_size) const noexcept;
    #endif // LV_USE_OBJ_NAME

    /**
     * Get the parent of an object
     * @return the parent of the object. (NULL if `obj` was a screen)
     * @see lv_obj_get_parent
     */
    Obj get_parent() const noexcept;
    #if LV_USE_OBJ_PROPERTY
    /**
     * Read property value from Widget.
     * If id is a style property, computes the style of PART_MAIN.
     * @param id  ID of property to read
     * @return return property value read. The returned property ID is set to `LV_PROPERTY_ID_INVALID` if read failed.
     * @see lv_obj_get_property
     */
    lv_property_t get_property(lv_prop_id_t id) const noexcept;
    #endif // LV_USE_OBJ_PROPERTY

    /**
     * Get the screen of an object
     * @return pointer to the object's screen
     * @see lv_obj_get_screen
     */
    Obj get_screen() const noexcept;
    /**
     * Number of pixels a scrollable container Widget can be scrolled up
     * before its bottom edge appears.  When LV_OBJ_FLAG_SCROLL_ELASTIC flag
     * is set in Widget, this value can go negative while Widget is being
     * dragged above its normal bottom-edge boundary.
     * @return pixels Widget can be scrolled up before its bottom edge appears
     * @see lv_obj_get_scroll_bottom
     */
    int32_t get_scroll_bottom() const noexcept;
    /**
     * Get directions Widget can be scrolled (set with `lv_obj_set_scroll_dir()`)
     * @return current scroll direction bit(s)
     * @see lv_obj_get_scroll_dir
     */
    Dir get_scroll_dir() const noexcept;
    /**
     * Get the X and Y coordinates where the scrolling will end for Widget if a scrolling animation is in progress.
     * If no scrolling animation, give the current `x` or `y` scroll position.
     * @return pointer to `lv_point_t` object in which to store result
     * @see lv_obj_get_scroll_end
     */
    Point get_scroll_end() const noexcept;
    /**
     * Number of pixels a scrollable container Widget can be scrolled right
     * before its left edge appears.  When LV_OBJ_FLAG_SCROLL_ELASTIC flag
     * is set in Widget, this value can go negative while Widget is being
     * dragged farther right than its normal left-edge boundary.
     * @return pixels Widget can be scrolled right before its left edge appears
     * @see lv_obj_get_scroll_left
     */
    int32_t get_scroll_left() const noexcept;
    /**
     * Number of pixels a scrollable container Widget can be scrolled left
     * before its right edge appears.  When LV_OBJ_FLAG_SCROLL_ELASTIC flag
     * is set in Widget, this value can go negative while Widget is being
     * dragged farther left than its normal right-edge boundary.
     * @return pixels Widget can be scrolled left before its right edge appears
     * @see lv_obj_get_scroll_right
     */
    int32_t get_scroll_right() const noexcept;
    /**
     * Get where to snap child Widgets when horizontal scrolling ends.
     * @return current snap value from `lv_scroll_snap_t`
     * @see lv_obj_get_scroll_snap_x
     */
    ScrollSnap get_scroll_snap_x() const noexcept;
    /**
     * Get where to snap child Widgets when vertical scrolling ends.
     * @return current snap value from `lv_scroll_snap_t`
     * @see lv_obj_get_scroll_snap_y
     */
    ScrollSnap get_scroll_snap_y() const noexcept;
    /**
     * Number of pixels a scrollable container Widget can be scrolled down
     * before its top edge appears.  When LV_OBJ_FLAG_SCROLL_ELASTIC flag
     * is set in Widget, this value can go negative while Widget is being
     * dragged below its normal top-edge boundary.
     * @return pixels Widget can be scrolled down before its top edge appears
     * @see lv_obj_get_scroll_top
     */
    int32_t get_scroll_top() const noexcept;
    /**
     * Get current X scroll position.  Identical to `lv_obj_get_scroll_left()`.
     * @return current scroll position from left edge - If Widget is not scrolled return 0. - If scrolled return > 0. - If scrolled inside (elastic scroll) return < 0.
     * @see lv_obj_get_scroll_x
     */
    int32_t get_scroll_x() const noexcept;
    /**
     * Get current Y scroll position.  Identical to `lv_obj_get_scroll_top()`.
     * @return current scroll position from top edge - If Widget is not scrolled return 0. - If scrolled return > 0. - If scrolled inside (elastic scroll) return < 0.
     * @see lv_obj_get_scroll_y
     */
    int32_t get_scroll_y() const noexcept;
    /**
     * Get the area of the scrollbars
     * @return hor: pointer to store the area of the horizontal scrollbar; ver: pointer to store the area of the vertical scrollbar
     * @see lv_obj_get_scrollbar_area
     */
    std::pair<Area, Area> get_scrollbar_area() const noexcept;
    /**
     * Get the current scroll mode (when to hide the scrollbars)
     * @return the current scroll mode from `lv_scrollbar_mode_t`
     * @see lv_obj_get_scrollbar_mode
     */
    ScrollbarMode get_scrollbar_mode() const noexcept;
    /**
     * Get the height occupied by the "parts" of the widget. E.g. the height of all rows of a table.
     * @return the width of the virtually drawn content
     * @see lv_obj_get_self_height
     */
    int32_t get_self_height() const noexcept;
    /**
     * Get the width occupied by the "parts" of the widget. E.g. the width of all columns of a table.
     * @return the width of the virtually drawn content
     * @see lv_obj_get_self_width
     */
    int32_t get_self_width() const noexcept;
    /**
     * Return a sibling of an object
     * @param idx  0: `obj` itself -1: the first older sibling -2: the next older sibling 1: the first younger sibling 2: the next younger sibling etc
     * @return pointer to the requested sibling or NULL if there is no such sibling
     * @see lv_obj_get_sibling
     */
    Obj get_sibling(int32_t idx) const noexcept;
    /**
     * Return a sibling of an object. Consider the siblings only with a given type.
     * @param idx  0: `obj` itself -1: the first older sibling -2: the next older sibling 1: the first younger sibling 2: the next younger sibling etc
     * @param class_p  the type of the children to check
     * @return pointer to the requested sibling or NULL if there is no such sibling
     * @see lv_obj_get_sibling_by_type
     */
    Obj get_sibling_by_type(int32_t idx, ObjClass class_p) const noexcept;
    /**
     * Get the state of an object
     * @return the state (OR-ed values from `lv_state_t`)
     * @see lv_obj_get_state
     */
    State get_state() const noexcept;
    #if LV_USE_MATRIX
    /**
     * Get the transform matrix of an object
     * @return pointer to the transform matrix or NULL if not set
     * @see lv_obj_get_transform
     */
    Matrix get_transform() const noexcept;
    #endif // LV_USE_MATRIX

    /**
     * Transform an area using the angle and zoom style properties of an object
     * @param area  an area to transform, the result will be written back here too
     * @param flags  OR-ed valued of :cpp:enum:`lv_obj_point_transform_flag_t`
     * @see lv_obj_get_transformed_area
     */
    void get_transformed_area(Area& area, ObjPointTransformFlag flags) const noexcept;
    /**
     * Get the user_data field of the object
     * @return the pointer to the user_data of the object
     * @see lv_obj_get_user_data
     */
    void* get_user_data() const noexcept;
    /**
     * Get the width of an object
     * @return the width in pixels
     * @see lv_obj_get_width
     */
    int32_t get_width() const noexcept;
    /**
     * Get the x coordinate of object.
     * @return distance of `obj` from the left side of its parent plus the parent's left padding
     * @see lv_obj_get_x
     */
    int32_t get_x() const noexcept;
    /**
     * Get the x2 coordinate of object.
     * @return distance of `obj` from the right side of its parent plus the parent's right padding
     * @see lv_obj_get_x2
     */
    int32_t get_x2() const noexcept;
    /**
     * Get the actually set x coordinate of object, i.e. the offset from the set alignment
     * @return the set x coordinate
     * @see lv_obj_get_x_aligned
     */
    int32_t get_x_aligned() const noexcept;
    /**
     * Get the y coordinate of object.
     * @return distance of `obj` from the top side of its parent plus the parent's top padding
     * @see lv_obj_get_y
     */
    int32_t get_y() const noexcept;
    /**
     * Get the y2 coordinate of object.
     * @return distance of `obj` from the bottom side of its parent plus the parent's bottom padding
     * @see lv_obj_get_y2
     */
    int32_t get_y2() const noexcept;
    /**
     * Get the actually set y coordinate of object, i.e. the offset from the set alignment
     * @return the set y coordinate
     * @see lv_obj_get_y_aligned
     */
    int32_t get_y_aligned() const noexcept;
    /**
     * Check if any object has a given class (type).
     * It checks the ancestor classes too.
     * @param class_p  a class to check (e.g. `lv_slider_class`)
     * @return true: `obj` has the given class
     * @see lv_obj_has_class
     */
    bool has_class(ObjClass class_p) const noexcept;
    /**
     * Check if a given flag or all the given flags are set on an object.
     * @param f  the flag(s) to check (OR-ed values can be used)
     * @return true: all flags are set; false: not all flags are set
     * @see lv_obj_has_flag
     */
    bool has_flag(ObjFlag f) const noexcept;
    /**
     * Check if a given flag or any of the flags are set on an object.
     * @param f  the flag(s) to check (OR-ed values can be used)
     * @return true: at least one flag is set; false: none of the flags are set
     * @see lv_obj_has_flag_any
     */
    bool has_flag_any(ObjFlag f) const noexcept;
    /**
     * Check if the object is in a given state or not.
     * @param state  a state or combination of states to check
     * @return true: `obj` is in `state`; false: `obj` is not in `state`
     * @see lv_obj_has_state
     */
    bool has_state(State state) const noexcept;
    /**
     * Check if an object has a specified style property for a given style selector.
     * @param selector  the style selector to be checked, defining the scope of the style to be examined.
     * @param prop  the property to be checked.
     * @return true if the object has the specified selector and property, false otherwise.
     * @see lv_obj_has_style_prop
     */
    bool has_style_prop(lv_style_selector_t selector, lv_style_prop_t prop) const noexcept;
    /**
     * Hit-test an object given a particular point in screen space.
     * @param point  screen-space point (absolute coordinate)
     * @return true: if the object is considered under the point
     * @see lv_obj_hit_test
     */
    bool hit_test(const Point& point) const noexcept;
    /**
     * Initialize an arc draw descriptor from an object's styles in its current state
     * @param part  part of the object, e.g. `LV_PART_MAIN`, `LV_PART_SCROLLBAR`, `LV_PART_KNOB`, etc
     * @param draw_dsc  the descriptor to initialize. Should be initialized with `lv_draw_arc_dsc_init(draw_dsc)`.
     * @see lv_obj_init_draw_arc_dsc
     */
    void init_draw_arc_dsc(Part part, DrawArcDsc& draw_dsc) const noexcept;
    /**
     * Initialize a blur draw descriptor from an object's styles in its current state.
     * draw_dsc->radius will only be calculated if it's 0 initially. Radius can be set before calling this function
     * to avoid getting it twice.
     * @param part  part of the object, e.g. `LV_PART_MAIN`, `LV_PART_SCROLLBAR`, `LV_PART_KNOB`, etc
     * @param draw_dsc  the descriptor to initialize. Should be initialized with `lv_draw_blur_dsc_init(draw_dsc)`.
     * @see lv_obj_init_draw_blur_dsc
     */
    void init_draw_blur_dsc(Part part, DrawBlurDsc& draw_dsc) const noexcept;
    /**
     * Initialize an image draw descriptor from an object's styles in its current state
     * @param part  part of the object, e.g. `LV_PART_MAIN`, `LV_PART_SCROLLBAR`, `LV_PART_KNOB`, etc
     * @param draw_dsc  the descriptor to initialize. Should be initialized with `lv_draw_image_dsc_init(draw_dsc)`.
     * @see lv_obj_init_draw_image_dsc
     */
    void init_draw_image_dsc(Part part, DrawImageDsc& draw_dsc) const noexcept;
    /**
     * Initialize a label draw descriptor from an object's styles in its current state
     * @param part  part of the object, e.g. `LV_PART_MAIN`, `LV_PART_SCROLLBAR`, `LV_PART_KNOB`, etc
     * @param draw_dsc  the descriptor to initialize. If the `opa` field is set to or the property is equal to `LV_OPA_TRANSP` the rest won't be initialized. Should be initialized with `lv_draw_label_dsc_init(draw_dsc)`.
     * @see lv_obj_init_draw_label_dsc
     */
    void init_draw_label_dsc(Part part, DrawLabelDsc& draw_dsc) const noexcept;
    /**
     * Initialize a line draw descriptor from an object's styles in its current state
     * @param part  part of the object, e.g. `LV_PART_MAIN`, `LV_PART_SCROLLBAR`, `LV_PART_KNOB`, etc
     * @param draw_dsc  the descriptor to initialize. Should be initialized with `lv_draw_line_dsc_init(draw_dsc)`.
     * @see lv_obj_init_draw_line_dsc
     */
    void init_draw_line_dsc(Part part, DrawLineDsc& draw_dsc) const noexcept;
    /**
     * Initialize a rectangle draw descriptor from an object's styles in its current state
     * @param part  part of the object, e.g. `LV_PART_MAIN`, `LV_PART_SCROLLBAR`, `LV_PART_KNOB`, etc
     * @param draw_dsc  the descriptor to initialize. If an `..._opa` field is set to `LV_OPA_TRANSP` the related properties won't be initialized. Should be initialized with `lv_draw_rect_dsc_init(draw_dsc)`.
     * @see lv_obj_init_draw_rect_dsc
     */
    void init_draw_rect_dsc(Part part, DrawRectDsc& draw_dsc) const noexcept;
    /**
     * Mark the object as invalid to redrawn its area
     * @return LV_RESULT_OK: the area is invalidated; LV_RESULT_INVALID: the area wasn't invalidated. (maybe it was off-screen or fully clipped)
     * @see lv_obj_invalidate
     */
    Result invalidate() const noexcept;
    /**
     * Mark an area of an object as invalid.
     * The area will be truncated to the object's area and marked for redraw.
     * @param area  the area to redraw
     * @return LV_RESULT_OK: the area is invalidated; LV_RESULT_INVALID: the area wasn't invalidated. (maybe it was off-screen or fully clipped)
     * @see lv_obj_invalidate_area
     */
    Result invalidate_area(const Area& area) const noexcept;
    /** @see lv_obj_is_editable */
    bool is_editable() const noexcept;
    /** @see lv_obj_is_group_def */
    bool is_group_def() const noexcept;
    /**
     * Determine if the object's resolved height was limited by its maximum height constraint.
     * This function reports whether, in the most recent layout / size calculation, the object's
     * final (used) height had to be raised to satisfy a maximum height requirement.
     * @return true The computed height == the effective maximum height (i.e. it was clamped). false The height is smaller than the maximum (not min‑clamped).
     * @see lv_obj_is_height_max
     */
    bool is_height_max() const noexcept;
    /**
     * Determine if the object's resolved height was limited by its minimum height constraint.
     * This function reports whether, in the most recent layout / size calculation, the object's
     * final (used) height had to be raised to satisfy a minimum height requirement.
     * @return true The computed height == the effective minimum height (i.e. it was clamped). false The height is larger than the minimum (not min‑clamped).
     * @see lv_obj_is_height_min
     */
    bool is_height_min() const noexcept;
    /**
     * Test whether the and object is positioned by a layout or not
     * @return true: positioned by a layout; false: not positioned by a layout
     * @see lv_obj_is_layout_positioned
     */
    bool is_layout_positioned() const noexcept;
    /**
     * Get whether the object is a radio button
     * @return true if radio button behavior is enabled
     * @see lv_obj_is_radio_button
     */
    bool is_radio_button() const noexcept;
    /**
     * Tell whether Widget is being scrolled or not at this moment
     * @return true: `obj` is being scrolled
     * @see lv_obj_is_scrolling
     */
    bool is_scrolling() const noexcept;
    /**
     * Determine if any of the object's height style properties are set to `LV_SIZE_CONTENT`.
     * @return `true` At least one of the following height style properties is `LV_SIZE_CONTENT`: `LV_STYLE_HEIGHT`, `LV_STYLE_MIN_HEIGHT`, `LV_STYLE_MAX_HEIGHT`. `false` No height style properties are `LV_SIZE_CONTENT`.
     * @see lv_obj_is_style_any_height_content
     */
    bool is_style_any_height_content() const noexcept;
    /**
     * Determine if any of the object's width style properties are set to `LV_SIZE_CONTENT`.
     * @return `true` At least one of the following width style properties is `LV_SIZE_CONTENT`: `LV_STYLE_WIDTH`, `LV_STYLE_MIN_WIDTH`, `LV_STYLE_MAX_WIDTH`. `false` No width style properties are `LV_SIZE_CONTENT`.
     * @see lv_obj_is_style_any_width_content
     */
    bool is_style_any_width_content() const noexcept;
    /**
     * Check if any object is still "alive".
     * @return true: valid
     * @see lv_obj_is_valid
     */
    bool is_valid() const noexcept;
    /**
     * Tell whether an object is visible (even partially) now or not
     * @return true: visible; false not visible (hidden, out of parent, on other screen, etc)
     * @see lv_obj_is_visible
     */
    bool is_visible() const noexcept;
    /**
     * Determine if the object's resolved width was limited by its maximum width constraint.
     * This function reports whether, in the most recent layout / size calculation, the object's
     * final (used) width had to be raised to satisfy a maximum width requirement.
     * @return true The computed width == the effective maximum width (i.e. it was clamped). false The width is smaller than the maximum (not min‑clamped).
     * @see lv_obj_is_width_max
     */
    bool is_width_max() const noexcept;
    /**
     * Determine if the object's resolved width was limited by its minimum width constraint.
     * This function reports whether, in the most recent layout / size calculation, the object's
     * final (used) width had to be raised to satisfy a minimum width requirement.
     * @return true The computed width == the effective minimum width (i.e. it was clamped). false The width is larger than the minimum (not min‑clamped).
     * @see lv_obj_is_width_min
     */
    bool is_width_min() const noexcept;
    /**
     * Mark the object for layout update.
     * @see lv_obj_mark_layout_as_dirty
     */
    void mark_layout_as_dirty() const noexcept;
    #if LVPP_COMPAT_V8
    /**
     * Move the object to the background.
     * It will look like if it was created as the first child of its parent.
     * It also means any of the siblings can cover the object.
     * @see lv_obj_move_background
     */
    void move_background() const noexcept;
    #endif // LVPP_COMPAT_V8

    /** @see lv_obj_move_children_by */
    void move_children_by(int32_t x_diff, int32_t y_diff, bool ignore_floating) const noexcept;
    #if LVPP_COMPAT_V8
    /**
     * Move the object to the foreground.
     * It will look like if it was created as the last child of its parent.
     * It also means it can cover any of the siblings.
     * @see lv_obj_move_foreground
     */
    void move_foreground() const noexcept;
    #endif // LVPP_COMPAT_V8

    /** @see lv_obj_move_to */
    void move_to(int32_t x, int32_t y) const noexcept;
    /**
     * moves the object to the given index in its parent.
     * When used in listboxes, it can be used to sort the listbox items.
     * @param index  new index in parent. -1 to count from the back
     * @see lv_obj_move_to_index
     */
    void move_to_index(int32_t index) const noexcept;
    /**
     * Checks if the content is scrolled "in" and adjusts it to a normal position.
     * @param anim_en  LV_ANIM_ON/OFF
     * @see lv_obj_readjust_scroll
     */
    void readjust_scroll(lv_anim_enable_t anim_en) const noexcept;
    /** @see lv_obj_refr_pos */
    void refr_pos() const noexcept;
    /**
     * Recalculate the size of the object
     * @return true: the size has been changed
     * @see lv_obj_refr_size
     */
    bool refr_size() const noexcept;
    /**
     * Send a 'LV_EVENT_REFR_EXT_DRAW_SIZE' Call the ancestor's event handler to the object to refresh the value of the extended draw size.
     * The result will be saved in `obj`.
     * @see lv_obj_refresh_ext_draw_size
     */
    void refresh_ext_draw_size() const noexcept;
    /**
     * Handle if the size of the internal ("virtual") content of an object has changed.
     * @return false: nothing happened; true: refresh happened
     * @see lv_obj_refresh_self_size
     */
    bool refresh_self_size() const noexcept;
    /**
     * Notify an object and its children about its style is modified.
     * @param part  the part whose style was changed. E.g. `LV_PART_ANY`, `LV_PART_MAIN`
     * @param prop  `LV_STYLE_PROP_ANY` or an `LV_STYLE_...` property. It is used to optimize what needs to be refreshed. `LV_STYLE_PROP_INV` to perform only a style cache update
     * @see lv_obj_refresh_style
     */
    void refresh_style(Part part, lv_style_prop_t prop) const noexcept;
    /** @see lv_obj_remove_event */
    bool remove_event(uint32_t index) const noexcept;
    /**
     * Remove an event_cb from an object
     * @param event_cb  the event_cb of the event to remove
     * @return the count of the event removed
     * @see lv_obj_remove_event_cb
     */
    uint32_t remove_event_cb(lv_event_cb_t event_cb) const noexcept;
    /**
     * Remove an event_cb with user_data
     * @param event_cb  the event_cb of the event to remove
     * @param user_data  user_data
     * @return the count of the event removed
     * @see lv_obj_remove_event_cb_with_user_data
     */
    uint32_t remove_event_cb_with_user_data(lv_event_cb_t event_cb, void* user_data) const noexcept;
    /** @see lv_obj_remove_event_dsc */
    bool remove_event_dsc(EventDsc dsc) const noexcept;
    /**
     * Remove one or more flags
     * @param f  OR-ed values from `lv_obj_flag_t` to clear.
     * @see lv_obj_remove_flag
     */
    void remove_flag(ObjFlag f) const noexcept;
    #if LV_USE_OBSERVER
    /**
     * Remove Observers associated with Widget `obj` from specified `subject` or all Subjects.
     * @param subject  Subject to remove Widget from, or NULL to remove from all Subjects
     * @see lv_obj_remove_from_subject
     */
    void remove_from_subject(Subject& subject) const noexcept;
    #endif // LV_USE_OBSERVER

    /**
     * Remove a local style property from a part of an object with a given state.
     * @param prop  a style property to remove.
     * @param selector  OR-ed value of parts and state for which the style should be removed
     * @return true the property was found and removed; false: the property was not found
     * @see lv_obj_remove_local_style_prop
     */
    bool remove_local_style_prop(lv_style_prop_t prop, lv_style_selector_t selector) const noexcept;
    /**
     * Remove one or more states to the object. The other state bits will remain unchanged.
     * If specified in the styles, transition animation will be started from the previous state to the current.
     * @param state  the states to add. E.g `LV_STATE_PRESSED | LV_STATE_FOCUSED`
     * @see lv_obj_remove_state
     */
    void remove_state(State state) const noexcept;
    /**
     * Remove a style from an object.
     * @param style  pointer to a style to remove. Can be NULL to check only the selector
     * @see lv_obj_remove_style
     */
    void remove_style(Style& style, lv_style_selector_t selector) const noexcept;
    /**
     * Remove all styles from an object
     * @see lv_obj_remove_style_all
     */
    void remove_style_all() const noexcept;
    /**
     * Remove all styles added by a theme from a widget
     * @param selector  OR-ed values of states and a part to remove only styles with matching selectors. LV_STATE_ANY and LV_PART_ANY can be used
     * @see lv_obj_remove_theme
     */
    void remove_theme(lv_style_selector_t selector) const noexcept;
    /**
     * Replaces a style of an object, preserving the order of the style stack (local styles and transitions are ignored).
     * @param old_style  pointer to a style to replace.
     * @param new_style  pointer to a style to replace the old style with.
     * @see lv_obj_replace_style
     */
    bool replace_style(Style& old_style, Style& new_style, lv_style_selector_t selector) const noexcept;
    /**
     * Reset the transform matrix of an object to identity matrix
     * @see lv_obj_reset_transform
     */
    void reset_transform() const noexcept;
    /**
     * Invalidate the area of the scrollbars
     * @see lv_obj_scrollbar_invalidate
     */
    void scrollbar_invalidate() const noexcept;
    /**
     * Change the alignment of an object.
     * @param align  type of alignment (see 'lv_align_t' enum) `LV_ALIGN_OUT_...` can't be used.
     * @see lv_obj_set_align
     */
    void set_align(Align align) const noexcept;
    /**
     * Set the height reduced by the top and bottom padding and the border width.
     * @param h  the height without paddings in pixels
     * @see lv_obj_set_content_height
     */
    void set_content_height(int32_t h) const noexcept;
    /**
     * Set the width reduced by the left and right padding and the border width.
     * @param w  the width without paddings in pixels
     * @see lv_obj_set_content_width
     */
    void set_content_width(int32_t w) const noexcept;
    /**
     * Set the size of an extended clickable area
     * @param size  extended clickable area in all 4 directions [px]
     * @see lv_obj_set_ext_click_area
     */
    void set_ext_click_area(int32_t size) const noexcept;
    #if LV_USE_EXT_DATA
    /**
     * Associates an array of external data pointers with an LVGL object
     * Associates custom user data with an LVGL object and specifies a destructor function
     * that will be automatically invoked when the object is deleted to properly clean up
     * the associated resources.
     * @param data  User-defined data pointer to associate with a object
     * @see lv_obj_set_external_data
     */
    void set_external_data(void* data, void (*arg)(void*)) const noexcept;
    /**
     * Takes the function itself as a template argument, so its real parameter types survive: the C idiom CASTS the pointer, which is undefined whenever they differ, and between the versions they do.
     * Associates an array of external data pointers with an LVGL object
     * Associates custom user data with an LVGL object and specifies a destructor function
     * that will be automatically invoked when the object is deleted to properly clean up
     * the associated resources.
     * @param data  User-defined data pointer to associate with a object
     * @see lv_obj_set_external_data
     */
    template <auto Fn>
    void set_external_data(void* data) const noexcept;
    #endif // LV_USE_EXT_DATA

    /**
     * Set add or remove one or more flags.
     * @param f  OR-ed values from `lv_obj_flag_t` to update.
     * @param v  true: add the flags; false: remove the flags
     * @see lv_obj_set_flag
     */
    void set_flag(ObjFlag f, bool v) const noexcept;
    #if LV_USE_FLEX
    /**
     * Set how to place (where to align) the items and tracks
     * @param main_place  where to place the items on main axis (in their track). Any value of `lv_flex_align_t`.
     * @param cross_place  where to place the item in their track on the cross axis. `LV_FLEX_ALIGN_START/END/CENTER`
     * @param track_cross_place  where to place the tracks in the cross direction. Any value of `lv_flex_align_t`.
     * @see lv_obj_set_flex_align
     */
    void set_flex_align(FlexAlign main_place, FlexAlign cross_place, FlexAlign track_cross_place) const noexcept;
    /**
     * Set how the item should flow
     * @param flow  an element of `lv_flex_flow_t`.
     * @see lv_obj_set_flex_flow
     */
    void set_flex_flow(FlexFlow flow) const noexcept;
    /**
     * Sets the width or height (on main axis) to grow the object in order fill the free space
     * @param grow  a value to set how much free space to take proportionally to other growing items.
     * @see lv_obj_set_flex_grow
     */
    void set_flex_grow(uint8_t grow) const noexcept;
    #endif // LV_USE_FLEX

    #if LV_USE_GRID
    /** @see lv_obj_set_grid_align */
    void set_grid_align(GridAlign column_align, GridAlign row_align) const noexcept;
    /**
     * Set the cell of an object. The object's parent needs to have grid layout, else nothing will happen
     * @param column_align  the vertical alignment in the cell. `LV_GRID_START/END/CENTER/STRETCH`
     * @param col_pos  column ID
     * @param col_span  number of columns to take (>= 1)
     * @param row_align  the horizontal alignment in the cell. `LV_GRID_START/END/CENTER/STRETCH`
     * @param row_pos  row ID
     * @param row_span  number of rows to take (>= 1)
     * @see lv_obj_set_grid_cell
     */
    void set_grid_cell(GridAlign column_align, int32_t col_pos, int32_t col_span, GridAlign row_align, int32_t row_pos, int32_t row_span) const noexcept;
    /**
     * LVGL keeps this pointer and reads until it finds LV_GRID_TEMPLATE_LAST: the type writes the sentinel, and the rvalue overload is deleted so it cannot be a temporary.
     * LVGL keeps this pointer and reads until it finds LV_GRID_TEMPLATE_LAST: the type writes the sentinel, and the rvalue overload is deleted so it cannot be a temporary.
     * @see lv_obj_set_grid_dsc_array
     */
    template <std::size_t N1, std::size_t N2>
    void set_grid_dsc_array(const GridTemplate<N1>& col_dsc, const GridTemplate<N2>& row_dsc) const noexcept;
    /** Refused: LVGL keeps the pointer, so this argument may not be a temporary. */
    template <std::size_t N1, std::size_t N2>
    void set_grid_dsc_array(GridTemplate<N1>&& col_dsc, const GridTemplate<N2>& row_dsc) const noexcept = delete;
    /** Refused: LVGL keeps the pointer, so this argument may not be a temporary. */
    template <std::size_t N1, std::size_t N2>
    void set_grid_dsc_array(const GridTemplate<N1>& col_dsc, GridTemplate<N2>&& row_dsc) const noexcept = delete;
    #endif // LV_USE_GRID

    /**
     * Set the height of an object
     * @param h  the new height
     * @see lv_obj_set_height
     */
    void set_height(int32_t h) const noexcept;
    #if LV_USE_OBJ_ID
    /**
     * Set an id for an object.
     * @param id  the id of the object
     * @see lv_obj_set_id
     */
    void set_id(void* id) const noexcept;
    #endif // LV_USE_OBJ_ID

    /**
     * Set a layout for an object
     * @param layout  pointer to a layout descriptor to set
     * @see lv_obj_set_layout
     */
    void set_layout(uint32_t layout) const noexcept;
    /**
     * Set local style property on an object's part and state.
     * @param prop  the property
     * @param value  value of the property. The correct element should be set according to the type of the property
     * @param selector  OR-ed value of parts and state for which the style should be set
     * @see lv_obj_set_local_style_prop
     */
    void set_local_style_prop(lv_style_prop_t prop, lv_style_value_t value, lv_style_selector_t selector) const noexcept;
    #if LV_USE_OBJ_NAME
    /**
     * Set a name for a widget. The name will be allocated and freed when the
     * widget is deleted or a new name is set.
     * @param name  the name to set. If set to `NULL` the default "<widget_type>_#" name will be used.
     * @see lv_obj_set_name
     */
    void set_name(const char* name) const noexcept;
    /**
     * Set a name for a widget. Only a pointer will be saved.
     * @param name  the name to set. If set to `NULL` the default "<widget_type>_#" name will be used.
     * @see lv_obj_set_name_static
     */
    void set_name_static(const char* name) const noexcept;
    #endif // LV_USE_OBJ_NAME

    /**
     * Move the parent of an object. The relative coordinates will be kept.
     * @param parent  pointer to the new parent
     * @see lv_obj_set_parent
     */
    void set_parent(Obj parent) const noexcept;
    /**
     * Set the position of an object relative to the set alignment.
     * @param x  new x coordinate
     * @param y  new y coordinate
     * @see lv_obj_set_pos
     */
    void set_pos(int32_t x, int32_t y) const noexcept;
    #if LV_USE_OBJ_PROPERTY
    /**
     * Set multiple Widget properties. Helper `LV_OBJ_SET_PROPERTY_ARRAY` can be used for constant property array.
     * @param value  property value array to set
     * @param count  number of array elements
     * @return return LV_RESULT_OK if call succeeded
     * @see lv_obj_set_properties
     */
    Result set_properties(const lv_property_t* value, uint32_t count) const noexcept;
    /**
     * Set Widget property.
     * @param value  property value to set
     * @return return LV_RESULT_OK if call succeeded
     * @see lv_obj_set_property
     */
    Result set_property(const lv_property_t* value) const noexcept;
    #endif // LV_USE_OBJ_PROPERTY

    /**
     * Allow only one RADIO_BUTTON sibling to be checked
     * @param en  enable or disable radio button behavior
     * @see lv_obj_set_radio_button
     */
    void set_radio_button(bool en) const noexcept;
    /**
     * Set direction Widget can be scrolled
     * @param dir  one or more bit-wise OR-ed values of `lv_dir_t` enumeration
     * @see lv_obj_set_scroll_dir
     */
    void set_scroll_dir(Dir dir) const noexcept;
    /**
     * Set where to snap the children when scrolling ends horizontally
     * @param align  value from `lv_scroll_snap_t` enumeration
     * @see lv_obj_set_scroll_snap_x
     */
    void set_scroll_snap_x(ScrollSnap align) const noexcept;
    /**
     * Set where to snap the children when scrolling ends vertically
     * @param align  value from `lv_scroll_snap_t` enumeration
     * @see lv_obj_set_scroll_snap_y
     */
    void set_scroll_snap_y(ScrollSnap align) const noexcept;
    /**
     * Set how the scrollbars should behave.
     * @param mode  LV_SCROLL_MODE_ON/OFF/AUTO/ACTIVE
     * @see lv_obj_set_scrollbar_mode
     */
    void set_scrollbar_mode(ScrollbarMode mode) const noexcept;
    /**
     * Set the size of an object.
     * @param w  the new width
     * @param h  the new height
     * @see lv_obj_set_size
     */
    void set_size(int32_t w, int32_t h) const noexcept;
    /**
     * Add or remove one or more states to the object. The other state bits will remain unchanged.
     * @param state  the states to add. E.g `LV_STATE_PRESSED | LV_STATE_FOCUSED`
     * @param v  true: add the states; false: remove the states
     * @see lv_obj_set_state
     */
    void set_state(State state, bool v) const noexcept;
    #if LV_USE_MATRIX
    /**
     * Set the transform matrix of an object
     * @param matrix  pointer to a matrix to set
     * @see lv_obj_set_transform
     */
    void set_transform(Matrix matrix) const noexcept;
    #endif // LV_USE_MATRIX

    /**
     * Set the user_data field of the object
     * @param user_data  pointer to the new user_data.
     * @see lv_obj_set_user_data
     */
    void set_user_data(void* user_data) const noexcept;
    /**
     * Set the width of an object
     * @param w  the new width
     * @see lv_obj_set_width
     */
    void set_width(int32_t w) const noexcept;
    /**
     * Set the x coordinate of an object
     * @param x  new x coordinate
     * @see lv_obj_set_x
     */
    void set_x(int32_t x) const noexcept;
    /**
     * Set the y coordinate of an object
     * @param y  new y coordinate
     * @see lv_obj_set_y
     */
    void set_y(int32_t y) const noexcept;
    /**
     * Stop scrolling the current object
     * @see lv_obj_stop_scroll_anim
     */
    void stop_scroll_anim() const noexcept;
    #if LV_USE_OBJ_ID
    /**
     * Format an object's id into a string.
     * @param buf  buffer to write the string into
     * @param len  length of the buffer
     * @see lv_obj_stringify_id
     */
    const char* stringify_id(char* buf, uint32_t len) const noexcept;
    #endif // LV_USE_OBJ_ID

    /**
     * Swap the positions of two objects.
     * When used in listboxes, it can be used to sort the listbox items.
     * @param obj2  pointer to the second object
     * @see lv_obj_swap
     */
    void swap(Obj obj2) const noexcept;
    /**
     * Transform a point using the angle and zoom style properties of an object
     * @param p  a point to transform, the result will be written back here too
     * @param flags  OR-ed valued of :cpp:enum:`lv_obj_point_transform_flag_t`
     * @see lv_obj_transform_point
     */
    void transform_point(Point& p, ObjPointTransformFlag flags) const noexcept;
    /**
     * Transform an array of points using the angle and zoom style properties of an object
     * @param points  the array of points to transform, the result will be written back here too
     * @param count  number of points in the array
     * @param flags  OR-ed valued of :cpp:enum:`lv_obj_point_transform_flag_t`
     * @see lv_obj_transform_point_array
     */
    void transform_point_array(Point& points, size_t count, ObjPointTransformFlag flags) const noexcept;
    /**
     * Update the layout of an object.
     * @see lv_obj_update_layout
     */
    void update_layout() const noexcept;
    /**
     * Check children of `obj` and scroll `obj` to fulfill scroll_snap settings.
     * @param anim_en  LV_ANIM_ON/OFF
     * @see lv_obj_update_snap
     */
    void update_snap(lv_anim_enable_t anim_en) const noexcept;
    /**
     * The local style of one (part, state). The proxy is two words and
     * never escapes, so writing the selector once costs nothing.
     */
    LocalStyle style(Selector sel) const noexcept;
    /**
     * Get the style width actually used by the object after clamping the width within the min max range.
     * @return the min/max/normal width set by `lv_obj_set_style_<min/max>_width()`
     * @see lv_obj_get_style_clamped_width
     */
    int32_t get_style_clamped_width() const noexcept;
    /**
     * Get the style height actually used by the object after clamping the height within the min max range.
     * @return the min/max/normal height set by `lv_obj_set_style_<min/max>_height()`
     * @see lv_obj_get_style_clamped_height
     */
    int32_t get_style_clamped_height() const noexcept;
    #if LV_USE_OBJ_PROPERTY
    /**
     * Read style property value from Widget
     * @param id  ID of style property
     * @param part  part for which the style property should be computed
     * @return return property value read. The returned property ID is set to `LV_PROPERTY_ID_INVALID` if read failed.
     * @see lv_obj_get_style_property
     */
    lv_property_t get_style_property(lv_prop_id_t id, Part part) const noexcept;
    #endif // LV_USE_OBJ_PROPERTY

    /**
     * Get the value of a style property. The current state of the object will be considered.
     * Inherited properties will be inherited.
     * If a property is not set a default value will be returned.
     * @param part  a part from which the property should be get
     * @param prop  the property to get
     * @return the value of the property. Should be read from the correct field of the `lv_style_value_t` according to the type of the property.
     * @see lv_obj_get_style_prop
     */
    lv_style_value_t get_style_prop(Part part, lv_style_prop_t prop) const noexcept;
    /** @see lv_obj_get_style_space_left */
    int32_t get_style_space_left(Part part) const noexcept;
    /** @see lv_obj_get_style_space_right */
    int32_t get_style_space_right(Part part) const noexcept;
    /** @see lv_obj_get_style_space_top */
    int32_t get_style_space_top(Part part) const noexcept;
    /** @see lv_obj_get_style_space_bottom */
    int32_t get_style_space_bottom(Part part) const noexcept;
    /** @see lv_obj_get_style_transform_scale_x_safe */
    int32_t get_style_transform_scale_x_safe(Part part) const noexcept;
    /** @see lv_obj_get_style_transform_scale_y_safe */
    int32_t get_style_transform_scale_y_safe(Part part) const noexcept;
    /**
     * Get the `opa` style property from all parents and multiply and `>> 8` them.
     * @param part  the part whose opacity should be get. Non-MAIN parts will consider the `opa` of the MAIN part too
     * @return the final opacity considering the parents' opacity too
     * @see lv_obj_get_style_opa_recursive
     */
    lv_opa_t get_style_opa_recursive(Part part) const noexcept;
    /**
     * Get the `recolor` style property from all parents and blend them recursively.
     * @param part  the target part to check. Non-MAIN parts will also consider the `recolor` value from the MAIN part during calculation
     * @return the final blended recolor value combining all parent's recolor values
     * @see lv_obj_get_style_recolor_recursive
     */
    lv_color32_t get_style_recolor_recursive(Part part) const noexcept;
    /**
     * Gets width of Widget. Pixel, percentage and `LV_SIZE_CONTENT` values can be used.
     * Percentage values are relative to the width of the parent's content area.
     * Default: Widget dependent, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_width
     */
    int32_t get_style_width(Part part) const noexcept;
    /**
     * Gets a minimal width. Pixel and percentage values can be used. Percentage values
     * are relative to the width of the parent's content area.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_min_width
     */
    int32_t get_style_min_width(Part part) const noexcept;
    /**
     * Gets a maximal width. Pixel and percentage values can be used. Percentage values
     * are relative to the width of the parent's content area.
     * Default: LV_COORD_MAX, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_max_width
     */
    int32_t get_style_max_width(Part part) const noexcept;
    /**
     * Gets height of Widget. Pixel, percentage and `LV_SIZE_CONTENT` can be used.
     * Percentage values are relative to the height of the parent's content area.
     * Default: Widget dependent, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_height
     */
    int32_t get_style_height(Part part) const noexcept;
    /**
     * Gets a minimal height. Pixel and percentage values can be used. Percentage values
     * are relative to the height of the parent's content area.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_min_height
     */
    int32_t get_style_min_height(Part part) const noexcept;
    /**
     * Gets a maximal height. Pixel and percentage values can be used. Percentage values
     * are relative to the height of the parent's content area.
     * Default: LV_COORD_MAX, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_max_height
     */
    int32_t get_style_max_height(Part part) const noexcept;
    /**
     * Its meaning depends on the type of Widget. For example in case of lv_scale it means
     * the length of the ticks.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_length
     */
    int32_t get_style_length(Part part) const noexcept;
    /**
     * Get X coordinate of Widget considering the ``align`` setting. Pixel and percentage
     * values can be used. Percentage values are relative to the width of the parent's
     * content area.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_x
     */
    int32_t get_style_x(Part part) const noexcept;
    /**
     * Get Y coordinate of Widget considering the ``align`` setting. Pixel and percentage
     * values can be used. Percentage values are relative to the height of the parent's
     * content area.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_y
     */
    int32_t get_style_y(Part part) const noexcept;
    /**
     * Get the alignment which tells from which point of the parent the X and Y
     * coordinates should be interpreted. Possible values are: `LV_ALIGN_DEFAULT`,
     * `LV_ALIGN_TOP_LEFT/MID/RIGHT`, `LV_ALIGN_BOTTOM_LEFT/MID/RIGHT`,
     * `LV_ALIGN_LEFT/RIGHT_MID`, `LV_ALIGN_CENTER`. `LV_ALIGN_DEFAULT` means
     * `LV_ALIGN_TOP_LEFT` with LTR base direction and `LV_ALIGN_TOP_RIGHT` with RTL base
     * direction.
     * Default: `LV_ALIGN_DEFAULT`, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_align
     */
    Align get_style_align(Part part) const noexcept;
    /**
     * Make Widget wider on both sides with this value. Pixel and percentage (with
     * `lv_pct(x)`) values can be used. Percentage values are relative to Widget's width.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_transform_width
     */
    int32_t get_style_transform_width(Part part) const noexcept;
    /**
     * Make Widget higher on both sides with this value. Pixel and percentage (with
     * `lv_pct(x)`) values can be used. Percentage values are relative to Widget's height.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_transform_height
     */
    int32_t get_style_transform_height(Part part) const noexcept;
    /**
     * Move Widget with this value in X direction. Applied after layouts, aligns and other
     * positioning. Pixel and percentage (with `lv_pct(x)`) values can be used. Percentage
     * values are relative to Widget's width.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_translate_x
     */
    int32_t get_style_translate_x(Part part) const noexcept;
    /**
     * Move Widget with this value in Y direction. Applied after layouts, aligns and other
     * positioning. Pixel and percentage (with `lv_pct(x)`) values can be used. Percentage
     * values are relative to Widget's height.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_translate_y
     */
    int32_t get_style_translate_y(Part part) const noexcept;
    /**
     * Move object around the centre of the parent object (e.g. around the circumference
     * of a scale).
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_translate_radial
     */
    int32_t get_style_translate_radial(Part part) const noexcept;
    /**
     * Zoom Widget horizontally. The value 256 (or `LV_SCALE_NONE`) means normal size, 128
     * half size, 512 double size, and so on.
     * Default: 0, inherited: No, layout: Yes, ext. draw: Yes.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_transform_scale_x
     */
    int32_t get_style_transform_scale_x(Part part) const noexcept;
    /**
     * Zoom Widget vertically. The value 256 (or `LV_SCALE_NONE`) means normal size, 128
     * half size, 512 double size, and so on.
     * Default: 0, inherited: No, layout: Yes, ext. draw: Yes.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_transform_scale_y
     */
    int32_t get_style_transform_scale_y(Part part) const noexcept;
    /**
     * Rotate Widget. The value is interpreted in 0.1 degree units. E.g. 450 means 45 deg.
     * Default: 0, inherited: No, layout: Yes, ext. draw: Yes.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_transform_rotation
     */
    int32_t get_style_transform_rotation(Part part) const noexcept;
    /**
     * Get pivot point's X coordinate for transformations. Relative to Widget's top left corner.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_transform_pivot_x
     */
    int32_t get_style_transform_pivot_x(Part part) const noexcept;
    /**
     * Get pivot point's Y coordinate for transformations. Relative to Widget's top left corner.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_transform_pivot_y
     */
    int32_t get_style_transform_pivot_y(Part part) const noexcept;
    /**
     * Skew Widget horizontally. The value is interpreted in 0.1 degree units. E.g. 450
     * means 45 deg.
     * Default: 0, inherited: No, layout: Yes, ext. draw: Yes.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_transform_skew_x
     */
    int32_t get_style_transform_skew_x(Part part) const noexcept;
    /**
     * Skew Widget vertically. The value is interpreted in 0.1 degree units. E.g. 450
     * means 45 deg.
     * Default: 0, inherited: No, layout: Yes, ext. draw: Yes.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_transform_skew_y
     */
    int32_t get_style_transform_skew_y(Part part) const noexcept;
    /**
     * Gets the padding on the top. It makes the content area smaller in this direction.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_pad_top
     */
    int32_t get_style_pad_top(Part part) const noexcept;
    /**
     * Gets the padding on the bottom. It makes the content area smaller in this direction.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_pad_bottom
     */
    int32_t get_style_pad_bottom(Part part) const noexcept;
    /**
     * Gets the padding on the left. It makes the content area smaller in this direction.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_pad_left
     */
    int32_t get_style_pad_left(Part part) const noexcept;
    /**
     * Gets the padding on the right. It makes the content area smaller in this direction.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_pad_right
     */
    int32_t get_style_pad_right(Part part) const noexcept;
    /**
     * Gets the padding between the rows. Used by the layouts.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_pad_row
     */
    int32_t get_style_pad_row(Part part) const noexcept;
    /**
     * Gets the padding between the columns. Used by the layouts.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_pad_column
     */
    int32_t get_style_pad_column(Part part) const noexcept;
    /**
     * Pad text labels away from the scale ticks/remainder of the ``LV_PART_``.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_pad_radial
     */
    int32_t get_style_pad_radial(Part part) const noexcept;
    /**
     * Gets margin on the top. Widget will keep this space from its siblings in layouts.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_margin_top
     */
    int32_t get_style_margin_top(Part part) const noexcept;
    /**
     * Gets margin on the bottom. Widget will keep this space from its siblings in layouts.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_margin_bottom
     */
    int32_t get_style_margin_bottom(Part part) const noexcept;
    /**
     * Gets margin on the left. Widget will keep this space from its siblings in layouts.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_margin_left
     */
    int32_t get_style_margin_left(Part part) const noexcept;
    /**
     * Gets margin on the right. Widget will keep this space from its siblings in layouts.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_margin_right
     */
    int32_t get_style_margin_right(Part part) const noexcept;
    /**
     * Get background color of Widget.
     * Default: `0xffffff`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_bg_color
     */
    Color get_style_bg_color(Part part) const noexcept;
    /**
     * Get background color of Widget.
     * Default: `0xffffff`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_bg_color_filtered
     */
    Color get_style_bg_color_filtered(Part part) const noexcept;
    /**
     * Get opacity of the background. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means fully
     * transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means fully covering, other values
     * or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_TRANSP`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_bg_opa
     */
    lv_opa_t get_style_bg_opa(Part part) const noexcept;
    /**
     * Get gradient color of the background. Used only if `grad_dir` is not `LV_GRAD_DIR_NONE`.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_bg_grad_color
     */
    Color get_style_bg_grad_color(Part part) const noexcept;
    /**
     * Get gradient color of the background. Used only if `grad_dir` is not `LV_GRAD_DIR_NONE`.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_bg_grad_color_filtered
     */
    Color get_style_bg_grad_color_filtered(Part part) const noexcept;
    /**
     * Get direction of the gradient of the background. Possible values are
     * `LV_GRAD_DIR_NONE/HOR/VER`.
     * Default: `LV_GRAD_DIR_NONE`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_bg_grad_dir
     */
    GradDir get_style_bg_grad_dir(Part part) const noexcept;
    /**
     * Get point from which background color should start for gradients. 0 means to
     * top/left side, 255 the bottom/right side, 128 the center, and so on.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_bg_main_stop
     */
    int32_t get_style_bg_main_stop(Part part) const noexcept;
    /**
     * Get point from which background's gradient color should start. 0 means to top/left
     * side, 255 the bottom/right side, 128 the center, and so on.
     * Default: 255, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_bg_grad_stop
     */
    int32_t get_style_bg_grad_stop(Part part) const noexcept;
    /**
     * Get opacity of the first gradient color.
     * Default: 255, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_bg_main_opa
     */
    lv_opa_t get_style_bg_main_opa(Part part) const noexcept;
    /**
     * Get opacity of the second gradient color.
     * Default: 255, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_bg_grad_opa
     */
    lv_opa_t get_style_bg_grad_opa(Part part) const noexcept;
    /**
     * Get gradient definition. The pointed instance must exist while Widget is alive.
     * NULL to disable. It wraps `BG_GRAD_COLOR`, `BG_GRAD_DIR`, `BG_MAIN_STOP` and
     * `BG_GRAD_STOP` into one descriptor and allows creating gradients with more colors
     * as well. If it's set other gradient related properties will be ignored.
     * Default: `NULL`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_bg_grad
     */
    const lv_grad_dsc_t* get_style_bg_grad(Part part) const noexcept;
    /**
     * Get a background image. Can be a pointer to `lv_image_dsc_t`, a path to a file or
     * an `LV_SYMBOL_...`.
     * Default: `NULL`, inherited: No, layout: No, ext. draw: Yes.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_bg_image_src
     */
    const void* get_style_bg_image_src(Part part) const noexcept;
    /**
     * Get opacity of the background image. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means
     * fully transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means fully covering, other
     * values or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_bg_image_opa
     */
    lv_opa_t get_style_bg_image_opa(Part part) const noexcept;
    /**
     * Get a color to mix to the background image.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_bg_image_recolor
     */
    Color get_style_bg_image_recolor(Part part) const noexcept;
    /**
     * Get a color to mix to the background image.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_bg_image_recolor_filtered
     */
    Color get_style_bg_image_recolor_filtered(Part part) const noexcept;
    /**
     * Get intensity of background image recoloring. Value 0, `LV_OPA_0` or
     * `LV_OPA_TRANSP` means no mixing, 255, `LV_OPA_100` or `LV_OPA_COVER` means full
     * recoloring, other values or LV_OPA_10, LV_OPA_20, etc are interpreted
     * proportionally.
     * Default: `LV_OPA_TRANSP`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_bg_image_recolor_opa
     */
    lv_opa_t get_style_bg_image_recolor_opa(Part part) const noexcept;
    /**
     * If enabled the background image will be tiled. Possible values are `true` or `false`.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_bg_image_tiled
     */
    bool get_style_bg_image_tiled(Part part) const noexcept;
    /**
     * Get color of the border.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_border_color
     */
    Color get_style_border_color(Part part) const noexcept;
    /**
     * Get color of the border.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_border_color_filtered
     */
    Color get_style_border_color_filtered(Part part) const noexcept;
    /**
     * Get opacity of the border. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means fully
     * transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means fully covering, other values
     * or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_border_opa
     */
    lv_opa_t get_style_border_opa(Part part) const noexcept;
    /**
     * Get width of the border. Only pixel values can be used.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_border_width
     */
    int32_t get_style_border_width(Part part) const noexcept;
    /**
     * Get only which side(s) the border should be drawn. Possible values are
     * `LV_BORDER_SIDE_NONE/TOP/BOTTOM/LEFT/RIGHT/INTERNAL`. OR-ed values can be used as
     * well, e.g. `LV_BORDER_SIDE_TOP | LV_BORDER_SIDE_LEFT`.
     * Default: `LV_BORDER_SIDE_FULL`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_border_side
     */
    BorderSide get_style_border_side(Part part) const noexcept;
    /**
     * Gets whether the border should be drawn before or after the children are drawn.
     * `true`: after children, `false`: before children.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_border_post
     */
    bool get_style_border_post(Part part) const noexcept;
    /**
     * Get width of outline in pixels.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_outline_width
     */
    int32_t get_style_outline_width(Part part) const noexcept;
    /**
     * Get color of outline.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_outline_color
     */
    Color get_style_outline_color(Part part) const noexcept;
    /**
     * Get color of outline.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_outline_color_filtered
     */
    Color get_style_outline_color_filtered(Part part) const noexcept;
    /**
     * Get opacity of outline. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means fully
     * transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means fully covering, other values
     * or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: No, layout: No, ext. draw: Yes.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_outline_opa
     */
    lv_opa_t get_style_outline_opa(Part part) const noexcept;
    /**
     * Get padding of outline, i.e. the gap between Widget and the outline.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_outline_pad
     */
    int32_t get_style_outline_pad(Part part) const noexcept;
    /**
     * Get width of the shadow in pixels. The value should be >= 0.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_shadow_width
     */
    int32_t get_style_shadow_width(Part part) const noexcept;
    /**
     * Get an offset on the shadow in pixels in X direction.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_shadow_offset_x
     */
    int32_t get_style_shadow_offset_x(Part part) const noexcept;
    /**
     * Get an offset on the shadow in pixels in Y direction.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_shadow_offset_y
     */
    int32_t get_style_shadow_offset_y(Part part) const noexcept;
    /**
     * Make shadow calculation to use a larger or smaller rectangle as base. The value can
     * be in pixels to make the area larger/smaller.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_shadow_spread
     */
    int32_t get_style_shadow_spread(Part part) const noexcept;
    /**
     * Get color of shadow.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_shadow_color
     */
    Color get_style_shadow_color(Part part) const noexcept;
    /**
     * Get color of shadow.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_shadow_color_filtered
     */
    Color get_style_shadow_color_filtered(Part part) const noexcept;
    /**
     * Get opacity of shadow. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means fully
     * transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means fully covering, other values
     * or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: No, layout: No, ext. draw: Yes.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_shadow_opa
     */
    lv_opa_t get_style_shadow_opa(Part part) const noexcept;
    /**
     * Get opacity of an image. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means fully
     * transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means fully covering, other values
     * or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_image_opa
     */
    lv_opa_t get_style_image_opa(Part part) const noexcept;
    /**
     * Get color to mix with the image.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_image_recolor
     */
    Color get_style_image_recolor(Part part) const noexcept;
    /**
     * Get color to mix with the image.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_image_recolor_filtered
     */
    Color get_style_image_recolor_filtered(Part part) const noexcept;
    /**
     * Get intensity of color mixing. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means fully
     * transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means fully covering, other values
     * or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_image_recolor_opa
     */
    lv_opa_t get_style_image_recolor_opa(Part part) const noexcept;
    /**
     * Get image colorkey definition. The lv_image_colorkey_t contains two color values:
     * `high_color` and `low_color`. the color of pixels ranging from `low_color` to
     * `high_color` will be transparent.
     * Default: `NULL`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_image_colorkey
     */
    const lv_image_colorkey_t* get_style_image_colorkey(Part part) const noexcept;
    /**
     * Get width of lines in pixels.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_line_width
     */
    int32_t get_style_line_width(Part part) const noexcept;
    /**
     * Get width of dashes in pixels. Note that dash works only on horizontal and vertical lines.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_line_dash_width
     */
    int32_t get_style_line_dash_width(Part part) const noexcept;
    /**
     * Get gap between dashes in pixels. Note that dash works only on horizontal and
     * vertical lines.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_line_dash_gap
     */
    int32_t get_style_line_dash_gap(Part part) const noexcept;
    /**
     * Make end points of the lines rounded. `true`: rounded, `false`: perpendicular line ending.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_line_rounded
     */
    bool get_style_line_rounded(Part part) const noexcept;
    /**
     * Get color of lines.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_line_color
     */
    Color get_style_line_color(Part part) const noexcept;
    /**
     * Get color of lines.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_line_color_filtered
     */
    Color get_style_line_color_filtered(Part part) const noexcept;
    /**
     * Get opacity of lines.
     * Default: `LV_OPA_COVER`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_line_opa
     */
    lv_opa_t get_style_line_opa(Part part) const noexcept;
    /**
     * Get width (thickness) of arcs in pixels.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_arc_width
     */
    int32_t get_style_arc_width(Part part) const noexcept;
    /**
     * Make end points of arcs rounded. `true`: rounded, `false`: perpendicular line ending.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_arc_rounded
     */
    bool get_style_arc_rounded(Part part) const noexcept;
    /**
     * Get color of arc.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_arc_color
     */
    Color get_style_arc_color(Part part) const noexcept;
    /**
     * Get color of arc.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_arc_color_filtered
     */
    Color get_style_arc_color_filtered(Part part) const noexcept;
    /**
     * Get opacity of arcs.
     * Default: `LV_OPA_COVER`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_arc_opa
     */
    lv_opa_t get_style_arc_opa(Part part) const noexcept;
    /**
     * Get an image from which arc will be masked out. It's useful to display complex
     * effects on the arcs. Can be a pointer to `lv_image_dsc_t` or a path to a file.
     * Default: `NULL`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_arc_image_src
     */
    const void* get_style_arc_image_src(Part part) const noexcept;
    /**
     * Gets color of text.
     * Default: `0x000000`, inherited: Yes, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_text_color
     */
    Color get_style_text_color(Part part) const noexcept;
    /**
     * Gets color of text.
     * Default: `0x000000`, inherited: Yes, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_text_color_filtered
     */
    Color get_style_text_color_filtered(Part part) const noexcept;
    /**
     * Get opacity of text. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means fully
     * transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means fully covering, other values
     * or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: Yes, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_text_opa
     */
    lv_opa_t get_style_text_opa(Part part) const noexcept;
    /**
     * Get font of text (a pointer `lv_font_t *`).
     * Default: `LV_FONT_DEFAULT`, inherited: Yes, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_text_font
     */
    Font get_style_text_font(Part part) const noexcept;
    /**
     * Get letter space in pixels.
     * Default: 0, inherited: Yes, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_text_letter_space
     */
    int32_t get_style_text_letter_space(Part part) const noexcept;
    /**
     * Get line space in pixels.
     * Default: 0, inherited: Yes, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_text_line_space
     */
    int32_t get_style_text_line_space(Part part) const noexcept;
    /**
     * Get decoration for the text. Possible values are
     * `LV_TEXT_DECOR_NONE/UNDERLINE/STRIKETHROUGH`. OR-ed values can be used as well.
     * Default: `LV_TEXT_DECOR_NONE`, inherited: Yes, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_text_decor
     */
    TextDecor get_style_text_decor(Part part) const noexcept;
    /**
     * Get how to align the lines of the text. Note that it doesn't align the Widget
     * itself, only the lines inside the Widget. Possible values are
     * `LV_TEXT_ALIGN_LEFT/CENTER/RIGHT/AUTO`. `LV_TEXT_ALIGN_AUTO` detect the text base
     * direction and uses left or right alignment accordingly.
     * Default: `LV_TEXT_ALIGN_AUTO`, inherited: Yes, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_text_align
     */
    TextAlign get_style_text_align(Part part) const noexcept;
    /**
     * Gets the color of letter outline stroke.
     * Default: `0x000000`, inherited: Yes, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_text_outline_stroke_color
     */
    Color get_style_text_outline_stroke_color(Part part) const noexcept;
    /**
     * Gets the color of letter outline stroke.
     * Default: `0x000000`, inherited: Yes, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_text_outline_stroke_color_filtered
     */
    Color get_style_text_outline_stroke_color_filtered(Part part) const noexcept;
    /**
     * Get the letter outline stroke width in pixels.
     * Default: 0, inherited: Yes, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_text_outline_stroke_width
     */
    int32_t get_style_text_outline_stroke_width(Part part) const noexcept;
    /**
     * Get the opacity of the letter outline stroke. Value 0, `LV_OPA_0` or
     * `LV_OPA_TRANSP` means fully transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means
     * fully covering, other values or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: Yes, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_text_outline_stroke_opa
     */
    lv_opa_t get_style_text_outline_stroke_opa(Part part) const noexcept;
    /**
     * Gets the intensity of blurring. Applied on each lv_part separately before the
     * children are rendered.
     * Default: `0`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_blur_radius
     */
    int32_t get_style_blur_radius(Part part) const noexcept;
    /**
     * If `true` the background of the widget will be blurred. The part should have < 100%
     * opacity to make it visible. If `false` the given part will be blurred when it's
     * rendered but before drawing the children.
     * Default: `false`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_blur_backdrop
     */
    bool get_style_blur_backdrop(Part part) const noexcept;
    /**
     * Setting to `LV_BLUR_QUALITY_SPEED` the blurring algorithm will prefer speed over
     * quality. `LV_BLUR_QUALITY_PRECISION` will force using higher quality but slower
     * blur. With `LV_BLUR_QUALITY_AUTO` the quality will be selected automatically.
     * Default: `LV_BLUR_QUALITY_AUTO`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_blur_quality
     */
    BlurQuality get_style_blur_quality(Part part) const noexcept;
    /**
     * Gets the intensity of blurring. Applied on each lv_part separately before the
     * children are rendered.
     * Default: `0`, inherited: No, layout: No, ext. draw: Yes.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_drop_shadow_radius
     */
    int32_t get_style_drop_shadow_radius(Part part) const noexcept;
    /**
     * Get an offset on the shadow in pixels in X direction.
     * Default: `0`, inherited: No, layout: No, ext. draw: Yes.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_drop_shadow_offset_x
     */
    int32_t get_style_drop_shadow_offset_x(Part part) const noexcept;
    /**
     * Get an offset on the shadow in pixels in Y direction.
     * Default: `0`, inherited: No, layout: No, ext. draw: Yes.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_drop_shadow_offset_y
     */
    int32_t get_style_drop_shadow_offset_y(Part part) const noexcept;
    /**
     * Get the color of the shadow.
     * Default: `0`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_drop_shadow_color
     */
    Color get_style_drop_shadow_color(Part part) const noexcept;
    /**
     * Get the color of the shadow.
     * Default: `0`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_drop_shadow_color_filtered
     */
    Color get_style_drop_shadow_color_filtered(Part part) const noexcept;
    /**
     * Get the opacity of the shadow.
     * Default: `0`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_drop_shadow_opa
     */
    lv_opa_t get_style_drop_shadow_opa(Part part) const noexcept;
    /**
     * Setting to `LV_BLUR_QUALITY_SPEED` the blurring algorithm will prefer speed over
     * quality. `LV_BLUR_QUALITY_PRECISION` will force using higher quality but slower
     * blur. With `LV_BLUR_QUALITY_AUTO` the quality will be selected automatically.
     * Default: `LV_BLUR_QUALITY_PRECISION`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_drop_shadow_quality
     */
    BlurQuality get_style_drop_shadow_quality(Part part) const noexcept;
    /**
     * Get radius on every corner. The value is interpreted in pixels (>= 0) or
     * `LV_RADIUS_CIRCLE` for max radius.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_radius
     */
    int32_t get_style_radius(Part part) const noexcept;
    /**
     * Move start point of object (e.g. scale tick) radially.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_radial_offset
     */
    int32_t get_style_radial_offset(Part part) const noexcept;
    /**
     * Enable clipping of content that overflows rounded corners of parent Widget. Can be
     * `true` or `false`.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_clip_corner
     */
    bool get_style_clip_corner(Part part) const noexcept;
    /**
     * Scale down all opacity values of the Widget by this factor. Value 0, `LV_OPA_0` or
     * `LV_OPA_TRANSP` means fully transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means
     * fully covering, other values or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: Yes, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_opa
     */
    lv_opa_t get_style_opa(Part part) const noexcept;
    /**
     * First draw Widget on the layer, then scale down layer opacity factor. Value 0,
     * `LV_OPA_0` or `LV_OPA_TRANSP` means fully transparent, 255, `LV_OPA_100` or
     * `LV_OPA_COVER` means fully covering, other values or LV_OPA_10, LV_OPA_20, etc
     * means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: Yes, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_opa_layered
     */
    lv_opa_t get_style_opa_layered(Part part) const noexcept;
    /**
     * Mix a color with all colors of the Widget.
     * Default: `NULL`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_color_filter_dsc
     */
    const lv_color_filter_dsc_t* get_style_color_filter_dsc(Part part) const noexcept;
    /**
     * The intensity of mixing of color filter.
     * Default: `LV_OPA_TRANSP`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_color_filter_opa
     */
    lv_opa_t get_style_color_filter_opa(Part part) const noexcept;
    /**
     * Get a color to mix to the obj.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_recolor
     */
    Color get_style_recolor(Part part) const noexcept;
    /**
     * Gets the intensity of color mixing. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means
     * fully transparent. A value of  255, `LV_OPA_100` or `LV_OPA_COVER` means fully
     * opaque. Intermediate values like LV_OPA_10, LV_OPA_20, etc result in
     * semi-transparency.
     * Default: `LV_OPA_TRANSP`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_recolor_opa
     */
    lv_opa_t get_style_recolor_opa(Part part) const noexcept;
    /**
     * Animation template for Widget's animation. Should be a pointer to `lv_anim_t`. The
     * animation parameters are widget specific, e.g. animation time could be the E.g.
     * blink time of the cursor on the Text Area or scroll time of a roller. See Widgets'
     * documentation to learn more.
     * Default: `NULL`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_anim
     */
    const lv_anim_t* get_style_anim(Part part) const noexcept;
    /**
     * Animation duration in milliseconds. Its meaning is widget specific. E.g. blink time
     * of the cursor on the Text Area or scroll time of a roller. See Widgets'
     * documentation to learn more.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_anim_duration
     */
    uint32_t get_style_anim_duration(Part part) const noexcept;
    /**
     * An initialized ``lv_style_transition_dsc_t`` to describe a transition.
     * Default: `NULL`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_transition
     */
    const lv_style_transition_dsc_t* get_style_transition(Part part) const noexcept;
    /**
     * Describes how to blend the colors to the background. Possible values are
     * `LV_BLEND_MODE_NORMAL/ADDITIVE/SUBTRACTIVE/MULTIPLY/DIFFERENCE`.
     * Default: `LV_BLEND_MODE_NORMAL`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_blend_mode
     */
    BlendMode get_style_blend_mode(Part part) const noexcept;
    /**
     * Get layout of Widget. Children will be repositioned and resized according to
     * policies set for the layout. For possible values see documentation of the layouts.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_layout
     */
    uint16_t get_style_layout(Part part) const noexcept;
    /**
     * Get base direction of Widget. Possible values are `LV_BIDI_DIR_LTR/RTL/AUTO`.
     * Default: `LV_BASE_DIR_AUTO`, inherited: Yes, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_base_dir
     */
    BaseDir get_style_base_dir(Part part) const noexcept;
    /**
     * If set, a layer will be created for the widget and the layer will be masked with
     * this A8 bitmap mask.
     * Default: `NULL`, inherited: No, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_bitmap_mask_src
     */
    const void* get_style_bitmap_mask_src(Part part) const noexcept;
    /**
     * Adjust sensitivity for rotary encoders in 1/256 unit. It means, 128: slow down the
     * rotary to half, 512: speeds up to double, 256: no change.
     * Default: `256`, inherited: Yes, layout: No, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_rotary_sensitivity
     */
    uint32_t get_style_rotary_sensitivity(Part part) const noexcept;
    #if LV_USE_FLEX
    /**
     * Defines in which direction the flex layout should arrange the children.
     * Default: `LV_FLEX_FLOW_NONE`, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_flex_flow
     */
    FlexFlow get_style_flex_flow(Part part) const noexcept;
    /**
     * Defines how to align the children in the direction of flex flow.
     * Default: `LV_FLEX_ALIGN_NONE`, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_flex_main_place
     */
    FlexAlign get_style_flex_main_place(Part part) const noexcept;
    /**
     * Defines how to align the children perpendicular to the direction of flex flow.
     * Default: `LV_FLEX_ALIGN_NONE`, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_flex_cross_place
     */
    FlexAlign get_style_flex_cross_place(Part part) const noexcept;
    /**
     * Defines how to align the tracks of the flow.
     * Default: `LV_FLEX_ALIGN_NONE`, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_flex_track_place
     */
    FlexAlign get_style_flex_track_place(Part part) const noexcept;
    /**
     * Defines how much space to take proportionally from the free space of the Widget's track.
     * Default: `0`, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_flex_grow
     */
    uint8_t get_style_flex_grow(Part part) const noexcept;
    #endif // LV_USE_FLEX

    #if LV_USE_GRID
    /**
     * An array to describe the columns of the grid. Should be LV_GRID_TEMPLATE_LAST terminated.
     * Default: `NULL`, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_grid_column_dsc_array
     */
    const int32_t* get_style_grid_column_dsc_array(Part part) const noexcept;
    /**
     * Defines how to distribute the columns.
     * Default: `LV_GRID_ALIGN_START`, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_grid_column_align
     */
    GridAlign get_style_grid_column_align(Part part) const noexcept;
    /**
     * An array to describe the rows of the grid. Should be LV_GRID_TEMPLATE_LAST terminated.
     * Default: `NULL`, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_grid_row_dsc_array
     */
    const int32_t* get_style_grid_row_dsc_array(Part part) const noexcept;
    /**
     * Defines how to distribute the rows.
     * Default: `LV_GRID_ALIGN_START`, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_grid_row_align
     */
    GridAlign get_style_grid_row_align(Part part) const noexcept;
    /**
     * Get column in which Widget should be placed.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_grid_cell_column_pos
     */
    int32_t get_style_grid_cell_column_pos(Part part) const noexcept;
    /**
     * Get how to align Widget horizontally.
     * Default: `LV_GRID_ALIGN_START`, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_grid_cell_x_align
     */
    GridAlign get_style_grid_cell_x_align(Part part) const noexcept;
    /**
     * Get how many columns Widget should span. Needs to be >= 1.
     * Default: 1, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_grid_cell_column_span
     */
    int32_t get_style_grid_cell_column_span(Part part) const noexcept;
    /**
     * Get row in which Widget should be placed.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_grid_cell_row_pos
     */
    int32_t get_style_grid_cell_row_pos(Part part) const noexcept;
    /**
     * Get how to align Widget vertically.
     * Default: `LV_GRID_ALIGN_START`, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_grid_cell_y_align
     */
    GridAlign get_style_grid_cell_y_align(Part part) const noexcept;
    /**
     * Get how many rows Widget should span. Needs to be >= 1.
     * Default: 1, inherited: No, layout: Yes, ext. draw: No.
     * @param part  One of the `LV_PART_...` enum values
     * @see lv_obj_get_style_grid_cell_row_span
     */
    int32_t get_style_grid_cell_row_span(Part part) const noexcept;
    #endif // LV_USE_GRID

    #if LVPP_COMPAT_V8
    /** v8 spelling of `delete_`. */
    void del() const noexcept;
    /** v8 spelling of `delete_async`. */
    void del_async() const noexcept;
    /** v8 spelling of `remove_flag`. */
    void clear_flag(ObjFlag f) const noexcept;
    /** v8 spelling of `remove_state`. */
    void clear_state(State state) const noexcept;
    /** v8 spelling of `get_child_count`. */
    uint32_t get_child_cnt() const noexcept;
    /** v8 spelling of `get_display`. */
    Display get_disp() const noexcept;
    /** v8 spelling of `get_style_anim_duration`. */
    uint32_t get_style_anim_time(Part part) const noexcept;
    /** v8 spelling of `get_style_image_opa`. */
    lv_opa_t get_style_img_opa(Part part) const noexcept;
    /** v8 spelling of `get_style_image_recolor`. */
    Color get_style_img_recolor(Part part) const noexcept;
    /** v8 spelling of `get_style_image_recolor_filtered`. */
    Color get_style_img_recolor_filtered(Part part) const noexcept;
    /** v8 spelling of `get_style_image_recolor_opa`. */
    lv_opa_t get_style_img_recolor_opa(Part part) const noexcept;
    /** v8 spelling of `get_style_shadow_offset_x`. */
    int32_t get_style_shadow_ofs_x(Part part) const noexcept;
    /** v8 spelling of `get_style_shadow_offset_y`. */
    int32_t get_style_shadow_ofs_y(Part part) const noexcept;
    /** v8 spelling of `get_style_transform_rotation`. */
    int32_t get_style_transform_angle(Part part) const noexcept;
    /** v8 spelling of `get_style_bg_image_src`. */
    const void* get_style_bg_img_src(Part part) const noexcept;
    /** v8 spelling of `get_style_bg_image_recolor`. */
    Color get_style_bg_img_recolor(Part part) const noexcept;
    /** v8 spelling of `get_style_bg_image_recolor_opa`. */
    lv_opa_t get_style_bg_img_recolor_opa(Part part) const noexcept;
    #endif // LVPP_COMPAT_V8

    /**
     * The children, as a range: `for (auto child : parent.children())`.
     * Derived from lv_obj_get_child_count and lv_obj_get_child, so a rename between versions costs nothing.
     */
    ChildRange children() const noexcept;
};
static_assert(sizeof(Obj) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Obj));

/**
 * The children of an object, as a range.
 *
 * Two words, exactly what the C loop keeps in registers, and the bound cannot be
 * got wrong because nobody writes it.
 */
class ChildRange {
    lv_obj_t* p_;
    uint32_t n_;

public:
    class iterator {
        lv_obj_t* p_;
        uint32_t i_;

    public:
        constexpr iterator(lv_obj_t* p, uint32_t i) noexcept : p_(p), i_(i) {}

        Obj operator*() const noexcept {
            return Obj(lv_obj_get_child(p_, static_cast<int32_t>(i_)));
        }
        iterator& operator++() noexcept { ++i_; return *this; }
        friend constexpr bool operator!=(iterator a, iterator b) noexcept {
            return a.i_ != b.i_;
        }
        friend constexpr bool operator==(iterator a, iterator b) noexcept {
            return a.i_ == b.i_;
        }
    };

    constexpr ChildRange(lv_obj_t* p, uint32_t n) noexcept : p_(p), n_(n) {}

    iterator begin() const noexcept { return iterator(p_, 0); }
    iterator end()   const noexcept { return iterator(p_, n_); }
    constexpr uint32_t size() const noexcept { return n_; }
};

/**
 * Utility to set an object reference to NULL when it gets deleted.
 * The reference should be in a location that will not become invalid
 * during the object's lifetime, i.e. static or allocated.
 * @param obj_ptr  a pointer to a pointer to an object
 * @see lv_obj_null_on_delete
 */
inline void obj_null_on_delete(lv_obj_t** obj_ptr) noexcept;

#if LV_USE_OBJ_ID
/**
 * Assign id to object if not previously assigned.
 * This function gets called automatically when LV_OBJ_ID_AUTO_ASSIGN is enabled.
 * Set `LV_USE_OBJ_ID_BUILTIN` to use the builtin method to generate object ID.
 * Otherwise, these functions including `lv_obj_[set|assign|free|stringify]_id` and
 * `lv_obj_id_compare`should be implemented externally.
 * @param class_p  the class this obj belongs to. Note obj->class_p is the class currently being constructed.
 * @param obj  pointer to an object
 * @see lv_obj_assign_id
 */
inline void obj_assign_id(ObjClass class_p, Obj obj) noexcept;

/**
 * Compare two obj id, return 0 if they are equal.
 * Set `LV_USE_OBJ_ID_BUILTIN` to use the builtin method for compare.
 * Otherwise, it must be implemented externally.
 * @return 0 if they are equal, non-zero otherwise.
 * @see lv_obj_id_compare
 */
inline int32_t obj_id_compare(const void* id1, const void* id2) noexcept;
#endif // LV_USE_OBJ_ID

#if (LV_USE_OBJ_ID) && (LV_USE_OBJ_ID_BUILTIN)
/**
 * Free resources used by builtin ID generator.
 * @see lv_objid_builtin_destroy
 */
inline void obj_objid_builtin_destroy() noexcept;
#endif // (LV_USE_OBJ_ID) && (LV_USE_OBJ_ID_BUILTIN)

} // namespace lv
