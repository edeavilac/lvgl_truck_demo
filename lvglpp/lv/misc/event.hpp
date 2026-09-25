#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>
#include <new>

namespace lv {

class Event {
protected:
    lv_event_t* p_ = nullptr;

public:
    constexpr Event() noexcept = default;  /**< the "no object" handle */
    constexpr explicit Event(lv_event_t* p) noexcept : p_(p) {}

    constexpr lv_event_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(Event a, Event b) noexcept { return a.p_ == b.p_; }

    /**
     * Helper function typically used in LV_EVENT_DELETE
     * to free the event's user_data
     * @see lv_event_free_user_data_cb
     */
    void free_user_data_cb() const noexcept;
    /**
     * Get event code of an event.
     * @return the event code. (E.g. `LV_EVENT_CLICKED`, `LV_EVENT_FOCUSED`, etc)
     * @see lv_event_get_code
     */
    EventCode get_code() const noexcept;
    /**
     * Get a pointer to an area which should be examined whether the object fully covers it or not.
     * Can be used in `LV_EVENT_HIT_TEST`
     * @return an area with absolute coordinates to check
     * @see lv_event_get_cover_area
     */
    const lv_area_t* get_cover_area() const noexcept;
    /**
     * Get current target of the event. It's the Widget for which the event handler being called.
     * If the event is not bubbled it's the same as "normal" target.
     * @return pointer to the current target of the event_code
     * @see lv_event_get_current_target
     */
    void* get_current_target() const noexcept;
    /**
     * Get the current target of the event. It's the object which event handler being called.
     * If the event is not bubbled it's the same as "original" target.
     * @return the target of the event_code
     * @see lv_event_get_current_target_obj
     */
    Obj get_current_target_obj() const noexcept;
    /**
     * Get the draw task which was just added.
     * Can be used in `LV_EVENT_DRAW_TASK_ADDED event`
     * @return the added draw task
     * @see lv_event_get_draw_task
     */
    DrawTask get_draw_task() const noexcept;
    #if LV_USE_GESTURE_RECOGNITION
    /**
     * Obtains the current state of the gesture recognizer attached to an event
     * @return current state of the gesture recognizer
     * @see lv_event_get_gesture_state
     */
    IndevGestureState get_gesture_state(IndevGestureType type) const noexcept;
    /**
     * Obtains the current event type of the gesture recognizer attached to an event
     * @return current event type of the gesture recognizer
     * @see lv_event_get_gesture_type
     */
    IndevGestureType get_gesture_type() const noexcept;
    #endif // LV_USE_GESTURE_RECOGNITION

    /**
     * Get a pointer to an `lv_hit_test_info_t` variable in which the hit test result should be saved. Can be used in `LV_EVENT_HIT_TEST`
     * @return pointer to `lv_hit_test_info_t` or NULL if called on an unrelated event
     * @see lv_event_get_hit_test_info
     */
    lv_hit_test_info_t* get_hit_test_info() const noexcept;
    /**
     * Get the input device passed as parameter to indev related events.
     * @return the indev that triggered the event or NULL if called on a not indev related event
     * @see lv_event_get_indev
     */
    Indev get_indev() const noexcept;
    /**
     * Get the area to be invalidated. Can be used in `LV_EVENT_INVALIDATE_AREA`
     * @return the area to invalidated (can be modified as required)
     * @see lv_event_get_invalidated_area
     */
    lv_area_t* get_invalidated_area() const noexcept;
    /**
     * Get the key passed as parameter to an event. Can be used in `LV_EVENT_KEY`
     * @return the triggering key or NULL if called on an unrelated event
     * @see lv_event_get_key
     */
    uint32_t get_key() const noexcept;
    /**
     * Get the draw context which should be the first parameter of the draw functions.
     * Namely: `LV_EVENT_DRAW_MAIN/POST`, `LV_EVENT_DRAW_MAIN/POST_BEGIN`, `LV_EVENT_DRAW_MAIN/POST_END`
     * @return pointer to a draw context or NULL if called on an unrelated event
     * @see lv_event_get_layer
     */
    lv_layer_t* get_layer() const noexcept;
    /**
     * Get the old area of the object before its size was changed. Can be used in `LV_EVENT_SIZE_CHANGED`
     * @return the old absolute area of the object or NULL if called on an unrelated event
     * @see lv_event_get_old_size
     */
    const lv_area_t* get_old_size() const noexcept;
    /**
     * Get parameter passed when event was sent.
     * @return pointer to the parameter
     * @see lv_event_get_param
     */
    void* get_param() const noexcept;
    #if LV_USE_GESTURE_RECOGNITION
    /**
     * Obtains the current scale of a pinch gesture
     * @return the scale of the current gesture
     * @see lv_event_get_pinch_scale
     */
    float get_pinch_scale() const noexcept;
    #endif // LV_USE_GESTURE_RECOGNITION

    /**
     * Get the previous state before the state change.
     * Can be used in `LV_EVENT_STATE_CHANGED` event
     * @return the previous state
     * @see lv_event_get_prev_state
     */
    State get_prev_state() const noexcept;
    /**
     * Get the signed rotary encoder diff. passed as parameter to an event. Can be used in `LV_EVENT_ROTARY`
     * @return the triggering key or NULL if called on an unrelated event
     * @see lv_event_get_rotary_diff
     */
    int32_t get_rotary_diff() const noexcept;
    #if LV_USE_GESTURE_RECOGNITION
    /**
     * Obtains the current angle in radian of a rotation gesture
     * @return the rotation angle in radian of the current gesture
     * @see lv_event_get_rotation
     */
    float get_rotation() const noexcept;
    #endif // LV_USE_GESTURE_RECOGNITION

    /**
     * Get the animation descriptor of a scrolling. Can be used in `LV_EVENT_SCROLL_BEGIN`
     * @return the animation that will scroll the object. (can be modified as required)
     * @see lv_event_get_scroll_anim
     */
    lv_anim_t* get_scroll_anim() const noexcept;
    /**
     * Get a pointer to an `lv_point_t` variable in which the self size should be saved (width in `point->x` and height `point->y`).
     * Can be used in `LV_EVENT_GET_SELF_SIZE`
     * @return pointer to `lv_point_t` or NULL if called on an unrelated event
     * @see lv_event_get_self_size_info
     */
    lv_point_t* get_self_size_info() const noexcept;
    /**
     * Get Widget originally targeted by the event. It's the same even if event was bubbled.
     * @return the target of the event_code
     * @see lv_event_get_target
     */
    void* get_target() const noexcept;
    /**
     * Get the object originally targeted by the event. It's the same even if the event is bubbled.
     * @return pointer to the original target of the event_code
     * @see lv_event_get_target_obj
     */
    Obj get_target_obj() const noexcept;
    #if LV_USE_GESTURE_RECOGNITION
    /**
     * Obtains the current direction from the center of a two finger swipe
     * @return the rotation angle in radian of the current gesture
     * @see lv_event_get_two_fingers_swipe_dir
     */
    Dir get_two_fingers_swipe_dir() const noexcept;
    /**
     * Obtains the current distance in pixels of a two fingers swipe gesture, from the starting center
     * @return the distance from the center, in pixels, of the current gesture
     * @see lv_event_get_two_fingers_swipe_distance
     */
    float get_two_fingers_swipe_distance() const noexcept;
    #endif // LV_USE_GESTURE_RECOGNITION

