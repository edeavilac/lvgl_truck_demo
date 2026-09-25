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

#if LV_USE_CHART != 0
class ChartSeries {
protected:
    lv_obj_t* owner_ = nullptr;
    lv_chart_series_t* p_ = nullptr;

public:
    constexpr ChartSeries() noexcept = default;
    constexpr ChartSeries(lv_obj_t* owner, lv_chart_series_t* p) noexcept : owner_(owner), p_(p) {}

    constexpr lv_chart_series_t* raw() const noexcept { return p_; }
    constexpr lv_obj_t* owner() const noexcept { return owner_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(ChartSeries a, ChartSeries b) noexcept { return a.p_ == b.p_ && a.owner_ == b.owner_; }

    /**
     * Get the position of a point to the chart.
     * @param obj  pointer to a chart object
     * @param id  the index.
     * @return store the result position here
     * @see lv_chart_get_point_pos_by_id
     */
    Point get_point_pos_by_id(uint32_t id) const noexcept {
        lv_point_t p_out_out{};
        lv_chart_get_point_pos_by_id(owner_, p_, id, &p_out_out);
        return Point{p_out_out};
    }
    /**
     * Get the color of a series
     * @param chart  pointer to a chart object.
     * @return the color of the series
     * @see lv_chart_get_series_color
     */
    Color get_series_color() const noexcept { return Color{lv_chart_get_series_color(owner_, p_)}; }
    /**
     * Get the next series.
     * @param chart  pointer to a chart
     * @return the next series or NULL if there is no more.
     * @see lv_chart_get_series_next
     */
    ChartSeries get_series_next() const noexcept { return ChartSeries(owner_, lv_chart_get_series_next(owner_, p_)); }
    /**
     * Get the array of x values of a series
     * @param obj  pointer to a chart object
     * @return the array of values with 'point_count' elements
     * @see lv_chart_get_series_x_array
     */
    int32_t* get_series_x_array() const noexcept { return lv_chart_get_series_x_array(owner_, p_); }
    /**
     * Get the array of y values of a series
     * @param obj  pointer to a chart object
     * @return the array of values with 'point_count' elements
     * @see lv_chart_get_series_y_array
     */
    int32_t* get_series_y_array() const noexcept { return lv_chart_get_series_y_array(owner_, p_); }
    /**
     * Get the current index of the x-axis start point in the data array
     * @param obj  pointer to a chart object
     * @return the index of the current x start point in the data array
     * @see lv_chart_get_x_start_point
     */
    uint32_t get_x_start_point() const noexcept { return lv_chart_get_x_start_point(owner_, p_); }
    /**
     * Hide/Unhide a single series of a chart.
     * @param chart  pointer to a chart object.
     * @param hide  true: hide the series
     * @see lv_chart_hide_series
     */
    void hide_series(bool hide) const noexcept { lv_chart_hide_series(owner_, p_, hide); }
    /**
     * Deallocate and remove a data series from a chart
     * @param obj  pointer to a chart object
     * @see lv_chart_remove_series
     */
    void remove_series() const noexcept { lv_chart_remove_series(owner_, p_); }
    /**
     * Initialize all data points of a series with a value
     * @param obj  pointer to chart object
     * @param value  the new value for all points. `LV_CHART_POINT_NONE` can be used to hide the points.
     * @see lv_chart_set_all_values
     */
    void set_all_values(int32_t value) const noexcept { lv_chart_set_all_values(owner_, p_, value); }
    /**
     * Set the next point's Y value according to the update mode policy.
     * @param obj  pointer to chart object
     * @param value  the new value of the next data
     * @see lv_chart_set_next_value
     */
    void set_next_value(int32_t value) const noexcept { lv_chart_set_next_value(owner_, p_, value); }
    /**
     * Set the next point's X and Y value according to the update mode policy.
     * @param obj  pointer to chart object
     * @param x_value  the new X value of the next data
     * @param y_value  the new Y value of the next data
     * @see lv_chart_set_next_value2
     */
    void set_next_value2(int32_t x_value, int32_t y_value) const noexcept { lv_chart_set_next_value2(owner_, p_, x_value, y_value); }
    /**
     * Change the color of a series
     * @param chart  pointer to a chart object.
     * @param color  the new color of the series
     * @see lv_chart_set_series_color
     */
    void set_series_color(Color color) const noexcept { lv_chart_set_series_color(owner_, p_, color.raw()); }
    /**
     * Set an external array for the x data points to use for the chart
     * NOTE: It is the users responsibility to make sure the `point_cnt` matches the external array size.
     * @param obj  pointer to a chart object
     * @param array  external array of points for chart
     * @see lv_chart_set_series_ext_x_array
     */
    void set_series_ext_x_array(int32_t* array) const noexcept { lv_chart_set_series_ext_x_array(owner_, p_, array); }
    /**
     * Set an external array for the y data points to use for the chart
     * NOTE: It is the users responsibility to make sure the `point_cnt` matches the external array size.
     * @param obj  pointer to a chart object
     * @param array  external array of points for chart
     * @see lv_chart_set_series_ext_y_array
     */
    void set_series_ext_y_array(int32_t* array) const noexcept { lv_chart_set_series_ext_y_array(owner_, p_, array); }
    /**
     * Set an individual point's y value of a chart's series directly based on its index
     * @param obj  pointer to a chart object
     * @param id  the index of the x point in the array
     * @param value  value to assign to array point
     * @see lv_chart_set_series_value_by_id
     */
    void set_series_value_by_id(uint32_t id, int32_t value) const noexcept { lv_chart_set_series_value_by_id(owner_, p_, id, value); }
    /**
     * Set an individual point's x and y value of a chart's series directly based on its index
     * Can be used only with `LV_CHART_TYPE_SCATTER`.
     * @param obj  pointer to chart object
     * @param id  the index of the x point in the array
     * @param x_value  the new X value of the next data
     * @param y_value  the new Y value of the next data
     * @see lv_chart_set_series_value_by_id2
     */
    void set_series_value_by_id2(uint32_t id, int32_t x_value, int32_t y_value) const noexcept { lv_chart_set_series_value_by_id2(owner_, p_, id, x_value, y_value); }
    /**
     * Same as `lv_chart_set_next_value` but set the values from an array
     * @param obj  pointer to chart object
     * @param values  the new values to set
     * @param values_cnt  number of items in `values`
     * @see lv_chart_set_series_values
     */
    void set_series_values(const int32_t* values, size_t values_cnt) const noexcept { lv_chart_set_series_values(owner_, p_, values, values_cnt); }
    /**
     * Same as `lv_chart_set_next_value2` but set the values from an array
     * @param obj  pointer to chart object
     * @param x_values  the new values to set on the X axis
     * @param y_values  the new values to set o nthe Y axis
     * @param values_cnt  number of items in `x_values` and `y_values`
     * @see lv_chart_set_series_values2
     */
    void set_series_values2(const int32_t* x_values, const int32_t* y_values, size_t values_cnt) const noexcept { lv_chart_set_series_values2(owner_, p_, x_values, y_values, values_cnt); }
    /**
     * Set the index of the x-axis start point in the data array.
     * This point will be considers the first (left) point and the other points will be drawn after it.
     * @param obj  pointer to a chart object
     * @param id  the index of the x point in the data array
     * @see lv_chart_set_x_start_point
     */
    void set_x_start_point(uint32_t id) const noexcept { lv_chart_set_x_start_point(owner_, p_, id); }
};
static_assert(sizeof(ChartSeries) == 2 * sizeof(void*));
static_assert(__is_trivially_copyable(ChartSeries));

class ChartCursor {
protected:
    lv_obj_t* owner_ = nullptr;
    lv_chart_cursor_t* p_ = nullptr;

public:
    constexpr ChartCursor() noexcept = default;
    constexpr ChartCursor(lv_obj_t* owner, lv_chart_cursor_t* p) noexcept : owner_(owner), p_(p) {}

