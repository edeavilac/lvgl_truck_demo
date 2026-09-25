#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core/obj.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lv/widgets/button/button.hpp"
#include "lv/widgets/image/image.hpp"
#include "lv/widgets/label/label.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if (LV_USE_ANIMIMG) && (LV_USE_ANIMIMG != 0) && (LV_USE_IMAGE != 0)
class Animimg : public Image {
public:
    using Image::Image;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_animimg_class; }

    /** Image parts */
    enum class Part : int {
        Main = LV_ANIM_IMAGE_PART_MAIN,
    };

    /**
     * Create an animation image objects
     * @param parent  pointer to an object, it will be the parent of the new button
     * @return pointer to the created animation image object
     * @see lv_animimg_create
     */
    static Animimg create(Obj parent) noexcept;
    /**
     * Delete the image animation.
     * @see lv_animimg_delete
     */
    bool delete_() const noexcept;
    /**
     * Get the image animation underlying animation.
     * @return the animation reference
     * @see lv_animimg_get_anim
     */
    lv_anim_t* get_anim() const noexcept;
    /**
     * Get the image animation duration time. unit:ms
     * @return the animation duration time
     * @see lv_animimg_get_duration
     */
    uint32_t get_duration() const noexcept;
    /**
     * Get the image animation repeat play times.
     * @return the repeat count
     * @see lv_animimg_get_repeat_count
     */
    uint32_t get_repeat_count() const noexcept;
    /**
     * Get the image animation images source.
     * @return a pointer that will point to a series images
     * @see lv_animimg_get_src
     */
    const void** get_src() const noexcept;
    /**
     * Get the image animation images source.
     * @return the number of source images
     * @see lv_animimg_get_src_count
     */
    uint8_t get_src_count() const noexcept;
    /**
     * Set a function call when the animation is completed
     * @param completed_cb  a function call when the animation is completed
     * @see lv_animimg_set_completed_cb
     */
    void set_completed_cb(lv_anim_completed_cb_t completed_cb) const noexcept;
    /**
     * Set the image animation duration time. unit:ms
     * @param duration  the duration in milliseconds
     * @see lv_animimg_set_duration
     */
    void set_duration(uint32_t duration) const noexcept;
    /**
     * Set the image animation repeatedly play times.
     * @param count  the number of times to repeat the animation
     * @see lv_animimg_set_repeat_count
     */
    void set_repeat_count(uint32_t count) const noexcept;
    /**
     * Make the image animation to play back to when the forward direction is ready.
     * @param duration  delay in milliseconds before starting the playback image animation.
     * @see lv_animimg_set_reverse_delay
     */
    void set_reverse_delay(uint32_t duration) const noexcept;
    /**
     * Make the image animation to play back to when the forward direction is ready.
     * @param duration  the duration of the playback image animation in milliseconds. 0: disable playback
     * @see lv_animimg_set_reverse_duration
     */
    void set_reverse_duration(uint32_t duration) const noexcept;
    /**
     * Set the image animation images source.
     * @param dsc  pointer to a series images
     * @param num  images' number
     * @see lv_animimg_set_src
     */
    void set_src(const void** dsc, size_t num) const noexcept;
    /**
     * Set the images source for flip playback of animation image.
     * @param dsc  pointer to a series images
     * @param num  images' number
     * @see lv_animimg_set_src_reverse
     */
    void set_src_reverse(const void** dsc, size_t num) const noexcept;
    /**
     * Set a function call when the animation image really starts (considering `delay`)
     * @param start_cb  a function call when the animation is start
     * @see lv_animimg_set_start_cb
     */
    void set_start_cb(lv_anim_start_cb_t start_cb) const noexcept;
    /**
     * Startup the image animation.
     * @see lv_animimg_start
     */
    void start() const noexcept;
};
static_assert(sizeof(Animimg) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Animimg));
#endif // (LV_USE_ANIMIMG) && (LV_USE_ANIMIMG != 0) && (LV_USE_IMAGE != 0)

class Color16 {
protected:
    lv_color16_t* p_ = nullptr;

public:
    constexpr Color16() noexcept = default;  /**< the "no object" handle */
    constexpr explicit Color16(lv_color16_t* p) noexcept : p_(p) {}

    constexpr lv_color16_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(Color16 a, Color16 b) noexcept { return a.p_ == b.p_; }

    /** @see lv_color16_premultiply */
    void premultiply(lv_opa_t a) const noexcept;
};
static_assert(sizeof(Color16) == sizeof(lv_color16_t*));
static_assert(__is_trivially_copyable(Color16));

class ColorFilterDsc {
protected:
    lv_color_filter_dsc_t s_;

public:
    explicit ColorFilterDsc(lv_color_filter_cb_t cb) noexcept { lv_color_filter_dsc_init(&s_, cb); }
protected:
    ColorFilterDsc() noexcept = default;
public:


    ColorFilterDsc(const ColorFilterDsc&) = delete;
    ColorFilterDsc& operator=(const ColorFilterDsc&) = delete;
    ColorFilterDsc(ColorFilterDsc&&) = delete;
    ColorFilterDsc& operator=(ColorFilterDsc&&) = delete;

    lv_color_filter_dsc_t* raw() noexcept { return &s_; }

};

class DrawArcDsc {
protected:
    lv_draw_arc_dsc_t s_;

public:
    DrawArcDsc() noexcept { lv_draw_arc_dsc_init(&s_); }

    DrawArcDsc(const DrawArcDsc&) = delete;
    DrawArcDsc& operator=(const DrawArcDsc&) = delete;
    DrawArcDsc(DrawArcDsc&&) = delete;
    DrawArcDsc& operator=(DrawArcDsc&&) = delete;

    lv_draw_arc_dsc_t* raw() noexcept { return &s_; }

};

class DrawBlurDsc {
protected:
    lv_draw_blur_dsc_t s_;

public:
    DrawBlurDsc() noexcept { lv_draw_blur_dsc_init(&s_); }

    DrawBlurDsc(const DrawBlurDsc&) = delete;
    DrawBlurDsc& operator=(const DrawBlurDsc&) = delete;
    DrawBlurDsc(DrawBlurDsc&&) = delete;
    DrawBlurDsc& operator=(DrawBlurDsc&&) = delete;

    lv_draw_blur_dsc_t* raw() noexcept { return &s_; }

};

class DrawBorderDsc {
protected:
    lv_draw_border_dsc_t s_;

public:
    DrawBorderDsc() noexcept { lv_draw_border_dsc_init(&s_); }

    DrawBorderDsc(const DrawBorderDsc&) = delete;
    DrawBorderDsc& operator=(const DrawBorderDsc&) = delete;
    DrawBorderDsc(DrawBorderDsc&&) = delete;
    DrawBorderDsc& operator=(DrawBorderDsc&&) = delete;

    lv_draw_border_dsc_t* raw() noexcept { return &s_; }

};

class DrawBoxShadowDsc {
protected:
    lv_draw_box_shadow_dsc_t s_;

public:
    DrawBoxShadowDsc() noexcept { lv_draw_box_shadow_dsc_init(&s_); }

    DrawBoxShadowDsc(const DrawBoxShadowDsc&) = delete;
    DrawBoxShadowDsc& operator=(const DrawBoxShadowDsc&) = delete;
    DrawBoxShadowDsc(DrawBoxShadowDsc&&) = delete;
    DrawBoxShadowDsc& operator=(DrawBoxShadowDsc&&) = delete;

    lv_draw_box_shadow_dsc_t* raw() noexcept { return &s_; }

};

class DrawBufHandlers {
protected:
    lv_draw_buf_handlers_t* p_ = nullptr;

public:
    constexpr DrawBufHandlers() noexcept = default;  /**< the "no object" handle */
    constexpr explicit DrawBufHandlers(lv_draw_buf_handlers_t* p) noexcept : p_(p) {}

    constexpr lv_draw_buf_handlers_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(DrawBufHandlers a, DrawBufHandlers b) noexcept { return a.p_ == b.p_; }

