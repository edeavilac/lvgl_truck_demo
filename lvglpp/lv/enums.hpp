#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lvgl.h"
#include <cstdint>

namespace lv {

/** Predefined keys to control which Widget has focus via lv_group_send(group, c) */
enum class Key : int {
    Up = LV_KEY_UP,
    Down = LV_KEY_DOWN,
    Right = LV_KEY_RIGHT,
    Left = LV_KEY_LEFT,
    Esc = LV_KEY_ESC,
    Del = LV_KEY_DEL,
    Backspace = LV_KEY_BACKSPACE,
    Enter = LV_KEY_ENTER,
    Next = LV_KEY_NEXT,
    Prev = LV_KEY_PREV,
    Home = LV_KEY_HOME,
    End = LV_KEY_END,
};

enum class GroupRefocusPolicy : int {
    Next = LV_GROUP_REFOCUS_POLICY_NEXT,
    Prev = LV_GROUP_REFOCUS_POLICY_PREV,
};

/**
 * On/Off features controlling the object's behavior.
 * OR-ed values are possible
 * Note: update obj flags corresponding properties below
 * whenever add/remove flags or change bit definition of flags.
 */
enum class ObjFlag : int {
    /** Make the object hidden. (Like it wasn't there at all) */
    Hidden = LV_OBJ_FLAG_HIDDEN,
    /** Make the object clickable by the input devices */
    Clickable = LV_OBJ_FLAG_CLICKABLE,
    /** Add focused state to the object when clicked */
    ClickFocusable = LV_OBJ_FLAG_CLICK_FOCUSABLE,
    /** Toggle checked state when the object is clicked */
    Checkable = LV_OBJ_FLAG_CHECKABLE,
    /** Make the object scrollable */
    Scrollable = LV_OBJ_FLAG_SCROLLABLE,
    /** Allow scrolling inside but with slower speed */
    ScrollElastic = LV_OBJ_FLAG_SCROLL_ELASTIC,
    /** Make the object scroll further when "thrown" */
    ScrollMomentum = LV_OBJ_FLAG_SCROLL_MOMENTUM,
    /** Allow scrolling only one snappable children */
    ScrollOne = LV_OBJ_FLAG_SCROLL_ONE,
    /** Allow propagating the horizontal scroll to a parent */
    ScrollChainHor = LV_OBJ_FLAG_SCROLL_CHAIN_HOR,
    /** Allow propagating the vertical scroll to a parent */
    ScrollChainVer = LV_OBJ_FLAG_SCROLL_CHAIN_VER,
    ScrollChain = LV_OBJ_FLAG_SCROLL_CHAIN,
    /** Automatically scroll object to make it visible when focused */
    ScrollOnFocus = LV_OBJ_FLAG_SCROLL_ON_FOCUS,
    /** Allow scrolling the focused object with arrow keys */
    ScrollWithArrow = LV_OBJ_FLAG_SCROLL_WITH_ARROW,
    /** If scroll snap is enabled on the parent it can snap to this object */
    Snappable = LV_OBJ_FLAG_SNAPPABLE,
    /** Keep the object pressed even if the press slid from the object */
    PressLock = LV_OBJ_FLAG_PRESS_LOCK,
    /** Propagate the events to the parent too */
    EventBubble = LV_OBJ_FLAG_EVENT_BUBBLE,
    /** Propagate the gestures to the parent */
    GestureBubble = LV_OBJ_FLAG_GESTURE_BUBBLE,
    /** Allow performing more accurate hit (click) test. E.g. consider rounded corners. */
    AdvHittest = LV_OBJ_FLAG_ADV_HITTEST,
    /** Make the object not positioned by the layouts */
    IgnoreLayout = LV_OBJ_FLAG_IGNORE_LAYOUT,
    /** Do not scroll the object when the parent scrolls and ignore layout */
    Floating = LV_OBJ_FLAG_FLOATING,
    /** Send `LV_EVENT_DRAW_TASK_ADDED` events */
    SendDrawTaskEvents = LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS,
    /** Do not clip the children to the parent's ext draw size */
    OverflowVisible = LV_OBJ_FLAG_OVERFLOW_VISIBLE,
    /** Propagate the events to the children too */
    EventTrickle = LV_OBJ_FLAG_EVENT_TRICKLE,
    /** Propagate the states to the children too */
    StateTrickle = LV_OBJ_FLAG_STATE_TRICKLE,
    /** Custom flag, free to use by layouts */
    Layout1 = LV_OBJ_FLAG_LAYOUT_1,
    /** Custom flag, free to use by layouts */
    Layout2 = LV_OBJ_FLAG_LAYOUT_2,
    #if LV_USE_FLEX
    /** Start a new flex track on this item */
    FlexInNewTrack = LV_OBJ_FLAG_FLEX_IN_NEW_TRACK,
    #endif // LV_USE_FLEX

