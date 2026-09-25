#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

class Iter {
protected:
    lv_iter_t* p_ = nullptr;

public:
    constexpr Iter() noexcept = default;  /**< the "no object" handle */
    constexpr explicit Iter(lv_iter_t* p) noexcept : p_(p) {}

    constexpr lv_iter_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(Iter a, Iter b) noexcept { return a.p_ == b.p_; }

    /**
     * Create an iterator based on an instance, and then the next element of the iterator can be obtained through lv_iter_next,
     * In order to obtain the next operation in a unified and abstract way.
     * @param instance  The instance to be iterated
     * @param elem_size  The size of the element to be iterated in bytes
     * @param context_size  The size of the context to be passed to the next_cb in bytes
     * @param next_cb  The callback function to get the next element
     * @return The iterator object
     * @see lv_iter_create
     */
    static Iter create(void* instance, uint32_t elem_size, uint32_t context_size, lv_iter_next_cb next_cb) noexcept { return Iter(lv_iter_create(instance, elem_size, context_size, next_cb)); }
    /**
     * Takes the function itself as a template argument, so its real parameter types survive: the C idiom CASTS the pointer, which is undefined whenever they differ, and between the versions they do.
     * Create an iterator based on an instance, and then the next element of the iterator can be obtained through lv_iter_next,
     * In order to obtain the next operation in a unified and abstract way.
     * @param instance  The instance to be iterated
     * @param elem_size  The size of the element to be iterated in bytes
     * @param context_size  The size of the context to be passed to the next_cb in bytes
     * @param next_cb  The callback function to get the next element
     * @return The iterator object
     * @see lv_iter_create
     */
    template <auto Fn>
    static Iter create(void* instance, uint32_t elem_size, uint32_t context_size) noexcept { return Iter(lv_iter_create(instance, elem_size, context_size, &detail::IterNextCbThunk<Fn>::call)); }
    /**
     * Destroy the iterator object, and release the context. Other resources allocated by the user are not released.
     * The user needs to release it by itself.
     * @see lv_iter_destroy
     */
    void destroy() const noexcept { lv_iter_destroy(p_); }
    /**
     * Get the context of the iterator. You can use it to store some temporary variables associated with current iterator..
     * @return the iter context
     * @see lv_iter_get_context
     */
    void* get_context() const noexcept { return lv_iter_get_context(p_); }
    /**
     * Inspect the element of the iterator. The callback function will be called for each element of the iterator.
     * @param inspect_cb  The callback function to inspect the element
     * @see lv_iter_inspect
     */
    void inspect(lv_iter_inspect_cb inspect_cb) const noexcept { lv_iter_inspect(p_, inspect_cb); }
    /**
     * Takes the function itself as a template argument, so its real parameter types survive: the C idiom CASTS the pointer, which is undefined whenever they differ, and between the versions they do.
     * Inspect the element of the iterator. The callback function will be called for each element of the iterator.
     * @param inspect_cb  The callback function to inspect the element
     * @see lv_iter_inspect
     */
    template <auto Fn>
    void inspect() const noexcept { lv_iter_inspect(p_, &detail::IterInspectCbThunk<Fn>::call); }
    /**
     * Make the iterator peekable, which means that the user can peek the next element without advancing the iterator.
     * @param capacity  The capacity of the peek buffer
     * @see lv_iter_make_peekable
     */
    void make_peekable(uint32_t capacity) const noexcept { lv_iter_make_peekable(p_, capacity); }
    /**
     * Get the next element of the iterator.
     * @param elem  The pointer to store the next element
     * @return LV_RESULT_OK: Get the next element successfully LV_RESULT_INVALID: The next element is invalid
     * @see lv_iter_next
     */
    Result next(void* elem) const noexcept { return static_cast<Result>(lv_iter_next(p_, elem)); }
    /**
     * Peek the next element of the iterator without advancing the iterator.
     * @param elem  The pointer to store the next element
     * @return LV_RESULT_OK: Peek the next element successfully LV_RESULT_INVALID: The next element is invalid
     * @see lv_iter_peek
     */
    Result peek(void* elem) const noexcept { return static_cast<Result>(lv_iter_peek(p_, elem)); }
    /**
     * Only advance the iterator without getting the next element.
     * @return LV_RESULT_OK: Peek the next element successfully LV_RESULT_INVALID: The next element is invalid
     * @see lv_iter_peek_advance
     */
    Result peek_advance() const noexcept { return static_cast<Result>(lv_iter_peek_advance(p_)); }
    /**
     * Reset the peek cursor to the `next` cursor.
     * @return LV_RESULT_OK: Reset the peek buffer successfully LV_RESULT_INVALID: The peek buffer is invalid
     * @see lv_iter_peek_reset
     */
    Result peek_reset() const noexcept { return static_cast<Result>(lv_iter_peek_reset(p_)); }
};
static_assert(sizeof(Iter) == sizeof(lv_iter_t*));
static_assert(__is_trivially_copyable(Iter));

} // namespace lv
