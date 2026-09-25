#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_GLTF
class GltfModelLoader {
protected:
    lv_gltf_model_loader_t* p_ = nullptr;

public:
    constexpr GltfModelLoader() noexcept = default;  /**< the "no object" handle */
    constexpr explicit GltfModelLoader(lv_gltf_model_loader_t* p) noexcept : p_(p) {}

    constexpr lv_gltf_model_loader_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(GltfModelLoader a, GltfModelLoader b) noexcept { return a.p_ == b.p_; }

    /**
     * Create a new glTF model loader instance
     * @return pointer to the newly created glTF model loader instance
     * @see lv_gltf_model_loader_create
     */
    static GltfModelLoader create() noexcept { return GltfModelLoader(lv_gltf_model_loader_create()); }
    /**
     * Delete a glTF model loader instance and free its resources
     * @see lv_gltf_model_loader_delete
     */
    void delete_() const noexcept { lv_gltf_model_loader_delete(p_); }
    /**
     * Retrieve a texture ID by its hash from the loader
     * @param texture_hash  hash value of the texture to retrieve
     * @return the texture ID associated with the hash, or 0 if not found
     * @see lv_gltf_model_loader_get_texture
     */
    uint32_t get_texture(uint32_t texture_hash) const noexcept { return lv_gltf_model_loader_get_texture(p_, texture_hash); }
    /**
     * Store a texture ID associated with a texture hash in the loader
     * @param texture_hash  hash value identifying the texture
     * @param texture_id  the texture ID to associate with the hash
     * @see lv_gltf_model_loader_store_texture
     */
    void store_texture(uint32_t texture_hash, uint32_t texture_id) const noexcept { lv_gltf_model_loader_store_texture(p_, texture_hash, texture_id); }
};
static_assert(sizeof(GltfModelLoader) == sizeof(lv_gltf_model_loader_t*));
static_assert(__is_trivially_copyable(GltfModelLoader));
#endif // LV_USE_GLTF

} // namespace lv