    /**
     * Get user_data passed when event was registered on Widget.
     * @return pointer to the user_data
     * @see lv_event_get_user_data
     */
    void* get_user_data() const noexcept;
    /**
     * Set the result of cover checking. Can be used in `LV_EVENT_COVER_CHECK`
     * @param res  an element of ::lv_cover_check_info_t
     * @see lv_event_set_cover_res
     */
    void set_cover_res(CoverRes res) const noexcept;
    /**
     * Set the new extra draw size. Can be used in `LV_EVENT_REFR_EXT_DRAW_SIZE`
     * @param size  The new extra draw size
     * @see lv_event_set_ext_draw_size
     */
    void set_ext_draw_size(int32_t size) const noexcept;
    /**
     * Stop event from bubbling.
     * This is only valid when called in the middle of an event processing chain.
     * @see lv_event_stop_bubbling
     */
    void stop_bubbling() const noexcept;
    /**
     * Stop processing this event.
     * This is only valid when called in the middle of an event processing chain.
     * @see lv_event_stop_processing
     */
    void stop_processing() const noexcept;
    /**
     * Stop event from trickling down to children.
     * This is only valid when called in the middle of an event processing chain.
     * @see lv_event_stop_trickling
     */
    void stop_trickling() const noexcept;
};
static_assert(sizeof(Event) == sizeof(lv_event_t*));
static_assert(__is_trivially_copyable(Event));

namespace events {
namespace tag {

struct Any {
    using Super = void;
    using Param = void;
    static constexpr bool is_category = true;
    static constexpr bool is_root = true;
    static constexpr EventCode code = EventCode::All;
};

struct Input {
    using Super = tag::Any;
    using Param = void;
    static constexpr bool is_category = true;
    static constexpr bool is_root = false;
};

struct Press {
    using Super = tag::Input;
    using Param = void;
    static constexpr bool is_category = true;
    static constexpr bool is_root = false;
};

struct Scrolling {
    using Super = tag::Input;
    using Param = void;
    static constexpr bool is_category = true;
    static constexpr bool is_root = false;
};

struct Focus {
    using Super = tag::Input;
    using Param = void;
    static constexpr bool is_category = true;
    static constexpr bool is_root = false;
};

struct Draw {
    using Super = tag::Any;
    using Param = void;
    static constexpr bool is_category = true;
    static constexpr bool is_root = false;
};

struct DrawPhase {
    using Super = tag::Draw;
    using Param = void;
    static constexpr bool is_category = true;
    static constexpr bool is_root = false;
};

struct Special {
    using Super = tag::Any;
    using Param = void;
    static constexpr bool is_category = true;
    static constexpr bool is_root = false;
};

struct Other {
    using Super = tag::Any;
    using Param = void;
    static constexpr bool is_category = true;
    static constexpr bool is_root = false;
};

struct DisplayEvent {
    using Super = tag::Any;
    using Param = void;
    static constexpr bool is_category = true;
    static constexpr bool is_root = false;
};

struct Pressed {
    using Super = tag::Press;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::Pressed;
};

struct Pressing {
    using Super = tag::Press;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::Pressing;
};

struct PressLost {
    using Super = tag::Press;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::PressLost;
};

struct ShortClicked {
    using Super = tag::Press;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::ShortClicked;
};

struct LongPressed {
    using Super = tag::Press;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::LongPressed;
};

struct LongPressedRepeat {
    using Super = tag::Press;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::LongPressedRepeat;
};

struct Clicked {
    using Super = tag::Press;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::Clicked;
};

struct Released {
    using Super = tag::Press;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::Released;
};

struct ScrollBegin {
    using Super = tag::Scrolling;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::ScrollBegin;
};

struct ScrollEnd {
    using Super = tag::Scrolling;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::ScrollEnd;
};

struct Scroll {
    using Super = tag::Scrolling;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::Scroll;
};

struct Focused {
    using Super = tag::Focus;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::Focused;
};

struct Defocused {
    using Super = tag::Focus;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::Defocused;
};

struct Leave {
    using Super = tag::Focus;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::Leave;
};

struct Gesture {
    using Super = tag::Input;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::Gesture;
};

struct Key {
    using Super = tag::Input;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::Key;
};

struct DrawMainBegin {
    using Super = tag::DrawPhase;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::DrawMainBegin;
};

struct DrawMain {
    using Super = tag::DrawPhase;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::DrawMain;
};

struct DrawMainEnd {
    using Super = tag::DrawPhase;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::DrawMainEnd;
};

struct DrawPostBegin {
    using Super = tag::DrawPhase;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::DrawPostBegin;
};

struct DrawPost {
    using Super = tag::DrawPhase;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::DrawPost;
};

struct DrawPostEnd {
    using Super = tag::DrawPhase;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::DrawPostEnd;
};

struct DrawTaskAdded {
    using Super = tag::Draw;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::DrawTaskAdded;
};

struct CoverCheck {
    using Super = tag::Draw;
    using Param = lv_cover_check_info_t;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::CoverCheck;
};

struct RefrExtDrawSize {
    using Super = tag::Draw;
    using Param = int32_t;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::RefrExtDrawSize;
};

struct ValueChanged {
    using Super = tag::Special;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::ValueChanged;
};

struct Insert {
    using Super = tag::Special;
    using Param = char;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::Insert;
};

struct Refresh {
    using Super = tag::Special;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::Refresh;
};

struct Ready {
    using Super = tag::Special;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::Ready;
};

struct Cancel {
    using Super = tag::Special;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::Cancel;
};

struct Create {
    using Super = tag::Other;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::Create;
};

struct Delete {
    using Super = tag::Other;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::Delete;
};

struct ChildChanged {
    using Super = tag::Other;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::ChildChanged;
};

struct ChildCreated {
    using Super = tag::Other;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::ChildCreated;
};

struct ChildDeleted {
    using Super = tag::Other;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::ChildDeleted;
};

struct ScreenUnloadStart {
    using Super = tag::Other;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::ScreenUnloadStart;
};

struct ScreenLoadStart {
    using Super = tag::Other;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::ScreenLoadStart;
};

struct ScreenLoaded {
    using Super = tag::Other;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::ScreenLoaded;
};

struct ScreenUnloaded {
    using Super = tag::Other;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::ScreenUnloaded;
};

struct SizeChanged {
    using Super = tag::Other;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::SizeChanged;
};

struct StyleChanged {
    using Super = tag::Other;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::StyleChanged;
};

struct LayoutChanged {
    using Super = tag::Other;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::LayoutChanged;
};

struct GetSelfSize {
    using Super = tag::Other;
    using Param = lv_point_t;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::GetSelfSize;
};

struct HitTest {
    using Super = tag::Any;
    using Param = lv_hit_test_info_t;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::HitTest;
};

struct Rotary {
    using Super = tag::Any;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::Rotary;
};

struct ScrollThrowBegin {
    using Super = tag::Any;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::ScrollThrowBegin;
};

struct IndevReset {
    using Super = tag::Any;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::IndevReset;
};

struct InvalidateArea {
    using Super = tag::DisplayEvent;
    using Param = lv_area_t;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::InvalidateArea;
};

struct ResolutionChanged {
    using Super = tag::DisplayEvent;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::ResolutionChanged;
};

struct ColorFormatChanged {
    using Super = tag::DisplayEvent;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::ColorFormatChanged;
};

struct RefrRequest {
    using Super = tag::DisplayEvent;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::RefrRequest;
};

struct RefrStart {
    using Super = tag::DisplayEvent;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::RefrStart;
};

struct RefrReady {
    using Super = tag::DisplayEvent;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::RefrReady;
};

struct RenderStart {
    using Super = tag::DisplayEvent;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::RenderStart;
};

struct RenderReady {
    using Super = tag::DisplayEvent;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::RenderReady;
};

struct FlushStart {
    using Super = tag::DisplayEvent;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::FlushStart;
};

struct FlushFinish {
    using Super = tag::DisplayEvent;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::FlushFinish;
};

struct FlushWaitStart {
    using Super = tag::DisplayEvent;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::FlushWaitStart;
};

struct FlushWaitFinish {
    using Super = tag::DisplayEvent;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::FlushWaitFinish;
};

struct Vsync {
    using Super = tag::DisplayEvent;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::Vsync;
};

struct SingleClicked {
    using Super = tag::Any;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::SingleClicked;
};

struct DoubleClicked {
    using Super = tag::Any;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::DoubleClicked;
};

struct TripleClicked {
    using Super = tag::Any;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::TripleClicked;
};

struct HoverOver {
    using Super = tag::Input;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::HoverOver;
};

struct HoverLeave {
    using Super = tag::Input;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::HoverLeave;
};

struct StateChanged {
    using Super = tag::Special;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::StateChanged;
};

struct SyncStart {
    using Super = tag::DisplayEvent;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::SyncStart;
};

struct SyncFinish {
    using Super = tag::DisplayEvent;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::SyncFinish;
};

struct SyncWaitStart {
    using Super = tag::DisplayEvent;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::SyncWaitStart;
};

struct SyncWaitFinish {
    using Super = tag::DisplayEvent;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::SyncWaitFinish;
};

struct UpdateLayoutCompleted {
    using Super = tag::DisplayEvent;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::UpdateLayoutCompleted;
};

struct VsyncRequest {
    using Super = tag::DisplayEvent;
    using Param = void;
    static constexpr bool is_category = false;
    static constexpr bool is_root = false;
    static constexpr EventCode code = EventCode::VsyncRequest;
};

} // namespace tag

// The value a call site writes: `btn.on(events::Clicked, f)`.
inline constexpr tag::Any Any{};
inline constexpr tag::Input Input{};
inline constexpr tag::Press Press{};
inline constexpr tag::Scrolling Scrolling{};
inline constexpr tag::Focus Focus{};
inline constexpr tag::Draw Draw{};
inline constexpr tag::DrawPhase DrawPhase{};
inline constexpr tag::Special Special{};
inline constexpr tag::Other Other{};
inline constexpr tag::DisplayEvent DisplayEvent{};
inline constexpr tag::Pressed Pressed{};
inline constexpr tag::Pressing Pressing{};
inline constexpr tag::PressLost PressLost{};
inline constexpr tag::ShortClicked ShortClicked{};
inline constexpr tag::LongPressed LongPressed{};
inline constexpr tag::LongPressedRepeat LongPressedRepeat{};
inline constexpr tag::Clicked Clicked{};
inline constexpr tag::Released Released{};
inline constexpr tag::ScrollBegin ScrollBegin{};
inline constexpr tag::ScrollEnd ScrollEnd{};
inline constexpr tag::Scroll Scroll{};
inline constexpr tag::Focused Focused{};
inline constexpr tag::Defocused Defocused{};
inline constexpr tag::Leave Leave{};
inline constexpr tag::Gesture Gesture{};
inline constexpr tag::Key Key{};
inline constexpr tag::DrawMainBegin DrawMainBegin{};
inline constexpr tag::DrawMain DrawMain{};
inline constexpr tag::DrawMainEnd DrawMainEnd{};
inline constexpr tag::DrawPostBegin DrawPostBegin{};
inline constexpr tag::DrawPost DrawPost{};
inline constexpr tag::DrawPostEnd DrawPostEnd{};
inline constexpr tag::DrawTaskAdded DrawTaskAdded{};
inline constexpr tag::CoverCheck CoverCheck{};
inline constexpr tag::RefrExtDrawSize RefrExtDrawSize{};
inline constexpr tag::ValueChanged ValueChanged{};
inline constexpr tag::Insert Insert{};
inline constexpr tag::Refresh Refresh{};
inline constexpr tag::Ready Ready{};
inline constexpr tag::Cancel Cancel{};
inline constexpr tag::Create Create{};
inline constexpr tag::Delete Delete{};
inline constexpr tag::ChildChanged ChildChanged{};
inline constexpr tag::ChildCreated ChildCreated{};
inline constexpr tag::ChildDeleted ChildDeleted{};
inline constexpr tag::ScreenUnloadStart ScreenUnloadStart{};
inline constexpr tag::ScreenLoadStart ScreenLoadStart{};
inline constexpr tag::ScreenLoaded ScreenLoaded{};
inline constexpr tag::ScreenUnloaded ScreenUnloaded{};
inline constexpr tag::SizeChanged SizeChanged{};
inline constexpr tag::StyleChanged StyleChanged{};
inline constexpr tag::LayoutChanged LayoutChanged{};
inline constexpr tag::GetSelfSize GetSelfSize{};
inline constexpr tag::HitTest HitTest{};
inline constexpr tag::Rotary Rotary{};
inline constexpr tag::ScrollThrowBegin ScrollThrowBegin{};
inline constexpr tag::IndevReset IndevReset{};
inline constexpr tag::InvalidateArea InvalidateArea{};
inline constexpr tag::ResolutionChanged ResolutionChanged{};
inline constexpr tag::ColorFormatChanged ColorFormatChanged{};
inline constexpr tag::RefrRequest RefrRequest{};
inline constexpr tag::RefrStart RefrStart{};
inline constexpr tag::RefrReady RefrReady{};
inline constexpr tag::RenderStart RenderStart{};
inline constexpr tag::RenderReady RenderReady{};
inline constexpr tag::FlushStart FlushStart{};
inline constexpr tag::FlushFinish FlushFinish{};
inline constexpr tag::FlushWaitStart FlushWaitStart{};
inline constexpr tag::FlushWaitFinish FlushWaitFinish{};
inline constexpr tag::Vsync Vsync{};
inline constexpr tag::SingleClicked SingleClicked{};
inline constexpr tag::DoubleClicked DoubleClicked{};
inline constexpr tag::TripleClicked TripleClicked{};
inline constexpr tag::HoverOver HoverOver{};
inline constexpr tag::HoverLeave HoverLeave{};
inline constexpr tag::StateChanged StateChanged{};
inline constexpr tag::SyncStart SyncStart{};
inline constexpr tag::SyncFinish SyncFinish{};
inline constexpr tag::SyncWaitStart SyncWaitStart{};
inline constexpr tag::SyncWaitFinish SyncWaitFinish{};
inline constexpr tag::UpdateLayoutCompleted UpdateLayoutCompleted{};
inline constexpr tag::VsyncRequest VsyncRequest{};

} // namespace events

// ---------------------------------------------------------------------------------------------
// PRELUDE FRAGMENT (D-C6), part 1 of 2: walking the tag tree.
//
// The tags themselves are GENERATED -- they come from the profile's taxonomy, which is the set
// LVGL enumerates in the guard of each accessor. What is here is the machinery that reads them,
// which is a fact about C++ and not about LVGL, and which is why it is copied rather than derived.
//
// Placed after the tag tree and before `AllEvents`, because `AllEvents` is a `LeafList` and the
// specialisations of `EventData` below need its primary template.
// ---------------------------------------------------------------------------------------------
namespace detail {

/** Is `T` the category `Cat`, or a descendant of it? Walks the Super chain upwards. */
template <class T, class Cat>
struct IsA : IsA<typename T::Super, Cat> {};

template <class Cat> struct IsA<Cat, Cat>  : std::true_type  {};
template <class Cat> struct IsA<void, Cat> : std::false_type {};
/** Disambiguates the two partial specialisations above when Cat itself is `void`. */
template <>          struct IsA<void, void> : std::true_type {};

/**
 * The list of every LEAF, which is the one thing the Super links cannot give: they point up, and
 * registering a category needs to look down. C++ cannot enumerate "every type with property X",
 * so the list is emitted once and filtered with IsA.
 */
template <class... Leaves>
struct LeafList {
    /**
     * Calls `fn(Leaf{})` for each leaf that belongs to `Cat`. `if constexpr` keeps `fn` from
     * being instantiated for the leaves that do not match.
     */
    template <class Cat, class Fn>
    static void for_each_in(Fn&& fn) {
        ([&] { if constexpr (IsA<Leaves, Cat>::value) fn(Leaves{}); }(), ...);
    }

