#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

/**
 * Give a pointer to a driver from its letter
 * @param letter  the driver-identifier letter
 * @return pointer to a driver or NULL if not found
 * @see lv_fs_get_drv
 */
inline lv_fs_drv_t* fs_get_drv(char letter) noexcept { return lv_fs_get_drv(letter); }

/**
 * Remove a drive and call its remove function if available
 * @param letter  letter identifier of the drive to remove
 * @see lv_fs_remove_drive
 */
inline void fs_remove_drive(char letter) noexcept { lv_fs_remove_drive(letter); }

/**
 * Test if a drive is ready or not. If the `ready` function was not initialized `true` will be
 * returned.
 * @param letter  letter of the drive
 * @return true: drive is ready; false: drive is not ready
 * @see lv_fs_is_ready
 */
inline bool fs_is_ready(char letter) noexcept { return lv_fs_is_ready(letter); }

/**
 * Open a file
 * @param file_p  pointer to a lv_fs_file_t variable
 * @param path  path to the file beginning with the driver letter (e.g. S:/folder/file.txt)
 * @param mode  read: FS_MODE_RD, write: FS_MODE_WR, both: FS_MODE_RD | FS_MODE_WR
 * @return LV_FS_RES_OK or any error from lv_fs_res_t enum
 * @see lv_fs_open
 */
inline FsRes fs_open(lv_fs_file_t* file_p, const char* path, FsMode mode) noexcept { return static_cast<FsRes>(lv_fs_open(file_p, path, static_cast<lv_fs_mode_t>(mode))); }

/**
 * Create a special object from buffer/ memory address which looks like a file and can be passed
 * as path to `lv_fs_open` and other functions accepting a path.
 * For example
 * @param letter  the identifier letter of the driver. E.g. `LV_FS_MEMFS_LETTER`
 * @param buf  address of the memory buffer
 * @param size  size of the memory buffer in bytes
 * @param ext  the extension, e.g. "png", if NULL no extension will be added.
 * @see lv_fs_make_path_from_buffer
 */
inline void fs_make_path_from_buffer(lv_fs_path_ex_t* path, char letter, const void* buf, uint32_t size, const char* ext) noexcept { lv_fs_make_path_from_buffer(path, letter, buf, size, ext); }

/**
 * Get the buffer address and size from a path object
 * @param path  pointer to an initialized `lv_fs_path_ex` data
 * @param buffer  pointer to a `void *` variable to store the address
 * @param size  pointer to an `uint32_t` data to store the size
 * @return LV_RESULT_OK: buffer and size are set; LV_RESULT_INVALID: an error happened.
 * @see lv_fs_get_buffer_from_path
 */
inline Result fs_get_buffer_from_path(lv_fs_path_ex_t* path, void** buffer, uint32_t* size) noexcept { return static_cast<Result>(lv_fs_get_buffer_from_path(path, buffer, size)); }

/**
 * Close an already opened file
 * @param file_p  pointer to a lv_fs_file_t variable
 * @return LV_FS_RES_OK or any error from lv_fs_res_t enum
 * @see lv_fs_close
 */
inline FsRes fs_close(lv_fs_file_t* file_p) noexcept { return static_cast<FsRes>(lv_fs_close(file_p)); }

/**
 * Read from a file
 * @param file_p  pointer to a lv_fs_file_t variable
 * @param buf  pointer to a buffer where the read bytes are stored
 * @param btr  Bytes To Read
 * @param br  the number of real read bytes (Bytes Read). NULL if unused.
 * @return LV_FS_RES_OK or any error from lv_fs_res_t enum
 * @see lv_fs_read
 */
inline FsRes fs_read(lv_fs_file_t* file_p, void* buf, uint32_t btr, uint32_t* br) noexcept { return static_cast<FsRes>(lv_fs_read(file_p, buf, btr, br)); }

/**
 * Write into a file
 * @param file_p  pointer to a lv_fs_file_t variable
 * @param buf  pointer to a buffer with the bytes to write
 * @param btw  Bytes To Write
 * @param bw  the number of real written bytes (Bytes Written). NULL if unused.
 * @return LV_FS_RES_OK or any error from lv_fs_res_t enum
 * @see lv_fs_write
 */
inline FsRes fs_write(lv_fs_file_t* file_p, const void* buf, uint32_t btw, uint32_t* bw) noexcept { return static_cast<FsRes>(lv_fs_write(file_p, buf, btw, bw)); }

/**
 * Set the position of the 'cursor' (read write pointer) in a file
 * @param file_p  pointer to a lv_fs_file_t variable
 * @param pos  the new position expressed in bytes index (0: start of file)
 * @param whence  tells from where to set position. See lv_fs_whence_t
 * @return LV_FS_RES_OK or any error from lv_fs_res_t enum
 * @see lv_fs_seek
 */
