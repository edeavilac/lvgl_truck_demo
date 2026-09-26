#pragma once
// Bodies of types.hpp, separated because its file cycle needs every type
// complete. Same mechanism as D-C7, applied where the graph asks for it.
// Included by the umbrella and never by a header: it is NOT a translation
// unit and every definition in it is `inline`. The stem says so, not the
// extension, so a glob written for *.hpp still installs it.

#include "lv/lvgl.hpp"

namespace lv {

constexpr int32_t Area::x1() const noexcept { return v.x1; }

constexpr int32_t Area::y1() const noexcept { return v.y1; }

constexpr int32_t Area::x2() const noexcept { return v.x2; }

constexpr int32_t Area::y2() const noexcept { return v.y2; }

inline void Area::align(Area& to_align, Align align, int32_t ofs_x, int32_t ofs_y) const noexcept { lv_area_align(&v, to_align.ptr(), static_cast<lv_align_t>(align), ofs_x, ofs_y); }

inline void Area::copy(const Area& src) noexcept { lv_area_copy(&v, src.ptr()); }

inline int32_t Area::get_height() const noexcept { return lv_area_get_height(&v); }

inline uint32_t Area::get_size() const noexcept { return lv_area_get_size(&v); }

inline int32_t Area::get_width() const noexcept { return lv_area_get_width(&v); }

inline void Area::increase(int32_t w_extra, int32_t h_extra) noexcept { lv_area_increase(&v, w_extra, h_extra); }

inline void Area::move(int32_t x_ofs, int32_t y_ofs) noexcept { lv_area_move(&v, x_ofs, y_ofs); }

inline void Area::set(int32_t x1, int32_t y1, int32_t x2, int32_t y2) noexcept { lv_area_set(&v, x1, y1, x2, y2); }

inline void Area::set_height(int32_t h) noexcept { lv_area_set_height(&v, h); }

inline void Area::set_width(int32_t w) noexcept { lv_area_set_width(&v, w); }

constexpr uint8_t Color::blue() const noexcept { return v.blue; }

constexpr uint8_t Color::green() const noexcept { return v.green; }

constexpr uint8_t Color::red() const noexcept { return v.red; }

inline Color Color::hex(uint32_t c) noexcept { return Color{lv_color_hex(c)}; }

inline Color Color::make(uint8_t r, uint8_t g, uint8_t b) noexcept { return Color{lv_color_make(r, g, b)}; }

inline Color Color::hex3(uint32_t c) noexcept { return Color{lv_color_hex3(c)}; }

inline Color Color::lighten(Color c, lv_opa_t lvl) noexcept { return Color{lv_color_lighten(c.raw(), lvl)}; }

inline Color Color::darken(Color c, lv_opa_t lvl) noexcept { return Color{lv_color_darken(c.raw(), lvl)}; }

inline Color Color::white() noexcept { return Color{lv_color_white()}; }

inline Color Color::black() noexcept { return Color{lv_color_black()}; }

inline Color Color::mix(Color c1, Color c2, uint8_t mix) noexcept { return Color{lv_color_mix(c1.raw(), c2.raw(), mix)}; }

constexpr int32_t Point::x() const noexcept { return v.x; }

constexpr int32_t Point::y() const noexcept { return v.y; }

inline Point Point::from_precise(PointPrecise p) noexcept { return Point{lv_point_from_precise(p.raw())}; }

inline void Point::array_transform(size_t count, int32_t angle, int32_t scale_x, int32_t scale_y, const Point& pivot, bool zoom_first) noexcept { lv_point_array_transform(&v, count, angle, scale_x, scale_y, pivot.ptr(), zoom_first); }

inline void Point::set(int32_t x, int32_t y) noexcept { lv_point_set(&v, x, y); }

inline void Point::swap(Point& p2) noexcept { lv_point_swap(&v, p2.ptr()); }

inline lv_point_precise_t Point::to_precise() const noexcept { return lv_point_to_precise(&v); }

inline void Point::transform(int32_t angle, int32_t scale_x, int32_t scale_y, const Point& pivot, bool zoom_first) noexcept { lv_point_transform(&v, angle, scale_x, scale_y, pivot.ptr(), zoom_first); }

} // namespace lv
