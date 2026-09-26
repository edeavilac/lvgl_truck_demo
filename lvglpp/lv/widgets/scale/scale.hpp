#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core.hpp"
#include "lv/core/obj.hpp"
#include "lv/core/observer.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/style.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_SCALE != 0
class Scale : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_scale_class; }

    /** Scale mode */
    enum class Mode : int {
        HorizontalTop = LV_SCALE_MODE_HORIZONTAL_TOP,
        HorizontalBottom = LV_SCALE_MODE_HORIZONTAL_BOTTOM,
        VerticalLeft = LV_SCALE_MODE_VERTICAL_LEFT,
        VerticalRight = LV_SCALE_MODE_VERTICAL_RIGHT,
        RoundInner = LV_SCALE_MODE_ROUND_INNER,
        RoundOuter = LV_SCALE_MODE_ROUND_OUTER,
    };

    /**
     * Add a Section to specified Scale.  Section will not be drawn until
     * a valid range is set for it using `lv_scale_set_section_range()`.
     * @return pointer to new Section
     * @see lv_scale_add_section
     */
    ScaleSection add_section() const noexcept { return ScaleSection(lv_scale_add_section(p_)); }
    #if LV_USE_OBSERVER
    /**
     * Bind an integer subject to a scales section maximum value
     * @param section  pointer to a Scale section
     * @param subject  pointer to a Subject
     * @return pointer to newly-created Observer
     * @see lv_scale_bind_section_max_value
     */
    Observer bind_section_max_value(ScaleSection section, Subject& subject) const noexcept { return Observer(lv_scale_bind_section_max_value(p_, section.raw(), subject.raw())); }
    /**
     * Bind an integer subject to a scales section minimum value
     * @param section  pointer to a Scale section
     * @param subject  pointer to a Subject
     * @return pointer to newly-created Observer
     * @see lv_scale_bind_section_min_value
     */
    Observer bind_section_min_value(ScaleSection section, Subject& subject) const noexcept { return Observer(lv_scale_bind_section_min_value(p_, section.raw(), subject.raw())); }
    #endif // LV_USE_OBSERVER

    /**
     * Create an scale object
     * @param parent  pointer to an object, it will be the parent of the new scale
     * @return pointer to created Scale Widget
     * @see lv_scale_create
     */
    static Scale create(Obj parent) noexcept { return Scale(lv_scale_create(parent.raw())); }
    /**
     * Get Scale's range in degrees
     * @return Scale's angle_range
     * @see lv_scale_get_angle_range
     */
    uint32_t get_angle_range() const noexcept { return lv_scale_get_angle_range(p_); }
    /**
     * Gets label visibility
     * @return true if tick label is enabled, false otherwise
     * @see lv_scale_get_label_show
     */
    bool get_label_show() const noexcept { return lv_scale_get_label_show(p_); }
    /**
     * Get how often the major tick will be drawn
     * @return Scale major tick every count
     * @see lv_scale_get_major_tick_every
     */
    int32_t get_major_tick_every() const noexcept { return lv_scale_get_major_tick_every(p_); }
    /**
     * Get scale mode. See lv_scale_mode_t
     * @return Scale mode
     * @see lv_scale_get_mode
     */
    Scale::Mode get_mode() const noexcept { return static_cast<Scale::Mode>(lv_scale_get_mode(p_)); }
    /**
     * Get maximum value for Scale
     * @return Scale's maximum value
     * @see lv_scale_get_range_max_value
     */
    int32_t get_range_max_value() const noexcept { return lv_scale_get_range_max_value(p_); }
    /**
     * Get minimum value for Scale
     * @return Scale's minimum value
     * @see lv_scale_get_range_min_value
     */
    int32_t get_range_min_value() const noexcept { return lv_scale_get_range_min_value(p_); }
    /**
     * Get angular location of low end of Scale.
     * @return Scale low end angular location
     * @see lv_scale_get_rotation
     */
    int32_t get_rotation() const noexcept { return lv_scale_get_rotation(p_); }
    /**
     * Get scale total tick count (including minor and major ticks)
     * @return Scale total tick count
     * @see lv_scale_get_total_tick_count
     */
    int32_t get_total_tick_count() const noexcept { return lv_scale_get_total_tick_count(p_); }
    /**
     * Set angle between the low end and the high end of the Scale.
     * (Applies only to round Scales.)
     * @see lv_scale_set_angle_range
     */
    void set_angle_range(uint32_t angle_range) const noexcept { lv_scale_set_angle_range(p_, angle_range); }
    /**
     * Draw Scale ticks on top of all other parts.
     * @param en  true: enable draw ticks on top of all parts
     * @see lv_scale_set_draw_ticks_on_top
     */
    void set_draw_ticks_on_top(bool en) const noexcept { lv_scale_set_draw_ticks_on_top(p_, en); }
    /**
     * Point image needle to specified value;
     * image must point to the right. E.g. -O------>
     * @param needle_img  pointer to needle's Image
     * @param value  Scale value needle will point to
     * @see lv_scale_set_image_needle_value
     */
    void set_image_needle_value(Obj needle_img, int32_t value) const noexcept { lv_scale_set_image_needle_value(p_, needle_img.raw(), value); }
    /**
     * Sets label visibility.
     * @param show_label  true/false to enable tick label
     * @see lv_scale_set_label_show
     */
    void set_label_show(bool show_label) const noexcept { lv_scale_set_label_show(p_, show_label); }
    /**
     * Point line needle to specified value.
     * @param needle_line  needle_line of the Scale. The line points will be allocated and managed by the Scale unless the line point array was previously set using `lv_line_set_points_mutable`.
     * @param needle_length  length of the needle - needle_length>0: needle_length=needle_length; - needle_length<0: needle_length=radius-|needle_length|;
     * @param value  Scale value needle will point to
     * @see lv_scale_set_line_needle_value
     */
    void set_line_needle_value(Obj needle_line, int32_t needle_length, int32_t value) const noexcept { lv_scale_set_line_needle_value(p_, needle_line.raw(), needle_length, value); }
    /**
     * Sets how often major ticks are drawn.
     * @param major_tick_every  the new count for major tick drawing
     * @see lv_scale_set_major_tick_every
     */
    void set_major_tick_every(uint32_t major_tick_every) const noexcept { lv_scale_set_major_tick_every(p_, major_tick_every); }
    /**
     * Set maximum values on Scale.
     * @see lv_scale_set_max_value
     */
    void set_max_value(int32_t max) const noexcept { lv_scale_set_max_value(p_, max); }
    /**
     * Set minimum values on Scale.
     * @param min  minimum value of Scale
     * @see lv_scale_set_min_value
     */
    void set_min_value(int32_t min) const noexcept { lv_scale_set_min_value(p_, min); }
    /**
     * Set scale mode. See lv_scale_mode_t.
     * @param mode  the new scale mode
     * @see lv_scale_set_mode
     */
    void set_mode(Scale::Mode mode) const noexcept { lv_scale_set_mode(p_, static_cast<lv_scale_mode_t>(mode)); }
    /**
     * Draw Scale after all its children are drawn.
     * @param en  true: enable post draw
     * @see lv_scale_set_post_draw
     */
    void set_post_draw(bool en) const noexcept { lv_scale_set_post_draw(p_, en); }
    /**
     * Set minimum and maximum values on Scale.
     * @param min  minimum value of Scale
     * @param max  maximum value of Scale
     * @see lv_scale_set_range
     */
    void set_range(int32_t min, int32_t max) const noexcept { lv_scale_set_range(p_, min, max); }
    /**
     * Set angular offset from the 3-o'clock position of the low end of the Scale.
     * (Applies only to round Scales.)
     * @param rotation  clockwise angular offset (in degrees) from the 3-o'clock position of the low end of the scale; negative and >360 values are first normalized to range [0..360]. Examples: - 0 = 3 o'clock (right side) - 30 = 4 o'clock - 60 = 5 o'clock - 90 = 6 o'clock - 135 = midway between 7 and 8 o'clock (default) - 180 = 9 o'clock - 270 = 12 o'clock - 300 = 1 o'clock - 330 = 2 o'clock - -30 = 2 o'clock - 390 = 4 o'clock
     * @see lv_scale_set_rotation
     */
    void set_rotation(int32_t rotation) const noexcept { lv_scale_set_rotation(p_, rotation); }
    /**
     * Set the maximum value of a scale section
     * @param section  pointer to section
     * @param max  the section's new maximum value
     * @see lv_scale_set_section_max_value
     */
    void set_section_max_value(ScaleSection section, int32_t max) const noexcept { lv_scale_set_section_max_value(p_, section.raw(), max); }
    /**
     * Set the minimum value of a scale section
     * @param section  pointer to section
     * @param min  the section's new minimum value
     * @see lv_scale_set_section_min_value
     */
    void set_section_min_value(ScaleSection section, int32_t min) const noexcept { lv_scale_set_section_min_value(p_, section.raw(), min); }
    /**
     * Set the range of a scale section
     * @param section  pointer to section
     * @see lv_scale_set_section_range
     */
    void set_section_range(ScaleSection section, int32_t min, int32_t max) const noexcept { lv_scale_set_section_range(p_, section.raw(), min, max); }
    /**
     * Set the style of the major ticks and label on a section.
     * @param section  pointer to section
     * @param style  point to a style
     * @see lv_scale_set_section_style_indicator
     */
    void set_section_style_indicator(ScaleSection section, Style& style) const noexcept { lv_scale_set_section_style_indicator(p_, section.raw(), style.raw()); }
    /**
     * Set the style of the minor ticks on a section.
     * @param section  pointer to section
     * @param style  point to a style
     * @see lv_scale_set_section_style_items
     */
    void set_section_style_items(ScaleSection section, Style& style) const noexcept { lv_scale_set_section_style_items(p_, section.raw(), style.raw()); }
    /**
     * Set the style of the line on a section.
     * @param section  pointer to section
     * @param style  point to a style
     * @see lv_scale_set_section_style_main
     */
    void set_section_style_main(ScaleSection section, Style& style) const noexcept { lv_scale_set_section_style_main(p_, section.raw(), style.raw()); }
    /**
     * Set custom text source for major ticks labels.
     * @param txt_src  pointer to an array of strings which will be display at major ticks; last element must be a NULL pointer.
     * @see lv_scale_set_text_src
     */
    void set_text_src(const char** txt_src) const noexcept { lv_scale_set_text_src(p_, txt_src); }
    /**
     * Set scale total tick count (including minor and major ticks).
     * @param total_tick_count  New total tick count
     * @see lv_scale_set_total_tick_count
     */
    void set_total_tick_count(uint32_t total_tick_count) const noexcept { lv_scale_set_total_tick_count(p_, total_tick_count); }
};
static_assert(sizeof(Scale) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Scale));
#endif // LV_USE_SCALE != 0

#if LV_USE_SCALE != 0
inline void ScaleSection::set_range(int32_t min, int32_t max) const noexcept { lv_scale_section_set_range(p_, min, max); }

inline void ScaleSection::set_style(Part part, Style& section_part_style) const noexcept { lv_scale_section_set_style(p_, static_cast<lv_part_t>(part), section_part_style.raw()); }
#endif // LV_USE_SCALE != 0

} // namespace lv