    /**
     * Initialize the draw buffer with given handlers.
     * @param buf_malloc_cb  the callback to allocate memory for the buffer
     * @param buf_free_cb  the callback to free memory of the buffer
     * @param buf_copy_cb  the callback to copy a draw buffer to an other
     * @param align_pointer_cb  the callback to align the buffer
     * @param invalidate_cache_cb  the callback to invalidate the cache of the buffer
     * @param flush_cache_cb  the callback to flush buffer
     * @param width_to_stride_cb  the callback to calculate the stride based on the width and color format
     * @see lv_draw_buf_handlers_init
     */
    void init(lv_draw_buf_malloc_cb_t buf_malloc_cb, lv_draw_buf_free_cb_t buf_free_cb, lv_draw_buf_copy_cb_t buf_copy_cb, lv_draw_buf_align_cb_t align_pointer_cb, lv_draw_buf_cache_operation_cb_t invalidate_cache_cb, lv_draw_buf_cache_operation_cb_t flush_cache_cb, lv_draw_buf_width_to_stride_cb_t width_to_stride_cb) const noexcept;
    /**
     * Takes the function itself as a template argument, so its real parameter types survive: the C idiom CASTS the pointer, which is undefined whenever they differ, and between the versions they do.
     * Initialize the draw buffer with given handlers.
     * @param buf_malloc_cb  the callback to allocate memory for the buffer
     * @param buf_free_cb  the callback to free memory of the buffer
     * @param buf_copy_cb  the callback to copy a draw buffer to an other
     * @param align_pointer_cb  the callback to align the buffer
     * @param invalidate_cache_cb  the callback to invalidate the cache of the buffer
     * @param flush_cache_cb  the callback to flush buffer
     * @param width_to_stride_cb  the callback to calculate the stride based on the width and color format
     * @see lv_draw_buf_handlers_init
     */
    template <auto Fn>
    void init(lv_draw_buf_malloc_cb_t buf_malloc_cb, lv_draw_buf_free_cb_t buf_free_cb, lv_draw_buf_copy_cb_t buf_copy_cb, lv_draw_buf_cache_operation_cb_t invalidate_cache_cb, lv_draw_buf_cache_operation_cb_t flush_cache_cb, lv_draw_buf_width_to_stride_cb_t width_to_stride_cb) const noexcept;
};
static_assert(sizeof(DrawBufHandlers) == sizeof(lv_draw_buf_handlers_t*));
static_assert(__is_trivially_copyable(DrawBufHandlers));

class DrawFillDsc {
protected:
    lv_draw_fill_dsc_t s_;

public:
    DrawFillDsc() noexcept { lv_draw_fill_dsc_init(&s_); }

    DrawFillDsc(const DrawFillDsc&) = delete;
    DrawFillDsc& operator=(const DrawFillDsc&) = delete;
    DrawFillDsc(DrawFillDsc&&) = delete;
    DrawFillDsc& operator=(DrawFillDsc&&) = delete;

    lv_draw_fill_dsc_t* raw() noexcept { return &s_; }

};

class DrawGlyphDsc {
protected:
    lv_draw_glyph_dsc_t* p_ = nullptr;

public:
    constexpr DrawGlyphDsc() noexcept = default;  /**< the "no object" handle */
    constexpr explicit DrawGlyphDsc(lv_draw_glyph_dsc_t* p) noexcept : p_(p) {}

    constexpr lv_draw_glyph_dsc_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(DrawGlyphDsc a, DrawGlyphDsc b) noexcept { return a.p_ == b.p_; }

    /**
     * Initialize a glyph draw descriptor.
     * Used internally.
     * @see lv_draw_glyph_dsc_init
     */
    void init() const noexcept;
};
static_assert(sizeof(DrawGlyphDsc) == sizeof(lv_draw_glyph_dsc_t*));
static_assert(__is_trivially_copyable(DrawGlyphDsc));

class DrawImageDsc {
protected:
    lv_draw_image_dsc_t s_;

public:
    DrawImageDsc() noexcept { lv_draw_image_dsc_init(&s_); }

    DrawImageDsc(const DrawImageDsc&) = delete;
    DrawImageDsc& operator=(const DrawImageDsc&) = delete;
    DrawImageDsc(DrawImageDsc&&) = delete;
    DrawImageDsc& operator=(DrawImageDsc&&) = delete;

    lv_draw_image_dsc_t* raw() noexcept { return &s_; }

};

class DrawLabelDsc {
protected:
    lv_draw_label_dsc_t s_;

public:
    DrawLabelDsc() noexcept { lv_draw_label_dsc_init(&s_); }

    DrawLabelDsc(const DrawLabelDsc&) = delete;
    DrawLabelDsc& operator=(const DrawLabelDsc&) = delete;
    DrawLabelDsc(DrawLabelDsc&&) = delete;
    DrawLabelDsc& operator=(DrawLabelDsc&&) = delete;

    lv_draw_label_dsc_t* raw() noexcept { return &s_; }

};

class DrawLetterDsc {
protected:
    lv_draw_letter_dsc_t s_;

public:
    DrawLetterDsc() noexcept { lv_draw_letter_dsc_init(&s_); }

    DrawLetterDsc(const DrawLetterDsc&) = delete;
    DrawLetterDsc& operator=(const DrawLetterDsc&) = delete;
    DrawLetterDsc(DrawLetterDsc&&) = delete;
    DrawLetterDsc& operator=(DrawLetterDsc&&) = delete;

    lv_draw_letter_dsc_t* raw() noexcept { return &s_; }

};

class DrawLineDsc {
protected:
    lv_draw_line_dsc_t s_;

public:
    DrawLineDsc() noexcept { lv_draw_line_dsc_init(&s_); }

    DrawLineDsc(const DrawLineDsc&) = delete;
    DrawLineDsc& operator=(const DrawLineDsc&) = delete;
    DrawLineDsc(DrawLineDsc&&) = delete;
    DrawLineDsc& operator=(DrawLineDsc&&) = delete;

    lv_draw_line_dsc_t* raw() noexcept { return &s_; }

};

class DrawRectDsc {
protected:
    lv_draw_rect_dsc_t s_;

public:
    DrawRectDsc() noexcept { lv_draw_rect_dsc_init(&s_); }

    DrawRectDsc(const DrawRectDsc&) = delete;
    DrawRectDsc& operator=(const DrawRectDsc&) = delete;
    DrawRectDsc(DrawRectDsc&&) = delete;
    DrawRectDsc& operator=(DrawRectDsc&&) = delete;

    lv_draw_rect_dsc_t* raw() noexcept { return &s_; }

};

class Layer {
protected:
    lv_layer_t s_;

public:
    Layer() noexcept { lv_layer_init(&s_); }
    ~Layer() { lv_layer_reset(&s_); }

    Layer(const Layer&) = delete;
    Layer& operator=(const Layer&) = delete;
    Layer(Layer&&) = delete;
    Layer& operator=(Layer&&) = delete;

    lv_layer_t* raw() noexcept { return &s_; }

    /**
     * Reset the layer to a drawable state
     * @see lv_layer_reset
     */
    Layer& reset() noexcept;
};

#if LV_USE_VECTOR_GRAPHIC
class VectorPath {
protected:
    lv_vector_path_t* p_ = nullptr;

public:
    constexpr VectorPath() noexcept = default;  /**< the "no object" handle */
    constexpr explicit VectorPath(lv_vector_path_t* p) noexcept : p_(p) {}

    constexpr lv_vector_path_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(VectorPath a, VectorPath b) noexcept { return a.p_ == b.p_; }

    /**
     * Add a arc to the path
     * @param c  pointer to a `lv_fpoint_t` variable for center of the circle
     * @param radius  the radius for arc
     * @param start_angle  the start angle for arc
     * @param sweep  the sweep angle for arc, could be negative
     * @param pie  true: draw a pie, false: draw a arc
     * @see lv_vector_path_append_arc
     */
    void append_arc(const lv_fpoint_t* c, float radius, float start_angle, float sweep, bool pie) const noexcept;
    /**
     * Add a circle to the path
     * @param c  pointer to a `lv_fpoint_t` variable for center of the circle
     * @param rx  the horizontal radius for circle
     * @param ry  the vertical radius for circle
     * @see lv_vector_path_append_circle
     */
    void append_circle(const lv_fpoint_t* c, float rx, float ry) const noexcept;
    /**
     * Add an sub path to the path
     * @param subpath  pointer to another path which will be added
     * @see lv_vector_path_append_path
     */
    void append_path(VectorPath subpath) const noexcept;
    /**
     * Add a rectangle to the path (legacy api, recommend use lv_vector_path_append_rectangle instead)
     * @param rect  pointer to a `lv_area_t` variable
     * @param rx  the horizontal radius for rounded rectangle
     * @param ry  the vertical radius for rounded rectangle
     * @see lv_vector_path_append_rect
     */
    void append_rect(const Area& rect, float rx, float ry) const noexcept;
    /**
     * Add a rectangle to the path by x/y/w/h. rx/ry are corner radii
     * @param x  the x coordinate of the top-left corner of the rectangle
     * @param y  the y coordinate of the top-left corner of the rectangle
     * @param w  the width of the rectangle
     * @param h  the height of the rectangle
     * @param rx  the horizontal radius for rounded rectangle
     * @param ry  the vertical radius for rounded rectangle
     * @see lv_vector_path_append_rectangle
     */
    void append_rectangle(float x, float y, float w, float h, float rx, float ry) const noexcept;
    /**
     * Add ellipse arc to the path from last point to the point
     * @param radius_x  the x radius for ellipse arc
     * @param radius_y  the y radius for ellipse arc
     * @param rotate_angle  the rotate angle for arc
     * @param large_arc  true for large arc, otherwise small
     * @param clockwise  true for clockwise, otherwise anticlockwise
     * @param p  pointer to a `lv_fpoint_t` variable for end point
     * @see lv_vector_path_arc_to
     */
    void arc_to(float radius_x, float radius_y, float rotate_angle, bool large_arc, bool clockwise, const lv_fpoint_t* p) const noexcept;
    /**
     * Clear path data
     * @see lv_vector_path_clear
     */
    void clear() const noexcept;
    /**
     * Close the sub path
     * @see lv_vector_path_close
     */
    void close() const noexcept;
    /**
     * Copy a path data to another
     * @param path  pointer to source path
     * @see lv_vector_path_copy
     */
    void copy(VectorPath path) const noexcept;
    /**
     * Create a vector graphic path object
     * @param quality  the quality hint of path
     * @return pointer to the created path object
     * @see lv_vector_path_create
     */
    static VectorPath create(VectorPathQuality quality) noexcept;
    /**
     * Add a cubic bezier line to the path from last point to the point
     * @param p1  pointer to a `lv_fpoint_t` variable for first control point
     * @param p2  pointer to a `lv_fpoint_t` variable for second control point
     * @param p3  pointer to a `lv_fpoint_t` variable for end point
     * @see lv_vector_path_cubic_to
     */
    void cubic_to(const lv_fpoint_t* p1, const lv_fpoint_t* p2, const lv_fpoint_t* p3) const noexcept;
    /**
     * Delete the graphic path object
     * @see lv_vector_path_delete
     */
    void delete_() const noexcept;
    /**
     * Get the bounding box of a path
     * @return pointer to a `lv_area_t` variable for bounding box
     * @see lv_vector_path_get_bounding
     */
    Area get_bounding() const noexcept;
    /**
     * Add a line to the path from last point to the point
     * @param p  pointer to a `lv_fpoint_t` variable
     * @see lv_vector_path_line_to
     */
    void line_to(const lv_fpoint_t* p) const noexcept;
    /**
     * Begin a new sub path and set a point to path
     * @param p  pointer to a `lv_fpoint_t` variable
     * @see lv_vector_path_move_to
     */
    void move_to(const lv_fpoint_t* p) const noexcept;
    /**
     * Add a quadratic bezier line to the path from last point to the point
     * @param p1  pointer to a `lv_fpoint_t` variable for control point
     * @param p2  pointer to a `lv_fpoint_t` variable for end point
     * @see lv_vector_path_quad_to
     */
    void quad_to(const lv_fpoint_t* p1, const lv_fpoint_t* p2) const noexcept;
};
static_assert(sizeof(VectorPath) == sizeof(lv_vector_path_t*));
static_assert(__is_trivially_copyable(VectorPath));

