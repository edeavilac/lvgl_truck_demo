#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core.hpp"
#include "lv/display/display.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

/**
 * Used internally to initialize the drawing module
 * @see lv_draw_init
 */
inline void draw_init() noexcept { lv_draw_init(); }

/**
 * Deinitialize the drawing module
 * @see lv_draw_deinit
 */
inline void draw_deinit() noexcept { lv_draw_deinit(); }

/**
 * Allocate a new draw unit with the given size and appends it to the list of draw units
 * @param size  the size to allocate. E.g. `sizeof(my_draw_unit_t)`, where the first element of `my_draw_unit_t` is `lv_draw_unit_t`.
 * @see lv_draw_create_unit
 */
inline void* draw_create_unit(size_t size) noexcept { return lv_draw_create_unit(size); }

/**
 * Add an empty draw task to the draw task list of a layer.
 * @param layer  pointer to a layer
 * @param coords  the coordinates of the draw task
 * @return the created draw task which needs to be further configured e.g. by added a draw descriptor
 * @see lv_draw_add_task
 */
inline DrawTask draw_add_task(Layer& layer, const Area& coords, DrawTaskType type) noexcept { return DrawTask(lv_draw_add_task(layer.raw(), coords.ptr(), static_cast<lv_draw_task_type_t>(type))); }

/**
 * Needs to be called when a draw task is created and configured.
 * It will send an event about the new draw task to the widget
 * and assign it to a draw unit.
 * @param layer  pointer to a layer
 * @param t  pointer to a draw task
 * @see lv_draw_finalize_task_creation
 */
inline void draw_finalize_task_creation(Layer& layer, DrawTask t) noexcept { lv_draw_finalize_task_creation(layer.raw(), t.raw()); }

/**
 * Try dispatching draw tasks to draw units
 * @see lv_draw_dispatch
 */
inline void draw_dispatch() noexcept { lv_draw_dispatch(); }

/**
 * Used internally to try dispatching draw tasks of a specific layer
 * @param disp  pointer to a display on which the dispatching was requested
 * @param layer  pointer to a layer
 * @return at least one draw task is being rendered (maybe it was taken earlier)
 * @see lv_draw_dispatch_layer
 */
inline bool draw_dispatch_layer(Display disp, Layer& layer) noexcept { return lv_draw_dispatch_layer(disp.raw(), layer.raw()); }

/**
 * Wait for a new dispatch request.
 * It's blocking if `LV_USE_OS == 0` else it yields
 * @see lv_draw_dispatch_wait_for_request
 */
inline void draw_dispatch_wait_for_request() noexcept { lv_draw_dispatch_wait_for_request(); }

/**
 * Wait for draw finish in case of asynchronous task execution.
 * If `LV_USE_OS == 0` it just return.
 * @see lv_draw_wait_for_finish
 */
inline void draw_wait_for_finish() noexcept { lv_draw_wait_for_finish(); }

/**
 * When a draw unit finished a draw task it needs to request dispatching
 * to let LVGL assign a new draw task to it
 * @see lv_draw_dispatch_request
 */
inline void draw_dispatch_request() noexcept { lv_draw_dispatch_request(); }

/**
 * Get the total number of draw units.
 * @see lv_draw_get_unit_count
 */
inline uint32_t draw_get_unit_count() noexcept { return lv_draw_get_unit_count(); }

/**
 * If there is only one draw unit check the first draw task if it's available.
 * If there are multiple draw units call `lv_draw_get_next_available_task` to find a task.
 * @param layer  the draw layer to search in
 * @param t_prev  continue searching from this task
 * @param draw_unit_id  check the task where `preferred_draw_unit_id` equals this value or `LV_DRAW_UNIT_NONE`
 * @return an available draw task or NULL if there is not any
 * @see lv_draw_get_available_task
 */
inline DrawTask draw_get_available_task(Layer& layer, DrawTask t_prev, uint8_t draw_unit_id) noexcept { return DrawTask(lv_draw_get_available_task(layer.raw(), t_prev.raw(), draw_unit_id)); }

/**
 * Find and available draw task
 * @param layer  the draw layer to search in
 * @param t_prev  continue searching from this task
 * @param draw_unit_id  check the task where `preferred_draw_unit_id` equals this value or `LV_DRAW_UNIT_NONE`
 * @return an available draw task or NULL if there is not any
 * @see lv_draw_get_next_available_task
 */
