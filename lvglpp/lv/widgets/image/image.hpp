#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core/obj.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_IMAGE != 0
class Image : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_image_class; }

    /** Source of image. */
    enum class Src : int {
        Variable = LV_IMAGE_SRC_VARIABLE,
        /** Binary/C variable */
        File = LV_IMAGE_SRC_FILE,
        /** File in filesystem */
        Symbol = LV_IMAGE_SRC_SYMBOL,
        /** Symbol (@ref lv_symbol_def.h) */
        Unknown = LV_IMAGE_SRC_UNKNOWN,
    };

    enum class Flags : int {
        /**
         * For RGB map of the image data, mark if it's pre-multiplied with alpha.
         * For indexed image, this bit indicated palette data is pre-multiplied with alpha.
         */
        Premultiplied = LV_IMAGE_FLAGS_PREMULTIPLIED,
        /**
         * The image data is compressed, so decoder needs to decode image firstly.
         * If this flag is set, the whole image will be decompressed upon decode, and
         * `get_area_cb` won't be necessary.
         */
        Compressed = LV_IMAGE_FLAGS_COMPRESSED,
        /** The image is allocated from heap, thus should be freed after use. */
        Allocated = LV_IMAGE_FLAGS_ALLOCATED,
        /**
         * If the image data is malloced and can be processed in place.
         * In image decoder post processing, this flag means we modify it in-place.
         */
        Modifiable = LV_IMAGE_FLAGS_MODIFIABLE,
        /** The image has custom drawing methods. */
        CustomDraw = LV_IMAGE_FLAGS_CUSTOM_DRAW,
        /** Flags reserved for user, lvgl won't use these bits. */
        User1 = LV_IMAGE_FLAGS_USER1,
        User2 = LV_IMAGE_FLAGS_USER2,
        User3 = LV_IMAGE_FLAGS_USER3,
        User4 = LV_IMAGE_FLAGS_USER4,
        User5 = LV_IMAGE_FLAGS_USER5,
        User6 = LV_IMAGE_FLAGS_USER6,
        User7 = LV_IMAGE_FLAGS_USER7,
        User8 = LV_IMAGE_FLAGS_USER8,
    };

    enum class Compress : int {
        None = LV_IMAGE_COMPRESS_NONE,
        /** LVGL custom RLE compression */
        Rle = LV_IMAGE_COMPRESS_RLE,
        Lz4 = LV_IMAGE_COMPRESS_LZ4,
    };

    /** Image size mode, when image size and object size is different */
    enum class Align : int {
        Default = LV_IMAGE_ALIGN_DEFAULT,
        TopLeft = LV_IMAGE_ALIGN_TOP_LEFT,
        TopMid = LV_IMAGE_ALIGN_TOP_MID,
        TopRight = LV_IMAGE_ALIGN_TOP_RIGHT,
        BottomLeft = LV_IMAGE_ALIGN_BOTTOM_LEFT,
        BottomMid = LV_IMAGE_ALIGN_BOTTOM_MID,
        BottomRight = LV_IMAGE_ALIGN_BOTTOM_RIGHT,
        LeftMid = LV_IMAGE_ALIGN_LEFT_MID,
        RightMid = LV_IMAGE_ALIGN_RIGHT_MID,
        Center = LV_IMAGE_ALIGN_CENTER,
        /** Marks the start of modes that transform the image */
        AutoTransform = _LV_IMAGE_ALIGN_AUTO_TRANSFORM,
        /** Set X and Y scale to fill the Widget's area. */
        Stretch = LV_IMAGE_ALIGN_STRETCH,
        /** Tile image to fill Widget's area. Offset is applied to shift the tiling. */
        Tile = LV_IMAGE_ALIGN_TILE,
        /** The image keeps its aspect ratio, but is resized to the maximum size that fits within the Widget's area. */
        Contain = LV_IMAGE_ALIGN_CONTAIN,
        /** The image keeps its aspect ratio and fills the Widget's area. */
        Cover = LV_IMAGE_ALIGN_COVER,
    };

    #if LV_USE_OBSERVER
    /**
     * Bind a pointer Subject to an Image's source.
     * @param subject  pointer to Subject
     * @return pointer to newly-created Observer
     * @see lv_image_bind_src
     */
    Observer bind_src(Subject& subject) const noexcept;
    #endif // LV_USE_OBSERVER

    /**
     * Create an image object
     * @param parent  pointer to an object, it will be the parent of the new image
     * @return pointer to the created image
     * @see lv_image_create
     */
    static Image create(Obj parent) noexcept;
    /**
     * Get whether the transformations (rotate, zoom) are anti-aliased or not
     * @return true: anti-aliased; false: not anti-aliased
     * @see lv_image_get_antialias
     */
    bool get_antialias() const noexcept;
    /**
     * Get the bitmap mask source.
     * @return an lv_image_dsc_t bitmap mask source.
     * @see lv_image_get_bitmap_map_src
     */
    const lv_image_dsc_t* get_bitmap_map_src() const noexcept;
    /**
     * Get the current blend mode of the image
     * @return the current blend mode
     * @see lv_image_get_blend_mode
     */
    BlendMode get_blend_mode() const noexcept;
    /**
     * Get the size mode of the image
     * @return element of `lv_image_align_t`
     * @see lv_image_get_inner_align
     */
    Image::Align get_inner_align() const noexcept;
    /**
     * Get the offset's x attribute of the image object.
     * @return offset X value.
     * @see lv_image_get_offset_x
     */
    int32_t get_offset_x() const noexcept;
    /**
     * Get the offset's y attribute of the image object.
     * @return offset Y value.
     * @see lv_image_get_offset_y
     */
    int32_t get_offset_y() const noexcept;
    /**
     * Get the pivot (rotation center) of the image.
     * If pivot is set with LV_PCT, convert it to px before return.
     * @return store the rotation center here
     * @see lv_image_get_pivot
     */
    Point get_pivot() const noexcept;
    /**
     * Get the rotation of the image.
     * @return rotation in 0.1 degrees (0..3600)
     * @see lv_image_get_rotation
     */
    int32_t get_rotation() const noexcept;
    /**
     * Get the zoom factor of the image.
     * @return zoom factor (256: no zoom)
     * @see lv_image_get_scale
     */
    int32_t get_scale() const noexcept;
    /**
     * Get the horizontal zoom factor of the image.
     * @return zoom factor (256: no zoom)
     * @see lv_image_get_scale_x
     */
    int32_t get_scale_x() const noexcept;
    /**
     * Get the vertical zoom factor of the image.
     * @return zoom factor (256: no zoom)
     * @see lv_image_get_scale_y
     */
    int32_t get_scale_y() const noexcept;
    /**
     * Get the source of the image
     * @return the image source (symbol, file name or ::lv-img_dsc_t for C arrays)
     * @see lv_image_get_src
     */
    const void* get_src() const noexcept;
    /**
     * Get the height of an image before any transformations.
     * @return The height of the image.
     * @see lv_image_get_src_height
     */
    int32_t get_src_height() const noexcept;
    /**
     * Get the width of an image before any transformations.
     * @return The width of the image.
     * @see lv_image_get_src_width
     */
    int32_t get_src_width() const noexcept;
    /**
     * Get the transformed height of an image object.
     * @return The transformed height of the image.
     * @see lv_image_get_transformed_height
     */
    int32_t get_transformed_height() const noexcept;
    /**
     * Get the transformed width of an image object.
     * @return The transformed width of the image.
     * @see lv_image_get_transformed_width
     */
    int32_t get_transformed_width() const noexcept;
    /**
     * Enable/disable anti-aliasing for the transformations (rotate, zoom) or not.
     * The quality is better with anti-aliasing looks better but slower.
     * @param antialias  true: anti-aliased; false: not anti-aliased
     * @see lv_image_set_antialias
     */
    void set_antialias(bool antialias) const noexcept;
    /**
     * Set an A8 bitmap mask for the image.
     * @param src  an lv_image_dsc_t bitmap mask source.
     * @see lv_image_set_bitmap_map_src
     */
    void set_bitmap_map_src(const lv_image_dsc_t* src) const noexcept;
    /**
     * Set the blend mode of an image.
     * @param blend_mode  the new blend mode
     * @see lv_image_set_blend_mode
     */
    void set_blend_mode(BlendMode blend_mode) const noexcept;
    /**
     * Set the image object size mode.
     * @param align  the new align mode.
     * @see lv_image_set_inner_align
     */
    void set_inner_align(Image::Align align) const noexcept;
    /**
     * Set an offset for the source of an image so the image will be displayed from the new origin.
     * @param x  the new offset along x axis.
     * @see lv_image_set_offset_x
     */
    void set_offset_x(int32_t x) const noexcept;
    /**
     * Set an offset for the source of an image.
     * so the image will be displayed from the new origin.
     * @param y  the new offset along y axis.
     * @see lv_image_set_offset_y
     */
    void set_offset_y(int32_t y) const noexcept;
    /**
     * Set the rotation center of the image.
     * The image will be rotated around this point.
     * x, y can be set with value of LV_PCT, lv_image_get_pivot will return the true pixel coordinate of pivot in this case.
     * @param x  rotation center x of the image
     * @param y  rotation center y of the image
     * @see lv_image_set_pivot
     */
    void set_pivot(int32_t x, int32_t y) const noexcept;
    /**
     * Set the rotation horizontal center of the image.
     * @param x  rotation center x of the image, or lv_pct()
     * @see lv_image_set_pivot_x
     */
    void set_pivot_x(int32_t x) const noexcept;
    /**
     * Set the rotation vertical center of the image.
     * @param y  rotation center y of the image, or lv_pct()
     * @see lv_image_set_pivot_y
     */
    void set_pivot_y(int32_t y) const noexcept;
    /**
     * Set the rotation angle of the image.
     * The image will be rotated around the set pivot set by `lv_image_set_pivot()`
     * Note that indexed and alpha only images can't be transformed.
     * @param angle  rotation in degree with 0.1 degree resolution (0..3600: clock wise)
     * @see lv_image_set_rotation
     */
    void set_rotation(int32_t angle) const noexcept;
    /**
     * Set the zoom factor of the image.
     * Note that indexed and alpha only images can't be transformed.
     * @param zoom  the zoom factor. Example values: - 256 or LV_SCALE_NONE: no zoom - <256: scale down - >256: scale up - 128: half size - 512: double size
     * @see lv_image_set_scale
     */
    void set_scale(uint32_t zoom) const noexcept;
    /**
     * Set the horizontal zoom factor of the image.
     * Note that indexed and alpha only images can't be transformed.
     * @param zoom  the zoom factor. Example values: - 256 or LV_SCALE_NONE: no zoom - <256: scale down - >256: scale up - 128: half size - 512: double size
     * @see lv_image_set_scale_x
     */
    void set_scale_x(uint32_t zoom) const noexcept;
    /**
     * Set the vertical zoom factor of the image.
     * Note that indexed and alpha only images can't be transformed.
     * @param zoom  the zoom factor. Example values: - 256 or LV_SCALE_NONE: no zoom - <256: scale down - >256: scale up - 128: half size - 512: double size
     * @see lv_image_set_scale_y
     */
    void set_scale_y(uint32_t zoom) const noexcept;
    /**
     * Set the image data to display on the object
     * @param src  1) pointer to an ::lv_image_dsc_t descriptor (converted by LVGL's image converter) (e.g. &my_img) or 2) path to an image file (e.g. "S:/dir/img.bin")or 3) a SYMBOL (e.g. LV_SYMBOL_OK)
     * @see lv_image_set_src
     */
    void set_src(const void* src) const noexcept;
    #if LVPP_COMPAT_V8
    /** v8 spelling of `create`. */
    static Image img_create(Obj parent) noexcept;
    /** v8 spelling of `set_src`. */
    void img_set_src(const void* src) const noexcept;
    /** v8 spelling of `set_offset_x`. */
    void img_set_offset_x(int32_t x) const noexcept;
    /** v8 spelling of `set_offset_y`. */
    void img_set_offset_y(int32_t y) const noexcept;
    /** v8 spelling of `set_rotation`. */
    void img_set_angle(int32_t angle) const noexcept;
    /** v8 spelling of `set_pivot`. */
    void img_set_pivot(int32_t x, int32_t y) const noexcept;
    /** v8 spelling of `set_scale`. */
    void img_set_zoom(uint32_t zoom) const noexcept;
    /** v8 spelling of `set_antialias`. */
    void img_set_antialias(bool antialias) const noexcept;
    /** v8 spelling of `get_src`. */
    const void* img_get_src() const noexcept;
    /** v8 spelling of `get_offset_x`. */
    int32_t img_get_offset_x() const noexcept;
    /** v8 spelling of `get_offset_y`. */
    int32_t img_get_offset_y() const noexcept;
    /** v8 spelling of `get_rotation`. */
    int32_t img_get_angle() const noexcept;
    /** v8 spelling of `get_pivot`. */
    Point img_get_pivot() const noexcept;
    /** v8 spelling of `get_scale`. */
    int32_t img_get_zoom() const noexcept;
    /** v8 spelling of `get_antialias`. */
    bool img_get_antialias() const noexcept;
    #endif // LVPP_COMPAT_V8

};
static_assert(sizeof(Image) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Image));
#endif // LV_USE_IMAGE != 0

} // namespace lv
