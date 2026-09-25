#pragma once
// GENERATED. Do not edit: the source of truth is the neutral model, and the
// spelling is decided in generator/cpp/ (plan-generacion-cpp.md).

#include "lv/enums.hpp"
#include "lv/fwd.hpp"
#include "lv/types.hpp"
#include "lvgl.h"
#include <cstdint>

namespace lv {

#if LV_USE_TEST && defined(LV_USE_TEST_SCREENSHOT_COMPARE) && LV_USE_TEST_SCREENSHOT_COMPARE
/**
 * Compare the current content of the test screen with a reference PNG image
 * - If the reference image is not found it will be created automatically from the rendered screen.
 * - If the compare fails an `<image_name>_err.png` file will be created with the rendered content next to the reference image.
 * It requires lodepng.
 * @param fn_ref  path to the reference image. Will be appended to REF_IMGS_PATH if set.
 * @return An element of `lv_test_screenshot_result_t`
 * @see lv_test_screenshot_compare
 */
inline TestScreenshotResult test_screenshot_compare(const char* fn_ref) noexcept { return static_cast<TestScreenshotResult>(lv_test_screenshot_compare(fn_ref)); }
#endif // LV_USE_TEST && defined(LV_USE_TEST_SCREENSHOT_COMPARE) && LV_USE_TEST_SCREENSHOT_COMPARE

} // namespace lv
