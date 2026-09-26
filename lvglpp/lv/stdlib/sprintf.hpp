#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

/** @see lv_snprintf */
template <typename... A>
inline int32_t sprintf_snprintf(char* buffer, size_t count, const char* format, A... args) noexcept { return lv_snprintf(buffer, count, format, args...); }

/** @see lv_vsnprintf */
inline int32_t sprintf_vsnprintf(char* buffer, size_t count, const char* format, va_list va) noexcept { return lv_vsnprintf(buffer, count, format, va); }

} // namespace lv
