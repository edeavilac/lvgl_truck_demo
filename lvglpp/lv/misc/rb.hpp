#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

class Rb {
protected:
    lv_rb_t* p_ = nullptr;

public:
    constexpr Rb() noexcept = default;  /**< the "no object" handle */
    constexpr explicit Rb(lv_rb_t* p) noexcept : p_(p) {}

    constexpr lv_rb_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(Rb a, Rb b) noexcept { return a.p_ == b.p_; }

    /** @see lv_rb_destroy */
    void destroy() const noexcept { lv_rb_destroy(p_); }
    /** @see lv_rb_drop */
    bool drop(const void* key) const noexcept { return lv_rb_drop(p_, key); }
    /** @see lv_rb_drop_node */
    bool drop_node(lv_rb_node_t* node) const noexcept { return lv_rb_drop_node(p_, node); }
    /** @see lv_rb_find */
    lv_rb_node_t* find(const void* key) const noexcept { return lv_rb_find(p_, key); }
    /** @see lv_rb_init */
    bool init(lv_rb_compare_t compare, size_t node_size) const noexcept { return lv_rb_init(p_, compare, node_size); }
    /** @see lv_rb_insert */
    lv_rb_node_t* insert(void* key) const noexcept { return lv_rb_insert(p_, key); }
    /** @see lv_rb_maximum */
    lv_rb_node_t* maximum() const noexcept { return lv_rb_maximum(p_); }
    /** @see lv_rb_minimum */
    lv_rb_node_t* minimum() const noexcept { return lv_rb_minimum(p_); }
    /** @see lv_rb_remove */
    void* remove(const void* key) const noexcept { return lv_rb_remove(p_, key); }
    /** @see lv_rb_remove_node */
    void* remove_node(lv_rb_node_t* node) const noexcept { return lv_rb_remove_node(p_, node); }
};
static_assert(sizeof(Rb) == sizeof(lv_rb_t*));
static_assert(__is_trivially_copyable(Rb));

/** @see lv_rb_minimum_from */
inline lv_rb_node_t* rb_minimum_from(lv_rb_node_t* node) noexcept { return lv_rb_minimum_from(node); }

/** @see lv_rb_maximum_from */
inline lv_rb_node_t* rb_maximum_from(lv_rb_node_t* node) noexcept { return lv_rb_maximum_from(node); }

} // namespace lv
