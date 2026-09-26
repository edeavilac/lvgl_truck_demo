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

#if LV_USE_TILEVIEW
class Tileview : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_tileview_class; }

    /**
     * Add a tile to the tileview
     * @param col_id  column id of the tile
     * @param row_id  row id of the tile
     * @param dir  direction to move to the next tile
     * @return pointer to the added tile object
     * @see lv_tileview_add_tile
     */
    Obj add_tile(uint8_t col_id, uint8_t row_id, Dir dir) const noexcept { return Obj(lv_tileview_add_tile(p_, col_id, row_id, static_cast<lv_dir_t>(dir))); }
    /**
     * Create a tileview object
     * @param parent  pointer to an object, it will be the parent of the new tileview
     * @return pointer to the created tileview
     * @see lv_tileview_create
     */
    static Tileview create(Obj parent) noexcept { return Tileview(lv_tileview_create(parent.raw())); }
    /**
     * Get the currently active tile in the tileview
     * @return pointer to the currently active tile object
     * @see lv_tileview_get_tile_active
     */
    Obj get_tile_active() const noexcept { return Obj(lv_tileview_get_tile_active(p_)); }
    /**
     * Set the active tile in the tileview.
     * @param tile_obj  pointer to the tile object to be set as active
     * @param anim_en  animation enable flag (LV_ANIM_ON or LV_ANIM_OFF)
     * @see lv_tileview_set_tile
     */
    void set_tile(Obj tile_obj, lv_anim_enable_t anim_en) const noexcept { lv_tileview_set_tile(p_, tile_obj.raw(), anim_en); }
    /**
     * Set the active tile by index in the tileview
     * @param col_id  column id of the tile to be set as active
     * @param row_id  row id of the tile to be set as active
     * @param anim_en  animation enable flag (LV_ANIM_ON or LV_ANIM_OFF)
     * @see lv_tileview_set_tile_by_index
     */
    void set_tile_by_index(uint32_t col_id, uint32_t row_id, lv_anim_enable_t anim_en) const noexcept { lv_tileview_set_tile_by_index(p_, col_id, row_id, anim_en); }
    #if LVPP_COMPAT_V8
    /** v8 spelling of `get_tile_active`. */
    Obj get_tile_act() const noexcept { return get_tile_active(); }
    /** v8 spelling of `set_tile_by_index`. */
    void set_tile_id(uint32_t col_id, uint32_t row_id, lv_anim_enable_t anim_en) const noexcept { return set_tile_by_index(col_id, row_id, anim_en); }
    #endif // LVPP_COMPAT_V8

};
static_assert(sizeof(Tileview) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Tileview));
#endif // LV_USE_TILEVIEW

} // namespace lv
