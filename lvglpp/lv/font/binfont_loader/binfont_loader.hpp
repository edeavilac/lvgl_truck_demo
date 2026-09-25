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

/** @see lv_binfont_font_class */
inline constexpr const lv_font_class_t* binfont_loader_binfont_font_class = &lv_binfont_font_class;

/**
 * Loads a `lv_font_t` object from a binary font file
 * @param path  path to font file
 * @return pointer to font where to load
 * @see lv_binfont_create
 */
inline Font binfont_loader_binfont_create(const char* path) noexcept { return Font(lv_binfont_create(path)); }

#if LV_USE_FS_MEMFS
/**
 * Loads a `lv_font_t` object from a memory buffer containing the binary font file.
 * Requires LV_USE_FS_MEMFS
 * @param buffer  address of the font file in the memory
 * @param size  size of the font file buffer
 * @return pointer to font where to load
 * @see lv_binfont_create_from_buffer
 */
inline Font binfont_loader_binfont_create_from_buffer(void* buffer, uint32_t size) noexcept { return Font(lv_binfont_create_from_buffer(buffer, size)); }
#endif // LV_USE_FS_MEMFS

/**
 * Frees the memory allocated by the `lv_binfont_create()` function
 * @param font  lv_font_t object created by the lv_binfont_create function
 * @see lv_binfont_destroy
 */
inline void binfont_loader_binfont_destroy(Font font) noexcept { lv_binfont_destroy(font.raw()); }

} // namespace lv
