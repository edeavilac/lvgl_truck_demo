#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core/obj.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/libs/gltf/gltf_data/gltf_model.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_GLTF
/**
 * Create a glTF object
 * @param parent  pointer to the parent object
 * @return pointer to the created glTF object
 * @see lv_gltf_create
 */
inline Obj gltf_create(Obj parent) noexcept { return Obj(lv_gltf_create(parent.raw())); }

/**
 * Assign an environment to a glTF object for IBL rendering
 * @param obj  pointer to a glTF viewer object
 * @param environment  pointer to the environment to use
 * @see lv_gltf_set_environment
 */
inline void gltf_set_environment(Obj obj, lv_gltf_environment_t* environment) noexcept { lv_gltf_set_environment(obj.raw(), environment); }

/**
 * Load a glTF model from a file into the viewer
 * @param obj  pointer to a glTF viewer object
 * @param path  file path to the glTF model to load
 * @return pointer to the loaded glTF model, or NULL on failure
 * @see lv_gltf_load_model_from_file
 */
inline GltfModel gltf_load_model_from_file(Obj obj, const char* path) noexcept { return GltfModel(lv_gltf_load_model_from_file(obj.raw(), path)); }

/**
 * Load a glTF model from a byte array into the viewer
 * @param obj  pointer to a glTF viewer object
 * @param bytes  glTF raw data
 * @param len  glTF raw data length in bytes
 * @return pointer to the loaded glTF model, or NULL on failure
 * @see lv_gltf_load_model_from_bytes
 */
inline GltfModel gltf_load_model_from_bytes(Obj obj, const uint8_t* bytes, size_t len) noexcept { return GltfModel(lv_gltf_load_model_from_bytes(obj.raw(), bytes, len)); }

/**
 * Add a glTF model to the viewer.
 * Contrary to `lv_gltf_load_model_from_file` and `lv_gltf_load_model_from_bytes`, the model
 * is owned by the caller of this function meaning that it's the caller's responsibility
 * to delete the model when it is no longer needed, that is, the model must outlive the viewer's lifetime.
 * @param obj  pointer to a glTF viewer object
 * @param model  glTF model to add to the viewer
 * @return LV_RESULT_OK if the model was added to the viewer or LV_RESULT_INVALID on failure
 * @see lv_gltf_add_model
 */
inline Result gltf_add_model(Obj obj, GltfModel model) noexcept { return static_cast<Result>(lv_gltf_add_model(obj.raw(), model.raw())); }

/**
 * Get the number of models loaded in the glTF viewer
 * @param obj  pointer to a glTF viewer object
 * @return the total number of models in the viewer
 * @see lv_gltf_get_model_count
 */
inline uint32_t gltf_get_model_count(Obj obj) noexcept { return lv_gltf_get_model_count(obj.raw()); }

/**
 * Get a specific model by its index
 * @param obj  pointer to a glTF viewer object
 * @param id  index of the model to retrieve (0-based)
 * @return pointer to the model at the specified index, or NULL if index is invalid
 * @see lv_gltf_get_model_by_index
 */
inline GltfModel gltf_get_model_by_index(Obj obj, size_t id) noexcept { return GltfModel(lv_gltf_get_model_by_index(obj.raw(), id)); }

/**
 * Get the primary model from the glTF viewer
 * The primary model is the first model added to the viewer and can be used
 * for camera selection and other primary operations
 * @param obj  pointer to a glTF viewer object
 * @return pointer to the primary model, or NULL if no models are loaded
 * @see lv_gltf_get_primary_model
 */
inline GltfModel gltf_get_primary_model(Obj obj) noexcept { return GltfModel(lv_gltf_get_primary_model(obj.raw())); }

/**
 * Set the yaw (horizontal rotation) of the camera
 * @param obj  pointer to a glTF viewer object
 * @param yaw  yaw angle in degrees
 * @see lv_gltf_set_yaw
 */
inline void gltf_set_yaw(Obj obj, float yaw) noexcept { lv_gltf_set_yaw(obj.raw(), yaw); }

/**
 * Get the yaw (horizontal rotation) of the camera
 * @param obj  pointer to a glTF viewer object
 * @return yaw angle in degrees
 * @see lv_gltf_get_yaw
 */
