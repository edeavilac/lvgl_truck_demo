#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_LOG
/**
 * Register custom print/write function to call when a log is added.
 * It can format its "File path", "Line number" and "Description" as required
 * and send the formatted log message to a console or serial port.
 * @param print_cb  a function pointer to print a log
 * @see lv_log_register_print_cb
 */
inline void log_register_print_cb(lv_log_print_g_cb_t print_cb) noexcept { lv_log_register_print_cb(print_cb); }

/**
 * Print a log message via `printf` if enabled with `LV_LOG_PRINTF` in `lv_conf.h`
 * and/or a print callback if registered with `lv_log_register_print_cb`
 * @param format  printf-like format string
 * @see lv_log
 */
template <typename... A>
inline void log_log(const char* format, A... args) noexcept { lv_log(format, args...); }

/**
 * Add a log
 * @param level  the level of log. (From `lv_log_level_t` enum)
 * @param file  name of the file when the log added
 * @param line  line number in the source code where the log added
 * @param func  name of the function when the log added
 * @param format  printf-like format string
 * @see lv_log_add
 */
template <typename... A>
inline void log_add(lv_log_level_t level, const char* file, int32_t line, const char* func, const char* format, A... args) noexcept { lv_log_add(level, file, line, func, format, args...); }
#endif // LV_USE_LOG

} // namespace lv