    template <class Cat>
    static constexpr unsigned count_in() {
        unsigned n = 0;
        ((n += IsA<Leaves, Cat>::value ? 1u : 0u), ...);
        return n;
    }

    /** Membership, for using a LeafList as a SET rather than as the tree's leaf enumeration. */
    template <class Leaf>
    static constexpr bool contains() { return (std::is_same_v<Leaf, Leaves> || ...); }

    /**
     * "Every leaf under `Cat` is in `Set`" and "none of them is". The two questions an event
     * TARGET asks: the tree says what an event OFFERS, the target says which codes can REACH it,
     * and they are different axes -- LV_EVENT_DELETE is under `Other` and reaches all three
     * targets, while the thirteen display codes are their own category and reach only one.
     */
    template <class Cat, class Set>
    static constexpr bool all_in() {
        return ((IsA<Leaves, Cat>::value ? Set::template contains<Leaves>() : true) && ...);
    }
    template <class Cat, class Set>
    static constexpr bool none_in() {
        return ((IsA<Leaves, Cat>::value ? !Set::template contains<Leaves>() : true) && ...);
    }
};

} // namespace detail

// ---------------------------------------------------------------------------------------------
// The accessors, inherited along the tree.
//
// `EventData<Tag>` is a single-inheritance chain rooted at `Event`, following the Super links. A
// category that owns an accessor declares it once and every descendant gets it; a category that
// owns none contributes nothing and disappears. The specialisations below this are GENERATED, one
// per category that owns an accessor, and each of them mirrors a guard in LVGL's own source: the
// accessor exists in C++ exactly where the C function agrees to answer.
// ---------------------------------------------------------------------------------------------
template <class Tag>
struct EventData : EventData<typename Tag::Super> {
    using EventData<typename Tag::Super>::EventData;
};

/**
 * The root of the chain is the untyped event itself, so the handle is in scope all the way down
 * and no downcasting is needed anywhere.
 */
template <>
struct EventData<void> : Event {
    using Event::Event;
};

namespace detail {
using AllEvents = LeafList<
        events::tag::Pressed,
        events::tag::Pressing,
        events::tag::PressLost,
        events::tag::ShortClicked,
        events::tag::LongPressed,
        events::tag::LongPressedRepeat,
        events::tag::Clicked,
        events::tag::Released,
        events::tag::ScrollBegin,
        events::tag::ScrollEnd,
        events::tag::Scroll,
        events::tag::Focused,
        events::tag::Defocused,
        events::tag::Leave,
        events::tag::Gesture,
        events::tag::Key,
        events::tag::DrawMainBegin,
        events::tag::DrawMain,
        events::tag::DrawMainEnd,
        events::tag::DrawPostBegin,
        events::tag::DrawPost,
        events::tag::DrawPostEnd,
        events::tag::DrawTaskAdded,
        events::tag::CoverCheck,
        events::tag::RefrExtDrawSize,
        events::tag::ValueChanged,
        events::tag::Insert,
        events::tag::Refresh,
        events::tag::Ready,
        events::tag::Cancel,
        events::tag::Create,
        events::tag::Delete,
        events::tag::ChildChanged,
        events::tag::ChildCreated,
        events::tag::ChildDeleted,
        events::tag::ScreenUnloadStart,
        events::tag::ScreenLoadStart,
        events::tag::ScreenLoaded,
        events::tag::ScreenUnloaded,
        events::tag::SizeChanged,
        events::tag::StyleChanged,
        events::tag::LayoutChanged,
        events::tag::GetSelfSize,
        events::tag::HitTest,
        events::tag::Rotary,
        events::tag::ScrollThrowBegin,
        events::tag::IndevReset,
        events::tag::InvalidateArea,
        events::tag::ResolutionChanged,
        events::tag::ColorFormatChanged,
        events::tag::RefrRequest,
        events::tag::RefrStart,
        events::tag::RefrReady,
        events::tag::RenderStart,
        events::tag::RenderReady,
        events::tag::FlushStart,
        events::tag::FlushFinish,
        events::tag::FlushWaitStart,
        events::tag::FlushWaitFinish,
        events::tag::Vsync,
        events::tag::SingleClicked,
        events::tag::DoubleClicked,
        events::tag::TripleClicked,
        events::tag::HoverOver,
        events::tag::HoverLeave,
        events::tag::StateChanged,
        events::tag::SyncStart,
        events::tag::SyncFinish,
        events::tag::SyncWaitStart,
        events::tag::SyncWaitFinish,
        events::tag::UpdateLayoutCompleted,
        events::tag::VsyncRequest>;
} // namespace detail
using detail::AllEvents;

namespace detail {

/** The `obj` target: what an event can be raised on, and how a handler is registered. */
struct ObjTarget {
    using raw_type    = lv_obj_t*;
    using wrapper     = Obj;
    using code_type   = EventCode;
    using result_type = Result;