inline float gltf_get_yaw(Obj obj) noexcept { return lv_gltf_get_yaw(obj.raw()); }

/**
 * Set the pitch (vertical rotation) of the camera
 * @param obj  pointer to a glTF viewer object
 * @param pitch  pitch angle in degrees
 * @see lv_gltf_set_pitch
 */
inline void gltf_set_pitch(Obj obj, float pitch) noexcept { lv_gltf_set_pitch(obj.raw(), pitch); }

/**
 * Get the pitch (vertical rotation) of the camera
 * @param obj  pointer to a glTF viewer object
 * @return pitch angle in degrees
 * @see lv_gltf_get_pitch
 */
inline float gltf_get_pitch(Obj obj) noexcept { return lv_gltf_get_pitch(obj.raw()); }

/**
 * Set the camera distance from the focal point
 * @param obj  pointer to a glTF viewer object
 * @param value  distance value
 * @see lv_gltf_set_distance
 */
inline void gltf_set_distance(Obj obj, float value) noexcept { lv_gltf_set_distance(obj.raw(), value); }

/**
 * Get the camera distance scale factor from the focal point
 * @param obj  pointer to a glTF viewer object
 * @return distance scaling factor value
 * @see lv_gltf_get_distance
 */
inline float gltf_get_distance(Obj obj) noexcept { return lv_gltf_get_distance(obj.raw()); }

/**
 * Get the camera distance from the focal point in world units
 * @param obj  pointer to a GLTF viewer object
 * @return world unit distance value
 * @see lv_gltf_get_world_distance
 */
inline float gltf_get_world_distance(Obj obj) noexcept { return lv_gltf_get_world_distance(obj.raw()); }

/**
 * Set the field of view
 * @param obj  pointer to a glTF viewer object
 * @param value  vertical FOV in degrees. If zero, the view will be orthographic (non-perspective)
 * @see lv_gltf_set_fov
 */
inline void gltf_set_fov(Obj obj, float value) noexcept { lv_gltf_set_fov(obj.raw(), value); }

/**
 * Get the field of view
 * @param obj  pointer to a glTF viewer object
 * @return vertical FOV in degrees
 * @see lv_gltf_get_fov
 */
inline float gltf_get_fov(Obj obj) noexcept { return lv_gltf_get_fov(obj.raw()); }

/**
 * Set the X coordinate of the camera focal point
 * @param obj  pointer to a glTF viewer object
 * @param value  X coordinate
 * @see lv_gltf_set_focal_x
 */
inline void gltf_set_focal_x(Obj obj, float value) noexcept { lv_gltf_set_focal_x(obj.raw(), value); }

/**
 * Get the X coordinate of the camera focal point
 * @param obj  pointer to a glTF viewer object
 * @return X coordinate
 * @see lv_gltf_get_focal_x
 */
inline float gltf_get_focal_x(Obj obj) noexcept { return lv_gltf_get_focal_x(obj.raw()); }

/**
 * Set the Y coordinate of the camera focal point
 * @param obj  pointer to a glTF viewer object
 * @param value  Y coordinate
 * @see lv_gltf_set_focal_y
 */
inline void gltf_set_focal_y(Obj obj, float value) noexcept { lv_gltf_set_focal_y(obj.raw(), value); }

/**
 * Get the Y coordinate of the camera focal point
 * @param obj  pointer to a glTF viewer object
 * @return Y coordinate
 * @see lv_gltf_get_focal_y
 */
inline float gltf_get_focal_y(Obj obj) noexcept { return lv_gltf_get_focal_y(obj.raw()); }

/**
 * Set the Z coordinate of the camera focal point
 * @param obj  pointer to a glTF viewer object
 * @param value  Z coordinate
 * @see lv_gltf_set_focal_z
 */
inline void gltf_set_focal_z(Obj obj, float value) noexcept { lv_gltf_set_focal_z(obj.raw(), value); }

/**
 * Get the Z coordinate of the camera focal point
 * @param obj  pointer to a glTF viewer object
 * @return Z coordinate
 * @see lv_gltf_get_focal_z
 */
inline float gltf_get_focal_z(Obj obj) noexcept { return lv_gltf_get_focal_z(obj.raw()); }

