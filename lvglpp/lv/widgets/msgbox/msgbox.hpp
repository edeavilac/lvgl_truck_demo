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

#if LV_USE_MSGBOX
class Msgbox : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_msgbox_class; }

    /**
     * Add a close button to the message box. It also creates a header.
     * @return the created close button
     * @see lv_msgbox_add_close_button
     */
    Obj add_close_button() const noexcept { return Obj(lv_msgbox_add_close_button(p_)); }
    /**
     * Add a button to the footer of to the message box. It also creates a footer.
     * @param text  the text of the button
     * @return the created button
     * @see lv_msgbox_add_footer_button
     */
    Obj add_footer_button(const char* text) const noexcept { return Obj(lv_msgbox_add_footer_button(p_, text)); }
    /**
     * Add a button to the header of to the message box. It also creates a header.
     * @param icon  the icon of the button
     * @return the created button
     * @see lv_msgbox_add_header_button
     */
    Obj add_header_button(const void* icon) const noexcept { return Obj(lv_msgbox_add_header_button(p_, icon)); }
    /**
     * Add a text to the content area of message box. Multiple texts will be created below each other.
     * @param text  text to add
     * @return the created label
     * @see lv_msgbox_add_text
     */
    Obj add_text(const char* text) const noexcept { return Obj(lv_msgbox_add_text(p_, text)); }
    /**
     * Add a formatted text to the content area of message box. Multiple texts will be created below each other.
     * @param fmt  `printf`-like format string
     * @return the created label
     * @see lv_msgbox_add_text_fmt
     */
    template <typename... A>
    Obj add_text_fmt(const char* fmt, A... args) const noexcept { return Obj(lv_msgbox_add_text_fmt(p_, fmt, args...)); }
    /**
     * Add title to the message box. It also creates a header for the title.
     * @param title  the text of the tile
     * @return the created title label
     * @see lv_msgbox_add_title
     */
    Obj add_title(const char* title) const noexcept { return Obj(lv_msgbox_add_title(p_, title)); }
    /**
     * Close a message box
     * @see lv_msgbox_close
     */
    void close() const noexcept { lv_msgbox_close(p_); }
    /**
     * Close a message box in the next call of the message box
     * @see lv_msgbox_close_async
     */
    void close_async() const noexcept { lv_msgbox_close_async(p_); }
    /**
     * Create an empty message box
     * @param parent  the parent or NULL to create a modal msgbox
     * @return the created message box
     * @see lv_msgbox_create
     */
    static Msgbox create(Obj parent) noexcept { return Msgbox(lv_msgbox_create(parent.raw())); }
    /**
     * Get the content widget
     * @return the content
     * @see lv_msgbox_get_content
     */
    Obj get_content() const noexcept { return Obj(lv_msgbox_get_content(p_)); }
    /**
     * Get the footer widget
     * @return the footer, or NULL if not exists
     * @see lv_msgbox_get_footer
     */
    Obj get_footer() const noexcept { return Obj(lv_msgbox_get_footer(p_)); }
    /**
     * Get the header widget
     * @return the header, or NULL if not exists
     * @see lv_msgbox_get_header
     */
    Obj get_header() const noexcept { return Obj(lv_msgbox_get_header(p_)); }
    /**
     * Get the title label
     * @return the title, or NULL if it does not exist
     * @see lv_msgbox_get_title
     */
    Obj get_title() const noexcept { return Obj(lv_msgbox_get_title(p_)); }
};
static_assert(sizeof(Msgbox) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Msgbox));
#endif // LV_USE_MSGBOX

} // namespace lv