    static void add(raw_type t, lv_event_cb_t cb, lv_event_code_t filter,
                    void* ud) noexcept { lv_obj_add_event_cb(t, cb, filter, ud); }

    /**
     * `!= 0` on purpose, and it is what lets one spelling serve both
     * versions: one remover takes ONE registration off and returns bool,
     * the other takes them all and returns the count. The caller loops.
     */
    static bool remove(raw_type t, lv_event_cb_t cb, void* ud) noexcept {
        return lv_obj_remove_event_cb_with_user_data(t, cb, ud) != 0;
    }

    static result_type send(raw_type t, lv_event_code_t code,
                            void* param) noexcept {
        return static_cast<result_type>(lv_obj_send_event(t, code, param));
    }

    static raw_type from_event(lv_event_t* e) noexcept {
        return static_cast<raw_type>(lv_event_get_target(e));
    }
    static raw_type current_from_event(lv_event_t* e) noexcept {
        return static_cast<raw_type>(lv_event_get_current_target(e));
    }

    /**
     * Measured from the sender's call sites, not from the tag tree: the
     * tree says what a code OFFERS and this says where it can ARRIVE.
     */
    using Accepted = LeafList<
            events::tag::Cancel,
            events::tag::ChildChanged,
            events::tag::ChildCreated,
            events::tag::ChildDeleted,
            events::tag::Clicked,
            events::tag::CoverCheck,
            events::tag::Create,
            events::tag::Defocused,
            events::tag::Delete,
            events::tag::DoubleClicked,
            events::tag::DrawMain,
            events::tag::DrawMainBegin,
            events::tag::DrawMainEnd,
            events::tag::DrawPost,
            events::tag::DrawPostBegin,
            events::tag::DrawPostEnd,
            events::tag::DrawTaskAdded,
            events::tag::Focused,
            events::tag::Gesture,
            events::tag::GetSelfSize,
            events::tag::HitTest,
            events::tag::HoverLeave,
            events::tag::HoverOver,
            events::tag::IndevReset,
            events::tag::Insert,
            events::tag::Key,
            events::tag::LayoutChanged,
            events::tag::Leave,
            events::tag::LongPressed,
            events::tag::LongPressedRepeat,
            events::tag::PressLost,
            events::tag::Pressed,
            events::tag::Pressing,
            events::tag::Ready,
            events::tag::RefrExtDrawSize,
            events::tag::Refresh,
            events::tag::Released,
            events::tag::Rotary,
            events::tag::ScreenLoadStart,
            events::tag::ScreenLoaded,
            events::tag::ScreenUnloadStart,
            events::tag::ScreenUnloaded,
            events::tag::Scroll,
            events::tag::ScrollBegin,
            events::tag::ScrollEnd,
            events::tag::ScrollThrowBegin,
            events::tag::ShortClicked,
            events::tag::SingleClicked,
            events::tag::SizeChanged,
            events::tag::StateChanged,
            events::tag::StyleChanged,
            events::tag::TripleClicked,
            events::tag::ValueChanged>;
    template <class Tag>
    static constexpr bool accepts =
            AllEvents::template all_in<Tag, Accepted>();
    /**
     * Whether this target raises the destroying code, which is the
     * one moment a registration can hand memory back.
     */
    static constexpr bool has_destroy_event = true;
    static constexpr lv_event_code_t destroy_code = LV_EVENT_DELETE;
};

} // namespace detail

namespace detail {

/** The `display` target: what an event can be raised on, and how a handler is registered. */
struct DisplayTarget {
    using raw_type    = lv_display_t*;
    using wrapper     = Display;
    using code_type   = EventCode;
    using result_type = Result;

