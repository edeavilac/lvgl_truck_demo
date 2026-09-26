#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/misc/event.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

class Display : public detail::EventAliases<Display, detail::DisplayTarget> {
protected:
    lv_display_t* p_ = nullptr;

public:
    constexpr Display() noexcept = default;  /**< the "no object" handle */
    constexpr explicit Display(lv_display_t* p) noexcept : p_(p) {}

    constexpr lv_display_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(Display a, Display b) noexcept { return a.p_ == b.p_; }

    /**
     * Create a new display with the given resolution
     * @param hor_res  horizontal resolution in pixels
     * @param ver_res  vertical resolution in pixels
     * @return pointer to a display object or `NULL` on error
     * @see lv_display_create
     */
    static Display create(int32_t hor_res, int32_t ver_res) noexcept;
    /**
     * Remove a display
     * @see lv_display_delete
     */
    void delete_() const noexcept;
    /**
     * Remove an event
     * @param index  the index of the event to remove
     * @return true: and event was removed; false: no event was removed
     * @see lv_display_delete_event
     */
    bool delete_event(uint32_t index) const noexcept;
    /**
     * Delete screen refresher timer
     * @see lv_display_delete_refr_timer
     */
    void delete_refr_timer() const noexcept;
    /**
     * For specified display, computes the number of pixels (a distance or size) as if the
     * display had 160 DPI.  This allows you to specify 1/160-th fractions of an inch to
     * get real distance on the display that will be consistent regardless of its current
     * DPI.  It ensures `lv_dpx(100)`, for example, will have the same physical size
     * regardless to the DPI of the display.
     * @param n  number of 1/160-th-inch units to compute with
     * @return number of pixels to use to make that distance
     * @see lv_display_dpx
     */
    int32_t dpx(int32_t n) const noexcept;
    /**
     * Temporarily enable and disable the invalidation of the display.
     * @param en  true: enable invalidation; false: invalidation
     * @see lv_display_enable_invalidation
     */
    void enable_invalidation(bool en) const noexcept;
    /**
     * Tell if it's the last area of the refreshing process.
     * Can be called from `flush_cb` to execute some special display refreshing if needed when all areas are flushed.
     * @return true: it's the last area to flush; false: there are other areas too which will be refreshed soon
     * @see lv_display_flush_is_last
     */
    bool flush_is_last() const noexcept;
    /**
     * Call from the display driver when the flushing is finished
     * @see lv_display_flush_ready
     */
    void flush_ready() const noexcept;
    /**
     * Get if anti-aliasing is enabled for a display or not
     * @return true/false
     * @see lv_display_get_antialiasing
     */
    bool get_antialiasing() const noexcept;
    /** @see lv_display_get_buf_active */
    DrawBuf get_buf_active() const noexcept;
    /**
     * Get the color format of the display
     * @return the color format
     * @see lv_display_get_color_format
     */
    ColorFormat get_color_format() const noexcept;
    /**
     * Get the DPI of the display
     * @return dpi of the display
     * @see lv_display_get_dpi
     */
    int32_t get_dpi() const noexcept;
    /**
     * Get the size of the draw buffers
     * @return the size of the draw buffer in bytes for valid display, 0 otherwise
     * @see lv_display_get_draw_buf_size
     */
    uint32_t get_draw_buf_size() const noexcept;
    /** @see lv_display_get_driver_data */
    void* get_driver_data() const noexcept;
    /**
     * Get the number of event attached to a display
     * @return number of events
     * @see lv_display_get_event_count
     */
    uint32_t get_event_count() const noexcept;
    /**
     * Get an event descriptor for an event
     * @param index  the index of the event
     * @return the event descriptor
     * @see lv_display_get_event_dsc
     */
    EventDsc get_event_dsc(uint32_t index) const noexcept;
    /**
     * Get the horizontal resolution of a display.
     * @return the horizontal resolution of the display.
     * @see lv_display_get_horizontal_resolution
     */
    int32_t get_horizontal_resolution() const noexcept;
    /**
     * Get elapsed time since last user activity on a display (e.g. click)
     * @return elapsed ticks (milliseconds) since the last activity
     * @see lv_display_get_inactive_time
     */
    uint32_t get_inactive_time() const noexcept;
    /**
     * Get the size of the invalidated draw buffer. Can be used in the flush callback
     * to get the number of bytes used in the current render buffer.
     * @param width  the width of the invalidated area
     * @param height  the height of the invalidated area
     * @return the size of the invalidated draw buffer in bytes, not accounting for any preceding palette information for a valid display, 0 otherwise
     * @see lv_display_get_invalidated_draw_buf_size
     */
    uint32_t get_invalidated_draw_buf_size(uint32_t width, uint32_t height) const noexcept;
    /**
     * Return the bottom layer. The bottom layer is the same on all screen and it is under the normal screen layer.
     * It's visible only if the screen is transparent.
     * @return pointer to the bottom layer object
     * @see lv_display_get_layer_bottom
     */
    Obj get_layer_bottom() const noexcept;
    /**
     * Return the sys. layer. The system layer is the same on all screen and it is above the normal screen and the top layer.
     * @return pointer to the sys layer object
     * @see lv_display_get_layer_sys
     */
    Obj get_layer_sys() const noexcept;
    /**
     * Return the top layer. The top layer is the same on all screens and it is above the normal screen layer.
     * @return pointer to the top layer object
     * @see lv_display_get_layer_top
     */
    Obj get_layer_top() const noexcept;
    /**
     * Get if matrix rotation is enabled for a display or not
     * @return true: matrix rotation is enabled; false: disabled
     * @see lv_display_get_matrix_rotation
     */
    bool get_matrix_rotation() const noexcept;
    /**
     * Get the next display.
     * @return the next display or NULL if no more. Gives the first display when the parameter is NULL.
     * @see lv_display_get_next
     */
    Display get_next() const noexcept;
    /**
     * Get the horizontal offset from the full / physical display
     * @return the horizontal offset from the physical display
     * @see lv_display_get_offset_x
     */
    int32_t get_offset_x() const noexcept;
    /**
     * Get the vertical offset from the full / physical display
     * @return the horizontal offset from the physical display
     * @see lv_display_get_offset_y
     */
    int32_t get_offset_y() const noexcept;
    /**
     * Get the original horizontal resolution of a display without considering rotation
     * @return the horizontal resolution of the display.
     * @see lv_display_get_original_horizontal_resolution
     */
    int32_t get_original_horizontal_resolution() const noexcept;
    /**
     * Get the original vertical resolution of a display without considering rotation
     * @return the vertical resolution of the display
     * @see lv_display_get_original_vertical_resolution
     */
    int32_t get_original_vertical_resolution() const noexcept;
    /**
     * Get the physical horizontal resolution of a display
     * @return the physical horizontal resolution of the display
     * @see lv_display_get_physical_horizontal_resolution
     */
    int32_t get_physical_horizontal_resolution() const noexcept;
    /**
     * Get the physical vertical resolution of a display
     * @return the physical vertical resolution of the display
     * @see lv_display_get_physical_vertical_resolution
     */
    int32_t get_physical_vertical_resolution() const noexcept;
    /**
     * Get a pointer to the screen refresher timer to
     * modify its parameters with `lv_timer_...` functions.
     * @return pointer to the display refresher timer. (NULL on error)
     * @see lv_display_get_refr_timer
     */
    Timer get_refr_timer() const noexcept;
    /**
     * Get display render mode
     * @return display's render mode (LV_DISPLAY_RENDER_MODE_PARTIAL/DIRECT/FULL)
     * @see lv_display_get_render_mode
     */
    DisplayRenderMode get_render_mode() const noexcept;
    /**
     * Get the current rotation of this display.
     * @return the current rotation
     * @see lv_display_get_rotation
     */
    DisplayRotation get_rotation() const noexcept;
    /**
     * Return a pointer to the active screen on a display
     * @return pointer to the active screen object (loaded by 'lv_screen_load()')
     * @see lv_display_get_screen_active
     */
    Obj get_screen_active() const noexcept;
    #if LV_USE_OBJ_NAME
    /**
     * Get screen by its name on a display. The name should be set by
     * `lv_obj_set_name()` or `lv_obj_set_name_static()`.
     * @param screen_name  name of the screen to get
     * @return pointer to the screen, or NULL if not found.
     * @see lv_display_get_screen_by_name
     */
    Obj get_screen_by_name(const char* screen_name) const noexcept;
    #endif // LV_USE_OBJ_NAME

