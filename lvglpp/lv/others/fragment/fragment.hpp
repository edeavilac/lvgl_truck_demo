#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_FRAGMENT
class Fragment {
protected:
    lv_fragment_t* p_ = nullptr;

public:
    constexpr Fragment() noexcept = default;  /**< the "no object" handle */
    constexpr explicit Fragment(lv_fragment_t* p) noexcept : p_(p) {}

    constexpr lv_fragment_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(Fragment a, Fragment b) noexcept { return a.p_ == b.p_; }

    /**
     * Create a fragment instance.
     * @param cls  Fragment class. This fragment must return non null object.
     * @param args  Arguments assigned by fragment manager
     * @return Fragment instance
     * @see lv_fragment_create
     */
    static Fragment create(const lv_fragment_class_t* cls, void* args) noexcept;
    /**
     * Create object by fragment.
     * @param container  Container of the objects should be created upon.
     * @return Created object
     * @see lv_fragment_create_obj
     */
    Obj create_obj(Obj container) const noexcept;
    /**
     * Destroy a fragment.
     * @see lv_fragment_delete
     */
    void delete_() const noexcept;
    /**
     * Delete created object of a fragment
     * @see lv_fragment_delete_obj
     */
    void delete_obj() const noexcept;
    /**
     * Get container object of this fragment
     * @return Reference to container object
     * @see lv_fragment_get_container
     */
    lv_obj_t* const* get_container() const noexcept;
    /**
     * Get associated manager of this fragment
     * @return Fragment manager instance
     * @see lv_fragment_get_manager
     */
    FragmentManager get_manager() const noexcept;
    /**
     * Get parent fragment of this fragment
     * @return Parent fragment
     * @see lv_fragment_get_parent
     */
    Fragment get_parent() const noexcept;
    /**
     * Destroy obj in fragment, and recreate them.
     * @see lv_fragment_recreate_obj
     */
    void recreate_obj() const noexcept;
};
static_assert(sizeof(Fragment) == sizeof(lv_fragment_t*));
static_assert(__is_trivially_copyable(Fragment));
#endif // LV_USE_FRAGMENT

} // namespace lv
