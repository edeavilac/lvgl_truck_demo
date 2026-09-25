#pragma once
// Bodies of widgets/button/button.hpp, separated because its file cycle needs every type
// complete. Same mechanism as D-C7, applied where the graph asks for it.
// Included by the umbrella and never by a header: it is NOT a translation
// unit and every definition in it is `inline`. The stem says so, not the
// extension, so a glob written for *.hpp still installs it.

#include "lv/lvgl.hpp"

namespace lv {

#if LV_USE_BUTTON != 0
inline Button Button::create(Obj parent) noexcept { return Button(lv_button_create(parent.raw())); }
#endif // LV_USE_BUTTON != 0

#if (LV_USE_BUTTON != 0) && (LVPP_COMPAT_V8)
inline Button Button::btn_create(Obj parent) noexcept { return create(parent); }
#endif // (LV_USE_BUTTON != 0) && (LVPP_COMPAT_V8)

} // namespace lv
