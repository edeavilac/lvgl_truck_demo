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

#if LV_USE_FONT_MANAGER
class FontManager {
protected:
    lv_font_manager_t* p_ = nullptr;

public:
    constexpr FontManager() noexcept = default;  /**< the "no object" handle */
    constexpr explicit FontManager(lv_font_manager_t* p) noexcept : p_(p) {}

    constexpr lv_font_manager_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(FontManager a, FontManager b) noexcept { return a.p_ == b.p_; }

    /**
     * Add font resource.
     * @param name  font name.
     * @param src  font source. Need to strictly correspond to the font class.
     * @param class_p  font class. eg. lv_freetype_font_class, lv_builtin_font_class.
     * @return return true if the add was successful.
     * @see lv_font_manager_add_src
     */
    bool add_src(const char* name, const void* src, const lv_font_class_t* class_p) const noexcept { return lv_font_manager_add_src(p_, name, src, class_p); }
    /**
     * Add font resource with static memory.
     * @param name  font name. It cannot be a local variable.
     * @param src  font source. Need to strictly correspond to the font class. And it cannot be a local variable.
     * @param class_p  font class. E.g. lv_freetype_font_class, lv_builtin_font_class.
     * @return return true if the add was successful.
     * @see lv_font_manager_add_src_static
     */
    bool add_src_static(const char* name, const void* src, const lv_font_class_t* class_p) const noexcept { return lv_font_manager_add_src_static(p_, name, src, class_p); }
    /**
     * Create main font manager.
     * @param recycle_cache_size  number of fonts that were recently deleted from the cache.
     * @return pointer to main font manager.
     * @see lv_font_manager_create
     */
    static FontManager create(uint32_t recycle_cache_size) noexcept { return FontManager(lv_font_manager_create(recycle_cache_size)); }
    /**
     * Create font.
     * @param font_family  font family name. Matches the font resource name, using commas to separate different names. E.g. "my_font_1,my_font_2".
     * @param render_mode  font render mode. see `lv_freetype_font_render_mode_t`.
     * @param size  font size in pixel.
     * @param style  font style. see `lv_freetype_font_style_t`.
     * @param kerning  kerning mode. see `lv_font_kerning_t`.
     * @return point to the created font.
     * @see lv_font_manager_create_font
     */
    Font create_font(const char* font_family, uint32_t render_mode, uint32_t size, uint32_t style, FontKerning kerning) const noexcept { return Font(lv_font_manager_create_font(p_, font_family, render_mode, size, style, static_cast<lv_font_kerning_t>(kerning))); }
    /**
     * Delete main font manager.
     * @return return true if the deletion was successful.
     * @see lv_font_manager_delete
     */
    bool delete_() const noexcept { return lv_font_manager_delete(p_); }
    /**
     * Delete font.
     * @param font  point to the font.
     * @see lv_font_manager_delete_font
     */
    void delete_font(Font font) const noexcept { lv_font_manager_delete_font(p_, font.raw()); }
    /**
     * Remove font resource.
     * @param name  font name.
     * @return return true if the remove was successful.
     * @see lv_font_manager_remove_src
     */
    bool remove_src(const char* name) const noexcept { return lv_font_manager_remove_src(p_, name); }
};
static_assert(sizeof(FontManager) == sizeof(lv_font_manager_t*));
static_assert(__is_trivially_copyable(FontManager));
#endif // LV_USE_FONT_MANAGER

} // namespace lv
