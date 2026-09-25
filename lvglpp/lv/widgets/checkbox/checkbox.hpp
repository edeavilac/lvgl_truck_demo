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

#if LV_USE_CHECKBOX != 0
class Checkbox : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_checkbox_class; }

    /**
     * Create a check box object
     * @param parent  pointer to an object, it will be the parent of the new button
     * @return pointer to the created check box
     * @see lv_checkbox_create
     */
    static Checkbox create(Obj parent) noexcept { return Checkbox(lv_checkbox_create(parent.raw())); }
    /**
     * Get the text of a check box
     * @return pointer to the text of the check box
     * @see lv_checkbox_get_text
     */
    const char* get_text() const noexcept { return lv_checkbox_get_text(p_); }
    /**
     * Set the text of a check box. `txt` will be copied and may be deallocated
     * after this function returns.
     * @param txt  the text of the check box. NULL to refresh with the current text.
     * @see lv_checkbox_set_text
     */
    void set_text(const char* txt) const noexcept { lv_checkbox_set_text(p_, txt); }
    /**
     * LVGL keeps this pointer rather than copying what it points at: it must outlive the object. A string literal is the intended use.
     * Set the text of a check box. `txt` must not be deallocated during the life
     * of this checkbox.
     * @param txt  the text of the check box.
     * @see lv_checkbox_set_text_static
     */
    void set_text_static(const char* txt) const noexcept { lv_checkbox_set_text_static(p_, txt); }
};
static_assert(sizeof(Checkbox) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Checkbox));
#endif // LV_USE_CHECKBOX != 0

} // namespace lv