inline DrawTask draw_get_next_available_task(Layer& layer, DrawTask t_prev, uint8_t draw_unit_id) noexcept { return DrawTask(lv_draw_get_next_available_task(layer.raw(), t_prev.raw(), draw_unit_id)); }

/**
 * Tell how many draw task are waiting to be drawn on the area of `t_check`.
 * It can be used to determine if a GPU shall combine many draw tasks into one or not.
 * If a lot of tasks are waiting for the current ones it makes sense to draw them one-by-one
 * to not block the dependent tasks' rendering
 * @param t_check  the task whose dependent tasks shall be counted
 * @return number of tasks depending on `t_check`
 * @see lv_draw_get_dependent_count
 */
inline uint32_t draw_get_dependent_count(DrawTask t_check) noexcept { return lv_draw_get_dependent_count(t_check.raw()); }

/**
 * Send an event to the draw units
 * @param name  the name of the draw unit to send the event to
 * @param code  the event code
 * @param param  the event parameter
 * @see lv_draw_unit_send_event
 */
inline void draw_unit_send_event(const char* name, EventCode code, void* param) noexcept { lv_draw_unit_send_event(name, static_cast<lv_event_code_t>(code), param); }

/**
 * Create (allocate) a new layer on a parent layer
 * @param parent_layer  the parent layer to which the layer will be merged when it's rendered
 * @param color_format  the color format of the layer
 * @param area  the areas of the layer (absolute coordinates)
 * @return the new target_layer or NULL on error
 * @see lv_draw_layer_create
 */
inline lv_layer_t* draw_layer_create(Layer& parent_layer, ColorFormat color_format, const Area& area) noexcept { return lv_draw_layer_create(parent_layer.raw(), static_cast<lv_color_format_t>(color_format), area.ptr()); }

/**
 * Initialize a layer which is allocated by the user
 * @param layer  pointer the layer to initialize (its lifetime needs to be managed by the user)
 * @param parent_layer  the parent layer to which the layer will be merged when it's rendered
 * @param color_format  the color format of the layer
 * @param area  the areas of the layer (absolute coordinates)
 * @see lv_draw_layer_init
 */
inline void draw_layer_init(Layer& layer, Layer& parent_layer, ColorFormat color_format, const Area& area) noexcept { lv_draw_layer_init(layer.raw(), parent_layer.raw(), static_cast<lv_color_format_t>(color_format), area.ptr()); }

/**
 * Try to allocate a buffer for the layer.
 * @param layer  pointer to a layer
 * @return pointer to the allocated aligned buffer or NULL on failure
 * @see lv_draw_layer_alloc_buf
 */
inline void* draw_layer_alloc_buf(Layer& layer) noexcept { return lv_draw_layer_alloc_buf(layer.raw()); }

/**
 * Got to a pixel at X and Y coordinate on a layer
 * @param layer  pointer to a layer
 * @param x  the target X coordinate
 * @param y  the target X coordinate
 * @return `buf` offset to point to the given X and Y coordinate
 * @see lv_draw_layer_go_to_xy
 */
inline void* draw_layer_go_to_xy(Layer& layer, int32_t x, int32_t y) noexcept { return lv_draw_layer_go_to_xy(layer.raw(), x, y); }

/** @see lv_draw_layer_create_drop_shadow */
inline lv_layer_t* draw_layer_create_drop_shadow(Layer& parent_layer, const lv_draw_dsc_base_t* base, const Area& area) noexcept { return lv_draw_layer_create_drop_shadow(parent_layer.raw(), base, area.ptr()); }

/** @see lv_draw_layer_finish_drop_shadow */
inline void draw_layer_finish_drop_shadow(Layer& drop_shadow_layer, const lv_draw_dsc_base_t* base) noexcept { lv_draw_layer_finish_drop_shadow(drop_shadow_layer.raw(), base); }

inline Area DrawTask::get_area() const noexcept {
    lv_area_t area_out{};
    lv_draw_task_get_area(p_, &area_out);
    return Area{area_out};
}

inline void* DrawTask::get_draw_dsc() const noexcept { return lv_draw_task_get_draw_dsc(p_); }

inline DrawTaskType DrawTask::get_type() const noexcept { return static_cast<DrawTaskType>(lv_draw_task_get_type(p_)); }

} // namespace lv
