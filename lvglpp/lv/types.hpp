#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lvgl.h"
#include <cstddef>
#include <cstdint>
#include <type_traits>

namespace lv {

/** Represents an area of the screen. */
class Area {
public:
    lv_area_t v;

public:
    constexpr lv_area_t raw() const noexcept { return v; }
    constexpr const lv_area_t* ptr() const noexcept { return &v; }
    constexpr lv_area_t* ptr() noexcept { return &v; }

    constexpr int32_t x1() const noexcept;
    constexpr int32_t y1() const noexcept;
    constexpr int32_t x2() const noexcept;
    constexpr int32_t y2() const noexcept;
    /**
     * Align an area to another
     * @param to_align  the area to align
     * @param align  `LV_ALIGN_...`
     * @param ofs_x  X offset
     * @param ofs_y  Y offset
     * @see lv_area_align
     */
    void align(Area& to_align, Align align, int32_t ofs_x, int32_t ofs_y) const noexcept;
    /**
     * Copy an area
     * @param src  pointer to the source area
     * @see lv_area_copy
     */
    void copy(const Area& src) noexcept;
    /**
     * Get the height of an area
     * @return the height of the area (if y1 == y2 -> height = 1)
     * @see lv_area_get_height
     */
    int32_t get_height() const noexcept;
    /**
     * Return with area of an area (x * y)
     * @return size of area
     * @see lv_area_get_size
     */
    uint32_t get_size() const noexcept;
    /**
     * Get the width of an area
     * @return the width of the area (if x1 == x2 -> width = 1)
     * @see lv_area_get_width
     */
    int32_t get_width() const noexcept;
    /** @see lv_area_increase */
    void increase(int32_t w_extra, int32_t h_extra) noexcept;
    /** @see lv_area_move */
    void move(int32_t x_ofs, int32_t y_ofs) noexcept;
    /**
     * Initialize an area
     * @param x1  left coordinate of the area
     * @param y1  top coordinate of the area
     * @param x2  right coordinate of the area
     * @param y2  bottom coordinate of the area
     * @see lv_area_set
     */
    void set(int32_t x1, int32_t y1, int32_t x2, int32_t y2) noexcept;
    /**
     * Set the height of an area
     * @param h  the new height of the area (h == 1 makes y1 == y2)
     * @see lv_area_set_height
     */
    void set_height(int32_t h) noexcept;
    /**
     * Set the width of an area
     * @param w  the new width of the area (w == 1 makes x1 == x2)
     * @see lv_area_set_width
     */
    void set_width(int32_t w) noexcept;
};
static_assert(sizeof(Area) == sizeof(lv_area_t));

class Color {
public:
    lv_color_t v;

public:
    constexpr lv_color_t raw() const noexcept { return v; }
    constexpr const lv_color_t* ptr() const noexcept { return &v; }
    constexpr lv_color_t* ptr() noexcept { return &v; }

    constexpr uint8_t blue() const noexcept;
    constexpr uint8_t green() const noexcept;
    constexpr uint8_t red() const noexcept;
    /**
     * Create a color from 0x000000..0xffffff input
     * @param c  the hex input
     * @return the color
     * @see lv_color_hex
     */
    static Color hex(uint32_t c) noexcept;
    /**
     * Create an RGB888 color
     * @param r  the red channel (0..255)
     * @param g  the green channel (0..255)
     * @param b  the blue channel (0..255)
     * @return the color
     * @see lv_color_make
     */
    static Color make(uint8_t r, uint8_t g, uint8_t b) noexcept;
    /**
     * Create a color from 0x000..0xfff input
     * @param c  the hex input (e.g. 0x123 will be 0x112233)
     * @return the color
     * @see lv_color_hex3
     */
    static Color hex3(uint32_t c) noexcept;
    /**
     * Mix white to a color
     * @param c  the base color
     * @param lvl  the intensity of white (0: no change, 255: fully white)
     * @return the mixed color
     * @see lv_color_lighten
     */
    static Color lighten(Color c, lv_opa_t lvl) noexcept;
    /**
     * Mix black to a color
     * @param c  the base color
     * @param lvl  the intensity of black (0: no change, 255: fully black)
     * @return the mixed color
     * @see lv_color_darken
     */
    static Color darken(Color c, lv_opa_t lvl) noexcept;
    /**
     * A helper for white color
     * @return a white color
     * @see lv_color_white
     */
    static Color white() noexcept;
    /**
     * A helper for black color
     * @return a black color
     * @see lv_color_black
     */
    static Color black() noexcept;
    /**
     * Mix two colors with a given ratio.
     * @param c1  the first color to mix (usually the foreground)
     * @param c2  the second color to mix (usually the background)
     * @param mix  The ratio of the colors. 0: full `c2`, 255: full `c1`, 127: half `c1` and half`c2`
     * @return the mixed color
     * @see lv_color_mix
     */
    static Color mix(Color c1, Color c2, uint8_t mix) noexcept;
};
static_assert(sizeof(Color) == sizeof(lv_color_t));

/** Represents a point on the screen. */
class Point {
public:
    lv_point_t v;

public:
    constexpr lv_point_t raw() const noexcept { return v; }
    constexpr const lv_point_t* ptr() const noexcept { return &v; }
    constexpr lv_point_t* ptr() noexcept { return &v; }

