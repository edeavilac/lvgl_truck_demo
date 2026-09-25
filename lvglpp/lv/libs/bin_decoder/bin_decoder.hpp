#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/draw/image_decoder.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

/**
 * Initialize the binary image decoder module
 * @see lv_bin_decoder_init
 */
inline void bin_decoder_init() noexcept { lv_bin_decoder_init(); }

/**
 * Get info about a lvgl binary image
 * @param decoder  the decoder where this function belongs
 * @param dsc  image descriptor containing the source and type of the image and other info.
 * @param header  store the image data here
 * @return LV_RESULT_OK: the info is successfully stored in `header`; LV_RESULT_INVALID: unknown format or other error.
 * @see lv_bin_decoder_info
 */
inline Result bin_decoder_info(ImageDecoder decoder, lv_image_decoder_dsc_t* dsc, lv_image_header_t* header) noexcept { return static_cast<Result>(lv_bin_decoder_info(decoder.raw(), dsc, header)); }

/** @see lv_bin_decoder_get_area */
inline Result bin_decoder_get_area(ImageDecoder decoder, lv_image_decoder_dsc_t* dsc, const Area& full_area, Area& decoded_area) noexcept { return static_cast<Result>(lv_bin_decoder_get_area(decoder.raw(), dsc, full_area.ptr(), decoded_area.ptr())); }

/**
 * Open a lvgl binary image
 * @param decoder  the decoder where this function belongs
 * @param dsc  pointer to decoder descriptor. `src`, `style` are already initialized in it.
 * @return LV_RESULT_OK: the info is successfully stored in `header`; LV_RESULT_INVALID: unknown format or other error.
 * @see lv_bin_decoder_open
 */
inline Result bin_decoder_open(ImageDecoder decoder, lv_image_decoder_dsc_t* dsc) noexcept { return static_cast<Result>(lv_bin_decoder_open(decoder.raw(), dsc)); }

/**
 * Close the pending decoding. Free resources etc.
 * @param decoder  pointer to the decoder the function associated with
 * @param dsc  pointer to decoder descriptor
 * @see lv_bin_decoder_close
 */
inline void bin_decoder_close(ImageDecoder decoder, lv_image_decoder_dsc_t* dsc) noexcept { lv_bin_decoder_close(decoder.raw(), dsc); }

} // namespace lv
