#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/misc/anim.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

class AnimTimeline {
protected:
    lv_anim_timeline_t* p_ = nullptr;

public:
    constexpr AnimTimeline() noexcept = default;  /**< the "no object" handle */
    constexpr explicit AnimTimeline(lv_anim_timeline_t* p) noexcept : p_(p) {}

    constexpr lv_anim_timeline_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(AnimTimeline a, AnimTimeline b) noexcept { return a.p_ == b.p_; }

    /**
     * Add animation to the animation timeline.
     * @param start_time  the time the animation started on the timeline, note that start_time will override the value of delay.
     * @param a  pointer to an animation.
     * @see lv_anim_timeline_add
     */
    void add(uint32_t start_time, Anim& a) const noexcept { lv_anim_timeline_add(p_, start_time, a.raw()); }
    /**
     * Create an animation timeline.
     * @return pointer to the animation timeline.
     * @see lv_anim_timeline_create
     */
    static AnimTimeline create() noexcept { return AnimTimeline(lv_anim_timeline_create()); }
    /**
     * Delete animation timeline.
     * @see lv_anim_timeline_delete
     */
    void delete_() const noexcept { lv_anim_timeline_delete(p_); }
    /**
     * Get the wait time when  playing from the very start, or reverse from the very end.
     * @return the remaining time in milliseconds
     * @see lv_anim_timeline_get_delay
     */
    uint32_t get_delay() const noexcept { return lv_anim_timeline_get_delay(p_); }
    /**
     * Get the time used to play the animation timeline.
     * @return total time spent in animation timeline.
     * @see lv_anim_timeline_get_playtime
     */
    uint32_t get_playtime() const noexcept { return lv_anim_timeline_get_playtime(p_); }
    /**
     * Get the progress of the animation timeline.
     * @return return value 0~65535 to map 0~100% animation progress.
     * @see lv_anim_timeline_get_progress
     */
    uint16_t get_progress() const noexcept { return lv_anim_timeline_get_progress(p_); }
    /**
     * Get repeat count of the animation timeline.
     * @see lv_anim_timeline_get_repeat_count
     */
    uint32_t get_repeat_count() const noexcept { return lv_anim_timeline_get_repeat_count(p_); }
    /**
     * Get repeat delay of the animation timeline.
     * @see lv_anim_timeline_get_repeat_delay
     */
    uint32_t get_repeat_delay() const noexcept { return lv_anim_timeline_get_repeat_delay(p_); }
    /**
     * Get whether the animation timeline is played in reverse.
     * @return return true if it is reverse playback.
     * @see lv_anim_timeline_get_reverse
     */
    bool get_reverse() const noexcept { return lv_anim_timeline_get_reverse(p_); }
    /**
     * Get the user_data of a an animation timeline
     * @see lv_anim_timeline_get_user_data
     */
    void* get_user_data() const noexcept { return lv_anim_timeline_get_user_data(p_); }
    /**
     * Merge (add) all animations of a timeline to another
     * @param src  merge the animations of this timeline
     * @param delay  add the animations with this extra delay
     * @see lv_anim_timeline_merge
     */
    void merge(AnimTimeline src, int32_t delay) const noexcept { lv_anim_timeline_merge(p_, src.raw(), delay); }
    /**
     * Pause the animation timeline.
     * @see lv_anim_timeline_pause
     */
    void pause() const noexcept { lv_anim_timeline_pause(p_); }
    /**
     * Set the time to wait before starting the animation.
     * Applies only when playing from the very start, or reverse from the very end.
     * @param delay  the delay time in milliseconds
     * @see lv_anim_timeline_set_delay
     */
    void set_delay(uint32_t delay) const noexcept { lv_anim_timeline_set_delay(p_, delay); }
    /**
     * Set the progress of the animation timeline.
     * @param progress  set value 0~65535 to map 0~100% animation progress.
     * @see lv_anim_timeline_set_progress
     */
    void set_progress(uint16_t progress) const noexcept { lv_anim_timeline_set_progress(p_, progress); }
    /**
     * Make the animation timeline repeat itself.
     * @param cnt  repeat count or `LV_ANIM_REPEAT_INFINITE` for infinite repetition. 0: to disable repetition.
     * @see lv_anim_timeline_set_repeat_count
     */
    void set_repeat_count(uint32_t cnt) const noexcept { lv_anim_timeline_set_repeat_count(p_, cnt); }
    /**
     * Set a delay before repeating the animation timeline.
     * @param delay  delay in milliseconds before repeating the animation timeline.
     * @see lv_anim_timeline_set_repeat_delay
     */
    void set_repeat_delay(uint32_t delay) const noexcept { lv_anim_timeline_set_repeat_delay(p_, delay); }
    /**
     * Set the playback direction of the animation timeline.
     * @param reverse  whether to play in reverse.
     * @see lv_anim_timeline_set_reverse
     */
    void set_reverse(bool reverse) const noexcept { lv_anim_timeline_set_reverse(p_, reverse); }
    /**
     * Set the user_data of a an animation timeline
     * @param user_data  pointer to any data. Only the pointer will be saved.
     * @see lv_anim_timeline_set_user_data
     */
    void set_user_data(void* user_data) const noexcept { lv_anim_timeline_set_user_data(p_, user_data); }
    /**
     * Start the animation timeline.
     * @return total time spent in animation timeline.
     * @see lv_anim_timeline_start
     */
    uint32_t start() const noexcept { return lv_anim_timeline_start(p_); }
};
static_assert(sizeof(AnimTimeline) == sizeof(lv_anim_timeline_t*));
static_assert(__is_trivially_copyable(AnimTimeline));

} // namespace lv