    constexpr int32_t x() const noexcept;
    constexpr int32_t y() const noexcept;
    /** @see lv_point_from_precise */
    static Point from_precise(PointPrecise p) noexcept;
    /**
     * Transform an array of points
     * @param count  number of points in the array
     * @param angle  angle with 0.1 resolutions (123 means 12.3°)
     * @param scale_x  horizontal zoom, 256 means 100%
     * @param scale_y  vertical zoom, 256 means 100%
     * @param pivot  pointer to the pivot point of the transformation
     * @param zoom_first  true: zoom first and rotate after that; else: opposite order
     * @see lv_point_array_transform
     */
    void array_transform(size_t count, int32_t angle, int32_t scale_x, int32_t scale_y, const Point& pivot, bool zoom_first) noexcept;
    /** @see lv_point_set */
    void set(int32_t x, int32_t y) noexcept;
    /** @see lv_point_swap */
    void swap(Point& p2) noexcept;
    /** @see lv_point_to_precise */
    lv_point_precise_t to_precise() const noexcept;
    /**
     * Transform a point
     * @param angle  angle with 0.1 resolutions (123 means 12.3°)
     * @param scale_x  horizontal zoom, 256 means 100%
     * @param scale_y  vertical zoom, 256 means 100%
     * @param pivot  pointer to the pivot point of the transformation
     * @param zoom_first  true: zoom first and rotate after that; else: opposite order
     * @see lv_point_transform
     */
    void transform(int32_t angle, int32_t scale_x, int32_t scale_y, const Point& pivot, bool zoom_first) noexcept;
};
static_assert(sizeof(Point) == sizeof(lv_point_t));

#if LV_USE_GRID
/**
 * A int32_t array LVGL keeps the address of and reads until it
 * finds LV_GRID_TEMPLATE_LAST. Both hazards are the type's: the sentinel is
 * written by the constructor, and the copy constructor is deleted so the array
 * cannot be a temporary. `constexpr`, so it lands in .rodata where the C's
 * mutable `static int32_t dsc[]` lands in .data.
 */
template <std::size_t N>
class GridTemplate {
    int32_t v_[N + 1];

public:
    template <class... A>
    constexpr explicit GridTemplate(A... a) noexcept
        : v_{static_cast<int32_t>(a)..., static_cast<int32_t>(LV_GRID_TEMPLATE_LAST)} {
        static_assert(sizeof...(A) == N);
    }

    GridTemplate(const GridTemplate&) = delete;
    GridTemplate& operator=(const GridTemplate&) = delete;

    constexpr const int32_t* raw() const noexcept { return v_; }
    static constexpr std::size_t size() noexcept { return N; }
};

template <class... A> GridTemplate(A...) -> GridTemplate<sizeof...(A)>;
#endif // LV_USE_GRID

namespace detail {

/**
 * The allocator seam. Named from the model because the two versions spell it
 * differently, and routed through the library's own allocator because an
 * allocation outside its pool is invisible to the budget the consumer is counting.
 */
inline void* alloc(size_t n) noexcept { return lv_malloc(n); }
inline void  release(void* p) noexcept { lv_free(p); }

} // namespace detail

namespace detail {

// The closure trampolines, declared. Their bodies name handles by value,
// so they are defined once every class is complete -- see closures.hpp.
template <auto Fn> struct AnimExecXcbThunk;
#if LV_USE_EXT_DATA
template <auto Fn> struct EventDescSetExternalDataThunk;
#endif
#if LV_USE_EXT_DATA
template <auto Fn> struct AnimSetExternalDataThunk;
#endif
#if LV_USE_EXT_DATA
template <auto Fn> struct DisplaySetExternalDataThunk;
#endif
template <auto Fn> struct DrawBufFreeCbThunk;
template <auto Fn> struct DrawBufAlignCbThunk;
#if LV_USE_EXT_DATA
template <auto Fn> struct GroupSetExternalDataThunk;
#endif
#if LV_USE_EXT_DATA
template <auto Fn> struct IndevSetExternalDataThunk;
#endif
template <auto Fn> struct IterNextCbThunk;
template <auto Fn> struct IterInspectCbThunk;
template <auto Fn> struct LlClearCustomThunk;
#if LV_USE_EXT_DATA
template <auto Fn> struct ObjSetExternalDataThunk;
#endif
#if LV_USE_OBSERVER && LV_USE_EXT_DATA
template <auto Fn> struct SubjectSetExternalDataThunk;
#endif
#if LV_USE_EXT_DATA
template <auto Fn> struct ThemeSetExternalDataThunk;
#endif
#if LV_USE_EXT_DATA
template <auto Fn> struct TimerSetExternalDataThunk;
#endif
template <class F, bool Stateless = std::is_empty_v<F>> struct ObjTreeWalkCbClosure;
#if LV_USE_IMGFONT
template <class F, bool Stateless = std::is_empty_v<F>> struct ImgfontGetPathCbClosure;
#endif
template <class F, bool Stateless = std::is_empty_v<F>> struct LayoutUpdateCbClosure;
template <class F, bool Stateless = std::is_empty_v<F>> struct AsyncCbClosure;
template <class F, bool Stateless = std::is_empty_v<F>> struct TimerHandlerResumeCbClosure;
template <class F, bool Stateless = std::is_empty_v<F>> struct TreeTraverseCbClosure;
template <class F, bool Stateless = std::is_empty_v<F>> struct CircleBufFillCbClosure;
#if LV_USE_OBSERVER
template <class F, bool Stateless = std::is_empty_v<F>> struct ObserverCbClosure;
#endif
template <class F, bool Stateless = std::is_empty_v<F>> struct TimerCbClosure;

} // namespace detail

// The tagged unions of the API, as one type per variant.
// Declared here because a class template is not forward
// declarable the way a class is, and every signature that
// names one needs it visible.
template <class T> class SubjectOf;

} // namespace lv
