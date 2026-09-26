#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

class Array {
protected:
    lv_array_t s_;

public:
    Array(uint32_t capacity, uint32_t element_size) noexcept { lv_array_init(&s_, capacity, element_size); }
    Array(void* buf, uint32_t capacity, uint32_t element_size) noexcept { lv_array_init_from_buf(&s_, buf, capacity, element_size); }
    ~Array() { lv_array_deinit(&s_); }
protected:
    Array() noexcept = default;
public:


    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;
    Array(Array&&) = delete;
    Array& operator=(Array&&) = delete;

    lv_array_t* raw() noexcept { return &s_; }

    /**
     * Assigns one content to the array, replacing its current content.
     * @param index  the index of the element to replace
     * @param value  pointer to the elements to add
     * @return true: success; false: error
     * @see lv_array_assign
     */
    Result assign(uint32_t index, const void* value) noexcept { return static_cast<Result>(lv_array_assign(&s_, index, value)); }
    /**
     * Returns a pointer to the element at position n in the array.
     * @param index  the index of the element to return
     * @return a pointer to the requested element, NULL if `index` is out of range
     * @see lv_array_at
     */
    void* at(uint32_t index) const noexcept { return lv_array_at(&s_, index); }
    /**
     * Returns a pointer to the last element in the array.
     * @see lv_array_back
     */
    void* back() const noexcept { return lv_array_back(&s_); }
    /**
     * Return the capacity of the array, i.e. how many elements can be stored.
     * @return the capacity of the array
     * @see lv_array_capacity
     */
    uint32_t capacity() const noexcept { return lv_array_capacity(&s_); }
    /**
     * Remove all elements in array.
     * @see lv_array_clear
     */
    Array& clear() noexcept { lv_array_clear(&s_); return *this; }
    /**
     * Concatenate two arrays. Adds new elements to the end of the array.
     * @param other  pointer to the array to concatenate
     * @return LV_RESULT_OK: success, otherwise: error
     * @see lv_array_concat
     */
    Result concat(Array& other) noexcept { return static_cast<Result>(lv_array_concat(&s_, other.raw())); }
    /**
     * Copy an array to another.
     * @param source  pointer to an `lv_array_t` variable to copy from
     * @see lv_array_copy
     */
    Array& copy(Array& source) noexcept { lv_array_copy(&s_, source.raw()); return *this; }
    /**
     * Deinit the array, and free the allocated memory
     * @see lv_array_deinit
     */
    Array& deinit() noexcept { lv_array_deinit(&s_); return *this; }
    /**
     * Remove from the array either a single element or a range of elements ([start, end)).
     * @param start  the index of the first element to be removed
     * @param end  the index of the first element that is not to be removed
     * @return LV_RESULT_OK: success, otherwise: error
     * @see lv_array_erase
     */
    Result erase(uint32_t start, uint32_t end) noexcept { return static_cast<Result>(lv_array_erase(&s_, start, end)); }
    /**
     * Returns a pointer to the first element in the array.
     * @return a pointer to the first element in the array
     * @see lv_array_front
     */
    void* front() const noexcept { return lv_array_front(&s_); }
    /**
     * Return if the array is empty
     * @return true: array is empty; false: array is not empty
     * @see lv_array_is_empty
     */
    bool is_empty() const noexcept { return lv_array_is_empty(&s_); }
    /**
     * Return if the array is full
     * @return true: array is full; false: array is not full
     * @see lv_array_is_full
     */
    bool is_full() const noexcept { return lv_array_is_full(&s_); }
    /**
     * Push back element. Adds a new element to the end of the array.
     * If the array capacity is not enough for the new element, the array will be resized automatically.
     * @param element  pointer to the element to add. NULL to push an empty element.
     * @return LV_RESULT_OK: success, otherwise: error
     * @see lv_array_push_back
     */
    Result push_back(const void* element) noexcept { return static_cast<Result>(lv_array_push_back(&s_, element)); }
    /**
     * Remove the element at the specified position in the array.
     * This function keeps the array order. Complexity is O(n)
     * @param index  the index of the element to remove
     * @return LV_RESULT_OK: success, otherwise: error
     * @see lv_array_remove
     */
    Result remove(uint32_t index) noexcept { return static_cast<Result>(lv_array_remove(&s_, index)); }
    /**
     * Remove the element at the specified position in the array.
     * This function does not guarantee the array order. Complexity is O(1)
     * @param index  the index of the element to remove
     * @return LV_RESULT_OK: success, otherwise: error
     * @see lv_array_remove_unordered
     */
    Result remove_unordered(uint32_t index) noexcept { return static_cast<Result>(lv_array_remove_unordered(&s_, index)); }
    /**
     * Resize the array to the given capacity.
     * @param new_capacity  the new capacity of the array
     * @see lv_array_resize
     */
    bool resize(uint32_t new_capacity) noexcept { return lv_array_resize(&s_, new_capacity); }
    /**
     * Shrink the memory capacity of array if necessary.
     * @see lv_array_shrink
     */
    Array& shrink() noexcept { lv_array_shrink(&s_); return *this; }
    /**
     * Return how many elements are stored in the array.
     * @return the number of elements stored in the array
     * @see lv_array_size
     */
    uint32_t size() const noexcept { return lv_array_size(&s_); }
};

} // namespace lv
