#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_FS_FATFS
/** @see lv_fs_fatfs_init */
inline void fs_fatfs_init() noexcept { lv_fs_fatfs_init(); }
#endif // LV_USE_FS_FATFS

#if LV_USE_FS_STDIO
/** @see lv_fs_stdio_init */
inline void fs_stdio_init() noexcept { lv_fs_stdio_init(); }
#endif // LV_USE_FS_STDIO

#if LV_USE_FS_POSIX
/** @see lv_fs_posix_init */
inline void fs_posix_init() noexcept { lv_fs_posix_init(); }
#endif // LV_USE_FS_POSIX

#if LV_USE_FS_WIN32
/** @see lv_fs_win32_init */
inline void fs_win32_init() noexcept { lv_fs_win32_init(); }
#endif // LV_USE_FS_WIN32

#if LV_USE_FS_MEMFS
/** @see lv_fs_memfs_init */
inline void fs_memfs_init() noexcept { lv_fs_memfs_init(); }
#endif // LV_USE_FS_MEMFS

#if LV_USE_FS_LITTLEFS
/**
 * Set the default LittleFS handler to be used by LVGL
 * @param lfs  pointer to an initialized LittleFS filesystem structure
 * @see lv_littlefs_set_handler
 */
inline void fsdrv_littlefs_set_handler(struct lfs* lfs) noexcept { lv_littlefs_set_handler(lfs); }

/**
 * Initialize LittleFS file system driver
 * @see lv_fs_littlefs_init
 */
inline void fs_littlefs_init() noexcept { lv_fs_littlefs_init(); }

/** @see lv_fs_littlefs_register_drive */
inline Type fs_littlefs_register_drive(Type* lfs, char letter) noexcept { return lv_fs_littlefs_register_drive(lfs, letter); }
#endif // LV_USE_FS_LITTLEFS

#if LV_USE_FS_ARDUINO_ESP_LITTLEFS
/**
 * Register a LittleFS drive with LVGL
 * @see lv_fs_arduino_esp_littlefs_init
 */
inline void fs_arduino_esp_littlefs_init() noexcept { lv_fs_arduino_esp_littlefs_init(); }
#endif // LV_USE_FS_ARDUINO_ESP_LITTLEFS

#if LV_USE_FS_ARDUINO_SD
/** @see lv_fs_arduino_sd_init */
inline void fs_arduino_sd_init() noexcept { lv_fs_arduino_sd_init(); }
#endif // LV_USE_FS_ARDUINO_SD

#if LV_USE_FS_UEFI
/** @see lv_fs_uefi_init */
inline void fs_uefi_init() noexcept { lv_fs_uefi_init(); }
#endif // LV_USE_FS_UEFI

#if LV_USE_FS_FROGFS
/** @see lv_fs_frogfs_init */
inline void fs_frogfs_init() noexcept { lv_fs_frogfs_init(); }

/** @see lv_fs_frogfs_deinit */
inline void fs_frogfs_deinit() noexcept { lv_fs_frogfs_deinit(); }

/**
 * Mount a frogfs blob at the path prefix. If there is a file "foo.txt"
 * in the blob and the blob is registered with `path_prefix` as "my_blob",
 * it can be opened later at path "my_blob/foo.txt".
 * @param blob  a frogfs blob/image from mkfrogfs.py
 * @param path_prefix  a prefix that will be used to refer to this blob when accessing it.
 * @return LV_RESULT_OK or LV_RESULT_INVALID if there was an issue with the blob
 * @see lv_fs_frogfs_register_blob
 */
inline Result fs_frogfs_register_blob(const void* blob, const char* path_prefix) noexcept { return static_cast<Result>(lv_fs_frogfs_register_blob(blob, path_prefix)); }

/**
 * Unmount a frogfs blob that was previously mounted by `lv_fs_frogfs_register_blob`.
 * All files and dirs should be closed before calling this.
 * @param path_prefix  the path prefix that the blob was registered with
 * @see lv_fs_frogfs_unregister_blob
 */
inline void fs_frogfs_unregister_blob(const char* path_prefix) noexcept { lv_fs_frogfs_unregister_blob(path_prefix); }
#endif // LV_USE_FS_FROGFS

} // namespace lv
