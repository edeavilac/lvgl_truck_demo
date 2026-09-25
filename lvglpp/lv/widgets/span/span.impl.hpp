#pragma once
// Bodies of widgets/span/span.hpp, separated because its file cycle needs every type
// complete. Same mechanism as D-C7, applied where the graph asks for it.
// Included by the umbrella and never by a header: it is NOT a translation
// unit and every definition in it is `inline`. The stem says so, not the
// extension, so a glob written for *.hpp still installs it.

#include "lv/lvgl.hpp"

namespace lv {

#if LV_USE_SPAN != 0
inline Span Spangroup::add_span() const noexcept { return Span(lv_spangroup_add_span(p_)); }
#endif // LV_USE_SPAN != 0

#if (LV_USE_SPAN != 0) && (LV_USE_OBSERVER)
inline Observer Spangroup::bind_span_text(Span span, Subject& subject, const char* fmt) const noexcept { return Observer(lv_spangroup_bind_span_text(p_, span.raw(), subject.raw(), fmt)); }
#endif // (LV_USE_SPAN != 0) && (LV_USE_OBSERVER)

#if LV_USE_SPAN != 0
inline Spangroup Spangroup::create(Obj parent) noexcept { return Spangroup(lv_spangroup_create(parent.raw())); }

inline void Spangroup::delete_span(Span span) const noexcept { lv_spangroup_delete_span(p_, span.raw()); }

inline TextAlign Spangroup::get_align() const noexcept { return static_cast<TextAlign>(lv_spangroup_get_align(p_)); }

inline Span Spangroup::get_child(int32_t id) const noexcept { return Span(lv_spangroup_get_child(p_, id)); }

inline int32_t Spangroup::get_expand_height(int32_t width) const noexcept { return lv_spangroup_get_expand_height(p_, width); }

inline uint32_t Spangroup::get_expand_width(uint32_t max_width) const noexcept { return lv_spangroup_get_expand_width(p_, max_width); }

inline int32_t Spangroup::get_indent() const noexcept { return lv_spangroup_get_indent(p_); }

inline int32_t Spangroup::get_max_line_height() const noexcept { return lv_spangroup_get_max_line_height(p_); }

inline int32_t Spangroup::get_max_lines() const noexcept { return lv_spangroup_get_max_lines(p_); }

inline SpanMode Spangroup::get_mode() const noexcept { return static_cast<SpanMode>(lv_spangroup_get_mode(p_)); }

inline SpanOverflow Spangroup::get_overflow() const noexcept { return static_cast<SpanOverflow>(lv_spangroup_get_overflow(p_)); }

inline Span Spangroup::get_span_by_point(const Point& point) const noexcept { return Span(lv_spangroup_get_span_by_point(p_, point.ptr())); }

inline lv_span_coords_t Spangroup::get_span_coords(Span span) const noexcept { return lv_spangroup_get_span_coords(p_, span.raw()); }

inline uint32_t Spangroup::get_span_count() const noexcept { return lv_spangroup_get_span_count(p_); }

inline void Spangroup::refresh() const noexcept { lv_spangroup_refresh(p_); }

inline void Spangroup::set_align(TextAlign align) const noexcept { lv_spangroup_set_align(p_, static_cast<lv_text_align_t>(align)); }

inline void Spangroup::set_indent(int32_t indent) const noexcept { lv_spangroup_set_indent(p_, indent); }

inline void Spangroup::set_max_lines(int32_t lines) const noexcept { lv_spangroup_set_max_lines(p_, lines); }

inline void Spangroup::set_mode(SpanMode mode) const noexcept { lv_spangroup_set_mode(p_, static_cast<lv_span_mode_t>(mode)); }

inline void Spangroup::set_overflow(SpanOverflow overflow) const noexcept { lv_spangroup_set_overflow(p_, static_cast<lv_span_overflow_t>(overflow)); }

inline void Spangroup::set_span_style(Span span, Style& style) const noexcept { lv_spangroup_set_span_style(p_, span.raw(), style.raw()); }

inline void Spangroup::set_span_text(Span span, const char* text) const noexcept { lv_spangroup_set_span_text(p_, span.raw(), text); }

inline void Spangroup::set_span_text_static(Span span, const char* text) const noexcept { lv_spangroup_set_span_text_static(p_, span.raw(), text); }

inline lv_style_t* Span::get_style() const noexcept { return lv_span_get_style(p_); }

inline const char* Span::get_text() const noexcept { return lv_span_get_text(p_); }

inline void Span::set_text(const char* text) const noexcept { lv_span_set_text(p_, text); }

template <typename... A>
inline void Span::set_text_fmt(const char* fmt, A... args) const noexcept { lv_span_set_text_fmt(p_, fmt, args...); }

inline void Span::set_text_static(const char* text) const noexcept { lv_span_set_text_static(p_, text); }

inline void Span::set_text_static_(const char* text) const noexcept { lv_span_set_text_static(p_, text); }

inline void span_stack_init() noexcept { lv_span_stack_init(); }

inline void span_stack_deinit() noexcept { lv_span_stack_deinit(); }
#endif // LV_USE_SPAN != 0

} // namespace lv
