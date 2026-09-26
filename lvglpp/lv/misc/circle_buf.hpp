#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/misc/array.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

class CircleBuf {
protected:
    lv_circle_buf_t* p_ = nullptr;

public:
    constexpr CircleBuf() noexcept = default;  /**< the "no object" handle */
    constexpr explicit CircleBuf(lv_circle_buf_t* p) noexcept : p_(p) {}

    constexpr lv_circle_buf_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(CircleBuf a, CircleBuf b) noexcept { return a.p_ == b.p_; }

    /**
     * Get the capacity of the buffer
     * @return the maximum number of elements in the buffer
     * @see lv_circle_buf_capacity
     */
    uint32_t capacity() const noexcept { return lv_circle_buf_capacity(p_); }
    /**
     * Create a circle buffer
     * @param capacity  the maximum number of elements in the buffer
     * @param element_size  the size of an element in bytes
     * @return pointer to the created buffer
     * @see lv_circle_buf_create
     */
    static CircleBuf create(uint32_t capacity, uint32_t element_size) noexcept { return CircleBuf(lv_circle_buf_create(capacity, element_size)); }
    /**
     * Destroy a circle buffer
     * @see lv_circle_buf_destroy
     */
    void destroy() const noexcept { lv_circle_buf_destroy(p_); }
    /**
     * Fill the buffer with values
     * @param count  the number of values to fill
     * @param fill_cb  the callback function to fill the buffer
     * @param user_data  
     * @return the number of values filled
     * @see lv_circle_buf_fill
     */
    uint32_t fill(uint32_t count, lv_circle_buf_fill_cb_t fill_cb, void* user_data) const noexcept { return lv_circle_buf_fill(p_, count, fill_cb, user_data); }
    /**
     * Takes any callable instead of the C pair: the closure travels in the single void* LVGL stores, and the trampoline is chosen by its type.
     * Fill the buffer with values
     * @param count  the number of values to fill
     * @param fill_cb  the callback function to fill the buffer
     * @param user_data  
     * @return the number of values filled
     * @see lv_circle_buf_fill
     */
    template <class F>
    uint32_t fill(uint32_t count, F&& f) const noexcept { return lv_circle_buf_fill(p_, count, detail::CircleBufFillCbClosure<std::decay_t<F>>::fn(f), detail::CircleBufFillCbClosure<std::decay_t<F>>::state(f)); }
    /**
     * Get the head of the buffer
     * @return pointer to the head of the buffer
     * @see lv_circle_buf_head
     */
    void* head() const noexcept { return lv_circle_buf_head(p_); }
    /**
     * Check if the buffer is empty
     * @return true: the buffer is empty; false: the buffer is not empty
     * @see lv_circle_buf_is_empty
     */
    bool is_empty() const noexcept { return lv_circle_buf_is_empty(p_); }
    /**
     * Check if the buffer is full
     * @return true: the buffer is full; false: the buffer is not full
     * @see lv_circle_buf_is_full
     */
    bool is_full() const noexcept { return lv_circle_buf_is_full(p_); }
    /**
     * Peek a value
     * @param data  pointer to a variable to store the peeked value
     * @return LV_RESULT_OK: the value is peeked; LV_RESULT_INVALID: the value is not peeked
     * @see lv_circle_buf_peek
     */
    Result peek(void* data) const noexcept { return static_cast<Result>(lv_circle_buf_peek(p_, data)); }
    /**
     * Peek a value at an index
     * @param index  the index of the value to peek, if the index is greater than the size of the buffer, it will return looply.
     * @param data  pointer to a variable to store the peeked value
     * @return LV_RESULT_OK: the value is peeked; LV_RESULT_INVALID: the value is not peeked
     * @see lv_circle_buf_peek_at
     */
    Result peek_at(uint32_t index, void* data) const noexcept { return static_cast<Result>(lv_circle_buf_peek_at(p_, index, data)); }
    /**
     * Read a value
     * @param data  pointer to a variable to store the read value
     * @return LV_RESULT_OK: the value is read; LV_RESULT_INVALID: the value is not read
     * @see lv_circle_buf_read
     */
    Result read(void* data) const noexcept { return static_cast<Result>(lv_circle_buf_read(p_, data)); }
    /**
     * Get the remaining space in the buffer
     * @return the number of elements that can be written to the buffer
     * @see lv_circle_buf_remain
     */
    uint32_t remain() const noexcept { return lv_circle_buf_remain(p_); }
    /**
     * Reset the buffer
     * @see lv_circle_buf_reset
     */
    void reset() const noexcept { lv_circle_buf_reset(p_); }
    /**
     * Resize the buffer
     * @param capacity  the new capacity of the buffer
     * @return LV_RESULT_OK: the buffer is resized; LV_RESULT_INVALID: the buffer is not resized
     * @see lv_circle_buf_resize
     */
    Result resize(uint32_t capacity) const noexcept { return static_cast<Result>(lv_circle_buf_resize(p_, capacity)); }
    /**
     * Get the size of the buffer
     * @return the number of elements in the buffer
     * @see lv_circle_buf_size
     */
    uint32_t size() const noexcept { return lv_circle_buf_size(p_); }
    /**
     * Skip a value
     * @return LV_RESULT_OK: the value is skipped; LV_RESULT_INVALID: the value is not skipped
     * @see lv_circle_buf_skip
     */
    Result skip() const noexcept { return static_cast<Result>(lv_circle_buf_skip(p_)); }
    /**
     * Get the tail of the buffer
     * @return pointer to the tail of the buffer
     * @see lv_circle_buf_tail
     */
    void* tail() const noexcept { return lv_circle_buf_tail(p_); }
    /**
     * Write a value
     * @param data  pointer to the value to write
     * @return LV_RESULT_OK: the value is written; LV_RESULT_INVALID: the value is not written
     * @see lv_circle_buf_write
     */
    Result write(const void* data) const noexcept { return static_cast<Result>(lv_circle_buf_write(p_, data)); }
};
static_assert(sizeof(CircleBuf) == sizeof(lv_circle_buf_t*));
static_assert(__is_trivially_copyable(CircleBuf));

/**
 * Create a circle buffer from an existing buffer
 * @param buf  pointer to a buffer
 * @param capacity  the maximum number of elements in the buffer
 * @param element_size  the size of an element in bytes
 * @return pointer to the created buffer
 * @see lv_circle_buf_create_from_buf
 */
inline CircleBuf circle_buf_create_from_buf(void* buf, uint32_t capacity, uint32_t element_size) noexcept { return CircleBuf(lv_circle_buf_create_from_buf(buf, capacity, element_size)); }

/**
 * Create a circle buffer from an existing array
 * @param array  pointer to an array
 * @return pointer to the created buffer
 * @see lv_circle_buf_create_from_array
 */
inline CircleBuf circle_buf_create_from_array(Array& array) noexcept { return CircleBuf(lv_circle_buf_create_from_array(array.raw())); }

} // namespace lv
