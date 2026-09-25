#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/libs/gltf/gltf_data/gltf_model.hpp"
#include "lv/misc/event.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_GLTF
class GltfModelNode {
protected:
    lv_gltf_model_node_t* p_ = nullptr;

public:
    constexpr GltfModelNode() noexcept = default;  /**< the "no object" handle */
    constexpr explicit GltfModelNode(lv_gltf_model_node_t* p) noexcept : p_(p) {}

    constexpr lv_gltf_model_node_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(GltfModelNode a, GltfModelNode b) noexcept { return a.p_ == b.p_; }

    /**
     * Add an event callback to a glTF model node
     * @param cb  The event callback function to add. Use lv_event_get_param() to retrieve lv_gltf_node_data_t with the node's data.
     * @param filter_list  Event code filter for the callback
     * @param user_data  User data to pass to the callback
     * @return Pointer to the event descriptor, or NULL if allocation failed
     * @see lv_gltf_model_node_add_event_cb
     */
    EventDsc add_event_cb(lv_event_cb_t cb, EventCode filter_list, void* user_data) const noexcept { return EventDsc(lv_gltf_model_node_add_event_cb(p_, cb, static_cast<lv_event_code_t>(filter_list), user_data)); }
    /**
     * Add an event callback to a glTF model node with world position computation enabled. Use this only when world position is needed, as computing it is an expensive operation.
     * @param cb  The event callback function to add. Use lv_event_get_param() to retrieve lv_gltf_node_data_t with the node's data.
     * @param filter_list  Event code filter for the callback
     * @param user_data  User data to pass to the callback
     * @return Pointer to the event descriptor, or NULL if allocation failed
     * @see lv_gltf_model_node_add_event_cb_with_world_position
     */
    EventDsc add_event_cb_with_world_position(lv_event_cb_t cb, EventCode filter_list, void* user_data) const noexcept { return EventDsc(lv_gltf_model_node_add_event_cb_with_world_position(p_, cb, static_cast<lv_event_code_t>(filter_list), user_data)); }
    /**
     * Get the IP (internal pointer/identifier) of a glTF model node
     * @return The IP string of the node, or NULL if node is invalid
     * @see lv_gltf_model_node_get_ip
     */
    const char* get_ip() const noexcept { return lv_gltf_model_node_get_ip(p_); }
    /**
     * Get the path of a glTF model node
     * @return The path string of the node, or NULL if node is invalid
     * @see lv_gltf_model_node_get_path
     */
    const char* get_path() const noexcept { return lv_gltf_model_node_get_path(p_); }
    /**
     * Set the X position of a glTF model node. The operation is queued and applied on the next rendering phase.
     * @param x  The X position value
     * @return LV_RESULT_OK if the operation is queued successfully, LV_RESULT_INVALID if node is null or no more memory to queue the operation
     * @see lv_gltf_model_node_set_position_x
     */
    Result set_position_x(float x) const noexcept { return static_cast<Result>(lv_gltf_model_node_set_position_x(p_, x)); }
    /**
     * Set the Y position of a glTF model node. The operation is queued and applied on the next rendering phase.
     * @param y  The Y position value
     * @return LV_RESULT_OK if the operation is queued successfully, LV_RESULT_INVALID if node is null or no more memory to queue the operation
     * @see lv_gltf_model_node_set_position_y
     */
    Result set_position_y(float y) const noexcept { return static_cast<Result>(lv_gltf_model_node_set_position_y(p_, y)); }
    /**
     * Set the Z position of a glTF model node. The operation is queued and applied on the next rendering phase.
     * @param z  The Z position value
     * @return LV_RESULT_OK if the operation is queued successfully, LV_RESULT_INVALID if node is null or no more memory to queue the operation
     * @see lv_gltf_model_node_set_position_z
     */
    Result set_position_z(float z) const noexcept { return static_cast<Result>(lv_gltf_model_node_set_position_z(p_, z)); }
    /**
     * Set the X component of a glTF model node's rotation quaternion. The operation is queued and applied on the next rendering phase.
     * @param x  The X rotation component value
     * @return LV_RESULT_OK if the operation is queued successfully, LV_RESULT_INVALID if node is null or no more memory to queue the operation
     * @see lv_gltf_model_node_set_rotation_x
     */
    Result set_rotation_x(float x) const noexcept { return static_cast<Result>(lv_gltf_model_node_set_rotation_x(p_, x)); }
    /**
     * Set the Y component of a glTF model node's rotation quaternion. The operation is queued and applied on the next rendering phase.
     * @param y  The Y rotation component value
     * @return LV_RESULT_OK if the operation is queued successfully, LV_RESULT_INVALID if node is null or no more memory to queue the operation
     * @see lv_gltf_model_node_set_rotation_y
     */
    Result set_rotation_y(float y) const noexcept { return static_cast<Result>(lv_gltf_model_node_set_rotation_y(p_, y)); }
    /**
     * Set the Z component of a glTF model node's rotation quaternion. The operation is queued and applied on the next rendering phase.
     * @param z  The Z rotation component value
     * @return LV_RESULT_OK if the operation is queued successfully, LV_RESULT_INVALID if node is null or no more memory to queue the operation
     * @see lv_gltf_model_node_set_rotation_z
     */
    Result set_rotation_z(float z) const noexcept { return static_cast<Result>(lv_gltf_model_node_set_rotation_z(p_, z)); }
    /**
     * Set the X scale of a glTF model node. The operation is queued and applied on the next rendering phase.
     * @param x  The X scale value
     * @return LV_RESULT_OK if the operation is queued successfully, LV_RESULT_INVALID if node is null or no more memory to queue the operation
     * @see lv_gltf_model_node_set_scale_x
     */
    Result set_scale_x(float x) const noexcept { return static_cast<Result>(lv_gltf_model_node_set_scale_x(p_, x)); }
    /**
     * Set the Y scale of a glTF model node. The operation is queued and applied on the next rendering phase.
     * @param y  The Y scale value
     * @return LV_RESULT_OK if the operation is queued successfully, LV_RESULT_INVALID if node is null or no more memory to queue the operation
     * @see lv_gltf_model_node_set_scale_y
     */
    Result set_scale_y(float y) const noexcept { return static_cast<Result>(lv_gltf_model_node_set_scale_y(p_, y)); }
    /**
     * Set the Z scale of a glTF model node. The operation is queued and applied on the next rendering phase.
     * @param z  The Z scale value
     * @return LV_RESULT_OK if the operation is queued successfully, LV_RESULT_INVALID if node is null or no more memory to queue the operation
     * @see lv_gltf_model_node_set_scale_z
     */
    Result set_scale_z(float z) const noexcept { return static_cast<Result>(lv_gltf_model_node_set_scale_z(p_, z)); }
};
static_assert(sizeof(GltfModelNode) == sizeof(lv_gltf_model_node_t*));
static_assert(__is_trivially_copyable(GltfModelNode));

