#pragma once
// Bodies of misc/event.hpp, separated because its file cycle needs every type
// complete. Same mechanism as D-C7, applied where the graph asks for it.
// Included by the umbrella and never by a header: it is NOT a translation
// unit and every definition in it is `inline`. The stem says so, not the
// extension, so a glob written for *.hpp still installs it.

#include "lv/lvgl.hpp"

namespace lv {

inline lv_event_cb_t EventDsc::get_cb() const noexcept { return lv_event_dsc_get_cb(p_); }

inline void* EventDsc::get_user_data() const noexcept { return lv_event_dsc_get_user_data(p_); }

inline void Event::free_user_data_cb() const noexcept { lv_event_free_user_data_cb(p_); }

inline EventCode Event::get_code() const noexcept { return static_cast<EventCode>(lv_event_get_code(p_)); }

inline void* Event::get_current_target() const noexcept { return lv_event_get_current_target(p_); }

inline void* Event::get_param() const noexcept { return lv_event_get_param(p_); }

inline void* Event::get_target() const noexcept { return lv_event_get_target(p_); }

inline void* Event::get_user_data() const noexcept { return lv_event_get_user_data(p_); }

inline void Event::stop_bubbling() const noexcept { lv_event_stop_bubbling(p_); }

inline void Event::stop_processing() const noexcept { lv_event_stop_processing(p_); }

inline void Event::stop_trickling() const noexcept { lv_event_stop_trickling(p_); }

inline Result event_send(lv_event_list_t* list, Event& e, bool preprocess) noexcept { return static_cast<Result>(lv_event_send(list, e.raw(), preprocess)); }

inline EventDsc event_add(lv_event_list_t* list, lv_event_cb_t cb, EventCode filter, void* user_data) noexcept { return EventDsc(lv_event_add(list, cb, static_cast<lv_event_code_t>(filter), user_data)); }

inline bool event_remove_dsc(lv_event_list_t* list, EventDsc dsc) noexcept { return lv_event_remove_dsc(list, dsc.raw()); }

inline uint32_t event_get_count(lv_event_list_t* list) noexcept { return lv_event_get_count(list); }

inline EventDsc event_get_dsc(lv_event_list_t* list, uint32_t index) noexcept { return EventDsc(lv_event_get_dsc(list, index)); }

inline bool event_remove(lv_event_list_t* list, uint32_t index) noexcept { return lv_event_remove(list, index); }

inline void event_remove_all(lv_event_list_t* list) noexcept { lv_event_remove_all(list); }

inline uint32_t event_register_id() noexcept { return lv_event_register_id(); }

inline const char* event_code_get_name(EventCode code) noexcept { return lv_event_code_get_name(static_cast<lv_event_code_t>(code)); }

#if LV_USE_EXT_DATA
inline void event_desc_set_external_data(EventDsc dsc, void* data, void (*arg)(void*)) noexcept { lv_event_desc_set_external_data(dsc.raw(), data, arg); }
#endif // LV_USE_EXT_DATA

} // namespace lv
