#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core.hpp"
#include "lv/core/obj.hpp"
#include "lv/draw/draw_buf.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lv/widgets/image/image.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if (LV_USE_CANVAS != 0) && (LV_USE_IMAGE != 0)
class Canvas : public Image {
public:
    using Image::Image;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_canvas_class; }

    /**
     * Copy a buffer to the canvas
     * @param canvas_area  the area of the canvas to copy the new data to
     * @param src_buf  pointer to a buffer holding the source data
     * @param src_area  the area of the source buffer to copy from. If NULL, copy the whole buffer.
     * @see lv_canvas_copy_buf
     */
    void copy_buf(const Area& canvas_area, DrawBuf src_buf, const Area& src_area) const noexcept { lv_canvas_copy_buf(p_, canvas_area.ptr(), src_buf.raw(), src_area.ptr()); }
    /**
     * Create a canvas object
     * @param parent  pointer to an object, it will be the parent of the new canvas
     * @return pointer to the created canvas
     * @see lv_canvas_create
     */
    static Canvas create(Obj parent) noexcept { return Canvas(lv_canvas_create(parent.raw())); }
    /**
     * Fill the canvas with color
     * @param color  the background color
     * @param opa  the desired opacity
     * @see lv_canvas_fill_bg
     */
    void fill_bg(Color color, lv_opa_t opa) const noexcept { lv_canvas_fill_bg(p_, color.raw(), opa); }
    /**
     * Wait until all the drawings are finished on layer.
     * Needs to be usd in pair with `lv_canvas_init_layer`.
     * @param layer  pointer to a layer to finalize
     * @see lv_canvas_finish_layer
     */
    void finish_layer(Layer& layer) const noexcept { lv_canvas_finish_layer(p_, layer.raw()); }
    /**
     * Return the pointer for the buffer.
     * It's recommended to use this function instead of the buffer form the
     * return value of lv_canvas_get_image() as is can be aligned
     * @return pointer to the buffer
     * @see lv_canvas_get_buf
     */
    const void* get_buf() const noexcept { return lv_canvas_get_buf(p_); }
    /** @see lv_canvas_get_draw_buf */
    DrawBuf get_draw_buf() const noexcept { return DrawBuf(lv_canvas_get_draw_buf(p_)); }
    /**
     * Get the image of the canvas as a pointer to an `lv_image_dsc_t` variable.
     * @return pointer to the image descriptor.
     * @see lv_canvas_get_image
     */
    lv_image_dsc_t* get_image() const noexcept { return lv_canvas_get_image(p_); }
    /**
     * Get a pixel's color and opacity
     * @param x  X coordinate of the pixel
     * @param y  Y coordinate of the pixel
     * @return ARGB8888 color of the pixel
     * @see lv_canvas_get_px
     */
    lv_color32_t get_px(int32_t x, int32_t y) const noexcept { return lv_canvas_get_px(p_, x, y); }
    /**
     * Initialize a layer to use LVGL's generic draw functions (lv_draw_rect/label/...) on the canvas.
     * Needs to be usd in pair with `lv_canvas_finish_layer`.
     * @param layer  pointer to a layer variable to initialize
     * @see lv_canvas_init_layer
     */
    void init_layer(Layer& layer) const noexcept { lv_canvas_init_layer(p_, layer.raw()); }
    /**
     * Set a buffer for the canvas.
     * Use lv_canvas_set_draw_buf() instead if you need to set a buffer with alignment requirement.
     * @param buf  buffer where content of canvas will be. The required size is (lv_image_color_format_get_px_size(cf) * w) / 8 * h) It can be allocated with `lv_malloc()` or it can be statically allocated array (e.g. static lv_color_t buf[100*50]) or it can be an address in RAM or external SRAM
     * @param w  width of canvas
     * @param h  height of canvas
     * @param cf  color format. `LV_COLOR_FORMAT...`
     * @see lv_canvas_set_buffer
     */
    void set_buffer(void* buf, int32_t w, int32_t h, ColorFormat cf) const noexcept { lv_canvas_set_buffer(p_, buf, w, h, static_cast<lv_color_format_t>(cf)); }
    /**
     * Set a draw buffer for the canvas. A draw buffer either can be allocated by `lv_draw_buf_create()`
     * or defined statically by `LV_DRAW_BUF_DEFINE_STATIC`. When buffer start address and stride has alignment
     * requirement, it's recommended to use `lv_draw_buf_create`.
     * @param draw_buf  pointer to a draw buffer
     * @see lv_canvas_set_draw_buf
     */
    void set_draw_buf(DrawBuf draw_buf) const noexcept { lv_canvas_set_draw_buf(p_, draw_buf.raw()); }
    /**
     * Set the palette color of a canvas for index format. Valid only for `LV_COLOR_FORMAT_I1/2/4/8`
     * @param index  the palette color to set: - for `LV_COLOR_FORMAT_I1`: 0..1 - for `LV_COLOR_FORMAT_I2`: 0..3 - for `LV_COLOR_FORMAT_I4`: 0..15 - for `LV_COLOR_FORMAT_I8`: 0..255
     * @param color  the color to set
     * @see lv_canvas_set_palette
     */
    void set_palette(uint8_t index, lv_color32_t color) const noexcept { lv_canvas_set_palette(p_, index, color); }
    /**
     * Set a pixel's color and opacity
     * @param x  X coordinate of the pixel
     * @param y  Y coordinate of the pixel
     * @param color  the color
     * @param opa  the opacity
     * @see lv_canvas_set_px
     */
    void set_px(int32_t x, int32_t y, Color color, lv_opa_t opa) const noexcept { lv_canvas_set_px(p_, x, y, color.raw(), opa); }
};
static_assert(sizeof(Canvas) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Canvas));
#endif // (LV_USE_CANVAS != 0) && (LV_USE_IMAGE != 0)

#if LV_USE_CANVAS != 0
/**
 * Just a wrapper to `LV_CANVAS_BUF_SIZE` for bindings.
 * @see lv_canvas_buf_size
 */
inline uint32_t canvas_buf_size(int32_t w, int32_t h, uint8_t bpp, uint8_t stride) noexcept { return lv_canvas_buf_size(w, h, bpp, stride); }
#endif // LV_USE_CANVAS != 0

} // namespace lv
