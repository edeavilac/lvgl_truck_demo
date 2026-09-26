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

#if LV_USE_TABVIEW
class Tabview : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_tabview_class; }

    /**
     * Add a tab to the tabview
     * @param name  the name of the tab, it will be displayed on the tab bar
     * @return the widget where the content of the tab can be created
     * @see lv_tabview_add_tab
     */
    Obj add_tab(const char* name) const noexcept { return Obj(lv_tabview_add_tab(p_, name)); }
    /**
     * Create a tabview widget
     * @param parent  pointer to a parent widget
     * @return the created tabview
     * @see lv_tabview_create
     */
    static Tabview create(Obj parent) noexcept { return Tabview(lv_tabview_create(parent.raw())); }
    /**
     * Get the widget where the container of each tab is created
     * @return the main container widget
     * @see lv_tabview_get_content
     */
    Obj get_content() const noexcept { return Obj(lv_tabview_get_content(p_)); }
    /**
     * Get the current tab's index
     * @return the zero based index of the current tab
     * @see lv_tabview_get_tab_active
     */
    uint32_t get_tab_active() const noexcept { return lv_tabview_get_tab_active(p_); }
    /**
     * Get the tab bar where the buttons are created
     * @return the tab bar
     * @see lv_tabview_get_tab_bar
     */
    Obj get_tab_bar() const noexcept { return Obj(lv_tabview_get_tab_bar(p_)); }
    /**
     * Get the position of the tab bar
     * @return LV_DIR_TOP/BOTTOM/LEFT/RIGHT
     * @see lv_tabview_get_tab_bar_position
     */
    Dir get_tab_bar_position() const noexcept { return static_cast<Dir>(lv_tabview_get_tab_bar_position(p_)); }
    /**
     * Get a given tab button by index
     * @param idx  zero based index of the tab button to get. < 0 means start counting tab button from the back (-1 is the last tab button)
     * @return pointer to the tab button, or NULL if the index was out of range
     * @see lv_tabview_get_tab_button
     */
    Obj get_tab_button(int32_t idx) const noexcept { return Obj(lv_tabview_get_tab_button(p_, idx)); }
    /**
     * Get the number of tabs
     * @return the number of tabs
     * @see lv_tabview_get_tab_count
     */
    uint32_t get_tab_count() const noexcept { return lv_tabview_get_tab_count(p_); }
    /**
     * Show a tab
     * @param idx  the index of the tab to show
     * @param anim_en  LV_ANIM_ON/OFF
     * @see lv_tabview_set_active
     */
    void set_active(uint32_t idx, lv_anim_enable_t anim_en) const noexcept { lv_tabview_set_active(p_, idx, anim_en); }
    /**
     * Set the position of the tab bar
     * @param dir  LV_DIR_TOP/BOTTOM/LEFT/RIGHT
     * @see lv_tabview_set_tab_bar_position
     */
    void set_tab_bar_position(Dir dir) const noexcept { lv_tabview_set_tab_bar_position(p_, static_cast<lv_dir_t>(dir)); }
    /**
     * Set the width or height of the tab bar
     * @param size  size of the tab bar in pixels or percentage. will be used as width or height based on the position of the tab bar)
     * @see lv_tabview_set_tab_bar_size
     */
    void set_tab_bar_size(int32_t size) const noexcept { lv_tabview_set_tab_bar_size(p_, size); }
    /**
     * Change the name of the tab
     * @param idx  the index of the tab to rename
     * @param new_name  the new name as a string
     * @see lv_tabview_set_tab_text
     */
    void set_tab_text(uint32_t idx, const char* new_name) const noexcept { lv_tabview_set_tab_text(p_, idx, new_name); }
    #if LV_USE_TRANSLATION
    /**
     * Add a tab with a translation tag to the tabview.
     * @param tag  translation key used for the tab label; will be displayed on the tab bar
     * @return the widget where the content of the tab can be created
     * @see lv_tabview_set_tab_translation_tag
     */
    Obj set_tab_translation_tag(const char* tag) const noexcept { return Obj(lv_tabview_set_tab_translation_tag(p_, tag)); }
    #endif // LV_USE_TRANSLATION

    #if LVPP_COMPAT_V8
    /** v8 spelling of `get_tab_bar`. */
    Obj get_tab_btns() const noexcept { return get_tab_bar(); }
    /** v8 spelling of `get_tab_active`. */
    uint32_t get_tab_act() const noexcept { return get_tab_active(); }
    /** v8 spelling of `set_active`. */
    void set_act(uint32_t idx, lv_anim_enable_t anim_en) const noexcept { return set_active(idx, anim_en); }
    #endif // LVPP_COMPAT_V8

};
static_assert(sizeof(Tabview) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Tabview));
#endif // LV_USE_TABVIEW

} // namespace lv
