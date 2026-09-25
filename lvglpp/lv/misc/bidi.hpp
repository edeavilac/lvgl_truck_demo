#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_BIDI
/**
 * Get the real text alignment from the a text alignment, base direction and a text.
 * @param align  LV_TEXT_ALIGN_..., write back the calculated align here (LV_TEXT_ALIGN_LEFT/RIGHT/CENTER)
 * @param base_dir  LV_BASE_DIR_..., write the calculated base dir here (LV_BASE_DIR_LTR/RTL)
 * @param txt  a text, used with LV_BASE_DIR_AUTO to determine the base direction
 * @see lv_bidi_calculate_align
 */
inline void bidi_calculate_align(lv_text_align_t* align, lv_base_dir_t* base_dir, const char* txt) noexcept { lv_bidi_calculate_align(align, base_dir, txt); }

/**
 * Set custom neutrals string
 * @param neutrals  default " \t\n\r.,:;'\"`!?%/\\-=()[]{}<>@#&$|"
 * @see lv_bidi_set_custom_neutrals_static
 */
inline void bidi_set_custom_neutrals_static(const char* neutrals) noexcept { lv_bidi_set_custom_neutrals_static(neutrals); }
#else // !(LV_USE_BIDI)
/**
 * For compatibility if LV_USE_BIDI = 0
 * Get the real text alignment from the a text alignment, base direction and a text.
 * @param align  For LV_TEXT_ALIGN_AUTO give LV_TEXT_ALIGN_LEFT else leave unchanged, write back the calculated align here
 * @param base_dir  Unused
 * @param txt  Unused
 * @see lv_bidi_calculate_align
 */
inline void bidi_calculate_align(lv_text_align_t* align, lv_base_dir_t* base_dir, const char* txt) noexcept { lv_bidi_calculate_align(align, base_dir, txt); }
#endif // LV_USE_BIDI

} // namespace lv
