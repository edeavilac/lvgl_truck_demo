#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core.hpp"
#include "lv/core/obj.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_MENU
class Menu : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_menu_class; }

    enum class ModeHeader : int {
        /** Header is positioned at the top */
        TopFixed = LV_MENU_HEADER_TOP_FIXED,
        /** Header is positioned at the top and can be scrolled out of view */
        TopUnfixed = LV_MENU_HEADER_TOP_UNFIXED,
        /** Header is positioned at the bottom */
        BottomFixed = LV_MENU_HEADER_BOTTOM_FIXED,
    };

    enum class ModeRootBackButton : int {
        Disabled = LV_MENU_ROOT_BACK_BUTTON_DISABLED,
        Enabled = LV_MENU_ROOT_BACK_BUTTON_ENABLED,
    };

    /**
     * Check if an obj is a root back btn
     * @param obj  pointer to the back button
     * @return true if it is a root back btn
     * @see lv_menu_back_button_is_root
     */
    bool back_button_is_root(Obj obj) const noexcept { return lv_menu_back_button_is_root(p_, obj.raw()); }
    /**
     * Clear menu history
     * @see lv_menu_clear_history
     */
    void clear_history() const noexcept { lv_menu_clear_history(p_); }
    /**
     * Create a menu cont object
     * @return pointer to the created menu cont
     * @see lv_menu_cont_create
     */
    Obj cont_create() const noexcept { return Obj(lv_menu_cont_create(p_)); }
    /**
     * Create a menu object
     * @param parent  pointer to an object, it will be the parent of the new menu
     * @return pointer to the created menu
     * @see lv_menu_create
     */
    static Menu create(Obj parent) noexcept { return Menu(lv_menu_create(parent.raw())); }
    /**
     * Get a pointer to menu page that is currently displayed in main
     * @return pointer to current page
     * @see lv_menu_get_cur_main_page
     */
    Obj get_cur_main_page() const noexcept { return Obj(lv_menu_get_cur_main_page(p_)); }
    /**
     * Get a pointer to menu page that is currently displayed in sidebar
     * @return pointer to current page
     * @see lv_menu_get_cur_sidebar_page
     */
    Obj get_cur_sidebar_page() const noexcept { return Obj(lv_menu_get_cur_sidebar_page(p_)); }
    /**
     * Get a pointer to main header obj
     * @return pointer to main header obj
     * @see lv_menu_get_main_header
     */
    Obj get_main_header() const noexcept { return Obj(lv_menu_get_main_header(p_)); }
    /**
     * Get a pointer to main header back btn obj
     * @return pointer to main header back btn obj
     * @see lv_menu_get_main_header_back_button
     */
    Obj get_main_header_back_button() const noexcept { return Obj(lv_menu_get_main_header_back_button(p_)); }
    /**
     * Get the header mode of the menu
     * @return LV_MENU_HEADER_TOP_FIXED/TOP_UNFIXED/BOTTOM_FIXED
     * @see lv_menu_get_mode_header
     */
    Menu::ModeHeader get_mode_header() const noexcept { return static_cast<Menu::ModeHeader>(lv_menu_get_mode_header(p_)); }
    /**
     * Get the root back button mode of the menu
     * @return LV_MENU_ROOT_BACK_BUTTON_DISABLED/ENABLED
     * @see lv_menu_get_mode_root_back_button
     */
    Menu::ModeRootBackButton get_mode_root_back_button() const noexcept { return static_cast<Menu::ModeRootBackButton>(lv_menu_get_mode_root_back_button(p_)); }
    /**
     * Get a pointer to sidebar header obj
     * @return pointer to sidebar header obj
     * @see lv_menu_get_sidebar_header
     */
    Obj get_sidebar_header() const noexcept { return Obj(lv_menu_get_sidebar_header(p_)); }
    /**
     * Get a pointer to sidebar header obj
     * @return pointer to sidebar header back btn obj
     * @see lv_menu_get_sidebar_header_back_button
     */
    Obj get_sidebar_header_back_button() const noexcept { return Obj(lv_menu_get_sidebar_header_back_button(p_)); }
    /**
     * Create a menu section object
     * @return pointer to the created menu section
     * @see lv_menu_section_create
     */
    Obj section_create() const noexcept { return Obj(lv_menu_section_create(p_)); }
    /**
     * Create a menu separator object
     * @return pointer to the created menu separator
     * @see lv_menu_separator_create
     */
    Obj separator_create() const noexcept { return Obj(lv_menu_separator_create(p_)); }
    /**
     * Add menu to the menu item
     * @param obj  pointer to the obj
     * @param page  pointer to the page to load when obj is clicked
     * @see lv_menu_set_load_page_event
     */
    void set_load_page_event(Obj obj, Obj page) const noexcept { lv_menu_set_load_page_event(p_, obj.raw(), page.raw()); }
    /**
     * Set the how the header should behave and its position
     * @param mode  LV_MENU_HEADER_TOP_FIXED/TOP_UNFIXED/BOTTOM_FIXED
     * @see lv_menu_set_mode_header
     */
    void set_mode_header(Menu::ModeHeader mode) const noexcept { lv_menu_set_mode_header(p_, static_cast<lv_menu_mode_header_t>(mode)); }
    /**
     * Set whether back button should appear at root
     * @param mode  LV_MENU_ROOT_BACK_BUTTON_DISABLED/ENABLED
     * @see lv_menu_set_mode_root_back_button
     */
    void set_mode_root_back_button(Menu::ModeRootBackButton mode) const noexcept { lv_menu_set_mode_root_back_button(p_, static_cast<lv_menu_mode_root_back_button_t>(mode)); }
    /**
     * Set menu page to display in main
     * @param page  pointer to the menu page to set (NULL to clear main and clear menu history)
     * @see lv_menu_set_page
     */
    void set_page(Obj page) const noexcept { lv_menu_set_page(p_, page.raw()); }
    /**
     * Set menu page title
     * @param title  pointer to text for title in header (NULL to not display title)
     * @see lv_menu_set_page_title
     */
    void set_page_title(const char* title) const noexcept { lv_menu_set_page_title(p_, title); }
    /**
     * LVGL keeps this pointer rather than copying what it points at: it must outlive the object. A string literal is the intended use.
     * Set menu page title with a static text. It will not be saved by the label so the 'text' variable
     * has to be 'alive' while the page exists.
     * @param title  pointer to text for title in header (NULL to not display title)
     * @see lv_menu_set_page_title_static
     */
    void set_page_title_static(const char* title) const noexcept { lv_menu_set_page_title_static(p_, title); }
    /**
     * Set menu page to display in sidebar
     * @param page  pointer to the menu page to set (NULL to clear sidebar)
     * @see lv_menu_set_sidebar_page
     */
    void set_sidebar_page(Obj page) const noexcept { lv_menu_set_sidebar_page(p_, page.raw()); }
};
static_assert(sizeof(Menu) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Menu));
#endif // LV_USE_MENU

#if LV_USE_MENU
inline MenuPage MenuPage::create(Obj menu, const char* title) noexcept { return MenuPage(lv_menu_page_create(menu.raw(), title)); }
#endif // LV_USE_MENU

} // namespace lv
