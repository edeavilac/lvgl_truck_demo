#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_GLTF
/**
 * Get a plane that faces upward, centered at a given height
 * @param elevation  elevation of the ground plane, in world units. this is usually zero
 * @return ground plane
 * @see lv_get_ground_plane
 */
inline lv_3dplane_t _3dmath_get_ground_plane(float elevation) noexcept { return lv_get_ground_plane(elevation); }
#endif // LV_USE_GLTF

} // namespace lv
