#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstddef>
#include <cstdint>

namespace lv {

/**
 * A local style: (object, selector) written once, then the properties.
 * Two words, always inlined and never stored, so it costs nothing.
 */
class LocalStyle {
    lv_obj_t* p_;
    lv_style_selector_t sel_;

public:
    constexpr LocalStyle(lv_obj_t* p, Selector sel) noexcept : p_(p), sel_(sel.value()) {}

    /** @see lv_obj_set_style_pad_all */
    LocalStyle& pad_all(int32_t value) noexcept;
    /** @see lv_obj_set_style_pad_hor */
    LocalStyle& pad_hor(int32_t value) noexcept;
    /** @see lv_obj_set_style_pad_ver */
    LocalStyle& pad_ver(int32_t value) noexcept;
    /** @see lv_obj_set_style_margin_all */
    LocalStyle& margin_all(int32_t value) noexcept;
    /** @see lv_obj_set_style_margin_hor */
    LocalStyle& margin_hor(int32_t value) noexcept;
    /** @see lv_obj_set_style_margin_ver */
    LocalStyle& margin_ver(int32_t value) noexcept;
    /** @see lv_obj_set_style_pad_gap */
    LocalStyle& pad_gap(int32_t value) noexcept;
    /** @see lv_obj_set_style_size */
    LocalStyle& size(int32_t width, int32_t height) noexcept;
    /** @see lv_obj_set_style_transform_scale */
    LocalStyle& transform_scale(int32_t value) noexcept;
    /**
     * Sets width of Widget. Pixel, percentage and `LV_SIZE_CONTENT` values can be used.
     * Percentage values are relative to the width of the parent's content area.
     * Default: Widget dependent, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_width
     */
    LocalStyle& width(int32_t value) noexcept;
    /**
     * Sets a minimal width. Pixel and percentage values can be used. Percentage values
     * are relative to the width of the parent's content area.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_min_width
     */
    LocalStyle& min_width(int32_t value) noexcept;
    /**
     * Sets a maximal width. Pixel and percentage values can be used. Percentage values
     * are relative to the width of the parent's content area.
     * Default: LV_COORD_MAX, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_max_width
     */
    LocalStyle& max_width(int32_t value) noexcept;
    /**
     * Sets height of Widget. Pixel, percentage and `LV_SIZE_CONTENT` can be used.
     * Percentage values are relative to the height of the parent's content area.
     * Default: Widget dependent, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_height
     */
    LocalStyle& height(int32_t value) noexcept;
    /**
     * Sets a minimal height. Pixel and percentage values can be used. Percentage values
     * are relative to the height of the parent's content area.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_min_height
     */
    LocalStyle& min_height(int32_t value) noexcept;
    /**
     * Sets a maximal height. Pixel and percentage values can be used. Percentage values
     * are relative to the height of the parent's content area.
     * Default: LV_COORD_MAX, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_max_height
     */
    LocalStyle& max_height(int32_t value) noexcept;
    /**
     * Its meaning depends on the type of Widget. For example in case of lv_scale it means
     * the length of the ticks.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_length
     */
    LocalStyle& length(int32_t value) noexcept;
    /**
     * Set X coordinate of Widget considering the ``align`` setting. Pixel and percentage
     * values can be used. Percentage values are relative to the width of the parent's
     * content area.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_x
     */
    LocalStyle& x(int32_t value) noexcept;
    /**
     * Set Y coordinate of Widget considering the ``align`` setting. Pixel and percentage
     * values can be used. Percentage values are relative to the height of the parent's
     * content area.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_y
     */
    LocalStyle& y(int32_t value) noexcept;
    /**
     * Set the alignment which tells from which point of the parent the X and Y
     * coordinates should be interpreted. Possible values are: `LV_ALIGN_DEFAULT`,
     * `LV_ALIGN_TOP_LEFT/MID/RIGHT`, `LV_ALIGN_BOTTOM_LEFT/MID/RIGHT`,
     * `LV_ALIGN_LEFT/RIGHT_MID`, `LV_ALIGN_CENTER`. `LV_ALIGN_DEFAULT` means
     * `LV_ALIGN_TOP_LEFT` with LTR base direction and `LV_ALIGN_TOP_RIGHT` with RTL base
     * direction.
     * Default: `LV_ALIGN_DEFAULT`, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_align
     */
    LocalStyle& align(Align value) noexcept;
    /**
     * Make Widget wider on both sides with this value. Pixel and percentage (with
     * `lv_pct(x)`) values can be used. Percentage values are relative to Widget's width.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_transform_width
     */
    LocalStyle& transform_width(int32_t value) noexcept;
    /**
     * Make Widget higher on both sides with this value. Pixel and percentage (with
     * `lv_pct(x)`) values can be used. Percentage values are relative to Widget's height.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_transform_height
     */
    LocalStyle& transform_height(int32_t value) noexcept;
    /**
     * Move Widget with this value in X direction. Applied after layouts, aligns and other
     * positioning. Pixel and percentage (with `lv_pct(x)`) values can be used. Percentage
     * values are relative to Widget's width.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_translate_x
     */
    LocalStyle& translate_x(int32_t value) noexcept;
    /**
     * Move Widget with this value in Y direction. Applied after layouts, aligns and other
     * positioning. Pixel and percentage (with `lv_pct(x)`) values can be used. Percentage
     * values are relative to Widget's height.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_translate_y
     */
    LocalStyle& translate_y(int32_t value) noexcept;
    /**
     * Move object around the centre of the parent object (e.g. around the circumference
     * of a scale).
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_translate_radial
     */
    LocalStyle& translate_radial(int32_t value) noexcept;
    /**
     * Zoom Widget horizontally. The value 256 (or `LV_SCALE_NONE`) means normal size, 128
     * half size, 512 double size, and so on.
     * Default: 0, inherited: No, layout: Yes, ext. draw: Yes.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_transform_scale_x
     */
    LocalStyle& transform_scale_x(int32_t value) noexcept;
    /**
     * Zoom Widget vertically. The value 256 (or `LV_SCALE_NONE`) means normal size, 128
     * half size, 512 double size, and so on.
     * Default: 0, inherited: No, layout: Yes, ext. draw: Yes.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_transform_scale_y
     */
    LocalStyle& transform_scale_y(int32_t value) noexcept;
    /**
     * Rotate Widget. The value is interpreted in 0.1 degree units. E.g. 450 means 45 deg.
     * Default: 0, inherited: No, layout: Yes, ext. draw: Yes.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_transform_rotation
     */
    LocalStyle& transform_rotation(int32_t value) noexcept;
    /**
     * Set pivot point's X coordinate for transformations. Relative to Widget's top left corner.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_transform_pivot_x
     */
    LocalStyle& transform_pivot_x(int32_t value) noexcept;
    /**
     * Set pivot point's Y coordinate for transformations. Relative to Widget's top left corner.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_transform_pivot_y
     */
    LocalStyle& transform_pivot_y(int32_t value) noexcept;
    /**
     * Skew Widget horizontally. The value is interpreted in 0.1 degree units. E.g. 450
     * means 45 deg.
     * Default: 0, inherited: No, layout: Yes, ext. draw: Yes.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_transform_skew_x
     */
    LocalStyle& transform_skew_x(int32_t value) noexcept;
    /**
     * Skew Widget vertically. The value is interpreted in 0.1 degree units. E.g. 450
     * means 45 deg.
     * Default: 0, inherited: No, layout: Yes, ext. draw: Yes.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_transform_skew_y
     */
    LocalStyle& transform_skew_y(int32_t value) noexcept;
    /**
     * Sets the padding on the top. It makes the content area smaller in this direction.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_pad_top
     */
    LocalStyle& pad_top(int32_t value) noexcept;
    /**
     * Sets the padding on the bottom. It makes the content area smaller in this direction.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_pad_bottom
     */
    LocalStyle& pad_bottom(int32_t value) noexcept;
    /**
     * Sets the padding on the left. It makes the content area smaller in this direction.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_pad_left
     */
    LocalStyle& pad_left(int32_t value) noexcept;
    /**
     * Sets the padding on the right. It makes the content area smaller in this direction.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_pad_right
     */
    LocalStyle& pad_right(int32_t value) noexcept;
    /**
     * Sets the padding between the rows. Used by the layouts.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_pad_row
     */
    LocalStyle& pad_row(int32_t value) noexcept;
    /**
     * Sets the padding between the columns. Used by the layouts.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_pad_column
     */
    LocalStyle& pad_column(int32_t value) noexcept;
    /**
     * Pad text labels away from the scale ticks/remainder of the ``LV_PART_``.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_pad_radial
     */
    LocalStyle& pad_radial(int32_t value) noexcept;
    /**
     * Sets margin on the top. Widget will keep this space from its siblings in layouts.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_margin_top
     */
    LocalStyle& margin_top(int32_t value) noexcept;
    /**
     * Sets margin on the bottom. Widget will keep this space from its siblings in layouts.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_margin_bottom
     */
    LocalStyle& margin_bottom(int32_t value) noexcept;
    /**
     * Sets margin on the left. Widget will keep this space from its siblings in layouts.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_margin_left
     */
    LocalStyle& margin_left(int32_t value) noexcept;
    /**
     * Sets margin on the right. Widget will keep this space from its siblings in layouts.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_margin_right
     */
    LocalStyle& margin_right(int32_t value) noexcept;
    /**
     * Set background color of Widget.
     * Default: `0xffffff`, inherited: No, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_bg_color
     */
    LocalStyle& bg_color(Color value) noexcept;
    /**
     * Set opacity of the background. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means fully
     * transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means fully covering, other values
     * or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_TRANSP`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_bg_opa
     */
    LocalStyle& bg_opa(lv_opa_t value) noexcept;
    /**
     * Set gradient color of the background. Used only if `grad_dir` is not `LV_GRAD_DIR_NONE`.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_bg_grad_color
     */
    LocalStyle& bg_grad_color(Color value) noexcept;
    /**
     * Set direction of the gradient of the background. Possible values are
     * `LV_GRAD_DIR_NONE/HOR/VER`.
     * Default: `LV_GRAD_DIR_NONE`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_bg_grad_dir
     */
    LocalStyle& bg_grad_dir(GradDir value) noexcept;
    /**
     * Set point from which background color should start for gradients. 0 means to
     * top/left side, 255 the bottom/right side, 128 the center, and so on.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_bg_main_stop
     */
    LocalStyle& bg_main_stop(int32_t value) noexcept;
    /**
     * Set point from which background's gradient color should start. 0 means to top/left
     * side, 255 the bottom/right side, 128 the center, and so on.
     * Default: 255, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_bg_grad_stop
     */
    LocalStyle& bg_grad_stop(int32_t value) noexcept;
    /**
     * Set opacity of the first gradient color.
     * Default: 255, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_bg_main_opa
     */
    LocalStyle& bg_main_opa(lv_opa_t value) noexcept;
    /**
     * Set opacity of the second gradient color.
     * Default: 255, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_bg_grad_opa
     */
    LocalStyle& bg_grad_opa(lv_opa_t value) noexcept;
    /**
     * Set gradient definition. The pointed instance must exist while Widget is alive.
     * NULL to disable. It wraps `BG_GRAD_COLOR`, `BG_GRAD_DIR`, `BG_MAIN_STOP` and
     * `BG_GRAD_STOP` into one descriptor and allows creating gradients with more colors
     * as well. If it's set other gradient related properties will be ignored.
     * Default: `NULL`, inherited: No, layout: No, ext. draw: No.
     * @param value  Pointer to gradient descriptor
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_bg_grad
     */
    LocalStyle& bg_grad(const lv_grad_dsc_t* value) noexcept;
    /**
     * Set a background image. Can be a pointer to `lv_image_dsc_t`, a path to a file or
     * an `LV_SYMBOL_...`.
     * Default: `NULL`, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Pointer to image source
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_bg_image_src
     */
    LocalStyle& bg_image_src(const void* value) noexcept;
    /**
     * Set opacity of the background image. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means
     * fully transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means fully covering, other
     * values or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_bg_image_opa
     */
    LocalStyle& bg_image_opa(lv_opa_t value) noexcept;
    /**
     * Set a color to mix to the background image.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_bg_image_recolor
     */
    LocalStyle& bg_image_recolor(Color value) noexcept;
    /**
     * Set intensity of background image recoloring. Value 0, `LV_OPA_0` or
     * `LV_OPA_TRANSP` means no mixing, 255, `LV_OPA_100` or `LV_OPA_COVER` means full
     * recoloring, other values or LV_OPA_10, LV_OPA_20, etc are interpreted
     * proportionally.
     * Default: `LV_OPA_TRANSP`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_bg_image_recolor_opa
     */
    LocalStyle& bg_image_recolor_opa(lv_opa_t value) noexcept;
    /**
     * If enabled the background image will be tiled. Possible values are `true` or `false`.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_bg_image_tiled
     */
    LocalStyle& bg_image_tiled(bool value) noexcept;
    /**
     * Set color of the border.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_border_color
     */
    LocalStyle& border_color(Color value) noexcept;
    /**
     * Set opacity of the border. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means fully
     * transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means fully covering, other values
     * or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_border_opa
     */
    LocalStyle& border_opa(lv_opa_t value) noexcept;
    /**
     * Set width of the border. Only pixel values can be used.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_border_width
     */
    LocalStyle& border_width(int32_t value) noexcept;
    /**
     * Set only which side(s) the border should be drawn. Possible values are
     * `LV_BORDER_SIDE_NONE/TOP/BOTTOM/LEFT/RIGHT/INTERNAL`. OR-ed values can be used as
     * well, e.g. `LV_BORDER_SIDE_TOP | LV_BORDER_SIDE_LEFT`.
     * Default: `LV_BORDER_SIDE_FULL`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_border_side
     */
    LocalStyle& border_side(BorderSide value) noexcept;
    /**
     * Sets whether the border should be drawn before or after the children are drawn.
     * `true`: after children, `false`: before children.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_border_post
     */
    LocalStyle& border_post(bool value) noexcept;
    /**
     * Set width of outline in pixels.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_outline_width
     */
    LocalStyle& outline_width(int32_t value) noexcept;
    /**
     * Set color of outline.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_outline_color
     */
    LocalStyle& outline_color(Color value) noexcept;
    /**
     * Set opacity of outline. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means fully
     * transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means fully covering, other values
     * or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_outline_opa
     */
    LocalStyle& outline_opa(lv_opa_t value) noexcept;
    /**
     * Set padding of outline, i.e. the gap between Widget and the outline.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_outline_pad
     */
    LocalStyle& outline_pad(int32_t value) noexcept;
    /**
     * Set width of the shadow in pixels. The value should be >= 0.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_shadow_width
     */
    LocalStyle& shadow_width(int32_t value) noexcept;
    /**
     * Set an offset on the shadow in pixels in X direction.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_shadow_offset_x
     */
    LocalStyle& shadow_offset_x(int32_t value) noexcept;
    /**
     * Set an offset on the shadow in pixels in Y direction.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_shadow_offset_y
     */
    LocalStyle& shadow_offset_y(int32_t value) noexcept;
    /**
     * Make shadow calculation to use a larger or smaller rectangle as base. The value can
     * be in pixels to make the area larger/smaller.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_shadow_spread
     */
    LocalStyle& shadow_spread(int32_t value) noexcept;
    /**
     * Set color of shadow.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_shadow_color
     */
    LocalStyle& shadow_color(Color value) noexcept;
    /**
     * Set opacity of shadow. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means fully
     * transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means fully covering, other values
     * or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_shadow_opa
     */
    LocalStyle& shadow_opa(lv_opa_t value) noexcept;
    /**
     * Set opacity of an image. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means fully
     * transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means fully covering, other values
     * or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_image_opa
     */
    LocalStyle& image_opa(lv_opa_t value) noexcept;
    /**
     * Set color to mix with the image.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_image_recolor
     */
    LocalStyle& image_recolor(Color value) noexcept;
    /**
     * Set intensity of color mixing. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means fully
     * transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means fully covering, other values
     * or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_image_recolor_opa
     */
    LocalStyle& image_recolor_opa(lv_opa_t value) noexcept;
    /**
     * Set image colorkey definition. The lv_image_colorkey_t contains two color values:
     * `high_color` and `low_color`. the color of pixels ranging from `low_color` to
     * `high_color` will be transparent.
     * Default: `NULL`, inherited: No, layout: No, ext. draw: No.
     * @param value  Pointer to image color key
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_image_colorkey
     */
    LocalStyle& image_colorkey(const lv_image_colorkey_t* value) noexcept;
    /**
     * Set width of lines in pixels.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_line_width
     */
    LocalStyle& line_width(int32_t value) noexcept;
    /**
     * Set width of dashes in pixels. Note that dash works only on horizontal and vertical lines.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_line_dash_width
     */
    LocalStyle& line_dash_width(int32_t value) noexcept;
    /**
     * Set gap between dashes in pixels. Note that dash works only on horizontal and
     * vertical lines.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_line_dash_gap
     */
    LocalStyle& line_dash_gap(int32_t value) noexcept;
    /**
     * Make end points of the lines rounded. `true`: rounded, `false`: perpendicular line ending.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_line_rounded
     */
    LocalStyle& line_rounded(bool value) noexcept;
    /**
     * Set color of lines.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_line_color
     */
    LocalStyle& line_color(Color value) noexcept;
    /**
     * Set opacity of lines.
     * Default: `LV_OPA_COVER`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_line_opa
     */
    LocalStyle& line_opa(lv_opa_t value) noexcept;
    /**
     * Set width (thickness) of arcs in pixels.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_arc_width
     */
    LocalStyle& arc_width(int32_t value) noexcept;
    /**
     * Make end points of arcs rounded. `true`: rounded, `false`: perpendicular line ending.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_arc_rounded
     */
    LocalStyle& arc_rounded(bool value) noexcept;
    /**
     * Set color of arc.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_arc_color
     */
    LocalStyle& arc_color(Color value) noexcept;
    /**
     * Set opacity of arcs.
     * Default: `LV_OPA_COVER`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_arc_opa
     */
    LocalStyle& arc_opa(lv_opa_t value) noexcept;
    /**
     * Set an image from which arc will be masked out. It's useful to display complex
     * effects on the arcs. Can be a pointer to `lv_image_dsc_t` or a path to a file.
     * Default: `NULL`, inherited: No, layout: No, ext. draw: No.
     * @param value  Pointer to image source
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_arc_image_src
     */
    LocalStyle& arc_image_src(const void* value) noexcept;
    /**
     * Sets color of text.
     * Default: `0x000000`, inherited: Yes, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_text_color
     */
    LocalStyle& text_color(Color value) noexcept;
    /**
     * Set opacity of text. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means fully
     * transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means fully covering, other values
     * or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: Yes, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_text_opa
     */
    LocalStyle& text_opa(lv_opa_t value) noexcept;
    /**
     * Set font of text (a pointer `lv_font_t *`).
     * Default: `LV_FONT_DEFAULT`, inherited: Yes, layout: Yes, ext. draw: No.
     * @param value  Pointer to font
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_text_font
     */
    LocalStyle& text_font(Font value) noexcept;
    /**
     * Set letter space in pixels.
     * Default: 0, inherited: Yes, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_text_letter_space
     */
    LocalStyle& text_letter_space(int32_t value) noexcept;
    /**
     * Set line space in pixels.
     * Default: 0, inherited: Yes, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_text_line_space
     */
    LocalStyle& text_line_space(int32_t value) noexcept;
    /**
     * Set decoration for the text. Possible values are
     * `LV_TEXT_DECOR_NONE/UNDERLINE/STRIKETHROUGH`. OR-ed values can be used as well.
     * Default: `LV_TEXT_DECOR_NONE`, inherited: Yes, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_text_decor
     */
    LocalStyle& text_decor(TextDecor value) noexcept;
    /**
     * Set how to align the lines of the text. Note that it doesn't align the Widget
     * itself, only the lines inside the Widget. Possible values are
     * `LV_TEXT_ALIGN_LEFT/CENTER/RIGHT/AUTO`. `LV_TEXT_ALIGN_AUTO` detect the text base
     * direction and uses left or right alignment accordingly.
     * Default: `LV_TEXT_ALIGN_AUTO`, inherited: Yes, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_text_align
     */
    LocalStyle& text_align(TextAlign value) noexcept;
    /**
     * Sets the color of letter outline stroke.
     * Default: `0x000000`, inherited: Yes, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_text_outline_stroke_color
     */
    LocalStyle& text_outline_stroke_color(Color value) noexcept;
    /**
     * Set the letter outline stroke width in pixels.
     * Default: 0, inherited: Yes, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_text_outline_stroke_width
     */
    LocalStyle& text_outline_stroke_width(int32_t value) noexcept;
    /**
     * Set the opacity of the letter outline stroke. Value 0, `LV_OPA_0` or
     * `LV_OPA_TRANSP` means fully transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means
     * fully covering, other values or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: Yes, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_text_outline_stroke_opa
     */
    LocalStyle& text_outline_stroke_opa(lv_opa_t value) noexcept;
    /**
     * Sets the intensity of blurring. Applied on each lv_part separately before the
     * children are rendered.
     * Default: `0`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_blur_radius
     */
    LocalStyle& blur_radius(int32_t value) noexcept;
    /**
     * If `true` the background of the widget will be blurred. The part should have < 100%
     * opacity to make it visible. If `false` the given part will be blurred when it's
     * rendered but before drawing the children.
     * Default: `false`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_blur_backdrop
     */
    LocalStyle& blur_backdrop(bool value) noexcept;
    /**
     * Setting to `LV_BLUR_QUALITY_SPEED` the blurring algorithm will prefer speed over
     * quality. `LV_BLUR_QUALITY_PRECISION` will force using higher quality but slower
     * blur. With `LV_BLUR_QUALITY_AUTO` the quality will be selected automatically.
     * Default: `LV_BLUR_QUALITY_AUTO`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_blur_quality
     */
    LocalStyle& blur_quality(BlurQuality value) noexcept;
    /**
     * Sets the intensity of blurring. Applied on each lv_part separately before the
     * children are rendered.
     * Default: `0`, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_drop_shadow_radius
     */
    LocalStyle& drop_shadow_radius(int32_t value) noexcept;
    /**
     * Set an offset on the shadow in pixels in X direction.
     * Default: `0`, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_drop_shadow_offset_x
     */
    LocalStyle& drop_shadow_offset_x(int32_t value) noexcept;
    /**
     * Set an offset on the shadow in pixels in Y direction.
     * Default: `0`, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_drop_shadow_offset_y
     */
    LocalStyle& drop_shadow_offset_y(int32_t value) noexcept;
    /**
     * Set the color of the shadow.
     * Default: `0`, inherited: No, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_drop_shadow_color
     */
    LocalStyle& drop_shadow_color(Color value) noexcept;
    /**
     * Set the opacity of the shadow.
     * Default: `0`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_drop_shadow_opa
     */
    LocalStyle& drop_shadow_opa(lv_opa_t value) noexcept;
    /**
     * Setting to `LV_BLUR_QUALITY_SPEED` the blurring algorithm will prefer speed over
     * quality. `LV_BLUR_QUALITY_PRECISION` will force using higher quality but slower
     * blur. With `LV_BLUR_QUALITY_AUTO` the quality will be selected automatically.
     * Default: `LV_BLUR_QUALITY_PRECISION`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_drop_shadow_quality
     */
    LocalStyle& drop_shadow_quality(BlurQuality value) noexcept;
    /**
     * Set radius on every corner. The value is interpreted in pixels (>= 0) or
     * `LV_RADIUS_CIRCLE` for max radius.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_radius
     */
    LocalStyle& radius(int32_t value) noexcept;
    /**
     * Move start point of object (e.g. scale tick) radially.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_radial_offset
     */
    LocalStyle& radial_offset(int32_t value) noexcept;
    /**
     * Enable clipping of content that overflows rounded corners of parent Widget. Can be
     * `true` or `false`.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_clip_corner
     */
    LocalStyle& clip_corner(bool value) noexcept;
    /**
     * Scale down all opacity values of the Widget by this factor. Value 0, `LV_OPA_0` or
     * `LV_OPA_TRANSP` means fully transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means
     * fully covering, other values or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: Yes, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_opa
     */
    LocalStyle& opa(lv_opa_t value) noexcept;
    /**
     * First draw Widget on the layer, then scale down layer opacity factor. Value 0,
     * `LV_OPA_0` or `LV_OPA_TRANSP` means fully transparent, 255, `LV_OPA_100` or
     * `LV_OPA_COVER` means fully covering, other values or LV_OPA_10, LV_OPA_20, etc
     * means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: Yes, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_opa_layered
     */
    LocalStyle& opa_layered(lv_opa_t value) noexcept;
    /**
     * Mix a color with all colors of the Widget.
     * Default: `NULL`, inherited: No, layout: No, ext. draw: No.
     * @param value  Pointer to color-filter descriptor
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_color_filter_dsc
     */
    LocalStyle& color_filter_dsc(ColorFilterDsc& value) noexcept;
    /**
     * The intensity of mixing of color filter.
     * Default: `LV_OPA_TRANSP`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_color_filter_opa
     */
    LocalStyle& color_filter_opa(lv_opa_t value) noexcept;
    /**
     * Set a color to mix to the obj.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_recolor
     */
    LocalStyle& recolor(Color value) noexcept;
    /**
     * Sets the intensity of color mixing. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means
     * fully transparent. A value of  255, `LV_OPA_100` or `LV_OPA_COVER` means fully
     * opaque. Intermediate values like LV_OPA_10, LV_OPA_20, etc result in
     * semi-transparency.
     * Default: `LV_OPA_TRANSP`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_recolor_opa
     */
    LocalStyle& recolor_opa(lv_opa_t value) noexcept;
    /**
     * Animation template for Widget's animation. Should be a pointer to `lv_anim_t`. The
     * animation parameters are widget specific, e.g. animation time could be the E.g.
     * blink time of the cursor on the Text Area or scroll time of a roller. See Widgets'
     * documentation to learn more.
     * Default: `NULL`, inherited: No, layout: No, ext. draw: No.
     * @param value  Pointer to animation descriptor
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_anim
     */
    LocalStyle& anim(Anim& value) noexcept;
    /**
     * Animation duration in milliseconds. Its meaning is widget specific. E.g. blink time
     * of the cursor on the Text Area or scroll time of a roller. See Widgets'
     * documentation to learn more.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_anim_duration
     */
    LocalStyle& anim_duration(uint32_t value) noexcept;
    /**
     * An initialized ``lv_style_transition_dsc_t`` to describe a transition.
     * Default: `NULL`, inherited: No, layout: No, ext. draw: No.
     * @param value  Pointer to transition descriptor
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_transition
     */
    LocalStyle& transition(StyleTransitionDsc& value) noexcept;
    /**
     * Describes how to blend the colors to the background. Possible values are
     * `LV_BLEND_MODE_NORMAL/ADDITIVE/SUBTRACTIVE/MULTIPLY/DIFFERENCE`.
     * Default: `LV_BLEND_MODE_NORMAL`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_blend_mode
     */
    LocalStyle& blend_mode(BlendMode value) noexcept;
    /**
     * Set layout of Widget. Children will be repositioned and resized according to
     * policies set for the layout. For possible values see documentation of the layouts.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_layout
     */
    LocalStyle& layout(uint16_t value) noexcept;
    /**
     * Set base direction of Widget. Possible values are `LV_BIDI_DIR_LTR/RTL/AUTO`.
     * Default: `LV_BASE_DIR_AUTO`, inherited: Yes, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_base_dir
     */
    LocalStyle& base_dir(BaseDir value) noexcept;
    /**
     * If set, a layer will be created for the widget and the layer will be masked with
     * this A8 bitmap mask.
     * Default: `NULL`, inherited: No, layout: No, ext. draw: No.
     * @param value  Pointer to A8 bitmap mask
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_bitmap_mask_src
     */
    LocalStyle& bitmap_mask_src(const void* value) noexcept;
    /**
     * Adjust sensitivity for rotary encoders in 1/256 unit. It means, 128: slow down the
     * rotary to half, 512: speeds up to double, 256: no change.
     * Default: `256`, inherited: Yes, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_rotary_sensitivity
     */
    LocalStyle& rotary_sensitivity(uint32_t value) noexcept;
    #if LV_USE_FLEX
    /**
     * Defines in which direction the flex layout should arrange the children.
     * Default: `LV_FLEX_FLOW_NONE`, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_flex_flow
     */
    LocalStyle& flex_flow(FlexFlow value) noexcept;
    /**
     * Defines how to align the children in the direction of flex flow.
     * Default: `LV_FLEX_ALIGN_NONE`, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_flex_main_place
     */
    LocalStyle& flex_main_place(FlexAlign value) noexcept;
    /**
     * Defines how to align the children perpendicular to the direction of flex flow.
     * Default: `LV_FLEX_ALIGN_NONE`, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_flex_cross_place
     */
    LocalStyle& flex_cross_place(FlexAlign value) noexcept;
    /**
     * Defines how to align the tracks of the flow.
     * Default: `LV_FLEX_ALIGN_NONE`, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_flex_track_place
     */
    LocalStyle& flex_track_place(FlexAlign value) noexcept;
    /**
     * Defines how much space to take proportionally from the free space of the Widget's track.
     * Default: `0`, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_flex_grow
     */
    LocalStyle& flex_grow(uint8_t value) noexcept;
    #endif // LV_USE_FLEX

