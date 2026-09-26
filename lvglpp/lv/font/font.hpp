#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

class Font {
protected:
    lv_font_t* p_ = nullptr;

public:
    constexpr Font() noexcept = default;  /**< the "no object" handle */
    constexpr explicit Font(lv_font_t* p) noexcept : p_(p) {}

    constexpr lv_font_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(Font a, Font b) noexcept { return a.p_ == b.p_; }

    /**
     * Get the descriptor of a glyph
     * @param dsc_out  store the result descriptor here
     * @param letter  a UNICODE letter code
     * @param letter_next  the next letter after `letter`. Used for kerning
     * @return true: descriptor is successfully loaded into `dsc_out`. false: the letter was not found, no data is loaded to `dsc_out`
     * @see lv_font_get_glyph_dsc
     */
    bool get_glyph_dsc(lv_font_glyph_dsc_t* dsc_out, uint32_t letter, uint32_t letter_next) const noexcept;
    /**
     * Used as `get_glyph_dsc` callback in lvgl's native font format if the font is uncompressed.
     * @param dsc_out  store the result descriptor here
     * @param unicode_letter  a UNICODE letter code
     * @param unicode_letter_next  the unicode letter succeeding the letter under test
     * @return true: descriptor is successfully loaded into `dsc_out`. false: the letter was not found, no data is loaded to `dsc_out`
     * @see lv_font_get_glyph_dsc_fmt_txt
     */
    bool get_glyph_dsc_fmt_txt(lv_font_glyph_dsc_t* dsc_out, uint32_t unicode_letter, uint32_t unicode_letter_next) const noexcept;
    /**
     * Get the width of a glyph with kerning
     * @param letter  a UNICODE letter
     * @param letter_next  the next letter after `letter`. Used for kerning
     * @return the width of the glyph
     * @see lv_font_get_glyph_width
     */
    uint16_t get_glyph_width(uint32_t letter, uint32_t letter_next) const noexcept;
    /**
     * Get the line height of a font. All characters fit into this height
     * @return the height of a font
     * @see lv_font_get_line_height
     */
    int32_t get_line_height() const noexcept;
    /**
     * Checks if a font has a static rendering bitmap.
     * @return return true if the font has a bitmap generated for static rendering.
     * @see lv_font_has_static_bitmap
     */
    bool has_static_bitmap() const noexcept;
    /**
     * Configure the use of kerning information stored in a font
     * @param kerning  `LV_FONT_KERNING_NORMAL` (default) or `LV_FONT_KERNING_NONE`
     * @see lv_font_set_kerning
     */
    void set_kerning(FontKerning kerning) const noexcept;
};
static_assert(sizeof(Font) == sizeof(lv_font_t*));
static_assert(__is_trivially_copyable(Font));

#if LV_FONT_MONTSERRAT_8
/** @see lv_font_montserrat_8 */
inline constexpr Font font_montserrat_8 = Font(const_cast<lv_font_t*>(&lv_font_montserrat_8));
#endif // LV_FONT_MONTSERRAT_8

#if LV_FONT_MONTSERRAT_10
/** @see lv_font_montserrat_10 */
inline constexpr Font font_montserrat_10 = Font(const_cast<lv_font_t*>(&lv_font_montserrat_10));
#endif // LV_FONT_MONTSERRAT_10

#if LV_FONT_MONTSERRAT_12
/** @see lv_font_montserrat_12 */
inline constexpr Font font_montserrat_12 = Font(const_cast<lv_font_t*>(&lv_font_montserrat_12));
#endif // LV_FONT_MONTSERRAT_12

#if LV_FONT_MONTSERRAT_14
/** @see lv_font_montserrat_14 */
inline constexpr Font font_montserrat_14 = Font(const_cast<lv_font_t*>(&lv_font_montserrat_14));
#endif // LV_FONT_MONTSERRAT_14

#if LV_FONT_MONTSERRAT_16
/** @see lv_font_montserrat_16 */
inline constexpr Font font_montserrat_16 = Font(const_cast<lv_font_t*>(&lv_font_montserrat_16));
#endif // LV_FONT_MONTSERRAT_16

