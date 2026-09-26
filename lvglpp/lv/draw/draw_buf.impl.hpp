#pragma once
// Bodies of draw/draw_buf.hpp, separated because its file cycle needs every type
// complete. Same mechanism as D-C7, applied where the graph asks for it.
// Included by the umbrella and never by a header: it is NOT a translation
// unit and every definition in it is `inline`. The stem says so, not the
// extension, so a glob written for *.hpp still installs it.

#include "lv/lvgl.hpp"

namespace lv {

inline void DrawBufHandlers::init(lv_draw_buf_malloc_cb_t buf_malloc_cb, lv_draw_buf_free_cb_t buf_free_cb, lv_draw_buf_copy_cb_t buf_copy_cb, lv_draw_buf_align_cb_t align_pointer_cb, lv_draw_buf_cache_operation_cb_t invalidate_cache_cb, lv_draw_buf_cache_operation_cb_t flush_cache_cb, lv_draw_buf_width_to_stride_cb_t width_to_stride_cb) const noexcept { lv_draw_buf_handlers_init(p_, buf_malloc_cb, buf_free_cb, buf_copy_cb, align_pointer_cb, invalidate_cache_cb, flush_cache_cb, width_to_stride_cb); }

inline Result DrawBuf::adjust_stride(uint32_t stride) const noexcept { return static_cast<Result>(lv_draw_buf_adjust_stride(p_, stride)); }

inline void DrawBuf::clear(const Area& a) const noexcept { lv_draw_buf_clear(p_, a.ptr()); }

inline void DrawBuf::clear_flag(Image::Flags flag) const noexcept { lv_draw_buf_clear_flag(p_, static_cast<lv_image_flags_t>(flag)); }

inline void DrawBuf::copy(const Area& dest_area, DrawBuf src, const Area& src_area) const noexcept { lv_draw_buf_copy(p_, dest_area.ptr(), src.raw(), src_area.ptr()); }

inline DrawBuf DrawBuf::create(uint32_t w, uint32_t h, ColorFormat cf, uint32_t stride) noexcept { return DrawBuf(lv_draw_buf_create(w, h, static_cast<lv_color_format_t>(cf), stride)); }

inline void DrawBuf::destroy() const noexcept { lv_draw_buf_destroy(p_); }

inline DrawBuf DrawBuf::dup() const noexcept { return DrawBuf(lv_draw_buf_dup(p_)); }

inline void DrawBuf::flush_cache(const Area& area) const noexcept { lv_draw_buf_flush_cache(p_, area.ptr()); }

inline Result DrawBuf::from_image(const lv_image_dsc_t* img) const noexcept { return static_cast<Result>(lv_draw_buf_from_image(p_, img)); }

inline void* DrawBuf::goto_xy(uint32_t x, uint32_t y) const noexcept { return lv_draw_buf_goto_xy(p_, x, y); }

inline bool DrawBuf::has_flag(Image::Flags flag) const noexcept { return lv_draw_buf_has_flag(p_, static_cast<lv_image_flags_t>(flag)); }

inline Result DrawBuf::init(uint32_t w, uint32_t h, ColorFormat cf, uint32_t stride, void* data, uint32_t data_size) const noexcept { return static_cast<Result>(lv_draw_buf_init(p_, w, h, static_cast<lv_color_format_t>(cf), stride, data, data_size)); }

inline void DrawBuf::invalidate_cache(const Area& area) const noexcept { lv_draw_buf_invalidate_cache(p_, area.ptr()); }

inline Result DrawBuf::premultiply() const noexcept { return static_cast<Result>(lv_draw_buf_premultiply(p_)); }

inline DrawBuf DrawBuf::reshape(ColorFormat cf, uint32_t w, uint32_t h, uint32_t stride) const noexcept { return DrawBuf(lv_draw_buf_reshape(p_, static_cast<lv_color_format_t>(cf), w, h, stride)); }

inline void DrawBuf::set_flag(Image::Flags flag) const noexcept { lv_draw_buf_set_flag(p_, static_cast<lv_image_flags_t>(flag)); }

inline void DrawBuf::set_palette(uint8_t index, lv_color32_t color) const noexcept { lv_draw_buf_set_palette(p_, index, color); }

inline void DrawBuf::to_image(lv_image_dsc_t* img) const noexcept { lv_draw_buf_to_image(p_, img); }

inline void draw_buf_init_with_default_handlers(DrawBufHandlers handlers) noexcept { lv_draw_buf_init_with_default_handlers(handlers.raw()); }

inline DrawBufHandlers draw_buf_get_handlers() noexcept { return DrawBufHandlers(lv_draw_buf_get_handlers()); }

inline DrawBufHandlers draw_buf_get_font_handlers() noexcept { return DrawBufHandlers(lv_draw_buf_get_font_handlers()); }

inline DrawBufHandlers draw_buf_get_image_handlers() noexcept { return DrawBufHandlers(lv_draw_buf_get_image_handlers()); }

inline void* draw_buf_align(void* buf, ColorFormat color_format) noexcept { return lv_draw_buf_align(buf, static_cast<lv_color_format_t>(color_format)); }

inline void* draw_buf_align_ex(DrawBufHandlers handlers, void* buf, ColorFormat color_format) noexcept { return lv_draw_buf_align_ex(handlers.raw(), buf, static_cast<lv_color_format_t>(color_format)); }

inline uint32_t draw_buf_width_to_stride(uint32_t w, ColorFormat color_format) noexcept { return lv_draw_buf_width_to_stride(w, static_cast<lv_color_format_t>(color_format)); }

inline uint32_t draw_buf_width_to_stride_ex(DrawBufHandlers handlers, uint32_t w, ColorFormat color_format) noexcept { return lv_draw_buf_width_to_stride_ex(handlers.raw(), w, static_cast<lv_color_format_t>(color_format)); }

inline DrawBuf draw_buf_create_ex(DrawBufHandlers handlers, uint32_t w, uint32_t h, ColorFormat cf, uint32_t stride) noexcept { return DrawBuf(lv_draw_buf_create_ex(handlers.raw(), w, h, static_cast<lv_color_format_t>(cf), stride)); }

inline DrawBuf draw_buf_dup_ex(DrawBufHandlers handlers, DrawBuf draw_buf) noexcept { return DrawBuf(lv_draw_buf_dup_ex(handlers.raw(), draw_buf.raw())); }

inline void image_buf_set_palette(lv_image_dsc_t* dsc, uint8_t id, lv_color32_t c) noexcept { lv_image_buf_set_palette(dsc, id, c); }

inline void image_buf_free(lv_image_dsc_t* dsc) noexcept { lv_image_buf_free(dsc); }

} // namespace lv
