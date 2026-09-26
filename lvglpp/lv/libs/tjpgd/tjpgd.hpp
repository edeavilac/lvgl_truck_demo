#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_TJPGD
/** @see lv_tjpgd_init */
inline void tjpgd_init() noexcept { lv_tjpgd_init(); }

/** @see lv_tjpgd_deinit */
inline void tjpgd_deinit() noexcept { lv_tjpgd_deinit(); }
#endif // LV_USE_TJPGD

} // namespace lv
