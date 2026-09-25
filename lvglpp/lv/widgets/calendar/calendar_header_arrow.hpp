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

#if (LV_USE_CALENDAR_HEADER_ARROW) && (LV_USE_CALENDAR && LV_USE_CALENDAR_HEADER_ARROW)
class CalendarHeaderArrow : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_calendar_header_arrow_class; }

};
static_assert(sizeof(CalendarHeaderArrow) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(CalendarHeaderArrow));
#endif // (LV_USE_CALENDAR_HEADER_ARROW) && (LV_USE_CALENDAR && LV_USE_CALENDAR_HEADER_ARROW)

#if (LV_USE_CALENDAR) && (LV_USE_CALENDAR && LV_USE_CALENDAR_HEADER_ARROW)
inline Obj Calendar::add_header_arrow() const noexcept { return Obj(lv_calendar_add_header_arrow(p_)); }
#endif // (LV_USE_CALENDAR) && (LV_USE_CALENDAR && LV_USE_CALENDAR_HEADER_ARROW)

} // namespace lv