    /** Custom flag, free to use by widget */
    Widget1 = LV_OBJ_FLAG_WIDGET_1,
    /** Custom flag, free to use by widget */
    Widget2 = LV_OBJ_FLAG_WIDGET_2,
    /** Custom flag, free to use by user */
    User1 = LV_OBJ_FLAG_USER_1,
    /** Custom flag, free to use by user */
    User2 = LV_OBJ_FLAG_USER_2,
    /** Custom flag, free to use by user */
    User3 = LV_OBJ_FLAG_USER_3,
    /** Custom flag, free to use by user */
    User4 = LV_OBJ_FLAG_USER_4,
};
constexpr ObjFlag operator|(ObjFlag a, ObjFlag b) noexcept {
    return static_cast<ObjFlag>(static_cast<int>(a) | static_cast<int>(b));
}
constexpr ObjFlag operator&(ObjFlag a, ObjFlag b) noexcept {
    return static_cast<ObjFlag>(static_cast<int>(a) & static_cast<int>(b));
}
constexpr ObjFlag operator^(ObjFlag a, ObjFlag b) noexcept {
    return static_cast<ObjFlag>(static_cast<int>(a) ^ static_cast<int>(b));
}
constexpr ObjFlag& operator|=(ObjFlag& a, ObjFlag b) noexcept { a = a | b; return a; }

#if LV_USE_OBJ_PROPERTY
enum class SignedPropId : int {
    FlagStart = LV_PROPERTY_OBJ_FLAG_START,
    FlagHidden = LV_PROPERTY_OBJ_FLAG_HIDDEN,
    FlagClickable = LV_PROPERTY_OBJ_FLAG_CLICKABLE,
    FlagClickFocusable = LV_PROPERTY_OBJ_FLAG_CLICK_FOCUSABLE,
    FlagCheckable = LV_PROPERTY_OBJ_FLAG_CHECKABLE,
    FlagScrollable = LV_PROPERTY_OBJ_FLAG_SCROLLABLE,
    FlagScrollElastic = LV_PROPERTY_OBJ_FLAG_SCROLL_ELASTIC,
    FlagScrollMomentum = LV_PROPERTY_OBJ_FLAG_SCROLL_MOMENTUM,
    FlagScrollOne = LV_PROPERTY_OBJ_FLAG_SCROLL_ONE,
    FlagScrollChainHor = LV_PROPERTY_OBJ_FLAG_SCROLL_CHAIN_HOR,
    FlagScrollChainVer = LV_PROPERTY_OBJ_FLAG_SCROLL_CHAIN_VER,
    FlagScrollOnFocus = LV_PROPERTY_OBJ_FLAG_SCROLL_ON_FOCUS,
    FlagScrollWithArrow = LV_PROPERTY_OBJ_FLAG_SCROLL_WITH_ARROW,
    FlagSnappable = LV_PROPERTY_OBJ_FLAG_SNAPPABLE,
    FlagPressLock = LV_PROPERTY_OBJ_FLAG_PRESS_LOCK,
    FlagEventBubble = LV_PROPERTY_OBJ_FLAG_EVENT_BUBBLE,
    FlagGestureBubble = LV_PROPERTY_OBJ_FLAG_GESTURE_BUBBLE,
    FlagAdvHittest = LV_PROPERTY_OBJ_FLAG_ADV_HITTEST,
    FlagIgnoreLayout = LV_PROPERTY_OBJ_FLAG_IGNORE_LAYOUT,
    FlagFloating = LV_PROPERTY_OBJ_FLAG_FLOATING,
    FlagSendDrawTaskEvents = LV_PROPERTY_OBJ_FLAG_SEND_DRAW_TASK_EVENTS,
    FlagOverflowVisible = LV_PROPERTY_OBJ_FLAG_OVERFLOW_VISIBLE,
    FlagEventTrickle = LV_PROPERTY_OBJ_FLAG_EVENT_TRICKLE,
    FlagStateTrickle = LV_PROPERTY_OBJ_FLAG_STATE_TRICKLE,
    FlagLayout1 = LV_PROPERTY_OBJ_FLAG_LAYOUT_1,
    FlagLayout2 = LV_PROPERTY_OBJ_FLAG_LAYOUT_2,
    FlagFlexInNewTrack = LV_PROPERTY_OBJ_FLAG_FLEX_IN_NEW_TRACK,
    FlagWidget1 = LV_PROPERTY_OBJ_FLAG_WIDGET_1,
    FlagWidget2 = LV_PROPERTY_OBJ_FLAG_WIDGET_2,
    FlagUser1 = LV_PROPERTY_OBJ_FLAG_USER_1,
    FlagUser2 = LV_PROPERTY_OBJ_FLAG_USER_2,
    FlagUser3 = LV_PROPERTY_OBJ_FLAG_USER_3,
    FlagUser4 = LV_PROPERTY_OBJ_FLAG_USER_4,
    FlagEnd = LV_PROPERTY_OBJ_FLAG_END,
    StateStart = LV_PROPERTY_OBJ_STATE_START,
    StateAlt = LV_PROPERTY_OBJ_STATE_ALT,
    StateChecked = LV_PROPERTY_OBJ_STATE_CHECKED,
    StateFocused = LV_PROPERTY_OBJ_STATE_FOCUSED,
    StateFocusKey = LV_PROPERTY_OBJ_STATE_FOCUS_KEY,
    StateEdited = LV_PROPERTY_OBJ_STATE_EDITED,
    StateHovered = LV_PROPERTY_OBJ_STATE_HOVERED,
    StatePressed = LV_PROPERTY_OBJ_STATE_PRESSED,
    StateScrolled = LV_PROPERTY_OBJ_STATE_SCROLLED,
    StateDisabled = LV_PROPERTY_OBJ_STATE_DISABLED,
    StateUser1 = LV_PROPERTY_OBJ_STATE_USER_1,
    StateUser2 = LV_PROPERTY_OBJ_STATE_USER_2,
    StateUser3 = LV_PROPERTY_OBJ_STATE_USER_3,
    StateUser4 = LV_PROPERTY_OBJ_STATE_USER_4,
    StateAny = LV_PROPERTY_OBJ_STATE_ANY,
    StateEnd = LV_PROPERTY_OBJ_STATE_END,
    Parent = LV_PROPERTY_OBJ_PARENT,
    X = LV_PROPERTY_OBJ_X,
    Y = LV_PROPERTY_OBJ_Y,
    W = LV_PROPERTY_OBJ_W,
    H = LV_PROPERTY_OBJ_H,
    ContentWidth = LV_PROPERTY_OBJ_CONTENT_WIDTH,
    ContentHeight = LV_PROPERTY_OBJ_CONTENT_HEIGHT,
    Layout = LV_PROPERTY_OBJ_LAYOUT,
    Align = LV_PROPERTY_OBJ_ALIGN,
    ScrollbarMode = LV_PROPERTY_OBJ_SCROLLBAR_MODE,
    ScrollDir = LV_PROPERTY_OBJ_SCROLL_DIR,
    ScrollSnapX = LV_PROPERTY_OBJ_SCROLL_SNAP_X,
    ScrollSnapY = LV_PROPERTY_OBJ_SCROLL_SNAP_Y,
    ScrollX = LV_PROPERTY_OBJ_SCROLL_X,
    ScrollY = LV_PROPERTY_OBJ_SCROLL_Y,
    ScrollTop = LV_PROPERTY_OBJ_SCROLL_TOP,
    ScrollBottom = LV_PROPERTY_OBJ_SCROLL_BOTTOM,
    ScrollLeft = LV_PROPERTY_OBJ_SCROLL_LEFT,
    ScrollRight = LV_PROPERTY_OBJ_SCROLL_RIGHT,
    ScrollEnd = LV_PROPERTY_OBJ_SCROLL_END,
    ExtDrawSize = LV_PROPERTY_OBJ_EXT_DRAW_SIZE,
    EventCount = LV_PROPERTY_OBJ_EVENT_COUNT,
    Screen = LV_PROPERTY_OBJ_SCREEN,
    Display = LV_PROPERTY_OBJ_DISPLAY,
    ChildCount = LV_PROPERTY_OBJ_CHILD_COUNT,
    Index = LV_PROPERTY_OBJ_INDEX,
    End = LV_PROPERTY_OBJ_END,
};
#endif // LV_USE_OBJ_PROPERTY

enum class ObjClassEditable : int {
    /** Check the base class. Must have 0 value to let zero initialized class inherit */
    Inherit = LV_OBJ_CLASS_EDITABLE_INHERIT,
    True = LV_OBJ_CLASS_EDITABLE_TRUE,
    False = LV_OBJ_CLASS_EDITABLE_FALSE,
};

enum class ObjClassGroupDef : int {
    /** Check the base class. Must have 0 value to let zero initialized class inherit */
    Inherit = LV_OBJ_CLASS_GROUP_DEF_INHERIT,
    True = LV_OBJ_CLASS_GROUP_DEF_TRUE,
    False = LV_OBJ_CLASS_GROUP_DEF_FALSE,
};

enum class ObjClassThemeInheritable : int {
    /** Do not inherit theme from base class. */
    False = LV_OBJ_CLASS_THEME_INHERITABLE_FALSE,
    True = LV_OBJ_CLASS_THEME_INHERITABLE_TRUE,
};

/** Store the type of layer required to render a widget. */
enum class LayerType : int {
    /** No layer is needed. */
    None = LV_LAYER_TYPE_NONE,
    /**
     * Simple layer means that the layer can be rendered in chunks.
     * For example with opa_layered = 140 it's possible to render only 10 lines
     * from the layer. When it's ready go to the next 10 lines.
     * It avoids large memory allocations for the layer buffer.
     * The buffer size for a chunk can be set by `LV_DRAW_LAYER_SIMPLE_BUF_SIZE` in lv_conf.h.
     */
    Simple = LV_LAYER_TYPE_SIMPLE,
    /**
     * The widget is transformed and cannot be rendered in chunks.
     * It's because - due to the transformations -  pixel outside of
     * a given area will also contribute to the final image.
     * In this case there is no limitation on the buffer size.
     * LVGL will allocate as large buffer as needed to render the transformed area.
     */
    Transform = LV_LAYER_TYPE_TRANSFORM,
};

/** Cover check results. */
enum class CoverRes : int {
    Cover = LV_COVER_RES_COVER,
    NotCover = LV_COVER_RES_NOT_COVER,
    Masked = LV_COVER_RES_MASKED,
};

enum class ObjPointTransformFlag : int {
    /** No flags */
    None = LV_OBJ_POINT_TRANSFORM_FLAG_NONE,
    /** Consider the transformation properties of the parents too */
    Recursive = LV_OBJ_POINT_TRANSFORM_FLAG_RECURSIVE,
    /** Execute the inverse of the transformation (-angle and 1/zoom) */
    Inverse = LV_OBJ_POINT_TRANSFORM_FLAG_INVERSE,
    /** Both inverse and recursive */
    InverseRecursive = LV_OBJ_POINT_TRANSFORM_FLAG_INVERSE_RECURSIVE,
};

#if LV_USE_OBJ_PROPERTY
/** Group of predefined widget ID start value. */
enum class PropIdRangeBoundary : int {
    IdInvalid = LV_PROPERTY_ID_INVALID,
    StyleStart = LV_PROPERTY_STYLE_START,
    IdStart = LV_PROPERTY_ID_START,
    ObjStart = LV_PROPERTY_OBJ_START,
    ImageStart = LV_PROPERTY_IMAGE_START,
    LabelStart = LV_PROPERTY_LABEL_START,
    KeyboardStart = LV_PROPERTY_KEYBOARD_START,
    TextareaStart = LV_PROPERTY_TEXTAREA_START,
    RollerStart = LV_PROPERTY_ROLLER_START,
    DropdownStart = LV_PROPERTY_DROPDOWN_START,
    SliderStart = LV_PROPERTY_SLIDER_START,
    AnimimageStart = LV_PROPERTY_ANIMIMAGE_START,
    ArcStart = LV_PROPERTY_ARC_START,
    BarStart = LV_PROPERTY_BAR_START,
    SwitchStart = LV_PROPERTY_SWITCH_START,
    CheckboxStart = LV_PROPERTY_CHECKBOX_START,
    LedStart = LV_PROPERTY_LED_START,
    LineStart = LV_PROPERTY_LINE_START,
    ScaleStart = LV_PROPERTY_SCALE_START,
    SpinboxStart = LV_PROPERTY_SPINBOX_START,
    SpinnerStart = LV_PROPERTY_SPINNER_START,
    TableStart = LV_PROPERTY_TABLE_START,
    TabviewStart = LV_PROPERTY_TABVIEW_START,
    ButtonmatrixStart = LV_PROPERTY_BUTTONMATRIX_START,
    SpanStart = LV_PROPERTY_SPAN_START,
    MenuStart = LV_PROPERTY_MENU_START,
    ChartStart = LV_PROPERTY_CHART_START,
    IdAny = LV_PROPERTY_ID_ANY,
};
#endif // LV_USE_OBJ_PROPERTY

/** Scrollbar modes: shows when should the scrollbars be visible */
enum class ScrollbarMode : int {
    /** Never show scrollbars */
    Off = LV_SCROLLBAR_MODE_OFF,
    /** Always show scrollbars */
    On = LV_SCROLLBAR_MODE_ON,
    /** Show scroll bars when Widget is being scrolled */
    Active = LV_SCROLLBAR_MODE_ACTIVE,
    /** Show scroll bars when the content is large enough to be scrolled */
    Auto = LV_SCROLLBAR_MODE_AUTO,
};

/** Scroll span align options. Tells where to align the snappable children when scroll stops. */
enum class ScrollSnap : int {
    /** Do not align, leave where it is */
    None = LV_SCROLL_SNAP_NONE,
    /** Align to the left/top */
    Start = LV_SCROLL_SNAP_START,
    /** Align to the right/bottom */
    End = LV_SCROLL_SNAP_END,
    /** Align to the center */
    Center = LV_SCROLL_SNAP_CENTER,
};

/**
 * Possible states of a widget.
 * OR-ed values are possible
 */
enum class State : int {
    Default = LV_STATE_DEFAULT,
    Alt = LV_STATE_ALT,
    Checked = LV_STATE_CHECKED,
    Focused = LV_STATE_FOCUSED,
    FocusKey = LV_STATE_FOCUS_KEY,
    Edited = LV_STATE_EDITED,
    Hovered = LV_STATE_HOVERED,
    Pressed = LV_STATE_PRESSED,
    Scrolled = LV_STATE_SCROLLED,
    Disabled = LV_STATE_DISABLED,
    User1 = LV_STATE_USER_1,
    User2 = LV_STATE_USER_2,
    User3 = LV_STATE_USER_3,
    User4 = LV_STATE_USER_4,
    /** Special value can be used in some functions to target all states */
    Any = LV_STATE_ANY,
};
constexpr State operator|(State a, State b) noexcept {
    return static_cast<State>(static_cast<int>(a) | static_cast<int>(b));
}
constexpr State operator&(State a, State b) noexcept {
    return static_cast<State>(static_cast<int>(a) & static_cast<int>(b));
}
constexpr State operator^(State a, State b) noexcept {
    return static_cast<State>(static_cast<int>(a) ^ static_cast<int>(b));
}
constexpr State& operator|=(State& a, State b) noexcept { a = a | b; return a; }

/**
 * The possible parts of widgets.
 * The parts can be considered as the internal building block of the widgets.
 * E.g. slider = background + indicator + knob
 * Not all parts are used by every widget
 */
enum class Part : int {
    /** A background like rectangle */
    Main = LV_PART_MAIN,
    /** The scrollbar(s) */
    Scrollbar = LV_PART_SCROLLBAR,
    /** Indicator, e.g. for slider, bar, switch, or the tick box of the checkbox */
    Indicator = LV_PART_INDICATOR,
    /** Like handle to grab to adjust the value */
    Knob = LV_PART_KNOB,
    /** Indicate the currently selected option or section */
    Selected = LV_PART_SELECTED,
    /** Used if the widget has multiple similar elements (e.g. table cells) */
    Items = LV_PART_ITEMS,
    /** Mark a specific place e.g. for text area's cursor or on a chart */
    Cursor = LV_PART_CURSOR,
    /** Extension point for custom widgets */
    CustomFirst = LV_PART_CUSTOM_FIRST,
    /** Special value can be used in some functions to target all parts */
    Any = LV_PART_ANY,
};
constexpr Part operator|(Part a, Part b) noexcept {
    return static_cast<Part>(static_cast<int>(a) | static_cast<int>(b));
}
constexpr Part operator&(Part a, Part b) noexcept {
    return static_cast<Part>(static_cast<int>(a) & static_cast<int>(b));
}
constexpr Part operator^(Part a, Part b) noexcept {
    return static_cast<Part>(static_cast<int>(a) ^ static_cast<int>(b));
}
constexpr Part& operator|=(Part& a, Part b) noexcept { a = a | b; return a; }

enum class StyleStateCmp : int {
    /** The style properties in the 2 states are identical */
    Same = LV_STYLE_STATE_CMP_SAME,
    /** The differences can be shown with a simple redraw */
    DiffRedraw = LV_STYLE_STATE_CMP_DIFF_REDRAW,
    /** The differences can be shown with a simple redraw */
    DiffDrawPad = LV_STYLE_STATE_CMP_DIFF_DRAW_PAD,
    /** The differences can be shown with a simple redraw */
    DiffLayout = LV_STYLE_STATE_CMP_DIFF_LAYOUT,
};

enum class ObjTreeWalkRes : int {
    Next = LV_OBJ_TREE_WALK_NEXT,
    SkipChildren = LV_OBJ_TREE_WALK_SKIP_CHILDREN,
    End = LV_OBJ_TREE_WALK_END,
};

#if LV_USE_OBSERVER
/** Values for lv_subject_t's `type` field */
enum class SubjectType : int {
    /** indicates Subject not initialized yet */
    Invalid = LV_SUBJECT_TYPE_INVALID,
    /** a null value like None or NILt */
    None = LV_SUBJECT_TYPE_NONE,
    /** an int32_t */
    Int = LV_SUBJECT_TYPE_INT,
    /** a float, requires `LV_USE_FLOAT 1` */
    Float = LV_SUBJECT_TYPE_FLOAT,
    /** a void pointer */
    Pointer = LV_SUBJECT_TYPE_POINTER,
    /** an lv_color_t */
    Color = LV_SUBJECT_TYPE_COLOR,
    /** an array of Subjects */
    Group = LV_SUBJECT_TYPE_GROUP,
    /** a char pointer */
    String = LV_SUBJECT_TYPE_STRING,
};
#endif // LV_USE_OBSERVER

#if LV_USE_TEST && defined(LV_USE_TEST_SCREENSHOT_COMPARE) && LV_USE_TEST_SCREENSHOT_COMPARE
/** Return value of `lv_test_screenshot_compare` */
enum class TestScreenshotResult : int {
    /** The screenshot is different than the reference image */
    Failed = LV_TEST_SCREENSHOT_RESULT_FAILED,
    /**
     * The screenshot is the same as the reference image.
     * It is also returned if `LV_TEST_SCREENSHOT_CREATE_REFERENCE_IMAGE` is enabled
     * and the reference image was missing.
     */
    Passed = LV_TEST_SCREENSHOT_RESULT_PASSED,
    /**
     * If `LV_TEST_SCREENSHOT_CREATE_REFERENCE_IMAGE` is not enabled
     * and the reference image is missing.
     */
    NoReferenceImage = LV_TEST_SCREENSHOT_RESULT_NO_REFERENCE_IMAGE,
};
#endif // LV_USE_TEST && defined(LV_USE_TEST_SCREENSHOT_COMPARE) && LV_USE_TEST_SCREENSHOT_COMPARE

enum class DisplayRotation : int {
    _0 = LV_DISPLAY_ROTATION_0,
    _90 = LV_DISPLAY_ROTATION_90,
    _180 = LV_DISPLAY_ROTATION_180,
    _270 = LV_DISPLAY_ROTATION_270,
};

enum class DisplayRenderMode : int {
    /**
     * Use the buffer(s) to render the screen is smaller parts.
     * This way the buffers can be smaller then the display to save RAM. At least 1/10 screen size buffer(s) are recommended.
     */
    Partial = LV_DISPLAY_RENDER_MODE_PARTIAL,
    /**
     * The buffer(s) has to be screen sized and LVGL will render into the correct location of the buffer.
     * This way the buffer always contain the whole image. Only the changed ares will be updated.
     * With 2 buffers the buffers' content are kept in sync automatically and in flush_cb only address change is required.
     */
    Direct = LV_DISPLAY_RENDER_MODE_DIRECT,
    /**
     * Always redraw the whole screen even if only one pixel has been changed.
     * With 2 buffers in flush_cb only an address change is required.
     */
    Full = LV_DISPLAY_RENDER_MODE_FULL,
};

enum class ScreenLoadAnim : int {
    None = LV_SCREEN_LOAD_ANIM_NONE,
    OverLeft = LV_SCREEN_LOAD_ANIM_OVER_LEFT,
    OverRight = LV_SCREEN_LOAD_ANIM_OVER_RIGHT,
    OverTop = LV_SCREEN_LOAD_ANIM_OVER_TOP,
    OverBottom = LV_SCREEN_LOAD_ANIM_OVER_BOTTOM,
    MoveLeft = LV_SCREEN_LOAD_ANIM_MOVE_LEFT,
    MoveRight = LV_SCREEN_LOAD_ANIM_MOVE_RIGHT,
    MoveTop = LV_SCREEN_LOAD_ANIM_MOVE_TOP,
    MoveBottom = LV_SCREEN_LOAD_ANIM_MOVE_BOTTOM,
    FadeIn = LV_SCREEN_LOAD_ANIM_FADE_IN,
    FadeOn = LV_SCREEN_LOAD_ANIM_FADE_ON,
    FadeOut = LV_SCREEN_LOAD_ANIM_FADE_OUT,
    OutLeft = LV_SCREEN_LOAD_ANIM_OUT_LEFT,
    OutRight = LV_SCREEN_LOAD_ANIM_OUT_RIGHT,
    OutTop = LV_SCREEN_LOAD_ANIM_OUT_TOP,
    OutBottom = LV_SCREEN_LOAD_ANIM_OUT_BOTTOM,
};

#if LV_USE_DRAW_EVE
enum class DrawEveOperation : int {
    /** set the "PD_N" pin low */
    PowerdownSet = LV_DRAW_EVE_OPERATION_POWERDOWN_SET,
    /** set the "PD_N" pin high */
    PowerdownClear = LV_DRAW_EVE_OPERATION_POWERDOWN_CLEAR,
    /** set the "CS_N" pin low */
    CsAssert = LV_DRAW_EVE_OPERATION_CS_ASSERT,
    /** set the "CS_N" pin high */
    CsDeassert = LV_DRAW_EVE_OPERATION_CS_DEASSERT,
    /** send `length` bytes of `data` over SPI */
    SpiSend = LV_DRAW_EVE_OPERATION_SPI_SEND,
    /** receive `length` bytes into `data` from SPI */
    SpiReceive = LV_DRAW_EVE_OPERATION_SPI_RECEIVE,
};
#endif // LV_USE_DRAW_EVE

enum class DrawTaskType : int {
    None = LV_DRAW_TASK_TYPE_NONE,
    Fill = LV_DRAW_TASK_TYPE_FILL,
    Border = LV_DRAW_TASK_TYPE_BORDER,
    BoxShadow = LV_DRAW_TASK_TYPE_BOX_SHADOW,
    Letter = LV_DRAW_TASK_TYPE_LETTER,
    Label = LV_DRAW_TASK_TYPE_LABEL,
    Image = LV_DRAW_TASK_TYPE_IMAGE,
    Layer = LV_DRAW_TASK_TYPE_LAYER,
    Line = LV_DRAW_TASK_TYPE_LINE,
    Arc = LV_DRAW_TASK_TYPE_ARC,
    Triangle = LV_DRAW_TASK_TYPE_TRIANGLE,
    MaskRectangle = LV_DRAW_TASK_TYPE_MASK_RECTANGLE,
    MaskBitmap = LV_DRAW_TASK_TYPE_MASK_BITMAP,
    Blur = LV_DRAW_TASK_TYPE_BLUR,
    #if LV_USE_VECTOR_GRAPHIC
    Vector = LV_DRAW_TASK_TYPE_VECTOR,
    #endif // LV_USE_VECTOR_GRAPHIC