    static void add(raw_type t, lv_event_cb_t cb, lv_event_code_t filter,
                    void* ud) noexcept { lv_display_add_event_cb(t, cb, filter, ud); }

    /**
     * `!= 0` on purpose, and it is what lets one spelling serve both
     * versions: one remover takes ONE registration off and returns bool,
     * the other takes them all and returns the count. The caller loops.
     */
    static bool remove(raw_type t, lv_event_cb_t cb, void* ud) noexcept {
        return lv_display_remove_event_cb_with_user_data(t, cb, ud) != 0;
    }

    static result_type send(raw_type t, lv_event_code_t code,
                            void* param) noexcept {
        return static_cast<result_type>(lv_display_send_event(t, code, param));
    }

    static raw_type from_event(lv_event_t* e) noexcept {
        return static_cast<raw_type>(lv_event_get_target(e));
    }
    static raw_type current_from_event(lv_event_t* e) noexcept {
        return static_cast<raw_type>(lv_event_get_current_target(e));
    }

    /**
     * Measured from the sender's call sites, not from the tag tree: the
     * tree says what a code OFFERS and this says where it can ARRIVE.
     */
    using Accepted = LeafList<
            events::tag::ColorFormatChanged,
            events::tag::Delete,
            events::tag::FlushFinish,
            events::tag::FlushStart,
            events::tag::FlushWaitFinish,
            events::tag::FlushWaitStart,
            events::tag::InvalidateArea,
            events::tag::RefrReady,
            events::tag::RefrRequest,
            events::tag::RefrStart,
            events::tag::RenderReady,
            events::tag::RenderStart,
            events::tag::ResolutionChanged,
            events::tag::SyncFinish,
            events::tag::SyncStart,
            events::tag::SyncWaitFinish,
            events::tag::SyncWaitStart,
            events::tag::UpdateLayoutCompleted,
            events::tag::Vsync,
            events::tag::VsyncRequest>;
    template <class Tag>
    static constexpr bool accepts =
            AllEvents::template all_in<Tag, Accepted>();
    /**
     * Whether this target raises the destroying code, which is the
     * one moment a registration can hand memory back.
     */
    static constexpr bool has_destroy_event = true;
    static constexpr lv_event_code_t destroy_code = LV_EVENT_DELETE;
};

} // namespace detail

namespace detail {

/** The `indev` target: what an event can be raised on, and how a handler is registered. */
struct IndevTarget {
    using raw_type    = lv_indev_t*;
    using wrapper     = Indev;
    using code_type   = EventCode;
    using result_type = Result;

    static void add(raw_type t, lv_event_cb_t cb, lv_event_code_t filter,
                    void* ud) noexcept { lv_indev_add_event_cb(t, cb, filter, ud); }

    /**
     * `!= 0` on purpose, and it is what lets one spelling serve both
     * versions: one remover takes ONE registration off and returns bool,
     * the other takes them all and returns the count. The caller loops.
     */
    static bool remove(raw_type t, lv_event_cb_t cb, void* ud) noexcept {
        return lv_indev_remove_event_cb_with_user_data(t, cb, ud) != 0;
    }

    static result_type send(raw_type t, lv_event_code_t code,
                            void* param) noexcept {
        return static_cast<result_type>(lv_indev_send_event(t, code, param));
    }

    static raw_type from_event(lv_event_t* e) noexcept {
        return static_cast<raw_type>(lv_event_get_target(e));
    }
    static raw_type current_from_event(lv_event_t* e) noexcept {
        return static_cast<raw_type>(lv_event_get_current_target(e));
    }

    /**
     * Measured from the sender's call sites, not from the tag tree: the
     * tree says what a code OFFERS and this says where it can ARRIVE.
     */
    using Accepted = LeafList<
            events::tag::Clicked,
            events::tag::Delete,
            events::tag::HoverLeave,
            events::tag::HoverOver,
            events::tag::IndevReset,
            events::tag::Key,
            events::tag::LongPressed,
            events::tag::LongPressedRepeat,
            events::tag::Pressed,
            events::tag::Released,
            events::tag::Rotary,
            events::tag::ShortClicked>;
    template <class Tag>
    static constexpr bool accepts =
            AllEvents::template all_in<Tag, Accepted>();
    /**
     * Whether this target raises the destroying code, which is the
     * one moment a registration can hand memory back.
     */
    static constexpr bool has_destroy_event = true;
    static constexpr lv_event_code_t destroy_code = LV_EVENT_DELETE;
};

} // namespace detail

// ---------------------------------------------------------------------------------------------
// PRELUDE FRAGMENT (D-C6), part 2 of 2: the registration machinery.
//
// Nothing here names an LVGL symbol, and that is what lets one copy serve every version. Where a
// spelling differs -- the registration functions, the event-code enumeration, the result type --
// the TARGET declares it and this reads it back through the typedef. The targets are generated.
//
//   using raw_type    = lv_obj_t*;      what the C API takes
//   using wrapper     = Obj;            what the C++ API hands the user
//   using code_type   = Ev;             the scoped enumeration of codes
//   using result_type = Res;            what sending one yields
//
// It is placed after the targets and after the generated `EventData` specialisations, because
// `TypedEvent` names both.
// ---------------------------------------------------------------------------------------------
namespace detail {

/**
 * The OTHER axis. `EventData<Tag>` answers "what does this code offer"; this answers "what was it
 * raised on". They are independent, so the target is a mixin layered over whatever event type is
 * underneath rather than a second parameter threaded through the accessor chain -- which would
 * double the chain for a question none of its links ask.
 */
template <class Base, class Target>
struct WithTarget : Base {
    using Base::Base;
    using target_type = Target;