/**
 * Get a glTF model node by its index
 * @param data  Pointer to the glTF model structure
 * @param index  The index of the node to retrieve
 * @return Pointer to the glTF model node, or NULL if not found
 * @see lv_gltf_model_node_get_by_index
 */
inline GltfModelNode gltf_model_node_get_by_index(GltfModel data, size_t index) noexcept { return GltfModelNode(lv_gltf_model_node_get_by_index(data.raw(), index)); }

/**
 * Get a glTF model node by its numeric path
 * @param data  Pointer to the glTF model structure
 * @param num_path  The numeric path string of the node to retrieve (eg. ".0")
 * @return Pointer to the glTF model node, or NULL if not found
 * @see lv_gltf_model_node_get_by_numeric_path
 */
inline GltfModelNode gltf_model_node_get_by_numeric_path(GltfModel data, const char* num_path) noexcept { return GltfModelNode(lv_gltf_model_node_get_by_numeric_path(data.raw(), num_path)); }

/**
 * Get a glTF model node by its path
 * @param data  Pointer to the glTF model structure
 * @param path  The path string of the node to retrieve
 * @return Pointer to the glTF model node, or NULL if not found
 * @see lv_gltf_model_node_get_by_path
 */
inline GltfModelNode gltf_model_node_get_by_path(GltfModel data, const char* path) noexcept { return GltfModelNode(lv_gltf_model_node_get_by_path(data.raw(), path)); }