    #if LV_USE_GRID
    /**
     * LVGL keeps this pointer and reads until it finds LV_GRID_TEMPLATE_LAST: the type writes the sentinel, and the rvalue overload is deleted so it cannot be a temporary.
     * An array to describe the columns of the grid. Should be LV_GRID_TEMPLATE_LAST terminated.
     * Default: `NULL`, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Pointer to grid-column descriptor array
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_grid_column_dsc_array
     */
    template <std::size_t N1>
    LocalStyle& grid_column_dsc_array(const GridTemplate<N1>& value) noexcept;
    /** Refused: LVGL keeps the pointer, so this argument may not be a temporary. */
    template <std::size_t N1>
    LocalStyle& grid_column_dsc_array(GridTemplate<N1>&& value) noexcept = delete;
    /**
     * Defines how to distribute the columns.
     * Default: `LV_GRID_ALIGN_START`, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_grid_column_align
     */
    LocalStyle& grid_column_align(GridAlign value) noexcept;
    /**
     * LVGL keeps this pointer and reads until it finds LV_GRID_TEMPLATE_LAST: the type writes the sentinel, and the rvalue overload is deleted so it cannot be a temporary.
     * An array to describe the rows of the grid. Should be LV_GRID_TEMPLATE_LAST terminated.
     * Default: `NULL`, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Pointer to grid-row descriptor array
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_grid_row_dsc_array
     */
    template <std::size_t N1>
    LocalStyle& grid_row_dsc_array(const GridTemplate<N1>& value) noexcept;
    /** Refused: LVGL keeps the pointer, so this argument may not be a temporary. */
    template <std::size_t N1>
    LocalStyle& grid_row_dsc_array(GridTemplate<N1>&& value) noexcept = delete;
    /**
     * Defines how to distribute the rows.
     * Default: `LV_GRID_ALIGN_START`, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_grid_row_align
     */
    LocalStyle& grid_row_align(GridAlign value) noexcept;
    /**
     * Set column in which Widget should be placed.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_grid_cell_column_pos
     */
    LocalStyle& grid_cell_column_pos(int32_t value) noexcept;
    /**
     * Set how to align Widget horizontally.
     * Default: `LV_GRID_ALIGN_START`, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_grid_cell_x_align
     */
    LocalStyle& grid_cell_x_align(GridAlign value) noexcept;
    /**
     * Set how many columns Widget should span. Needs to be >= 1.
     * Default: 1, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_grid_cell_column_span
     */
    LocalStyle& grid_cell_column_span(int32_t value) noexcept;
    /**
     * Set row in which Widget should be placed.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_grid_cell_row_pos
     */
    LocalStyle& grid_cell_row_pos(int32_t value) noexcept;
    /**
     * Set how to align Widget vertically.
     * Default: `LV_GRID_ALIGN_START`, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_grid_cell_y_align
     */
    LocalStyle& grid_cell_y_align(GridAlign value) noexcept;
    /**
     * Set how many rows Widget should span. Needs to be >= 1.
     * Default: 1, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @param selector  A joint type for `lv_part_t` and `lv_state_t`. Example values: - `0`: means `LV_PART_MAIN | LV_STATE_DEFAULT` - `LV_STATE_PRESSED` - `LV_PART_KNOB` - `LV_PART_KNOB | LV_STATE_PRESSED | LV_STATE_CHECKED`
     * @see lv_obj_set_style_grid_cell_row_span
     */
    LocalStyle& grid_cell_row_span(int32_t value) noexcept;
    #endif // LV_USE_GRID

};
static_assert(sizeof(LocalStyle) <= 2 * sizeof(void*));

/**
 * A standalone lv_style_t.
 * LVGL stores the ADDRESS, not a copy, so this must never move and must
 * outlive every object that references it: not copyable, not movable.
 */
class Style {
protected:
    lv_style_t s_;

public:
    Style() noexcept { lv_style_init(&s_); }
    ~Style() { lv_style_reset(&s_); }

