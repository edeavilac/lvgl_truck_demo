#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lv/widgets/calendar/calendar.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_CALENDAR && LV_USE_CALENDAR_CHINESE
/**
 * Get the name of the day
 * @param gregorian  to obtain the gregorian time for the name
 * @return return the name of the day
 * @see lv_calendar_get_day_name
 */
inline const char* calendar_get_day_name(lv_calendar_date_t* gregorian) noexcept { return lv_calendar_get_day_name(gregorian); }

/**
 * Get the chinese time of the gregorian time (reference: https://www.cnblogs.com/liyang31tg/p/4123171.html)
 * @param gregorian_time  need to convert to chinese time in gregorian time
 * @param chinese_time  the chinese time convert from gregorian time
 * @see lv_calendar_gregorian_to_chinese
 */
inline void calendar_gregorian_to_chinese(lv_calendar_date_t* gregorian_time, lv_calendar_chinese_t* chinese_time) noexcept { lv_calendar_gregorian_to_chinese(gregorian_time, chinese_time); }
#endif // LV_USE_CALENDAR && LV_USE_CALENDAR_CHINESE

#if (LV_USE_CALENDAR) && (LV_USE_CALENDAR && LV_USE_CALENDAR_CHINESE)
inline void Calendar::set_chinese_mode(bool en) const noexcept { lv_calendar_set_chinese_mode(p_, en); }
#endif // (LV_USE_CALENDAR) && (LV_USE_CALENDAR && LV_USE_CALENDAR_CHINESE)

} // namespace lv
