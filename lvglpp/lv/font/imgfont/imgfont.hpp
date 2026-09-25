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

#if LV_USE_IMGFONT
/**
 * Creates a image font with info parameter specified.
 * @param height  font size
 * @param path_cb  a function to get the image path name of character.
 * @param user_data  pointer to user data
 * @return pointer to the new imgfont or NULL if create error.
 * @see lv_imgfont_create
 */
inline Font imgfont_create(uint16_t height, lv_imgfont_get_path_cb_t path_cb, void* user_data) noexcept { return Font(lv_imgfont_create(height, path_cb, user_data)); }

/**
 * Takes any callable instead of the C pair.
 * Creates a image font with info parameter specified.
 * @param height  font size
 * @param path_cb  a function to get the image path name of character.
 * @param user_data  pointer to user data
 * @return pointer to the new imgfont or NULL if create error.
 * @see lv_imgfont_create
 */
template <class F>
inline Font imgfont_create(uint16_t height, F&& f) noexcept { return Font(lv_imgfont_create(height, detail::ImgfontGetPathCbClosure<std::decay_t<F>>::fn(f), detail::ImgfontGetPathCbClosure<std::decay_t<F>>::state(f))); }

/**
 * Destroy a image font that has been created.
 * @param font  pointer to image font handle.
 * @see lv_imgfont_destroy
 */
inline void imgfont_destroy(Font font) noexcept { lv_imgfont_destroy(font.raw()); }
#endif // LV_USE_IMGFONT

} // namespace lv
