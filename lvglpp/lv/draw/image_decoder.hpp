#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/draw/draw_buf.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

class ImageDecoder {
protected:
    lv_image_decoder_t* p_ = nullptr;

public:
    constexpr ImageDecoder() noexcept = default;  /**< the "no object" handle */
    constexpr explicit ImageDecoder(lv_image_decoder_t* p) noexcept : p_(p) {}

    constexpr lv_image_decoder_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(ImageDecoder a, ImageDecoder b) noexcept { return a.p_ == b.p_; }

    /** @see lv_image_decoder_add_to_cache */
    lv_cache_entry_t* add_to_cache(lv_image_cache_data_t* search_key, DrawBuf decoded, void* user_data) const noexcept { return lv_image_decoder_add_to_cache(p_, search_key, decoded.raw(), user_data); }
    /**
     * Create a new image decoder
     * @return pointer to the new image decoder
     * @see lv_image_decoder_create
     */
    static ImageDecoder create() noexcept { return ImageDecoder(lv_image_decoder_create()); }
    /**
     * Delete an image decoder
     * @see lv_image_decoder_delete
     */
    void delete_() const noexcept { lv_image_decoder_delete(p_); }
    /**
     * Get the next image decoder in the linked list of image decoders
     * @return the next image decoder or NULL if no more image decoder exists
     * @see lv_image_decoder_get_next
     */
    ImageDecoder get_next() const noexcept { return ImageDecoder(lv_image_decoder_get_next(p_)); }
    /**
     * Set a callback to close a decoding session. E.g. close files and free other resources.
     * @param close_cb  a function to close a decoding session
     * @see lv_image_decoder_set_close_cb
     */
    void set_close_cb(lv_image_decoder_close_f_t close_cb) const noexcept { lv_image_decoder_set_close_cb(p_, close_cb); }
    /**
     * Set a callback to a decoded line of an image
     * @param read_line_cb  a function to read a line of an image
     * @see lv_image_decoder_set_get_area_cb
     */
    void set_get_area_cb(lv_image_decoder_get_area_cb_t read_line_cb) const noexcept { lv_image_decoder_set_get_area_cb(p_, read_line_cb); }
    /**
     * Set a callback to get information about the image
     * @param info_cb  a function to collect info about an image (fill an `lv_image_header_t` struct)
     * @see lv_image_decoder_set_info_cb
     */
    void set_info_cb(lv_image_decoder_info_f_t info_cb) const noexcept { lv_image_decoder_set_info_cb(p_, info_cb); }
    /**
     * Set a callback to open an image
     * @param open_cb  a function to open an image
     * @see lv_image_decoder_set_open_cb
     */
    void set_open_cb(lv_image_decoder_open_f_t open_cb) const noexcept { lv_image_decoder_set_open_cb(p_, open_cb); }
};
static_assert(sizeof(ImageDecoder) == sizeof(lv_image_decoder_t*));
static_assert(__is_trivially_copyable(ImageDecoder));

/**
 * Get information about an image.
 * Try the created image decoder one by one. Once one is able to get info that info will be used.
 * @param src  the image source. Can be 1) File name: E.g. "S:folder/img1.png" (The drivers needs to registered via `lv_fs_drv_register()`) 2) Variable: Pointer to an `lv_image_dsc_t` variable 3) Symbol: E.g. `LV_SYMBOL_OK`
 * @param header  the image info will be stored here
 * @return LV_RESULT_OK: success; LV_RESULT_INVALID: wasn't able to get info about the image
 * @see lv_image_decoder_get_info
 */
inline Result image_decoder_get_info(const void* src, lv_image_header_t* header) noexcept { return static_cast<Result>(lv_image_decoder_get_info(src, header)); }

/**
 * Open an image.
 * Try the created image decoders one by one. Once one is able to open the image that decoder is saved in `dsc`
 * @param dsc  describes a decoding session. Simply a pointer to an `lv_image_decoder_dsc_t` variable.
 * @param src  the image source. Can be 1) File name: E.g. "S:folder/img1.png" (The drivers needs to registered via `lv_fs_drv_register())`) 2) Variable: Pointer to an `lv_image_dsc_t` variable 3) Symbol: E.g. `LV_SYMBOL_OK`
 * @param args  args about how the image should be opened.
 * @return LV_RESULT_OK: opened the image. `dsc->decoded` and `dsc->header` are set. LV_RESULT_INVALID: none of the registered image decoders were able to open the image.
 * @see lv_image_decoder_open
 */
inline Result image_decoder_open(lv_image_decoder_dsc_t* dsc, const void* src, const lv_image_decoder_args_t* args) noexcept { return static_cast<Result>(lv_image_decoder_open(dsc, src, args)); }

/**
 * Decode `full_area` pixels incrementally by calling in a loop. Set `decoded_area` to `LV_COORD_MIN` on first call.
 * @param dsc  image decoder descriptor
 * @param full_area  input parameter. the full area to decode after enough subsequent calls
 * @param decoded_area  input+output parameter. set the values to `LV_COORD_MIN` for the first call and to reset decoding. the decoded area is stored here after each call.
 * @return LV_RESULT_OK: success; LV_RESULT_INVALID: an error occurred or there is nothing left to decode
 * @see lv_image_decoder_get_area
 */
inline Result image_decoder_get_area(lv_image_decoder_dsc_t* dsc, const Area& full_area, Area& decoded_area) noexcept { return static_cast<Result>(lv_image_decoder_get_area(dsc, full_area.ptr(), decoded_area.ptr())); }

/**
 * Close a decoding session
 * @param dsc  pointer to `lv_image_decoder_dsc_t` used in `lv_image_decoder_open`
 * @see lv_image_decoder_close
 */
inline void image_decoder_close(lv_image_decoder_dsc_t* dsc) noexcept { lv_image_decoder_close(dsc); }

/**
 * Check the decoded image, make any modification if decoder `args` requires.
 * @param dsc  pointer to a decoder descriptor
 * @param decoded  pointer to a decoded image to post process to meet dsc->args requirement.
 * @return post processed draw buffer, when it differs with `decoded`, it's newly allocated.
 * @see lv_image_decoder_post_process
 */
inline DrawBuf image_decoder_post_process(lv_image_decoder_dsc_t* dsc, DrawBuf decoded) noexcept { return DrawBuf(lv_image_decoder_post_process(dsc, decoded.raw())); }

} // namespace lv