    Style(const Style&) = delete;
    Style& operator=(const Style&) = delete;
    Style(Style&&) = delete;
    Style& operator=(Style&&) = delete;

    lv_style_t* raw() noexcept { return &s_; }

    /**
     * Set the value of property in a style.
     * This function shouldn't be used directly by the user.
     * Instead use `lv_style_set_<prop_name>()`. E.g. `lv_style_set_bg_color()`
     * @param prop  the ID of a property (e.g. `LV_STYLE_BG_COLOR`)
     * @param value  `lv_style_value_t` variable in which a field is set according to the type of `prop`
     * @see lv_style_set_prop
     */
    Style& prop(lv_style_prop_t prop, lv_style_value_t value) noexcept;
    /**
     * Set all 4 of `style`s padding values.
     * @param value  padding dimension in pixels
     * @see lv_style_set_pad_all
     */
    Style& pad_all(int32_t value) noexcept;
    /**
     * Set `style`s left and right padding values.
     * @param value  padding dimension in pixels
     * @see lv_style_set_pad_hor
     */
    Style& pad_hor(int32_t value) noexcept;
    /**
     * Set `style`s top and bottom padding values.
     * @param value  padding dimension in pixels
     * @see lv_style_set_pad_ver
     */
    Style& pad_ver(int32_t value) noexcept;
    /**
     * Set all 4 of `style`s margin values.
     * @param value  margin dimension in pixels
     * @see lv_style_set_margin_all
     */
    Style& margin_all(int32_t value) noexcept;
    /**
     * Set `style`s left and right margin values.
     * @param value  margin dimension in pixels
     * @see lv_style_set_margin_hor
     */
    Style& margin_hor(int32_t value) noexcept;
    /**
     * Set `style`s top and bottom margin values.
     * @param value  margin dimension in pixels
     * @see lv_style_set_margin_ver
     */
    Style& margin_ver(int32_t value) noexcept;
    /**
     * Set `style`s row and column padding gaps (applies only to Grid and Flex layouts).
     * @param value  gap dimension in pixels
     * @see lv_style_set_pad_gap
     */
    Style& pad_gap(int32_t value) noexcept;
    /**
     * Set `style`s width and height.
     * @param width  width in pixels
     * @param height  height in pixels
     * @see lv_style_set_size
     */
    Style& size(int32_t width, int32_t height) noexcept;
    /**
     * Set `style`s X and Y transform scale values.
     * @param value  scale factor. Example values: - 256 or LV_SCALE_NONE: no zoom - <256: scale down - >256: scale up - 128: half size - 512: double size
     * @see lv_style_set_transform_scale
     */
    Style& transform_scale(int32_t value) noexcept;
    /**
     * Sets width of Widget. Pixel, percentage and `LV_SIZE_CONTENT` values can be used.
     * Percentage values are relative to the width of the parent's content area.
     * Default: Widget dependent, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_width
     */
    Style& width(int32_t value) noexcept;
    /**
     * Sets a minimal width. Pixel and percentage values can be used. Percentage values
     * are relative to the width of the parent's content area.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_min_width
     */
    Style& min_width(int32_t value) noexcept;
    /**
     * Sets a maximal width. Pixel and percentage values can be used. Percentage values
     * are relative to the width of the parent's content area.
     * Default: LV_COORD_MAX, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_max_width
     */
    Style& max_width(int32_t value) noexcept;
    /**
     * Sets height of Widget. Pixel, percentage and `LV_SIZE_CONTENT` can be used.
     * Percentage values are relative to the height of the parent's content area.
     * Default: Widget dependent, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_height
     */
    Style& height(int32_t value) noexcept;
    /**
     * Sets a minimal height. Pixel and percentage values can be used. Percentage values
     * are relative to the height of the parent's content area.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_min_height
     */
    Style& min_height(int32_t value) noexcept;
    /**
     * Sets a maximal height. Pixel and percentage values can be used. Percentage values
     * are relative to the height of the parent's content area.
     * Default: LV_COORD_MAX, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_max_height
     */
    Style& max_height(int32_t value) noexcept;
    /**
     * Its meaning depends on the type of Widget. For example in case of lv_scale it means
     * the length of the ticks.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @see lv_style_set_length
     */
    Style& length(int32_t value) noexcept;
    /**
     * Set X coordinate of Widget considering the ``align`` setting. Pixel and percentage
     * values can be used. Percentage values are relative to the width of the parent's
     * content area.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_x
     */
    Style& x(int32_t value) noexcept;
    /**
     * Set Y coordinate of Widget considering the ``align`` setting. Pixel and percentage
     * values can be used. Percentage values are relative to the height of the parent's
     * content area.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_y
     */
    Style& y(int32_t value) noexcept;
    /**
     * Set the alignment which tells from which point of the parent the X and Y
     * coordinates should be interpreted. Possible values are: `LV_ALIGN_DEFAULT`,
     * `LV_ALIGN_TOP_LEFT/MID/RIGHT`, `LV_ALIGN_BOTTOM_LEFT/MID/RIGHT`,
     * `LV_ALIGN_LEFT/RIGHT_MID`, `LV_ALIGN_CENTER`. `LV_ALIGN_DEFAULT` means
     * `LV_ALIGN_TOP_LEFT` with LTR base direction and `LV_ALIGN_TOP_RIGHT` with RTL base
     * direction.
     * Default: `LV_ALIGN_DEFAULT`, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_align
     */
    Style& align(Align value) noexcept;
    /**
     * Make Widget wider on both sides with this value. Pixel and percentage (with
     * `lv_pct(x)`) values can be used. Percentage values are relative to Widget's width.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @see lv_style_set_transform_width
     */
    Style& transform_width(int32_t value) noexcept;
    /**
     * Make Widget higher on both sides with this value. Pixel and percentage (with
     * `lv_pct(x)`) values can be used. Percentage values are relative to Widget's height.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @see lv_style_set_transform_height
     */
    Style& transform_height(int32_t value) noexcept;
    /**
     * Move Widget with this value in X direction. Applied after layouts, aligns and other
     * positioning. Pixel and percentage (with `lv_pct(x)`) values can be used. Percentage
     * values are relative to Widget's width.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_translate_x
     */
    Style& translate_x(int32_t value) noexcept;
    /**
     * Move Widget with this value in Y direction. Applied after layouts, aligns and other
     * positioning. Pixel and percentage (with `lv_pct(x)`) values can be used. Percentage
     * values are relative to Widget's height.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_translate_y
     */
    Style& translate_y(int32_t value) noexcept;
    /**
     * Move object around the centre of the parent object (e.g. around the circumference
     * of a scale).
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_translate_radial
     */
    Style& translate_radial(int32_t value) noexcept;
    /**
     * Zoom Widget horizontally. The value 256 (or `LV_SCALE_NONE`) means normal size, 128
     * half size, 512 double size, and so on.
     * Default: 0, inherited: No, layout: Yes, ext. draw: Yes.
     * @param value  Value to submit
     * @see lv_style_set_transform_scale_x
     */
    Style& transform_scale_x(int32_t value) noexcept;
    /**
     * Zoom Widget vertically. The value 256 (or `LV_SCALE_NONE`) means normal size, 128
     * half size, 512 double size, and so on.
     * Default: 0, inherited: No, layout: Yes, ext. draw: Yes.
     * @param value  Value to submit
     * @see lv_style_set_transform_scale_y
     */
    Style& transform_scale_y(int32_t value) noexcept;
    /**
     * Rotate Widget. The value is interpreted in 0.1 degree units. E.g. 450 means 45 deg.
     * Default: 0, inherited: No, layout: Yes, ext. draw: Yes.
     * @param value  Value to submit
     * @see lv_style_set_transform_rotation
     */
    Style& transform_rotation(int32_t value) noexcept;
    /**
     * Set pivot point's X coordinate for transformations. Relative to Widget's top left corner.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_transform_pivot_x
     */
    Style& transform_pivot_x(int32_t value) noexcept;
    /**
     * Set pivot point's Y coordinate for transformations. Relative to Widget's top left corner.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_transform_pivot_y
     */
    Style& transform_pivot_y(int32_t value) noexcept;
    /**
     * Skew Widget horizontally. The value is interpreted in 0.1 degree units. E.g. 450
     * means 45 deg.
     * Default: 0, inherited: No, layout: Yes, ext. draw: Yes.
     * @param value  Value to submit
     * @see lv_style_set_transform_skew_x
     */
    Style& transform_skew_x(int32_t value) noexcept;
    /**
     * Skew Widget vertically. The value is interpreted in 0.1 degree units. E.g. 450
     * means 45 deg.
     * Default: 0, inherited: No, layout: Yes, ext. draw: Yes.
     * @param value  Value to submit
     * @see lv_style_set_transform_skew_y
     */
    Style& transform_skew_y(int32_t value) noexcept;
    /**
     * Sets the padding on the top. It makes the content area smaller in this direction.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_pad_top
     */
    Style& pad_top(int32_t value) noexcept;
    /**
     * Sets the padding on the bottom. It makes the content area smaller in this direction.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_pad_bottom
     */
    Style& pad_bottom(int32_t value) noexcept;
    /**
     * Sets the padding on the left. It makes the content area smaller in this direction.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_pad_left
     */
    Style& pad_left(int32_t value) noexcept;
    /**
     * Sets the padding on the right. It makes the content area smaller in this direction.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_pad_right
     */
    Style& pad_right(int32_t value) noexcept;
    /**
     * Sets the padding between the rows. Used by the layouts.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_pad_row
     */
    Style& pad_row(int32_t value) noexcept;
    /**
     * Sets the padding between the columns. Used by the layouts.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_pad_column
     */
    Style& pad_column(int32_t value) noexcept;
    /**
     * Pad text labels away from the scale ticks/remainder of the ``LV_PART_``.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_pad_radial
     */
    Style& pad_radial(int32_t value) noexcept;
    /**
     * Sets margin on the top. Widget will keep this space from its siblings in layouts.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_margin_top
     */
    Style& margin_top(int32_t value) noexcept;
    /**
     * Sets margin on the bottom. Widget will keep this space from its siblings in layouts.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_margin_bottom
     */
    Style& margin_bottom(int32_t value) noexcept;
    /**
     * Sets margin on the left. Widget will keep this space from its siblings in layouts.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_margin_left
     */
    Style& margin_left(int32_t value) noexcept;
    /**
     * Sets margin on the right. Widget will keep this space from its siblings in layouts.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_margin_right
     */
    Style& margin_right(int32_t value) noexcept;
    /**
     * Set background color of Widget.
     * Default: `0xffffff`, inherited: No, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @see lv_style_set_bg_color
     */
    Style& bg_color(Color value) noexcept;
    /**
     * Set opacity of the background. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means fully
     * transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means fully covering, other values
     * or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_TRANSP`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_bg_opa
     */
    Style& bg_opa(lv_opa_t value) noexcept;
    /**
     * Set gradient color of the background. Used only if `grad_dir` is not `LV_GRAD_DIR_NONE`.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @see lv_style_set_bg_grad_color
     */
    Style& bg_grad_color(Color value) noexcept;
    /**
     * Set direction of the gradient of the background. Possible values are
     * `LV_GRAD_DIR_NONE/HOR/VER`.
     * Default: `LV_GRAD_DIR_NONE`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_bg_grad_dir
     */
    Style& bg_grad_dir(GradDir value) noexcept;
    /**
     * Set point from which background color should start for gradients. 0 means to
     * top/left side, 255 the bottom/right side, 128 the center, and so on.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_bg_main_stop
     */
    Style& bg_main_stop(int32_t value) noexcept;
    /**
     * Set point from which background's gradient color should start. 0 means to top/left
     * side, 255 the bottom/right side, 128 the center, and so on.
     * Default: 255, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_bg_grad_stop
     */
    Style& bg_grad_stop(int32_t value) noexcept;
    /**
     * Set opacity of the first gradient color.
     * Default: 255, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_bg_main_opa
     */
    Style& bg_main_opa(lv_opa_t value) noexcept;
    /**
     * Set opacity of the second gradient color.
     * Default: 255, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_bg_grad_opa
     */
    Style& bg_grad_opa(lv_opa_t value) noexcept;
    /**
     * Set gradient definition. The pointed instance must exist while Widget is alive.
     * NULL to disable. It wraps `BG_GRAD_COLOR`, `BG_GRAD_DIR`, `BG_MAIN_STOP` and
     * `BG_GRAD_STOP` into one descriptor and allows creating gradients with more colors
     * as well. If it's set other gradient related properties will be ignored.
     * Default: `NULL`, inherited: No, layout: No, ext. draw: No.
     * @param value  Pointer to gradient descriptor
     * @see lv_style_set_bg_grad
     */
    Style& bg_grad(const lv_grad_dsc_t* value) noexcept;
    /**
     * Set a background image. Can be a pointer to `lv_image_dsc_t`, a path to a file or
     * an `LV_SYMBOL_...`.
     * Default: `NULL`, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Pointer to image source
     * @see lv_style_set_bg_image_src
     */
    Style& bg_image_src(const void* value) noexcept;
    /**
     * Set opacity of the background image. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means
     * fully transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means fully covering, other
     * values or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_bg_image_opa
     */
    Style& bg_image_opa(lv_opa_t value) noexcept;
    /**
     * Set a color to mix to the background image.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @see lv_style_set_bg_image_recolor
     */
    Style& bg_image_recolor(Color value) noexcept;
    /**
     * Set intensity of background image recoloring. Value 0, `LV_OPA_0` or
     * `LV_OPA_TRANSP` means no mixing, 255, `LV_OPA_100` or `LV_OPA_COVER` means full
     * recoloring, other values or LV_OPA_10, LV_OPA_20, etc are interpreted
     * proportionally.
     * Default: `LV_OPA_TRANSP`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_bg_image_recolor_opa
     */
    Style& bg_image_recolor_opa(lv_opa_t value) noexcept;
    /**
     * If enabled the background image will be tiled. Possible values are `true` or `false`.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_bg_image_tiled
     */
    Style& bg_image_tiled(bool value) noexcept;
    /**
     * Set color of the border.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @see lv_style_set_border_color
     */
    Style& border_color(Color value) noexcept;
    /**
     * Set opacity of the border. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means fully
     * transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means fully covering, other values
     * or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_border_opa
     */
    Style& border_opa(lv_opa_t value) noexcept;
    /**
     * Set width of the border. Only pixel values can be used.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_border_width
     */
    Style& border_width(int32_t value) noexcept;
    /**
     * Set only which side(s) the border should be drawn. Possible values are
     * `LV_BORDER_SIDE_NONE/TOP/BOTTOM/LEFT/RIGHT/INTERNAL`. OR-ed values can be used as
     * well, e.g. `LV_BORDER_SIDE_TOP | LV_BORDER_SIDE_LEFT`.
     * Default: `LV_BORDER_SIDE_FULL`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_border_side
     */
    Style& border_side(BorderSide value) noexcept;
    /**
     * Sets whether the border should be drawn before or after the children are drawn.
     * `true`: after children, `false`: before children.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_border_post
     */
    Style& border_post(bool value) noexcept;
    /**
     * Set width of outline in pixels.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @see lv_style_set_outline_width
     */
    Style& outline_width(int32_t value) noexcept;
    /**
     * Set color of outline.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @see lv_style_set_outline_color
     */
    Style& outline_color(Color value) noexcept;
    /**
     * Set opacity of outline. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means fully
     * transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means fully covering, other values
     * or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @see lv_style_set_outline_opa
     */
    Style& outline_opa(lv_opa_t value) noexcept;
    /**
     * Set padding of outline, i.e. the gap between Widget and the outline.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @see lv_style_set_outline_pad
     */
    Style& outline_pad(int32_t value) noexcept;
    /**
     * Set width of the shadow in pixels. The value should be >= 0.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @see lv_style_set_shadow_width
     */
    Style& shadow_width(int32_t value) noexcept;
    /**
     * Set an offset on the shadow in pixels in X direction.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @see lv_style_set_shadow_offset_x
     */
    Style& shadow_offset_x(int32_t value) noexcept;
    /**
     * Set an offset on the shadow in pixels in Y direction.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @see lv_style_set_shadow_offset_y
     */
    Style& shadow_offset_y(int32_t value) noexcept;
    /**
     * Make shadow calculation to use a larger or smaller rectangle as base. The value can
     * be in pixels to make the area larger/smaller.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @see lv_style_set_shadow_spread
     */
    Style& shadow_spread(int32_t value) noexcept;
    /**
     * Set color of shadow.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @see lv_style_set_shadow_color
     */
    Style& shadow_color(Color value) noexcept;
    /**
     * Set opacity of shadow. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means fully
     * transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means fully covering, other values
     * or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @see lv_style_set_shadow_opa
     */
    Style& shadow_opa(lv_opa_t value) noexcept;
    /**
     * Set opacity of an image. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means fully
     * transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means fully covering, other values
     * or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_image_opa
     */
    Style& image_opa(lv_opa_t value) noexcept;
    /**
     * Set color to mix with the image.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @see lv_style_set_image_recolor
     */
    Style& image_recolor(Color value) noexcept;
    /**
     * Set intensity of color mixing. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means fully
     * transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means fully covering, other values
     * or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_image_recolor_opa
     */
    Style& image_recolor_opa(lv_opa_t value) noexcept;
    /**
     * Set image colorkey definition. The lv_image_colorkey_t contains two color values:
     * `high_color` and `low_color`. the color of pixels ranging from `low_color` to
     * `high_color` will be transparent.
     * Default: `NULL`, inherited: No, layout: No, ext. draw: No.
     * @param value  Pointer to image color key
     * @see lv_style_set_image_colorkey
     */
    Style& image_colorkey(const lv_image_colorkey_t* value) noexcept;
    /**
     * Set width of lines in pixels.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @see lv_style_set_line_width
     */
    Style& line_width(int32_t value) noexcept;
    /**
     * Set width of dashes in pixels. Note that dash works only on horizontal and vertical lines.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_line_dash_width
     */
    Style& line_dash_width(int32_t value) noexcept;
    /**
     * Set gap between dashes in pixels. Note that dash works only on horizontal and
     * vertical lines.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_line_dash_gap
     */
    Style& line_dash_gap(int32_t value) noexcept;
    /**
     * Make end points of the lines rounded. `true`: rounded, `false`: perpendicular line ending.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_line_rounded
     */
    Style& line_rounded(bool value) noexcept;
    /**
     * Set color of lines.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @see lv_style_set_line_color
     */
    Style& line_color(Color value) noexcept;
    /**
     * Set opacity of lines.
     * Default: `LV_OPA_COVER`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_line_opa
     */
    Style& line_opa(lv_opa_t value) noexcept;
    /**
     * Set width (thickness) of arcs in pixels.
     * Default: 0, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @see lv_style_set_arc_width
     */
    Style& arc_width(int32_t value) noexcept;
    /**
     * Make end points of arcs rounded. `true`: rounded, `false`: perpendicular line ending.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_arc_rounded
     */
    Style& arc_rounded(bool value) noexcept;
    /**
     * Set color of arc.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @see lv_style_set_arc_color
     */
    Style& arc_color(Color value) noexcept;
    /**
     * Set opacity of arcs.
     * Default: `LV_OPA_COVER`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_arc_opa
     */
    Style& arc_opa(lv_opa_t value) noexcept;
    /**
     * Set an image from which arc will be masked out. It's useful to display complex
     * effects on the arcs. Can be a pointer to `lv_image_dsc_t` or a path to a file.
     * Default: `NULL`, inherited: No, layout: No, ext. draw: No.
     * @param value  Pointer to image source
     * @see lv_style_set_arc_image_src
     */
    Style& arc_image_src(const void* value) noexcept;
    /**
     * Sets color of text.
     * Default: `0x000000`, inherited: Yes, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @see lv_style_set_text_color
     */
    Style& text_color(Color value) noexcept;
    /**
     * Set opacity of text. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means fully
     * transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means fully covering, other values
     * or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: Yes, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_text_opa
     */
    Style& text_opa(lv_opa_t value) noexcept;
    /**
     * Set font of text (a pointer `lv_font_t *`).
     * Default: `LV_FONT_DEFAULT`, inherited: Yes, layout: Yes, ext. draw: No.
     * @param value  Pointer to font
     * @see lv_style_set_text_font
     */
    Style& text_font(Font value) noexcept;
    /**
     * Set letter space in pixels.
     * Default: 0, inherited: Yes, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_text_letter_space
     */
    Style& text_letter_space(int32_t value) noexcept;
    /**
     * Set line space in pixels.
     * Default: 0, inherited: Yes, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_text_line_space
     */
    Style& text_line_space(int32_t value) noexcept;
    /**
     * Set decoration for the text. Possible values are
     * `LV_TEXT_DECOR_NONE/UNDERLINE/STRIKETHROUGH`. OR-ed values can be used as well.
     * Default: `LV_TEXT_DECOR_NONE`, inherited: Yes, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_text_decor
     */
    Style& text_decor(TextDecor value) noexcept;
    /**
     * Set how to align the lines of the text. Note that it doesn't align the Widget
     * itself, only the lines inside the Widget. Possible values are
     * `LV_TEXT_ALIGN_LEFT/CENTER/RIGHT/AUTO`. `LV_TEXT_ALIGN_AUTO` detect the text base
     * direction and uses left or right alignment accordingly.
     * Default: `LV_TEXT_ALIGN_AUTO`, inherited: Yes, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_text_align
     */
    Style& text_align(TextAlign value) noexcept;
    /**
     * Sets the color of letter outline stroke.
     * Default: `0x000000`, inherited: Yes, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @see lv_style_set_text_outline_stroke_color
     */
    Style& text_outline_stroke_color(Color value) noexcept;
    /**
     * Set the letter outline stroke width in pixels.
     * Default: 0, inherited: Yes, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_text_outline_stroke_width
     */
    Style& text_outline_stroke_width(int32_t value) noexcept;
    /**
     * Set the opacity of the letter outline stroke. Value 0, `LV_OPA_0` or
     * `LV_OPA_TRANSP` means fully transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means
     * fully covering, other values or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: Yes, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_text_outline_stroke_opa
     */
    Style& text_outline_stroke_opa(lv_opa_t value) noexcept;
    /**
     * Sets the intensity of blurring. Applied on each lv_part separately before the
     * children are rendered.
     * Default: `0`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_blur_radius
     */
    Style& blur_radius(int32_t value) noexcept;
    /**
     * If `true` the background of the widget will be blurred. The part should have < 100%
     * opacity to make it visible. If `false` the given part will be blurred when it's
     * rendered but before drawing the children.
     * Default: `false`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_blur_backdrop
     */
    Style& blur_backdrop(bool value) noexcept;
    /**
     * Setting to `LV_BLUR_QUALITY_SPEED` the blurring algorithm will prefer speed over
     * quality. `LV_BLUR_QUALITY_PRECISION` will force using higher quality but slower
     * blur. With `LV_BLUR_QUALITY_AUTO` the quality will be selected automatically.
     * Default: `LV_BLUR_QUALITY_AUTO`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_blur_quality
     */
    Style& blur_quality(BlurQuality value) noexcept;
    /**
     * Sets the intensity of blurring. Applied on each lv_part separately before the
     * children are rendered.
     * Default: `0`, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @see lv_style_set_drop_shadow_radius
     */
    Style& drop_shadow_radius(int32_t value) noexcept;
    /**
     * Set an offset on the shadow in pixels in X direction.
     * Default: `0`, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @see lv_style_set_drop_shadow_offset_x
     */
    Style& drop_shadow_offset_x(int32_t value) noexcept;
    /**
     * Set an offset on the shadow in pixels in Y direction.
     * Default: `0`, inherited: No, layout: No, ext. draw: Yes.
     * @param value  Value to submit
     * @see lv_style_set_drop_shadow_offset_y
     */
    Style& drop_shadow_offset_y(int32_t value) noexcept;
    /**
     * Set the color of the shadow.
     * Default: `0`, inherited: No, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @see lv_style_set_drop_shadow_color
     */
    Style& drop_shadow_color(Color value) noexcept;
    /**
     * Set the opacity of the shadow.
     * Default: `0`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_drop_shadow_opa
     */
    Style& drop_shadow_opa(lv_opa_t value) noexcept;
    /**
     * Setting to `LV_BLUR_QUALITY_SPEED` the blurring algorithm will prefer speed over
     * quality. `LV_BLUR_QUALITY_PRECISION` will force using higher quality but slower
     * blur. With `LV_BLUR_QUALITY_AUTO` the quality will be selected automatically.
     * Default: `LV_BLUR_QUALITY_PRECISION`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_drop_shadow_quality
     */
    Style& drop_shadow_quality(BlurQuality value) noexcept;
    /**
     * Set radius on every corner. The value is interpreted in pixels (>= 0) or
     * `LV_RADIUS_CIRCLE` for max radius.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_radius
     */
    Style& radius(int32_t value) noexcept;
    /**
     * Move start point of object (e.g. scale tick) radially.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_radial_offset
     */
    Style& radial_offset(int32_t value) noexcept;
    /**
     * Enable clipping of content that overflows rounded corners of parent Widget. Can be
     * `true` or `false`.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_clip_corner
     */
    Style& clip_corner(bool value) noexcept;
    /**
     * Scale down all opacity values of the Widget by this factor. Value 0, `LV_OPA_0` or
     * `LV_OPA_TRANSP` means fully transparent, 255, `LV_OPA_100` or `LV_OPA_COVER` means
     * fully covering, other values or LV_OPA_10, LV_OPA_20, etc means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: Yes, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_opa
     */
    Style& opa(lv_opa_t value) noexcept;
    /**
     * First draw Widget on the layer, then scale down layer opacity factor. Value 0,
     * `LV_OPA_0` or `LV_OPA_TRANSP` means fully transparent, 255, `LV_OPA_100` or
     * `LV_OPA_COVER` means fully covering, other values or LV_OPA_10, LV_OPA_20, etc
     * means semi transparency.
     * Default: `LV_OPA_COVER`, inherited: Yes, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_opa_layered
     */
    Style& opa_layered(lv_opa_t value) noexcept;
    /**
     * Mix a color with all colors of the Widget.
     * Default: `NULL`, inherited: No, layout: No, ext. draw: No.
     * @param value  Pointer to color-filter descriptor
     * @see lv_style_set_color_filter_dsc
     */
    Style& color_filter_dsc(ColorFilterDsc& value) noexcept;
    /**
     * The intensity of mixing of color filter.
     * Default: `LV_OPA_TRANSP`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_color_filter_opa
     */
    Style& color_filter_opa(lv_opa_t value) noexcept;
    /**
     * Set a color to mix to the obj.
     * Default: `0x000000`, inherited: No, layout: No, ext. draw: No.
     * @param value  Color to submit
     * @see lv_style_set_recolor
     */
    Style& recolor(Color value) noexcept;
    /**
     * Sets the intensity of color mixing. Value 0, `LV_OPA_0` or `LV_OPA_TRANSP` means
     * fully transparent. A value of  255, `LV_OPA_100` or `LV_OPA_COVER` means fully
     * opaque. Intermediate values like LV_OPA_10, LV_OPA_20, etc result in
     * semi-transparency.
     * Default: `LV_OPA_TRANSP`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_recolor_opa
     */
    Style& recolor_opa(lv_opa_t value) noexcept;
    /**
     * Animation template for Widget's animation. Should be a pointer to `lv_anim_t`. The
     * animation parameters are widget specific, e.g. animation time could be the E.g.
     * blink time of the cursor on the Text Area or scroll time of a roller. See Widgets'
     * documentation to learn more.
     * Default: `NULL`, inherited: No, layout: No, ext. draw: No.
     * @param value  Pointer to animation descriptor
     * @see lv_style_set_anim
     */
    Style& anim(Anim& value) noexcept;
    /**
     * Animation duration in milliseconds. Its meaning is widget specific. E.g. blink time
     * of the cursor on the Text Area or scroll time of a roller. See Widgets'
     * documentation to learn more.
     * Default: 0, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_anim_duration
     */
    Style& anim_duration(uint32_t value) noexcept;
    /**
     * An initialized ``lv_style_transition_dsc_t`` to describe a transition.
     * Default: `NULL`, inherited: No, layout: No, ext. draw: No.
     * @param value  Pointer to transition descriptor
     * @see lv_style_set_transition
     */
    Style& transition(StyleTransitionDsc& value) noexcept;
    /**
     * Describes how to blend the colors to the background. Possible values are
     * `LV_BLEND_MODE_NORMAL/ADDITIVE/SUBTRACTIVE/MULTIPLY/DIFFERENCE`.
     * Default: `LV_BLEND_MODE_NORMAL`, inherited: No, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_blend_mode
     */
    Style& blend_mode(BlendMode value) noexcept;
    /**
     * Set layout of Widget. Children will be repositioned and resized according to
     * policies set for the layout. For possible values see documentation of the layouts.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_layout
     */
    Style& layout(uint16_t value) noexcept;
    /**
     * Set base direction of Widget. Possible values are `LV_BIDI_DIR_LTR/RTL/AUTO`.
     * Default: `LV_BASE_DIR_AUTO`, inherited: Yes, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_base_dir
     */
    Style& base_dir(BaseDir value) noexcept;
    /**
     * If set, a layer will be created for the widget and the layer will be masked with
     * this A8 bitmap mask.
     * Default: `NULL`, inherited: No, layout: No, ext. draw: No.
     * @param value  Pointer to A8 bitmap mask
     * @see lv_style_set_bitmap_mask_src
     */
    Style& bitmap_mask_src(const void* value) noexcept;
    /**
     * Adjust sensitivity for rotary encoders in 1/256 unit. It means, 128: slow down the
     * rotary to half, 512: speeds up to double, 256: no change.
     * Default: `256`, inherited: Yes, layout: No, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_rotary_sensitivity
     */
    Style& rotary_sensitivity(uint32_t value) noexcept;
    #if LV_USE_FLEX
    /**
     * Defines in which direction the flex layout should arrange the children.
     * Default: `LV_FLEX_FLOW_NONE`, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_flex_flow
     */
    Style& flex_flow(FlexFlow value) noexcept;
    /**
     * Defines how to align the children in the direction of flex flow.
     * Default: `LV_FLEX_ALIGN_NONE`, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_flex_main_place
     */
    Style& flex_main_place(FlexAlign value) noexcept;
    /**
     * Defines how to align the children perpendicular to the direction of flex flow.
     * Default: `LV_FLEX_ALIGN_NONE`, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_flex_cross_place
     */
    Style& flex_cross_place(FlexAlign value) noexcept;
    /**
     * Defines how to align the tracks of the flow.
     * Default: `LV_FLEX_ALIGN_NONE`, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_flex_track_place
     */
    Style& flex_track_place(FlexAlign value) noexcept;
    /**
     * Defines how much space to take proportionally from the free space of the Widget's track.
     * Default: `0`, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_flex_grow
     */
    Style& flex_grow(uint8_t value) noexcept;
    #endif // LV_USE_FLEX

