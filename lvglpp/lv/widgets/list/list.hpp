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

#if LV_USE_LIST
class List : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_list_class; }

    /**
     * Add button to a list
     * @param icon  icon for the button, when NULL it will have no icon
     * @param txt  text of the new button, when NULL no text will be added
     * @return pointer to the created button
     * @see lv_list_add_button
     */
    Obj add_button(const void* icon, const char* txt) const noexcept { return Obj(lv_list_add_button(p_, icon, txt)); }
    #if LV_USE_TRANSLATION
    /**
     * Add translation tag button to a list
     * @param icon  icon for the button, when NULL it will have no icon
     * @param tag  translation tag of the new button, when NULL no translation tag will be added
     * @return pointer to the created button
     * @see lv_list_add_button_translation_tag
     */
    Obj add_button_translation_tag(const void* icon, const char* tag) const noexcept { return Obj(lv_list_add_button_translation_tag(p_, icon, tag)); }
    #endif // LV_USE_TRANSLATION

    /**
     * Add text to a list
     * @param txt  text of the new label
     * @return pointer to the created label
     * @see lv_list_add_text
     */
    Obj add_text(const char* txt) const noexcept { return Obj(lv_list_add_text(p_, txt)); }
    #if LV_USE_TRANSLATION
    /**
     * Add translation tag text to a list
     * @param tag  translation tag of the new label
     * @return pointer to the created label
     * @see lv_list_add_translation_tag
     */
    Obj add_translation_tag(const char* tag) const noexcept { return Obj(lv_list_add_translation_tag(p_, tag)); }
    #endif // LV_USE_TRANSLATION

    /**
     * Create a list object
     * @param parent  pointer to an object, it will be the parent of the new list
     * @return pointer to the created list
     * @see lv_list_create
     */
    static List create(Obj parent) noexcept { return List(lv_list_create(parent.raw())); }
    /**
     * Get text of a given list button
     * @param btn  pointer to the button
     * @return text of btn, if btn doesn't have text "" will be returned
     * @see lv_list_get_button_text
     */
    const char* get_button_text(Obj btn) const noexcept { return lv_list_get_button_text(p_, btn.raw()); }
    /**
     * Set text of a given list button
     * @param btn  pointer to the button
     * @param txt  pointer to the text
     * @see lv_list_set_button_text
     */
    void set_button_text(Obj btn, const char* txt) const noexcept { lv_list_set_button_text(p_, btn.raw(), txt); }
    #if LV_USE_TRANSLATION
    /**
     * Set translation tag text of a given list button
     * @param btn  pointer to the button
     * @param tag  pointer to the translation tag
     * @see lv_list_set_button_translation_tag
     */
    void set_button_translation_tag(Obj btn, const char* tag) const noexcept { lv_list_set_button_translation_tag(p_, btn.raw(), tag); }
    #endif // LV_USE_TRANSLATION

    #if LVPP_COMPAT_V8
    /** v8 spelling of `set_button_text`. */
    void set_btn_text(Obj btn, const char* txt) const noexcept { return set_button_text(btn, txt); }
    /** v8 spelling of `get_button_text`. */
    const char* get_btn_text(Obj btn) const noexcept { return get_button_text(btn); }
    /** v8 spelling of `add_button`. */
    Obj add_btn(const void* icon, const char* txt) const noexcept { return add_button(icon, txt); }
    #endif // LVPP_COMPAT_V8

};
static_assert(sizeof(List) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(List));
#endif // LV_USE_LIST

} // namespace lv
