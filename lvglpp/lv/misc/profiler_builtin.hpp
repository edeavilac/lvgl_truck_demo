#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_PROFILER && LV_USE_PROFILER_BUILTIN
/**
 * Initialize the built-in profiler with the given configuration
 * @param config  Pointer to the configuration structure of the built-in profiler
 * @see lv_profiler_builtin_init
 */
inline void profiler_builtin_init(ProfilerBuiltinConfig config) noexcept { lv_profiler_builtin_init(config.raw()); }

/**
 * Uninitialize the built-in profiler
 * @see lv_profiler_builtin_uninit
 */
inline void profiler_builtin_uninit() noexcept { lv_profiler_builtin_uninit(); }

/**
 * Enable or disable the built-in profiler
 * @param enable  true to enable the built-in profiler, false to disable
 * @see lv_profiler_builtin_set_enable
 */
inline void profiler_builtin_set_enable(bool enable) noexcept { lv_profiler_builtin_set_enable(enable); }

/**
 * Flush the profiling data to the console
 * @see lv_profiler_builtin_flush
 */
inline void profiler_builtin_flush() noexcept { lv_profiler_builtin_flush(); }

/**
 * Write the profiling data for a function with the given tag
 * @param func  Name of the function being profiled
 * @param tag  Tag to associate with the profiling data for the function
 * @see lv_profiler_builtin_write
 */
inline void profiler_builtin_write(const char* func, char tag) noexcept { lv_profiler_builtin_write(func, tag); }
#endif // LV_USE_PROFILER && LV_USE_PROFILER_BUILTIN

#if LV_USE_PROFILER && LV_USE_PROFILER_BUILTIN
inline void ProfilerBuiltinConfig::init() const noexcept { lv_profiler_builtin_config_init(p_); }
#endif // LV_USE_PROFILER && LV_USE_PROFILER_BUILTIN

} // namespace lv
