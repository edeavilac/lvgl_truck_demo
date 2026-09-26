#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

/**
 * Create a new layout
 * @param callbacks  the layout callbacks
 * @param user_data  custom data that will be passed when a callback is invoked
 * @return the ID of the new layout
 * @see lv_layout_create
 */
inline uint32_t layout_create(lv_layout_callbacks_t callbacks, void* user_data) noexcept { return lv_layout_create(callbacks, user_data); }

/**
 * DEPRECATED: `lv_layout_register` is deprecated. `lv_layout_create` should be used instead.
 * Register a new layout
 * @param cb  the layout update callback
 * @param user_data  custom data that will be passed to `cb`
 * @return the ID of the new layout
 * @see lv_layout_register
 */
inline uint32_t layout_register(lv_layout_update_cb_t cb, void* user_data) noexcept { return lv_layout_register(cb, user_data); }

/**
 * Takes any callable instead of the C pair.
 * DEPRECATED: `lv_layout_register` is deprecated. `lv_layout_create` should be used instead.
 * Register a new layout
 * @param cb  the layout update callback
 * @param user_data  custom data that will be passed to `cb`
 * @return the ID of the new layout
 * @see lv_layout_register
 */
template <class F>
inline uint32_t layout_register(F&& f) noexcept { return lv_layout_register(detail::LayoutUpdateCbClosure<std::decay_t<F>>::fn(f), detail::LayoutUpdateCbClosure<std::decay_t<F>>::state(f)); }

} // namespace lv
