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

#if LV_USE_CALENDAR
class Calendar : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_calendar_class; }

    #if LV_USE_CALENDAR && LV_USE_CALENDAR_HEADER_ARROW
    /**
     * Create a calendar header with drop-drowns to select the year and month
     * @return the created header
     * @see lv_calendar_add_header_arrow
     */
    Obj add_header_arrow() const noexcept;
    #endif // LV_USE_CALENDAR && LV_USE_CALENDAR_HEADER_ARROW

    #if LV_USE_CALENDAR && LV_USE_CALENDAR_HEADER_DROPDOWN
    /**
     * Create a calendar header with drop-drowns to select the year and month
     * @return the created header
     * @see lv_calendar_add_header_dropdown
     */
    Obj add_header_dropdown() const noexcept;
    #endif // LV_USE_CALENDAR && LV_USE_CALENDAR_HEADER_DROPDOWN

    /**
     * Create a calendar widget
     * @param parent  pointer to an object, it will be the parent of the new calendar
     * @return pointer the created calendar
     * @see lv_calendar_create
     */
    static Calendar create(Obj parent) noexcept { return Calendar(lv_calendar_create(parent.raw())); }
    /**
     * Get the button matrix object of the calendar.
     * It shows the dates and day names.
     * @return pointer to a the button matrix
     * @see lv_calendar_get_btnmatrix
     */
    Obj get_btnmatrix() const noexcept { return Obj(lv_calendar_get_btnmatrix(p_)); }
    /**
     * Get the highlighted dates
     * @return pointer to an `lv_calendar_date_t` array containing the dates.
     * @see lv_calendar_get_highlighted_dates
     */
    lv_calendar_date_t* get_highlighted_dates() const noexcept { return lv_calendar_get_highlighted_dates(p_); }
    /**
     * Get the number of the highlighted dates
     * @return number of highlighted days
     * @see lv_calendar_get_highlighted_dates_num
     */
    uint32_t get_highlighted_dates_num() const noexcept { return lv_calendar_get_highlighted_dates_num(p_); }
    /**
     * Get the currently pressed day
     * @param date  store the pressed date here
     * @return LV_RESULT_OK: there is a valid pressed date LV_RESULT_INVALID: there is no pressed data
     * @see lv_calendar_get_pressed_date
     */
    Result get_pressed_date(lv_calendar_date_t* date) const noexcept { return static_cast<Result>(lv_calendar_get_pressed_date(p_, date)); }
    /**
     * Get the currently showed
     * @return pointer to an `lv_calendar_date_t` variable containing the date is being shown.
     * @see lv_calendar_get_showed_date
     */
    const lv_calendar_date_t* get_showed_date() const noexcept { return lv_calendar_get_showed_date(p_); }
    /**
     * Get the today's date
     * @return return pointer to an `lv_calendar_date_t` variable containing the date of today.
     * @see lv_calendar_get_today_date
     */
    const lv_calendar_date_t* get_today_date() const noexcept { return lv_calendar_get_today_date(p_); }
    #if LV_USE_CALENDAR && LV_USE_CALENDAR_CHINESE
    /**
     * Enable the chinese calendar.
     * @param en  true: enable chinese calendar; false: disable
     * @see lv_calendar_set_chinese_mode
     */
    void set_chinese_mode(bool en) const noexcept;
    #endif // LV_USE_CALENDAR && LV_USE_CALENDAR_CHINESE

    /**
     * Set the name of the days
     * @param day_names  pointer to an array with the names. E.g. `const char * days[7] = {"Sun", "Mon", ...}` Only the pointer will be saved so this variable can't be local which will be destroyed later.
     * @see lv_calendar_set_day_names
     */
    void set_day_names(const char** day_names) const noexcept { lv_calendar_set_day_names(p_, day_names); }
    /**
     * Set the highlighted dates
     * @param highlighted  pointer to an `lv_calendar_date_t` array containing the dates. Only the pointer will be saved so this variable can't be local which will be destroyed later.
     * @param date_num  number of dates in the array
     * @see lv_calendar_set_highlighted_dates
     */
    void set_highlighted_dates(lv_calendar_date_t* highlighted, size_t date_num) const noexcept { lv_calendar_set_highlighted_dates(p_, highlighted, date_num); }
    /**
     * Set the currently shown year and month at once
     * @param year  shown year
     * @param month  shown month [1..12]
     * @see lv_calendar_set_month_shown
     */
    void set_month_shown(uint32_t year, uint32_t month) const noexcept { lv_calendar_set_month_shown(p_, year, month); }
    /**
     * Set the currently shown month
     * @param month  shown month [1..12]
     * @see lv_calendar_set_shown_month
     */
    void set_shown_month(uint32_t month) const noexcept { lv_calendar_set_shown_month(p_, month); }
    /**
     * Set the currently shown year
     * @param year  shown year
     * @see lv_calendar_set_shown_year
     */
    void set_shown_year(uint32_t year) const noexcept { lv_calendar_set_shown_year(p_, year); }
    /**
     * Set the today's year, month and day at once
     * @param year  today's year
     * @param month  today's month [1..12]
     * @param day  today's day [1..31]
     * @see lv_calendar_set_today_date
     */
    void set_today_date(uint32_t year, uint32_t month, uint32_t day) const noexcept { lv_calendar_set_today_date(p_, year, month, day); }
    /**
     * Set the today's year
     * @param day  today's day [1..31]
     * @see lv_calendar_set_today_day
     */
    void set_today_day(uint32_t day) const noexcept { lv_calendar_set_today_day(p_, day); }
    /**
     * Set the today's year
     * @param month  today's month [1..12]
     * @see lv_calendar_set_today_month
     */
    void set_today_month(uint32_t month) const noexcept { lv_calendar_set_today_month(p_, month); }
    /**
     * Set the today's year
     * @param year  today's year
     * @see lv_calendar_set_today_year
     */
    void set_today_year(uint32_t year) const noexcept { lv_calendar_set_today_year(p_, year); }
};
static_assert(sizeof(Calendar) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Calendar));
#endif // LV_USE_CALENDAR

} // namespace lv
