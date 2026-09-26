#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

class Ll {
protected:
    lv_ll_t s_;

public:
    explicit Ll(uint32_t node_size) noexcept { lv_ll_init(&s_, node_size); }
protected:
    Ll() noexcept = default;
public:


    Ll(const Ll&) = delete;
    Ll& operator=(const Ll&) = delete;
    Ll(Ll&&) = delete;
    Ll& operator=(Ll&&) = delete;

    lv_ll_t* raw() noexcept { return &s_; }

    /**
     * Move a node to a new linked list
     * @param ll_new_p  pointer to the new linked list
     * @param node  pointer to a node
     * @param head  true: be the head in the new list false be the tail in the new list
     * @see lv_ll_chg_list
     */
    Ll& chg_list(Ll& ll_new_p, void* node, bool head) noexcept { lv_ll_chg_list(&s_, ll_new_p.raw(), node, head); return *this; }
    /**
     * Remove and free all elements from a linked list. The list remain valid but become empty.
     * @see lv_ll_clear
     */
    Ll& clear() noexcept { lv_ll_clear(&s_); return *this; }
    /** @see lv_ll_clear_custom */
    Ll& clear_custom(void (*arg)(void*)) noexcept { lv_ll_clear_custom(&s_, arg); return *this; }
    /**
     * Takes the function itself as a template argument, so its real parameter types survive: the C idiom CASTS the pointer, which is undefined whenever they differ, and between the versions they do.
     * @see lv_ll_clear_custom
     */
    template <auto Fn>
    Ll& clear_custom() noexcept { lv_ll_clear_custom(&s_, &detail::LlClearCustomThunk<Fn>::call); return *this; }
    /**
     * Return with head node of the linked list
     * @return pointer to the head of 'll_p'
     * @see lv_ll_get_head
     */
    void* get_head() const noexcept { return lv_ll_get_head(&s_); }
    /**
     * Return the length of the linked list.
     * @return length of the linked list
     * @see lv_ll_get_len
     */
    uint32_t get_len() const noexcept { return lv_ll_get_len(&s_); }
    /**
     * Return with the pointer of the next node after 'n_act'
     * @param n_act  pointer a node
     * @return pointer to the next node
     * @see lv_ll_get_next
     */
    void* get_next(const void* n_act) const noexcept { return lv_ll_get_next(&s_, n_act); }
    /**
     * Return with the pointer of the previous node after 'n_act'
     * @param n_act  pointer a node
     * @return pointer to the previous node
     * @see lv_ll_get_prev
     */
    void* get_prev(const void* n_act) const noexcept { return lv_ll_get_prev(&s_, n_act); }
    /**
     * Return with tail node of the linked list
     * @return pointer to the tail of 'll_p'
     * @see lv_ll_get_tail
     */
    void* get_tail() const noexcept { return lv_ll_get_tail(&s_); }
    /**
     * Add a new head to a linked list
     * @return pointer to the new head
     * @see lv_ll_ins_head
     */
    void* ins_head() noexcept { return lv_ll_ins_head(&s_); }
    /**
     * Insert a new node in front of the n_act node
     * @param n_act  pointer a node
     * @return pointer to the new node
     * @see lv_ll_ins_prev
     */
    void* ins_prev(void* n_act) noexcept { return lv_ll_ins_prev(&s_, n_act); }
    /**
     * Add a new tail to a linked list
     * @return pointer to the new tail
     * @see lv_ll_ins_tail
     */
    void* ins_tail() noexcept { return lv_ll_ins_tail(&s_); }
    /**
     * Check if a linked list is empty
     * @return true: the linked list is empty; false: not empty
     * @see lv_ll_is_empty
     */
    bool is_empty() noexcept { return lv_ll_is_empty(&s_); }
    /**
     * Move a node before another node in the same linked list
     * @param n_act  pointer to node to move
     * @param n_after  pointer to a node which should be after `n_act`
     * @see lv_ll_move_before
     */
    Ll& move_before(void* n_act, void* n_after) noexcept { lv_ll_move_before(&s_, n_act, n_after); return *this; }
    /**
     * Remove the node 'node_p' from 'll_p' linked list.
     * It does not free the memory of node.
     * @param node_p  pointer to node in 'll_p' linked list
     * @see lv_ll_remove
     */
    Ll& remove(void* node_p) noexcept { lv_ll_remove(&s_, node_p); return *this; }
};

} // namespace lv
