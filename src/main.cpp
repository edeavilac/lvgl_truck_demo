#include <lv_demo_truck/lv_demo_truck.hpp>

#include <cstdint>
#include <unistd.h>

/*
 * The display and input drivers are not part of the binding -- the generator's profile excludes
 * the whole of src/drivers, which drags in platform headers -- so they are called in C, and what
 * they return is wrapped straight away: from there on it is an lv::Display or an lv::Indev like
 * any other.
 */

namespace {

lv::Display init_drm();
lv::Display init_sdl();
lv::Display init_wayland();
lv::Result init_evdev(lv::Display disp);
void discovery_cb(lv_indev_t * indev, lv_evdev_type_t type, void * user_data);

struct Backend {
    const char * name;
    lv::Display (*init)();
};

constexpr Backend backends[] = {
    {"drm",     init_drm},
    {"wayland", init_wayland},
    {"sdl",     init_sdl},
};

} // namespace

int main(int argc, const char ** argv)
{
    const char * ui_assets_path = "ui/assets";
    if(argc < 2) {
        LV_LOG_WARN("Assets Path not set, assuming `ui/assets`");
    }
    else {
        ui_assets_path = argv[1];
    }
    LV_LOG_USER("Assets path is %s", ui_assets_path);

    lv::init();
    lv::Display display;
    for(const Backend & backend : backends) {
        display = backend.init();
        if(!display) {
            LV_LOG_WARN("Failed to init '%s' backend", backend.name);
            continue;
        }
        break;
    }
    if(!display) {
        LV_LOG_ERROR("Failed to create a LVGL display");
        return 1;
    }

    lv_demo_truck(ui_assets_path);

    while(true) {
        uint32_t ms = lv::timer_handler();
        if(ms == LV_NO_TIMER_READY) {
            ms = LV_DEF_REFR_PERIOD;
        }
        usleep(ms * 1000);
    }
    lv::deinit();
}

namespace {

lv::Display init_sdl()
{
#if !LV_USE_SDL
    return lv::Display();
#else
    lv::Display disp(lv_sdl_window_create(1920, 1080));
    lv::Indev mouse(lv_sdl_mouse_create());
    mouse.set_group(lv::group_get_default());
    return disp;
#endif
}

lv::Display init_drm()
{
    char * device = lv_linux_drm_find_device_path();
    lv::Display disp(lv_linux_drm_create());

    if(!disp) {
        LV_LOG_WARN("lv_linux_drm_create failed");
        return lv::Display();
    }

    lv_result_t res = lv_linux_drm_set_file(disp.raw(), device, -1);
    lv::mem_free(device);
    if(res != LV_RESULT_OK) {
        disp.delete_();
        LV_LOG_WARN("lv_linux_drm_set_file failed");
        return lv::Display();
    }
    if(init_evdev(disp) != lv::Result::Ok) {
        LV_LOG_WARN("Failed to initialize evdev");
    }
    LV_LOG_USER("DRM initialized");
    return disp;
}

lv::Display init_wayland()
{
    /* The driver takes the title as `char *`, which a string literal is not in C++. */
    static char title[] = "Renesas Oven 3D Demo";
    lv::Display disp(lv_wayland_window_create(1280, 720, title, NULL));
    if(!disp) {
        LV_LOG_WARN("lv_wayland_window_create failed");
    }
    LV_LOG_USER("Wayland initialized");
    return disp;
}

lv::Result init_evdev(lv::Display disp)
{
    return static_cast<lv::Result>(lv_evdev_discovery_start(discovery_cb, disp.raw()));
}

void discovery_cb(lv_indev_t * indev, lv_evdev_type_t type, void * user_data)
{
    LV_LOG_USER("new '%s' device discovered", type == LV_EVDEV_TYPE_REL ? "REL" :
                type == LV_EVDEV_TYPE_ABS ? "ABS" :
                type == LV_EVDEV_TYPE_KEY ? "KEY" :
                "unknown");

    lv::Indev(indev).set_display(static_cast<lv_display_t *>(user_data));
}

} // namespace
