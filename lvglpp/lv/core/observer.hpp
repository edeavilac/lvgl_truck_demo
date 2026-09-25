#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_OBSERVER
class Observer {
protected:
    lv_observer_t* p_ = nullptr;

public:
    constexpr Observer() noexcept = default;  /**< the "no object" handle */
    constexpr explicit Observer(lv_observer_t* p) noexcept : p_(p) {}

    constexpr lv_observer_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(Observer a, Observer b) noexcept { return a.p_ == b.p_; }

    /**
     * Get target of an Observer.
     * @return pointer to saved target
     * @see lv_observer_get_target
     */
    void* get_target() const noexcept;
    /**
     * Get target Widget of Observer.
     * This is the same as `lv_observer_get_target()`, except it returns `target`
     * as an `lv_obj_t *`.
     * @return pointer to saved Widget target
     * @see lv_observer_get_target_obj
     */
    Obj get_target_obj() const noexcept;
    /**
     * Get Observer's user data.
     * @return void pointer to saved user data
     * @see lv_observer_get_user_data
     */
    void* get_user_data() const noexcept;
    /**
     * Remove Observer from its Subject.
     * @see lv_observer_remove
     */
    void remove() const noexcept;
};
static_assert(sizeof(Observer) == sizeof(lv_observer_t*));
static_assert(__is_trivially_copyable(Observer));
#endif // LV_USE_OBSERVER

class SubjectIncrementDsc {
protected:
    lv_obj_t* owner_ = nullptr;
    lv_subject_increment_dsc_t* p_ = nullptr;

public:
    constexpr SubjectIncrementDsc() noexcept = default;
    constexpr SubjectIncrementDsc(lv_obj_t* owner, lv_subject_increment_dsc_t* p) noexcept : owner_(owner), p_(p) {}

    constexpr lv_subject_increment_dsc_t* raw() const noexcept { return p_; }
    constexpr lv_obj_t* owner() const noexcept { return owner_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(SubjectIncrementDsc a, SubjectIncrementDsc b) noexcept { return a.p_ == b.p_ && a.owner_ == b.owner_; }

    #if LV_USE_OBSERVER
    /**
     * Set the maximum subject value to set by the event
     * @param obj  pointer to the Widget to which the event is attached
     * @param max_value  the maximum value to set
     * @see lv_obj_set_subject_increment_event_max_value
     */
    void set_subject_increment_event_max_value(int32_t max_value) const noexcept;
    /**
     * Set the minimum subject value to set by the event
     * @param obj  pointer to the Widget to which the event is attached
     * @param min_value  the minimum value to set
     * @see lv_obj_set_subject_increment_event_min_value
     */
    void set_subject_increment_event_min_value(int32_t min_value) const noexcept;
    /**
     * Set what to do when the min/max value is crossed.
     * @param obj  pointer to the Widget to which the event is attached
     * @param rollover  false: stop at the min/max value; true: jump to the other end
     * @see lv_obj_set_subject_increment_event_rollover
     */
    void set_subject_increment_event_rollover(bool rollover) const noexcept;
    #endif // LV_USE_OBSERVER

};
static_assert(sizeof(SubjectIncrementDsc) == 2 * sizeof(void*));
static_assert(__is_trivially_copyable(SubjectIncrementDsc));

} // namespace lv