inline FsRes fs_seek(lv_fs_file_t* file_p, uint32_t pos, FsWhence whence) noexcept { return static_cast<FsRes>(lv_fs_seek(file_p, pos, static_cast<lv_fs_whence_t>(whence))); }

/**
 * Give the position of the read write pointer
 * @param file_p  pointer to a lv_fs_file_t variable
 * @param pos  pointer to store the position of the read write pointer
 * @return LV_FS_RES_OK or any error from 'fs_res_t'
 * @see lv_fs_tell
 */
inline FsRes fs_tell(lv_fs_file_t* file_p, uint32_t* pos) noexcept { return static_cast<FsRes>(lv_fs_tell(file_p, pos)); }

/**
 * Get the size in bytes of an open file.
 * The file read/write position will not be affected.
 * @param file_p  pointer to a lv_fs_file_t variable
 * @param size_res  pointer to store the file size
 * @return LV_FS_RES_OK or any error from `lv_fs_res_t`
 * @see lv_fs_get_size
 */
inline FsRes fs_get_size(lv_fs_file_t* file_p, uint32_t* size_res) noexcept { return static_cast<FsRes>(lv_fs_get_size(file_p, size_res)); }

/**
 * Get the size in bytes of a file at the given path.
 * @param path  the path of the file
 * @param size_res  pointer to store the file size
 * @return LV_FS_RES_OK or any error from `lv_fs_res_t`
 * @see lv_fs_path_get_size
 */
inline FsRes fs_path_get_size(const char* path, uint32_t* size_res) noexcept { return static_cast<FsRes>(lv_fs_path_get_size(path, size_res)); }

/**
 * Read the contents of a file at the given path into a buffer.
 * @param buf  a buffer to read the contents of the file into
 * @param buf_size  the size of the buffer and the amount to read from the file
 * @param path  the path of the file
 * @return LV_FS_RES_OK on success, LV_FS_RES_UNKNOWN if fewer than `buf_size` bytes could be read from the file, or any error from `lv_fs_res_t`
 * @see lv_fs_load_to_buf
 */
inline FsRes fs_load_to_buf(void* buf, uint32_t buf_size, const char* path) noexcept { return static_cast<FsRes>(lv_fs_load_to_buf(buf, buf_size, path)); }

/**
 * Load a file into a memory buffer.
 * @param size  pointer to store the size of the loaded file
 * @return a pointer to the loaded file buffer, or NULL if an error occurred
 * @see lv_fs_load_with_alloc
 */
inline void* fs_load_with_alloc(const char* path, uint32_t* size) noexcept { return lv_fs_load_with_alloc(path, size); }

/**
 * Fill a buffer with the letters of existing drivers
 * @param buf  buffer to store the letters ('\0' added after the last letter)
 * @return the buffer
 * @see lv_fs_get_letters
 */
inline char* fs_get_letters(char* buf) noexcept { return lv_fs_get_letters(buf); }

/**
 * Return with the extension of the filename
 * @param fn  string with a filename
 * @return pointer to the beginning extension or empty string if no extension
 * @see lv_fs_get_ext
 */
inline const char* fs_get_ext(const char* fn) noexcept { return lv_fs_get_ext(fn); }

/**
 * Step up one level
 * @param path  pointer to a file name
 * @return the truncated file name
 * @see lv_fs_up
 */
inline char* fs_up(char* path) noexcept { return lv_fs_up(path); }

/**
 * Get the last element of a path (e.g. U:/folder/file -> file)
 * @param path  pointer to a file name
 * @return pointer to the beginning of the last element in the path
 * @see lv_fs_get_last
 */
inline const char* fs_get_last(const char* path) noexcept { return lv_fs_get_last(path); }

/**
 * Concatenate two path components and automatically add/remove a separator as needed.
 * buf, buf_sz, and the return value are analogous to lv_snprintf
 * @param buf  the buffer to place the result in
 * @param buf_sz  the size of buf. At most buf_sz - 1 characters will be written to buf, and a null terminator
 * @param base  the first path component
 * @param end  the second path component
 * @return the number of characters (not including the null terminator) that would be written to buf, even if buf_sz-1 was smaller
 * @see lv_fs_path_join
 */
inline int32_t fs_path_join(char* buf, size_t buf_sz, const char* base, const char* end) noexcept { return lv_fs_path_join(buf, buf_sz, base, end); }

inline FsRes FsDir::close() const noexcept { return static_cast<FsRes>(lv_fs_dir_close(p_)); }

inline FsRes FsDir::open(const char* path) const noexcept { return static_cast<FsRes>(lv_fs_dir_open(p_, path)); }

inline FsRes FsDir::read(char* fn, uint32_t fn_len) const noexcept { return static_cast<FsRes>(lv_fs_dir_read(p_, fn, fn_len)); }

} // namespace lv