    /**
     * Return the screen that is currently being loaded by the display
     * @return pointer to the screen being loaded or NULL if no screen is currently being loaded
     * @see lv_display_get_screen_loading
     */
    Obj get_screen_loading() const noexcept;
    /**
     * Return with a pointer to the previous screen. Only used during screen transitions.
     * @return pointer to the previous screen object or NULL if not used now
     * @see lv_display_get_screen_prev
     */
    Obj get_screen_prev() const noexcept;
    /**
     * Get the theme of a display
     * @return the display's theme (can be NULL)
     * @see lv_display_get_theme
     */
    Theme get_theme() const noexcept;
    /**
     * Get the number of tiles used for parallel rendering
     * @return number of tiles
     * @see lv_display_get_tile_cnt
     */
    uint32_t get_tile_cnt() const noexcept;
    /** @see lv_display_get_user_data */
    void* get_user_data() const noexcept;
    /**
     * Get the vertical resolution of a display
     * @return the vertical resolution of the display
     * @see lv_display_get_vertical_resolution
     */
    int32_t get_vertical_resolution() const noexcept;
    /**
     * Get display is double buffered.
     * @return return true if display is double buffered
     * @see lv_display_is_double_buffered
     */
    bool is_double_buffered() const noexcept;
    /**
     * Get display invalidation is enabled.
     * @return return true if invalidation is enabled
     * @see lv_display_is_invalidation_enabled
     */
    bool is_invalidation_enabled() const noexcept;
    /**
     * Register vsync event of a display. `LV_EVENT_VSYNC` event will be sent periodically.
     * Please don't use it in display event listeners, as it may cause memory leaks and illegal access issues.
     * @param event_cb  an event callback
     * @param user_data  optional user_data
     * @see lv_display_register_vsync_event
     */
    bool register_vsync_event(lv_event_cb_t event_cb, void* user_data) const noexcept;
    /**
     * Remove an event_cb with user_data
     * @param event_cb  the event_cb of the event to remove
     * @param user_data  user_data
     * @return the count of the event removed
     * @see lv_display_remove_event_cb_with_user_data
     */
    uint32_t remove_event_cb_with_user_data(lv_event_cb_t event_cb, void* user_data) const noexcept;
    /**
     * Rotate an area in-place according to the display's rotation
     * @param area  pointer to an area to rotate
     * @see lv_display_rotate_area
     */
    void rotate_area(Area& area) const noexcept;
    /**
     * Rotate a point in-place according to the display's rotation
     * @param point  pointer to a point to rotate
     * @see lv_display_rotate_point
     */
    void rotate_point(Point& point) const noexcept;
    /**
     * Send an vsync event to a display
     * @param param  optional param
     * @return LV_RESULT_OK: disp wasn't deleted in the event.
     * @see lv_display_send_vsync_event
     */
    Result send_vsync_event(void* param) const noexcept;
    /**
     * Set the third draw buffer for a display.
     * @param buf3  third buffer
     * @see lv_display_set_3rd_draw_buffer
     */
    void set_3rd_draw_buffer(DrawBuf buf3) const noexcept;
    /**
     * Disabling anti-aliasing is not supported since v9. This function will be removed.
     * Enable anti-aliasing for the render engine
     * @param en  true/false
     * @see lv_display_set_antialiasing
     */
    void set_antialiasing(bool en) const noexcept;
    /**
     * Set the buffers for a display, similarly to `lv_display_set_draw_buffers`, but accept the raw buffer pointers.
     * For DIRECT/FULL rending modes, the buffer size must be at least
     * `hor_res * ver_res * lv_color_format_get_size(lv_display_get_color_format(disp))`
     * @param buf1  first buffer
     * @param buf2  second buffer (can be `NULL`)
     * @param buf_size  buffer size in byte
     * @param render_mode  LV_DISPLAY_RENDER_MODE_PARTIAL/DIRECT/FULL
     * @see lv_display_set_buffers
     */
    void set_buffers(void* buf1, void* buf2, uint32_t buf_size, DisplayRenderMode render_mode) const noexcept;
    /**
     * Set the frame buffers for a display, similarly to `lv_display_set_buffers`, but allow
     * for a custom stride as required by a display controller.
     * This allows the frame buffers to have a stride alignment different from the rest of
     * the buffers`
     * @param buf1  first buffer
     * @param buf2  second buffer (can be `NULL`)
     * @param buf_size  buffer size in byte
     * @param stride  buffer stride in bytes
     * @param render_mode  LV_DISPLAY_RENDER_MODE_PARTIAL/DIRECT/FULL
     * @see lv_display_set_buffers_with_stride
     */
    void set_buffers_with_stride(void* buf1, void* buf2, uint32_t buf_size, uint32_t stride, DisplayRenderMode render_mode) const noexcept;
    /**
     * Set the color format of the display.
     * @param color_format  Possible values are - LV_COLOR_FORMAT_RGB565 - LV_COLOR_FORMAT_RGB888 - LV_COLOR_FORMAT_XRGB888 - LV_COLOR_FORMAT_ARGB888
     * @see lv_display_set_color_format
     */
    void set_color_format(ColorFormat color_format) const noexcept;
    /**
     * Set a default display. The new screens will be created on it by default.
     * @see lv_display_set_default
     */
    void set_default() const noexcept;
    /**
     * Set the DPI (dot per inch) of the display.
     * dpi = sqrt(hor_res^2 + ver_res^2) / diagonal"
     * @param dpi  the new DPI
     * @see lv_display_set_dpi
     */
    void set_dpi(int32_t dpi) const noexcept;
    /**
     * Set the buffers for a display, accept a draw buffer pointer.
     * Normally use `lv_display_set_buffers` is enough for most cases.
     * Use this function when an existing lv_draw_buf_t is available.
     * @param buf1  first buffer
     * @param buf2  second buffer (can be `NULL`)
     * @see lv_display_set_draw_buffers
     */
    void set_draw_buffers(DrawBuf buf1, DrawBuf buf2) const noexcept;
    /** @see lv_display_set_driver_data */
    void set_driver_data(void* driver_data) const noexcept;
    #if LV_USE_EXT_DATA
    /**
     * Attaches external user data and destructor callback to a display
     * Associates custom user data with an LVGL display and specifies a destructor function
     * that will be automatically invoked when the display is deleted to properly clean up
     * the associated resources.
     * @param data  User-defined data pointer to associate with the display
     * @see lv_display_set_external_data
     */
    void set_external_data(void* data, void (*arg)(void*)) const noexcept;
    /**
     * Takes the function itself as a template argument, so its real parameter types survive: the C idiom CASTS the pointer, which is undefined whenever they differ, and between the versions they do.
     * Attaches external user data and destructor callback to a display
     * Associates custom user data with an LVGL display and specifies a destructor function
     * that will be automatically invoked when the display is deleted to properly clean up
     * the associated resources.
     * @param data  User-defined data pointer to associate with the display
     * @see lv_display_set_external_data
     */
    template <auto Fn>
    void set_external_data(void* data) const noexcept;
    #endif // LV_USE_EXT_DATA

