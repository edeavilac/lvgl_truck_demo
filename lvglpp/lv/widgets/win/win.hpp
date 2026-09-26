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

#if LV_USE_WIN
class Win : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_win_class; }

    /**
     * Add a button to the window
     * @param icon  an icon to be displayed on the button
     * @param btn_w  width of the button
     * @return the widget where the content of the button can be created
     * @see lv_win_add_button
     */
    Obj add_button(const void* icon, int32_t btn_w) const noexcept { return Obj(lv_win_add_button(p_, icon, btn_w)); }
    /**
     * Add a title to the window
     * @param txt  the text of the title
     * @return the widget where the content of the title can be created
     * @see lv_win_add_title
     */
    Obj add_title(const char* txt) const noexcept { return Obj(lv_win_add_title(p_, txt)); }
    /**
     * Create a window widget
     * @param parent  pointer to a parent widget
     * @return the created window
     * @see lv_win_create
     */
    static Win create(Obj parent) noexcept { return Win(lv_win_create(parent.raw())); }
    /**
     * Get the content of the window
     * @return the content of the window
     * @see lv_win_get_content
     */
    Obj get_content() const noexcept { return Obj(lv_win_get_content(p_)); }
    /**
     * Get the header of the window
     * @return the header of the window
     * @see lv_win_get_header
     */
    Obj get_header() const noexcept { return Obj(lv_win_get_header(p_)); }
};
static_assert(sizeof(Win) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Win));
#endif // LV_USE_WIN

} // namespace lv
