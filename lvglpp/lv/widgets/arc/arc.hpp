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

#if LV_USE_ARC != 0
class Arc : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_arc_class; }

    /** In which direction the indicator should grow. */
    enum class Mode : int {
        /** Clock-wise */
        Normal = LV_ARC_MODE_NORMAL,
        /** Left/right from the midpoint */
        Symmetrical = LV_ARC_MODE_SYMMETRICAL,
        /** Counterclock-wise */
        Reverse = LV_ARC_MODE_REVERSE,
    };

    /**
     * Align an object to the current position of the arc (knob)
     * @param obj_to_align  pointer to an object to align
     * @param r_offset  consider the radius larger with this value (< 0: for smaller radius)
     * @see lv_arc_align_obj_to_angle
     */
    void align_obj_to_angle(Obj obj_to_align, int32_t r_offset) const noexcept { lv_arc_align_obj_to_angle(p_, obj_to_align.raw(), r_offset); }
    #if LV_USE_OBSERVER
    /**
     * Bind an integer subject to an Arc's value.
     * @param subject  pointer to Subject
     * @return pointer to newly-created Observer
     * @see lv_arc_bind_value
     */
    Observer bind_value(Subject& subject) const noexcept { return Observer(lv_arc_bind_value(p_, subject.raw())); }
    #endif // LV_USE_OBSERVER

    /**
     * Create an arc object
     * @param parent  pointer to an object, it will be the parent of the new arc
     * @return pointer to the created arc
     * @see lv_arc_create
     */
    static Arc create(Obj parent) noexcept { return Arc(lv_arc_create(parent.raw())); }
    /**
     * Get the end angle of an arc.
     * @return the end angle [0..360] (if `LV_USE_FLOAT` is enabled it can be fractional too.)
     * @see lv_arc_get_angle_end
     */
    float get_angle_end() const noexcept { return lv_arc_get_angle_end(p_); }
    /**
     * Get the start angle of an arc.
     * @return the start angle [0..360] (if `LV_USE_FLOAT` is enabled it can be fractional too.)
     * @see lv_arc_get_angle_start
     */
    float get_angle_start() const noexcept { return lv_arc_get_angle_start(p_); }
    /**
     * Get the end angle of an arc background.
     * @return the end angle [0..360] (if `LV_USE_FLOAT` is enabled it can be fractional too.)
     * @see lv_arc_get_bg_angle_end
     */
    float get_bg_angle_end() const noexcept { return lv_arc_get_bg_angle_end(p_); }
    /**
     * Get the start angle of an arc background.
     * @return the start angle [0..360] (if `LV_USE_FLOAT` is enabled it can be fractional too.)
     * @see lv_arc_get_bg_angle_start
     */
    float get_bg_angle_start() const noexcept { return lv_arc_get_bg_angle_start(p_); }
    /**
     * Get the change rate of an arc
     * @return the change rate
     * @see lv_arc_get_change_rate
     */
    uint32_t get_change_rate() const noexcept { return lv_arc_get_change_rate(p_); }
    /**
     * Get the current knob angle offset
     * @return arc's current knob offset
     * @see lv_arc_get_knob_offset
     */
    int32_t get_knob_offset() const noexcept { return lv_arc_get_knob_offset(p_); }
    /**
     * Get the maximum value of an arc
     * @return the maximum value of the arc
     * @see lv_arc_get_max_value
     */
    int32_t get_max_value() const noexcept { return lv_arc_get_max_value(p_); }
    /**
     * Get the minimum value of an arc
     * @return the minimum value of the arc
     * @see lv_arc_get_min_value
     */
    int32_t get_min_value() const noexcept { return lv_arc_get_min_value(p_); }
    /**
     * Get whether the arc is type or not.
     * @return arc's mode
     * @see lv_arc_get_mode
     */
    Arc::Mode get_mode() const noexcept { return static_cast<Arc::Mode>(lv_arc_get_mode(p_)); }
    /**
     * Get the rotation for the whole arc
     * @return arc's current rotation
     * @see lv_arc_get_rotation
     */
    int32_t get_rotation() const noexcept { return lv_arc_get_rotation(p_); }
    /**
     * Get the value of an arc
     * @return the value of the arc
     * @see lv_arc_get_value
     */
    int32_t get_value() const noexcept { return lv_arc_get_value(p_); }
    /**
     * Rotate an object to the current position of the arc (knob)
     * @param obj_to_rotate  pointer to an object to rotate
     * @param r_offset  consider the radius larger with this value (< 0: for smaller radius)
     * @see lv_arc_rotate_obj_to_angle
     */
    void rotate_obj_to_angle(Obj obj_to_rotate, int32_t r_offset) const noexcept { lv_arc_rotate_obj_to_angle(p_, obj_to_rotate.raw(), r_offset); }
    /**
     * Set the start and end angles
     * @param start  the start angle (if `LV_USE_FLOAT` is enabled it can be fractional too.)
     * @param end  the end angle (if `LV_USE_FLOAT` is enabled it can be fractional too.)
     * @see lv_arc_set_angles
     */
    void set_angles(lv_value_precise_t start, lv_value_precise_t end) const noexcept { lv_arc_set_angles(p_, start, end); }
    /**
     * Set the start and end angles of the arc background
     * @param start  the start angle (if `LV_USE_FLOAT` is enabled it can be fractional too.)
     * @param end  the end angle (if `LV_USE_FLOAT` is enabled it can be fractional too.)
     * @see lv_arc_set_bg_angles
     */
    void set_bg_angles(lv_value_precise_t start, lv_value_precise_t end) const noexcept { lv_arc_set_bg_angles(p_, start, end); }
    /**
     * Set the start angle of an arc background. 0 deg: right, 90 bottom etc.
     * @param end  the end angle (if `LV_USE_FLOAT` is enabled it can be fractional too.)
     * @see lv_arc_set_bg_end_angle
     */
    void set_bg_end_angle(lv_value_precise_t end) const noexcept { lv_arc_set_bg_end_angle(p_, end); }
    /**
     * Set the start angle of an arc background. 0 deg: right, 90 bottom, etc.
     * @param start  the start angle (if `LV_USE_FLOAT` is enabled it can be fractional too.)
     * @see lv_arc_set_bg_start_angle
     */
    void set_bg_start_angle(lv_value_precise_t start) const noexcept { lv_arc_set_bg_start_angle(p_, start); }
    /**
     * Set a change rate to limit the speed how fast the arc should reach the pressed point.
     * @param rate  the change rate
     * @see lv_arc_set_change_rate
     */
    void set_change_rate(uint32_t rate) const noexcept { lv_arc_set_change_rate(p_, rate); }
    /**
     * Set the end angle of an arc. 0 deg: right, 90 bottom, etc.
     * @param end  the end angle (if `LV_USE_FLOAT` is enabled it can be fractional too.)
     * @see lv_arc_set_end_angle
     */
    void set_end_angle(lv_value_precise_t end) const noexcept { lv_arc_set_end_angle(p_, end); }
    /**
     * Set an offset angle for the knob
     * @param offset  knob offset from main arc in degrees
     * @see lv_arc_set_knob_offset
     */
    void set_knob_offset(int32_t offset) const noexcept { lv_arc_set_knob_offset(p_, offset); }
    /**
     * Set the maximum values of an arc
     * @param max  maximum value
     * @see lv_arc_set_max_value
     */
    void set_max_value(int32_t max) const noexcept { lv_arc_set_max_value(p_, max); }
    /**
     * Set the minimum values of an arc
     * @param min  minimum value
     * @see lv_arc_set_min_value
     */
    void set_min_value(int32_t min) const noexcept { lv_arc_set_min_value(p_, min); }
    /**
     * Set in which direction the indicator should grow.
     * @param type  arc's mode
     * @see lv_arc_set_mode
     */
    void set_mode(Arc::Mode type) const noexcept { lv_arc_set_mode(p_, static_cast<lv_arc_mode_t>(type)); }
    /**
     * Set minimum and the maximum values of an arc
     * @param min  minimum value
     * @param max  maximum value
     * @see lv_arc_set_range
     */
    void set_range(int32_t min, int32_t max) const noexcept { lv_arc_set_range(p_, min, max); }
    /**
     * Set the rotation for the whole arc
     * @param rotation  rotation angle
     * @see lv_arc_set_rotation
     */
    void set_rotation(int32_t rotation) const noexcept { lv_arc_set_rotation(p_, rotation); }
    /**
     * Set the start angle of an arc. 0 deg: right, 90 bottom, etc.
     * @param start  the start angle. (if `LV_USE_FLOAT` is enabled it can be fractional too.)
     * @see lv_arc_set_start_angle
     */
    void set_start_angle(lv_value_precise_t start) const noexcept { lv_arc_set_start_angle(p_, start); }
    /**
     * Set a new value on the arc
     * @param value  new value
     * @see lv_arc_set_value
     */
    void set_value(int32_t value) const noexcept { lv_arc_set_value(p_, value); }
};
static_assert(sizeof(Arc) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Arc));
#endif // LV_USE_ARC != 0

} // namespace lv