    /**
     * Set the flush callback which will be called to copy the rendered image to the display.
     * @param flush_cb  the flush callback (`px_map` contains the rendered image as raw pixel map and it should be copied to `area` on the display)
     * @see lv_display_set_flush_cb
     */
    void set_flush_cb(lv_display_flush_cb_t flush_cb) const noexcept;
    /**
     * Set a callback to be used while LVGL is waiting flushing to be finished.
     * It can do any complex logic to wait, including semaphores, mutexes, polling flags, etc.
     * If not set the `disp->flushing` flag is used which can be cleared with `lv_display_flush_ready()`
     * @param wait_cb  a callback to call while LVGL is waiting for flush ready. If NULL `lv_display_flush_ready()` can be used to signal that flushing is ready.
     * @see lv_display_set_flush_wait_cb
     */
    void set_flush_wait_cb(lv_display_flush_wait_cb_t wait_cb) const noexcept;
    /**
     * Use matrix rotation for the display. This function is depended on `LV_DRAW_TRANSFORM_USE_MATRIX`
     * @param enable  true: enable matrix rotation, false: disable
     * @see lv_display_set_matrix_rotation
     */
    void set_matrix_rotation(bool enable) const noexcept;
    /**
     * If physical resolution is not the same as the normal resolution
     * the offset of the active display area can be set here.
     * @param x  X offset
     * @param y  Y offset
     * @see lv_display_set_offset
     */
    void set_offset(int32_t x, int32_t y) const noexcept;
    /**
     * It's not mandatory to use the whole display for LVGL, however in some cases physical resolution is important.
     * For example the touchpad still sees whole resolution and the values needs to be converted
     * to the active LVGL display area.
     * @param hor_res  the new physical horizontal resolution, or -1 to assume it's the same as the normal hor. res.
     * @param ver_res  the new physical vertical resolution, or -1 to assume it's the same as the normal hor. res.
     * @see lv_display_set_physical_resolution
     */
    void set_physical_resolution(int32_t hor_res, int32_t ver_res) const noexcept;
    /**
     * Set display render mode
     * @param render_mode  LV_DISPLAY_RENDER_MODE_PARTIAL/DIRECT/FULL
     * @see lv_display_set_render_mode
     */
    void set_render_mode(DisplayRenderMode render_mode) const noexcept;
    /**
     * Sets the resolution of a display. `LV_EVENT_RESOLUTION_CHANGED` event will be sent.
     * Here the native resolution of the device should be set. If the display will be rotated later with
     * `lv_display_set_rotation` LVGL will swap the hor. and ver. resolution automatically.
     * @param hor_res  the new horizontal resolution
     * @param ver_res  the new vertical resolution
     * @see lv_display_set_resolution
     */
    void set_resolution(int32_t hor_res, int32_t ver_res) const noexcept;
    /**
     * Set the rotation of this display. LVGL will swap the horizontal and vertical resolutions internally.
     * @param rotation  `LV_DISPLAY_ROTATION_0/90/180/270`
     * @see lv_display_set_rotation
     */
    void set_rotation(DisplayRotation rotation) const noexcept;
    /**
     * Set the sync callback which will be called to synchronize invalidated areas between frame buffers pre-render.
     * @param sync_cb  the sync callback (pointer to `area` needing to be synchronized)
     * @see lv_display_set_sync_cb
     */
    void set_sync_cb(lv_display_sync_cb_t sync_cb) const noexcept;
    /**
     * Set a callback to be used while LVGL is waiting sync to be finished.
     * It can do any complex logic to wait, including semaphores, mutexes, polling flags, etc.
     * If not set the `disp->syncing` flag is used which can be cleared with `lv_display_sync_ready()`
     * @param wait_cb  a callback to call while LVGL is waiting for sync ready. If NULL `lv_display_sync_ready()` can be used to signal that syncing is ready.
     * @see lv_display_set_sync_wait_cb
     */
    void set_sync_wait_cb(lv_display_sync_wait_cb_t wait_cb) const noexcept;
    /**
     * Set the theme of a display. If there are no user created widgets yet the screens' theme will be updated
     * @param th  pointer to a theme
     * @see lv_display_set_theme
     */
    void set_theme(Theme th) const noexcept;
    /**
     * Set the number of tiles for parallel rendering.
     * @param tile_cnt  number of tiles (1 =< tile_cnt < 256)
     * @see lv_display_set_tile_cnt
     */
    void set_tile_cnt(uint32_t tile_cnt) const noexcept;
    /** @see lv_display_set_user_data */
    void set_user_data(void* user_data) const noexcept;
    /**
     * Tell if it's the last area of the syncing process.
     * Can be called from `sync_cb` to execute some special display refreshing if needed when all areas are synced.
     * @return true: it's the last area to sync; false: there are other areas too which will be synced soon
     * @see lv_display_sync_is_last
     */
    bool sync_is_last() const noexcept;
    /**
     * Call from the display driver when the syncing is finished
     * @see lv_display_sync_ready
     */
    void sync_ready() const noexcept;
    /**
     * Manually trigger an activity on a display
     * @see lv_display_trigger_activity
     */
    void trigger_activity() const noexcept;
    /**
     * Unregister vsync event of a display. `LV_EVENT_VSYNC` event won't be sent periodically.
     * Please don't use it in display event listeners, as it may cause memory leaks and illegal access issues.
     * @param event_cb  an event callback
     * @param user_data  optional user_data
     * @see lv_display_unregister_vsync_event
     */
    bool unregister_vsync_event(lv_event_cb_t event_cb, void* user_data) const noexcept;
    #if LVPP_COMPAT_V8
    /** v8 spelling of `delete_`. */
    void remove() const noexcept;
    /** v8 spelling of `get_horizontal_resolution`. */
    int32_t get_hor_res() const noexcept;
    /** v8 spelling of `get_vertical_resolution`. */
    int32_t get_ver_res() const noexcept;
    /** v8 spelling of `get_physical_horizontal_resolution`. */
    int32_t get_physical_hor_res() const noexcept;
    /** v8 spelling of `get_physical_vertical_resolution`. */
    int32_t get_physical_ver_res() const noexcept;
    /** v8 spelling of `get_screen_active`. */
    Obj get_scr_act() const noexcept;
    /** v8 spelling of `get_screen_prev`. */
    Obj get_scr_prev() const noexcept;
    /** v8 spelling of `trigger_activity`. */
    void trig_activity() const noexcept;
    #endif // LVPP_COMPAT_V8

};
static_assert(sizeof(Display) == sizeof(lv_display_t*));
static_assert(__is_trivially_copyable(Display));

