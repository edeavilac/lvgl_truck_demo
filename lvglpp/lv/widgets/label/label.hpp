#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core/obj.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_LABEL != 0
class Label : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_label_class; }

    /** Long mode behaviors. Used in 'lv_label_ext_t' */
    enum class LongMode : int {
        /** Keep the object width, wrap lines longer than object width and expand the object height */
        Wrap = LV_LABEL_LONG_MODE_WRAP,
        /** Keep the size and write dots at the end if the text is too long */
        Dots = LV_LABEL_LONG_MODE_DOTS,
        /** Keep the size and roll the text back and forth */
        Scroll = LV_LABEL_LONG_MODE_SCROLL,
        /** Keep the size and roll the text circularly */
        ScrollCircular = LV_LABEL_LONG_MODE_SCROLL_CIRCULAR,
        /** Keep the size and clip the text out of it */
        Clip = LV_LABEL_LONG_MODE_CLIP,
    };

    #if LV_USE_OBSERVER
    /**
     * Bind an integer, string, or pointer Subject to a Label.
     * @param subject  pointer to Subject
     * @param fmt  optional printf-like format string with 1 format specifier (e.g. "%d °C") or NULL to bind to the value directly.
     * @return pointer to newly-created Observer
     * @see lv_label_bind_text
     */
    Observer bind_text(Subject& subject, const char* fmt) const noexcept;
    #endif // LV_USE_OBSERVER

    /**
     * Create a label object
     * @param parent  pointer to an object, it will be the parent of the new label.
     * @return pointer to the created button
     * @see lv_label_create
     */
    static Label create(Obj parent) noexcept;
    /**
     * Delete characters from a label. The label text cannot be static.
     * @param pos  character index from where to cut. Expressed in character index and not byte index. 0: start in front of the first character
     * @param cnt  number of characters to cut
     * @see lv_label_cut_text
     */
    void cut_text(uint32_t pos, uint32_t cnt) const noexcept;
    /**
     * Get the index of letter on a relative point of a label.
     * @param pos_in  pointer to point with coordinates on a the label
     * @param bidi  whether to use bidi processed
     * @return The index of the letter on the 'pos_p' point (E.g. on 0;0 is the 0. letter if aligned to the left) Expressed in character index and not byte index (different in UTF-8)
     * @see lv_label_get_letter_on
     */
    uint32_t get_letter_on(Point& pos_in, bool bidi) const noexcept;
    /**
     * Get the relative x and y coordinates of a letter
     * @param char_id  index of the character [0 ... text length - 1]. Expressed in character index, not byte index (different in UTF-8)
     * @return store the result here (E.g. index = 0 gives 0;0 coordinates if the text if aligned to the left)
     * @see lv_label_get_letter_pos
     */
    Point get_letter_pos(uint32_t char_id) const noexcept;
    /**
     * Get the long mode of a label
     * @return the current long mode
     * @see lv_label_get_long_mode
     */
    Label::LongMode get_long_mode() const noexcept;
    /**
     * Get the recoloring attribute
     * @return true: recoloring is enabled, false: recoloring is disabled
     * @see lv_label_get_recolor
     */
    bool get_recolor() const noexcept;
    /**
     * Get the text of a label
     * @return the text of the label
     * @see lv_label_get_text
     */
    char* get_text() const noexcept;
    /**
     * Get the selection end index.
     * @return selection end index. `LV_LABEL_TXT_SEL_OFF` if nothing is selected.
     * @see lv_label_get_text_selection_end
     */
    uint32_t get_text_selection_end() const noexcept;
    /**
     * Get the selection start index.
     * @return selection start index. `LV_LABEL_TEXT_SELECTION_OFF` if nothing is selected.
     * @see lv_label_get_text_selection_start
     */
    uint32_t get_text_selection_start() const noexcept;
    /**
     * Insert a text to a label. The label text cannot be static.
     * @param pos  character index to insert. Expressed in character index and not byte index. 0: before first char. LV_LABEL_POS_LAST: after last char.
     * @param txt  pointer to the text to insert
     * @see lv_label_ins_text
     */
    void ins_text(uint32_t pos, const char* txt) const noexcept;
    /**
     * Check if a character is drawn under a point.
     * @param pos  Point to check for character under
     * @return whether a character is drawn under the point
     * @see lv_label_is_char_under_pos
     */
    bool is_char_under_pos(Point& pos) const noexcept;
    /**
     * Set the behavior of the label with text longer than the object size
     * @param long_mode  the new mode from 'lv_label_long_mode' enum. In LV_LONG_WRAP/DOT/SCROLL/SCROLL_CIRC the size of the label should be set AFTER this function
     * @see lv_label_set_long_mode
     */
    void set_long_mode(Label::LongMode long_mode) const noexcept;
    /**
     * Enable the recoloring by in-line commands
     * @param en  true: enable recoloring, false: disable Example: "This is a #ff0000 red# word"
     * @see lv_label_set_recolor
     */
    void set_recolor(bool en) const noexcept;
    /**
     * Set a new text for a label. Memory will be allocated to store the text by the label.
     * @param text  '\0' terminated character string. NULL to refresh with the current text.
     * @see lv_label_set_text
     */
    void set_text(const char* text) const noexcept;
    /**
     * Set a new formatted text for a label. Memory will be allocated to store the text by the label.
     * @see lv_label_set_text_fmt
     */
    template <typename... A>
    void set_text_fmt(const char* fmt, A... args) const noexcept;
    /**
     * Set where text selection should end
     * @param index  character index where selection should end. `LV_LABEL_TEXT_SELECTION_OFF` for no selection
     * @see lv_label_set_text_selection_end
     */
    void set_text_selection_end(uint32_t index) const noexcept;
    /**
     * Set where text selection should start
     * @param index  character index from where selection should start. `LV_LABEL_TEXT_SELECTION_OFF` for no selection
     * @see lv_label_set_text_selection_start
     */
    void set_text_selection_start(uint32_t index) const noexcept;
    /**
     * LVGL keeps this pointer rather than copying what it points at: it must outlive the object. A string literal is the intended use.
     * Set a static text. It will not be saved by the label so the 'text' variable
     * has to be 'alive' while the label exists.
     * @param text  pointer to a text. NULL to refresh with the current text.
     * @see lv_label_set_text_static
     */
    void set_text_static(const char* text) const noexcept;
    /**
     * Set a new formatted text for a label. Memory will be allocated to store the text by the label.
     * @param fmt  `printf`-like format string
     * @see lv_label_set_text_vfmt
     */
    void set_text_vfmt(const char* fmt, va_list args) const noexcept;
    #if LV_USE_TRANSLATION
    /**
     * Assign a translation tag for this label. Memory will be allocated to store the tag by the label.
     * The label text will automatically update when the language is changed via `lv_translation_set_language`.
     * @param tag  '\0' terminated character string.
     * @see lv_label_set_translation_tag
     */
    void set_translation_tag(const char* tag) const noexcept;
    #endif // LV_USE_TRANSLATION

};
static_assert(sizeof(Label) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Label));
#endif // LV_USE_LABEL != 0

} // namespace lv
