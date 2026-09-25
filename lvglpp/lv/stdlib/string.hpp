#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

/**
 * Copies a block of memory from a source address to a destination address.
 * @param dst  Pointer to the destination array where the content is to be copied.
 * @param src  Pointer to the source of data to be copied.
 * @param len  Number of bytes to copy.
 * @return Pointer to the destination array.
 * @see lv_memcpy
 */
inline void* string_memcpy(void* dst, const void* src, size_t len) noexcept { return lv_memcpy(dst, src, len); }

/**
 * Fills a block of memory with a specified value.
 * @param dst  Pointer to the destination array to fill with the specified value.
 * @param v  Value to be set. The value is passed as an int, but the function fills the block of memory using the unsigned char conversion of this value.
 * @param len  Number of bytes to be set to the value.
 * @see lv_memset
 */
inline void string_memset(void* dst, uint8_t v, size_t len) noexcept { lv_memset(dst, v, len); }

/**
 * Move a block of memory from source to destination
 * @param dst  Pointer to the destination array where the content is to be copied.
 * @param src  Pointer to the source of data to be copied.
 * @param len  Number of bytes to copy
 * @return Pointer to the destination array.
 * @see lv_memmove
 */
inline void* string_memmove(void* dst, const void* src, size_t len) noexcept { return lv_memmove(dst, src, len); }

/**
 * This function will compare two memory blocks
 * @param p1  Pointer to the first memory block
 * @param p2  Pointer to the second memory block
 * @param len  Number of bytes to compare
 * @return The difference between the value of the first unmatching byte.
 * @see lv_memcmp
 */
inline int32_t string_memcmp(const void* p1, const void* p2, size_t len) noexcept { return lv_memcmp(p1, p2, len); }

/**
 * Same as `memset(dst, 0x00, len)`.
 * @param dst  pointer to the destination buffer
 * @param len  number of byte to set
 * @see lv_memzero
 */
inline void string_memzero(void* dst, size_t len) noexcept { lv_memzero(dst, len); }

/**
 * Computes the length of the string str up to (but not including) the terminating null character.
 * @param str  Pointer to the null-terminated byte string to be examined.
 * @return The length of the string in bytes.
 * @see lv_strlen
 */
inline uint32_t string_strlen(const char* str) noexcept { return lv_strlen(str); }

/**
 * Computes the length of the string str up to (but not including) the terminating null character,
 * or the given maximum length.
 * @param str  Pointer to byte string that is null-terminated or at least max_len bytes long.
 * @param max_len  Maximum number of characters to examine.
 * @return The length of the string in bytes.
 * @see lv_strnlen
 */
inline uint32_t string_strnlen(const char* str, size_t max_len) noexcept { return lv_strnlen(str, max_len); }

/**
 * Copies up to dst_size-1 (non-null) characters from src to dst. A null terminator is always added.
 * @param dst  Pointer to the destination array where the content is to be copied.
 * @param src  Pointer to the source of data to be copied.
 * @param dst_size  Maximum number of characters to be copied to dst, including the null character.
 * @return The length of src. The return value is equivalent to the value returned by lv_strlen(src)
 * @see lv_strlcpy
 */
inline uint32_t string_strlcpy(char* dst, const char* src, size_t dst_size) noexcept { return lv_strlcpy(dst, src, dst_size); }

/**
 * Copies up to dest_size characters from the string pointed to by src to the character array pointed to by dst
 * and fills the remaining length with null bytes.
 * @param dst  Pointer to the destination array where the content is to be copied.
 * @param src  Pointer to the source of data to be copied.
 * @param dest_size  Maximum number of characters to be copied to dst.
 * @return A pointer to the destination array, which is dst.
 * @see lv_strncpy
 */
inline char* string_strncpy(char* dst, const char* src, size_t dest_size) noexcept { return lv_strncpy(dst, src, dest_size); }

/**
 * Copies the string pointed to by src, including the terminating null character,
 * to the character array pointed to by dst.
 * @param dst  Pointer to the destination array where the content is to be copied.
 * @param src  Pointer to the source of data to be copied.
 * @return A pointer to the destination array, which is dst.
 * @see lv_strcpy
 */
inline char* string_strcpy(char* dst, const char* src) noexcept { return lv_strcpy(dst, src); }

/**
 * This function will compare two strings without specified length.
 * @param s1  pointer to the first string
 * @param s2  pointer to the second string
 * @return the difference between the value of the first unmatching character.
 * @see lv_strcmp
 */
inline int32_t string_strcmp(const char* s1, const char* s2) noexcept { return lv_strcmp(s1, s2); }

/**
 * This function will compare two strings up to the given length.
 * @param s1  pointer to the first string
 * @param s2  pointer to the second string
 * @param len  the maximum amount of characters to compare
 * @return the difference between the value of the first unmatching character.
 * @see lv_strncmp
 */
inline int32_t string_strncmp(const char* s1, const char* s2, size_t len) noexcept { return lv_strncmp(s1, s2, len); }

/**
 * Returns true if the two strings are equal.
 * Just a wrapper around strcmp for convenience.
 * @param s1  pointer to the first string
 * @param s2  pointer to the second string
 * @return true: the strings are equal; false: otherwise
 * @see lv_streq
 */
inline bool string_streq(const char* s1, const char* s2) noexcept { return lv_streq(s1, s2); }

/**
 * Duplicate a string by allocating a new one and copying the content.
 * @param src  Pointer to the source of data to be copied.
 * @return A pointer to the new allocated string. NULL if failed.
 * @see lv_strdup
 */
inline char* string_strdup(const char* src) noexcept { return lv_strdup(src); }

/**
 * Duplicate a string by allocating a new one and copying the content
 * up to the end or the specified maximum length, whichever comes first.
 * @param src  Pointer to the source of data to be copied.
 * @param max_len  Maximum number of characters to be copied.
 * @return Pointer to a newly allocated null-terminated string. NULL if failed.
 * @see lv_strndup
 */
inline char* string_strndup(const char* src, size_t max_len) noexcept { return lv_strndup(src, max_len); }

/**
 * Copies the string pointed to by src, including the terminating null character,
 * to the end of the string pointed to by dst.
 * @param dst  Pointer to the destination string where the content is to be appended.
 * @param src  Pointer to the source of data to be copied.
 * @return A pointer to the destination string, which is dst.
 * @see lv_strcat
 */
inline char* string_strcat(char* dst, const char* src) noexcept { return lv_strcat(dst, src); }

/**
 * Copies up to src_len characters from the string pointed to by src
 * to the end of the string pointed to by dst.
 * A terminating null character is appended to dst even if no null character
 * was encountered in src after src_len characters were copied.
 * @param dst  Pointer to the destination string where the content is to be appended.
 * @param src  Pointer to the source of data to be copied.
 * @param src_len  Maximum number of characters from src to be copied to the end of dst.
 * @return A pointer to the destination string, which is dst.
 * @see lv_strncat
 */
inline char* string_strncat(char* dst, const char* src, size_t src_len) noexcept { return lv_strncat(dst, src, src_len); }

/**
 * Searches for the first occurrence of character c in the string str.
 * @param str  Pointer to the null-terminated byte string to be searched.
 * @param c  The character to be searched for.
 * @return A pointer to the first occurrence of character c in the string str, or a null pointer if c is not found.
 * @see lv_strchr
 */
inline char* string_strchr(const char* str, int32_t c) noexcept { return lv_strchr(str, c); }

} // namespace lv