    #if LV_USE_GRID
    /**
     * LVGL keeps this pointer and reads until it finds LV_GRID_TEMPLATE_LAST: the type writes the sentinel, and the rvalue overload is deleted so it cannot be a temporary.
     * An array to describe the columns of the grid. Should be LV_GRID_TEMPLATE_LAST terminated.
     * Default: `NULL`, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Pointer to grid-column descriptor array
     * @see lv_style_set_grid_column_dsc_array
     */
    template <std::size_t N1>
    Style& grid_column_dsc_array(const GridTemplate<N1>& value) noexcept;
    /** Refused: LVGL keeps the pointer, so this argument may not be a temporary. */
    template <std::size_t N1>
    Style& grid_column_dsc_array(GridTemplate<N1>&& value) noexcept = delete;
    /**
     * Defines how to distribute the columns.
     * Default: `LV_GRID_ALIGN_START`, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_grid_column_align
     */
    Style& grid_column_align(GridAlign value) noexcept;
    /**
     * LVGL keeps this pointer and reads until it finds LV_GRID_TEMPLATE_LAST: the type writes the sentinel, and the rvalue overload is deleted so it cannot be a temporary.
     * An array to describe the rows of the grid. Should be LV_GRID_TEMPLATE_LAST terminated.
     * Default: `NULL`, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Pointer to grid-row descriptor array
     * @see lv_style_set_grid_row_dsc_array
     */
    template <std::size_t N1>
    Style& grid_row_dsc_array(const GridTemplate<N1>& value) noexcept;
    /** Refused: LVGL keeps the pointer, so this argument may not be a temporary. */
    template <std::size_t N1>
    Style& grid_row_dsc_array(GridTemplate<N1>&& value) noexcept = delete;
    /**
     * Defines how to distribute the rows.
     * Default: `LV_GRID_ALIGN_START`, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_grid_row_align
     */
    Style& grid_row_align(GridAlign value) noexcept;
    /**
     * Set column in which Widget should be placed.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_grid_cell_column_pos
     */
    Style& grid_cell_column_pos(int32_t value) noexcept;
    /**
     * Set how to align Widget horizontally.
     * Default: `LV_GRID_ALIGN_START`, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_grid_cell_x_align
     */
    Style& grid_cell_x_align(GridAlign value) noexcept;
    /**
     * Set how many columns Widget should span. Needs to be >= 1.
     * Default: 1, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_grid_cell_column_span
     */
    Style& grid_cell_column_span(int32_t value) noexcept;
    /**
     * Set row in which Widget should be placed.
     * Default: 0, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_grid_cell_row_pos
     */
    Style& grid_cell_row_pos(int32_t value) noexcept;
    /**
     * Set how to align Widget vertically.
     * Default: `LV_GRID_ALIGN_START`, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_grid_cell_y_align
     */
    Style& grid_cell_y_align(GridAlign value) noexcept;
    /**
     * Set how many rows Widget should span. Needs to be >= 1.
     * Default: 1, inherited: No, layout: Yes, ext. draw: No.
     * @param value  Value to submit
     * @see lv_style_set_grid_cell_row_span
     */
    Style& grid_cell_row_span(int32_t value) noexcept;
    #endif // LV_USE_GRID