#if LV_FONT_MONTSERRAT_18
/** @see lv_font_montserrat_18 */
inline constexpr Font font_montserrat_18 = Font(const_cast<lv_font_t*>(&lv_font_montserrat_18));
#endif // LV_FONT_MONTSERRAT_18

#if LV_FONT_MONTSERRAT_20
/** @see lv_font_montserrat_20 */
inline constexpr Font font_montserrat_20 = Font(const_cast<lv_font_t*>(&lv_font_montserrat_20));
#endif // LV_FONT_MONTSERRAT_20

#if LV_FONT_MONTSERRAT_22
/** @see lv_font_montserrat_22 */
inline constexpr Font font_montserrat_22 = Font(const_cast<lv_font_t*>(&lv_font_montserrat_22));
#endif // LV_FONT_MONTSERRAT_22

#if LV_FONT_MONTSERRAT_24
/** @see lv_font_montserrat_24 */
inline constexpr Font font_montserrat_24 = Font(const_cast<lv_font_t*>(&lv_font_montserrat_24));
#endif // LV_FONT_MONTSERRAT_24

#if LV_FONT_MONTSERRAT_26
/** @see lv_font_montserrat_26 */
inline constexpr Font font_montserrat_26 = Font(const_cast<lv_font_t*>(&lv_font_montserrat_26));
#endif // LV_FONT_MONTSERRAT_26

#if LV_FONT_MONTSERRAT_28
/** @see lv_font_montserrat_28 */
inline constexpr Font font_montserrat_28 = Font(const_cast<lv_font_t*>(&lv_font_montserrat_28));
#endif // LV_FONT_MONTSERRAT_28

#if LV_FONT_MONTSERRAT_30
/** @see lv_font_montserrat_30 */
inline constexpr Font font_montserrat_30 = Font(const_cast<lv_font_t*>(&lv_font_montserrat_30));
#endif // LV_FONT_MONTSERRAT_30

#if LV_FONT_MONTSERRAT_32
/** @see lv_font_montserrat_32 */
inline constexpr Font font_montserrat_32 = Font(const_cast<lv_font_t*>(&lv_font_montserrat_32));
#endif // LV_FONT_MONTSERRAT_32

#if LV_FONT_MONTSERRAT_34
/** @see lv_font_montserrat_34 */
inline constexpr Font font_montserrat_34 = Font(const_cast<lv_font_t*>(&lv_font_montserrat_34));
#endif // LV_FONT_MONTSERRAT_34

#if LV_FONT_MONTSERRAT_36
/** @see lv_font_montserrat_36 */
inline constexpr Font font_montserrat_36 = Font(const_cast<lv_font_t*>(&lv_font_montserrat_36));
#endif // LV_FONT_MONTSERRAT_36

#if LV_FONT_MONTSERRAT_38
/** @see lv_font_montserrat_38 */
inline constexpr Font font_montserrat_38 = Font(const_cast<lv_font_t*>(&lv_font_montserrat_38));
#endif // LV_FONT_MONTSERRAT_38

#if LV_FONT_MONTSERRAT_40
/** @see lv_font_montserrat_40 */
inline constexpr Font font_montserrat_40 = Font(const_cast<lv_font_t*>(&lv_font_montserrat_40));
#endif // LV_FONT_MONTSERRAT_40

#if LV_FONT_MONTSERRAT_42
/** @see lv_font_montserrat_42 */
inline constexpr Font font_montserrat_42 = Font(const_cast<lv_font_t*>(&lv_font_montserrat_42));
#endif // LV_FONT_MONTSERRAT_42

#if LV_FONT_MONTSERRAT_44
/** @see lv_font_montserrat_44 */
inline constexpr Font font_montserrat_44 = Font(const_cast<lv_font_t*>(&lv_font_montserrat_44));
#endif // LV_FONT_MONTSERRAT_44

#if LV_FONT_MONTSERRAT_46
/** @see lv_font_montserrat_46 */
inline constexpr Font font_montserrat_46 = Font(const_cast<lv_font_t*>(&lv_font_montserrat_46));
#endif // LV_FONT_MONTSERRAT_46

