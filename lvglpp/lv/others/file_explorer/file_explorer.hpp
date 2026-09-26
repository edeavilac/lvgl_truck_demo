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

#if LV_USE_FILE_EXPLORER != 0
class FileExplorer : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_file_explorer_class; }

    enum class Sort : int {
        None = LV_EXPLORER_SORT_NONE,
        Kind = LV_EXPLORER_SORT_KIND,
    };

    #if LV_FILE_EXPLORER_QUICK_ACCESS
    enum class Dir : int {
        HomeDir = LV_EXPLORER_HOME_DIR,
        MusicDir = LV_EXPLORER_MUSIC_DIR,
        PicturesDir = LV_EXPLORER_PICTURES_DIR,
        VideoDir = LV_EXPLORER_VIDEO_DIR,
        DocsDir = LV_EXPLORER_DOCS_DIR,
        FsDir = LV_EXPLORER_FS_DIR,
    };
    #endif // LV_FILE_EXPLORER_QUICK_ACCESS

    /** @see lv_file_explorer_create */
    static FileExplorer create(Obj parent) noexcept { return FileExplorer(lv_file_explorer_create(parent.raw())); }
    /**
     * Get file explorer cur path
     * @return pointer to the file explorer cur path
     * @see lv_file_explorer_get_current_path
     */
    const char* get_current_path() const noexcept { return lv_file_explorer_get_current_path(p_); }
    #if LV_FILE_EXPLORER_QUICK_ACCESS
    /**
     * Get file explorer device list obj(lv_list)
     * @return pointer to the file explorer device list obj(lv_list)
     * @see lv_file_explorer_get_device_list
     */
    Obj get_device_list() const noexcept { return Obj(lv_file_explorer_get_device_list(p_)); }
    #endif // LV_FILE_EXPLORER_QUICK_ACCESS

    /**
     * Get file explorer file list obj(lv_table)
     * @return pointer to the file explorer file table obj(lv_table)
     * @see lv_file_explorer_get_file_table
     */
    Obj get_file_table() const noexcept { return Obj(lv_file_explorer_get_file_table(p_)); }
    /**
     * Get file explorer head area obj
     * @return pointer to the file explorer head area obj(lv_obj)
     * @see lv_file_explorer_get_header
     */
    Obj get_header() const noexcept { return Obj(lv_file_explorer_get_header(p_)); }
    /**
     * Get file explorer path obj(label)
     * @return pointer to the file explorer path obj(lv_label)
     * @see lv_file_explorer_get_path_label
     */
    Obj get_path_label() const noexcept { return Obj(lv_file_explorer_get_path_label(p_)); }
    #if LV_FILE_EXPLORER_QUICK_ACCESS
    /**
     * Get file explorer places list obj(lv_list)
     * @return pointer to the file explorer places list obj(lv_list)
     * @see lv_file_explorer_get_places_list
     */
    Obj get_places_list() const noexcept { return Obj(lv_file_explorer_get_places_list(p_)); }
    /**
     * Get file explorer head area obj
     * @return pointer to the file explorer quick access area obj(lv_obj)
     * @see lv_file_explorer_get_quick_access_area
     */
    Obj get_quick_access_area() const noexcept { return Obj(lv_file_explorer_get_quick_access_area(p_)); }
    #endif // LV_FILE_EXPLORER_QUICK_ACCESS

    /**
     * Get file explorer Selected file
     * @return pointer to the file explorer selected file name
     * @see lv_file_explorer_get_selected_file_name
     */
    const char* get_selected_file_name() const noexcept { return lv_file_explorer_get_selected_file_name(p_); }
    /**
     * Set file_explorer sort
     * @return the current mode from 'lv_file_explorer_sort_t'
     * @see lv_file_explorer_get_sort
     */
    FileExplorer::Sort get_sort() const noexcept { return static_cast<FileExplorer::Sort>(lv_file_explorer_get_sort(p_)); }
    /**
     * Open a specified path
     * @param dir  pointer to the path
     * @see lv_file_explorer_open_dir
     */
    void open_dir(const char* dir) const noexcept { lv_file_explorer_open_dir(p_, dir); }
    #if LV_FILE_EXPLORER_QUICK_ACCESS
    /**
     * Set file_explorer
     * @param dir  the dir from 'lv_file_explorer_dir_t' enum.
     * @param path  path
     * @see lv_file_explorer_set_quick_access_path
     */
    void set_quick_access_path(FileExplorer::Dir dir, const char* path) const noexcept { lv_file_explorer_set_quick_access_path(p_, static_cast<lv_file_explorer_dir_t>(dir), path); }
    #endif // LV_FILE_EXPLORER_QUICK_ACCESS

    /**
     * Set file_explorer sort
     * @param sort  the sort from 'lv_file_explorer_sort_t' enum.
     * @see lv_file_explorer_set_sort
     */
    void set_sort(FileExplorer::Sort sort) const noexcept { lv_file_explorer_set_sort(p_, static_cast<lv_file_explorer_sort_t>(sort)); }
    /**
     * Set the visibility of the "< Back" button
     * @param show  bool true/false, enable or disable button
     * @see lv_file_explorer_show_back_button
     */
    void show_back_button(bool show) const noexcept { lv_file_explorer_show_back_button(p_, show); }
};
static_assert(sizeof(FileExplorer) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(FileExplorer));
#endif // LV_USE_FILE_EXPLORER != 0

} // namespace lv