    /** The target the event was originally raised on -- stable while bubbling. */
    typename Target::wrapper target() const noexcept {
        return typename Target::wrapper(Target::from_event(this->raw()));
    }
    /** The target whose handler is running right now. */
    typename Target::wrapper current_target() const noexcept {
        return typename Target::wrapper(Target::current_from_event(this->raw()));
    }
    /** Shorthand for `target().as<T>()`. */
    template <class T> T target_as() const noexcept { return target().template as<T>(); }
};

} // namespace detail

/**
 * An event that knows its tag at compile time: `param()` comes back typed, and the accessors of
 * its whole ancestry -- and only those -- are in scope. The target is known too, so `target()` is
 * the right type rather than a cast waiting to happen.
 */
template <class Tag, class Target = detail::ObjTarget>
class TypedEvent : public detail::WithTarget<EventData<Tag>, Target> {
    using base = detail::WithTarget<EventData<Tag>, Target>;

public:
    using base::base;

    using tag_type = Tag;
    static constexpr typename Target::code_type static_code = Tag::code;

    typename Tag::Param* param() const noexcept {
        return static_cast<typename Tag::Param*>(lv_event_get_param(this->raw()));
    }
};

/**
 * What a CATEGORY and a runtime code hand out. The code is not one value, so there is no typed
 * `param()` and no ancestry of accessors -- but the TARGET is still fixed at compile time, so
 * `target()` still comes back typed. That is why the runtime trampoline passes this and not a
 * bare `Event`.
 */
template <class Target = detail::ObjTarget>
using TargetedEvent = detail::WithTarget<Event, Target>;

// The whole chain is empty bases over one pointer -- the target mixin included.
static_assert(sizeof(Event) == sizeof(lv_event_t*));
static_assert(sizeof(TargetedEvent<detail::ObjTarget>) == sizeof(lv_event_t*));

// =============================================================================================
// Handle to a registration
//
// Identified by (callback, user_data), NOT by the descriptor pointer the registration returns.
// That pointer is unusable in v8: the descriptors live in ONE array that is reallocated on every
// registration and compacted on every removal, so a stored pointer can end up naming a DIFFERENT
// registration -- register A, B, C; remove A; and B's handle now points at C. The comparison is by
// address, so it never crashes; it silently removes the wrong handler. In v9 each descriptor is
// allocated separately and the pointer is stable, which is why this only bites on one of them.
//
// The pair (cb, user_data) is stable under both. What it gives up: two registrations that agree on
// both are indistinguishable, and remove() takes both. That is the honest reading of "remove this
// handler", and a far smaller surprise than removing somebody else's.
//
// Deliberately NOT RAII: removing a handler on scope exit is almost never what the caller means.
// =============================================================================================
template <class Target = detail::ObjTarget>
class EventHandle {
    typename Target::raw_type target_ = nullptr;
    lv_event_cb_t             cb_     = nullptr;
    void*                     ud_     = nullptr;

public:
    using target_type = Target;

    constexpr EventHandle() noexcept = default;
    constexpr EventHandle(typename Target::raw_type t, lv_event_cb_t cb, void* ud) noexcept
        : target_(t), cb_(cb), ud_(ud) {}

    constexpr explicit operator bool() const noexcept { return cb_ != nullptr; }

    /**
     * Removes every registration on this target that matches (callback, user_data).
     *
     * The loop is what makes one spelling work on both versions, with no `#if`: one version's
     * remover takes ONE registration off and returns bool, the other takes them all and returns
     * the count. On the second, the second turn returns 0 and stops.
     */
    bool remove() noexcept {
        if (!target_ || !cb_) {
            return false;
        }
        bool any = false;
        while (Target::remove(target_, cb_, ud_)) {
            any = true;
        }
        target_ = nullptr;
        cb_     = nullptr;
        ud_     = nullptr;
        return any;
    }
};

namespace detail {

/**
 * The function LVGL actually calls.
 *
 * Split on emptiness rather than handled uniformly: a captureless callable has nothing in the
 * slot, so it must not read it. Measured -- the uniform version left a live
 * `lv_event_get_user_data` call in the stateless case, one call more than the equivalent C.
 * EVERY TRAMPOLINE IS `noexcept`, and it is not decoration. This is the one place where C++
 * is called BACK FROM C: LVGL holds the address and invokes it from its own frames. If the
 * user's handler throws and the trampoline does not stop it, the exception unwinds through C
 * frames, which is undefined -- the C side is not compiled with unwind tables and there is no
 * catch above it. `noexcept` turns that into `std::terminate`, which at least is defined
 * behaviour a debugger can stand on.
 *
 * It costs nothing where the binding is normally built. Under `-fno-exceptions` -- what
 * `verify-generated.sh` uses and what most LVGL targets use -- gcc emits no unwind machinery
 * either way. The flag is the CONSUMER'S, though, not a property of these headers, so the
 * declaration has to be right when somebody compiles them with exceptions on. And `noexcept`
 * is part of the function TYPE since C++17: `&call` converts to `lv_event_cb_t` because that
 * conversion goes from noexcept to non-noexcept, which is the direction that is allowed.
 */
template <class Tag, class Target, class F, bool Stateless = std::is_empty_v<F>>
struct Trampoline;

/**
 * Captureless: no state to recover. C++20 makes such closures default-constructible, so the
 * object is conjured at zero cost and the user_data slot is never touched.
 */
template <class Tag, class Target, class F>
struct Trampoline<Tag, Target, F, true> {
    static void call(lv_event_t* e) noexcept {
        TypedEvent<Tag, Target> ev{e};
        F f{};
        f(ev);
    }
};

/** Captures up to one pointer: the closure travels INSIDE the user_data slot. */
template <class Tag, class Target, class F>
struct Trampoline<Tag, Target, F, false> {
    static void call(lv_event_t* e) noexcept {
        F f = unpack<F>(lv_event_get_user_data(e));
        TypedEvent<Tag, Target> ev{e};
        f(ev);
    }
};

/** Member-function form: the receiver is the whole state, and a receiver is one pointer. */
template <class Tag, class Target, auto Method, class R>
struct MemberTrampoline {
    static void call(lv_event_t* e) noexcept {
        R* self = static_cast<R*>(lv_event_get_user_data(e));
        TypedEvent<Tag, Target> ev{e};
        (self->*Method)(ev);
    }
};

/**
 * Used for a CATEGORY and for a runtime code -- the two cases where the code is not one fixed
 * compile-time value, so the handler gets the untyped event. It is still target-parameterised:
 * the code is unknown, the target is not.
 *
 * This is also what makes registering a category cheap in flash: one category registers N codes,
 * but they all share THIS one trampoline, because it does not depend on the code. A per-code
 * trampoline would have put N copies in the binary.
 */
template <class Target, class F, bool Stateless = std::is_empty_v<F>>
struct RuntimeTrampoline;

template <class Target, class F>
struct RuntimeTrampoline<Target, F, true> {
    static void call(lv_event_t* e) noexcept {
        TargetedEvent<Target> ev{e};
        F f{};
        f(ev);
    }
};

template <class Target, class F>
struct RuntimeTrampoline<Target, F, false> {
    static void call(lv_event_t* e) noexcept {
        F f = unpack<F>(lv_event_get_user_data(e));
        TargetedEvent<Target> ev{e};
        f(ev);
    }
};

// =============================================================================================
// EventSource -- the registration points, once, for any target
//
// THIS IS NOT A RETURN TO CRTP, and it is worth saying so where somebody will read it. D-02 was
// decided against CRTP because a CRTP base returns `Derived` -- which is what breaks
// `void f(Obj&)`, closes leaf widgets to extension, and costs 2x compile time at 56 classes. This
// base returns `Derived` from nothing. It exists only to reach `raw()`, it is empty, and the
// `sizeof(Obj) == sizeof(void*)` assertion that already guarded the object model guards it too.
// =============================================================================================
template <class Derived, class Target>
class EventSource {
    typename Target::raw_type self() const noexcept {
        return static_cast<const Derived*>(this)->raw();
    }