class DrawVectorDsc {
protected:
    lv_draw_vector_dsc_t* p_ = nullptr;

public:
    constexpr DrawVectorDsc() noexcept = default;  /**< the "no object" handle */
    constexpr explicit DrawVectorDsc(lv_draw_vector_dsc_t* p) noexcept : p_(p) {}

    constexpr lv_draw_vector_dsc_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(DrawVectorDsc a, DrawVectorDsc b) noexcept { return a.p_ == b.p_; }

    /**
     * Add a graphic path to the draw list.
     * It will use colors, opacity, matrix and other parameters set
     * by `lv_draw_vector_dsc_set_fill_color()` and similar functions.
     * @param path  pointer to a path
     * @see lv_draw_vector_dsc_add_path
     */
    void add_path(VectorPath path) const noexcept;
    /**
     * Clear a rectangle area use current fill color
     * @param rect  the area to clear in the buffer
     * @see lv_draw_vector_dsc_clear_area
     */
    void clear_area(const Area& rect) const noexcept;
    /**
     * Create a vector graphic descriptor
     * @param layer  pointer to a layer
     * @return pointer to the created descriptor
     * @see lv_draw_vector_dsc_create
     */
    static DrawVectorDsc create(Layer& layer) noexcept;
    /**
     * Delete the vector graphic descriptor
     * @see lv_draw_vector_dsc_delete
     */
    void delete_() const noexcept;
    /**
     * Set current transformation matrix to identity matrix
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this matrix.
     * @see lv_draw_vector_dsc_identity
     */
    void identity() const noexcept;
    /**
     * Rotate current transformation matrix with origin
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this rotation.
     * @param degree  angle to rotate
     * @see lv_draw_vector_dsc_rotate
     */
    void rotate(float degree) const noexcept;
    /**
     * Change the scale factor of current transformation matrix
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this scale.
     * @param scale_x  the scale factor for the X direction
     * @param scale_y  the scale factor for the Y direction
     * @see lv_draw_vector_dsc_scale
     */
    void scale(float scale_x, float scale_y) const noexcept;
    /**
     * Set blend mode for descriptor.
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this blend mode.
     * @param blend  the blend mode to be set in `lv_vector_blend_t`
     * @see lv_draw_vector_dsc_set_blend_mode
     */
    void set_blend_mode(VectorBlend blend) const noexcept;
    /**
     * Set fill color for descriptor.
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this color.
     * @param color  the color to be set in lv_color_t format
     * @see lv_draw_vector_dsc_set_fill_color
     */
    void set_fill_color(Color color) const noexcept;
    /**
     * Set the fill color for descriptor.
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this color.
     * @param color  the color to be set in lv_color32_t format
     * @see lv_draw_vector_dsc_set_fill_color32
     */
    void set_fill_color32(lv_color32_t color) const noexcept;
    /**
     * Set fill gradient color stops for descriptor.
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this gradient color stops.
     * @param stops  an array of `lv_grad_stop_t` variables
     * @param count  the number of stops in the array, range: 0..LV_GRADIENT_MAX_STOPS
     * @see lv_draw_vector_dsc_set_fill_gradient_color_stops
     */
    void set_fill_gradient_color_stops(const lv_grad_stop_t* stops, uint16_t count) const noexcept;
    /**
     * Set fill radial gradient spread for descriptor
     * @param spread  the gradient spread to be set in lv_vector_gradient_spread_t format
     * @see lv_draw_vector_dsc_set_fill_gradient_spread
     */
    void set_fill_gradient_spread(VectorGradientSpread spread) const noexcept;
    /**
     * Set fill image for descriptor.
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this fill image.
     * @param img_dsc  pointer to a `lv_draw_image_dsc_t` variable
     * @see lv_draw_vector_dsc_set_fill_image
     */
    void set_fill_image(DrawImageDsc& img_dsc) const noexcept;
    /**
     * Set fill linear gradient for descriptor
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this gradient.
     * @param x1  the x for start point
     * @param y1  the y for start point
     * @param x2  the x for end point
     * @param y2  the y for end point
     * @see lv_draw_vector_dsc_set_fill_linear_gradient
     */
    void set_fill_linear_gradient(float x1, float y1, float x2, float y2) const noexcept;
    /**
     * Set fill opacity for descriptor.
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this opacity.
     * @param opa  the opacity to be set in lv_opa_t format
     * @see lv_draw_vector_dsc_set_fill_opa
     */
    void set_fill_opa(lv_opa_t opa) const noexcept;
    /**
     * Set fill radial gradient radius for descriptor
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this gradient.
     * @param cx  the x for center of the circle
     * @param cy  the y for center of the circle
     * @param radius  the radius for circle
     * @see lv_draw_vector_dsc_set_fill_radial_gradient
     */
    void set_fill_radial_gradient(float cx, float cy, float radius) const noexcept;
    /**
     * Set fill rule for descriptor.
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this fill rule.
     * @param rule  the fill rule to be set in lv_vector_fill_t format
     * @see lv_draw_vector_dsc_set_fill_rule
     */
    void set_fill_rule(VectorFill rule) const noexcept;
    #if LV_USE_MATRIX
    /**
     * Set a matrix to current fill transformation matrix
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this matrix.
     * @param matrix  pointer to a matrix
     * @see lv_draw_vector_dsc_set_fill_transform
     */
    void set_fill_transform(Matrix matrix) const noexcept;
    #endif // LV_USE_MATRIX

