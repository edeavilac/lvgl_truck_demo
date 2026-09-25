#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core/obj.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_IME_PINYIN != 0
class ImePinyin : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_ime_pinyin_class; }

    enum class Mode : int {
        K26 = LV_IME_PINYIN_MODE_K26,
        K9 = LV_IME_PINYIN_MODE_K9,
        K9Number = LV_IME_PINYIN_MODE_K9_NUMBER,
    };

    /** @see lv_ime_pinyin_create */
    static ImePinyin create(Obj parent) noexcept { return ImePinyin(lv_ime_pinyin_create(parent.raw())); }
    /**
     * Set the dictionary of Pinyin input method.
     * @return pointer to the Pinyin input method candidate panel
     * @see lv_ime_pinyin_get_cand_panel
     */
    Obj get_cand_panel() const noexcept { return Obj(lv_ime_pinyin_get_cand_panel(p_)); }
    /**
     * Set the dictionary of Pinyin input method.
     * @return pointer to the Pinyin input method dictionary
     * @see lv_ime_pinyin_get_dict
     */
    const lv_pinyin_dict_t* get_dict() const noexcept { return lv_ime_pinyin_get_dict(p_); }
    /**
     * Set the dictionary of Pinyin input method.
     * @return pointer to the Pinyin IME keyboard
     * @see lv_ime_pinyin_get_kb
     */
    Obj get_kb() const noexcept { return Obj(lv_ime_pinyin_get_kb(p_)); }
    /**
     * Set the dictionary of Pinyin input method.
     * @param dict  pointer to a Pinyin input method dictionary
     * @see lv_ime_pinyin_set_dict
     */
    void set_dict(lv_pinyin_dict_t* dict) const noexcept { lv_ime_pinyin_set_dict(p_, dict); }
    /**
     * Set the keyboard of Pinyin input method.
     * @param kb  pointer to a Pinyin input method keyboard
     * @see lv_ime_pinyin_set_keyboard
     */
    void set_keyboard(Obj kb) const noexcept { lv_ime_pinyin_set_keyboard(p_, kb.raw()); }
    /**
     * Set mode, 26-key input(k26) or 9-key input(k9).
     * @param mode  the mode from 'lv_ime_pinyin_mode_t'
     * @see lv_ime_pinyin_set_mode
     */
    void set_mode(ImePinyin::Mode mode) const noexcept { lv_ime_pinyin_set_mode(p_, static_cast<lv_ime_pinyin_mode_t>(mode)); }
};
static_assert(sizeof(ImePinyin) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(ImePinyin));
#endif // LV_USE_IME_PINYIN != 0

} // namespace lv
