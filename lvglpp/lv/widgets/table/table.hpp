#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/core/obj.hpp"
#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>
#include <utility>

namespace lv {

#if LV_USE_TABLE != 0
class Table : public Obj {
public:
    using Obj::Obj;
    static const lv_obj_class_t* class_ptr() noexcept { return &lv_table_class; }

    /**
     * Clear control bits of the cell.
     * @param row  id of the row [0 .. row_cnt -1]
     * @param col  id of the column [0 .. col_cnt -1]
     * @param ctrl  OR-ed values from ::lv_table_cell_ctrl_t
     * @see lv_table_clear_cell_ctrl
     */
    void clear_cell_ctrl(uint32_t row, uint32_t col, TableCellCtrl ctrl) const noexcept { lv_table_clear_cell_ctrl(p_, row, col, static_cast<lv_table_cell_ctrl_t>(ctrl)); }
    /**
     * Create a table object
     * @param parent  pointer to an object, it will be the parent of the new table
     * @return pointer to the created table
     * @see lv_table_create
     */
    static Table create(Obj parent) noexcept { return Table(lv_table_create(parent.raw())); }
    /**
     * Get custom user data to the cell.
     * @param row  id of the row [0 .. row_cnt -1]
     * @param col  id of the column [0 .. col_cnt -1]
     * @see lv_table_get_cell_user_data
     */
    void* get_cell_user_data(uint16_t row, uint16_t col) const noexcept { return lv_table_get_cell_user_data(p_, row, col); }
    /**
     * Get the value of a cell.
     * @param row  id of the row [0 .. row_cnt -1]
     * @param col  id of the column [0 .. col_cnt -1]
     * @return text in the cell
     * @see lv_table_get_cell_value
     */
    const char* get_cell_value(uint32_t row, uint32_t col) const noexcept { return lv_table_get_cell_value(p_, row, col); }
    /**
     * Get the number of columns.
     * @return number of columns.
     * @see lv_table_get_column_count
     */
    uint32_t get_column_count() const noexcept { return lv_table_get_column_count(p_); }
    /**
     * Get the width of a column
     * @param col  id of the column [0 .. LV_TABLE_COL_MAX -1]
     * @return width of the column
     * @see lv_table_get_column_width
     */
    int32_t get_column_width(uint32_t col) const noexcept { return lv_table_get_column_width(p_, col); }
    /**
     * Get the number of rows.
     * @return number of rows.
     * @see lv_table_get_row_count
     */
    uint32_t get_row_count() const noexcept { return lv_table_get_row_count(p_); }
    /**
     * Get the selected cell (pressed and or focused)
     * @return row: pointer to variable to store the selected row (LV_TABLE_CELL_NONE: if no cell selected); col: pointer to variable to store the selected column (LV_TABLE_CELL_NONE: if no cell selected)
     * @see lv_table_get_selected_cell
     */
    std::pair<uint32_t, uint32_t> get_selected_cell() const noexcept {
        uint32_t row_out{};
        uint32_t col_out{};
        lv_table_get_selected_cell(p_, &row_out, &col_out);
        return std::pair<uint32_t, uint32_t>{row_out, col_out};
    }
    /**
     * Get whether a cell has the control bits
     * @param row  id of the row [0 .. row_cnt -1]
     * @param col  id of the column [0 .. col_cnt -1]
     * @param ctrl  OR-ed values from ::lv_table_cell_ctrl_t
     * @return true: all control bits are set; false: not all control bits are set
     * @see lv_table_has_cell_ctrl
     */
    bool has_cell_ctrl(uint32_t row, uint32_t col, TableCellCtrl ctrl) const noexcept { return lv_table_has_cell_ctrl(p_, row, col, static_cast<lv_table_cell_ctrl_t>(ctrl)); }
    /**
     * Add control bits to the cell.
     * @param row  id of the row [0 .. row_cnt -1]
     * @param col  id of the column [0 .. col_cnt -1]
     * @param ctrl  OR-ed values from ::lv_table_cell_ctrl_t
     * @see lv_table_set_cell_ctrl
     */
    void set_cell_ctrl(uint32_t row, uint32_t col, TableCellCtrl ctrl) const noexcept { lv_table_set_cell_ctrl(p_, row, col, static_cast<lv_table_cell_ctrl_t>(ctrl)); }
    /**
     * Add custom user data to the cell.
     * @param row  id of the row [0 .. row_cnt -1]
     * @param col  id of the column [0 .. col_cnt -1]
     * @param user_data  pointer to the new user_data. Should be allocated by `lv_malloc`, and it will be freed automatically when the table is deleted or when the cell is dropped due to lower row or column count.
     * @see lv_table_set_cell_user_data
     */
    void set_cell_user_data(uint16_t row, uint16_t col, void* user_data) const noexcept { lv_table_set_cell_user_data(p_, row, col, user_data); }
    /**
     * Set the value of a cell.
     * @param row  id of the row [0 .. row_cnt -1]
     * @param col  id of the column [0 .. col_cnt -1]
     * @param txt  text to display in the cell. It will be copied and saved so this variable is not required after this function call.
     * @see lv_table_set_cell_value
     */
    void set_cell_value(uint32_t row, uint32_t col, const char* txt) const noexcept { lv_table_set_cell_value(p_, row, col, txt); }
    /**
     * Set the value of a cell.  Memory will be allocated to store the text by the table.
     * @param row  id of the row [0 .. row_cnt -1]
     * @param col  id of the column [0 .. col_cnt -1]
     * @param fmt  `printf`-like format
     * @see lv_table_set_cell_value_fmt
     */
    template <typename... A>
    void set_cell_value_fmt(uint32_t row, uint32_t col, const char* fmt, A... args) const noexcept { lv_table_set_cell_value_fmt(p_, row, col, fmt, args...); }
    /**
     * Set the number of columns
     * @param col_cnt  number of columns.
     * @see lv_table_set_column_count
     */
    void set_column_count(uint32_t col_cnt) const noexcept { lv_table_set_column_count(p_, col_cnt); }
    /**
     * Set the width of a column
     * @param col_id  id of the column [0 .. LV_TABLE_COL_MAX -1]
     * @param w  width of the column
     * @see lv_table_set_column_width
     */
    void set_column_width(uint32_t col_id, int32_t w) const noexcept { lv_table_set_column_width(p_, col_id, w); }
    /**
     * Set the number of rows
     * @param row_cnt  number of rows
     * @see lv_table_set_row_count
     */
    void set_row_count(uint32_t row_cnt) const noexcept { lv_table_set_row_count(p_, row_cnt); }
    /**
     * Set the selected cell
     * @param row  id of the cell row to select
     * @param col  id of the cell column to select
     * @see lv_table_set_selected_cell
     */
    void set_selected_cell(uint16_t row, uint16_t col) const noexcept { lv_table_set_selected_cell(p_, row, col); }
    #if LVPP_COMPAT_V8
    /** v8 spelling of `set_column_count`. */
    void set_col_cnt(uint32_t col_cnt) const noexcept { return set_column_count(col_cnt); }
    /** v8 spelling of `set_row_count`. */
    void set_row_cnt(uint32_t row_cnt) const noexcept { return set_row_count(row_cnt); }
    /** v8 spelling of `get_column_count`. */
    uint32_t get_col_cnt() const noexcept { return get_column_count(); }
    /** v8 spelling of `get_row_count`. */
    uint32_t get_row_cnt() const noexcept { return get_row_count(); }
    /** v8 spelling of `set_column_width`. */
    void set_col_width(uint32_t col_id, int32_t w) const noexcept { return set_column_width(col_id, w); }
    /** v8 spelling of `get_column_width`. */
    int32_t get_col_width(uint32_t col) const noexcept { return get_column_width(col); }
    #endif // LVPP_COMPAT_V8

};
static_assert(sizeof(Table) == sizeof(lv_obj_t*));
static_assert(__is_trivially_copyable(Table));
#endif // LV_USE_TABLE != 0

} // namespace lv