    /**
     * Set the fill units for descriptor.
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this fill units.
     * @param units  the units to be set in lv_vector_fill_units_t format
     * @see lv_draw_vector_dsc_set_fill_units
     */
    void set_fill_units(VectorFillUnits units) const noexcept;
    /**
     * Set stroke line cap style for descriptor
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this line cap.
     * @param cap  the line cap to be set in lv_vector_stroke_cap_t format
     * @see lv_draw_vector_dsc_set_stroke_cap
     */
    void set_stroke_cap(VectorStrokeCap cap) const noexcept;
    /**
     * Set stroke color for descriptor.
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this color.
     * @param color  the color to be set in lv_color_t format
     * @see lv_draw_vector_dsc_set_stroke_color
     */
    void set_stroke_color(Color color) const noexcept;
    /**
     * Set stroke color for descriptor.
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this color.
     * @param color  the color to be set in lv_color32_t format
     * @see lv_draw_vector_dsc_set_stroke_color32
     */
    void set_stroke_color32(lv_color32_t color) const noexcept;
    /**
     * Set stroke line dash pattern for descriptor
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this dash.
     * @param dash_pattern  an array of values that specify the segments of dash line
     * @param dash_count  the length of dash pattern array
     * @see lv_draw_vector_dsc_set_stroke_dash
     */
    void set_stroke_dash(float* dash_pattern, uint16_t dash_count) const noexcept;
    /**
     * Set stroke color stops for descriptor
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this color stops.
     * @param stops  an array of `lv_grad_stop_t` variables
     * @param count  the number of stops in the array
     * @see lv_draw_vector_dsc_set_stroke_gradient_color_stops
     */
    void set_stroke_gradient_color_stops(const lv_grad_stop_t* stops, uint16_t count) const noexcept;
    /**
     * Set stroke color stops for descriptor
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this gradient spread.
     * @param spread  the gradient spread to be set in lv_vector_gradient_spread_t format
     * @see lv_draw_vector_dsc_set_stroke_gradient_spread
     */
    void set_stroke_gradient_spread(VectorGradientSpread spread) const noexcept;
    /**
     * Set stroke line join style for descriptor
     * @param join  the line join to be set in lv_vector_stroke_join_t format
     * @see lv_draw_vector_dsc_set_stroke_join
     */
    void set_stroke_join(VectorStrokeJoin join) const noexcept;
    /**
     * Set stroke linear gradient for descriptor
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this gradient.
     * @param x1  the x for start point
     * @param y1  the y for start point
     * @param x2  the x for end point
     * @param y2  the y for end point
     * @see lv_draw_vector_dsc_set_stroke_linear_gradient
     */
    void set_stroke_linear_gradient(float x1, float y1, float x2, float y2) const noexcept;
    /**
     * Set stroke miter limit for descriptor
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this miter limit.
     * @param miter_limit  the stroke miter_limit
     * @see lv_draw_vector_dsc_set_stroke_miter_limit
     */
    void set_stroke_miter_limit(uint16_t miter_limit) const noexcept;
    /**
     * Set stroke opacity for descriptor
     * @param opa  the opacity to be set in lv_opa_t format
     * @see lv_draw_vector_dsc_set_stroke_opa
     */
    void set_stroke_opa(lv_opa_t opa) const noexcept;
    /**
     * Set stroke radial gradient for descriptor
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this gradient.
     * @param cx  the x for center of the circle
     * @param cy  the y for center of the circle
     * @param radius  the radius for circle
     * @see lv_draw_vector_dsc_set_stroke_radial_gradient
     */
    void set_stroke_radial_gradient(float cx, float cy, float radius) const noexcept;
    #if LV_USE_MATRIX
    /**
     * Set a matrix to current stroke transformation matrix.
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this matrix.
     * @param matrix  pointer to a matrix
     * @see lv_draw_vector_dsc_set_stroke_transform
     */
    void set_stroke_transform(Matrix matrix) const noexcept;
    #endif // LV_USE_MATRIX

    /**
     * Set stroke line width for descriptor.
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this stroke width.
     * @param width  the stroke line width
     * @see lv_draw_vector_dsc_set_stroke_width
     */
    void set_stroke_width(float width) const noexcept;
    #if LV_USE_MATRIX
    /**
     * Set a matrix to current transformation matrix.
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this matrix.
     * @param matrix  pointer to a matrix
     * @see lv_draw_vector_dsc_set_transform
     */
    void set_transform(Matrix matrix) const noexcept;
    #endif // LV_USE_MATRIX

    /**
     * Change the skew factor of current transformation matrix
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this skew.
     * @param skew_x  the skew factor for x direction
     * @param skew_y  the skew factor for y direction
     * @see lv_draw_vector_dsc_skew
     */
    void skew(float skew_x, float skew_y) const noexcept;
    /**
     * Translate current transformation matrix to new position
     * The new path shapes added by `lv_draw_vector_dsc_add_path` will use this rotation.
     * @param tx  the amount of translate in x direction
     * @param ty  the amount of translate in y direction
     * @see lv_draw_vector_dsc_translate
     */
    void translate(float tx, float ty) const noexcept;
};
static_assert(sizeof(DrawVectorDsc) == sizeof(lv_draw_vector_dsc_t*));
static_assert(__is_trivially_copyable(DrawVectorDsc));
#endif // LV_USE_VECTOR_GRAPHIC

class DrawTask {
protected:
    lv_draw_task_t* p_ = nullptr;

public:
    constexpr DrawTask() noexcept = default;  /**< the "no object" handle */
    constexpr explicit DrawTask(lv_draw_task_t* p) noexcept : p_(p) {}

    constexpr lv_draw_task_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(DrawTask a, DrawTask b) noexcept { return a.p_ == b.p_; }

    /**
     * Try to get an arc draw descriptor from a draw task.
     * @return the task's draw descriptor or NULL if the task is not of type LV_DRAW_TASK_TYPE_ARC
     * @see lv_draw_task_get_arc_dsc
     */
    lv_draw_arc_dsc_t* get_arc_dsc() const noexcept;
    /**
     * Get the draw area of a draw task
     * @return the destination where the draw area will be stored
     * @see lv_draw_task_get_area
     */
    Area get_area() const noexcept;
    /**
     * Try to get a blur draw descriptor from a draw task.
     * @return the task's draw descriptor or NULL if the task is not of type LV_DRAW_TASK_TYPE_BLUR
     * @see lv_draw_task_get_blur_dsc
     */
    lv_draw_blur_dsc_t* get_blur_dsc() const noexcept;
    /**
     * Try to get a border draw descriptor from a draw task.
     * @return the task's draw descriptor or NULL if the task is not of type LV_DRAW_TASK_TYPE_BORDER
     * @see lv_draw_task_get_border_dsc
     */
    lv_draw_border_dsc_t* get_border_dsc() const noexcept;
    /**
     * Try to get a box shadow draw descriptor from a draw task.
     * @return the task's draw descriptor or NULL if the task is not of type LV_DRAW_TASK_TYPE_BOX_SHADOW
     * @see lv_draw_task_get_box_shadow_dsc
     */
    lv_draw_box_shadow_dsc_t* get_box_shadow_dsc() const noexcept;
    /**
     * Get the draw descriptor of a draw task
     * @return a void pointer to the draw descriptor
     * @see lv_draw_task_get_draw_dsc
     */
    void* get_draw_dsc() const noexcept;
    /**
     * Try to get a fill draw descriptor from a draw task.
     * @return the task's draw descriptor or NULL if the task is not of type LV_DRAW_TASK_TYPE_FILL
     * @see lv_draw_task_get_fill_dsc
     */
    lv_draw_fill_dsc_t* get_fill_dsc() const noexcept;
    /**
     * Try to get an image draw descriptor from a draw task.
     * @return the task's draw descriptor or NULL if the task is not of type LV_DRAW_TASK_TYPE_IMAGE
     * @see lv_draw_task_get_image_dsc
     */
    lv_draw_image_dsc_t* get_image_dsc() const noexcept;
    /**
     * Try to get a label draw descriptor from a draw task.
     * @return the task's draw descriptor or NULL if the task is not of type LV_DRAW_TASK_TYPE_LABEL
     * @see lv_draw_task_get_label_dsc
     */
    lv_draw_label_dsc_t* get_label_dsc() const noexcept;
    /**
     * Try to get a line draw descriptor from a draw task.
     * @return the task's draw descriptor or NULL if the task is not of type LV_DRAW_TASK_TYPE_LINE
     * @see lv_draw_task_get_line_dsc
     */
    lv_draw_line_dsc_t* get_line_dsc() const noexcept;
    /**
     * Try to get a triangle draw descriptor from a draw task.
     * @return the task's draw descriptor or NULL if the task is not of type LV_DRAW_TASK_TYPE_TRIANGLE
     * @see lv_draw_task_get_triangle_dsc
     */
    lv_draw_triangle_dsc_t* get_triangle_dsc() const noexcept;
    /**
     * Get the type of a draw task
     * @return the draw task type
     * @see lv_draw_task_get_type
     */
    DrawTaskType get_type() const noexcept;
    #if LV_USE_VECTOR_GRAPHIC
    /**
     * Try to get a vector draw descriptor from a draw task.
     * @return the task's draw descriptor or NULL if the task is not of type LV_DRAW_TASK_TYPE_VECTOR
     * @see lv_draw_task_get_vector_dsc
     */
    DrawVectorDsc get_vector_dsc() const noexcept;
    #endif // LV_USE_VECTOR_GRAPHIC

};
static_assert(sizeof(DrawTask) == sizeof(lv_draw_task_t*));
static_assert(__is_trivially_copyable(DrawTask));

class DrawTriangleDsc {
protected:
    lv_draw_triangle_dsc_t s_;

public:
    DrawTriangleDsc() noexcept { lv_draw_triangle_dsc_init(&s_); }

    DrawTriangleDsc(const DrawTriangleDsc&) = delete;
    DrawTriangleDsc& operator=(const DrawTriangleDsc&) = delete;
    DrawTriangleDsc(DrawTriangleDsc&&) = delete;
    DrawTriangleDsc& operator=(DrawTriangleDsc&&) = delete;

    lv_draw_triangle_dsc_t* raw() noexcept { return &s_; }

};

#if LV_USE_DROPDOWN != 0
class Dropdownlist : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_dropdownlist_class; }

};
static_assert(sizeof(Dropdownlist) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Dropdownlist));
#endif // LV_USE_DROPDOWN != 0

class EventDsc {
protected:
    lv_event_dsc_t* p_ = nullptr;

public:
    constexpr EventDsc() noexcept = default;  /**< the "no object" handle */
    constexpr explicit EventDsc(lv_event_dsc_t* p) noexcept : p_(p) {}

    constexpr lv_event_dsc_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(EventDsc a, EventDsc b) noexcept { return a.p_ == b.p_; }

