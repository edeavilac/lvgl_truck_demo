/**
 * @file lv_demo_truck.hpp
 *
 */

#pragma once

/*********************
 *      INCLUDES
 *********************/

#include "lv/lvgl.hpp"

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Build the truck demo on the active screen.
 * @param assets_path  directory holding lv_truck.glb and lvgl_logo_with_text.glb
 * @return             the glTF viewer the demo draws into
 */
lv::Obj lv_demo_truck(const char * assets_path);
