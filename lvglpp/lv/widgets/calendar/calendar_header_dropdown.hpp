#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core/obj.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lv/widgets/calendar/calendar.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_CALENDAR && LV_USE_CALENDAR_HEADER_DROPDOWN
class CalendarHeaderDropdown : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_calendar_header_dropdown_class; }

    /**
     * Sets a custom calendar year list
     * @param years_list  pointer to an const char array with the years list, see lv_dropdown set_options for more information. E.g. `const char * years = "2023\n2022\n2021\n2020\n2019" Only the pointer will be saved so this variable can't be local which will be destroyed later.
     * @see lv_calendar_header_dropdown_set_year_list
     */
    void set_year_list(const char* years_list) const noexcept { lv_calendar_header_dropdown_set_year_list(p_, years_list); }
};
static_assert(sizeof(CalendarHeaderDropdown) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(CalendarHeaderDropdown));
#endif // LV_USE_CALENDAR && LV_USE_CALENDAR_HEADER_DROPDOWN

#if (LV_USE_CALENDAR) && (LV_USE_CALENDAR && LV_USE_CALENDAR_HEADER_DROPDOWN)
inline Obj Calendar::add_header_dropdown() const noexcept { return Obj(lv_calendar_add_header_dropdown(p_)); }
#endif // (LV_USE_CALENDAR) && (LV_USE_CALENDAR && LV_USE_CALENDAR_HEADER_DROPDOWN)

} // namespace lv
