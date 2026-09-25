#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core/obj.hpp"
#include "lv/draw/draw_buf.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lv/widgets/canvas/canvas.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if (LV_USE_LOTTIE) && (LV_USE_CANVAS != 0) && (LV_USE_IMAGE != 0)
class Lottie : public Canvas {
public:
    using Canvas::Canvas;

    /**
     * Create a lottie animation
     * @param parent  pointer to the parent widget
     * @return pointer to the created Lottie animation widget
     * @see lv_lottie_create
     */
    static Lottie create(Obj parent) noexcept { return Lottie(lv_lottie_create(parent.raw())); }
    /**
     * Get the LVGL animation which controls the lottie animation
     * @return the LVGL animation
     * @see lv_lottie_get_anim
     */
    lv_anim_t* get_anim() const noexcept { return lv_lottie_get_anim(p_); }
    /**
     * Set a buffer for the animation. It also defines the size of the animation
     * @param w  width of the animation and buffer
     * @param h  height of the animation and buffer
     * @param buf  a static buffer with `width x height x 4` byte size
     * @see lv_lottie_set_buffer
     */
    void set_buffer(int32_t w, int32_t h, void* buf) const noexcept { lv_lottie_set_buffer(p_, w, h, buf); }
    /**
     * Set a draw buffer for the animation. It also defines the size of the animation
     * @param draw_buf  an initialized draw buffer with ARGB8888 color format
     * @see lv_lottie_set_draw_buf
     */
    void set_draw_buf(DrawBuf draw_buf) const noexcept { lv_lottie_set_draw_buf(p_, draw_buf.raw()); }
    /**
     * Set the source for the animation as an array
     * @param src  the lottie animation converted to an nul terminated array
     * @param src_size  size of the source array in bytes
     * @see lv_lottie_set_src_data
     */
    void set_src_data(const void* src, size_t src_size) const noexcept { lv_lottie_set_src_data(p_, src, src_size); }
    /**
     * Set the source for the animation as a path.
     * Lottie doesn't use LVGL's File System API.
     * @param src  path to a json file, e.g. "path/to/file.json"
     * @see lv_lottie_set_src_file
     */
    void set_src_file(const char* src) const noexcept { lv_lottie_set_src_file(p_, src); }
};
static_assert(sizeof(Lottie) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Lottie));
#endif // (LV_USE_LOTTIE) && (LV_USE_CANVAS != 0) && (LV_USE_IMAGE != 0)

} // namespace lv
