#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_SPAN != 0
class Span {
protected:
    lv_span_t* p_ = nullptr;

public:
    constexpr Span() noexcept = default;  /**< the "no object" handle */
    constexpr explicit Span(lv_span_t* p) noexcept : p_(p) {}

    constexpr lv_span_t* raw() const noexcept { return p_; }
    constexpr explicit operator bool() const noexcept { return p_ != nullptr; }
    friend constexpr bool operator==(Span a, Span b) noexcept { return a.p_ == b.p_; }

    /**
     * Get a pointer to the style of a span's built-in style.
     * Any lv_style_set_... functions can be applied on the returned style.
     * @return pointer to the style. (valid as long as the span is valid)
     * @see lv_span_get_style
     */
    lv_style_t* get_style() const noexcept;
    /**
     * Get a pointer to the text of a span
     * @return pointer to the text
     * @see lv_span_get_text
     */
    const char* get_text() const noexcept;
    /**
     * Set a new text for a span. Memory will be allocated to store the text by the span.
     * As the spangroup is not passed a redraw (invalidation) can't be triggered automatically.
     * Therefore `lv_spangroup_refresh(spangroup)` needs to be called manually,
     * @param text  pointer to a text.
     * @see lv_span_set_text
     */
    void set_text(const char* text) const noexcept;
    /**
     * Set a new text for a span using a printf-like formatting string.
     * Memory will be allocated to store the text by the span.
     * As the spangroup is not passed a redraw (invalidation) can't be triggered automatically.
     * Therefore `lv_spangroup_refresh(spangroup)` needs to be called manually,
     * @param fmt  `printf`-like format string
     * @see lv_span_set_text_fmt
     */
    template <typename... A>
    void set_text_fmt(const char* fmt, A... args) const noexcept;
    /**
     * LVGL keeps this pointer rather than copying what it points at: it must outlive the object. A string literal is the intended use.
     * Set a static text. It will not be saved by the span so the 'text' variable
     * has to be 'alive' while the span exist.
     * As the spangroup is not passed a redraw (invalidation) can't be triggered automatically.
     * Therefore `lv_spangroup_refresh(spangroup)` needs to be called manually,
     * @param text  pointer to a text.
     * @see lv_span_set_text_static
     */
    void set_text_static(const char* text) const noexcept;
    /**
     * LVGL keeps this pointer rather than copying what it points at: it must outlive the object. A string literal is the intended use.
     * Set a static text. It will not be saved by the span so the 'text' variable
     * has to be 'alive' while the span exist.
     * @param text  pointer to a text.
     * @see lv_span_set_text_static
     */
    void set_text_static_(const char* text) const noexcept;
};
static_assert(sizeof(Span) == sizeof(lv_span_t*));
static_assert(__is_trivially_copyable(Span));

/** @see lv_span_stack_init */
inline void span_stack_init() noexcept;

/** @see lv_span_stack_deinit */
inline void span_stack_deinit() noexcept;
#endif // LV_USE_SPAN != 0

} // namespace lv