    /**
     * The one thing a target can refuse: a code LVGL raises through a different sender, so the
     * registration would be accepted and never fire.
     *
     * The ROOT is exempt, and that is not a loophole. Registering on it means "whatever this
     * target does raise" -- it goes through LVGL's own catch-all filter in one call and never
     * names a code -- whereas `accepts<Root>` asks whether EVERY code in the library reaches
     * this target, which is false the moment there is a second kind of target.
     */
    template <class Tag>
    static constexpr void check_target() noexcept {
        static_assert(Tag::is_root || Target::template accepts<Tag>,
                "lv: this event code cannot reach this kind of target. LVGL raises it through a "
                "different *_send_event, so the registration would be accepted and never fire. "
                "See the target's accepts<> list -- it is measured from LVGL's own call sites.");
    }

public:
    // The code is not an enumeration ARGUMENT: it is a TAG, and the tag decides both what the
    // handler receives and how many registrations happen.
    //
    //     btn.on(events::Clicked,  [](auto& e) { ... });   // one code   -> TypedEvent<Clicked>&
    //     btn.on(events::Press,    [](Event& e) { ... });  // a category -> Event&, N registrations
    //     btn.on(events::Any,      [](Event& e) { ... });  // ALL, ONE registration, free

    /**
     * Any callable that fits in the single `void*` LVGL stores per registration. Captureless ->
     * nothing to store. Captures up to one pointer -> stored IN the slot. Neither allocates.
     */
    template <class Tag, class F>
    EventHandle<Target> on(Tag, F&& f) const noexcept {
        using D = std::decay_t<F>;
        check_target<Tag>();
        static_assert(fits_user_data<D>,
                "lv: this callable does not fit in the single void* LVGL stores per event "
                "registration. Capture only 'this' (or one handle), or use the member-function "
                "form on<&Type::method>(events::Code, receiver).");

        D copy = static_cast<F&&>(f);
        void* ud = pack(copy);
        if constexpr (!Tag::is_category) {
            static_assert(std::is_invocable_v<D&, TypedEvent<Tag, Target>&>,
                    "lv: the callable must accept an lv::Event& (or lv::TypedEvent<Tag>&).");
            lv_event_cb_t cb = &Trampoline<Tag, Target, D>::call;
            Target::add(self(), cb, static_cast<lv_event_code_t>(Tag::code), ud);
            return EventHandle<Target>(self(), cb, ud);
        } else {
            static_assert(std::is_invocable_v<D&, TargetedEvent<Target>&>,
                    "lv: a handler registered on a CATEGORY must accept an lv::Event&. The code "
                    "is not one fixed value, so there is no TypedEvent<Tag> to hand it.");
            lv_event_cb_t cb = &RuntimeTrampoline<Target, D>::call;
            if constexpr (Tag::is_root) {
                // The root is free: LVGL's own "all" filter already means everything.
                Target::add(self(), cb, static_cast<lv_event_code_t>(Tag::code), ud);
            } else {
                // Every other category expands to one registration per leaf under it. They all
                // share this single trampoline, so the binary does not grow with the category.
                typename Target::raw_type t = self();
                AllEvents::template for_each_in<Tag>([&](auto leaf) {
                    Target::add(t, cb, static_cast<lv_event_code_t>(decltype(leaf)::code), ud);
                });
            }
            return EventHandle<Target>(self(), cb, ud);
        }
    }

    /**
     * A member function plus its receiver. The receiver is one pointer, so it fits. Only for a
     * single code -- a member function that wants a whole category should take the untyped event
     * and go through the callable form.
     */
    template <auto Method, class Tag, class R>
    EventHandle<Target> on(Tag, R* receiver) const noexcept {
        static_assert(!Tag::is_category,
                "lv: the member-function form takes one event code, not a category.");
        check_target<Tag>();
        static_assert(std::is_invocable_v<decltype(Method), R*, TypedEvent<Tag, Target>&>,
                "lv: &Type::method must be callable as (receiver->*method)(lv::Event&).");
        lv_event_cb_t cb = &MemberTrampoline<Tag, Target, Method, R>::call;
        Target::add(self(), cb, static_cast<lv_event_code_t>(Tag::code), receiver);
        return EventHandle<Target>(self(), cb, receiver);
    }

    /**
     * Registration on a code that is only known at RUNTIME. There is no compile-time tag, so the
     * handler receives the untyped event and `param()` stays a `void*`, exactly as in C. Nothing
     * can check the target here either: the code is a value.
     */
    template <class F>
    EventHandle<Target> on(typename Target::code_type code, F&& f) const noexcept {
        using D = std::decay_t<F>;
        static_assert(fits_user_data<D>,
                "lv: this callable does not fit in the single void* LVGL stores per event "
                "registration.");
        static_assert(std::is_invocable_v<D&, TargetedEvent<Target>&>,
                "lv: a runtime-code handler must accept an lv::Event&. It cannot take a "
                "TypedEvent<Tag>&, because the code is not known until it runs.");
        D copy = static_cast<F&&>(f);
        void* ud = pack(copy);
        lv_event_cb_t cb = &RuntimeTrampoline<Target, D>::call;
        Target::add(self(), cb, static_cast<lv_event_code_t>(code), ud);
        return EventHandle<Target>(self(), cb, ud);
    }