/**
 * Set the focal coordinates to the center point of the model object
 * @param obj  pointer to a glTF viewer object
 * @param model  a model attached to this viewer or NULL for the first model
 * @see lv_gltf_recenter
 */
inline void gltf_recenter(Obj obj, GltfModel model) noexcept { lv_gltf_recenter(obj.raw(), model.raw()); }

/**
 * Set the active camera index
 * The camera is selected from the first glTF model added to the viewer
 * @param obj  pointer to a glTF viewer object
 * @param value  camera index (0 for default camera, 1+ for scene camera index)
 * @see lv_gltf_set_camera
 */
inline void gltf_set_camera(Obj obj, uint32_t value) noexcept { lv_gltf_set_camera(obj.raw(), value); }

/**
 * Get the active camera index
 * @param obj  pointer to a glTF viewer object
 * @return active camera index
 * @see lv_gltf_get_camera
 */
inline uint32_t gltf_get_camera(Obj obj) noexcept { return lv_gltf_get_camera(obj.raw()); }

/**
 * Get the number of cameras in the first glTF model added to the viewer
 * This count represents the valid range for the camera index parameter
 * used with lv_gltf_set_camera()
 * To get the camera count of other models, call
 * lv_gltf_model_get_camera_count(model) directly with the specific model
 * @param obj  pointer to a glTF viewer object
 * @return number of available cameras
 * @see lv_gltf_get_camera_count
 */
inline uint32_t gltf_get_camera_count(Obj obj) noexcept { return lv_gltf_get_camera_count(obj.raw()); }

/**
 * DEPRECATED. See `lv_gltf_model_set_animation_speed`
 * Set the animation speed ratio
 * The actual ratio is the value parameter / LV_GLTF_ANIM_SPEED_NORMAL
 * Values greater than LV_GLTF_ANIM_SPEED_NORMAL will speed-up the animation
 * Values less than LV_GLTF_ANIM_SPEED_NORMAL will slow down the animation
 * @param obj  pointer to a glTF viewer object
 * @param value  speed-up ratio of the animation
 * @see lv_gltf_set_animation_speed
 */
inline void gltf_set_animation_speed(Obj obj, uint32_t value) noexcept { lv_gltf_set_animation_speed(obj.raw(), value); }

/**
 * DEPRECATED. See `lv_gltf_model_get_animation_speed`
 * Get the animation speed ratio
 * The actual ratio is the return value / LV_GLTF_ANIM_SPEED_NORMAL
 * @param obj  pointer to a glTF viewer object
 * @see lv_gltf_get_animation_speed
 */
inline uint32_t gltf_get_animation_speed(Obj obj) noexcept { return lv_gltf_get_animation_speed(obj.raw()); }

/**
 * Set the background mode
 * @param obj  pointer to a glTF viewer object
 * @param value  background mode
 * @see lv_gltf_set_background_mode
 */
inline void gltf_set_background_mode(Obj obj, GltfBgMode value) noexcept { lv_gltf_set_background_mode(obj.raw(), static_cast<lv_gltf_bg_mode_t>(value)); }

/**
 * Get the background mode
 * @param obj  pointer to a glTF viewer object
 * @return background mode
 * @see lv_gltf_get_background_mode
 */
inline GltfBgMode gltf_get_background_mode(Obj obj) noexcept { return static_cast<GltfBgMode>(lv_gltf_get_background_mode(obj.raw())); }

/**
 * Set the background blur amount
 * @param obj  pointer to a glTF viewer object
 * @param value  blur amount between 0 and 100
 * @see lv_gltf_set_background_blur
 */
inline void gltf_set_background_blur(Obj obj, uint32_t value) noexcept { lv_gltf_set_background_blur(obj.raw(), value); }

/**
 * Get the background blur amount
 * @param obj  pointer to a glTF viewer object
 * @return blur amount between 0 and 100
 * @see lv_gltf_get_background_blur
 */
inline uint32_t gltf_get_background_blur(Obj obj) noexcept { return lv_gltf_get_background_blur(obj.raw()); }

/**
 * Set the environmental brightness/power
 * @param obj  pointer to a glTF viewer object
 * @param value  brightness multiplier
 * @see lv_gltf_set_env_brightness
 */
