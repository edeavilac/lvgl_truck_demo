#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/libs/gltf/gltf_data/gltf_model_loader.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_GLTF
class GltfModel {
protected:
    lv_gltf_model_t* p_ = nullptr;

public:
    constexpr GltfModel() noexcept = default;  /**< the "no object" handle */
    constexpr explicit GltfModel(lv_gltf_model_t* p) noexcept : p_(p) {}

    constexpr lv_gltf_model_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(GltfModel a, GltfModel b) noexcept { return a.p_ == b.p_; }

    /**
     * Delete a glTF model
     * @see lv_gltf_model_delete
     */
    void delete_() const noexcept { lv_gltf_model_delete(p_); }
    /**
     * Get the current selected animation. To see if it's playing see `lv_gltf_model_is_animation_paused`
     * @see lv_gltf_model_get_animation
     */
    uint32_t get_animation() const noexcept { return lv_gltf_model_get_animation(p_); }
    /**
     * Get the number of animations in the glTF model
     * Animations define keyframe-based motion for nodes in the scene, including transformations
     * like translation, rotation, and scaling over time.
     * @return Number of animations in the model
     * @see lv_gltf_model_get_animation_count
     */
    uint32_t get_animation_count() const noexcept { return lv_gltf_model_get_animation_count(p_); }
    /**
     * Get the animation speed ratio
     * The actual ratio is the return value / LV_GLTF_ANIM_SPEED_NORMAL
     * @see lv_gltf_model_get_animation_speed
     */
    uint32_t get_animation_speed() const noexcept { return lv_gltf_model_get_animation_speed(p_); }
    /**
     * Get the number of cameras in the glTF model
     * Cameras define viewpoints within the 3D scene and can be either perspective or
     * orthographic. They are typically attached to nodes in the scene graph.
     * @return Number of cameras in the model
     * @see lv_gltf_model_get_camera_count
     */
    uint32_t get_camera_count() const noexcept { return lv_gltf_model_get_camera_count(p_); }
    /**
     * Get the number of images in the glTF model
     * Images in glTF are used as sources for textures and can be stored either as external files
     * or embedded as base64-encoded model within the glTF file.
     * @return Number of images in the model
     * @see lv_gltf_model_get_image_count
     */
    uint32_t get_image_count() const noexcept { return lv_gltf_model_get_image_count(p_); }
    /**
     * Get the number of materials in the glTF model
     * Materials define the visual appearance of mesh primitives, including properties like
     * base color, metallic/roughness values, normal maps, and other surface characteristics.
     * @return Number of materials in the model
     * @see lv_gltf_model_get_material_count
     */
    uint32_t get_material_count() const noexcept { return lv_gltf_model_get_material_count(p_); }
    /**
     * Get the number of meshes in the glTF model
     * Meshes contain the geometric model for 3D objects, including vertex positions, normals,
     * texture coordinates, and indices. Each mesh can have multiple primitives with different materials.
     * @return Number of meshes in the model
     * @see lv_gltf_model_get_mesh_count
     */
    uint32_t get_mesh_count() const noexcept { return lv_gltf_model_get_mesh_count(p_); }
    /**
     * Get the number of nodes in the glTF model
     * Nodes form the scene graph hierarchy and can contain transformations, meshes, cameras,
     * or other nodes as children. They define the spatial relationships between objects in the scene.
     * @return Number of nodes in the model
     * @see lv_gltf_model_get_node_count
     */
    uint32_t get_node_count() const noexcept;
    /**
     * Get the number of scenes in the glTF model
     * Scenes define the root nodes of the scene graph. A glTF file can contain multiple scenes,
     * though typically only one is designated as the default scene to be displayed.
     * @return Number of scenes in the model
     * @see lv_gltf_model_get_scene_count
     */
    uint32_t get_scene_count() const noexcept { return lv_gltf_model_get_scene_count(p_); }
    /**
     * Get the number of textures in the glTF model
     * Textures define how images are sampled and applied to materials. Each texture references
     * an image and may specify sampling parameters like filtering and wrapping modes.
     * @return Number of textures in the model
     * @see lv_gltf_model_get_texture_count
     */
    uint32_t get_texture_count() const noexcept { return lv_gltf_model_get_texture_count(p_); }
    /**
     * Check if an animation is currently being played
     * @see lv_gltf_model_is_animation_paused
     */
    bool is_animation_paused() const noexcept { return lv_gltf_model_is_animation_paused(p_); }
    /**
     * Pause the current animation
     * @see lv_gltf_model_pause_animation
     */
    void pause_animation() const noexcept { lv_gltf_model_pause_animation(p_); }
    /**
     * Select and start playing an animation
     * @param index  Animation number to start playing
     * @return LV_RESULT_OK if the animation was started else LV_RESULT_INVALID
     * @see lv_gltf_model_play_animation
     */
    Result play_animation(size_t index) const noexcept { return static_cast<Result>(lv_gltf_model_play_animation(p_, index)); }
    /**
     * Set the animation speed ratio
     * The actual ratio is the value parameter / LV_GLTF_ANIM_SPEED_NORMAL
     * Values greater than LV_GLTF_ANIM_SPEED_NORMAL will speed-up the animation
     * Values less than LV_GLTF_ANIM_SPEED_NORMAL will slow down the animation
     * @param value  speed-up ratio of the animation
     * @see lv_gltf_model_set_animation_speed
     */
    void set_animation_speed(uint32_t value) const noexcept { lv_gltf_model_set_animation_speed(p_, value); }
};
static_assert(sizeof(GltfModel) == sizeof(lv_gltf_model_t*));
static_assert(__is_trivially_copyable(GltfModel));

/**
 * Load a glTF model from a file
 * @param file_path  path to the glTF file to load
 * @param loader  pointer to the glTF model loader instance, or NULL to create a new one
 * @return pointer to the loaded glTF model, or NULL on failure
 * @see lv_gltf_data_load_from_file
 */
inline GltfModel gltf_data_load_from_file(const char* file_path, GltfModelLoader loader) noexcept { return GltfModel(lv_gltf_data_load_from_file(file_path, loader.raw())); }

/**
 * Load a glTF model from a byte array
 * @param data  pointer to the glTF data buffer
 * @param data_size  size of the data buffer in bytes
 * @param loader  pointer to the glTF model loader instance, or NULL to create a new one
 * @return pointer to the loaded glTF model, or NULL on failure
 * @see lv_gltf_data_load_from_bytes
 */
inline GltfModel gltf_data_load_from_bytes(const uint8_t* data, size_t data_size, GltfModelLoader loader) noexcept { return GltfModel(lv_gltf_data_load_from_bytes(data, data_size, loader.raw())); }
#endif // LV_USE_GLTF

} // namespace lv