    /** @see lv_event_dsc_get_cb */
    lv_event_cb_t get_cb() const noexcept;
    /** @see lv_event_dsc_get_user_data */
    void* get_user_data() const noexcept;
};
static_assert(sizeof(EventDsc) == sizeof(lv_event_dsc_t*));
static_assert(__is_trivially_copyable(EventDsc));

class FontInfo {
protected:
    lv_font_info_t* p_ = nullptr;

public:
    constexpr FontInfo() noexcept = default;  /**< the "no object" handle */
    constexpr explicit FontInfo(lv_font_info_t* p) noexcept : p_(p) {}

    constexpr lv_font_info_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(FontInfo a, FontInfo b) noexcept { return a.p_ == b.p_; }

    /**
     * Compare font information.
     * @param ft_info_2  font information 2.
     * @return return true if the fonts are equal.
     * @see lv_font_info_is_equal
     */
    bool is_equal(FontInfo ft_info_2) const noexcept;
};
static_assert(sizeof(FontInfo) == sizeof(lv_font_info_t*));
static_assert(__is_trivially_copyable(FontInfo));

#if LV_USE_FRAGMENT
class FragmentManager {
protected:
    lv_fragment_manager_t* p_ = nullptr;

public:
    constexpr FragmentManager() noexcept = default;  /**< the "no object" handle */
    constexpr explicit FragmentManager(lv_fragment_manager_t* p) noexcept : p_(p) {}

    constexpr lv_fragment_manager_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(FragmentManager a, FragmentManager b) noexcept { return a.p_ == b.p_; }

    /**
     * Attach fragment to manager, and add to container.
     * @param fragment  Fragment instance
     * @param container  Pointer to container object for manager to add objects to
     * @see lv_fragment_manager_add
     */
    void add(Fragment fragment, lv_obj_t* const* container) const noexcept;
    /**
     * Create fragment manager instance
     * @param parent  Parent fragment if this manager is placed inside another fragment, can be null.
     * @return Fragment manager instance
     * @see lv_fragment_manager_create
     */
    static FragmentManager create(Fragment parent) noexcept;
    /**
     * Create object of all fragments managed by this manager.
     * @see lv_fragment_manager_create_obj
     */
    void create_obj() const noexcept;
    /**
     * Destroy fragment manager instance
     * @see lv_fragment_manager_delete
     */
    void delete_() const noexcept;
    /**
     * Delete object created by all fragments managed by this manager. Instance of fragments will not be deleted.
     * @see lv_fragment_manager_delete_obj
     */
    void delete_obj() const noexcept;
    /**
     * Find first fragment instance in the container
     * @param container  Container which target fragment added to
     * @return First fragment instance in the container
     * @see lv_fragment_manager_find_by_container
     */
    Fragment find_by_container(Obj container) const noexcept;
    /**
     * Get parent fragment
     * @return Parent fragment instance
     * @see lv_fragment_manager_get_parent_fragment
     */
    Fragment get_parent_fragment() const noexcept;
    /**
     * Get stack size of this fragment manager
     * @return Stack size of this fragment manager
     * @see lv_fragment_manager_get_stack_size
     */
    uint32_t get_stack_size() const noexcept;
    /**
     * Get top most fragment instance
     * @return Top most fragment instance
     * @see lv_fragment_manager_get_top
     */
    Fragment get_top() const noexcept;
    /**
     * Remove the top-most fragment for stack
     * @return true if there is fragment to pop
     * @see lv_fragment_manager_pop
     */
    bool pop() const noexcept;
    /**
     * Attach fragment to manager and add to navigation stack.
     * @param fragment  Fragment instance
     * @param container  Pointer to container object for manager to add objects to
     * @see lv_fragment_manager_push
     */
    void push(Fragment fragment, lv_obj_t* const* container) const noexcept;
    /**
     * Detach and destroy fragment. If fragment is in navigation stack, remove from it.
     * @param fragment  Fragment instance
     * @see lv_fragment_manager_remove
     */
    void remove(Fragment fragment) const noexcept;
    /**
     * Replace fragment. Old item in the stack will be removed.
     * @param fragment  Fragment instance
     * @param container  Pointer to container object for manager to add objects to
     * @see lv_fragment_manager_replace
     */
    void replace(Fragment fragment, lv_obj_t* const* container) const noexcept;
    /**
     * Send event to top-most fragment
     * @param code  User-defined ID of event
     * @param userdata  User-defined data
     * @return true if fragment returned true
     * @see lv_fragment_manager_send_event
     */
    bool send_event(int32_t code, void* userdata) const noexcept;
};
static_assert(sizeof(FragmentManager) == sizeof(lv_fragment_manager_t*));
static_assert(__is_trivially_copyable(FragmentManager));
#endif // LV_USE_FRAGMENT

class FsDir {
protected:
    lv_fs_dir_t* p_ = nullptr;

public:
    constexpr FsDir() noexcept = default;  /**< the "no object" handle */
    constexpr explicit FsDir(lv_fs_dir_t* p) noexcept : p_(p) {}

    constexpr lv_fs_dir_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(FsDir a, FsDir b) noexcept { return a.p_ == b.p_; }

    /**
     * Close the directory reading
     * @return LV_FS_RES_OK or any error from lv_fs_res_t enum
     * @see lv_fs_dir_close
     */
    FsRes close() const noexcept;
    /**
     * Initialize a 'fs_dir_t' variable for directory reading
     * @param path  path to a directory
     * @return LV_FS_RES_OK or any error from lv_fs_res_t enum
     * @see lv_fs_dir_open
     */
    FsRes open(const char* path) const noexcept;
    /**
     * Read the next filename form a directory.
     * The name of the directories will begin with '/'
     * @param fn  pointer to a buffer to store the filename
     * @param fn_len  length of the buffer to store the filename
     * @return LV_FS_RES_OK or any error from lv_fs_res_t enum
     * @see lv_fs_dir_read
     */
    FsRes read(char* fn, uint32_t fn_len) const noexcept;
};
static_assert(sizeof(FsDir) == sizeof(lv_fs_dir_t*));
static_assert(__is_trivially_copyable(FsDir));

class FsDrv {
protected:
    lv_fs_drv_t s_;

public:
    FsDrv() noexcept { lv_fs_drv_init(&s_); }

    FsDrv(const FsDrv&) = delete;
    FsDrv& operator=(const FsDrv&) = delete;
    FsDrv(FsDrv&&) = delete;
    FsDrv& operator=(FsDrv&&) = delete;

    lv_fs_drv_t* raw() noexcept { return &s_; }

    /**
     * Add a new drive
     * @see lv_fs_drv_register
     */
    FsDrv& register_() noexcept;
};

#if (LV_USE_LIST) && (LV_USE_BUTTON != 0)
class ListButton : public Button {
public:
    using Button::Button;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_list_button_class; }

};
static_assert(sizeof(ListButton) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(ListButton));
#endif // (LV_USE_LIST) && (LV_USE_BUTTON != 0)

#if (LV_USE_LIST) && (LV_USE_LABEL != 0)
class ListText : public Label {
public:
    using Label::Label;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_list_text_class; }

};
static_assert(sizeof(ListText) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(ListText));
#endif // (LV_USE_LIST) && (LV_USE_LABEL != 0)

class MemMonitor {
protected:
    lv_mem_monitor_t* p_ = nullptr;

public:
    constexpr MemMonitor() noexcept = default;  /**< the "no object" handle */
    constexpr explicit MemMonitor(lv_mem_monitor_t* p) noexcept : p_(p) {}

    constexpr lv_mem_monitor_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(MemMonitor a, MemMonitor b) noexcept { return a.p_ == b.p_; }

    /**
     * Used internally by lv_mem_monitor() to gather LVGL heap state information.
     * @see lv_mem_monitor_core
     */
    void core() const noexcept;
};
static_assert(sizeof(MemMonitor) == sizeof(lv_mem_monitor_t*));
static_assert(__is_trivially_copyable(MemMonitor));

#if LV_USE_MENU
class MenuCont : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_menu_cont_class; }

};
static_assert(sizeof(MenuCont) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(MenuCont));

class MenuMainCont : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_menu_main_cont_class; }

};
static_assert(sizeof(MenuMainCont) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(MenuMainCont));

class MenuMainHeaderCont : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_menu_main_header_cont_class; }

};
static_assert(sizeof(MenuMainHeaderCont) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(MenuMainHeaderCont));

class MenuPage : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_menu_page_class; }

    /**
     * Create a menu page object.
     * This call inserts the new page under menu->storage as its parent, which is itself a
     * child of the menu, so the resulting object hierarchy is: menu => storage => new_page
     * where `storage` is a Base Widget.
     * @param menu  pointer to menu object.
     * @param title  pointer to text for title in header (NULL to not display title)
     * @return pointer to the created menu page
     * @see lv_menu_page_create
     */
    static MenuPage create(Obj menu, const char* title) noexcept;
};
static_assert(sizeof(MenuPage) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(MenuPage));

class MenuSection : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_menu_section_class; }

};
static_assert(sizeof(MenuSection) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(MenuSection));

class MenuSeparator : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_menu_separator_class; }

};
static_assert(sizeof(MenuSeparator) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(MenuSeparator));

class MenuSidebarCont : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_menu_sidebar_cont_class; }

};
static_assert(sizeof(MenuSidebarCont) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(MenuSidebarCont));

