#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lv/widgets/image/image.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

class DrawBuf {
protected:
    lv_draw_buf_t* p_ = nullptr;

public:
    constexpr DrawBuf() noexcept = default;  /**< the "no object" handle */
    constexpr explicit DrawBuf(lv_draw_buf_t* p) noexcept : p_(p) {}

    constexpr lv_draw_buf_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(DrawBuf a, DrawBuf b) noexcept { return a.p_ == b.p_; }

    /**
     * Adjust the stride of a draw buf in place.
     * @param stride  the new stride in bytes for image. Use LV_STRIDE_AUTO for automatic calculation.
     * @return LV_RESULT_OK: success or LV_RESULT_INVALID: failed
     * @see lv_draw_buf_adjust_stride
     */
    Result adjust_stride(uint32_t stride) const noexcept;
    /**
     * Clear an area on the buffer
     * @param a  the area to clear, or NULL to clear the whole buffer
     * @see lv_draw_buf_clear
     */
    void clear(const Area& a) const noexcept;
    /**
     * Clear a flag from a draw buffer.
     * @param flag  the flag to clear
     * @see lv_draw_buf_clear_flag
     */
    void clear_flag(Image::Flags flag) const noexcept;
    /**
     * Copy an area from a buffer to another
     * @param dest_area  the area to copy from the destination buffer, if NULL, use the whole buffer
     * @param src  pointer to the source draw buffer
     * @param src_area  the area to copy from the destination buffer, if NULL, use the whole buffer
     * @see lv_draw_buf_copy
     */
    void copy(const Area& dest_area, DrawBuf src, const Area& src_area) const noexcept;
    /**
     * Note: Eventually, lv_draw_buf_malloc/free will be kept as private.
     * For now, we use `create` to distinguish with malloc.
     * Create an draw buf by allocating struct for `lv_draw_buf_t` and allocating a buffer for it
     * that meets specified requirements.
     * @param w  the buffer width in pixels
     * @param h  the buffer height in pixels
     * @param cf  the color format for image
     * @param stride  the stride in bytes for image. Use 0 for automatic calculation based on w, cf, and global stride alignment configuration.
     * @see lv_draw_buf_create
     */
    static DrawBuf create(uint32_t w, uint32_t h, ColorFormat cf, uint32_t stride) noexcept;
    /**
     * Destroy a draw buf by freeing the actual buffer if it's marked as LV_IMAGE_FLAGS_ALLOCATED in header.
     * Then free the lv_draw_buf_t struct.
     * @see lv_draw_buf_destroy
     */
    void destroy() const noexcept;
    /**
     * Duplicate a draw buf with same image size, stride and color format. Copy the image data too.
     * @return the duplicated draw buf on success, NULL if failed
     * @see lv_draw_buf_dup
     */
    DrawBuf dup() const noexcept;
    /**
     * Flush the cache of the buffer
     * @param area  the area to flush in the buffer, use NULL to flush the whole draw buffer address range
     * @see lv_draw_buf_flush_cache
     */
    void flush_cache(const Area& area) const noexcept;
    /**
     * As of now, draw buf share same definition as `lv_image_dsc_t`.
     * And is interchangeable with `lv_image_dsc_t`.
     * @see lv_draw_buf_from_image
     */
    Result from_image(const lv_image_dsc_t* img) const noexcept;
    /**
     * Return pointer to the buffer at the given coordinates
     * @see lv_draw_buf_goto_xy
     */
    void* goto_xy(uint32_t x, uint32_t y) const noexcept;
    /**
     * Check if a draw buffer has a given flag.
     * @param flag  the flag to check
     * @return true: the flag is set, false: the flag is not set
     * @see lv_draw_buf_has_flag
     */
    bool has_flag(Image::Flags flag) const noexcept;
    /**
     * Initialize a draw buf with the given buffer and parameters. Clear draw buffer flag to zero.
     * @param w  the buffer width in pixels
     * @param h  the buffer height in pixels
     * @param cf  the color format
     * @param stride  the stride in bytes. Use 0 for automatic calculation
     * @param data  the buffer used for drawing. Unaligned `data` will be aligned internally
     * @param data_size  the size of the buffer in bytes
     * @return return LV_RESULT_OK on success, LV_RESULT_INVALID otherwise
     * @see lv_draw_buf_init
     */
    Result init(uint32_t w, uint32_t h, ColorFormat cf, uint32_t stride, void* data, uint32_t data_size) const noexcept;
    /**
     * Invalidate the cache of the buffer
     * @param area  the area to invalidate in the buffer, use NULL to invalidate the whole draw buffer address range
     * @see lv_draw_buf_invalidate_cache
     */
    void invalidate_cache(const Area& area) const noexcept;
    /**
     * Premultiply draw buffer color with alpha channel.
     * If it's already premultiplied, return directly.
     * Only color formats with alpha channel will be processed.
     * @return LV_RESULT_OK: premultiply success
     * @see lv_draw_buf_premultiply
     */
    Result premultiply() const noexcept;
    /**
     * Keep using the existing memory, reshape the draw buffer to the given width and height.
     * Return NULL if data_size is smaller than the required size.
     * @param cf  the new color format, use 0 or LV_COLOR_FORMAT_UNKNOWN to keep using the original color format.
     * @param w  the new width in pixels
     * @param h  the new height in pixels
     * @param stride  the stride in bytes for image. Use 0 for automatic calculation.
     * @see lv_draw_buf_reshape
     */
    DrawBuf reshape(ColorFormat cf, uint32_t w, uint32_t h, uint32_t stride) const noexcept;
    /**
     * Save a draw buf to a file
     * @param path  path to the file to save
     * @return LV_RESULT_OK: success; LV_RESULT_INVALID: error
     * @see lv_draw_buf_save_to_file
     */
    Result save_to_file(const char* path) const noexcept;
    /**
     * Set a flag to a draw buffer.
     * @param flag  the flag to set
     * @see lv_draw_buf_set_flag
     */
    void set_flag(Image::Flags flag) const noexcept;
    /**
     * Set the palette color of an indexed image. Valid only for `LV_COLOR_FORMAT_I1/2/4/8`
     * @param index  the palette color to set: - for `LV_COLOR_FORMAT_I1`: 0..1 - for `LV_COLOR_FORMAT_I2`: 0..3 - for `LV_COLOR_FORMAT_I4`: 0..15 - for `LV_COLOR_FORMAT_I8`: 0..255
     * @param color  the color to set in lv_color32_t format
     * @see lv_draw_buf_set_palette
     */
    void set_palette(uint8_t index, lv_color32_t color) const noexcept;
    /** @see lv_draw_buf_to_image */
    void to_image(lv_image_dsc_t* img) const noexcept;
};
static_assert(sizeof(DrawBuf) == sizeof(lv_draw_buf_t*));
static_assert(__is_trivially_copyable(DrawBuf));