/**
 * Get the local position of a glTF model node. Must be called from within an LV_EVENT_VALUE_CHANGED callback.
 * Local position is relative to the node's parent.
 * This function is only valid when called from an event callback registered.
 * See `lv_gltf_model_node_add_event_cb()` and `lv_gltf_model_node_add_event_cb_with_world_position()`
 * @param e  Pointer to the event structure from the callback
 * @param result  Pointer to lv_3dpoint_t structure to store the position (x, y, z)
 * @return LV_RESULT_OK if successful, LV_RESULT_INVALID if called outside event callback or if parameters are null
 * @see lv_gltf_model_node_get_local_position
 */
inline Result gltf_model_node_get_local_position(Event& e, lv_3dpoint_t* result) noexcept { return static_cast<Result>(lv_gltf_model_node_get_local_position(e.raw(), result)); }

/**
 * Get the world position of a glTF model node. Must be called from within an LV_EVENT_VALUE_CHANGED callback
 * registered with world position enabled.
 * World position is the absolute position in global scene coordinates.
 * This function requires the event callback to be registered with lv_gltf_model_node_add_event_cb_with_world_position()
 * as it involves complex matrix calculations that are computed on-demand.
 * @param e  Pointer to the event structure from the callback
 * @param result  Pointer to lv_3dpoint_t structure to store the position (x, y, z)
 * @return LV_RESULT_OK if successful, LV_RESULT_INVALID if called outside event callback, world position not enabled, or if parameters are null
 * @see lv_gltf_model_node_get_world_position
 */
inline Result gltf_model_node_get_world_position(Event& e, lv_3dpoint_t* result) noexcept { return static_cast<Result>(lv_gltf_model_node_get_world_position(e.raw(), result)); }

/**
 * Get the scale of a glTF model node. Must be called from within an LV_EVENT_VALUE_CHANGED callback.
 * Returns the scale factors for each axis.
 * This function is only valid when called from an event callback registered.
 * See `lv_gltf_model_node_add_event_cb()` and `lv_gltf_model_node_add_event_cb_with_world_position()`
 * @param e  Pointer to the event structure from the callback
 * @param result  Pointer to lv_3dpoint_t structure to store the scale (x, y, z)
 * @return LV_RESULT_OK if successful, LV_RESULT_INVALID if called outside event callback or if parameters are null
 * @see lv_gltf_model_node_get_scale
 */
inline Result gltf_model_node_get_scale(Event& e, lv_3dpoint_t* result) noexcept { return static_cast<Result>(lv_gltf_model_node_get_scale(e.raw(), result)); }

/**
 * Get the Euler rotation of a glTF model node. Must be called from within an LV_EVENT_VALUE_CHANGED callback.
 * Returns rotation as Euler angles in radians (x, y, z).
 * This function is only valid when called from an event callback registered.
 * See `lv_gltf_model_node_add_event_cb()` and `lv_gltf_model_node_add_event_cb_with_world_position()`
 * @param e  Pointer to the event structure from the callback
 * @param result  Pointer to lv_3dpoint_t structure to store the rotation in radians (x, y, z)
 * @return LV_RESULT_OK if successful, LV_RESULT_INVALID if called outside event callback or if parameters are null
 * @see lv_gltf_model_node_get_euler_rotation
 */
inline Result gltf_model_node_get_euler_rotation(Event& e, lv_3dpoint_t* result) noexcept { return static_cast<Result>(lv_gltf_model_node_get_euler_rotation(e.raw(), result)); }
#endif // LV_USE_GLTF

#if LV_USE_GLTF
inline uint32_t GltfModel::get_node_count() const noexcept { return lv_gltf_model_get_node_count(p_); }
#endif // LV_USE_GLTF

} // namespace lv
