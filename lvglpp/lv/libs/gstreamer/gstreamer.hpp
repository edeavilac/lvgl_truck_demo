#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core/obj.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/misc/event.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_GSTREAMER
/**
 * Create a gstreamer object
 * @param parent  pointer to an object, it will be the parent of the new gstreamer
 * @return pointer to the created gstreamer
 * @see lv_gstreamer_create
 */
inline Obj gstreamer_create(Obj parent) noexcept { return Obj(lv_gstreamer_create(parent.raw())); }

/**
 * Add a source to this gstreamer object
 * @param gstreamer  pointer to a gstreamer object
 * @param factory_name  the factory name for the source of this gstreamer object. for common factory names, check `LV_GSTREAMER_FACTORY_XXX` defines
 * @param property  the property name for the gstreamer source object for common properties, see `LV_GSTREAMER_PROPERTY_XXX` defines Passing NULL will create the source object but not set its source
 * @param source  the property value for the gstreamer source object Passing NULL will create the source object but not set its source
 * @return LV_RESULT_OK if the source was correctly set else LV_RESULT_INVALID
 * @see lv_gstreamer_set_src
 */
inline Result gstreamer_set_src(Obj gstreamer, const char* factory_name, const char* property, const char* source) noexcept { return static_cast<Result>(lv_gstreamer_set_src(gstreamer.raw(), factory_name, property, source)); }

/**
 * Play this gstreamer
 * @param gstreamer  pointer to a gstreamer object
 * @see lv_gstreamer_play
 */
inline void gstreamer_play(Obj gstreamer) noexcept { lv_gstreamer_play(gstreamer.raw()); }

/**
 * Pause this gstreamer
 * @param gstreamer  pointer to a gstreamer object
 * @see lv_gstreamer_pause
 */
inline void gstreamer_pause(Obj gstreamer) noexcept { lv_gstreamer_pause(gstreamer.raw()); }

/**
 * Stop this gstreamer
 * @param gstreamer  pointer to a gstreamer object
 * @see lv_gstreamer_stop
 */
inline void gstreamer_stop(Obj gstreamer) noexcept { lv_gstreamer_stop(gstreamer.raw()); }

/**
 * Seek a position in this gstreamer
 * @param gstreamer  pointer to a gstreamer object
 * @param position  position to seek to
 * @see lv_gstreamer_set_position
 */
inline void gstreamer_set_position(Obj gstreamer, uint32_t position) noexcept { lv_gstreamer_set_position(gstreamer.raw(), position); }

/**
 * Get the duration of this gstreamer
 * @param gstreamer  pointer to a gstreamer object
 * @return the duration (in ms) of the gstreamer object
 * @see lv_gstreamer_get_duration
 */
inline uint32_t gstreamer_get_duration(Obj gstreamer) noexcept { return lv_gstreamer_get_duration(gstreamer.raw()); }

/**
 * Get the position of this gstreamer
 * @param gstreamer  pointer to a gstreamer object
 * @return the position (in ms) of the gstreamer object
 * @see lv_gstreamer_get_position
 */
inline uint32_t gstreamer_get_position(Obj gstreamer) noexcept { return lv_gstreamer_get_position(gstreamer.raw()); }

/**
 * Get the state of this gstreamer
 * @param gstreamer  pointer to a gstreamer object
 * @see lv_gstreamer_get_state
 */
inline GstreamerState gstreamer_get_state(Obj gstreamer) noexcept { return static_cast<GstreamerState>(lv_gstreamer_get_state(gstreamer.raw())); }

/**
 * Set the volume of this gstreamer
 * @param gstreamer  pointer to a gstreamer object
 * @param volume  the value to set in the range [0..100]. Higher values are clamped
 * @see lv_gstreamer_set_volume
 */
inline void gstreamer_set_volume(Obj gstreamer, uint8_t volume) noexcept { lv_gstreamer_set_volume(gstreamer.raw(), volume); }

/**
 * Get the volume of this gstreamer
 * @param gstreamer  pointer to a gstreamer object
 * @return the volume for this gstreamer
 * @see lv_gstreamer_get_volume
 */
inline uint8_t gstreamer_get_volume(Obj gstreamer) noexcept { return lv_gstreamer_get_volume(gstreamer.raw()); }

/**
 * Set the speed rate of this gstreamer
 * @param gstreamer  pointer to a gstreamer object
 * @param rate  the rate factor. Example values: - 256: 1x - <256: slow down - >256: speed up - 128: 0.5x - 512: 2x
 * @see lv_gstreamer_set_rate
 */
inline void gstreamer_set_rate(Obj gstreamer, uint32_t rate) noexcept { lv_gstreamer_set_rate(gstreamer.raw(), rate); }

/**
 * Retrieve the stream state from a STATE_CHANGED event callback
 * @param e  pointer to the event
 * @return the stream state or -1 if `e` is invalid (i.e. NULL or does not match expected event)
 * @see lv_gstreamer_get_stream_state
 */
inline GstreamerStreamState gstreamer_get_stream_state(Event& e) noexcept { return static_cast<GstreamerStreamState>(lv_gstreamer_get_stream_state(e.raw())); }
#endif // LV_USE_GSTREAMER

} // namespace lv