    constexpr lv_chart_cursor_t* raw() const noexcept { return p_; }
    constexpr lv_obj_t* owner() const noexcept { return owner_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(ChartCursor a, ChartCursor b) noexcept { return a.p_ == b.p_ && a.owner_ == b.owner_; }

    /**
     * Get the coordinate of the cursor with respect to the paddings
     * @param chart  pointer to a chart object
     * @return coordinate of the cursor as lv_point_t
     * @see lv_chart_get_cursor_point
     */
    Point get_cursor_point() const noexcept { return Point{lv_chart_get_cursor_point(owner_, p_)}; }
    /**
     * Remove a cursor
     * @param obj  pointer to chart object
     * @see lv_chart_remove_cursor
     */
    void remove_cursor() const noexcept { lv_chart_remove_cursor(owner_, p_); }
    /**
     * Stick the cursor to a point
     * @param chart  pointer to a chart object
     * @param ser  pointer to a series
     * @param point_id  the point's index or `LV_CHART_POINT_NONE` to not assign to any points.
     * @see lv_chart_set_cursor_point
     */
    void set_cursor_point(ChartSeries ser, uint32_t point_id) const noexcept { lv_chart_set_cursor_point(owner_, p_, ser.raw(), point_id); }
    /**
     * Set the coordinate of the cursor with respect to the paddings
     * @param chart  pointer to a chart object
     * @param pos  the new coordinate of cursor relative to the chart
     * @see lv_chart_set_cursor_pos
     */
    void set_cursor_pos(Point& pos) const noexcept { lv_chart_set_cursor_pos(owner_, p_, pos.ptr()); }
    /**
     * Set the X coordinate of the cursor with respect to the paddings
     * @param chart  pointer to a chart object
     * @param x  the new X coordinate of cursor relative to the chart
     * @see lv_chart_set_cursor_pos_x
     */
    void set_cursor_pos_x(int32_t x) const noexcept { lv_chart_set_cursor_pos_x(owner_, p_, x); }
    /**
     * Set the coordinate of the cursor with respect to the paddings
     * @param chart  pointer to a chart object
     * @param y  the new Y coordinate of cursor relative to the chart
     * @see lv_chart_set_cursor_pos_y
     */
    void set_cursor_pos_y(int32_t y) const noexcept { lv_chart_set_cursor_pos_y(owner_, p_, y); }
};
static_assert(sizeof(ChartCursor) == 2 * sizeof(void*));
static_assert(__is_trivially_copyable(ChartCursor));

class Chart : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_chart_class; }