    #if LV_USE_3DTEXTURE
    _3d = LV_DRAW_TASK_TYPE_3D,
    #endif // LV_USE_3DTEXTURE

};

enum class DrawTaskState : int {
    /**
     * Waiting for an other task to be finished.
     * For example in case of `LV_DRAW_TASK_TYPE_LAYER` (used to blend a layer)
     * is blocked until all the draw tasks of the layer is rendered.
     */
    Blocked = LV_DRAW_TASK_STATE_BLOCKED,
    /** The draw task is added to the layers list and waits to be rendered. */
    Waiting = LV_DRAW_TASK_STATE_WAITING,
    /**
     * The draw task is added to the command queue of the draw unit.
     * As the queued task are executed in order it's possible to queue multiple draw task
     * (for the same draw unit) even if they are depending on each other.
     * Therefore `lv_draw_get_available_task` and `lv_draw_get_next_available_task` can return
     * draw task for the same draw unit even if a dependent draw task is not finished ready yet.
     */
    Queued = LV_DRAW_TASK_STATE_QUEUED,
    /**
     * The draw task is being rendered. This draw task needs to be finished before
     * `lv_draw_get_available_task` and `lv_draw_get_next_available_task` would
     * return any depending draw tasks.
     */
    InProgress = LV_DRAW_TASK_STATE_IN_PROGRESS,
    /**
     * The draw task is rendered. It will be removed from the draw task list of the layer
     * and freed automatically.
     */
    Finished = LV_DRAW_TASK_STATE_FINISHED,
};

#if LV_USE_VECTOR_GRAPHIC
enum class VectorFill : int {
    Nonzero = LV_VECTOR_FILL_NONZERO,
    Evenodd = LV_VECTOR_FILL_EVENODD,
};

enum class VectorStrokeCap : int {
    Butt = LV_VECTOR_STROKE_CAP_BUTT,
    Square = LV_VECTOR_STROKE_CAP_SQUARE,
    Round = LV_VECTOR_STROKE_CAP_ROUND,
};

enum class VectorStrokeJoin : int {
    Miter = LV_VECTOR_STROKE_JOIN_MITER,
    Bevel = LV_VECTOR_STROKE_JOIN_BEVEL,
    Round = LV_VECTOR_STROKE_JOIN_ROUND,
};

enum class VectorPathQuality : int {
    Medium = LV_VECTOR_PATH_QUALITY_MEDIUM,
    High = LV_VECTOR_PATH_QUALITY_HIGH,
    Low = LV_VECTOR_PATH_QUALITY_LOW,
};

enum class VectorBlend : int {
    SrcOver = LV_VECTOR_BLEND_SRC_OVER,
    SrcIn = LV_VECTOR_BLEND_SRC_IN,
    DstOver = LV_VECTOR_BLEND_DST_OVER,
    DstIn = LV_VECTOR_BLEND_DST_IN,
    Screen = LV_VECTOR_BLEND_SCREEN,
    Multiply = LV_VECTOR_BLEND_MULTIPLY,
    None = LV_VECTOR_BLEND_NONE,
    Additive = LV_VECTOR_BLEND_ADDITIVE,
    Subtractive = LV_VECTOR_BLEND_SUBTRACTIVE,
};

enum class VectorPathOp : int {
    MoveTo = LV_VECTOR_PATH_OP_MOVE_TO,
    LineTo = LV_VECTOR_PATH_OP_LINE_TO,
    QuadTo = LV_VECTOR_PATH_OP_QUAD_TO,
    CubicTo = LV_VECTOR_PATH_OP_CUBIC_TO,
    Close = LV_VECTOR_PATH_OP_CLOSE,
};

enum class VectorDrawStyle : int {
    Solid = LV_VECTOR_DRAW_STYLE_SOLID,
    Pattern = LV_VECTOR_DRAW_STYLE_PATTERN,
    Gradient = LV_VECTOR_DRAW_STYLE_GRADIENT,
};

enum class VectorGradientSpread : int {
    Pad = LV_VECTOR_GRADIENT_SPREAD_PAD,
    Repeat = LV_VECTOR_GRADIENT_SPREAD_REPEAT,
    Reflect = LV_VECTOR_GRADIENT_SPREAD_REFLECT,
};

enum class VectorGradientStyle : int {
    Linear = LV_VECTOR_GRADIENT_STYLE_LINEAR,
    Radial = LV_VECTOR_GRADIENT_STYLE_RADIAL,
};

enum class VectorFillUnits : int {
    ObjectBoundingBox = LV_VECTOR_FILL_UNITS_OBJECT_BOUNDING_BOX,
    /** Relative coordinates relative to the object bounding box. */
    UserSpaceOnUse = LV_VECTOR_FILL_UNITS_USER_SPACE_ON_USE,
};
#endif // LV_USE_VECTOR_GRAPHIC

/** Format of font character map. */
enum class FontFmtTxtCmapType : int {
    Format0Full = LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL,
    SparseFull = LV_FONT_FMT_TXT_CMAP_SPARSE_FULL,
    Format0Tiny = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY,
    SparseTiny = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY,
};

/** Bitmap formats */
enum class FontFmtTxtBitmapFormat : int {
    Plain = LV_FONT_FMT_TXT_PLAIN,
    Compressed = LV_FONT_FMT_TXT_COMPRESSED,
    CompressedNoPrefilter = LV_FONT_FMT_TXT_COMPRESSED_NO_PREFILTER,
};

/** The font format. */
enum class FontGlyphFormat : int {
    /** Maybe not visible */
    None = LV_FONT_GLYPH_FORMAT_NONE,
    /** 1 bit per pixel */
    A1 = LV_FONT_GLYPH_FORMAT_A1,
    /** 2 bit per pixel */
    A2 = LV_FONT_GLYPH_FORMAT_A2,
    /** 3 bit per pixel */
    A3 = LV_FONT_GLYPH_FORMAT_A3,
    /** 4 bit per pixel */
    A4 = LV_FONT_GLYPH_FORMAT_A4,
    /** 8 bit per pixel */
    A8 = LV_FONT_GLYPH_FORMAT_A8,
    /** Image format */
    Image = LV_FONT_GLYPH_FORMAT_IMAGE,
    /** Vectorial format */
    Vector = LV_FONT_GLYPH_FORMAT_VECTOR,
    /** SVG format */
    Svg = LV_FONT_GLYPH_FORMAT_SVG,
    /** Custom format */
    Custom = LV_FONT_GLYPH_FORMAT_CUSTOM,
};

/** The bitmaps might be upscaled by 3 to achieve subpixel rendering. */
enum class FontSubpx : int {
    None = LV_FONT_SUBPX_NONE,
    Hor = LV_FONT_SUBPX_HOR,
    Ver = LV_FONT_SUBPX_VER,
    Both = LV_FONT_SUBPX_BOTH,
};

/** Adjust letter spacing for specific character pairs. */
enum class FontKerning : int {
    Normal = LV_FONT_KERNING_NORMAL,
    None = LV_FONT_KERNING_NONE,
};

enum class StrSymbolId : int {
    Bullet = LV_STR_SYMBOL_BULLET,
    Audio = LV_STR_SYMBOL_AUDIO,
    Video = LV_STR_SYMBOL_VIDEO,
    List = LV_STR_SYMBOL_LIST,
    Ok = LV_STR_SYMBOL_OK,
    Close = LV_STR_SYMBOL_CLOSE,
    Power = LV_STR_SYMBOL_POWER,
    Settings = LV_STR_SYMBOL_SETTINGS,
    Home = LV_STR_SYMBOL_HOME,
    Download = LV_STR_SYMBOL_DOWNLOAD,
    Drive = LV_STR_SYMBOL_DRIVE,
    Refresh = LV_STR_SYMBOL_REFRESH,
    Mute = LV_STR_SYMBOL_MUTE,
    VolumeMid = LV_STR_SYMBOL_VOLUME_MID,
    VolumeMax = LV_STR_SYMBOL_VOLUME_MAX,
    Image = LV_STR_SYMBOL_IMAGE,
    Tint = LV_STR_SYMBOL_TINT,
    Prev = LV_STR_SYMBOL_PREV,
    Play = LV_STR_SYMBOL_PLAY,
    Pause = LV_STR_SYMBOL_PAUSE,
    Stop = LV_STR_SYMBOL_STOP,
    Next = LV_STR_SYMBOL_NEXT,
    Eject = LV_STR_SYMBOL_EJECT,
    Left = LV_STR_SYMBOL_LEFT,
    Right = LV_STR_SYMBOL_RIGHT,
    Plus = LV_STR_SYMBOL_PLUS,
    Minus = LV_STR_SYMBOL_MINUS,
    EyeOpen = LV_STR_SYMBOL_EYE_OPEN,
    EyeClose = LV_STR_SYMBOL_EYE_CLOSE,
    Warning = LV_STR_SYMBOL_WARNING,
    Shuffle = LV_STR_SYMBOL_SHUFFLE,
    Up = LV_STR_SYMBOL_UP,
    Down = LV_STR_SYMBOL_DOWN,
    Loop = LV_STR_SYMBOL_LOOP,
    Directory = LV_STR_SYMBOL_DIRECTORY,
    Upload = LV_STR_SYMBOL_UPLOAD,
    Call = LV_STR_SYMBOL_CALL,
    Cut = LV_STR_SYMBOL_CUT,
    Copy = LV_STR_SYMBOL_COPY,
    Save = LV_STR_SYMBOL_SAVE,
    Bars = LV_STR_SYMBOL_BARS,
    Envelope = LV_STR_SYMBOL_ENVELOPE,
    Charge = LV_STR_SYMBOL_CHARGE,
    Paste = LV_STR_SYMBOL_PASTE,
    Bell = LV_STR_SYMBOL_BELL,
    Keyboard = LV_STR_SYMBOL_KEYBOARD,
    Gps = LV_STR_SYMBOL_GPS,
    File = LV_STR_SYMBOL_FILE,
    Wifi = LV_STR_SYMBOL_WIFI,
    BatteryFull = LV_STR_SYMBOL_BATTERY_FULL,
    Battery3 = LV_STR_SYMBOL_BATTERY_3,
    Battery2 = LV_STR_SYMBOL_BATTERY_2,
    Battery1 = LV_STR_SYMBOL_BATTERY_1,
    BatteryEmpty = LV_STR_SYMBOL_BATTERY_EMPTY,
    Usb = LV_STR_SYMBOL_USB,
    Bluetooth = LV_STR_SYMBOL_BLUETOOTH,
    Trash = LV_STR_SYMBOL_TRASH,
    Edit = LV_STR_SYMBOL_EDIT,
    Backspace = LV_STR_SYMBOL_BACKSPACE,
    SdCard = LV_STR_SYMBOL_SD_CARD,
    NewLine = LV_STR_SYMBOL_NEW_LINE,
    Dummy = LV_STR_SYMBOL_DUMMY,
};

#if LV_USE_GRIDNAV
enum class GridnavCtrl : int {
    None = LV_GRIDNAV_CTRL_NONE,
    /**
     * If there is no next/previous object in a direction,
     * the focus goes to the object in the next/previous row (on left/right keys)
     * or first/last row (on up/down keys)
     */
    Rollover = LV_GRIDNAV_CTRL_ROLLOVER,
    /**
     * If an arrow is pressed and the focused object can be scrolled in that direction
     * then it will be scrolled instead of going to the next/previous object.
     * If there is no more room for scrolling the next/previous object will be focused normally
     */
    ScrollFirst = LV_GRIDNAV_CTRL_SCROLL_FIRST,
    /**
     * Only use left/right keys for grid navigation. Up/down key events will be sent to the
     * focused object.
     */
    HorizontalMoveOnly = LV_GRIDNAV_CTRL_HORIZONTAL_MOVE_ONLY,
    /**
     * Only use up/down keys for grid navigation. Left/right key events will be sent to the
     * focused object.
     */
    VerticalMoveOnly = LV_GRIDNAV_CTRL_VERTICAL_MOVE_ONLY,
};
constexpr GridnavCtrl operator|(GridnavCtrl a, GridnavCtrl b) noexcept {
    return static_cast<GridnavCtrl>(static_cast<int>(a) | static_cast<int>(b));
}
constexpr GridnavCtrl operator&(GridnavCtrl a, GridnavCtrl b) noexcept {
    return static_cast<GridnavCtrl>(static_cast<int>(a) & static_cast<int>(b));
}
constexpr GridnavCtrl operator^(GridnavCtrl a, GridnavCtrl b) noexcept {
    return static_cast<GridnavCtrl>(static_cast<int>(a) ^ static_cast<int>(b));
}
constexpr GridnavCtrl& operator|=(GridnavCtrl& a, GridnavCtrl b) noexcept { a = a | b; return a; }
#endif // LV_USE_GRIDNAV

/** Possible input device types */
enum class IndevType : int {
    /** Uninitialized state */
    None = LV_INDEV_TYPE_NONE,
    /** Touch pad, mouse, external button */
    Pointer = LV_INDEV_TYPE_POINTER,
    /** Keypad or keyboard */
    Keypad = LV_INDEV_TYPE_KEYPAD,
    /** External (hardware button) which is assigned to a specific point of the screen */
    Button = LV_INDEV_TYPE_BUTTON,
    /** Encoder with only Left, Right turn and a Button */
    Encoder = LV_INDEV_TYPE_ENCODER,
};

/** States for input devices */
enum class IndevState : int {
    Released = LV_INDEV_STATE_RELEASED,
    Pressed = LV_INDEV_STATE_PRESSED,
    #if LVPP_COMPAT_V8
    /** v8 spelling of `Pressed`. */
    Pr = LV_INDEV_STATE_PRESSED,
    /** v8 spelling of `Released`. */
    Rel = LV_INDEV_STATE_RELEASED,
    #endif // LVPP_COMPAT_V8

};

enum class IndevMode : int {
    None = LV_INDEV_MODE_NONE,
    Timer = LV_INDEV_MODE_TIMER,
    Event = LV_INDEV_MODE_EVENT,
};

enum class IndevGestureType : int {
    None = LV_INDEV_GESTURE_NONE,
    Pinch = LV_INDEV_GESTURE_PINCH,
    Swipe = LV_INDEV_GESTURE_SWIPE,
    Rotate = LV_INDEV_GESTURE_ROTATE,
    TwoFingersSwipe = LV_INDEV_GESTURE_TWO_FINGERS_SWIPE,
    Scroll = LV_INDEV_GESTURE_SCROLL,
    Cnt = LV_INDEV_GESTURE_CNT,
};

#if LV_USE_GESTURE_RECOGNITION
enum class IndevGestureState : int {
    None = LV_INDEV_GESTURE_STATE_NONE,
    Ongoing = LV_INDEV_GESTURE_STATE_ONGOING,
    Recognized = LV_INDEV_GESTURE_STATE_RECOGNIZED,
    Ended = LV_INDEV_GESTURE_STATE_ENDED,
    Canceled = LV_INDEV_GESTURE_STATE_CANCELED,
};
#endif // LV_USE_GESTURE_RECOGNITION

#if LV_USE_FLEX
enum class FlexAlign : int {
    Start = LV_FLEX_ALIGN_START,
    End = LV_FLEX_ALIGN_END,
    Center = LV_FLEX_ALIGN_CENTER,
    SpaceEvenly = LV_FLEX_ALIGN_SPACE_EVENLY,
    SpaceAround = LV_FLEX_ALIGN_SPACE_AROUND,
    SpaceBetween = LV_FLEX_ALIGN_SPACE_BETWEEN,
};

enum class FlexFlow : int {
    Row = LV_FLEX_FLOW_ROW,
    Column = LV_FLEX_FLOW_COLUMN,
    RowWrap = LV_FLEX_FLOW_ROW_WRAP,
    RowReverse = LV_FLEX_FLOW_ROW_REVERSE,
    RowWrapReverse = LV_FLEX_FLOW_ROW_WRAP_REVERSE,
    ColumnWrap = LV_FLEX_FLOW_COLUMN_WRAP,
    ColumnReverse = LV_FLEX_FLOW_COLUMN_REVERSE,
    ColumnWrapReverse = LV_FLEX_FLOW_COLUMN_WRAP_REVERSE,
};
#endif // LV_USE_FLEX

#if LV_USE_GRID
enum class GridAlign : int {
    Start = LV_GRID_ALIGN_START,
    Center = LV_GRID_ALIGN_CENTER,
    End = LV_GRID_ALIGN_END,
    Stretch = LV_GRID_ALIGN_STRETCH,
    SpaceEvenly = LV_GRID_ALIGN_SPACE_EVENLY,
    SpaceAround = LV_GRID_ALIGN_SPACE_AROUND,
    SpaceBetween = LV_GRID_ALIGN_SPACE_BETWEEN,
};
#endif // LV_USE_GRID

enum class Layout : int {
    None = LV_LAYOUT_NONE,
    #if LV_USE_FLEX
    Flex = LV_LAYOUT_FLEX,
    #endif // LV_USE_FLEX

    #if LV_USE_GRID
    Grid = LV_LAYOUT_GRID,
    #endif // LV_USE_GRID

};

#if LV_USE_BARCODE
enum class BarcodeEncoding : int {
    /** Code 128 with GS1 encoding. Strips `[FCN1]` and spaces. */
    Gs1 = LV_BARCODE_ENCODING_CODE128_GS1,
    /** Code 128 with raw encoding. */
    Raw = LV_BARCODE_ENCODING_CODE128_RAW,
};
#endif // LV_USE_BARCODE

#if LV_USE_FFMPEG != 0
enum class FfmpegPlayerCmd : int {
    Start = LV_FFMPEG_PLAYER_CMD_START,
    Stop = LV_FFMPEG_PLAYER_CMD_STOP,
    Pause = LV_FFMPEG_PLAYER_CMD_PAUSE,
    Resume = LV_FFMPEG_PLAYER_CMD_RESUME,
};
#endif // LV_USE_FFMPEG != 0

#if LV_USE_FREETYPE
enum class FreetypeFontStyle : int {
    Normal = LV_FREETYPE_FONT_STYLE_NORMAL,
    Italic = LV_FREETYPE_FONT_STYLE_ITALIC,
    Bold = LV_FREETYPE_FONT_STYLE_BOLD,
};

enum class FreetypeFontRenderMode : int {
    Bitmap = LV_FREETYPE_FONT_RENDER_MODE_BITMAP,
    Outline = LV_FREETYPE_FONT_RENDER_MODE_OUTLINE,
};

enum class FreetypeOutlineType : int {
    End = LV_FREETYPE_OUTLINE_END,
    MoveTo = LV_FREETYPE_OUTLINE_MOVE_TO,
    LineTo = LV_FREETYPE_OUTLINE_LINE_TO,
    CubicTo = LV_FREETYPE_OUTLINE_CUBIC_TO,
    ConicTo = LV_FREETYPE_OUTLINE_CONIC_TO,
    BorderStart = LV_FREETYPE_OUTLINE_BORDER_START,
};
#endif // LV_USE_FREETYPE

#if LV_USE_GLTF
enum class GltfAaMode : int {
    Off = LV_GLTF_AA_MODE_OFF,
    /** Anti aliasing off */
    On = LV_GLTF_AA_MODE_ON,
    /** Anti aliasing on */
    Dynamic = LV_GLTF_AA_MODE_DYNAMIC,
};

enum class GltfBgMode : int {
    Solid = LV_GLTF_BG_MODE_SOLID,
    /** Solid background. Use `lv_obj_set_style_bg_color` to set the background color */
    Environment = LV_GLTF_BG_MODE_ENVIRONMENT,
};
#endif // LV_USE_GLTF

#if LV_USE_GSTREAMER
enum class GstreamerState : int {
    Null = LV_GSTREAMER_STATE_NULL,
    Ready = LV_GSTREAMER_STATE_READY,
    Paused = LV_GSTREAMER_STATE_PAUSED,
    Playing = LV_GSTREAMER_STATE_PLAYING,
};

enum class GstreamerStreamState : int {
    Start = LV_GSTREAMER_STREAM_STATE_START,
    Play = LV_GSTREAMER_STREAM_STATE_PLAY,
    Pause = LV_GSTREAMER_STREAM_STATE_PAUSE,
    Stop = LV_GSTREAMER_STREAM_STATE_STOP,
    End = LV_GSTREAMER_STREAM_STATE_END,
};
#endif // LV_USE_GSTREAMER

#if LV_USE_RLOTTIE
enum class RlottieCtrl : int {
    Forward = LV_RLOTTIE_CTRL_FORWARD,
    Backward = LV_RLOTTIE_CTRL_BACKWARD,
    Pause = LV_RLOTTIE_CTRL_PAUSE,
    Play = LV_RLOTTIE_CTRL_PLAY,
    Loop = LV_RLOTTIE_CTRL_LOOP,
};
#endif // LV_USE_RLOTTIE

#if LV_USE_SVG
enum class SvgTag : int8_t {
    Invalid = LV_SVG_TAG_INVALID,
    Content = LV_SVG_TAG_CONTENT,
    Svg = LV_SVG_TAG_SVG,
    Use = LV_SVG_TAG_USE,
    G = LV_SVG_TAG_G,
    Path = LV_SVG_TAG_PATH,
    Rect = LV_SVG_TAG_RECT,
    Circle = LV_SVG_TAG_CIRCLE,
    Ellipse = LV_SVG_TAG_ELLIPSE,
    Line = LV_SVG_TAG_LINE,
    Polyline = LV_SVG_TAG_POLYLINE,
    Polygon = LV_SVG_TAG_POLYGON,
    SolidColor = LV_SVG_TAG_SOLID_COLOR,
    LinearGradient = LV_SVG_TAG_LINEAR_GRADIENT,
    RadialGradient = LV_SVG_TAG_RADIAL_GRADIENT,
    Stop = LV_SVG_TAG_STOP,
    Defs = LV_SVG_TAG_DEFS,
    Image = LV_SVG_TAG_IMAGE,
    #if LV_USE_SVG_ANIMATION
    Mpath = LV_SVG_TAG_MPATH,
    Set = LV_SVG_TAG_SET,
    Animate = LV_SVG_TAG_ANIMATE,
    AnimateColor = LV_SVG_TAG_ANIMATE_COLOR,
    AnimateTransform = LV_SVG_TAG_ANIMATE_TRANSFORM,
    AnimateMotion = LV_SVG_TAG_ANIMATE_MOTION,
    #endif // LV_USE_SVG_ANIMATION