class MenuSidebarHeaderCont : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_menu_sidebar_header_cont_class; }

};
static_assert(sizeof(MenuSidebarHeaderCont) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(MenuSidebarHeaderCont));
#endif // LV_USE_MENU

#if LV_USE_MONKEY != 0
class MonkeyConfig {
protected:
    lv_monkey_config_t s_;

public:
    MonkeyConfig() noexcept { lv_monkey_config_init(&s_); }

    MonkeyConfig(const MonkeyConfig&) = delete;
    MonkeyConfig& operator=(const MonkeyConfig&) = delete;
    MonkeyConfig(MonkeyConfig&&) = delete;
    MonkeyConfig& operator=(MonkeyConfig&&) = delete;

    lv_monkey_config_t* raw() noexcept { return &s_; }

};
#endif // LV_USE_MONKEY != 0

#if LV_USE_MSGBOX
class MsgboxBackdrop : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_msgbox_backdrop_class; }

};
static_assert(sizeof(MsgboxBackdrop) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(MsgboxBackdrop));

class MsgboxContent : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_msgbox_content_class; }

};
static_assert(sizeof(MsgboxContent) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(MsgboxContent));

class MsgboxFooter : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_msgbox_footer_class; }

};
static_assert(sizeof(MsgboxFooter) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(MsgboxFooter));

class MsgboxFooterButton : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_msgbox_footer_button_class; }

};
static_assert(sizeof(MsgboxFooterButton) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(MsgboxFooterButton));

class MsgboxHeader : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_msgbox_header_class; }

};
static_assert(sizeof(MsgboxHeader) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(MsgboxHeader));

class MsgboxHeaderButton : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_msgbox_header_button_class; }

};
static_assert(sizeof(MsgboxHeaderButton) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(MsgboxHeaderButton));
#endif // LV_USE_MSGBOX

class PointPrecise {
protected:
    lv_point_precise_t* p_ = nullptr;

public:
    constexpr PointPrecise() noexcept = default;  /**< the "no object" handle */
    constexpr explicit PointPrecise(lv_point_precise_t* p) noexcept : p_(p) {}

    constexpr lv_point_precise_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(PointPrecise a, PointPrecise b) noexcept { return a.p_ == b.p_; }

    /** @see lv_point_precise_set */
    void set(lv_value_precise_t x, lv_value_precise_t y) const noexcept;
    /** @see lv_point_precise_swap */
    void swap(PointPrecise p2) const noexcept;
};
static_assert(sizeof(PointPrecise) == sizeof(lv_point_precise_t*));
static_assert(__is_trivially_copyable(PointPrecise));

#if LV_USE_PROFILER && LV_USE_PROFILER_BUILTIN
class ProfilerBuiltinConfig {
protected:
    lv_profiler_builtin_config_t* p_ = nullptr;

public:
    constexpr ProfilerBuiltinConfig() noexcept = default;  /**< the "no object" handle */
    constexpr explicit ProfilerBuiltinConfig(lv_profiler_builtin_config_t* p) noexcept : p_(p) {}

    constexpr lv_profiler_builtin_config_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(ProfilerBuiltinConfig a, ProfilerBuiltinConfig b) noexcept { return a.p_ == b.p_; }

    /**
     * Initialize the configuration of the built-in profiler
     * @see lv_profiler_builtin_config_init
     */
    void init() const noexcept;
};
static_assert(sizeof(ProfilerBuiltinConfig) == sizeof(lv_profiler_builtin_config_t*));
static_assert(__is_trivially_copyable(ProfilerBuiltinConfig));
#endif // LV_USE_PROFILER && LV_USE_PROFILER_BUILTIN

#if LV_USE_SCALE != 0
class ScaleSection {
protected:
    lv_scale_section_t* p_ = nullptr;

public:
    constexpr ScaleSection() noexcept = default;  /**< the "no object" handle */
    constexpr explicit ScaleSection(lv_scale_section_t* p) noexcept : p_(p) {}

    constexpr lv_scale_section_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(ScaleSection a, ScaleSection b) noexcept { return a.p_ == b.p_; }

    /**
     * DEPRECATED, use lv_scale_set_section_range instead.
     * Set range for specified Scale Section
     * @see lv_scale_section_set_range
     */
    void set_range(int32_t min, int32_t max) const noexcept;
    /**
     * DEPRECATED, use lv_scale_set_section_style_main/indicator/items instead.
     * Set style for specified part of Section.
     * @param part  the part of the Scale the style will apply to, e.g. LV_PART_INDICATOR
     * @param section_part_style  pointer to style to apply
     * @see lv_scale_section_set_style
     */
    void set_style(Part part, Style& section_part_style) const noexcept;
};
static_assert(sizeof(ScaleSection) == sizeof(lv_scale_section_t*));
static_assert(__is_trivially_copyable(ScaleSection));
#endif // LV_USE_SCALE != 0

#if LV_USE_OBSERVER
class Subject {
protected:
    lv_subject_t s_;

public:
    template <std::size_t N1>
    Subject(lv_subject_t* (&list)[N1], uint32_t list_len) noexcept { lv_subject_init_group(&s_, list, list_len); }
    ~Subject() { lv_subject_deinit(&s_); }
protected:
    Subject() noexcept = default;
public:


    Subject(const Subject&) = delete;
    Subject& operator=(const Subject&) = delete;
    Subject(Subject&&) = delete;
    Subject& operator=(Subject&&) = delete;

    lv_subject_t* raw() noexcept { return &s_; }

    /**
     * Add Observer to Subject. When Subject's value changes `observer_cb` will be called.
     * @param observer_cb  notification callback
     * @param user_data  optional user data
     * @return pointer to newly-created Observer
     * @see lv_subject_add_observer
     */
    Observer add_observer(lv_observer_cb_t observer_cb, void* user_data) noexcept;
    /**
     * Takes any callable instead of the C pair: the closure travels in the single void* LVGL stores, and the trampoline is chosen by its type.
     * Add Observer to Subject. When Subject's value changes `observer_cb` will be called.
     * @param observer_cb  notification callback
     * @param user_data  optional user data
     * @return pointer to newly-created Observer
     * @see lv_subject_add_observer
     */
    template <class F>
    Observer add_observer(F&& f) noexcept;
    /**
     * Add Observer to Subject for a Widget.
     * When the Widget is deleted, Observer will be unsubscribed from Subject automatically.
     * @param observer_cb  notification callback
     * @param obj  pointer to Widget
     * @param user_data  optional user data
     * @return pointer to newly-created Observer
     * @see lv_subject_add_observer_obj
     */
    Observer add_observer_obj(lv_observer_cb_t observer_cb, Obj obj, void* user_data) noexcept;
    /**
     * Takes any callable instead of the C pair: the closure travels in the single void* LVGL stores, and the trampoline is chosen by its type.
     * Add Observer to Subject for a Widget.
     * When the Widget is deleted, Observer will be unsubscribed from Subject automatically.
     * @param observer_cb  notification callback
     * @param obj  pointer to Widget
     * @param user_data  optional user data
     * @return pointer to newly-created Observer
     * @see lv_subject_add_observer_obj
     */
    template <class F>
    Observer add_observer_obj(Obj obj, F&& f) noexcept;
    /**
     * Add an Observer to a Subject and also save a target pointer.
     * @param observer_cb  notification callback
     * @param target  any pointer (NULL is okay)
     * @param user_data  optional user data
     * @return pointer to newly-created Observer
     * @see lv_subject_add_observer_with_target
     */
    Observer add_observer_with_target(lv_observer_cb_t observer_cb, void* target, void* user_data) noexcept;
    /**
     * Takes any callable instead of the C pair: the closure travels in the single void* LVGL stores, and the trampoline is chosen by its type.
     * Add an Observer to a Subject and also save a target pointer.
     * @param observer_cb  notification callback
     * @param target  any pointer (NULL is okay)
     * @param user_data  optional user data
     * @return pointer to newly-created Observer
     * @see lv_subject_add_observer_with_target
     */
    template <class F>
    Observer add_observer_with_target(void* user_data, F&& f) noexcept;
    /**
     * Remove all Observers from a Subject and free allocated memory, and delete
     * any associated Widget-Binding events.  This leaves `subject` "disconnected" from
     * all Observers and all associated Widget events established through Widget Binding.
     * @see lv_subject_deinit
     */
    Subject& deinit() noexcept;
    /**
     * Get an element from Subject Group's list.
     * @param index  index of element to get
     * @return pointer to indexed Subject from list, or NULL if index is out of bounds
     * @see lv_subject_get_group_element
     */
    lv_subject_t* get_group_element(int32_t index) noexcept;
    /**
     * Notify all Observers of Subject.
     * @see lv_subject_notify
     */
    Subject& notify() noexcept;
    #if LV_USE_EXT_DATA
    /**
     * Attaches external user data to an integer Subject with lifecycle management
     * Associates arbitrary user-defined data with an LVGL observer and registers a destructor
     * callback that will be automatically invoked when the observer is deleted. This enables:
     * - Safe resource cleanup through the destructor mechanism
     * - Contextual data storage for observer callbacks
     * - Proper memory management for observer-related resources
     * @param data  User-defined data pointer to associate
     * @see lv_subject_set_external_data
     */
    Subject& set_external_data(void* data, void (*arg)(void*)) noexcept;
    /**
     * Takes the function itself as a template argument, so its real parameter types survive: the C idiom CASTS the pointer, which is undefined whenever they differ, and between the versions they do.
     * Attaches external user data to an integer Subject with lifecycle management
     * Associates arbitrary user-defined data with an LVGL observer and registers a destructor
     * callback that will be automatically invoked when the observer is deleted. This enables:
     * - Safe resource cleanup through the destructor mechanism
     * - Contextual data storage for observer callbacks
     * - Proper memory management for observer-related resources
     * @param data  User-defined data pointer to associate
     * @see lv_subject_set_external_data
     */
    template <auto Fn>
    Subject& set_external_data(void* data) noexcept;
    #endif // LV_USE_EXT_DATA

