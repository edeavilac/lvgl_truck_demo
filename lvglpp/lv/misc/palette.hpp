#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

/** @see lv_palette_main */
inline Color palette_main(Palette p) noexcept { return Color{lv_palette_main(static_cast<lv_palette_t>(p))}; }

/** @see lv_palette_lighten */
inline Color palette_lighten(Palette p, uint8_t lvl) noexcept { return Color{lv_palette_lighten(static_cast<lv_palette_t>(p), lvl)}; }

/** @see lv_palette_darken */
inline Color palette_darken(Palette p, uint8_t lvl) noexcept { return Color{lv_palette_darken(static_cast<lv_palette_t>(p), lvl)}; }

} // namespace lv