#if LV_FONT_MONTSERRAT_48
/** @see lv_font_montserrat_48 */
inline constexpr Font font_montserrat_48 = Font(const_cast<lv_font_t*>(&lv_font_montserrat_48));
#endif // LV_FONT_MONTSERRAT_48

#if LV_FONT_MONTSERRAT_28_COMPRESSED
/** @see lv_font_montserrat_28_compressed */
inline constexpr Font font_montserrat_28_compressed = Font(const_cast<lv_font_t*>(&lv_font_montserrat_28_compressed));
#endif // LV_FONT_MONTSERRAT_28_COMPRESSED

#if LV_FONT_DEJAVU_16_PERSIAN_HEBREW
/** @see lv_font_dejavu_16_persian_hebrew */
inline constexpr Font font_dejavu_16_persian_hebrew = Font(const_cast<lv_font_t*>(&lv_font_dejavu_16_persian_hebrew));
#endif // LV_FONT_DEJAVU_16_PERSIAN_HEBREW

#if LV_FONT_SOURCE_HAN_SANS_SC_14_CJK
/** @see lv_font_source_han_sans_sc_14_cjk */
inline constexpr Font font_source_han_sans_sc_14_cjk = Font(const_cast<lv_font_t*>(&lv_font_source_han_sans_sc_14_cjk));
#endif // LV_FONT_SOURCE_HAN_SANS_SC_14_CJK

#if LV_FONT_SOURCE_HAN_SANS_SC_16_CJK
/** @see lv_font_source_han_sans_sc_16_cjk */
inline constexpr Font font_source_han_sans_sc_16_cjk = Font(const_cast<lv_font_t*>(&lv_font_source_han_sans_sc_16_cjk));
#endif // LV_FONT_SOURCE_HAN_SANS_SC_16_CJK

#if LV_FONT_UNSCII_8
/** @see lv_font_unscii_8 */
inline constexpr Font font_unscii_8 = Font(const_cast<lv_font_t*>(&lv_font_unscii_8));
#endif // LV_FONT_UNSCII_8

#if LV_FONT_UNSCII_16
/** @see lv_font_unscii_16 */
inline constexpr Font font_unscii_16 = Font(const_cast<lv_font_t*>(&lv_font_unscii_16));
#endif // LV_FONT_UNSCII_16

/**
 * Return with the bitmap of a font.
 * It always converts the normal fonts to A8 format in a draw_buf with
 * LV_DRAW_BUF_ALIGN and LV_DRAW_BUF_STRIDE_ALIGN
 * @param g_dsc  the glyph descriptor including which font to use, which supply the glyph_index and the format.
 * @param draw_buf  a draw buffer that can be used to store the bitmap of the glyph.
 * @return pointer to the glyph's data. It can be a draw buffer for bitmap fonts or an image source for imgfonts.
 * @see lv_font_get_glyph_bitmap
 */
inline const void* font_get_glyph_bitmap(lv_font_glyph_dsc_t* g_dsc, DrawBuf draw_buf) noexcept;

/**
 * Return the bitmap as it is. It works only if the font stores the bitmap in
 * a non-volitile memory.
 * @param g_dsc  the glyph descriptor including which font to use, which supply the glyph_index and the format.
 * @return the bitmap as it is
 * @see lv_font_get_glyph_static_bitmap
 */
inline const void* font_get_glyph_static_bitmap(lv_font_glyph_dsc_t* g_dsc) noexcept;

/**
 * Release the bitmap of a font.
 * @param g_dsc  the glyph descriptor including which font to use, which supply the glyph_index and the format.
 * @see lv_font_glyph_release_draw_data
 */
inline void font_glyph_release_draw_data(lv_font_glyph_dsc_t* g_dsc) noexcept;

/**
 * Get the default font, defined by LV_FONT_DEFAULT
 * @return return pointer to the default font
 * @see lv_font_get_default
 */
inline Font font_get_default() noexcept;

} // namespace lv