    /** Chart types */
    enum class Type : int {
        /** Don't draw the series */
        None = LV_CHART_TYPE_NONE,
        /** Connect the points with lines */
        Line = LV_CHART_TYPE_LINE,
        /** Connect the points with curves */
        Curve = LV_CHART_TYPE_CURVE,
        /** Draw bars for each series */
        Bar = LV_CHART_TYPE_BAR,
        /** Draw a single stacked bar for each data point. Supports only positive values */
        Stacked = LV_CHART_TYPE_STACKED,
        /** Draw points and lines in 2D (x,y coordinates) */
        Scatter = LV_CHART_TYPE_SCATTER,
    };

    /** Chart update mode for `lv_chart_set_next` */
    enum class UpdateMode : int {
        /** Shift old data to the left and add the new one the right */
        Shift = LV_CHART_UPDATE_MODE_SHIFT,
        /** Add the new data in a circular way */
        Circular = LV_CHART_UPDATE_MODE_CIRCULAR,
    };

    /** Enumeration of the axis' */
    enum class Axis : int {
        PrimaryY = LV_CHART_AXIS_PRIMARY_Y,
        SecondaryY = LV_CHART_AXIS_SECONDARY_Y,
        PrimaryX = LV_CHART_AXIS_PRIMARY_X,
        SecondaryX = LV_CHART_AXIS_SECONDARY_X,
    };