    /**
     * Format a new string, updating Subject, and notify Observers if it changed.
     * @param format  format string
     * @see lv_subject_snprintf
     */
    template <typename... A>
    Subject& snprintf(const char* format, A... args) noexcept;
};
#endif // LV_USE_OBSERVER

#if LV_USE_SPAN != 0
class Spangroup : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_spangroup_class; }

    /**
     * Create a span string descriptor and add to spangroup.
     * @return pointer to the created span.
     * @see lv_spangroup_add_span
     */
    Span add_span() const noexcept;
    #if LV_USE_OBSERVER
    /**
     * Bind an integer, string, or pointer Subject to a Spangroup's Span.
     * @param span  pointer to Span
     * @param subject  pointer to Subject
     * @param fmt  optional printf-like format string with 1 format specifier (e.g. "%d °C") or NULL to bind to the value directly.
     * @return pointer to newly-created Observer
     * @see lv_spangroup_bind_span_text
     */
    Observer bind_span_text(Span span, Subject& subject, const char* fmt) const noexcept;
    #endif // LV_USE_OBSERVER

    /**
     * Create a spangroup object
     * @param parent  pointer to an object, it will be the parent of the new spangroup
     * @return pointer to the created spangroup
     * @see lv_spangroup_create
     */
    static Spangroup create(Obj parent) noexcept;
    /**
     * Remove the span from the spangroup and free memory.
     * @param span  pointer to a span.
     * @see lv_spangroup_delete_span
     */
    void delete_span(Span span) const noexcept;
    /**
     * Get the align of the spangroup.
     * @return the align value.
     * @see lv_spangroup_get_align
     */
    TextAlign get_align() const noexcept;
    /**
     * Get a spangroup child by its index.
     * @param id  the index of the child. 0: the oldest (firstly created) child 1: the second oldest child count-1: the youngest -1: the youngest -2: the second youngest
     * @return The child span at index `id`, or NULL if the ID does not exist
     * @see lv_spangroup_get_child
     */
    Span get_child(int32_t id) const noexcept;
    /**
     * Get the text content height with width fixed.
     * @param width  the width of the span group.
     * @see lv_spangroup_get_expand_height
     */
    int32_t get_expand_height(int32_t width) const noexcept;
    /**
     * Get the text content width when all span of spangroup on a line.
     * @param max_width  if text content width >= max_width, return max_width to reduce computation, if max_width == 0, returns the text content width.
     * @return text content width or max_width.
     * @see lv_spangroup_get_expand_width
     */
    uint32_t get_expand_width(uint32_t max_width) const noexcept;
    /**
     * Get the indent of the spangroup.
     * @return the indent value.
     * @see lv_spangroup_get_indent
     */
    int32_t get_indent() const noexcept;
    /**
     * Get max line height of all span in the spangroup.
     * @see lv_spangroup_get_max_line_height
     */
    int32_t get_max_line_height() const noexcept;
    /**
     * Get maximum lines of the spangroup.
     * @return the max lines value.
     * @see lv_spangroup_get_max_lines
     */
    int32_t get_max_lines() const noexcept;
    /**
     * Get the mode of the spangroup.
     * @see lv_spangroup_get_mode
     */
    SpanMode get_mode() const noexcept;
    /**
     * Get the overflow of the spangroup.
     * @return the overflow value.
     * @see lv_spangroup_get_overflow
     */
    SpanOverflow get_overflow() const noexcept;
    /**
     * Get the span object by point.
     * @param point  pointer to point containing absolute coordinates
     * @return pointer to the span under the point or `NULL` if not found.
     * @see lv_spangroup_get_span_by_point
     */
    Span get_span_by_point(const Point& point) const noexcept;
    /**
     * Get the span's coords in the spangroup.
     * @param span  pointer to a span.
     * @return the span's coords in the spangroup.
     * @see lv_spangroup_get_span_coords
     */
    lv_span_coords_t get_span_coords(Span span) const noexcept;
    /**
     * Get number of spans
     * @return the span count of the spangroup.
     * @see lv_spangroup_get_span_count
     */
    uint32_t get_span_count() const noexcept;
    /**
     * Update the mode of the spangroup.
     * @see lv_spangroup_refresh
     */
    void refresh() const noexcept;
    /**
     * DEPRECATED. Use the text_align style property instead
     * Set the align of the spangroup.
     * @param align  see lv_text_align_t for details.
     * @see lv_spangroup_set_align
     */
    void set_align(TextAlign align) const noexcept;
    /**
     * Set the indent of the spangroup.
     * @param indent  the first line indentation
     * @see lv_spangroup_set_indent
     */
    void set_indent(int32_t indent) const noexcept;
    /**
     * Set maximum lines of the spangroup.
     * @param lines  max lines that can be displayed in LV_SPAN_MODE_BREAK mode. < 0 means no limit.
     * @see lv_spangroup_set_max_lines
     */
    void set_max_lines(int32_t lines) const noexcept;
    /**
     * DEPRECATED, set the width to LV_SIZE_CONTENT or fixed value to control expanding/wrapping"
     * Set the mode of the spangroup.
     * @param mode  see lv_span_mode_t for details.
     * @see lv_spangroup_set_mode
     */
    void set_mode(SpanMode mode) const noexcept;
    /**
     * Set the overflow of the spangroup.
     * @param overflow  see lv_span_overflow_t for details.
     * @see lv_spangroup_set_overflow
     */
    void set_overflow(SpanOverflow overflow) const noexcept;
    /**
     * Copy all style properties of style to the bbuilt-in static style of the span.
     * @param span  pointer to a span.
     * @param style  pointer to a style to copy into the span's built-in style
     * @see lv_spangroup_set_span_style
     */
    void set_span_style(Span span, Style& style) const noexcept;
    /**
     * Set a new text for a span. Memory will be allocated to store the text by the span.
     * @param span  pointer to a span.
     * @param text  pointer to a text.
     * @see lv_spangroup_set_span_text
     */
    void set_span_text(Span span, const char* text) const noexcept;
    /**
     * Set a new text for a span using a printf-like formatting string.
     * Memory will be allocated to store the text by the span.
     * @param span  pointer to a span.
     * @param fmt  `printf`-like format string
     * @see lv_spangroup_set_span_text_fmt
     */
    template <typename... A>
    void set_span_text_fmt(Span span, const char* fmt, A... args) const noexcept;
    /**
     * Set a new text for a span. Memory will be allocated to store the text by the span.
     * @param span  pointer to a span.
     * @param text  pointer to a text.
     * @see lv_spangroup_set_span_text_static
     */
    void set_span_text_static(Span span, const char* text) const noexcept;
};
static_assert(sizeof(Spangroup) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Spangroup));
#endif // LV_USE_SPAN != 0

class StyleTransitionDsc {
protected:
    lv_style_transition_dsc_t s_;

public:
    StyleTransitionDsc(const lv_style_prop_t* props, lv_anim_path_cb_t path_cb, uint32_t time, uint32_t delay, void* user_data) noexcept { lv_style_transition_dsc_init(&s_, props, path_cb, time, delay, user_data); }
protected:
    StyleTransitionDsc() noexcept = default;
public:


    StyleTransitionDsc(const StyleTransitionDsc&) = delete;
    StyleTransitionDsc& operator=(const StyleTransitionDsc&) = delete;
    StyleTransitionDsc(StyleTransitionDsc&&) = delete;
    StyleTransitionDsc& operator=(StyleTransitionDsc&&) = delete;

    lv_style_transition_dsc_t* raw() noexcept { return &s_; }

};

#if LV_USE_OBSERVER
/** The color variant of lv_subject_t (LV_SUBJECT_TYPE_COLOR). Its operations live here and not on the base, which is what makes the wrong one a compile error instead of an assertion. */
template <>
class SubjectOf<Color> : public Subject {
public:
    explicit SubjectOf(Color color) noexcept { lv_subject_init_color(&s_, color.raw()); }

    /**
     * Get current value of a color Subject.
     * @return current value
     * @see lv_subject_get_color
     */
    Color get() noexcept;
    /**
     * Get previous value of a color Subject.
     * @return previous value
     * @see lv_subject_get_previous_color
     */
    Color get_previous() noexcept;
    /**
     * Set value of a color Subject and notify Observers if it changed.
     * @param color  new value
     * @see lv_subject_set_color
     */
    void set(Color color) noexcept;
};
static_assert(sizeof(SubjectOf<Color>) == sizeof(Subject));