inline void gltf_set_env_brightness(Obj obj, uint32_t value) noexcept { lv_gltf_set_env_brightness(obj.raw(), value); }

/**
 * Get the environmental brightness/power
 * @param obj  pointer to a glTF viewer object
 * @return brightness multiplier
 * @see lv_gltf_get_env_brightness
 */
inline uint32_t gltf_get_env_brightness(Obj obj) noexcept { return lv_gltf_get_env_brightness(obj.raw()); }

/**
 * Set the image exposure level
 * @param obj  pointer to a glTF viewer object
 * @param value  exposure level (1.0 is default)
 * @see lv_gltf_set_image_exposure
 */
inline void gltf_set_image_exposure(Obj obj, float value) noexcept { lv_gltf_set_image_exposure(obj.raw(), value); }

/**
 * Get the image exposure level
 * @param obj  pointer to a glTF viewer object
 * @return exposure level
 * @see lv_gltf_get_image_exposure
 */
inline float gltf_get_image_exposure(Obj obj) noexcept { return lv_gltf_get_image_exposure(obj.raw()); }

/**
 * Set the anti-aliasing mode
 * @param obj  pointer to a glTF viewer object
 * @param value  anti-aliasing mode
 * @see lv_gltf_set_antialiasing_mode
 */
inline void gltf_set_antialiasing_mode(Obj obj, GltfAaMode value) noexcept { lv_gltf_set_antialiasing_mode(obj.raw(), static_cast<lv_gltf_aa_mode_t>(value)); }

/**
 * Get the anti-aliasing mode
 * @param obj  pointer to a glTF viewer object
 * @return anti-aliasing mode
 * @see lv_gltf_get_antialiasing_mode
 */
inline GltfAaMode gltf_get_antialiasing_mode(Obj obj) noexcept { return static_cast<GltfAaMode>(lv_gltf_get_antialiasing_mode(obj.raw())); }

/**
 * Get the point that a given ray intersects with a specified plane at, if any
 * @param ray  the intersection test ray
 * @param collision_point  output lv_3dpoint_t holder, values are only valid if true is the return value
 * @return LV_RESULT_OK if intersection, LV_RESULT_INVALID if no intersection
 * @see lv_intersect_ray_with_plane
 */
inline Result gltf_intersect_ray_with_plane(const lv_3dray_t* ray, const lv_3dplane_t* plane, lv_3dpoint_t* collision_point) noexcept { return static_cast<Result>(lv_intersect_ray_with_plane(ray, plane, collision_point)); }

/**
 * Get a plane that faces the current view camera, centered some units in front of it
 * @param obj  pointer to a GLTF viewer object
 * @param distance  distance in front of the camera to set the plane, in world units. see lv_gltf_get_world_distance to get the auto-distance
 * @return camera facing plane
 * @see lv_gltf_get_current_view_plane
 */
inline lv_3dplane_t gltf_get_current_view_plane(Obj obj, float distance) noexcept { return lv_gltf_get_current_view_plane(obj.raw(), distance); }

/**
 * Calculates a ray originating from the camera and passing through the specified mouse position on the screen.
 * @param obj  pointer to a GLTF viewer object
 * @param screen_pos  screen co-ordinate, in pixels
 * @return mouse point ray
 * @see lv_gltf_get_ray_from_2d_coordinate
 */
inline lv_3dray_t gltf_get_ray_from_2d_coordinate(Obj obj, const Point& screen_pos) noexcept { return lv_gltf_get_ray_from_2d_coordinate(obj.raw(), screen_pos.ptr()); }

/**
 * Get the screen position of a 3d point
 * @param obj  pointer to a GLTF viewer object
 * @param world_pos  world position to convert
 * @return LV_RESULT_OK if conversion valid, LV_RESULT_INVALID if no valid conversion
 * @see lv_gltf_world_to_screen
 */
inline Result gltf_world_to_screen(Obj obj, const lv_3dpoint_t world_pos, Point& screen_pos) noexcept { return static_cast<Result>(lv_gltf_world_to_screen(obj.raw(), world_pos, screen_pos.ptr())); }
#endif // LV_USE_GLTF

} // namespace lv
