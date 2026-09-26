#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core/obj.hpp"
#include "lv/display/display.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_SYSMON
/**
 * Create a new system monitor label
 * @param disp  create the sys. mon. on this display's system layer
 * @return the create label
 * @see lv_sysmon_create
 */
inline Obj sysmon_create(Display disp) noexcept { return Obj(lv_sysmon_create(disp.raw())); }
#endif // LV_USE_SYSMON

#if (LV_USE_SYSMON) && (LV_USE_PERF_MONITOR)
/**
 * Show system performance monitor: CPU usage and FPS count
 * @param disp  target display, NULL: use the default displays
 * @see lv_sysmon_show_performance
 */
inline void sysmon_show_performance(Display disp) noexcept { lv_sysmon_show_performance(disp.raw()); }

/**
 * Hide system performance monitor
 * @param disp  target display, NULL: use the default
 * @see lv_sysmon_hide_performance
 */
inline void sysmon_hide_performance(Display disp) noexcept { lv_sysmon_hide_performance(disp.raw()); }

/**
 * Dump the FPS data recorded between the last and current dump call.
 * @param disp  target display, NULL: use the default
 * @see lv_sysmon_performance_dump
 */
inline void sysmon_performance_dump(Display disp) noexcept { lv_sysmon_performance_dump(disp.raw()); }

/**
 * Resume the system performance monitor.
 * @param disp  target display, NULL: use the default
 * @see lv_sysmon_performance_resume
 */
inline void sysmon_performance_resume(Display disp) noexcept { lv_sysmon_performance_resume(disp.raw()); }

/**
 * Pause the system performance monitor.
 * @param disp  target display, NULL: use the default
 * @see lv_sysmon_performance_pause
 */
inline void sysmon_performance_pause(Display disp) noexcept { lv_sysmon_performance_pause(disp.raw()); }
#endif // (LV_USE_SYSMON) && (LV_USE_PERF_MONITOR)

#if (LV_USE_SYSMON) && (LV_USE_MEM_MONITOR)
/**
 * Show system memory monitor: used memory and the memory fragmentation
 * @param disp  target display, NULL: use the default displays
 * @see lv_sysmon_show_memory
 */
inline void sysmon_show_memory(Display disp) noexcept { lv_sysmon_show_memory(disp.raw()); }

/**
 * Hide system memory monitor
 * @param disp  target display, NULL: use the default displays
 * @see lv_sysmon_hide_memory
 */
inline void sysmon_hide_memory(Display disp) noexcept { lv_sysmon_hide_memory(disp.raw()); }
#endif // (LV_USE_SYSMON) && (LV_USE_MEM_MONITOR)

} // namespace lv
