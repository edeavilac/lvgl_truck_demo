#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/indev/indev.hpp"
#include "lv/misc/event.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

template <>
struct EventData<events::tag::Input> : EventData<events::tag::Any> {
    using EventData<events::tag::Any>::EventData;
    Indev indev() const noexcept { return Indev(lv_event_get_indev(this->raw())); }
};

template <>
struct EventData<events::tag::DrawPhase> : EventData<events::tag::Draw> {
    using EventData<events::tag::Draw>::EventData;
    lv_layer_t* layer() const noexcept { return lv_event_get_layer(this->raw()); }
};

template <>
struct EventData<events::tag::ScrollBegin> : EventData<events::tag::Scrolling> {
    using EventData<events::tag::Scrolling>::EventData;
    lv_anim_t* scroll_anim() const noexcept { return lv_event_get_scroll_anim(this->raw()); }
};

template <>
struct EventData<events::tag::Key> : EventData<events::tag::Input> {
    using EventData<events::tag::Input>::EventData;
    uint32_t key() const noexcept { return lv_event_get_key(this->raw()); }
};

template <>
struct EventData<events::tag::DrawTaskAdded> : EventData<events::tag::Draw> {
    using EventData<events::tag::Draw>::EventData;
    DrawTask draw_task() const noexcept { return DrawTask(lv_event_get_draw_task(this->raw())); }
};

template <>
struct EventData<events::tag::CoverCheck> : EventData<events::tag::Draw> {
    using EventData<events::tag::Draw>::EventData;
    const lv_area_t* cover_area() const noexcept { return lv_event_get_cover_area(this->raw()); }
};

template <>
struct EventData<events::tag::RefrExtDrawSize> : EventData<events::tag::Draw> {
    using EventData<events::tag::Draw>::EventData;
    void set_ext_draw_size(int32_t size) const noexcept { lv_event_set_ext_draw_size(this->raw(), size); }
};

template <>
struct EventData<events::tag::SizeChanged> : EventData<events::tag::Other> {
    using EventData<events::tag::Other>::EventData;
    const lv_area_t* old_size() const noexcept { return lv_event_get_old_size(this->raw()); }
};

template <>
struct EventData<events::tag::GetSelfSize> : EventData<events::tag::Other> {
    using EventData<events::tag::Other>::EventData;
    lv_point_t* self_size_info() const noexcept { return lv_event_get_self_size_info(this->raw()); }
};

template <>
struct EventData<events::tag::HitTest> : EventData<events::tag::Any> {
    using EventData<events::tag::Any>::EventData;
    lv_hit_test_info_t* hit_test_info() const noexcept { return lv_event_get_hit_test_info(this->raw()); }
};

template <>
struct EventData<events::tag::Rotary> : EventData<events::tag::Any> {
    using EventData<events::tag::Any>::EventData;
    int32_t rotary_diff() const noexcept { return lv_event_get_rotary_diff(this->raw()); }
};

template <>
struct EventData<events::tag::StateChanged> : EventData<events::tag::Special> {
    using EventData<events::tag::Special>::EventData;
    State prev_state() const noexcept { return static_cast<State>(lv_event_get_prev_state(this->raw())); }
};

} // namespace lv
