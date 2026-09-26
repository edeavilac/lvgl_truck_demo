#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core.hpp"
#include "lv/core/obj.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_LINE != 0
class Line : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_line_class; }

    /**
     * Create a line object
     * @param parent  pointer to an object, it will be the parent of the new line
     * @return pointer to the created line
     * @see lv_line_create
     */
    static Line create(Obj parent) noexcept { return Line(lv_line_create(parent.raw())); }
    /**
     * Get the number of points in the array of points.
     * @return number of points in array of points
     * @see lv_line_get_point_count
     */
    uint32_t get_point_count() const noexcept { return lv_line_get_point_count(p_); }
    /**
     * Get the pointer to the array of points.
     * @return const pointer to the array of points
     * @see lv_line_get_points
     */
    PointPrecise get_points() const noexcept { return PointPrecise(const_cast<lv_point_precise_t*>(lv_line_get_points(p_))); }
    /**
     * Get a pointer to the mutable array of points or NULL if it is not mutable
     * @return pointer to the array of points. NULL if not mutable.
     * @see lv_line_get_points_mutable
     */
    PointPrecise get_points_mutable() const noexcept { return PointPrecise(lv_line_get_points_mutable(p_)); }
    /**
     * Get the y inversion attribute
     * @return true: y inversion is enabled, false: disabled
     * @see lv_line_get_y_invert
     */
    bool get_y_invert() const noexcept { return lv_line_get_y_invert(p_); }
    /**
     * Check the mutability of the stored point array pointer.
     * @return true: the point array pointer is mutable, false: constant
     * @see lv_line_is_point_array_mutable
     */
    bool is_point_array_mutable() const noexcept { return lv_line_is_point_array_mutable(p_); }
    /**
     * Set an array of points. The line object will connect these points.
     * @param points  an array of points. Only the address is saved, so the array needs to be alive while the line exists
     * @param point_num  number of points in 'point_a'
     * @see lv_line_set_points
     */
    void set_points(PointPrecise points, uint32_t point_num) const noexcept { lv_line_set_points(p_, points.raw(), point_num); }
    /**
     * Set a non-const array of points. Identical to `lv_line_set_points` except the array may be retrieved by `lv_line_get_points_mutable`.
     * @param points  a non-const array of points. Only the address is saved, so the array needs to be alive while the line exists.
     * @param point_num  number of points in 'point_a'
     * @see lv_line_set_points_mutable
     */
    void set_points_mutable(PointPrecise points, uint32_t point_num) const noexcept { lv_line_set_points_mutable(p_, points.raw(), point_num); }
    /**
     * Enable (or disable) the y coordinate inversion.
     * If enabled then y will be subtracted from the height of the object,
     * therefore the y = 0 coordinate will be on the bottom.
     * @param en  true: enable the y inversion, false:disable the y inversion
     * @see lv_line_set_y_invert
     */
    void set_y_invert(bool en) const noexcept { lv_line_set_y_invert(p_, en); }
};
static_assert(sizeof(Line) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Line));
#endif // LV_USE_LINE != 0

} // namespace lv