/**
 * Get the default display
 * @return pointer to the default display
 * @see lv_display_get_default
 */
inline Display display_get_default() noexcept;

/**
 * Load a screen on the default display
 * @param scr  pointer to a screen
 * @see lv_screen_load
 */
inline void display_screen_load(Obj scr) noexcept;

/**
 * Switch screen with animation
 * @param scr  pointer to the new screen to load
 * @param anim_type  type of the animation from `lv_screen_load_anim_t`, e.g. `LV_SCREEN_LOAD_ANIM_MOVE_LEFT`
 * @param time  time of the animation
 * @param delay  delay before the transition
 * @param auto_del  true: automatically delete the old screen
 * @see lv_screen_load_anim
 */
inline void display_screen_load_anim(Obj scr, ScreenLoadAnim anim_type, uint32_t time, uint32_t delay, bool auto_del) noexcept;

/**
 * Get the active screen of the default display
 * @return pointer to the active screen
 * @see lv_screen_active
 */
inline Obj display_screen_active() noexcept;

/**
 * Get the top layer  of the default display
 * @return pointer to the top layer
 * @see lv_layer_top
 */
inline Obj layer_top() noexcept;

/**
 * Get the system layer  of the default display
 * @return pointer to the sys layer
 * @see lv_layer_sys
 */
inline Obj layer_sys() noexcept;

/**
 * Get the bottom layer  of the default display
 * @return pointer to the bottom layer
 * @see lv_layer_bottom
 */
inline Obj layer_bottom() noexcept;

/**
 * For default display, computes the number of pixels (a distance or size) as if the
 * display had 160 DPI.  This allows you to specify 1/160-th fractions of an inch to
 * get real distance on the display that will be consistent regardless of its current
 * DPI.  It ensures `lv_dpx(100)`, for example, will have the same physical size
 * regardless to the DPI of the display.
 * @param n  number of 1/160-th-inch units to compute with
 * @return number of pixels to use to make that distance
 * @see lv_dpx
 */
inline int32_t display_dpx(int32_t n) noexcept;

} // namespace lv