    Text = LV_SVG_TAG_TEXT,
    Tspan = LV_SVG_TAG_TSPAN,
    TextArea = LV_SVG_TAG_TEXT_AREA,
};

enum class SvgAttrType : uint8_t {
    Invalid = LV_SVG_ATTR_INVALID,
    Id = LV_SVG_ATTR_ID,
    XmlId = LV_SVG_ATTR_XML_ID,
    Version = LV_SVG_ATTR_VERSION,
    BaseProfile = LV_SVG_ATTR_BASE_PROFILE,
    Viewbox = LV_SVG_ATTR_VIEWBOX,
    PreserveAspectRatio = LV_SVG_ATTR_PRESERVE_ASPECT_RATIO,
    ViewportFill = LV_SVG_ATTR_VIEWPORT_FILL,
    ViewportFillOpacity = LV_SVG_ATTR_VIEWPORT_FILL_OPACITY,
    Display = LV_SVG_ATTR_DISPLAY,
    Visibility = LV_SVG_ATTR_VISIBILITY,
    X = LV_SVG_ATTR_X,
    Y = LV_SVG_ATTR_Y,
    Width = LV_SVG_ATTR_WIDTH,
    Height = LV_SVG_ATTR_HEIGHT,
    Rx = LV_SVG_ATTR_RX,
    Ry = LV_SVG_ATTR_RY,
    Cx = LV_SVG_ATTR_CX,
    Cy = LV_SVG_ATTR_CY,
    R = LV_SVG_ATTR_R,
    X1 = LV_SVG_ATTR_X1,
    Y1 = LV_SVG_ATTR_Y1,
    X2 = LV_SVG_ATTR_X2,
    Y2 = LV_SVG_ATTR_Y2,
    Points = LV_SVG_ATTR_POINTS,
    D = LV_SVG_ATTR_D,
    PathLength = LV_SVG_ATTR_PATH_LENGTH,
    XlinkHref = LV_SVG_ATTR_XLINK_HREF,
    Style = LV_SVG_ATTR_STYLE,
    Fill = LV_SVG_ATTR_FILL,
    FillRule = LV_SVG_ATTR_FILL_RULE,
    FillOpacity = LV_SVG_ATTR_FILL_OPACITY,
    Stroke = LV_SVG_ATTR_STROKE,
    StrokeWidth = LV_SVG_ATTR_STROKE_WIDTH,
    StrokeLinecap = LV_SVG_ATTR_STROKE_LINECAP,
    StrokeLinejoin = LV_SVG_ATTR_STROKE_LINEJOIN,
    StrokeMiterLimit = LV_SVG_ATTR_STROKE_MITER_LIMIT,
    StrokeDashArray = LV_SVG_ATTR_STROKE_DASH_ARRAY,
    StrokeDashOffset = LV_SVG_ATTR_STROKE_DASH_OFFSET,
    StrokeOpacity = LV_SVG_ATTR_STROKE_OPACITY,
    Opacity = LV_SVG_ATTR_OPACITY,
    SolidColor = LV_SVG_ATTR_SOLID_COLOR,
    SolidOpacity = LV_SVG_ATTR_SOLID_OPACITY,
    GradientUnits = LV_SVG_ATTR_GRADIENT_UNITS,
    GradientStopOffset = LV_SVG_ATTR_GRADIENT_STOP_OFFSET,
    GradientStopColor = LV_SVG_ATTR_GRADIENT_STOP_COLOR,
    GradientStopOpacity = LV_SVG_ATTR_GRADIENT_STOP_OPACITY,
    FontFamily = LV_SVG_ATTR_FONT_FAMILY,
    FontStyle = LV_SVG_ATTR_FONT_STYLE,
    FontVariant = LV_SVG_ATTR_FONT_VARIANT,
    FontWeight = LV_SVG_ATTR_FONT_WEIGHT,
    FontSize = LV_SVG_ATTR_FONT_SIZE,
    Transform = LV_SVG_ATTR_TRANSFORM,
    TextAnchor = LV_SVG_ATTR_TEXT_ANCHOR,
    #if LV_USE_SVG_ANIMATION
    AttributeName = LV_SVG_ATTR_ATTRIBUTE_NAME,
    AttributeType = LV_SVG_ATTR_ATTRIBUTE_TYPE,
    Begin = LV_SVG_ATTR_BEGIN,
    End = LV_SVG_ATTR_END,
    Dur = LV_SVG_ATTR_DUR,
    Min = LV_SVG_ATTR_MIN,
    Max = LV_SVG_ATTR_MAX,
    Restart = LV_SVG_ATTR_RESTART,
    RepeatCount = LV_SVG_ATTR_REPEAT_COUNT,
    RepeatDur = LV_SVG_ATTR_REPEAT_DUR,
    CalcMode = LV_SVG_ATTR_CALC_MODE,
    Values = LV_SVG_ATTR_VALUES,
    KeyTimes = LV_SVG_ATTR_KEY_TIMES,
    KeySplines = LV_SVG_ATTR_KEY_SPLINES,
    KeyPoints = LV_SVG_ATTR_KEY_POINTS,
    From = LV_SVG_ATTR_FROM,
    To = LV_SVG_ATTR_TO,
    By = LV_SVG_ATTR_BY,
    Additive = LV_SVG_ATTR_ADDITIVE,
    Accumulate = LV_SVG_ATTR_ACCUMULATE,
    Path = LV_SVG_ATTR_PATH,
    Rotate = LV_SVG_ATTR_ROTATE,
    TransformType = LV_SVG_ATTR_TRANSFORM_TYPE,
    #endif // LV_USE_SVG_ANIMATION

};

enum class SvgTransformType : uint8_t {
    Matrix = LV_SVG_TRANSFORM_TYPE_MATRIX,
    Translate = LV_SVG_TRANSFORM_TYPE_TRANSLATE,
    Rotate = LV_SVG_TRANSFORM_TYPE_ROTATE,
    Scale = LV_SVG_TRANSFORM_TYPE_SCALE,
    SkewX = LV_SVG_TRANSFORM_TYPE_SKEW_X,
    SkewY = LV_SVG_TRANSFORM_TYPE_SKEW_Y,
};
#endif // LV_USE_SVG

#if (LV_USE_SVG) && (LV_USE_SVG_ANIMATION)
enum class SvgAnimAction : int {
    Remove = LV_SVG_ANIM_REMOVE,
    Freeze = LV_SVG_ANIM_FREEZE,
};

enum class SvgAnimRestartType : int {
    Always = LV_SVG_ANIM_RESTART_ALWAYS,
    WhenNotActive = LV_SVG_ANIM_RESTART_WHEN_NOT_ACTIVE,
    Never = LV_SVG_ANIM_RESTART_NEVER,
};

enum class SvgAnimCalcMode : int {
    Linear = LV_SVG_ANIM_CALC_MODE_LINEAR,
    Paced = LV_SVG_ANIM_CALC_MODE_PACED,
    Spline = LV_SVG_ANIM_CALC_MODE_SPLINE,
    Discrete = LV_SVG_ANIM_CALC_MODE_DISCRETE,
};

enum class SvgAnimAdditiveType : int {
    Replace = LV_SVG_ANIM_ADDITIVE_REPLACE,
    Sum = LV_SVG_ANIM_ADDITIVE_SUM,
};

enum class SvgAnimAccumulateType : int {
    None = LV_SVG_ANIM_ACCUMULATE_NONE,
    Sum = LV_SVG_ANIM_ACCUMULATE_SUM,
};
#endif // (LV_USE_SVG) && (LV_USE_SVG_ANIMATION)

#if LV_USE_SVG
enum class SvgAspectRatio : uint32_t {
    None = LV_SVG_ASPECT_RATIO_NONE,
    XminYmin = LV_SVG_ASPECT_RATIO_XMIN_YMIN,
    XmidYmin = LV_SVG_ASPECT_RATIO_XMID_YMIN,
    XmaxYmin = LV_SVG_ASPECT_RATIO_XMAX_YMIN,
    XminYmid = LV_SVG_ASPECT_RATIO_XMIN_YMID,
    XmidYmid = LV_SVG_ASPECT_RATIO_XMID_YMID,
    XmaxYmid = LV_SVG_ASPECT_RATIO_XMAX_YMID,
    XminYmax = LV_SVG_ASPECT_RATIO_XMIN_YMAX,
    XmidYmax = LV_SVG_ASPECT_RATIO_XMID_YMAX,
    XmaxYmax = LV_SVG_ASPECT_RATIO_XMAX_YMAX,
};

enum class SvgAspectRatioOpt : int {
    Meet = LV_SVG_ASPECT_RATIO_OPT_MEET,
    Slice = LV_SVG_ASPECT_RATIO_OPT_SLICE,
};

enum class SvgFillRule : uint8_t {
    Nonzero = LV_SVG_FILL_NONZERO,
    Evenodd = LV_SVG_FILL_EVENODD,
};

enum class SvgLineCap : uint8_t {
    Butt = LV_SVG_LINE_CAP_BUTT,
    Square = LV_SVG_LINE_CAP_SQUARE,
    Round = LV_SVG_LINE_CAP_ROUND,
};

enum class SvgLineJoin : uint8_t {
    Miter = LV_SVG_LINE_JOIN_MITER,
    Bevel = LV_SVG_LINE_JOIN_BEVEL,
    Round = LV_SVG_LINE_JOIN_ROUND,
};

enum class SvgGradientUnits : uint8_t {
    Object = LV_SVG_GRADIENT_UNITS_OBJECT,
    UserSpace = LV_SVG_GRADIENT_UNITS_USER_SPACE,
};

enum class SvgPathCmd : int {
    MoveTo = LV_SVG_PATH_CMD_MOVE_TO,
    LineTo = LV_SVG_PATH_CMD_LINE_TO,
    CurveTo = LV_SVG_PATH_CMD_CURVE_TO,
    QuadTo = LV_SVG_PATH_CMD_QUAD_TO,
    ArcTo = LV_SVG_PATH_CMD_ARC_TO,
    Close = LV_SVG_PATH_CMD_CLOSE,
};

enum class SvgAttrValueType : uint8_t {
    Data = LV_SVG_ATTR_VALUE_DATA,
    Ptr = LV_SVG_ATTR_VALUE_PTR,
};

enum class SvgAttrValueClass : uint8_t {
    None = LV_SVG_ATTR_VALUE_NONE,
    Initial = LV_SVG_ATTR_VALUE_INITIAL,
    Inherit = LV_SVG_ATTR_VALUE_INHERIT,
};
#endif // LV_USE_SVG

/** Alignments */
enum class Align : int {
    Default = LV_ALIGN_DEFAULT,
    TopLeft = LV_ALIGN_TOP_LEFT,
    TopMid = LV_ALIGN_TOP_MID,
    TopRight = LV_ALIGN_TOP_RIGHT,
    BottomLeft = LV_ALIGN_BOTTOM_LEFT,
    BottomMid = LV_ALIGN_BOTTOM_MID,
    BottomRight = LV_ALIGN_BOTTOM_RIGHT,
    LeftMid = LV_ALIGN_LEFT_MID,
    RightMid = LV_ALIGN_RIGHT_MID,
    Center = LV_ALIGN_CENTER,
    OutTopLeft = LV_ALIGN_OUT_TOP_LEFT,
    OutTopMid = LV_ALIGN_OUT_TOP_MID,
    OutTopRight = LV_ALIGN_OUT_TOP_RIGHT,
    OutBottomLeft = LV_ALIGN_OUT_BOTTOM_LEFT,
    OutBottomMid = LV_ALIGN_OUT_BOTTOM_MID,
    OutBottomRight = LV_ALIGN_OUT_BOTTOM_RIGHT,
    OutLeftTop = LV_ALIGN_OUT_LEFT_TOP,
    OutLeftMid = LV_ALIGN_OUT_LEFT_MID,
    OutLeftBottom = LV_ALIGN_OUT_LEFT_BOTTOM,
    OutRightTop = LV_ALIGN_OUT_RIGHT_TOP,
    OutRightMid = LV_ALIGN_OUT_RIGHT_MID,
    OutRightBottom = LV_ALIGN_OUT_RIGHT_BOTTOM,
};

enum class Dir : int {
    None = LV_DIR_NONE,
    Left = LV_DIR_LEFT,
    Right = LV_DIR_RIGHT,
    Top = LV_DIR_TOP,
    Bottom = LV_DIR_BOTTOM,
    Hor = LV_DIR_HOR,
    Ver = LV_DIR_VER,
    All = LV_DIR_ALL,
};
constexpr Dir operator|(Dir a, Dir b) noexcept {
    return static_cast<Dir>(static_cast<int>(a) | static_cast<int>(b));
}
constexpr Dir operator&(Dir a, Dir b) noexcept {
    return static_cast<Dir>(static_cast<int>(a) & static_cast<int>(b));
}
constexpr Dir operator^(Dir a, Dir b) noexcept {
    return static_cast<Dir>(static_cast<int>(a) ^ static_cast<int>(b));
}
constexpr Dir& operator|=(Dir& a, Dir b) noexcept { a = a | b; return a; }

enum class BaseDir : int {
    Ltr = LV_BASE_DIR_LTR,
    Rtl = LV_BASE_DIR_RTL,
    Auto = LV_BASE_DIR_AUTO,
    Neutral = LV_BASE_DIR_NEUTRAL,
    Weak = LV_BASE_DIR_WEAK,
};

/** Opacity percentages. */
enum class OpacityLevel : int {
    Transp = LV_OPA_TRANSP,
    _0 = LV_OPA_0,
    _10 = LV_OPA_10,
    _20 = LV_OPA_20,
    _30 = LV_OPA_30,
    _40 = LV_OPA_40,
    _50 = LV_OPA_50,
    _60 = LV_OPA_60,
    _70 = LV_OPA_70,
    _80 = LV_OPA_80,
    _90 = LV_OPA_90,
    _100 = LV_OPA_100,
    Cover = LV_OPA_COVER,
};

enum class ColorFormat : int {
    Unknown = LV_COLOR_FORMAT_UNKNOWN,
    Raw = LV_COLOR_FORMAT_RAW,
    RawAlpha = LV_COLOR_FORMAT_RAW_ALPHA,
    L8 = LV_COLOR_FORMAT_L8,
    I1 = LV_COLOR_FORMAT_I1,
    I2 = LV_COLOR_FORMAT_I2,
    I4 = LV_COLOR_FORMAT_I4,
    I8 = LV_COLOR_FORMAT_I8,
    A8 = LV_COLOR_FORMAT_A8,
    Rgb565 = LV_COLOR_FORMAT_RGB565,
    /** Not supported by sw renderer yet. */
    Argb8565 = LV_COLOR_FORMAT_ARGB8565,
    /** Color array followed by Alpha array */
    Rgb565a8 = LV_COLOR_FORMAT_RGB565A8,
    /** L8 with alpha > */
    Al88 = LV_COLOR_FORMAT_AL88,
    Rgb565Swapped = LV_COLOR_FORMAT_RGB565_SWAPPED,
    Rgb888 = LV_COLOR_FORMAT_RGB888,
    Argb8888 = LV_COLOR_FORMAT_ARGB8888,
    Xrgb8888 = LV_COLOR_FORMAT_XRGB8888,
    Argb8888Premultiplied = LV_COLOR_FORMAT_ARGB8888_PREMULTIPLIED,
    A1 = LV_COLOR_FORMAT_A1,
    A2 = LV_COLOR_FORMAT_A2,
    A4 = LV_COLOR_FORMAT_A4,
    Argb1555 = LV_COLOR_FORMAT_ARGB1555,
    Argb4444 = LV_COLOR_FORMAT_ARGB4444,
    Argb2222 = LV_COLOR_FORMAT_ARGB2222,
    YuvStart = LV_COLOR_FORMAT_YUV_START,
    I420 = LV_COLOR_FORMAT_I420,
    I422 = LV_COLOR_FORMAT_I422,
    I444 = LV_COLOR_FORMAT_I444,
    I400 = LV_COLOR_FORMAT_I400,
    Nv21 = LV_COLOR_FORMAT_NV21,
    Nv12 = LV_COLOR_FORMAT_NV12,
    Yuy2 = LV_COLOR_FORMAT_YUY2,
    Uyvy = LV_COLOR_FORMAT_UYVY,
    YuvEnd = LV_COLOR_FORMAT_YUV_END,
    ProprietaryStart = LV_COLOR_FORMAT_PROPRIETARY_START,
    NemaTscStart = LV_COLOR_FORMAT_NEMA_TSC_START,
    NemaTsc4 = LV_COLOR_FORMAT_NEMA_TSC4,
    NemaTsc6 = LV_COLOR_FORMAT_NEMA_TSC6,
    NemaTsc6a = LV_COLOR_FORMAT_NEMA_TSC6A,
    NemaTsc6ap = LV_COLOR_FORMAT_NEMA_TSC6AP,
    NemaTsc12 = LV_COLOR_FORMAT_NEMA_TSC12,
    NemaTsc12a = LV_COLOR_FORMAT_NEMA_TSC12A,
    NemaTscEnd = LV_COLOR_FORMAT_NEMA_TSC_END,
    #if (!(LV_COLOR_DEPTH == 1)) && (!(LV_COLOR_DEPTH == 8)) && (LV_COLOR_DEPTH == 16)
    Native = LV_COLOR_FORMAT_NATIVE,
    NativeWithAlpha = LV_COLOR_FORMAT_NATIVE_WITH_ALPHA,
    #endif // (!(LV_COLOR_DEPTH == 1)) && (!(LV_COLOR_DEPTH == 8)) && (LV_COLOR_DEPTH == 16)

};

/** Type of event being sent to Widget */
enum class EventCode : int {
    All = LV_EVENT_ALL,
    /** Input device events */
    Pressed = LV_EVENT_PRESSED,
    /** Widget is being pressed (sent continuously while pressing) */
    Pressing = LV_EVENT_PRESSING,
    /** Widget is still being pressed but slid cursor/finger off Widget */
    PressLost = LV_EVENT_PRESS_LOST,
    /** Widget was pressed for a short period of time, then released. Not sent if scrolled. */
    ShortClicked = LV_EVENT_SHORT_CLICKED,
    /** Sent for first short click within a small distance and short time */
    SingleClicked = LV_EVENT_SINGLE_CLICKED,
    /** Sent for second short click within small distance and short time */
    DoubleClicked = LV_EVENT_DOUBLE_CLICKED,
    /** Sent for third short click within small distance and short time */
    TripleClicked = LV_EVENT_TRIPLE_CLICKED,
    /** Object has been pressed for at least `long_press_time`. Not sent if scrolled. */
    LongPressed = LV_EVENT_LONG_PRESSED,
    /** Sent after `long_press_time` in every `long_press_repeat_time` ms. Not sent if scrolled. */
    LongPressedRepeat = LV_EVENT_LONG_PRESSED_REPEAT,
    /** Sent on release if not scrolled (regardless to long press) */
    Clicked = LV_EVENT_CLICKED,
    /** Sent in every cases when Widget has been released */
    Released = LV_EVENT_RELEASED,
    /** Scrolling begins. The event parameter is a pointer to the animation of the scroll. Can be modified */
    ScrollBegin = LV_EVENT_SCROLL_BEGIN,
    ScrollThrowBegin = LV_EVENT_SCROLL_THROW_BEGIN,
    /** Scrolling ends */
    ScrollEnd = LV_EVENT_SCROLL_END,
    /** Scrolling */
    Scroll = LV_EVENT_SCROLL,
    /** A gesture is detected. Get gesture with `lv_indev_get_gesture_dir(lv_indev_active());` */
    Gesture = LV_EVENT_GESTURE,
    /** A key is sent to Widget. Get key with `lv_indev_get_key(lv_indev_active());` */
    Key = LV_EVENT_KEY,
    /** An encoder or wheel was rotated. Get rotation count with `lv_event_get_rotary_diff(e);` */
    Rotary = LV_EVENT_ROTARY,
    /** Widget received focus */
    Focused = LV_EVENT_FOCUSED,
    /** Widget's focus has been lost */
    Defocused = LV_EVENT_DEFOCUSED,
    /** Widget's focus has been lost but is still selected */
    Leave = LV_EVENT_LEAVE,
    /** Perform advanced hit-testing */
    HitTest = LV_EVENT_HIT_TEST,
    /** Indev has been reset */
    IndevReset = LV_EVENT_INDEV_RESET,
    /** Indev hover over object */
    HoverOver = LV_EVENT_HOVER_OVER,
    /** Indev hover leave object */
    HoverLeave = LV_EVENT_HOVER_LEAVE,
    /** Drawing events */
    CoverCheck = LV_EVENT_COVER_CHECK,
    /** Get required extra draw area around Widget (e.g. for shadow). The event parameter is `int32_t *` to store the size. */
    RefrExtDrawSize = LV_EVENT_REFR_EXT_DRAW_SIZE,
    /** Starting the main drawing phase */
    DrawMainBegin = LV_EVENT_DRAW_MAIN_BEGIN,
    /** Perform the main drawing */
    DrawMain = LV_EVENT_DRAW_MAIN,
    /** Finishing the main drawing phase */
    DrawMainEnd = LV_EVENT_DRAW_MAIN_END,
    /** Starting the post draw phase (when all children are drawn) */
    DrawPostBegin = LV_EVENT_DRAW_POST_BEGIN,
    /** Perform the post draw phase (when all children are drawn) */
    DrawPost = LV_EVENT_DRAW_POST,
    /** Finishing the post draw phase (when all children are drawn) */
    DrawPostEnd = LV_EVENT_DRAW_POST_END,
    /** Adding a draw task. The `LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS` flag needs to be set */
    DrawTaskAdded = LV_EVENT_DRAW_TASK_ADDED,
    /** Special events */
    ValueChanged = LV_EVENT_VALUE_CHANGED,
    /** Text has been inserted into Widget. The event data is `char *` being inserted. */
    Insert = LV_EVENT_INSERT,
    /** Notify Widget to refresh something on it (for user) */
    Refresh = LV_EVENT_REFRESH,
    /** A process has finished */
    Ready = LV_EVENT_READY,
    /** A process has been cancelled */
    Cancel = LV_EVENT_CANCEL,
    /** The state of the widget changed */
    StateChanged = LV_EVENT_STATE_CHANGED,
    /** Other events */
    Create = LV_EVENT_CREATE,
    /** Object is being deleted */
    Delete = LV_EVENT_DELETE,
    /** Child was removed, added, or its size, position were changed */
    ChildChanged = LV_EVENT_CHILD_CHANGED,
    /** Child was created, always bubbles up to all parents */
    ChildCreated = LV_EVENT_CHILD_CREATED,
    /** Child was deleted, always bubbles up to all parents */
    ChildDeleted = LV_EVENT_CHILD_DELETED,
    /** A screen unload started, fired immediately when scr_load is called */
    ScreenUnloadStart = LV_EVENT_SCREEN_UNLOAD_START,
    /** A screen load started, fired when the screen change delay is expired */
    ScreenLoadStart = LV_EVENT_SCREEN_LOAD_START,
    /** A screen was loaded */
    ScreenLoaded = LV_EVENT_SCREEN_LOADED,
    /** A screen was unloaded */
    ScreenUnloaded = LV_EVENT_SCREEN_UNLOADED,
    /** Object coordinates/size have changed */
    SizeChanged = LV_EVENT_SIZE_CHANGED,
    /** Object's style has changed */
    StyleChanged = LV_EVENT_STYLE_CHANGED,
    /** A child's position position has changed due to a layout recalculation */
    LayoutChanged = LV_EVENT_LAYOUT_CHANGED,
    /** Get internal size of a widget */
    GetSelfSize = LV_EVENT_GET_SELF_SIZE,
    /** Events of optional LVGL components */
    InvalidateArea = LV_EVENT_INVALIDATE_AREA,
    /** Sent when the resolution changes due to `lv_display_set_resolution()` or `lv_display_set_rotation()`. */
    ResolutionChanged = LV_EVENT_RESOLUTION_CHANGED,
    /** Sent as a result of any call to `lv_display_set_color_format()`. */
    ColorFormatChanged = LV_EVENT_COLOR_FORMAT_CHANGED,
    /** Sent when something happened that requires redraw. */
    RefrRequest = LV_EVENT_REFR_REQUEST,
    /** Sent before a refreshing cycle starts. Sent even if there is nothing to redraw. */
    RefrStart = LV_EVENT_REFR_START,
    /** Sent when refreshing has been completed (after rendering and calling flush callback). Sent even if no redraw happened. */
    RefrReady = LV_EVENT_REFR_READY,
    /** Sent just before rendering begins. */
    RenderStart = LV_EVENT_RENDER_START,
    /** Sent after rendering has been completed. */
    RenderReady = LV_EVENT_RENDER_READY,
    /** Sent before flush callback is called. */
    FlushStart = LV_EVENT_FLUSH_START,
    /** Sent after flush callback call has returned. */
    FlushFinish = LV_EVENT_FLUSH_FINISH,
    /** Sent before flush wait callback is called. */
    FlushWaitStart = LV_EVENT_FLUSH_WAIT_START,
    /** Sent after flush wait callback call has returned. */
    FlushWaitFinish = LV_EVENT_FLUSH_WAIT_FINISH,
    /** Sent before sync callback is called. */
    SyncStart = LV_EVENT_SYNC_START,
    /** Sent after sync callback call has returned. */
    SyncFinish = LV_EVENT_SYNC_FINISH,
    /** Sent before sync wait callback is called. */
    SyncWaitStart = LV_EVENT_SYNC_WAIT_START,
    /** Sent after sync wait callback call has returned. */
    SyncWaitFinish = LV_EVENT_SYNC_WAIT_FINISH,
    /** Sent after layout update completes */
    UpdateLayoutCompleted = LV_EVENT_UPDATE_LAYOUT_COMPLETED,
    Vsync = LV_EVENT_VSYNC,
    VsyncRequest = LV_EVENT_VSYNC_REQUEST,
    #if LV_USE_TRANSLATION
    /** Sent when the translation language changed. */
    TranslationLanguageChanged = LV_EVENT_TRANSLATION_LANGUAGE_CHANGED,
    #endif // LV_USE_TRANSLATION