    /**
     * Copy all properties of a style to an other.
     * It has the same affect callying the same `lv_set_style_...`
     * functions on both styles.
     * It means new memory will be allocated to store the properties in
     * the destination style.
     * After the copy the destination style is fully independent of the source
     * and source can removed without affecting the destination style.
     * @param src  the source style to copy from.
     * @see lv_style_copy
     */
    void copy(Style& src) noexcept;
    /**
     * Get the value of a property
     * @param prop  the ID of a property
     * @param value  pointer to a `lv_style_value_t` variable to store the value
     * @return LV_RESULT_INVALID: the property wasn't found in the style (`value` is unchanged) LV_RESULT_OK: the property was fond, and `value` is set accordingly
     * @see lv_style_get_prop
     */
    StyleRes get_prop(lv_style_prop_t prop, lv_style_value_t* value) const noexcept;
    /**
     * Get the value of a property
     * @param prop  the ID of a property
     * @param value  pointer to a `lv_style_value_t` variable to store the value
     * @return LV_RESULT_INVALID: the property wasn't found in the style (`value` is unchanged) LV_RESULT_OK: the property was fond, and `value` is set accordingly
     * @see lv_style_get_prop_inlined
     */
    StyleRes get_prop_inlined(lv_style_prop_t prop, lv_style_value_t* value) const noexcept;
    /**
     * Initialize a style
     * @see lv_style_init
     */
    void init() noexcept;
    /**
     * Check if a style is constant
     * @return true: the style is constant
     * @see lv_style_is_const
     */
    bool is_const() const noexcept;
    /**
     * Checks if a style is empty (has no properties)
     * @return true if the style is empty
     * @see lv_style_is_empty
     */
    bool is_empty() const noexcept;
    /**
     * Copy all properties of a style to an other without resetting the dst style.
     * It has the same effect as calling the same `lv_set_style_...`
     * functions on both styles.
     * It means new memory will be allocated to store the properties in
     * the destination style.
     * After the copy the destination style is fully independent of the source
     * and source can removed without affecting the destination style.
     * @param src  the source style to copy from.
     * @see lv_style_merge
     */
    void merge(Style& src) noexcept;
    /**
     * Remove a property from a style
     * @param prop  a style property ORed with a state.
     * @return true: the property was found and removed; false: the property wasn't found
     * @see lv_style_remove_prop
     */
    bool remove_prop(lv_style_prop_t prop) noexcept;
    /**
     * Clear all properties from a style and free all allocated memories.
     * @see lv_style_reset
     */
    void reset() noexcept;
};

} // namespace lv
