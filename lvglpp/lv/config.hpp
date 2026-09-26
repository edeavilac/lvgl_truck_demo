#pragma once
//
// PRELUDE -- copied verbatim by the generator (D-C6), versioned with the generator and not with
// LVGL. Nothing here is derived from a term, because there is no term to derive it from: it is
// how the binding talks about itself.
//
// If a file under prelude/ ever needs a substitution it is not prelude, it is a template, and
// D-C1 says there are none.

#include "lvgl.h"

/**
 * Which object model this binding was generated with. Exposed because it changes what a consumer
 * may write: a CRTP variant would define LVPP_OBJECT_MODEL_CRTP instead, and D-02 chose this one
 * by building both and measuring -- the -Os objects are byte-identical, and the difference is
 * compile time and debug builds.
 */
#define LVPP_OBJECT_MODEL_PLAIN 1

// The binding's own assertions guard against BINDING misuse (a bad downcast), so they follow
// NDEBUG rather than LVGL's LV_USE_ASSERT_* knobs, which govern LVGL's internal checks. Keying
// them off LV_ASSERT alone was measured to leave two lv_obj_has_class calls in a release build.
#ifndef LVPP_ASSERT
#  ifdef NDEBUG
#    define LVPP_ASSERT(cond, msg) ((void)0)
#  else
#    define LVPP_ASSERT(cond, msg) LV_ASSERT_MSG(cond, msg)
#  endif
#endif
