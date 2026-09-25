#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/callable.hpp"
#include "lv/core.hpp"
#include "lv/core/obj.hpp"
#include "lv/core/observer.hpp"
#include "lv/enums.hpp"
#include "lv/font/font.hpp"
#include "lv/fwd.hpp"
#include "lv/misc/timer.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>
#include <type_traits>

namespace lv {

/**
 * The typed-setter thunks: what the C idiom does with a cast, done with a
 * conversion instead.
 */
namespace detail {

/**
 * A typed setter behind `lv_anim_exec_xcb_t`. The C idiom casts the function pointer,
 * which is undefined whenever the parameter types differ -- and between
 * the versions they do, from the identical source line.
 */
template <class A0, class A1, void (*Fn)(A0, A1)>
struct AnimExecXcbThunk<Fn> {
    static void call(void* a0, int32_t a1) noexcept {
        return static_cast<void>(Fn(static_cast<A0>(a0), static_cast<A1>(a1)));
    }
};

} // namespace detail

#if LV_USE_EXT_DATA
/**
 * The typed-setter thunks: what the C idiom does with a cast, done with a
 * conversion instead.
 */
namespace detail {

/**
 * A typed setter behind `void (void*)*`. The C idiom casts the function pointer,
 * which is undefined whenever the parameter types differ -- and between
 * the versions they do, from the identical source line.
 */
template <class A0, void (*Fn)(A0)>
struct EventDescSetExternalDataThunk<Fn> {
    static void call(void* a0) noexcept {
        return static_cast<void>(Fn(static_cast<A0>(a0)));
    }
};

} // namespace detail

/**
 * The typed-setter thunks: what the C idiom does with a cast, done with a
 * conversion instead.
 */
namespace detail {

/**
 * A typed setter behind `void (void*)*`. The C idiom casts the function pointer,
 * which is undefined whenever the parameter types differ -- and between
 * the versions they do, from the identical source line.
 */
template <class A0, void (*Fn)(A0)>
struct AnimSetExternalDataThunk<Fn> {
    static void call(void* a0) noexcept {
        return static_cast<void>(Fn(static_cast<A0>(a0)));
    }
};

} // namespace detail

/**
 * The typed-setter thunks: what the C idiom does with a cast, done with a
 * conversion instead.
 */
namespace detail {

/**
 * A typed setter behind `void (void*)*`. The C idiom casts the function pointer,
 * which is undefined whenever the parameter types differ -- and between
 * the versions they do, from the identical source line.
 */
template <class A0, void (*Fn)(A0)>
struct DisplaySetExternalDataThunk<Fn> {
    static void call(void* a0) noexcept {
        return static_cast<void>(Fn(static_cast<A0>(a0)));
    }
};

} // namespace detail
#endif // LV_USE_EXT_DATA

/**
 * The typed-setter thunks: what the C idiom does with a cast, done with a
 * conversion instead.
 */
namespace detail {

/**
 * A typed setter behind `lv_draw_buf_free_cb_t`. The C idiom casts the function pointer,
 * which is undefined whenever the parameter types differ -- and between
 * the versions they do, from the identical source line.
 */
template <class A0, void (*Fn)(A0)>
struct DrawBufFreeCbThunk<Fn> {
    static void call(void* a0) noexcept {
        return static_cast<void>(Fn(static_cast<A0>(a0)));
    }
};

} // namespace detail

/**
 * The typed-setter thunks: what the C idiom does with a cast, done with a
 * conversion instead.
 */
namespace detail {

/**
 * A typed setter behind `lv_draw_buf_align_cb_t`. The C idiom casts the function pointer,
 * which is undefined whenever the parameter types differ -- and between
 * the versions they do, from the identical source line.
 */
template <class A0, class A1, void* (*Fn)(A0, A1)>
struct DrawBufAlignCbThunk<Fn> {
    static void* call(void* a0, lv_color_format_t a1) noexcept {
        return static_cast<void*>(Fn(static_cast<A0>(a0), static_cast<A1>(a1)));
    }
};

} // namespace detail

#if LV_USE_EXT_DATA
/**
 * The typed-setter thunks: what the C idiom does with a cast, done with a
 * conversion instead.
 */
namespace detail {

/**
 * A typed setter behind `void (void*)*`. The C idiom casts the function pointer,
 * which is undefined whenever the parameter types differ -- and between
 * the versions they do, from the identical source line.
 */
template <class A0, void (*Fn)(A0)>
struct GroupSetExternalDataThunk<Fn> {
    static void call(void* a0) noexcept {
        return static_cast<void>(Fn(static_cast<A0>(a0)));
    }
};

} // namespace detail

/**
 * The typed-setter thunks: what the C idiom does with a cast, done with a
 * conversion instead.
 */
namespace detail {

/**
 * A typed setter behind `void (void*)*`. The C idiom casts the function pointer,
 * which is undefined whenever the parameter types differ -- and between
 * the versions they do, from the identical source line.
 */
template <class A0, void (*Fn)(A0)>
struct IndevSetExternalDataThunk<Fn> {
    static void call(void* a0) noexcept {
        return static_cast<void>(Fn(static_cast<A0>(a0)));
    }
};

} // namespace detail
#endif // LV_USE_EXT_DATA

/**
 * The typed-setter thunks: what the C idiom does with a cast, done with a
 * conversion instead.
 */
namespace detail {

/**
 * A typed setter behind `lv_iter_next_cb`. The C idiom casts the function pointer,
 * which is undefined whenever the parameter types differ -- and between
 * the versions they do, from the identical source line.
 */
template <class A0, class A1, class A2, lv_result_t (*Fn)(A0, A1, A2)>
struct IterNextCbThunk<Fn> {
    static lv_result_t call(void* a0, void* a1, void* a2) noexcept {
        return static_cast<lv_result_t>(Fn(static_cast<A0>(a0), static_cast<A1>(a1), static_cast<A2>(a2)));
    }
};

} // namespace detail

/**
 * The typed-setter thunks: what the C idiom does with a cast, done with a
 * conversion instead.
 */
namespace detail {

/**
 * A typed setter behind `lv_iter_inspect_cb`. The C idiom casts the function pointer,
 * which is undefined whenever the parameter types differ -- and between
 * the versions they do, from the identical source line.
 */
template <class A0, void (*Fn)(A0)>
struct IterInspectCbThunk<Fn> {
    static void call(void* a0) noexcept {
        return static_cast<void>(Fn(static_cast<A0>(a0)));
    }
};

} // namespace detail

/**
 * The typed-setter thunks: what the C idiom does with a cast, done with a
 * conversion instead.
 */
namespace detail {

/**
 * A typed setter behind `void (void*)*`. The C idiom casts the function pointer,
 * which is undefined whenever the parameter types differ -- and between
 * the versions they do, from the identical source line.
 */
template <class A0, void (*Fn)(A0)>
struct LlClearCustomThunk<Fn> {
    static void call(void* a0) noexcept {
        return static_cast<void>(Fn(static_cast<A0>(a0)));
    }
};

} // namespace detail

#if LV_USE_EXT_DATA
/**
 * The typed-setter thunks: what the C idiom does with a cast, done with a
 * conversion instead.
 */
namespace detail {

/**
 * A typed setter behind `void (void*)*`. The C idiom casts the function pointer,
 * which is undefined whenever the parameter types differ -- and between
 * the versions they do, from the identical source line.
 */
template <class A0, void (*Fn)(A0)>
struct ObjSetExternalDataThunk<Fn> {
    static void call(void* a0) noexcept {
        return static_cast<void>(Fn(static_cast<A0>(a0)));
    }
};

} // namespace detail
#endif // LV_USE_EXT_DATA

#if (LV_USE_OBSERVER) && (LV_USE_EXT_DATA)
/**
 * The typed-setter thunks: what the C idiom does with a cast, done with a
 * conversion instead.
 */
namespace detail {

/**
 * A typed setter behind `void (void*)*`. The C idiom casts the function pointer,
 * which is undefined whenever the parameter types differ -- and between
 * the versions they do, from the identical source line.
 */
template <class A0, void (*Fn)(A0)>
struct SubjectSetExternalDataThunk<Fn> {
    static void call(void* a0) noexcept {
        return static_cast<void>(Fn(static_cast<A0>(a0)));
    }
};

} // namespace detail
#endif // (LV_USE_OBSERVER) && (LV_USE_EXT_DATA)

#if LV_USE_EXT_DATA
/**
 * The typed-setter thunks: what the C idiom does with a cast, done with a
 * conversion instead.
 */
namespace detail {

/**
 * A typed setter behind `void (void*)*`. The C idiom casts the function pointer,
 * which is undefined whenever the parameter types differ -- and between
 * the versions they do, from the identical source line.
 */
template <class A0, void (*Fn)(A0)>
struct ThemeSetExternalDataThunk<Fn> {
    static void call(void* a0) noexcept {
        return static_cast<void>(Fn(static_cast<A0>(a0)));
    }
};

} // namespace detail

/**
 * The typed-setter thunks: what the C idiom does with a cast, done with a
 * conversion instead.
 */
namespace detail {

/**
 * A typed setter behind `void (void*)*`. The C idiom casts the function pointer,
 * which is undefined whenever the parameter types differ -- and between
 * the versions they do, from the identical source line.
 */
template <class A0, void (*Fn)(A0)>
struct TimerSetExternalDataThunk<Fn> {
    static void call(void* a0) noexcept {
        return static_cast<void>(Fn(static_cast<A0>(a0)));
    }
};

} // namespace detail
#endif // LV_USE_EXT_DATA

/**
 * One trampoline per callback type: a static function of the right C
 * signature, and the two halves of the call the wrapper makes.
 */
namespace detail {

/** The state slot of `lv_obj_tree_walk_cb_t`, recovered as `a1`. */
template <class F>
struct ObjTreeWalkCbClosure<F, true> {
    using D = F;
    static_assert(std::is_invocable_v<D&, Obj> || std::is_invocable_v<D&>,
            "lv: this callable does not match the callback's parameters.");
    static lv_obj_tree_walk_res_t call(lv_obj_t* a0, void* a1) noexcept {
        (void)a0; (void)a1;
        D f{};
        if constexpr (std::is_invocable_v<D&, Obj>) return static_cast<lv_obj_tree_walk_res_t>(f(Obj(a0)));
        else return static_cast<lv_obj_tree_walk_res_t>(f());
    }
    /**
     * `auto`, because the callback type is not always a NAME: v9 declares one
     * registration whose parameter is a bare `void (*)(void*)`, and there is no
     * way to write that as the return type of a function taking arguments.
     */
    static auto fn(const F&) noexcept { return &call; }
    /** Nothing to carry: a captureless callable is rebuilt from its type. */
    static void* state(const F&) noexcept { return nullptr; }
};

template <class F>
struct ObjTreeWalkCbClosure<F, false> {
    using D = F;
    static_assert(fits_user_data<D>,
            "lv: this callable does not fit in the single void* LVGL stores. "
            "Capture one handle, or keep the state in an object you own.");
    static_assert(std::is_invocable_v<D&, Obj> || std::is_invocable_v<D&>,
            "lv: this callable does not match the callback's parameters.");
    static lv_obj_tree_walk_res_t call(lv_obj_t* a0, void* a1) noexcept {
        (void)a0; (void)a1;
        D f = unpack<D>(a1);
        if constexpr (std::is_invocable_v<D&, Obj>) return static_cast<lv_obj_tree_walk_res_t>(f(Obj(a0)));
        else return static_cast<lv_obj_tree_walk_res_t>(f());
    }
    static auto fn(const F&) noexcept { return &call; }
    static void* state(const F& f) noexcept { return pack(f); }
};

} // namespace detail

#if LV_USE_IMGFONT
/**
 * One trampoline per callback type: a static function of the right C
 * signature, and the two halves of the call the wrapper makes.
 */
namespace detail {

/** The state slot of `lv_imgfont_get_path_cb_t`, recovered as `a4`. */
template <class F>
struct ImgfontGetPathCbClosure<F, true> {
    using D = F;
    static_assert(std::is_invocable_v<D&, Font, uint32_t, uint32_t, int32_t*> || std::is_invocable_v<D&>,
            "lv: this callable does not match the callback's parameters.");
    static const void* call(const lv_font_t* a0, uint32_t a1, uint32_t a2, int32_t* a3, void* a4) noexcept {
        (void)a0; (void)a1; (void)a2; (void)a3; (void)a4;
        D f{};
        if constexpr (std::is_invocable_v<D&, Font, uint32_t, uint32_t, int32_t*>) return static_cast<const void*>(f(Font(a0), a1, a2, a3));
        else return static_cast<const void*>(f());
    }
    /**
     * `auto`, because the callback type is not always a NAME: v9 declares one
     * registration whose parameter is a bare `void (*)(void*)`, and there is no
     * way to write that as the return type of a function taking arguments.
     */
    static auto fn(const F&) noexcept { return &call; }
    /** Nothing to carry: a captureless callable is rebuilt from its type. */
    static void* state(const F&) noexcept { return nullptr; }
};

template <class F>
struct ImgfontGetPathCbClosure<F, false> {
    using D = F;
    static_assert(fits_user_data<D>,
            "lv: this callable does not fit in the single void* LVGL stores. "
            "Capture one handle, or keep the state in an object you own.");
    static_assert(std::is_invocable_v<D&, Font, uint32_t, uint32_t, int32_t*> || std::is_invocable_v<D&>,
            "lv: this callable does not match the callback's parameters.");
    static const void* call(const lv_font_t* a0, uint32_t a1, uint32_t a2, int32_t* a3, void* a4) noexcept {
        (void)a0; (void)a1; (void)a2; (void)a3; (void)a4;
        D f = unpack<D>(a4);
        if constexpr (std::is_invocable_v<D&, Font, uint32_t, uint32_t, int32_t*>) return static_cast<const void*>(f(Font(a0), a1, a2, a3));
        else return static_cast<const void*>(f());
    }
    static auto fn(const F&) noexcept { return &call; }
    static void* state(const F& f) noexcept { return pack(f); }
};

} // namespace detail
#endif // LV_USE_IMGFONT

/**
 * One trampoline per callback type: a static function of the right C
 * signature, and the two halves of the call the wrapper makes.
 */
namespace detail {

/** The state slot of `lv_layout_update_cb_t`, recovered as `a1`. */
template <class F>
struct LayoutUpdateCbClosure<F, true> {
    using D = F;
    static_assert(std::is_invocable_v<D&, Obj> || std::is_invocable_v<D&>,
            "lv: this callable does not match the callback's parameters.");
    static void call(lv_obj_t* a0, void* a1) noexcept {
        (void)a0; (void)a1;
        D f{};
        if constexpr (std::is_invocable_v<D&, Obj>) return static_cast<void>(f(Obj(a0)));
        else return static_cast<void>(f());
    }
    /**
     * `auto`, because the callback type is not always a NAME: v9 declares one
     * registration whose parameter is a bare `void (*)(void*)`, and there is no
     * way to write that as the return type of a function taking arguments.
     */
    static auto fn(const F&) noexcept { return &call; }
    /** Nothing to carry: a captureless callable is rebuilt from its type. */
    static void* state(const F&) noexcept { return nullptr; }
};

template <class F>
struct LayoutUpdateCbClosure<F, false> {
    using D = F;
    static_assert(fits_user_data<D>,
            "lv: this callable does not fit in the single void* LVGL stores. "
            "Capture one handle, or keep the state in an object you own.");
    static_assert(std::is_invocable_v<D&, Obj> || std::is_invocable_v<D&>,
            "lv: this callable does not match the callback's parameters.");
    static void call(lv_obj_t* a0, void* a1) noexcept {
        (void)a0; (void)a1;
        D f = unpack<D>(a1);
        if constexpr (std::is_invocable_v<D&, Obj>) return static_cast<void>(f(Obj(a0)));
        else return static_cast<void>(f());
    }
    static auto fn(const F&) noexcept { return &call; }
    static void* state(const F& f) noexcept { return pack(f); }
};

} // namespace detail

/**
 * One trampoline per callback type: a static function of the right C
 * signature, and the two halves of the call the wrapper makes.
 */
namespace detail {

/** The state slot of `lv_async_cb_t`, recovered as `a0`. */
template <class F>
struct AsyncCbClosure<F, true> {
    using D = F;
    static_assert(std::is_invocable_v<D&>,
            "lv: this callable does not match the callback's parameters.");
    static void call(void* a0) noexcept {
        (void)a0;
        D f{};
        return static_cast<void>(f());
    }
    /**
     * `auto`, because the callback type is not always a NAME: v9 declares one
     * registration whose parameter is a bare `void (*)(void*)`, and there is no
     * way to write that as the return type of a function taking arguments.
     */
    static auto fn(const F&) noexcept { return &call; }
    /** Nothing to carry: a captureless callable is rebuilt from its type. */
    static void* state(const F&) noexcept { return nullptr; }
};

template <class F>
struct AsyncCbClosure<F, false> {
    using D = F;
    static_assert(fits_user_data<D>,
            "lv: this callable does not fit in the single void* LVGL stores. "
            "Capture one handle, or keep the state in an object you own.");
    static_assert(std::is_invocable_v<D&>,
            "lv: this callable does not match the callback's parameters.");
    static void call(void* a0) noexcept {
        (void)a0;
        D f = unpack<D>(a0);
        return static_cast<void>(f());
    }
    static auto fn(const F&) noexcept { return &call; }
    static void* state(const F& f) noexcept { return pack(f); }
};

} // namespace detail

/**
 * One trampoline per callback type: a static function of the right C
 * signature, and the two halves of the call the wrapper makes.
 */
namespace detail {

/** The state slot of `lv_timer_handler_resume_cb_t`, recovered as `a0`. */
template <class F>
struct TimerHandlerResumeCbClosure<F, true> {
    using D = F;
    static_assert(std::is_invocable_v<D&>,
            "lv: this callable does not match the callback's parameters.");
    static void call(void* a0) noexcept {
        (void)a0;
        D f{};
        return static_cast<void>(f());
    }
    /**
     * `auto`, because the callback type is not always a NAME: v9 declares one
     * registration whose parameter is a bare `void (*)(void*)`, and there is no
     * way to write that as the return type of a function taking arguments.
     */
    static auto fn(const F&) noexcept { return &call; }
    /** Nothing to carry: a captureless callable is rebuilt from its type. */
    static void* state(const F&) noexcept { return nullptr; }
};

template <class F>
struct TimerHandlerResumeCbClosure<F, false> {
    using D = F;
    static_assert(fits_user_data<D>,
            "lv: this callable does not fit in the single void* LVGL stores. "
            "Capture one handle, or keep the state in an object you own.");
    static_assert(std::is_invocable_v<D&>,
            "lv: this callable does not match the callback's parameters.");
    static void call(void* a0) noexcept {
        (void)a0;
        D f = unpack<D>(a0);
        return static_cast<void>(f());
    }
    static auto fn(const F&) noexcept { return &call; }
    static void* state(const F& f) noexcept { return pack(f); }
};

} // namespace detail

/**
 * One trampoline per callback type: a static function of the right C
 * signature, and the two halves of the call the wrapper makes.
 */
namespace detail {

/** The state slot of `lv_tree_traverse_cb_t`, recovered as `a1`. */
template <class F>
struct TreeTraverseCbClosure<F, true> {
    using D = F;
    static_assert(std::is_invocable_v<D&, TreeNode> || std::is_invocable_v<D&>,
            "lv: this callable does not match the callback's parameters.");
    static _Bool call(const lv_tree_node_t* a0, void* a1) noexcept {
        (void)a0; (void)a1;
        D f{};
        if constexpr (std::is_invocable_v<D&, TreeNode>) return static_cast<_Bool>(f(TreeNode(a0)));
        else return static_cast<_Bool>(f());
    }
    /**
     * `auto`, because the callback type is not always a NAME: v9 declares one
     * registration whose parameter is a bare `void (*)(void*)`, and there is no
     * way to write that as the return type of a function taking arguments.
     */
    static auto fn(const F&) noexcept { return &call; }
    /** Nothing to carry: a captureless callable is rebuilt from its type. */
    static void* state(const F&) noexcept { return nullptr; }
};

template <class F>
struct TreeTraverseCbClosure<F, false> {
    using D = F;
    static_assert(fits_user_data<D>,
            "lv: this callable does not fit in the single void* LVGL stores. "
            "Capture one handle, or keep the state in an object you own.");
    static_assert(std::is_invocable_v<D&, TreeNode> || std::is_invocable_v<D&>,
            "lv: this callable does not match the callback's parameters.");
    static _Bool call(const lv_tree_node_t* a0, void* a1) noexcept {
        (void)a0; (void)a1;
        D f = unpack<D>(a1);
        if constexpr (std::is_invocable_v<D&, TreeNode>) return static_cast<_Bool>(f(TreeNode(a0)));
        else return static_cast<_Bool>(f());
    }
    static auto fn(const F&) noexcept { return &call; }
    static void* state(const F& f) noexcept { return pack(f); }
};

} // namespace detail

/**
 * One trampoline per callback type: a static function of the right C
 * signature, and the two halves of the call the wrapper makes.
 */
namespace detail {

/** The state slot of `lv_circle_buf_fill_cb_t`, recovered as `a3`. */
template <class F>
struct CircleBufFillCbClosure<F, true> {
    using D = F;
    static_assert(std::is_invocable_v<D&, void*, uint32_t, int32_t> || std::is_invocable_v<D&>,
            "lv: this callable does not match the callback's parameters.");
    static _Bool call(void* a0, uint32_t a1, int32_t a2, void* a3) noexcept {
        (void)a0; (void)a1; (void)a2; (void)a3;
        D f{};
        if constexpr (std::is_invocable_v<D&, void*, uint32_t, int32_t>) return static_cast<_Bool>(f(a0, a1, a2));
        else return static_cast<_Bool>(f());
    }
    /**
     * `auto`, because the callback type is not always a NAME: v9 declares one
     * registration whose parameter is a bare `void (*)(void*)`, and there is no
     * way to write that as the return type of a function taking arguments.
     */
    static auto fn(const F&) noexcept { return &call; }
    /** Nothing to carry: a captureless callable is rebuilt from its type. */
    static void* state(const F&) noexcept { return nullptr; }
};

template <class F>
struct CircleBufFillCbClosure<F, false> {
    using D = F;
    static_assert(fits_user_data<D>,
            "lv: this callable does not fit in the single void* LVGL stores. "
            "Capture one handle, or keep the state in an object you own.");
    static_assert(std::is_invocable_v<D&, void*, uint32_t, int32_t> || std::is_invocable_v<D&>,
            "lv: this callable does not match the callback's parameters.");
    static _Bool call(void* a0, uint32_t a1, int32_t a2, void* a3) noexcept {
        (void)a0; (void)a1; (void)a2; (void)a3;
        D f = unpack<D>(a3);
        if constexpr (std::is_invocable_v<D&, void*, uint32_t, int32_t>) return static_cast<_Bool>(f(a0, a1, a2));
        else return static_cast<_Bool>(f());
    }
    static auto fn(const F&) noexcept { return &call; }
    static void* state(const F& f) noexcept { return pack(f); }
};

} // namespace detail

#if LV_USE_OBSERVER
/**
 * One trampoline per callback type: a static function of the right C
 * signature, and the two halves of the call the wrapper makes.
 */
namespace detail {

/** The state slot of `lv_observer_cb_t`, recovered as `lv_observer_get_user_data(a0)`. */
template <class F>
struct ObserverCbClosure<F, true> {
    using D = F;
    static_assert(std::is_invocable_v<D&, Observer, lv_subject_t*> || std::is_invocable_v<D&>,
            "lv: this callable does not match the callback's parameters.");
    static void call(lv_observer_t* a0, lv_subject_t* a1) noexcept {
        (void)a0; (void)a1;
        D f{};
        if constexpr (std::is_invocable_v<D&, Observer, lv_subject_t*>) return static_cast<void>(f(Observer(a0), a1));
        else return static_cast<void>(f());
    }
    /**
     * `auto`, because the callback type is not always a NAME: v9 declares one
     * registration whose parameter is a bare `void (*)(void*)`, and there is no
     * way to write that as the return type of a function taking arguments.
     */
    static auto fn(const F&) noexcept { return &call; }
    /** Nothing to carry: a captureless callable is rebuilt from its type. */
    static void* state(const F&) noexcept { return nullptr; }
};

template <class F>
struct ObserverCbClosure<F, false> {
    using D = F;
    static_assert(fits_user_data<D>,
            "lv: this callable does not fit in the single void* LVGL stores. "
            "Capture one handle, or keep the state in an object you own.");
    static_assert(std::is_invocable_v<D&, Observer, lv_subject_t*> || std::is_invocable_v<D&>,
            "lv: this callable does not match the callback's parameters.");
    static void call(lv_observer_t* a0, lv_subject_t* a1) noexcept {
        (void)a0; (void)a1;
        D f = unpack<D>(lv_observer_get_user_data(a0));
        if constexpr (std::is_invocable_v<D&, Observer, lv_subject_t*>) return static_cast<void>(f(Observer(a0), a1));
        else return static_cast<void>(f());
    }
    static auto fn(const F&) noexcept { return &call; }
    static void* state(const F& f) noexcept { return pack(f); }
};

} // namespace detail
#endif // LV_USE_OBSERVER

/**
 * One trampoline per callback type: a static function of the right C
 * signature, and the two halves of the call the wrapper makes.
 */
namespace detail {

/** The state slot of `lv_timer_cb_t`, recovered as `lv_timer_get_user_data(a0)`. */
template <class F>
struct TimerCbClosure<F, true> {
    using D = F;
    static_assert(std::is_invocable_v<D&, Timer> || std::is_invocable_v<D&>,
            "lv: this callable does not match the callback's parameters.");
    static void call(lv_timer_t* a0) noexcept {
        (void)a0;
        D f{};
        if constexpr (std::is_invocable_v<D&, Timer>) return static_cast<void>(f(Timer(a0)));
        else return static_cast<void>(f());
    }
    /**
     * `auto`, because the callback type is not always a NAME: v9 declares one
     * registration whose parameter is a bare `void (*)(void*)`, and there is no
     * way to write that as the return type of a function taking arguments.
     */
    static auto fn(const F&) noexcept { return &call; }
    /** Nothing to carry: a captureless callable is rebuilt from its type. */
    static void* state(const F&) noexcept { return nullptr; }
};

template <class F>
struct TimerCbClosure<F, false> {
    using D = F;
    static_assert(fits_user_data<D>,
            "lv: this callable does not fit in the single void* LVGL stores. "
            "Capture one handle, or keep the state in an object you own.");
    static_assert(std::is_invocable_v<D&, Timer> || std::is_invocable_v<D&>,
            "lv: this callable does not match the callback's parameters.");
    static void call(lv_timer_t* a0) noexcept {
        (void)a0;
        D f = unpack<D>(lv_timer_get_user_data(a0));
        if constexpr (std::is_invocable_v<D&, Timer>) return static_cast<void>(f(Timer(a0)));
        else return static_cast<void>(f());
    }
    static auto fn(const F&) noexcept { return &call; }
    static void* state(const F& f) noexcept { return pack(f); }
};

} // namespace detail

} // namespace lv
