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

#if LV_USE_3DTEXTURE
class _3dtexture : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_3dtexture_class; }

    /**
     * Create a 3dtexture object
     * @param parent  pointer to an object, it will be the parent of the new 3dtexture
     * @return pointer to the created 3dtexture
     * @see lv_3dtexture_create
     */
    static _3dtexture create(Obj parent) noexcept { return _3dtexture(lv_3dtexture_create(parent.raw())); }
    /**
     * Set the flipping behavior of the widget.
     * @param h_flip  true to flip horizontally.
     * @param v_flip  true to flip vertically.
     * @see lv_3dtexture_set_flip
     */
    void set_flip(bool h_flip, bool v_flip) const noexcept { lv_3dtexture_set_flip(p_, h_flip, v_flip); }
    /**
     * Set the source texture of the widget.
     * The object size should be manually set to match.
     * @param id  the texture handle from the 3D graphics backend. I.e., an `unsigned int` texture for OpenGL.
     * @see lv_3dtexture_set_src
     */
    void set_src(lv_3dtexture_id_t id) const noexcept { lv_3dtexture_set_src(p_, id); }
};
static_assert(sizeof(_3dtexture) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(_3dtexture));
#endif // LV_USE_3DTEXTURE

} // namespace lv
