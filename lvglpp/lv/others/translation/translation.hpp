#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_TRANSLATION
/**
 * Initialize the translation module
 * @see lv_translation_init
 */
inline void translation_init() noexcept { lv_translation_init(); }

/**
 * De-initialize the translation module and free all allocated translations
 * @see lv_translation_deinit
 */
inline void translation_deinit() noexcept { lv_translation_deinit(); }

/**
 * Register a translation pack from static arrays.
 * All the pointers need to be static, that is to live while they are used
 * @param languages  List of languages. E.g. `{"en", "de", NULL}`
 * @param tags  Tags that are using in the UI. E.g. `{"dog", "cat", NULL}`
 * @param translations  List of translations. E.g. `{"Dog", "Cat", "Hund", "Katze"}`
 * @return The created pack
 * @see lv_translation_add_static
 */
inline lv_translation_pack_t* translation_add_static(const char* const* languages, const char* const* tags, const char* const* translations) noexcept { return lv_translation_add_static(languages, tags, translations); }

/**
 * Add a pack to which translations can be added dynamically.
 * `pack->languages` needs to be a malloc-ed array where each language is also malloc-ed as an element.
 * `pack->translation_array` stores the translation having `lv_translation_tag_dsc_t` items
 * In each array element `tag` is a malloced string, `translations` is a malloc-ed array
 * with malloc-ed array for each element.
 * @return the created pack to which data can be added manually.
 * @see lv_translation_add_dynamic
 */
inline lv_translation_pack_t* translation_add_dynamic() noexcept { return lv_translation_add_dynamic(); }

/**
 * Select the current language
 * The `LV_EVENT_TRANSLATION_LANGUAGE_CHANGED` event will be sent to every widget
 * @param lang  a string from the defined languages. E.g. "en" or "de"
 * @see lv_translation_set_language
 */
inline void translation_set_language(const char* lang) noexcept { lv_translation_set_language(lang); }

/**
 * Get the current selected language
 * @return the current selected language
 * @see lv_translation_get_language
 */
inline const char* translation_get_language() noexcept { return lv_translation_get_language(); }

/**
 * Get the translated version of a tag on the selected language
 * @param tag  the tag to translate
 * @return the translation
 * @see lv_translation_get
 */
inline const char* translation_get(const char* tag) noexcept { return lv_translation_get(tag); }

/**
 * Shorthand of lv_translation_set_language
 * @param tag  the tag to translate
 * @return the translation
 * @see lv_tr
 */
inline const char* translation_tr(const char* tag) noexcept { return lv_tr(tag); }

/**
 * Add a new language to a dynamic language pack.
 * All languages should be added before adding tags
 * @param pack  pointer to a dynamic translation pack
 * @param lang  language to add, e.g. "en", or "de"
 * @return LV_RESULT_OK: success, LV_RESULT_INVALID: failed
 * @see lv_translation_add_language
 */
inline Result translation_add_language(lv_translation_pack_t* pack, const char* lang) noexcept { return static_cast<Result>(lv_translation_add_language(pack, lang)); }

/**
 * Get the index of a language in a pack.
 * @param pack  pointer to a static or dynamic language pack
 * @param lang_name  name of the language to find
 * @return index of the language or -1 if not found.
 * @see lv_translation_get_language_index
 */
inline int32_t translation_get_language_index(lv_translation_pack_t* pack, const char* lang_name) noexcept { return lv_translation_get_language_index(pack, lang_name); }

/**
 * Add a new tag to a dynamic language pack.
 * Once the tag is added the translations for each language can be added too by using
 * `lv_translation_set_tag_translation`
 * @param pack  pointer to a dynamic translation pack
 * @param tag_name  name of the tag, e.g. "dog", or "house"
 * @return pointer to the allocated tag descriptor
 * @see lv_translation_add_tag
 */
inline lv_translation_tag_dsc_t* translation_add_tag(lv_translation_pack_t* pack, const char* tag_name) noexcept { return lv_translation_add_tag(pack, tag_name); }

/**
 * Add a translation to a tag in a dynamic translation pack
 * @param pack  pointer to a dynamic translation pack
 * @param tag  return value of `lv_translation_add_tag`
 * @param lang_idx  index of the language for which translation should be set
 * @param trans  the translation on the given language
 * @return LV_RESULT_OK: success, LV_RESULT_INVALID: failed
 * @see lv_translation_set_tag_translation
 */
inline Result translation_set_tag_translation(lv_translation_pack_t* pack, lv_translation_tag_dsc_t* tag, uint32_t lang_idx, const char* trans) noexcept { return static_cast<Result>(lv_translation_set_tag_translation(pack, tag, lang_idx, trans)); }
#endif // LV_USE_TRANSLATION

} // namespace lv