    /**
     * Add a cursor with a given color
     * @param color  color of the cursor
     * @param dir  direction of the cursor. `LV_DIR_RIGHT/LEFT/TOP/DOWN/HOR/VER/ALL`. OR-ed values are possible
     * @return pointer to the created cursor
     * @see lv_chart_add_cursor
     */
    ChartCursor add_cursor(Color color, Dir dir) const noexcept { return ChartCursor(p_, lv_chart_add_cursor(p_, color.raw(), static_cast<lv_dir_t>(dir))); }
    /**
     * Allocate and add a data series to the chart
     * @param color  color of the data series
     * @param axis  the y axis to which the series should be attached (::LV_CHART_AXIS_PRIMARY_Y or ::LV_CHART_AXIS_SECONDARY_Y)
     * @return pointer to the allocated data series or NULL on failure
     * @see lv_chart_add_series
     */
    ChartSeries add_series(Color color, Chart::Axis axis) const noexcept { return ChartSeries(p_, lv_chart_add_series(p_, color.raw(), static_cast<lv_chart_axis_t>(axis))); }
    /**
     * Create a chart object
     * @param parent  pointer to an object, it will be the parent of the new chart
     * @return pointer to the created chart
     * @see lv_chart_create
     */
    static Chart create(Obj parent) noexcept { return Chart(lv_chart_create(parent.raw())); }
    /**
     * Get the overall offset from the chart's side to the center of the first point.
     * In case of a bar chart it will be the center of the first column group
     * @return the offset of the center
     * @see lv_chart_get_first_point_center_offset
     */
    int32_t get_first_point_center_offset() const noexcept { return lv_chart_get_first_point_center_offset(p_); }
    /**
     * Get the number of horizontal division lines
     * @return the number of horizontal division lines
     * @see lv_chart_get_hor_div_line_count
     */
    uint32_t get_hor_div_line_count() const noexcept { return lv_chart_get_hor_div_line_count(p_); }
    /**
     * Get the data point number per data line on chart
     * @return point number on each data line
     * @see lv_chart_get_point_count
     */
    uint32_t get_point_count() const noexcept { return lv_chart_get_point_count(p_); }
    /**
     * Get the index of the currently pressed point. It's the same for every series.
     * @return the index of the point [0 .. point count] or LV_CHART_POINT_ID_NONE if no point is being pressed
     * @see lv_chart_get_pressed_point
     */
    uint32_t get_pressed_point() const noexcept { return lv_chart_get_pressed_point(p_); }
    /**
     * Get the type of a chart
     * @return type of the chart (from 'lv_chart_t' enum)
     * @see lv_chart_get_type
     */
    Chart::Type get_type() const noexcept { return static_cast<Chart::Type>(lv_chart_get_type(p_)); }
    /**
     * Get the update mode of a chart
     * @return the update mode
     * @see lv_chart_get_update_mode
     */
    Chart::UpdateMode get_update_mode() const noexcept { return static_cast<Chart::UpdateMode>(lv_chart_get_update_mode(p_)); }
    /**
     * Get the number of vertical division lines
     * @return the number of vertical division lines
     * @see lv_chart_get_ver_div_line_count
     */
    uint32_t get_ver_div_line_count() const noexcept { return lv_chart_get_ver_div_line_count(p_); }
    /**
     * Refresh a chart if its data line has changed
     * @see lv_chart_refresh
     */
    void refresh() const noexcept { lv_chart_refresh(p_); }
    /**
     * Set the maximal y values on an axis
     * @param axis  `LV_CHART_AXIS_PRIMARY_Y` or `LV_CHART_AXIS_SECONDARY_Y`
     * @param max  maximum value of the y axis
     * @see lv_chart_set_axis_max_value
     */
    void set_axis_max_value(Chart::Axis axis, int32_t max) const noexcept { lv_chart_set_axis_max_value(p_, static_cast<lv_chart_axis_t>(axis), max); }
    /**
     * Set the minimal values on an axis
     * @param axis  `LV_CHART_AXIS_PRIMARY_Y` or `LV_CHART_AXIS_SECONDARY_Y`
     * @param min  minimal value of the y axis
     * @see lv_chart_set_axis_min_value
     */
    void set_axis_min_value(Chart::Axis axis, int32_t min) const noexcept { lv_chart_set_axis_min_value(p_, static_cast<lv_chart_axis_t>(axis), min); }
    /**
     * Set the minimal and maximal y values on an axis
     * @param axis  `LV_CHART_AXIS_PRIMARY_Y` or `LV_CHART_AXIS_SECONDARY_Y`
     * @param min  minimum value of the y axis
     * @param max  maximum value of the y axis
     * @see lv_chart_set_axis_range
     */
    void set_axis_range(Chart::Axis axis, int32_t min, int32_t max) const noexcept { lv_chart_set_axis_range(p_, static_cast<lv_chart_axis_t>(axis), min, max); }
    /**
     * Set the number of horizontal and vertical division lines
     * @param hdiv  number of horizontal division lines
     * @param vdiv  number of vertical division lines
     * @see lv_chart_set_div_line_count
     */
    void set_div_line_count(uint32_t hdiv, uint32_t vdiv) const noexcept { lv_chart_set_div_line_count(p_, hdiv, vdiv); }
    /**
     * Set the number of horizontal division lines
     * @param cnt  number of horizontal division lines
     * @see lv_chart_set_hor_div_line_count
     */
    void set_hor_div_line_count(uint32_t cnt) const noexcept { lv_chart_set_hor_div_line_count(p_, cnt); }
    /**
     * Set the number of points on a data line on a chart
     * @param cnt  new number of points on the data lines
     * @see lv_chart_set_point_count
     */
    void set_point_count(uint32_t cnt) const noexcept { lv_chart_set_point_count(p_, cnt); }
    /**
     * Set a new type for a chart
     * @param type  new type of the chart (from 'lv_chart_type_t' enum)
     * @see lv_chart_set_type
     */
    void set_type(Chart::Type type) const noexcept { lv_chart_set_type(p_, static_cast<lv_chart_type_t>(type)); }
    /**
     * Set update mode of the chart object. Affects
     * @param update_mode  the update mode
     * @see lv_chart_set_update_mode
     */
    void set_update_mode(Chart::UpdateMode update_mode) const noexcept { lv_chart_set_update_mode(p_, static_cast<lv_chart_update_mode_t>(update_mode)); }
    /**
     * Set the number of vertical division lines
     * @param cnt  number of vertical division lines
     * @see lv_chart_set_ver_div_line_count
     */
    void set_ver_div_line_count(uint32_t cnt) const noexcept { lv_chart_set_ver_div_line_count(p_, cnt); }
};
static_assert(sizeof(Chart) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Chart));
#endif // LV_USE_CHART != 0

} // namespace lv