    /**
     * The third way out, named so that it can never happen by accident: the callable goes on
     * the HEAP. Costs one allocation plus a second registration to free it again, and only works
     * where the target says it raises the destroying code -- because that registration is what
     * hands the memory back.
     *
     * The two registrations share their user_data and not their callback, so removing the handle
     * takes `owned_call` off and leaves `owned_release` alive to free on destruction. That is
     * the intended behaviour, and it is what identifying a registration by (cb, user_data)
     * buys. The destroying code itself comes from the model (D-C18), and the allocator with it:
     * one version spells it lv_malloc and the other lv_mem_alloc.
     */
    template <class Tag, class F>
    EventHandle<Target> on_owned(Tag, F&& f) const noexcept {
        static_assert(!Tag::is_category,
                "lv: on_owned takes one event code, not a category.");
        static_assert(Target::has_destroy_event,
                "lv: on_owned needs the target to raise its destroying event, because that "
                "registration is what frees the closure. This target does not.");
        check_target<Tag>();
        using D = std::decay_t<F>;
        static_assert(std::is_invocable_v<D&, TypedEvent<Tag, Target>&>,
                "lv: the callable must accept an lv::Event& (or lv::TypedEvent<Tag>&).");
        void* mem = alloc(sizeof(D));
        if (mem == nullptr) {
            return EventHandle<Target>();
        }
        ::new (mem) D(static_cast<F&&>(f));
        Target::add(self(), &owned_release<D>, Target::destroy_code, mem);
        Target::add(self(), &owned_call<Tag, D>, static_cast<lv_event_code_t>(Tag::code), mem);
        return EventHandle<Target>(self(), &owned_call<Tag, D>, mem);
    }

    /** The raw escape hatch, unchanged from C. */
    EventHandle<Target> add_event_cb(lv_event_cb_t cb, typename Target::code_type filter,
                                     void* user_data) const noexcept {
        Target::add(self(), cb, static_cast<lv_event_code_t>(filter), user_data);
        return EventHandle<Target>(self(), cb, user_data);
    }

    /**
     * One of the three operations every target has. The C symbol differs between versions, which
     * is why the target owns it and this only forwards.
     */
    typename Target::result_type send_event(typename Target::code_type code,
                                            void* param = nullptr) const noexcept {
        return Target::send(self(), static_cast<lv_event_code_t>(code), param);
    }

private:
    /**
     * The heap handler's two halves. `owned_call` runs it; `owned_release` destroys it and gives
     * the memory back, and is registered on the destroying code so that it always runs exactly
     * once, whether or not anybody kept the handle.
     */
    template <class Tag, class D>
    static void owned_call(lv_event_t* e) {
        TypedEvent<Tag, Target> ev{e};
        (*static_cast<D*>(lv_event_get_user_data(e)))(ev);
    }

    template <class D>
    static void owned_release(lv_event_t* e) {
        D* d = static_cast<D*>(lv_event_get_user_data(e));
        d->~D();
        detail::release(d);
    }
};

} // namespace detail

/**
 * Event codes of one's own. `lv_event_register_id()` hands out ids past the built-in ones;
 * tagging them gives each its own C++ type, so two unrelated custom events cannot be confused.
 *
 * COST, stated because it is the one thing here that is not free: one function-local `static` per
 * tag -- a word of storage, a guard variable, and a test on every call. With
 * `-fno-threadsafe-statics` (usual on a microcontroller) the test is a compare against zero.
 */
template <class Tag, class Code>
struct CustomEvent {
    static Code code() noexcept {
        static const Code c = static_cast<Code>(lv_event_register_id());
        return c;
    }
};

namespace detail {

/** Zero-cost shorthands: each forwards to `on(events::X, f)`. */
template <class Derived, class Target>
class EventAliases : public EventSource<Derived, Target> {
    using base = EventSource<Derived, Target>;

public:
    template <class F> EventHandle<Target> on_pressed(F&& f) const noexcept {
        return base::on(events::Pressed, static_cast<F&&>(f));
    }
    template <class F> EventHandle<Target> on_short_clicked(F&& f) const noexcept {
        return base::on(events::ShortClicked, static_cast<F&&>(f));
    }
    template <class F> EventHandle<Target> on_long_pressed(F&& f) const noexcept {
        return base::on(events::LongPressed, static_cast<F&&>(f));
    }
    template <class F> EventHandle<Target> on_clicked(F&& f) const noexcept {
        return base::on(events::Clicked, static_cast<F&&>(f));
    }
    template <class F> EventHandle<Target> on_released(F&& f) const noexcept {
        return base::on(events::Released, static_cast<F&&>(f));
    }
    template <class F> EventHandle<Target> on_scroll(F&& f) const noexcept {
        return base::on(events::Scroll, static_cast<F&&>(f));
    }
    template <class F> EventHandle<Target> on_focused(F&& f) const noexcept {
        return base::on(events::Focused, static_cast<F&&>(f));
    }
    template <class F> EventHandle<Target> on_defocused(F&& f) const noexcept {
        return base::on(events::Defocused, static_cast<F&&>(f));
    }
    template <class F> EventHandle<Target> on_value_changed(F&& f) const noexcept {
        return base::on(events::ValueChanged, static_cast<F&&>(f));
    }
    template <class F> EventHandle<Target> on_insert(F&& f) const noexcept {
        return base::on(events::Insert, static_cast<F&&>(f));
    }
    template <class F> EventHandle<Target> on_ready(F&& f) const noexcept {
        return base::on(events::Ready, static_cast<F&&>(f));
    }
    template <class F> EventHandle<Target> on_cancel(F&& f) const noexcept {
        return base::on(events::Cancel, static_cast<F&&>(f));
    }
    template <class F> EventHandle<Target> on_delete(F&& f) const noexcept {
        return base::on(events::Delete, static_cast<F&&>(f));
    }
};

} // namespace detail

/**
 * Event callback.
 * Events are used to notify the user of some action being taken on Widget.
 * For details, see ::lv_event_t.
 * @see lv_event_send
 */
inline Result event_send(lv_event_list_t* list, Event& e, bool preprocess) noexcept;

/** @see lv_event_add */
inline EventDsc event_add(lv_event_list_t* list, lv_event_cb_t cb, EventCode filter, void* user_data) noexcept;

/** @see lv_event_remove_dsc */
inline bool event_remove_dsc(lv_event_list_t* list, EventDsc dsc) noexcept;

/** @see lv_event_get_count */
inline uint32_t event_get_count(lv_event_list_t* list) noexcept;

/** @see lv_event_get_dsc */
inline EventDsc event_get_dsc(lv_event_list_t* list, uint32_t index) noexcept;

/** @see lv_event_remove */
inline bool event_remove(lv_event_list_t* list, uint32_t index) noexcept;

/** @see lv_event_remove_all */
inline void event_remove_all(lv_event_list_t* list) noexcept;

/**
 * Register a new, custom event ID.
 * It can be used the same way as e.g. `LV_EVENT_CLICKED` to send custom events
 * @see lv_event_register_id
 */
inline uint32_t event_register_id() noexcept;

/**
 * Get the name of an event code.
 * @param code  the event code
 * @return the name of the event code as a string
 * @see lv_event_code_get_name
 */
inline const char* event_code_get_name(EventCode code) noexcept;

#if LV_USE_EXT_DATA
/**
 * Set external data and its destructor for an event descriptor.
 * This allows associating custom data with an event callback that will be automatically cleaned up
 * when the event descriptor is removed or destroyed.
 * @param dsc  pointer to an event descriptor (from lv_obj_add_event_cb)
 * @param data  pointer to the external data to associate with the event descriptor
 * @see lv_event_desc_set_external_data
 */
inline void event_desc_set_external_data(EventDsc dsc, void* data, void (*arg)(void*)) noexcept;
#endif // LV_USE_EXT_DATA

} // namespace lv
