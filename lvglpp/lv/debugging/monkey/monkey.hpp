#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/indev/indev.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_MONKEY != 0
class Monkey {
protected:
    lv_monkey_t* p_ = nullptr;

public:
    constexpr Monkey() noexcept = default;  /**< the "no object" handle */
    constexpr explicit Monkey(lv_monkey_t* p) noexcept : p_(p) {}

    constexpr lv_monkey_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(Monkey a, Monkey b) noexcept { return a.p_ == b.p_; }

    /**
     * Create monkey for test
     * @param config  pointer to 'lv_monkey_config_t' variable
     * @return pointer to the created monkey
     * @see lv_monkey_create
     */
    static Monkey create(MonkeyConfig& config) noexcept { return Monkey(lv_monkey_create(config.raw())); }
    /**
     * Delete monkey
     * @see lv_monkey_delete
     */
    void delete_() const noexcept { lv_monkey_delete(p_); }
    /**
     * Get whether monkey is enabled
     * @return return true if monkey enabled
     * @see lv_monkey_get_enable
     */
    bool get_enable() const noexcept { return lv_monkey_get_enable(p_); }
    /**
     * Get monkey input device
     * @return pointer to the input device
     * @see lv_monkey_get_indev
     */
    Indev get_indev() const noexcept { return Indev(lv_monkey_get_indev(p_)); }
    /**
     * Get the user_data field of the monkey
     * @return the pointer to the user_data of the monkey
     * @see lv_monkey_get_user_data
     */
    void* get_user_data() const noexcept { return lv_monkey_get_user_data(p_); }
    /**
     * Enable monkey
     * @param en  set to true to enable
     * @see lv_monkey_set_enable
     */
    void set_enable(bool en) const noexcept { lv_monkey_set_enable(p_, en); }
    /**
     * Set the user_data field of the monkey
     * @param user_data  pointer to the new user_data.
     * @see lv_monkey_set_user_data
     */
    void set_user_data(void* user_data) const noexcept { lv_monkey_set_user_data(p_, user_data); }
};
static_assert(sizeof(Monkey) == sizeof(lv_monkey_t*));
static_assert(__is_trivially_copyable(Monkey));
#endif // LV_USE_MONKEY != 0

} // namespace lv
