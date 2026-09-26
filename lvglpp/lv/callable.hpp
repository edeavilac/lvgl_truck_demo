#pragma once
//
// "One pointer of state" -- the mechanism, on its own.
//
// PRELUDE (D-C6). This is not an events concept, which is exactly why it is not in the events
// file and why no term produces it. LVGL hands the binding exactly one `void*` in four unrelated
// places, and the same three questions come up each time: does the callable fit in it, how does it
// get in, and where does the memory come from if it does not.
//
//   lv_obj_add_event_cb(obj, cb, filter, USER_DATA)      -> lv_event_get_user_data(e)
//   lv_timer_create(cb, period, USER_DATA)               -> timer->user_data
//   lv_async_call(cb, USER_DATA)                         -> the callback's only argument
//   lv_subject_add_observer(subject, cb, USER_DATA)      -> observer->user_data
//
// Nothing in this file mentions an event, and nothing in it names an LVGL symbol -- which is what
// lets one copy serve both versions. The allocator seam does name one, and is therefore NOT here:
// v8 spells it lv_mem_alloc/lv_mem_free and v9 lv_malloc/lv_free, so it is generated from the
// model like everything else that differs between the two.

#include "lvgl.h"

#include <cstring>
#include <type_traits>

namespace lv::detail {

/**
 * Can this callable ride inside the single `void*` LVGL gives us?
 *
 * Trivially copyable AND trivially destructible, not just small: the closure is memcpy'd into an
 * integer-sized slot and never destroyed, so a type with either non-trivial operation would be
 * silently miscopied or silently leaked.
 */
template <class F>
inline constexpr bool fits_user_data =
        sizeof(F) <= sizeof(void*)
        && alignof(F) <= alignof(void*)
        && std::is_trivially_copyable_v<F>
        && std::is_trivially_destructible_v<F>;

template <class F>
inline void* pack(const F& f) noexcept {
    void* ud = nullptr;
    std::memcpy(&ud, &f, sizeof(F));
    return ud;
}

/**
 * The inverse. `alignas` + memcpy rather than a cast: the slot is a `void*`, and reading it as an
 * `F` through a pointer cast is a strict-aliasing violation that -O2 is entitled to act on.
 */
template <class F>
inline F unpack(void* ud) noexcept {
    alignas(F) unsigned char storage[sizeof(F)];
    std::memcpy(storage, &ud, sizeof(F));
    return *reinterpret_cast<F*>(storage);
}

} // namespace lv::detail
