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
 * Call an asynchronous function the next time lv_timer_handler() is run. This function is likely to return
 * **before** the call actually happens!
 * @param async_xcb  a callback which is the task itself. (the 'x' in the argument name indicates that it's not a fully generic function because it not follows the `func_name(object, callback, ...)` convention)
 * @param user_data  custom parameter
 * @see lv_async_call
 */
inline Result async_call(lv_async_cb_t async_xcb, void* user_data) noexcept { return static_cast<Result>(lv_async_call(async_xcb, user_data)); }

/**
 * Takes any callable instead of the C pair.
 * Call an asynchronous function the next time lv_timer_handler() is run. This function is likely to return
 * **before** the call actually happens!
 * @param async_xcb  a callback which is the task itself. (the 'x' in the argument name indicates that it's not a fully generic function because it not follows the `func_name(object, callback, ...)` convention)
 * @param user_data  custom parameter
 * @see lv_async_call
 */
template <class F>
inline Result async_call(F&& f) noexcept { return static_cast<Result>(lv_async_call(detail::AsyncCbClosure<std::decay_t<F>>::fn(f), detail::AsyncCbClosure<std::decay_t<F>>::state(f))); }

/**
 * Cancel an asynchronous function call
 * @param async_xcb  a callback which is the task itself.
 * @param user_data  custom parameter
 * @see lv_async_call_cancel
 */
inline Result async_call_cancel(lv_async_cb_t async_xcb, void* user_data) noexcept { return static_cast<Result>(lv_async_call_cancel(async_xcb, user_data)); }

} // namespace lv
