#pragma once
// Bodies of core.hpp, separated because its file cycle needs every type
// complete. Same mechanism as D-C7, applied where the graph asks for it.
// Included by the umbrella and never by a header: it is NOT a translation
// unit and every definition in it is `inline`. The stem says so, not the
// extension, so a glob written for *.hpp still installs it.

#include "lv/lvgl.hpp"

namespace lv {

template <auto Fn>
inline void DrawBufHandlers::init(lv_draw_buf_malloc_cb_t buf_malloc_cb, lv_draw_buf_free_cb_t buf_free_cb, lv_draw_buf_copy_cb_t buf_copy_cb, lv_draw_buf_cache_operation_cb_t invalidate_cache_cb, lv_draw_buf_cache_operation_cb_t flush_cache_cb, lv_draw_buf_width_to_stride_cb_t width_to_stride_cb) const noexcept { lv_draw_buf_handlers_init(p_, buf_malloc_cb, buf_free_cb, buf_copy_cb, &detail::DrawBufAlignCbThunk<Fn>::call, invalidate_cache_cb, flush_cache_cb, width_to_stride_cb); }

inline Layer& Layer::reset() noexcept { lv_layer_reset(&s_); return *this; }

inline FsDrv& FsDrv::register_() noexcept { lv_fs_drv_register(&s_); return *this; }

#if LV_USE_OBSERVER
inline Observer Subject::add_observer(lv_observer_cb_t observer_cb, void* user_data) noexcept { return Observer(lv_subject_add_observer(&s_, observer_cb, user_data)); }

template <class F>
inline Observer Subject::add_observer(F&& f) noexcept { return Observer(lv_subject_add_observer(&s_, detail::ObserverCbClosure<std::decay_t<F>>::fn(f), detail::ObserverCbClosure<std::decay_t<F>>::state(f))); }

inline Observer Subject::add_observer_obj(lv_observer_cb_t observer_cb, Obj obj, void* user_data) noexcept { return Observer(lv_subject_add_observer_obj(&s_, observer_cb, obj.raw(), user_data)); }

template <class F>
inline Observer Subject::add_observer_obj(Obj obj, F&& f) noexcept { return Observer(lv_subject_add_observer_obj(&s_, detail::ObserverCbClosure<std::decay_t<F>>::fn(f), obj.raw(), detail::ObserverCbClosure<std::decay_t<F>>::state(f))); }

inline Observer Subject::add_observer_with_target(lv_observer_cb_t observer_cb, void* target, void* user_data) noexcept { return Observer(lv_subject_add_observer_with_target(&s_, observer_cb, target, user_data)); }

template <class F>
inline Observer Subject::add_observer_with_target(void* user_data, F&& f) noexcept { return Observer(lv_subject_add_observer_with_target(&s_, detail::ObserverCbClosure<std::decay_t<F>>::fn(f), detail::ObserverCbClosure<std::decay_t<F>>::state(f), user_data)); }

inline Subject& Subject::deinit() noexcept { lv_subject_deinit(&s_); return *this; }

inline lv_subject_t* Subject::get_group_element(int32_t index) noexcept { return lv_subject_get_group_element(&s_, index); }

inline Subject& Subject::notify() noexcept { lv_subject_notify(&s_); return *this; }
#endif // LV_USE_OBSERVER

#if (LV_USE_OBSERVER) && (LV_USE_EXT_DATA)
inline Subject& Subject::set_external_data(void* data, void (*arg)(void*)) noexcept { lv_subject_set_external_data(&s_, data, arg); return *this; }

template <auto Fn>
inline Subject& Subject::set_external_data(void* data) noexcept { lv_subject_set_external_data(&s_, data, &detail::SubjectSetExternalDataThunk<Fn>::call); return *this; }
#endif // (LV_USE_OBSERVER) && (LV_USE_EXT_DATA)

#if LV_USE_OBSERVER
template <typename... A>
inline Subject& Subject::snprintf(const char* format, A... args) noexcept { lv_subject_snprintf(&s_, format, args...); return *this; }
#endif // LV_USE_OBSERVER

#if LV_USE_SPAN != 0
template <typename... A>
inline void Spangroup::set_span_text_fmt(Span span, const char* fmt, A... args) const noexcept { lv_spangroup_set_span_text_fmt(p_, span.raw(), fmt, args...); }
#endif // LV_USE_SPAN != 0

#if LV_USE_OBSERVER
inline Color SubjectOf<Color>::get() noexcept { return Color{lv_subject_get_color(&s_)}; }

inline Color SubjectOf<Color>::get_previous() noexcept { return Color{lv_subject_get_previous_color(&s_)}; }

inline void SubjectOf<Color>::set(Color color) noexcept { lv_subject_set_color(&s_, color.raw()); }

inline void SubjectOf<const char*>::copy(const char* buf) noexcept { lv_subject_copy_string(&s_, buf); }

inline const char* SubjectOf<const char*>::get_previous() noexcept { return lv_subject_get_previous_string(&s_); }

inline const char* SubjectOf<const char*>::get() noexcept { return lv_subject_get_string(&s_); }
#endif // LV_USE_OBSERVER

#if (LV_USE_OBSERVER) && (LV_USE_FLOAT)
inline float SubjectOf<float>::get() noexcept { return lv_subject_get_float(&s_); }

inline float SubjectOf<float>::get_previous() noexcept { return lv_subject_get_previous_float(&s_); }

inline void SubjectOf<float>::set(float value) noexcept { lv_subject_set_float(&s_, value); }

inline void SubjectOf<float>::set_max_value(float max_value) noexcept { lv_subject_set_max_value_float(&s_, max_value); }

inline void SubjectOf<float>::set_min_value(float min_value) noexcept { lv_subject_set_min_value_float(&s_, min_value); }
#endif // (LV_USE_OBSERVER) && (LV_USE_FLOAT)

#if LV_USE_OBSERVER
inline int32_t SubjectOf<int32_t>::get() noexcept { return lv_subject_get_int(&s_); }

inline int32_t SubjectOf<int32_t>::get_previous() noexcept { return lv_subject_get_previous_int(&s_); }

inline void SubjectOf<int32_t>::set(int32_t value) noexcept { lv_subject_set_int(&s_, value); }

inline void SubjectOf<int32_t>::set_max_value(int32_t max_value) noexcept { lv_subject_set_max_value_int(&s_, max_value); }

inline void SubjectOf<int32_t>::set_min_value(int32_t min_value) noexcept { lv_subject_set_min_value_int(&s_, min_value); }

inline const void* SubjectOf<void*>::get() noexcept { return lv_subject_get_pointer(&s_); }

inline const void* SubjectOf<void*>::get_previous() noexcept { return lv_subject_get_previous_pointer(&s_); }

inline void SubjectOf<void*>::set(void* ptr) noexcept { lv_subject_set_pointer(&s_, ptr); }
#endif // LV_USE_OBSERVER

inline int32_t version_major() noexcept { return lv_version_major(); }

inline int32_t version_minor() noexcept { return lv_version_minor(); }

inline int32_t version_patch() noexcept { return lv_version_patch(); }

inline const char* version_info() noexcept { return lv_version_info(); }

inline lv_style_prop_t style_register_prop(uint8_t flag) noexcept { return lv_style_register_prop(flag); }

inline lv_style_prop_t style_get_num_custom_props() noexcept { return lv_style_get_num_custom_props(); }

inline lv_style_value_t style_prop_get_default(lv_style_prop_t prop) noexcept { return lv_style_prop_get_default(prop); }

inline uint32_t style_get_prop_group(lv_style_prop_t prop) noexcept { return lv_style_get_prop_group(prop); }

inline uint8_t style_prop_lookup_flags(lv_style_prop_t prop) noexcept { return lv_style_prop_lookup_flags(prop); }

inline bool style_prop_has_flag(lv_style_prop_t prop, uint8_t flag) noexcept { return lv_style_prop_has_flag(prop, flag); }

} // namespace lv
