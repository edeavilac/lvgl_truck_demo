#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/font/font.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_TINY_TTF
/** @see lv_tiny_ttf_font_class */
inline constexpr const lv_font_class_t* tiny_ttf_font_class = &lv_tiny_ttf_font_class;
#endif // LV_USE_TINY_TTF

#if (LV_USE_TINY_TTF) && (LV_TINY_TTF_FILE_SUPPORT != 0)
/**
 * Create a font from the specified file or path with the specified line height.
 * @param path  the path or file name of the font
 * @param font_size  the font size in pixel
 * @return a font object
 * @see lv_tiny_ttf_create_file
 */
inline Type* tiny_ttf_create_file(const char* path, Type font_size) noexcept { return lv_tiny_ttf_create_file(path, font_size); }

/**
 * Create a font from the specified file or path with the specified line height with the specified cache size.
 * @param path  the path or file name of the font
 * @param font_size  the font size in pixel
 * @param kerning  kerning value in pixel
 * @param cache_size  the cache size in count
 * @return a font object
 * @see lv_tiny_ttf_create_file_ex
 */
inline Type* tiny_ttf_create_file_ex(const char* path, Type font_size, Type kerning, Type cache_size) noexcept { return lv_tiny_ttf_create_file_ex(path, font_size, kerning, cache_size); }
#endif // (LV_USE_TINY_TTF) && (LV_TINY_TTF_FILE_SUPPORT != 0)

#if LV_USE_TINY_TTF
/**
 * Create a font from the specified data pointer with the specified line height.
 * @param data  the data pointer
 * @param data_size  the data size
 * @param font_size  the font size in pixel
 * @return a font object
 * @see lv_tiny_ttf_create_data
 */
inline Font tiny_ttf_create_data(const void* data, size_t data_size, int32_t font_size) noexcept { return Font(lv_tiny_ttf_create_data(data, data_size, font_size)); }

/**
 * Create a font from the specified data pointer with the specified line height and the specified cache size.
 * @param data  the data pointer
 * @param data_size  the data size
 * @param font_size  the font size in pixel
 * @param kerning  kerning value in pixel
 * @param cache_size  the cache size in count
 * @see lv_tiny_ttf_create_data_ex
 */
inline Font tiny_ttf_create_data_ex(const void* data, size_t data_size, int32_t font_size, FontKerning kerning, size_t cache_size) noexcept { return Font(lv_tiny_ttf_create_data_ex(data, data_size, font_size, static_cast<lv_font_kerning_t>(kerning), cache_size)); }

/**
 * Set the size of the font to a new font_size
 * @param font  the font object
 * @param font_size  the font size in pixel
 * @see lv_tiny_ttf_set_size
 */
inline void tiny_ttf_set_size(Font font, int32_t font_size) noexcept { lv_tiny_ttf_set_size(font.raw(), font_size); }

/**
 * Destroy a font previously created with lv_tiny_ttf_create_xxxx()
 * @param font  the font object
 * @see lv_tiny_ttf_destroy
 */
inline void tiny_ttf_destroy(Font font) noexcept { lv_tiny_ttf_destroy(font.raw()); }
#endif // LV_USE_TINY_TTF

} // namespace lv
