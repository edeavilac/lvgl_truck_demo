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
 * Initialize to use malloc/free/realloc etc
 * @see lv_mem_init
 */
inline void mem_init() noexcept { lv_mem_init(); }

/**
 * Drop all dynamically allocated memory and reset the memory pools' state
 * @see lv_mem_deinit
 */
inline void mem_deinit() noexcept { lv_mem_deinit(); }

/** @see lv_mem_add_pool */
inline lv_mem_pool_t mem_add_pool(void* mem, size_t bytes) noexcept { return lv_mem_add_pool(mem, bytes); }

/** @see lv_mem_remove_pool */
inline void mem_remove_pool(lv_mem_pool_t pool) noexcept { lv_mem_remove_pool(pool); }

/**
 * Allocate memory dynamically
 * @param size  requested size in bytes
 * @return pointer to allocated uninitialized memory, or NULL on failure
 * @see lv_malloc
 */
inline void* mem_malloc(size_t size) noexcept { return lv_malloc(size); }

/**
 * Allocate a block of zeroed memory dynamically
 * @param num  requested number of element to be allocated.
 * @param size  requested size of each element in bytes.
 * @return pointer to allocated zeroed memory, or NULL on failure
 * @see lv_calloc
 */
inline void* mem_calloc(size_t num, size_t size) noexcept { return lv_calloc(num, size); }

/**
 * Allocate zeroed memory dynamically
 * @param size  requested size in bytes
 * @return pointer to allocated zeroed memory, or NULL on failure
 * @see lv_zalloc
 */
inline void* mem_zalloc(size_t size) noexcept { return lv_zalloc(size); }

/**
 * Allocate zeroed memory dynamically
 * @param size  requested size in bytes
 * @return pointer to allocated zeroed memory, or NULL on failure
 * @see lv_malloc_zeroed
 */
inline void* mem_malloc_zeroed(size_t size) noexcept { return lv_malloc_zeroed(size); }

/**
 * Free an allocated data
 * @param data  pointer to an allocated memory
 * @see lv_free
 */
inline void mem_free(void* data) noexcept { lv_free(data); }

/**
 * Reallocate a memory with a new size. The old content will be kept.
 * @param data_p  pointer to an allocated memory. Its content will be copied to the new memory block and freed
 * @param new_size  the desired new size in byte
 * @return pointer to the new memory, NULL on failure
 * @see lv_realloc
 */
inline void* mem_realloc(void* data_p, size_t new_size) noexcept { return lv_realloc(data_p, new_size); }

/**
 * Reallocate a memory with a new size. The old content will be kept.
 * In case of failure, the old pointer is free'd.
 * @param data_p  pointer to an allocated memory. Its content will be copied to the new memory block and freed
 * @param new_size  the desired new size in byte
 * @return pointer to the new memory, NULL on failure
 * @see lv_reallocf
 */
inline void* mem_reallocf(void* data_p, size_t new_size) noexcept { return lv_reallocf(data_p, new_size); }

/**
 * Used internally to execute a plain `malloc` operation
 * @param size  size in bytes to `malloc`
 * @see lv_malloc_core
 */
inline void* mem_malloc_core(size_t size) noexcept { return lv_malloc_core(size); }

/**
 * Used internally to execute a plain `free` operation
 * @param p  memory address to free
 * @see lv_free_core
 */
inline void mem_free_core(void* p) noexcept { lv_free_core(p); }

/**
 * Used internally to execute a plain realloc operation
 * @param p  memory address to realloc
 * @param new_size  size in bytes to realloc
 * @see lv_realloc_core
 */
inline void* mem_realloc_core(void* p, size_t new_size) noexcept { return lv_realloc_core(p, new_size); }

/** @see lv_mem_test_core */
inline Result mem_test_core() noexcept { return static_cast<Result>(lv_mem_test_core()); }

/**
 * Tests the memory allocation system by allocating and freeing a block of memory.
 * @return LV_RESULT_OK if the memory allocation system is working properly, or LV_RESULT_INVALID if there is an error.
 * @see lv_mem_test
 */
inline Result mem_test() noexcept { return static_cast<Result>(lv_mem_test()); }

/**
 * Give information about the work memory of dynamic allocation
 * @param mon_p  pointer to a lv_mem_monitor_t variable, the result of the analysis will be stored here
 * @see lv_mem_monitor
 */
inline void mem_monitor(MemMonitor mon_p) noexcept { lv_mem_monitor(mon_p.raw()); }

inline void MemMonitor::core() const noexcept { lv_mem_monitor_core(p_); }

} // namespace lv