/** The string variant of lv_subject_t (LV_SUBJECT_TYPE_STRING). Its operations live here and not on the base, which is what makes the wrong one a compile error instead of an assertion. */
template <>
class SubjectOf<const char*> : public Subject {
public:
    template <std::size_t N1, std::size_t N2>
    SubjectOf(char (&buf)[N1], char (&prev_buf)[N2], size_t size, const char* value) noexcept { lv_subject_init_string(&s_, buf, prev_buf, size, value); }

    /**
     * Copy a string to a Subject and notify Observers if it changed.
     * @param buf  new string
     * @see lv_subject_copy_string
     */
    void copy(const char* buf) noexcept;
    /**
     * Get previous value of a string Subject.
     * @return pointer to buffer containing previous value
     * @see lv_subject_get_previous_string
     */
    const char* get_previous() noexcept;
    /**
     * Get current value of a string Subject.
     * @return pointer to buffer containing current value
     * @see lv_subject_get_string
     */
    const char* get() noexcept;
};
static_assert(sizeof(SubjectOf<const char*>) == sizeof(Subject));
#endif // LV_USE_OBSERVER

#if (LV_USE_OBSERVER) && (LV_USE_FLOAT)
/** The float variant of lv_subject_t (LV_SUBJECT_TYPE_FLOAT). Its operations live here and not on the base, which is what makes the wrong one a compile error instead of an assertion. */
template <>
class SubjectOf<float> : public Subject {
public:
    explicit SubjectOf(float value) noexcept { lv_subject_init_float(&s_, value); }

    /**
     * Get current value of an float Subject.
     * @return current value
     * @see lv_subject_get_float
     */
    float get() noexcept;
    /**
     * Get previous value of an float Subject.
     * @return current value
     * @see lv_subject_get_previous_float
     */
    float get_previous() noexcept;
    /**
     * Set value of an float Subject and notify Observers.
     * @param value  new value
     * @see lv_subject_set_float
     */
    void set(float value) noexcept;
    /**
     * Set a maximum value for a float subject
     * @param max_value  the maximum value
     * @see lv_subject_set_max_value_float
     */
    void set_max_value(float max_value) noexcept;
    /**
     * Set a minimum value for a float subject
     * @param min_value  the minimum value
     * @see lv_subject_set_min_value_float
     */
    void set_min_value(float min_value) noexcept;
};
static_assert(sizeof(SubjectOf<float>) == sizeof(Subject));
#endif // (LV_USE_OBSERVER) && (LV_USE_FLOAT)

/** @see lv_style_const_prop_id_inv */
inline constexpr const lv_style_prop_t* style_const_prop_id_inv = &lv_style_const_prop_id_inv;

#if LV_USE_OBSERVER
/** The int variant of lv_subject_t (LV_SUBJECT_TYPE_INT). Its operations live here and not on the base, which is what makes the wrong one a compile error instead of an assertion. */
template <>
class SubjectOf<int32_t> : public Subject {
public:
    explicit SubjectOf(int32_t value) noexcept { lv_subject_init_int(&s_, value); }

    /**
     * Get current value of an integer Subject.
     * @return current value
     * @see lv_subject_get_int
     */
    int32_t get() noexcept;
    /**
     * Get previous value of an integer Subject.
     * @return current value
     * @see lv_subject_get_previous_int
     */
    int32_t get_previous() noexcept;
    /**
     * Set value of an integer Subject and notify Observers.
     * @param value  new value
     * @see lv_subject_set_int
     */
    void set(int32_t value) noexcept;
    /**
     * Set a maximum value for an integer subject
     * @param max_value  the maximum value
     * @see lv_subject_set_max_value_int
     */
    void set_max_value(int32_t max_value) noexcept;
    /**
     * Set a minimum value for an integer subject
     * @param min_value  the minimum value
     * @see lv_subject_set_min_value_int
     */
    void set_min_value(int32_t min_value) noexcept;
};
static_assert(sizeof(SubjectOf<int32_t>) == sizeof(Subject));

/** The pointer variant of lv_subject_t (LV_SUBJECT_TYPE_POINTER). Its operations live here and not on the base, which is what makes the wrong one a compile error instead of an assertion. */
template <>
class SubjectOf<void*> : public Subject {
public:
    explicit SubjectOf(void* value) noexcept { lv_subject_init_pointer(&s_, value); }

    /**
     * Get current value of a pointer Subject.
     * @return current value
     * @see lv_subject_get_pointer
     */
    const void* get() noexcept;
    /**
     * Get previous value of a pointer Subject.
     * @return previous value
     * @see lv_subject_get_previous_pointer
     */
    const void* get_previous() noexcept;
    /**
     * Set value of a pointer Subject and notify Observers (regardless of whether it changed).
     * @param ptr  new value
     * @see lv_subject_set_pointer
     */
    void set(void* ptr) noexcept;
};
static_assert(sizeof(SubjectOf<void*>) == sizeof(Subject));
#endif // LV_USE_OBSERVER

#if LV_USE_SVG
class SvgNode {
protected:
    lv_svg_node_t* p_ = nullptr;

public:
    constexpr SvgNode() noexcept = default;  /**< the "no object" handle */
    constexpr explicit SvgNode(lv_svg_node_t* p) noexcept : p_(p) {}

    constexpr lv_svg_node_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(SvgNode a, SvgNode b) noexcept { return a.p_ == b.p_; }

    /**
     * Create an SVG DOM node
     * @param parent  pointer to the parent node
     * @return true: an new SVG DOM node, false: NULL
     * @see lv_svg_node_create
     */
    static SvgNode create(SvgNode parent) noexcept;
    /**
     * Delete an SVG DOM subtree
     * @see lv_svg_node_delete
     */
    void delete_() const noexcept;
};
static_assert(sizeof(SvgNode) == sizeof(lv_svg_node_t*));
static_assert(__is_trivially_copyable(SvgNode));
#endif // LV_USE_SVG

#if LV_USE_TILEVIEW
class TileviewTile : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_tileview_tile_class; }

};
static_assert(sizeof(TileviewTile) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(TileviewTile));
#endif // LV_USE_TILEVIEW

class TreeNode {
protected:
    lv_tree_node_t* p_ = nullptr;

public:
    constexpr TreeNode() noexcept = default;  /**< the "no object" handle */
    constexpr explicit TreeNode(lv_tree_node_t* p) noexcept : p_(p) {}

    constexpr lv_tree_node_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(TreeNode a, TreeNode b) noexcept { return a.p_ == b.p_; }

    /**
     * Create a tree node
     * @param class_p  pointer to a class of the node
     * @param parent  pointer to the parent node (or NULL if it's the root node)
     * @return pointer to the new node
     * @see lv_tree_node_create
     */
    static TreeNode create(const lv_tree_class_t* class_p, TreeNode parent) noexcept;
    /**
     * Delete a tree node and all its children recursively
     * @see lv_tree_node_delete
     */
    void delete_() const noexcept;
};
static_assert(sizeof(TreeNode) == sizeof(lv_tree_node_t*));
static_assert(__is_trivially_copyable(TreeNode));

/**
 * Wrapper functions for VERSION macros
 * @see lv_version_major
 */
inline int32_t version_major() noexcept;

/** @see lv_version_minor */
inline int32_t version_minor() noexcept;

/** @see lv_version_patch */
inline int32_t version_patch() noexcept;

/** @see lv_version_info */
inline const char* version_info() noexcept;

/**
 * Register a new style property for custom usage
 * @see lv_style_register_prop
 */
inline lv_style_prop_t style_register_prop(uint8_t flag) noexcept;

/**
 * Get the number of custom properties that have been registered thus far.
 * @see lv_style_get_num_custom_props
 */
inline lv_style_prop_t style_get_num_custom_props() noexcept;

/**
 * Get the default value of a property
 * @param prop  the ID of a property
 * @return the default value
 * @see lv_style_prop_get_default
 */
inline lv_style_value_t style_prop_get_default(lv_style_prop_t prop) noexcept;

/**
 * Tell the group of a property. If the a property from a group is set in a style the (1 << group) bit of style->has_group is set.
 * It allows early skipping the style if the property is not exists in the style at all.
 * @param prop  a style property
 * @return the group [0..30] 30 means all the custom properties with index > 120
 * @see lv_style_get_prop_group
 */
inline uint32_t style_get_prop_group(lv_style_prop_t prop) noexcept;

/**
 * Get the flags of a built-in or custom property.
 * @param prop  a style property
 * @return the flags of the property
 * @see lv_style_prop_lookup_flags
 */
inline uint8_t style_prop_lookup_flags(lv_style_prop_t prop) noexcept;

/**
 * Check if the style property has a specified behavioral flag.
 * Do not pass multiple flags to this function as backwards-compatibility is not guaranteed
 * for that.
 * @param prop  Property ID
 * @param flag  Flag
 * @return true if the flag is set for this property
 * @see lv_style_prop_has_flag
 */
inline bool style_prop_has_flag(lv_style_prop_t prop, uint8_t flag) noexcept;

} // namespace lv