    /** Number of default events */
    Preprocess = LV_EVENT_PREPROCESS,
    /**
     * This is a flag that can be set with an event so it's processed
     * before the class default event processing
     */
    MarkedDeleting = LV_EVENT_MARKED_DELETING,
};

/** Errors in the file system module. */
enum class FsRes : int {
    Ok = LV_FS_RES_OK,
    HwErr = LV_FS_RES_HW_ERR,
    FsErr = LV_FS_RES_FS_ERR,
    NotEx = LV_FS_RES_NOT_EX,
    Full = LV_FS_RES_FULL,
    Locked = LV_FS_RES_LOCKED,
    Denied = LV_FS_RES_DENIED,
    Busy = LV_FS_RES_BUSY,
    Tout = LV_FS_RES_TOUT,
    NotImp = LV_FS_RES_NOT_IMP,
    OutOfMem = LV_FS_RES_OUT_OF_MEM,
    InvParam = LV_FS_RES_INV_PARAM,
    DriveLetterAlreadyUsed = LV_FS_RES_DRIVE_LETTER_ALREADY_USED,
    Unknown = LV_FS_RES_UNKNOWN,
};

/** File open mode. */
enum class FsMode : int {
    Wr = LV_FS_MODE_WR,
    Rd = LV_FS_MODE_RD,
};
constexpr FsMode operator|(FsMode a, FsMode b) noexcept {
    return static_cast<FsMode>(static_cast<int>(a) | static_cast<int>(b));
}
constexpr FsMode operator&(FsMode a, FsMode b) noexcept {
    return static_cast<FsMode>(static_cast<int>(a) & static_cast<int>(b));
}
constexpr FsMode operator^(FsMode a, FsMode b) noexcept {
    return static_cast<FsMode>(static_cast<int>(a) ^ static_cast<int>(b));
}
constexpr FsMode& operator|=(FsMode& a, FsMode b) noexcept { a = a | b; return a; }

/** Seek modes. */
enum class FsWhence : int {
    /** Set the position from absolutely (from the start of file) */
    Set = LV_FS_SEEK_SET,
    /** Set the position from the current position */
    Cur = LV_FS_SEEK_CUR,
    /** Set the position from the end of the file */
    End = LV_FS_SEEK_END,
};

/** The direction of the gradient. */
enum class GradDir : int {
    /** No gradient (the `grad_color` property is ignored) */
    None = LV_GRAD_DIR_NONE,
    /** Simple vertical (top to bottom) gradient */
    Ver = LV_GRAD_DIR_VER,
    /** Simple horizontal (left to right) gradient */
    Hor = LV_GRAD_DIR_HOR,
    /** Linear gradient defined by start and end points. Can be at any angle. */
    Linear = LV_GRAD_DIR_LINEAR,
    /** Radial gradient defined by start and end circles */
    Radial = LV_GRAD_DIR_RADIAL,
    /** Conical gradient defined by center point, start and end angles */
    Conical = LV_GRAD_DIR_CONICAL,
};

/** Gradient behavior outside the defined range. */
enum class GradExtend : int {
    /** Repeat the same color */
    Pad = LV_GRAD_EXTEND_PAD,
    /** Repeat the pattern */
    Repeat = LV_GRAD_EXTEND_REPEAT,
    /** Repeat the pattern mirrored */
    Reflect = LV_GRAD_EXTEND_REFLECT,
};

enum class Palette : int {
    Red = LV_PALETTE_RED,
    Pink = LV_PALETTE_PINK,
    Purple = LV_PALETTE_PURPLE,
    DeepPurple = LV_PALETTE_DEEP_PURPLE,
    Indigo = LV_PALETTE_INDIGO,
    Blue = LV_PALETTE_BLUE,
    LightBlue = LV_PALETTE_LIGHT_BLUE,
    Cyan = LV_PALETTE_CYAN,
    Teal = LV_PALETTE_TEAL,
    Green = LV_PALETTE_GREEN,
    LightGreen = LV_PALETTE_LIGHT_GREEN,
    Lime = LV_PALETTE_LIME,
    Yellow = LV_PALETTE_YELLOW,
    Amber = LV_PALETTE_AMBER,
    Orange = LV_PALETTE_ORANGE,
    DeepOrange = LV_PALETTE_DEEP_ORANGE,
    Brown = LV_PALETTE_BROWN,
    BlueGrey = LV_PALETTE_BLUE_GREY,
    Grey = LV_PALETTE_GREY,
    None = LV_PALETTE_NONE,
};

enum class RbColor : int {
    Red = LV_RB_COLOR_RED,
    Black = LV_RB_COLOR_BLACK,
};

/** Possible options for blending opaque drawings */
enum class BlendMode : int {
    /** Simply mix according to the opacity value */
    Normal = LV_BLEND_MODE_NORMAL,
    /** Add the respective color channels */
    Additive = LV_BLEND_MODE_ADDITIVE,
    /** Subtract the foreground from the background */
    Subtractive = LV_BLEND_MODE_SUBTRACTIVE,
    /** Multiply the foreground and background */
    Multiply = LV_BLEND_MODE_MULTIPLY,
    /** Absolute difference between foreground and background */
    Difference = LV_BLEND_MODE_DIFFERENCE,
};

/**
 * Some options to apply decorations on texts.
 * 'OR'ed values can be used.
 */
enum class TextDecor : int {
    None = LV_TEXT_DECOR_NONE,
    Underline = LV_TEXT_DECOR_UNDERLINE,
    Strikethrough = LV_TEXT_DECOR_STRIKETHROUGH,
};
constexpr TextDecor operator|(TextDecor a, TextDecor b) noexcept {
    return static_cast<TextDecor>(static_cast<int>(a) | static_cast<int>(b));
}
constexpr TextDecor operator&(TextDecor a, TextDecor b) noexcept {
    return static_cast<TextDecor>(static_cast<int>(a) & static_cast<int>(b));
}
constexpr TextDecor operator^(TextDecor a, TextDecor b) noexcept {
    return static_cast<TextDecor>(static_cast<int>(a) ^ static_cast<int>(b));
}
constexpr TextDecor& operator|=(TextDecor& a, TextDecor b) noexcept { a = a | b; return a; }

/**
 * Selects on which sides border should be drawn
 * 'OR'ed values can be used.
 */
enum class BorderSide : int {
    None = LV_BORDER_SIDE_NONE,
    Bottom = LV_BORDER_SIDE_BOTTOM,
    Top = LV_BORDER_SIDE_TOP,
    Left = LV_BORDER_SIDE_LEFT,
    Right = LV_BORDER_SIDE_RIGHT,
    Full = LV_BORDER_SIDE_FULL,
    /** FOR matrix-like objects (e.g. Button matrix) */
    Internal = LV_BORDER_SIDE_INTERNAL,
};
constexpr BorderSide operator|(BorderSide a, BorderSide b) noexcept {
    return static_cast<BorderSide>(static_cast<int>(a) | static_cast<int>(b));
}
constexpr BorderSide operator&(BorderSide a, BorderSide b) noexcept {
    return static_cast<BorderSide>(static_cast<int>(a) & static_cast<int>(b));
}
constexpr BorderSide operator^(BorderSide a, BorderSide b) noexcept {
    return static_cast<BorderSide>(static_cast<int>(a) ^ static_cast<int>(b));
}
constexpr BorderSide& operator|=(BorderSide& a, BorderSide b) noexcept { a = a | b; return a; }

enum class BlurQuality : int {
    /** Set the quality automatically */
    Auto = LV_BLUR_QUALITY_AUTO,
    /** Prefer speed over precision */
    Speed = LV_BLUR_QUALITY_SPEED,
    /** Prefer precision over speed */
    Precision = LV_BLUR_QUALITY_PRECISION,
};

/**
 * Enumeration of all built in style properties
 * Props are split into groups of 16. When adding a new prop to a group, ensure it does not overflow into the next one.
 */
enum class StyleId : int {
    PropInv = LV_STYLE_PROP_INV,
    Width = LV_STYLE_WIDTH,
    Height = LV_STYLE_HEIGHT,
    Length = LV_STYLE_LENGTH,
    TransformWidth = LV_STYLE_TRANSFORM_WIDTH,
    TransformHeight = LV_STYLE_TRANSFORM_HEIGHT,
    MinWidth = LV_STYLE_MIN_WIDTH,
    MaxWidth = LV_STYLE_MAX_WIDTH,
    MinHeight = LV_STYLE_MIN_HEIGHT,
    MaxHeight = LV_STYLE_MAX_HEIGHT,
    TranslateX = LV_STYLE_TRANSLATE_X,
    TranslateY = LV_STYLE_TRANSLATE_Y,
    RadialOffset = LV_STYLE_RADIAL_OFFSET,
    X = LV_STYLE_X,
    Y = LV_STYLE_Y,
    Align = LV_STYLE_ALIGN,
    PadTop = LV_STYLE_PAD_TOP,
    PadBottom = LV_STYLE_PAD_BOTTOM,
    PadLeft = LV_STYLE_PAD_LEFT,
    PadRight = LV_STYLE_PAD_RIGHT,
    PadRadial = LV_STYLE_PAD_RADIAL,
    PadRow = LV_STYLE_PAD_ROW,
    PadColumn = LV_STYLE_PAD_COLUMN,
    MarginTop = LV_STYLE_MARGIN_TOP,
    MarginBottom = LV_STYLE_MARGIN_BOTTOM,
    MarginLeft = LV_STYLE_MARGIN_LEFT,
    MarginRight = LV_STYLE_MARGIN_RIGHT,
    BgGrad = LV_STYLE_BG_GRAD,
    BgGradDir = LV_STYLE_BG_GRAD_DIR,
    BgMainOpa = LV_STYLE_BG_MAIN_OPA,
    BgGradOpa = LV_STYLE_BG_GRAD_OPA,
    BgGradColor = LV_STYLE_BG_GRAD_COLOR,
    BgMainStop = LV_STYLE_BG_MAIN_STOP,
    BgGradStop = LV_STYLE_BG_GRAD_STOP,
    BgImageSrc = LV_STYLE_BG_IMAGE_SRC,
    BgImageOpa = LV_STYLE_BG_IMAGE_OPA,
    BgImageRecolorOpa = LV_STYLE_BG_IMAGE_RECOLOR_OPA,
    BgImageTiled = LV_STYLE_BG_IMAGE_TILED,
    BgImageRecolor = LV_STYLE_BG_IMAGE_RECOLOR,
    BorderWidth = LV_STYLE_BORDER_WIDTH,
    BorderColor = LV_STYLE_BORDER_COLOR,
    BorderOpa = LV_STYLE_BORDER_OPA,
    BorderPost = LV_STYLE_BORDER_POST,
    BorderSide = LV_STYLE_BORDER_SIDE,
    OutlineWidth = LV_STYLE_OUTLINE_WIDTH,
    OutlineColor = LV_STYLE_OUTLINE_COLOR,
    OutlineOpa = LV_STYLE_OUTLINE_OPA,
    OutlinePad = LV_STYLE_OUTLINE_PAD,
    BgOpa = LV_STYLE_BG_OPA,
    BgColor = LV_STYLE_BG_COLOR,
    ShadowWidth = LV_STYLE_SHADOW_WIDTH,
    LineWidth = LV_STYLE_LINE_WIDTH,
    ArcWidth = LV_STYLE_ARC_WIDTH,
    TextFont = LV_STYLE_TEXT_FONT,
    ImageRecolorOpa = LV_STYLE_IMAGE_RECOLOR_OPA,
    ImageOpa = LV_STYLE_IMAGE_OPA,
    ShadowOpa = LV_STYLE_SHADOW_OPA,
    LineOpa = LV_STYLE_LINE_OPA,
    ArcOpa = LV_STYLE_ARC_OPA,
    TextOpa = LV_STYLE_TEXT_OPA,
    ShadowColor = LV_STYLE_SHADOW_COLOR,
    ImageRecolor = LV_STYLE_IMAGE_RECOLOR,
    LineColor = LV_STYLE_LINE_COLOR,
    ArcColor = LV_STYLE_ARC_COLOR,
    TextColor = LV_STYLE_TEXT_COLOR,
    ArcImageSrc = LV_STYLE_ARC_IMAGE_SRC,
    ShadowOffsetX = LV_STYLE_SHADOW_OFFSET_X,
    ShadowOffsetY = LV_STYLE_SHADOW_OFFSET_Y,
    ShadowSpread = LV_STYLE_SHADOW_SPREAD,
    LineDashWidth = LV_STYLE_LINE_DASH_WIDTH,
    TextAlign = LV_STYLE_TEXT_ALIGN,
    TextLetterSpace = LV_STYLE_TEXT_LETTER_SPACE,
    TextLineSpace = LV_STYLE_TEXT_LINE_SPACE,
    LineDashGap = LV_STYLE_LINE_DASH_GAP,
    LineRounded = LV_STYLE_LINE_ROUNDED,
    ImageColorkey = LV_STYLE_IMAGE_COLORKEY,
    TextOutlineStrokeWidth = LV_STYLE_TEXT_OUTLINE_STROKE_WIDTH,
    TextOutlineStrokeOpa = LV_STYLE_TEXT_OUTLINE_STROKE_OPA,
    TextOutlineStrokeColor = LV_STYLE_TEXT_OUTLINE_STROKE_COLOR,
    TextDecor = LV_STYLE_TEXT_DECOR,
    ArcRounded = LV_STYLE_ARC_ROUNDED,
    Opa = LV_STYLE_OPA,
    OpaLayered = LV_STYLE_OPA_LAYERED,
    ColorFilterDsc = LV_STYLE_COLOR_FILTER_DSC,
    ColorFilterOpa = LV_STYLE_COLOR_FILTER_OPA,
    Anim = LV_STYLE_ANIM,
    AnimDuration = LV_STYLE_ANIM_DURATION,
    Transition = LV_STYLE_TRANSITION,
    Radius = LV_STYLE_RADIUS,
    BitmapMaskSrc = LV_STYLE_BITMAP_MASK_SRC,
    BlendMode = LV_STYLE_BLEND_MODE,
    RotarySensitivity = LV_STYLE_ROTARY_SENSITIVITY,
    TranslateRadial = LV_STYLE_TRANSLATE_RADIAL,
    ClipCorner = LV_STYLE_CLIP_CORNER,
    BaseDir = LV_STYLE_BASE_DIR,
    Recolor = LV_STYLE_RECOLOR,
    RecolorOpa = LV_STYLE_RECOLOR_OPA,
    Layout = LV_STYLE_LAYOUT,
    BlurRadius = LV_STYLE_BLUR_RADIUS,
    BlurBackdrop = LV_STYLE_BLUR_BACKDROP,
    BlurQuality = LV_STYLE_BLUR_QUALITY,
    DropShadowRadius = LV_STYLE_DROP_SHADOW_RADIUS,
    DropShadowOffsetX = LV_STYLE_DROP_SHADOW_OFFSET_X,
    DropShadowOffsetY = LV_STYLE_DROP_SHADOW_OFFSET_Y,
    DropShadowColor = LV_STYLE_DROP_SHADOW_COLOR,
    DropShadowOpa = LV_STYLE_DROP_SHADOW_OPA,
    DropShadowQuality = LV_STYLE_DROP_SHADOW_QUALITY,
    TransformScaleX = LV_STYLE_TRANSFORM_SCALE_X,
    TransformScaleY = LV_STYLE_TRANSFORM_SCALE_Y,
    TransformPivotX = LV_STYLE_TRANSFORM_PIVOT_X,
    TransformPivotY = LV_STYLE_TRANSFORM_PIVOT_Y,
    TransformRotation = LV_STYLE_TRANSFORM_ROTATION,
    TransformSkewX = LV_STYLE_TRANSFORM_SKEW_X,
    TransformSkewY = LV_STYLE_TRANSFORM_SKEW_Y,
    FlexFlow = LV_STYLE_FLEX_FLOW,
    FlexMainPlace = LV_STYLE_FLEX_MAIN_PLACE,
    FlexCrossPlace = LV_STYLE_FLEX_CROSS_PLACE,
    FlexTrackPlace = LV_STYLE_FLEX_TRACK_PLACE,
    FlexGrow = LV_STYLE_FLEX_GROW,
    GridColumnDscArray = LV_STYLE_GRID_COLUMN_DSC_ARRAY,
    GridRowDscArray = LV_STYLE_GRID_ROW_DSC_ARRAY,
    GridColumnAlign = LV_STYLE_GRID_COLUMN_ALIGN,
    GridRowAlign = LV_STYLE_GRID_ROW_ALIGN,
    GridCellColumnPos = LV_STYLE_GRID_CELL_COLUMN_POS,
    GridCellColumnSpan = LV_STYLE_GRID_CELL_COLUMN_SPAN,
    GridCellXAlign = LV_STYLE_GRID_CELL_X_ALIGN,
    GridCellRowPos = LV_STYLE_GRID_CELL_ROW_POS,
    GridCellRowSpan = LV_STYLE_GRID_CELL_ROW_SPAN,
    GridCellYAlign = LV_STYLE_GRID_CELL_Y_ALIGN,
    LastBuiltInProp = LV_STYLE_LAST_BUILT_IN_PROP,
    NumBuiltInProps = LV_STYLE_NUM_BUILT_IN_PROPS,
    PropAny = LV_STYLE_PROP_ANY,
    PropConst = LV_STYLE_PROP_CONST,
    #if LVPP_COMPAT_V8
    /** v8 spelling of `AnimDuration`. */
    AnimTime = LV_STYLE_ANIM_DURATION,
    /** v8 spelling of `ImageOpa`. */
    ImgOpa = LV_STYLE_IMAGE_OPA,
    /** v8 spelling of `ImageRecolor`. */
    ImgRecolor = LV_STYLE_IMAGE_RECOLOR,
    /** v8 spelling of `ImageRecolorOpa`. */
    ImgRecolorOpa = LV_STYLE_IMAGE_RECOLOR_OPA,
    /** v8 spelling of `ShadowOffsetX`. */
    ShadowOfsX = LV_STYLE_SHADOW_OFFSET_X,
    /** v8 spelling of `ShadowOffsetY`. */
    ShadowOfsY = LV_STYLE_SHADOW_OFFSET_Y,
    /** v8 spelling of `TransformRotation`. */
    TransformAngle = LV_STYLE_TRANSFORM_ROTATION,
    #endif // LVPP_COMPAT_V8

};

enum class StyleRes : int {
    NotFound = LV_STYLE_RES_NOT_FOUND,
    Found = LV_STYLE_RES_FOUND,
};

/** Options for text rendering. */
enum class TextFlag : int {
    None = LV_TEXT_FLAG_NONE,
    Expand = LV_TEXT_FLAG_EXPAND,
    /** Max-width is already equal to the longest line. (Used to skip some calculation) */
    Fit = LV_TEXT_FLAG_FIT,
    /**
     * To prevent overflow, insert breaks between any two characters.
     * Otherwise breaks are inserted at word boundaries, as configured via LV_TXT_BREAK_CHARS
     * or according to LV_TXT_LINE_BREAK_LONG_LEN, LV_TXT_LINE_BREAK_LONG_PRE_MIN_LEN,
     * and LV_TXT_LINE_BREAK_LONG_POST_MIN_LEN.
     */
    BreakAll = LV_TEXT_FLAG_BREAK_ALL,
    /** Enable parsing of recolor command */
    Recolor = LV_TEXT_FLAG_RECOLOR,
};
constexpr TextFlag operator|(TextFlag a, TextFlag b) noexcept {
    return static_cast<TextFlag>(static_cast<int>(a) | static_cast<int>(b));
}
constexpr TextFlag operator&(TextFlag a, TextFlag b) noexcept {
    return static_cast<TextFlag>(static_cast<int>(a) & static_cast<int>(b));
}
constexpr TextFlag operator^(TextFlag a, TextFlag b) noexcept {
    return static_cast<TextFlag>(static_cast<int>(a) ^ static_cast<int>(b));
}
constexpr TextFlag& operator|=(TextFlag& a, TextFlag b) noexcept { a = a | b; return a; }

/** Label align policy */
enum class TextAlign : int {
    /** Align text auto */
    Auto = LV_TEXT_ALIGN_AUTO,
    /** Align text to left */
    Left = LV_TEXT_ALIGN_LEFT,
    /** Align text to center */
    Center = LV_TEXT_ALIGN_CENTER,
    /** Align text to right */
    Right = LV_TEXT_ALIGN_RIGHT,
};

enum class TreeWalkMode : uint8_t {
    PreOrder = LV_TREE_WALK_PRE_ORDER,
    PostOrder = LV_TREE_WALK_POST_ORDER,
};

#if !defined(__ASSEMBLY__)
/** LVGL error codes. */
enum class Result : int {
    Invalid = LV_RESULT_INVALID,
    Ok = LV_RESULT_OK,
};
#endif // !defined(__ASSEMBLY__)

#if (LV_USE_ANIMIMG != 0) && (LV_USE_OBJ_PROPERTY)
enum class PropertyAnimimageId : int {
    Src = LV_PROPERTY_ANIMIMAGE_SRC,
    Duration = LV_PROPERTY_ANIMIMAGE_DURATION,
    RepeatCount = LV_PROPERTY_ANIMIMAGE_REPEAT_COUNT,
    SrcCount = LV_PROPERTY_ANIMIMAGE_SRC_COUNT,
    End = LV_PROPERTY_ANIMIMAGE_END,
};
#endif // (LV_USE_ANIMIMG != 0) && (LV_USE_OBJ_PROPERTY)

#if (LV_USE_ARC != 0) && (LV_USE_OBJ_PROPERTY)
enum class PropertyArcId : int {
    StartAngle = LV_PROPERTY_ARC_START_ANGLE,
    EndAngle = LV_PROPERTY_ARC_END_ANGLE,
    BgStartAngle = LV_PROPERTY_ARC_BG_START_ANGLE,
    BgEndAngle = LV_PROPERTY_ARC_BG_END_ANGLE,
    Rotation = LV_PROPERTY_ARC_ROTATION,
    Mode = LV_PROPERTY_ARC_MODE,
    Value = LV_PROPERTY_ARC_VALUE,
    MinValue = LV_PROPERTY_ARC_MIN_VALUE,
    MaxValue = LV_PROPERTY_ARC_MAX_VALUE,
    ChangeRate = LV_PROPERTY_ARC_CHANGE_RATE,
    KnobOffset = LV_PROPERTY_ARC_KNOB_OFFSET,
    End = LV_PROPERTY_ARC_END,
};
#endif // (LV_USE_ARC != 0) && (LV_USE_OBJ_PROPERTY)

#if LV_USE_ARCLABEL != 0
enum class ArclabelDir : int {
    Clockwise = LV_ARCLABEL_DIR_CLOCKWISE,
    CounterClockwise = LV_ARCLABEL_DIR_COUNTER_CLOCKWISE,
};

enum class ArclabelTextAlign : int {
    Default = LV_ARCLABEL_TEXT_ALIGN_DEFAULT,
    Leading = LV_ARCLABEL_TEXT_ALIGN_LEADING,
    Center = LV_ARCLABEL_TEXT_ALIGN_CENTER,
    Trailing = LV_ARCLABEL_TEXT_ALIGN_TRAILING,
};

enum class ArclabelOverflow : int {
    /** Show full text, may overflow object area */
    Visible = LV_ARCLABEL_OVERFLOW_VISIBLE,
    /** Show ellipsis (...) when text overflows */
    Ellipsis = LV_ARCLABEL_OVERFLOW_ELLIPSIS,
    /** Clip text at arc boundary */
    Clip = LV_ARCLABEL_OVERFLOW_CLIP,
};
#endif // LV_USE_ARCLABEL != 0

#if (LV_USE_BAR != 0) && (LV_USE_OBJ_PROPERTY)
enum class PropertyBarId : int {
    Value = LV_PROPERTY_BAR_VALUE,
    StartValue = LV_PROPERTY_BAR_START_VALUE,
    MinValue = LV_PROPERTY_BAR_MIN_VALUE,
    MaxValue = LV_PROPERTY_BAR_MAX_VALUE,
    Mode = LV_PROPERTY_BAR_MODE,
    Orientation = LV_PROPERTY_BAR_ORIENTATION,
    End = LV_PROPERTY_BAR_END,
};
#endif // (LV_USE_BAR != 0) && (LV_USE_OBJ_PROPERTY)

#if (LV_USE_BUTTONMATRIX != 0) && (LV_USE_OBJ_PROPERTY)
enum class PropertyButtonmatrixId : int {
    SelectedButton = LV_PROPERTY_BUTTONMATRIX_SELECTED_BUTTON,
    OneChecked = LV_PROPERTY_BUTTONMATRIX_ONE_CHECKED,
    End = LV_PROPERTY_BUTTONMATRIX_END,
};
#endif // (LV_USE_BUTTONMATRIX != 0) && (LV_USE_OBJ_PROPERTY)

#if (LV_USE_CHART != 0) && (LV_USE_OBJ_PROPERTY)
enum class PropertyChartId : int {
    Type = LV_PROPERTY_CHART_TYPE,
    PointCount = LV_PROPERTY_CHART_POINT_COUNT,
    UpdateMode = LV_PROPERTY_CHART_UPDATE_MODE,
    HorDivLineCount = LV_PROPERTY_CHART_HOR_DIV_LINE_COUNT,
    VerDivLineCount = LV_PROPERTY_CHART_VER_DIV_LINE_COUNT,
    End = LV_PROPERTY_CHART_END,
};
#endif // (LV_USE_CHART != 0) && (LV_USE_OBJ_PROPERTY)

#if (LV_USE_CHECKBOX != 0) && (LV_USE_OBJ_PROPERTY)
enum class PropertyCheckboxId : int {
    Text = LV_PROPERTY_CHECKBOX_TEXT,
    End = LV_PROPERTY_CHECKBOX_END,
};
#endif // (LV_USE_CHECKBOX != 0) && (LV_USE_OBJ_PROPERTY)

#if (LV_USE_DROPDOWN != 0) && (LV_USE_OBJ_PROPERTY)
enum class PropertyDropdownId : int {
    Text = LV_PROPERTY_DROPDOWN_TEXT,
    Options = LV_PROPERTY_DROPDOWN_OPTIONS,
    OptionCount = LV_PROPERTY_DROPDOWN_OPTION_COUNT,
    Selected = LV_PROPERTY_DROPDOWN_SELECTED,
    Dir = LV_PROPERTY_DROPDOWN_DIR,
    Symbol = LV_PROPERTY_DROPDOWN_SYMBOL,
    SelectedHighlight = LV_PROPERTY_DROPDOWN_SELECTED_HIGHLIGHT,
    List = LV_PROPERTY_DROPDOWN_LIST,
    IsOpen = LV_PROPERTY_DROPDOWN_IS_OPEN,
    End = LV_PROPERTY_DROPDOWN_END,
};
#endif // (LV_USE_DROPDOWN != 0) && (LV_USE_OBJ_PROPERTY)

#if (LV_USE_IMAGE != 0) && (LV_USE_OBJ_PROPERTY)
enum class PropertyImageId : int {
    Src = LV_PROPERTY_IMAGE_SRC,
    OffsetX = LV_PROPERTY_IMAGE_OFFSET_X,
    OffsetY = LV_PROPERTY_IMAGE_OFFSET_Y,
    Rotation = LV_PROPERTY_IMAGE_ROTATION,
    Pivot = LV_PROPERTY_IMAGE_PIVOT,
    Scale = LV_PROPERTY_IMAGE_SCALE,
    ScaleX = LV_PROPERTY_IMAGE_SCALE_X,
    ScaleY = LV_PROPERTY_IMAGE_SCALE_Y,
    BlendMode = LV_PROPERTY_IMAGE_BLEND_MODE,
    Antialias = LV_PROPERTY_IMAGE_ANTIALIAS,
    InnerAlign = LV_PROPERTY_IMAGE_INNER_ALIGN,
    End = LV_PROPERTY_IMAGE_END,
};
#endif // (LV_USE_IMAGE != 0) && (LV_USE_OBJ_PROPERTY)

#if (LV_USE_KEYBOARD) && (LV_USE_OBJ_PROPERTY)
enum class PropertyKeyboardId : int {
    Textarea = LV_PROPERTY_KEYBOARD_TEXTAREA,
    Mode = LV_PROPERTY_KEYBOARD_MODE,
    Popovers = LV_PROPERTY_KEYBOARD_POPOVERS,
    SelectedButton = LV_PROPERTY_KEYBOARD_SELECTED_BUTTON,
    End = LV_PROPERTY_KEYBOARD_END,
};
#endif // (LV_USE_KEYBOARD) && (LV_USE_OBJ_PROPERTY)

#if (LV_USE_LABEL != 0) && (LV_USE_OBJ_PROPERTY)
enum class PropertyLabelId : int {
    Text = LV_PROPERTY_LABEL_TEXT,
    LongMode = LV_PROPERTY_LABEL_LONG_MODE,
    TextSelectionStart = LV_PROPERTY_LABEL_TEXT_SELECTION_START,
    TextSelectionEnd = LV_PROPERTY_LABEL_TEXT_SELECTION_END,
    End = LV_PROPERTY_LABEL_END,
};
#endif // (LV_USE_LABEL != 0) && (LV_USE_OBJ_PROPERTY)

#if (LV_USE_LED) && (LV_USE_OBJ_PROPERTY)
enum class PropertyLedId : int {
    Color = LV_PROPERTY_LED_COLOR,
    Brightness = LV_PROPERTY_LED_BRIGHTNESS,
    End = LV_PROPERTY_LED_END,
};
#endif // (LV_USE_LED) && (LV_USE_OBJ_PROPERTY)

#if (LV_USE_LINE != 0) && (LV_USE_OBJ_PROPERTY)
enum class PropertyLineId : int {
    YInvert = LV_PROPERTY_LINE_Y_INVERT,
    End = LV_PROPERTY_LINE_END,
};
#endif // (LV_USE_LINE != 0) && (LV_USE_OBJ_PROPERTY)

#if (LV_USE_MENU) && (LV_USE_OBJ_PROPERTY)
enum class LvPropertyMenuId : int {
    ModeHeader = LV_PROPERTY_MENU_MODE_HEADER,
    ModeRootBackButton = LV_PROPERTY_MENU_MODE_ROOT_BACK_BUTTON,
    End = LV_PROPERTY_MENU_END,
};
#endif // (LV_USE_MENU) && (LV_USE_OBJ_PROPERTY)

#if LV_USE_OBJ_PROPERTY
enum class PropertyStyleId : int {
    Align = LV_PROPERTY_STYLE_ALIGN,
    Anim = LV_PROPERTY_STYLE_ANIM,
    AnimDuration = LV_PROPERTY_STYLE_ANIM_DURATION,
    ArcColor = LV_PROPERTY_STYLE_ARC_COLOR,
    ArcImageSrc = LV_PROPERTY_STYLE_ARC_IMAGE_SRC,
    ArcOpa = LV_PROPERTY_STYLE_ARC_OPA,
    ArcRounded = LV_PROPERTY_STYLE_ARC_ROUNDED,
    ArcWidth = LV_PROPERTY_STYLE_ARC_WIDTH,
    BaseDir = LV_PROPERTY_STYLE_BASE_DIR,
    BgColor = LV_PROPERTY_STYLE_BG_COLOR,
    BgGrad = LV_PROPERTY_STYLE_BG_GRAD,
    BgGradColor = LV_PROPERTY_STYLE_BG_GRAD_COLOR,
    BgGradDir = LV_PROPERTY_STYLE_BG_GRAD_DIR,
    BgGradOpa = LV_PROPERTY_STYLE_BG_GRAD_OPA,
    BgGradStop = LV_PROPERTY_STYLE_BG_GRAD_STOP,
    BgImageOpa = LV_PROPERTY_STYLE_BG_IMAGE_OPA,
    BgImageRecolor = LV_PROPERTY_STYLE_BG_IMAGE_RECOLOR,
    BgImageRecolorOpa = LV_PROPERTY_STYLE_BG_IMAGE_RECOLOR_OPA,
    BgImageSrc = LV_PROPERTY_STYLE_BG_IMAGE_SRC,
    BgImageTiled = LV_PROPERTY_STYLE_BG_IMAGE_TILED,
    BgMainOpa = LV_PROPERTY_STYLE_BG_MAIN_OPA,
    BgMainStop = LV_PROPERTY_STYLE_BG_MAIN_STOP,
    BgOpa = LV_PROPERTY_STYLE_BG_OPA,
    BitmapMaskSrc = LV_PROPERTY_STYLE_BITMAP_MASK_SRC,
    BlendMode = LV_PROPERTY_STYLE_BLEND_MODE,
    BlurBackdrop = LV_PROPERTY_STYLE_BLUR_BACKDROP,
    BlurQuality = LV_PROPERTY_STYLE_BLUR_QUALITY,
    BlurRadius = LV_PROPERTY_STYLE_BLUR_RADIUS,
    BorderColor = LV_PROPERTY_STYLE_BORDER_COLOR,
    BorderOpa = LV_PROPERTY_STYLE_BORDER_OPA,
    BorderPost = LV_PROPERTY_STYLE_BORDER_POST,
    BorderSide = LV_PROPERTY_STYLE_BORDER_SIDE,
    BorderWidth = LV_PROPERTY_STYLE_BORDER_WIDTH,
    ClipCorner = LV_PROPERTY_STYLE_CLIP_CORNER,
    ColorFilterDsc = LV_PROPERTY_STYLE_COLOR_FILTER_DSC,
    ColorFilterOpa = LV_PROPERTY_STYLE_COLOR_FILTER_OPA,
    DropShadowColor = LV_PROPERTY_STYLE_DROP_SHADOW_COLOR,
    DropShadowOffsetX = LV_PROPERTY_STYLE_DROP_SHADOW_OFFSET_X,
    DropShadowOffsetY = LV_PROPERTY_STYLE_DROP_SHADOW_OFFSET_Y,
    DropShadowOpa = LV_PROPERTY_STYLE_DROP_SHADOW_OPA,
    DropShadowQuality = LV_PROPERTY_STYLE_DROP_SHADOW_QUALITY,
    DropShadowRadius = LV_PROPERTY_STYLE_DROP_SHADOW_RADIUS,
    FlexCrossPlace = LV_PROPERTY_STYLE_FLEX_CROSS_PLACE,
    FlexFlow = LV_PROPERTY_STYLE_FLEX_FLOW,
    FlexGrow = LV_PROPERTY_STYLE_FLEX_GROW,
    FlexMainPlace = LV_PROPERTY_STYLE_FLEX_MAIN_PLACE,
    FlexTrackPlace = LV_PROPERTY_STYLE_FLEX_TRACK_PLACE,
    GridCellColumnPos = LV_PROPERTY_STYLE_GRID_CELL_COLUMN_POS,
    GridCellColumnSpan = LV_PROPERTY_STYLE_GRID_CELL_COLUMN_SPAN,
    GridCellRowPos = LV_PROPERTY_STYLE_GRID_CELL_ROW_POS,
    GridCellRowSpan = LV_PROPERTY_STYLE_GRID_CELL_ROW_SPAN,
    GridCellXAlign = LV_PROPERTY_STYLE_GRID_CELL_X_ALIGN,
    GridCellYAlign = LV_PROPERTY_STYLE_GRID_CELL_Y_ALIGN,
    GridColumnAlign = LV_PROPERTY_STYLE_GRID_COLUMN_ALIGN,
    GridColumnDscArray = LV_PROPERTY_STYLE_GRID_COLUMN_DSC_ARRAY,
    GridRowAlign = LV_PROPERTY_STYLE_GRID_ROW_ALIGN,
    GridRowDscArray = LV_PROPERTY_STYLE_GRID_ROW_DSC_ARRAY,
    Height = LV_PROPERTY_STYLE_HEIGHT,
    ImageColorkey = LV_PROPERTY_STYLE_IMAGE_COLORKEY,
    ImageOpa = LV_PROPERTY_STYLE_IMAGE_OPA,
    ImageRecolor = LV_PROPERTY_STYLE_IMAGE_RECOLOR,
    ImageRecolorOpa = LV_PROPERTY_STYLE_IMAGE_RECOLOR_OPA,
    LastBuiltInProp = LV_PROPERTY_STYLE_LAST_BUILT_IN_PROP,
    Layout = LV_PROPERTY_STYLE_LAYOUT,
    Length = LV_PROPERTY_STYLE_LENGTH,
    LineColor = LV_PROPERTY_STYLE_LINE_COLOR,
    LineDashGap = LV_PROPERTY_STYLE_LINE_DASH_GAP,
    LineDashWidth = LV_PROPERTY_STYLE_LINE_DASH_WIDTH,
    LineOpa = LV_PROPERTY_STYLE_LINE_OPA,
    LineRounded = LV_PROPERTY_STYLE_LINE_ROUNDED,
    LineWidth = LV_PROPERTY_STYLE_LINE_WIDTH,
    MarginBottom = LV_PROPERTY_STYLE_MARGIN_BOTTOM,
    MarginLeft = LV_PROPERTY_STYLE_MARGIN_LEFT,
    MarginRight = LV_PROPERTY_STYLE_MARGIN_RIGHT,
    MarginTop = LV_PROPERTY_STYLE_MARGIN_TOP,
    MaxHeight = LV_PROPERTY_STYLE_MAX_HEIGHT,
    MaxWidth = LV_PROPERTY_STYLE_MAX_WIDTH,
    MinHeight = LV_PROPERTY_STYLE_MIN_HEIGHT,
    MinWidth = LV_PROPERTY_STYLE_MIN_WIDTH,
    Opa = LV_PROPERTY_STYLE_OPA,
    OpaLayered = LV_PROPERTY_STYLE_OPA_LAYERED,
    OutlineColor = LV_PROPERTY_STYLE_OUTLINE_COLOR,
    OutlineOpa = LV_PROPERTY_STYLE_OUTLINE_OPA,
    OutlinePad = LV_PROPERTY_STYLE_OUTLINE_PAD,
    OutlineWidth = LV_PROPERTY_STYLE_OUTLINE_WIDTH,
    PadBottom = LV_PROPERTY_STYLE_PAD_BOTTOM,
    PadColumn = LV_PROPERTY_STYLE_PAD_COLUMN,
    PadLeft = LV_PROPERTY_STYLE_PAD_LEFT,
    PadRadial = LV_PROPERTY_STYLE_PAD_RADIAL,
    PadRight = LV_PROPERTY_STYLE_PAD_RIGHT,
    PadRow = LV_PROPERTY_STYLE_PAD_ROW,
    PadTop = LV_PROPERTY_STYLE_PAD_TOP,
    PropInv = LV_PROPERTY_STYLE_PROP_INV,
    RadialOffset = LV_PROPERTY_STYLE_RADIAL_OFFSET,
    Radius = LV_PROPERTY_STYLE_RADIUS,
    Recolor = LV_PROPERTY_STYLE_RECOLOR,
    RecolorOpa = LV_PROPERTY_STYLE_RECOLOR_OPA,
    RotarySensitivity = LV_PROPERTY_STYLE_ROTARY_SENSITIVITY,
    ShadowColor = LV_PROPERTY_STYLE_SHADOW_COLOR,
    ShadowOffsetX = LV_PROPERTY_STYLE_SHADOW_OFFSET_X,
    ShadowOffsetY = LV_PROPERTY_STYLE_SHADOW_OFFSET_Y,
    ShadowOpa = LV_PROPERTY_STYLE_SHADOW_OPA,
    ShadowSpread = LV_PROPERTY_STYLE_SHADOW_SPREAD,
    ShadowWidth = LV_PROPERTY_STYLE_SHADOW_WIDTH,
    TextAlign = LV_PROPERTY_STYLE_TEXT_ALIGN,
    TextColor = LV_PROPERTY_STYLE_TEXT_COLOR,
    TextDecor = LV_PROPERTY_STYLE_TEXT_DECOR,
    TextFont = LV_PROPERTY_STYLE_TEXT_FONT,
    TextLetterSpace = LV_PROPERTY_STYLE_TEXT_LETTER_SPACE,
    TextLineSpace = LV_PROPERTY_STYLE_TEXT_LINE_SPACE,
    TextOpa = LV_PROPERTY_STYLE_TEXT_OPA,
    TextOutlineStrokeColor = LV_PROPERTY_STYLE_TEXT_OUTLINE_STROKE_COLOR,
    TextOutlineStrokeOpa = LV_PROPERTY_STYLE_TEXT_OUTLINE_STROKE_OPA,
    TextOutlineStrokeWidth = LV_PROPERTY_STYLE_TEXT_OUTLINE_STROKE_WIDTH,
    TransformHeight = LV_PROPERTY_STYLE_TRANSFORM_HEIGHT,
    TransformPivotX = LV_PROPERTY_STYLE_TRANSFORM_PIVOT_X,
    TransformPivotY = LV_PROPERTY_STYLE_TRANSFORM_PIVOT_Y,
    TransformRotation = LV_PROPERTY_STYLE_TRANSFORM_ROTATION,
    TransformScaleX = LV_PROPERTY_STYLE_TRANSFORM_SCALE_X,
    TransformScaleY = LV_PROPERTY_STYLE_TRANSFORM_SCALE_Y,
    TransformSkewX = LV_PROPERTY_STYLE_TRANSFORM_SKEW_X,
    TransformSkewY = LV_PROPERTY_STYLE_TRANSFORM_SKEW_Y,
    TransformWidth = LV_PROPERTY_STYLE_TRANSFORM_WIDTH,
    Transition = LV_PROPERTY_STYLE_TRANSITION,
    TranslateRadial = LV_PROPERTY_STYLE_TRANSLATE_RADIAL,
    TranslateX = LV_PROPERTY_STYLE_TRANSLATE_X,
    TranslateY = LV_PROPERTY_STYLE_TRANSLATE_Y,
    Width = LV_PROPERTY_STYLE_WIDTH,
    X = LV_PROPERTY_STYLE_X,
    Y = LV_PROPERTY_STYLE_Y,
};
#endif // LV_USE_OBJ_PROPERTY

#if (LV_USE_ROLLER != 0) && (LV_USE_OBJ_PROPERTY)
enum class PropertyRollerId : int {
    Options = LV_PROPERTY_ROLLER_OPTIONS,
    Selected = LV_PROPERTY_ROLLER_SELECTED,
    VisibleRowCount = LV_PROPERTY_ROLLER_VISIBLE_ROW_COUNT,
    End = LV_PROPERTY_ROLLER_END,
};
#endif // (LV_USE_ROLLER != 0) && (LV_USE_OBJ_PROPERTY)

#if (LV_USE_SCALE != 0) && (LV_USE_OBJ_PROPERTY)
enum class PropertyScaleId : int {
    Mode = LV_PROPERTY_SCALE_MODE,
    TotalTickCount = LV_PROPERTY_SCALE_TOTAL_TICK_COUNT,
    MajorTickEvery = LV_PROPERTY_SCALE_MAJOR_TICK_EVERY,
    LabelShow = LV_PROPERTY_SCALE_LABEL_SHOW,
    AngleRange = LV_PROPERTY_SCALE_ANGLE_RANGE,
    Rotation = LV_PROPERTY_SCALE_ROTATION,
    RangeMinValue = LV_PROPERTY_SCALE_RANGE_MIN_VALUE,
    RangeMaxValue = LV_PROPERTY_SCALE_RANGE_MAX_VALUE,
    End = LV_PROPERTY_SCALE_END,
};
#endif // (LV_USE_SCALE != 0) && (LV_USE_OBJ_PROPERTY)

#if (LV_USE_SLIDER != 0) && (LV_USE_OBJ_PROPERTY)
enum class PropertySliderId : int {
    Value = LV_PROPERTY_SLIDER_VALUE,
    LeftValue = LV_PROPERTY_SLIDER_LEFT_VALUE,
    Range = LV_PROPERTY_SLIDER_RANGE,
    MinValue = LV_PROPERTY_SLIDER_MIN_VALUE,
    MaxValue = LV_PROPERTY_SLIDER_MAX_VALUE,
    Mode = LV_PROPERTY_SLIDER_MODE,
    IsDragged = LV_PROPERTY_SLIDER_IS_DRAGGED,
    IsSymmetrical = LV_PROPERTY_SLIDER_IS_SYMMETRICAL,
    End = LV_PROPERTY_SLIDER_END,
};
#endif // (LV_USE_SLIDER != 0) && (LV_USE_OBJ_PROPERTY)

#if LV_USE_SPAN != 0
enum class SpanOverflow : int {
    Clip = LV_SPAN_OVERFLOW_CLIP,
    Ellipsis = LV_SPAN_OVERFLOW_ELLIPSIS,
};

enum class SpanMode : int {
    /** fixed the obj size */
    Fixed = LV_SPAN_MODE_FIXED,
    /** Expand the object size to the text size */
    Expand = LV_SPAN_MODE_EXPAND,
    /** Keep width, break the too long lines and expand height */
    Break = LV_SPAN_MODE_BREAK,
};
#endif // LV_USE_SPAN != 0

#if (LV_USE_SPAN != 0) && (LV_USE_OBJ_PROPERTY)
enum class PropertySpanId : int {
    Align = LV_PROPERTY_SPAN_ALIGN,
    Overflow = LV_PROPERTY_SPAN_OVERFLOW,
    Indent = LV_PROPERTY_SPAN_INDENT,
    Mode = LV_PROPERTY_SPAN_MODE,
    MaxLines = LV_PROPERTY_SPAN_MAX_LINES,
    End = LV_PROPERTY_SPAN_END,
};
#endif // (LV_USE_SPAN != 0) && (LV_USE_OBJ_PROPERTY)

#if (LV_USE_SPINBOX) && (LV_USE_OBJ_PROPERTY)
enum class PropertySpinboxId : int {
    Value = LV_PROPERTY_SPINBOX_VALUE,
    Rollover = LV_PROPERTY_SPINBOX_ROLLOVER,
    DigitCount = LV_PROPERTY_SPINBOX_DIGIT_COUNT,
    DecPointPos = LV_PROPERTY_SPINBOX_DEC_POINT_POS,
    Step = LV_PROPERTY_SPINBOX_STEP,
    MinValue = LV_PROPERTY_SPINBOX_MIN_VALUE,
    MaxValue = LV_PROPERTY_SPINBOX_MAX_VALUE,
    DigitStepDirection = LV_PROPERTY_SPINBOX_DIGIT_STEP_DIRECTION,
    End = LV_PROPERTY_SPINBOX_END,
};
#endif // (LV_USE_SPINBOX) && (LV_USE_OBJ_PROPERTY)

#if (LV_USE_SPINNER) && (LV_USE_OBJ_PROPERTY)
enum class PropertySpinnerId : int {
    AnimDuration = LV_PROPERTY_SPINNER_ANIM_DURATION,
    ArcSweep = LV_PROPERTY_SPINNER_ARC_SWEEP,
    End = LV_PROPERTY_SPINNER_END,
};
#endif // (LV_USE_SPINNER) && (LV_USE_OBJ_PROPERTY)

#if (LV_USE_SWITCH != 0) && (LV_USE_OBJ_PROPERTY)
enum class PropertySwitchId : int {
    Orientation = LV_PROPERTY_SWITCH_ORIENTATION,
    End = LV_PROPERTY_SWITCH_END,
};
#endif // (LV_USE_SWITCH != 0) && (LV_USE_OBJ_PROPERTY)

#if LV_USE_TABLE != 0
enum class TableCellCtrl : int {
    None = LV_TABLE_CELL_CTRL_NONE,
    MergeRight = LV_TABLE_CELL_CTRL_MERGE_RIGHT,
    TextCrop = LV_TABLE_CELL_CTRL_TEXT_CROP,
    Custom1 = LV_TABLE_CELL_CTRL_CUSTOM_1,
    Custom2 = LV_TABLE_CELL_CTRL_CUSTOM_2,
    Custom3 = LV_TABLE_CELL_CTRL_CUSTOM_3,
    Custom4 = LV_TABLE_CELL_CTRL_CUSTOM_4,
};
#endif // LV_USE_TABLE != 0

#if (LV_USE_TABLE != 0) && (LV_USE_OBJ_PROPERTY)
enum class PropertyTableId : int {
    RowCount = LV_PROPERTY_TABLE_ROW_COUNT,
    ColumnCount = LV_PROPERTY_TABLE_COLUMN_COUNT,
    End = LV_PROPERTY_TABLE_END,
};
#endif // (LV_USE_TABLE != 0) && (LV_USE_OBJ_PROPERTY)

#if (LV_USE_TABVIEW) && (LV_USE_OBJ_PROPERTY)
enum class PropertyTabviewId : int {
    TabActive = LV_PROPERTY_TABVIEW_TAB_ACTIVE,
    TabBarPosition = LV_PROPERTY_TABVIEW_TAB_BAR_POSITION,
    End = LV_PROPERTY_TABVIEW_END,
};
#endif // (LV_USE_TABVIEW) && (LV_USE_OBJ_PROPERTY)

#if (LV_USE_TEXTAREA != 0) && (LV_USE_OBJ_PROPERTY)
enum class PropertyTextareaId : int {
    Text = LV_PROPERTY_TEXTAREA_TEXT,
    PlaceholderText = LV_PROPERTY_TEXTAREA_PLACEHOLDER_TEXT,
    CursorPos = LV_PROPERTY_TEXTAREA_CURSOR_POS,
    CursorClickPos = LV_PROPERTY_TEXTAREA_CURSOR_CLICK_POS,
    PasswordMode = LV_PROPERTY_TEXTAREA_PASSWORD_MODE,
    PasswordBullet = LV_PROPERTY_TEXTAREA_PASSWORD_BULLET,
    OneLine = LV_PROPERTY_TEXTAREA_ONE_LINE,
    AcceptedChars = LV_PROPERTY_TEXTAREA_ACCEPTED_CHARS,
    MaxLength = LV_PROPERTY_TEXTAREA_MAX_LENGTH,
    TextSelection = LV_PROPERTY_TEXTAREA_TEXT_SELECTION,
    PasswordShowTime = LV_PROPERTY_TEXTAREA_PASSWORD_SHOW_TIME,
    Label = LV_PROPERTY_TEXTAREA_LABEL,
    TextIsSelected = LV_PROPERTY_TEXTAREA_TEXT_IS_SELECTED,
    CurrentChar = LV_PROPERTY_TEXTAREA_CURRENT_CHAR,
    End = LV_PROPERTY_TEXTAREA_END,
};
#endif // (LV_USE_TEXTAREA != 0) && (LV_USE_OBJ_PROPERTY)

// ---------------------------------------------------------------------------------------------
// PRELUDE FRAGMENT (D-C6): the ALGEBRA over the two enumerations above, which are generated.
//
// Inserted into the enumerations file rather than given one of its own, because it can only be
// written once `Part` and `State` exist. Copied verbatim, with no substitution.
//
// Parts live in bits 16..23 and states in bits 0..15 -- disjoint, so the algebra is exact and
// free. It also removes the -Wdeprecated-enum-enum-conversion warning that `LV_PART_KNOB |
// LV_STATE_PRESSED` produces in C++20: written directly, that is a bitwise operation between two
// different unnamed enumerations.
// ---------------------------------------------------------------------------------------------
class Selector {
    lv_style_selector_t v_;

public:
    constexpr Selector() noexcept : v_(0) {}
    constexpr Selector(Part p) noexcept                                    // implicit on purpose
        : v_(static_cast<lv_style_selector_t>(p)) {}
    constexpr Selector(State s) noexcept
        : v_(static_cast<lv_style_selector_t>(s)) {}
    constexpr explicit Selector(lv_style_selector_t raw) noexcept : v_(raw) {}

    constexpr lv_style_selector_t value() const noexcept { return v_; }

    /**
     * The `part` half only -- the C getters take a bare part, not a selector. That asymmetry is
     * measured (104/104 setters against 109/110 getters) and deliberately not normalised (D-C9).
     */
    constexpr lv_style_selector_t part() const noexcept { return v_ & 0x00FF0000u; }

    friend constexpr Selector operator|(Selector a, Selector b) noexcept {
        return Selector(static_cast<lv_style_selector_t>(a.v_ | b.v_));
    }
};

constexpr Selector operator|(Part p, State s) noexcept { return Selector(p) | Selector(s); }
constexpr Selector operator|(State s, Part p) noexcept { return Selector(p) | Selector(s); }

static_assert(sizeof(Selector) == sizeof(lv_style_selector_t));
static_assert((Part::Main | State::Default).value()
              == (static_cast<lv_style_selector_t>(LV_PART_MAIN)
                  | static_cast<lv_style_selector_t>(LV_STATE_DEFAULT)));

} // namespace lv
