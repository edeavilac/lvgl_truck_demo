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

/**
 * Get size of a text
 * @param size_res  pointer to a 'point_t' variable to store the result
 * @param text  pointer to a text
 * @param font  pointer to font of the text
 * @param letter_space  letter space of the text
 * @param line_space  line space of the text
 * @param max_width  max width of the text (break the lines to fit this size). Set COORD_MAX to avoid
 * @param flag  settings for the text from ::lv_text_flag_t
 * @see lv_text_get_size
 */
inline void text_get_size(Point& size_res, const char* text, Font font, int32_t letter_space, int32_t line_space, int32_t max_width, TextFlag flag) noexcept { lv_text_get_size(size_res.ptr(), text, font.raw(), letter_space, line_space, max_width, static_cast<lv_text_flag_t>(flag)); }

} // namespace lv
