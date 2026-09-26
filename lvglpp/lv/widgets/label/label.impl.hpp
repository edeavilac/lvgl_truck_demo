#pragma once
// Bodies of widgets/label/label.hpp, separated because its file cycle needs every type
// complete. Same mechanism as D-C7, applied where the graph asks for it.
// Included by the umbrella and never by a header: it is NOT a translation
// unit and every definition in it is `inline`. The stem says so, not the
// extension, so a glob written for *.hpp still installs it.

#include "lv/lvgl.hpp"

namespace lv {

#if (LV_USE_LABEL != 0) && (LV_USE_OBSERVER)
inline Observer Label::bind_text(Subject& subject, const char* fmt) const noexcept { return Observer(lv_label_bind_text(p_, subject.raw(), fmt)); }
#endif // (LV_USE_LABEL != 0) && (LV_USE_OBSERVER)

#if LV_USE_LABEL != 0
inline Label Label::create(Obj parent) noexcept { return Label(lv_label_create(parent.raw())); }

inline void Label::cut_text(uint32_t pos, uint32_t cnt) const noexcept { lv_label_cut_text(p_, pos, cnt); }

inline uint32_t Label::get_letter_on(Point& pos_in, bool bidi) const noexcept { return lv_label_get_letter_on(p_, pos_in.ptr(), bidi); }

inline Point Label::get_letter_pos(uint32_t char_id) const noexcept {
    lv_point_t pos_out{};
    lv_label_get_letter_pos(p_, char_id, &pos_out);
    return Point{pos_out};
}

inline Label::LongMode Label::get_long_mode() const noexcept { return static_cast<Label::LongMode>(lv_label_get_long_mode(p_)); }

inline bool Label::get_recolor() const noexcept { return lv_label_get_recolor(p_); }

inline char* Label::get_text() const noexcept { return lv_label_get_text(p_); }

inline uint32_t Label::get_text_selection_end() const noexcept { return lv_label_get_text_selection_end(p_); }

inline uint32_t Label::get_text_selection_start() const noexcept { return lv_label_get_text_selection_start(p_); }

inline void Label::ins_text(uint32_t pos, const char* txt) const noexcept { lv_label_ins_text(p_, pos, txt); }

inline bool Label::is_char_under_pos(Point& pos) const noexcept { return lv_label_is_char_under_pos(p_, pos.ptr()); }

inline void Label::set_long_mode(Label::LongMode long_mode) const noexcept { lv_label_set_long_mode(p_, static_cast<lv_label_long_mode_t>(long_mode)); }

inline void Label::set_recolor(bool en) const noexcept { lv_label_set_recolor(p_, en); }

inline void Label::set_text(const char* text) const noexcept { lv_label_set_text(p_, text); }

template <typename... A>
inline void Label::set_text_fmt(const char* fmt, A... args) const noexcept { lv_label_set_text_fmt(p_, fmt, args...); }

inline void Label::set_text_selection_end(uint32_t index) const noexcept { lv_label_set_text_selection_end(p_, index); }

inline void Label::set_text_selection_start(uint32_t index) const noexcept { lv_label_set_text_selection_start(p_, index); }

inline void Label::set_text_static(const char* text) const noexcept { lv_label_set_text_static(p_, text); }

inline void Label::set_text_vfmt(const char* fmt, va_list args) const noexcept { lv_label_set_text_vfmt(p_, fmt, args); }
#endif // LV_USE_LABEL != 0

#if (LV_USE_LABEL != 0) && (LV_USE_TRANSLATION)
inline void Label::set_translation_tag(const char* tag) const noexcept { lv_label_set_translation_tag(p_, tag); }
#endif // (LV_USE_LABEL != 0) && (LV_USE_TRANSLATION)

} // namespace lv