/**
 * Initialize the draw buffer with the default handlers.
 * @param handlers  the draw buffer handlers to set
 * @see lv_draw_buf_init_with_default_handlers
 */
inline void draw_buf_init_with_default_handlers(DrawBufHandlers handlers) noexcept;

/**
 * Get the struct which holds the callbacks for draw buf management.
 * Custom callback can be set on the returned value
 * @return pointer to the struct of handlers
 * @see lv_draw_buf_get_handlers
 */
inline DrawBufHandlers draw_buf_get_handlers() noexcept;

/** @see lv_draw_buf_get_font_handlers */
inline DrawBufHandlers draw_buf_get_font_handlers() noexcept;

/** @see lv_draw_buf_get_image_handlers */
inline DrawBufHandlers draw_buf_get_image_handlers() noexcept;

/**
 * Align the address of a buffer. The buffer needs to be large enough for the real data after alignment
 * @param buf  the data to align
 * @param color_format  the color format of the buffer
 * @return the aligned buffer
 * @see lv_draw_buf_align
 */
inline void* draw_buf_align(void* buf, ColorFormat color_format) noexcept;

/**
 * Align the address of a buffer with custom draw buffer handlers.
 * The buffer needs to be large enough for the real data after alignment
 * @param handlers  the draw buffer handlers
 * @param buf  the data to align
 * @param color_format  the color format of the buffer
 * @return the aligned buffer
 * @see lv_draw_buf_align_ex
 */
inline void* draw_buf_align_ex(DrawBufHandlers handlers, void* buf, ColorFormat color_format) noexcept;

/**
 * Calculate the stride in bytes based on a width and color format
 * @param w  the width in pixels
 * @param color_format  the color format
 * @return the stride in bytes
 * @see lv_draw_buf_width_to_stride
 */
inline uint32_t draw_buf_width_to_stride(uint32_t w, ColorFormat color_format) noexcept;

/**
 * Calculate the stride in bytes based on a width and color format
 * @param handlers  the draw buffer handlers
 * @param w  the width in pixels
 * @param color_format  the color format
 * @return the stride in bytes
 * @see lv_draw_buf_width_to_stride_ex
 */
inline uint32_t draw_buf_width_to_stride_ex(DrawBufHandlers handlers, uint32_t w, ColorFormat color_format) noexcept;

/**
 * Note: Eventually, lv_draw_buf_malloc/free will be kept as private.
 * For now, we use `create` to distinguish with malloc.
 * Create an draw buf by allocating struct for `lv_draw_buf_t` and allocating a buffer for it
 * that meets specified requirements.
 * @param handlers  the draw buffer handlers
 * @param w  the buffer width in pixels
 * @param h  the buffer height in pixels
 * @param cf  the color format for image
 * @param stride  the stride in bytes for image. Use 0 for automatic calculation based on w, cf, and global stride alignment configuration.
 * @see lv_draw_buf_create_ex
 */
inline DrawBuf draw_buf_create_ex(DrawBufHandlers handlers, uint32_t w, uint32_t h, ColorFormat cf, uint32_t stride) noexcept;

/**
 * Duplicate a draw buf with same image size, stride and color format. Copy the image data too.
 * @param handlers  the draw buffer handlers
 * @param draw_buf  the draw buf to duplicate
 * @return the duplicated draw buf on success, NULL if failed
 * @see lv_draw_buf_dup_ex
 */
inline DrawBuf draw_buf_dup_ex(DrawBufHandlers handlers, DrawBuf draw_buf) noexcept;

/** @see lv_image_buf_set_palette */
inline void image_buf_set_palette(lv_image_dsc_t* dsc, uint8_t id, lv_color32_t c) noexcept;

/** @see lv_image_buf_free */
inline void image_buf_free(lv_image_dsc_t* dsc) noexcept;

} // namespace lv
