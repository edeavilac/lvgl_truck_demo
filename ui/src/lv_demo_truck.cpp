/**
 * @file lv_demo_truck.cpp
 *
 * The truck demo on lvglpp: the C++ binding cpp-binding generates for the LVGL in lvgl/.
 *
 * A port, not a redesign. The panels, sizes, colours and animation maths are the C original's and
 * the file keeps its order, so the two read side by side. What changes is what the binding takes
 * off the call site:
 *
 *  - a handle is a type: `lv::Slider` has `get_value()`, and a `lv::Obj` does not pretend to;
 *  - a style is a chain on one selector instead of one call per property;
 *  - an event handler is a lambda that carries its own state -- one pointer, stored in the
 *    registration's user_data -- so the C original's 32 event callbacks and their
 *    `lv_event_get_user_data` casts are gone;
 *  - an animation is an `lv::Anim` the controller owns, and its exec callback is set with
 *    `set_exec_cb<&fn>()`, which takes the controller typed and converts the `void *` LVGL hands
 *    back in one place -- the C idiom casts the function pointer at every call site, which is
 *    undefined behaviour whenever the parameter types differ;
 *  - a subject is `lv::SubjectOf<float>`: `set_color` on it does not compile, and the observers
 *    are lambdas, so the union that smuggled a setter through `void *` is gone.
 *
 * What stays C is what the binding hands out as C: `lv_opa_t` values, the LV_PCT and
 * LV_SIZE_CONTENT macros, and the `lv_anim_t *` of a running animation, which LVGL owns.
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_demo_truck/lv_demo_truck.hpp"

#include <cstddef>
#include <cstdint>
#include <utility>

namespace {

/*********************
 *      DEFINES
 *********************/

constexpr double PI = 3.14159265358979323846;
constexpr float DEG_TO_RAD = 0.01745329238f;
constexpr uint32_t ACCENT_COLOR = 0xFF6B35;
constexpr uint32_t SLIDER_COLOR = 0x26A69A;
constexpr int32_t CHECKBOX_HEIGHT = 22;

/**********************
 *      TYPEDEFS
 **********************/

enum class HatchType { Door = 1, Window = 2, TrunkHood = 3, Sunroof = 4 };
enum class HatchState { Unset = 0, Open = 1, Closed = 2 };
enum class TireType { Unset = 0, Clean = 1, Dirty = 2 };
enum class SpeedUnit { Unset = 0, Mph = 1, Kmph = 2 };
enum class Blinker { Unset = 0, None = 1, Left = 2, Right = 3, Hazard = 4 };
enum class WipersSetting { Unset = 0, Off = 1, Int = 2, Low = 3, High = 4 };
enum class Headlights { Unset = 0, Off = 1, Low = 2, High = 3 };
enum class Camera { Unset = 0, Interior = 1, Exterior = 2 };

struct MouseState {
    lv::Point last_pos{};
    bool is_dragging = false;
    float sensitivity = 0.3f;
};

struct Foldout {
    lv::Obj contents;
    lv::Obj title;
    lv::Obj title_button;
    bool contents_visible = false;
};

/*
 * Every controller owns its animation. `anim` is the template -- configured once, started as
 * often as needed -- and `running` is the copy LVGL keeps while it runs, which is LVGL's and not
 * ours: the binding hands it back as the C pointer it is.
 *
 * The template is never a controller's FIRST member, and that is load-bearing. lv_anim_start()
 * reads `var == &template` as "this animation animates itself" and swaps `var` for the running
 * copy. The C original is built on exactly that: its controllers start with their lv_anim_t, so
 * its exec callbacks receive the running animation, take the controller back out of its
 * user_data, and delete it with lv_anim_delete(running, NULL). Here `var` IS the controller and
 * the exec callback takes it typed, so the two addresses must differ -- with `anim` first, the
 * callback got LVGL's copy of the template cast to a controller. The static_asserts below the
 * structs hold the layout to it.
 */

struct Hatch {
    lv_anim_t * running = nullptr;
    lv::Anim anim;
    lv::GltfModelNode node;
    float open_degrees = 0.f;
    float closed_degrees = 0.f;
    int32_t last_set_value = 0;
    uint32_t length_ms = 0;
    HatchType hatch_type = HatchType::Door;
    HatchState hatch_state = HatchState::Unset;
    lv::Button checkbox;
};

struct Tire {
    lv_anim_t * running = nullptr;
    lv::Anim anim;
    lv::GltfModelNode node_steering;
    lv::GltfModelNode node_spin;
    lv::GltfModelNode node_tire_type1;
    lv::GltfModelNode node_tire_type2;
    float actual_spin_angle = 0.f;
    float goal_spin_rate = 0.f;
};

struct TiresetController {
    Tire * tire_FD_spin = nullptr;
    Tire * tire_FP_spin = nullptr;
    Tire * tire_BDP_spin = nullptr;
    float goal_speed_ratio = 0.f;
    float tach_offset = 0.f;
    float goal_spin_rate = 0.f;
    float goal_steer_ratio = 0.f;
    float goal_steer_angle = 0.f;
    float last_steer_angle = 0.f;
    TireType tire_type = TireType::Unset;
    SpeedUnit speed_type = SpeedUnit::Unset;
    lv::Button checkbox_mph;
    lv::Button checkbox_kmph;
    lv::Label label_speed;
    lv::Label label_speed_type;
    lv::Slider slider_speed;
    lv::Slider slider_steering;
};

struct Paintset {
    lv::GltfModelNode body_node;
    lv::GltfModelNode hood_node;
    lv::GltfModelNode door_FD_node;
    lv::GltfModelNode door_FP_node;
    lv::GltfModelNode door_BD_node;
    lv::GltfModelNode door_BP_node;
    lv::GltfModelNode tailgate_node;
    lv::Button button;
};

struct LightsetController {
    lv_anim_t * running = nullptr;
    lv::Anim anim;
    lv::GltfModelNode node_left_blinker_on;
    lv::GltfModelNode node_left_blinker_off;
    lv::GltfModelNode node_right_blinker_on;
    lv::GltfModelNode node_right_blinker_off;
    lv::GltfModelNode node_brakes_on;
    lv::GltfModelNode node_brakes_off;
    lv::GltfModelNode node_lights_low_on;
    lv::GltfModelNode node_lights_low_off;
    lv::GltfModelNode node_lights_high_on;
    lv::GltfModelNode node_lights_high_off;
    bool brakes_active = false;
    float blinker_set_angle = 0.f;
    float blinker_ext_angle = 0.f;
    Blinker blinker_setting = Blinker::Unset;
    Headlights headlights_setting = Headlights::Unset;
    Headlights last_applied_headlights_setting = Headlights::Unset;
    lv::Checkbox checkbox_headlights_low;
    lv::Checkbox checkbox_headlights_high;
};

struct WipersController {
    lv_anim_t * running = nullptr;
    lv::Anim anim;
    lv::GltfModelNode node_left_wiper;
    lv::GltfModelNode node_right_wiper;
    uint32_t last_anim_value = 10000;
    WipersSetting wipers_setting = WipersSetting::Off;
    WipersSetting next_wipers_setting = WipersSetting::Off;
    lv::Button btn_wipers_low;
    lv::Button btn_wipers_med;
    lv::Button btn_wipers_high;
};

struct InteriorController {
    lv_anim_t * running = nullptr;
    lv::Anim anim;
    lv::GltfModelNode node_speedometer_needle;
    lv::GltfModelNode node_tachometer_needle;
    lv::GltfModelNode node_left_turn_indicator;
    lv::GltfModelNode node_right_turn_indicator;
    lv::GltfModelNode node_steering_wheel;
};

struct CameraController {
    lv_anim_t * running = nullptr;
    lv::Anim anim;
    lv::Obj viewer;
    lv::Button checkbox_camera_interior;
    lv::Button checkbox_camera_exterior;
    lv::Button checkbox_camera_free;
    Camera next_camera_setting = Camera::Unset;
};

/* See above: a template at offset 0 would make lv_anim_start() hand the exec callback its own copy. */
static_assert(offsetof(Hatch, anim) != 0);
static_assert(offsetof(Tire, anim) != 0);
static_assert(offsetof(LightsetController, anim) != 0);
static_assert(offsetof(WipersController, anim) != 0);
static_assert(offsetof(InteriorController, anim) != 0);
static_assert(offsetof(CameraController, anim) != 0);

/**********************
 *  STATIC PROTOTYPES
 **********************/

void hatch_open_close_complete_anim_cb(lv_anim_t * anim);
void hatch_update_checkbox(Hatch * hatch);
void hatch_open_close_on_x_anim_cb(Hatch * hatch, int32_t anim_value);
void hatch_open_close_on_y_anim_cb(Hatch * hatch, int32_t anim_value);
void hatch_open_close_on_z_anim_cb(Hatch * hatch, int32_t anim_value);
void hatch_open_close_slide_z_anim_cb(Hatch * hatch, int32_t anim_value);
void tire_spin_on_z_anim_cb(Tire * tire, int32_t anim_value);
void blinker_lights_anim_cb(LightsetController * lights, int32_t anim_value);
void interior_update_anim_cb(InteriorController * interior, int32_t anim_value);
void camera_update_anim_cb(CameraController * cameras, int32_t anim_value);
void wipers_anim_cb(WipersController * wipers, int32_t anim_value);

void show_foldout(Foldout * foldout);
void hide_foldout(Foldout * foldout);

void hide_node(lv::GltfModelNode node);
void show_node(lv::GltfModelNode node);
void hide_all_paintsets();
void show_paintset(Paintset * paintset);
void hide_paintset(Paintset * paintset);
void apply_dirt(bool truck_is_dirty);
void enable_antialiasing(bool use_antialiasing);
void select_paintset_A();
void select_paintset_B();
void select_paintset_C();

void set_tire_type(Tire * tire, TireType tire_type);
void set_tireset_type(TiresetController * tireset, TireType tire_type);
void set_tireset_speed_type(TiresetController * tireset, SpeedUnit speed_type);
void set_tireset_speed_ratio(TiresetController * tireset, float max_speed_ratio);
void set_tireset_steer_ratio(TiresetController * tireset, float max_steer_ratio);
void set_lightset_blinker_type(LightsetController * lights, Blinker blinker_type);
void set_lightset_headlight_type(LightsetController * lights, Headlights headlights_type);
void set_wiper_speed(WipersController * wipers, WipersSetting wipers_setting);
void set_camera_num(CameraController * cameras, Camera camera_type);

void open_hatch(Hatch * hatch);
void close_hatch(Hatch * hatch);
void toggle_hatch(Hatch * hatch);
void open_all_doors();
void close_all_doors();
void open_all_windows();
void close_all_windows();

void init_anim_controllers(lv::Obj viewer);
void init_paintset_controllers(lv::Obj viewer);
void init_tire_controllers(lv::Obj viewer);
void init_lights_controller(lv::Obj viewer);
void init_wipers_controller(lv::Obj viewer);
void init_interior_controller(lv::Obj viewer);
void init_camera_controller(lv::Obj viewer);
void init_subjects(lv::Obj viewer);
void init_checkbox_states();

void create_about_panel(lv::Obj panel, lv::Obj viewer);
void create_doors_panel(lv::Obj panel, lv::Obj viewer);
void create_windows_panel(lv::Obj panel, lv::Obj viewer);
void create_paint_panel(lv::Obj panel, lv::Obj viewer);
void create_speed_panel(lv::Obj panel, lv::Obj viewer);
void create_steering_panel(lv::Obj panel, lv::Obj viewer);
void create_headlights_panel(lv::Obj panel, lv::Obj viewer);
void create_wipers_panel(lv::Obj panel, lv::Obj viewer);
void create_control_panel(lv::Obj viewer);
void create_camera_panel(lv::Obj panel, lv::Obj viewer);
void create_options_panel(lv::Obj parent, lv::Obj viewer);

void on_mouse_event(lv::Obj viewer, lv_event_code_t event_code);
void gas_pressing();
void brakes_pressing();

lv::Obj add_row(lv::Obj parent);
lv::Obj add_sep(lv::Obj parent);
lv::Button add_button_to_row(lv::Obj row, lv::Color color);
template <class F> lv::Button add_labeled_event_button_to_row(lv::Obj row, lv::Color color, const char * label,
                                                              F && on_clicked);
lv::Slider add_slider_to_row(lv::Obj row, lv::Color color);
template <class F> lv::Checkbox add_checkbox_to_row(lv::Obj row, lv::Color color, F && on_clicked);
template <class F> lv::Checkbox add_labeled_checkbox_row(lv::Obj panel, const char * label, F && on_clicked);
lv::Label add_title_to_row(lv::Obj row, const char * title);
lv::Obj add_foldout_header(lv::Obj parent, const char * title);

void style_slider(lv::Obj slider, lv::Color accent_color);
void style_toggle_button(lv::Obj btn, lv::Color accent_color);
void style_control_panel(lv::Obj panel);
void style_checkbox(lv::Obj checkbox, lv::Color accent_color);

double distance_per_revolution(double tire_radius);
double revolution_rate(double tire_radius, double travel_rate_kmh);

/**********************
 *  STATIC VARIABLES
 **********************/

/*
 * Allocated once in lv_demo_truck() and never freed, as in the C original: they live as long as
 * the screen does, and LVGL holds their addresses (animation vars, subjects, closures).
 */
lv::SubjectOf<float> * yaw_subject;
lv::SubjectOf<float> * pitch_subject;
lv::SubjectOf<int32_t> * animation_subject;
lv::SubjectOf<int32_t> * animation_speed_subject;

Hatch * door_FD_open_close;
Hatch * door_FP_open_close;
Hatch * door_BD_open_close;
Hatch * door_BP_open_close;
Hatch * hood_open_close;
Hatch * tailgate_open_close;
Hatch * window_FD_open_close;
Hatch * window_FP_open_close;
Hatch * window_BD_open_close;
Hatch * window_BP_open_close;
Hatch * sunroof_open_close;

Paintset * paintset_red;
Paintset * paintset_gray;
Paintset * paintset_green;

TiresetController * tireset_controller;
LightsetController * lights_controller;
WipersController * wipers_controller;
InteriorController * interior_controller;
CameraController * camera_controller;

MouseState mouse_state;

lv::GltfModelNode node_dirty_overlay_1;
lv::GltfModelNode node_dirty_overlay_2;
lv::GltfModelNode node_dirty_overlay_3;
lv::Button open_all_doors_btn;
lv::Button close_all_doors_btn;
lv::Button open_all_windows_btn;
lv::Button close_all_windows_btn;

lv::Button left_blinker_btn;
lv::Button hazard_blinker_btn;
lv::Button right_blinker_btn;

lv::Button mud_toggle_btn;
bool has_mud = false;
lv::Button checkbox_antialiasing;
Foldout * last_opened_foldout = nullptr;
lv::Obj logo_viewer;

constexpr float MAX_SPIN_SLIDER_VALUE = 10000.f;
constexpr float MIN_MAX_STEER_SLIDER_VALUE = 5000.f;

constexpr float TWO_PI = PI * 2.f;
constexpr float KM_TO_MILE = 0.621371f;
float MAX_SPIN_RATE = 1.f;
constexpr float MAX_STEER_ANGLE = PI / 6.f;

constexpr float MAX_SPEED_KMH = 105.f;

constexpr const char * door_FD_path = "/truck/013_door_driver_group";
constexpr const char * door_FP_path = "/truck/014_door_pass_group";
constexpr const char * door_BD_path = "/truck/017_door_back_driver_group";
constexpr const char * door_BP_path = "/truck/018_door_back_pass_group";
constexpr const char * hood_path = "/truck/012_hood_group";
constexpr const char * tailgate_path = "/truck/010_tailgate_group";

constexpr const char * window_FD_path = "/truck/013_door_driver_group/door_driver_window_pivot";
constexpr const char * window_FP_path = "/truck/014_door_pass_group/door_pass_window_pivot";
constexpr const char * window_BD_path = "/truck/017_door_back_driver_group/door_back_driver_window_pivot";
constexpr const char * window_BP_path = "/truck/018_door_back_pass_group/door_back_pass_window_pivot";
constexpr const char * sunroof_path = "/truck/500_glass_sunroof";

constexpr const char * steer_FD_path = "/truck/030_tire_front_driver";
constexpr const char * steer_FP_path = "/truck/033_tire_front_pass";
constexpr const char * tire_FD_path = "/truck/030_tire_front_driver/tire_spin_controller_000";
constexpr const char * tire_FP_path = "/truck/033_tire_front_pass/tire_spin_controller_001";
constexpr const char * tire_BDP_path = "/truck/036_tires_back";
constexpr const char * tire_FD_type1_path =
    "/truck/030_tire_front_driver/tire_spin_controller_000/032_tire_front_driver_clean";
constexpr const char * tire_FD_type2_path =
    "/truck/030_tire_front_driver/tire_spin_controller_000/031_tire_front_driver_muddy";
constexpr const char * tire_FP_type1_path =
    "/truck/033_tire_front_pass/tire_spin_controller_001/035_tire_front_pass_clean";
constexpr const char * tire_FP_type2_path =
    "/truck/033_tire_front_pass/tire_spin_controller_001/034_tire_front_pass_muddy";
constexpr const char * tire_BDP_type1_path = "/truck/036_tires_back/038_tires_back_clean";
constexpr const char * tire_BDP_type2_path = "/truck/036_tires_back/037_tires_back_muddy";

constexpr const char * paintset_A_body = "/truck/001a_body_painted";
constexpr const char * paintset_B_body = "/truck/001b_body_painted";
constexpr const char * paintset_C_body = "/truck/001c_body_painted";
constexpr const char * paintset_A_hood = "/truck/012_hood_group/012a_hood_painted_body";
constexpr const char * paintset_B_hood = "/truck/012_hood_group/012b_hood_painted_body";
constexpr const char * paintset_C_hood = "/truck/012_hood_group/012c_hood_painted_body";
constexpr const char * paintset_A_door_FD = "/truck/013_door_driver_group/002a_door_driver_painted_body";
constexpr const char * paintset_B_door_FD = "/truck/013_door_driver_group/002b_door_driver_painted_body";
constexpr const char * paintset_C_door_FD = "/truck/013_door_driver_group/002c_door_driver_painted_body";
constexpr const char * paintset_A_door_FP = "/truck/014_door_pass_group/002a_door_pass_painted_body";
constexpr const char * paintset_B_door_FP = "/truck/014_door_pass_group/002b_door_pass_painted_body";
constexpr const char * paintset_C_door_FP = "/truck/014_door_pass_group/002c_door_pass_painted_body";
constexpr const char * paintset_A_door_BD = "/truck/017_door_back_driver_group/004a_doors_back_driver_painted_body";
constexpr const char * paintset_B_door_BD = "/truck/017_door_back_driver_group/004b_doors_back_driver_painted_body";
constexpr const char * paintset_C_door_BD = "/truck/017_door_back_driver_group/004c_doors_back_driver_painted_body";
constexpr const char * paintset_A_door_BP = "/truck/018_door_back_pass_group/004a_doors_back_pass_painted_body";
constexpr const char * paintset_B_door_BP = "/truck/018_door_back_pass_group/004b_doors_back_pass_painted_body";
constexpr const char * paintset_C_door_BP = "/truck/018_door_back_pass_group/004c_doors_back_pass_painted_body";
constexpr const char * paintset_A_tailgate = "/truck/010_tailgate_group/011a_tailgate_painted_body";
constexpr const char * paintset_B_tailgate = "/truck/010_tailgate_group/011b_tailgate_painted_body";
constexpr const char * paintset_C_tailgate = "/truck/010_tailgate_group/011c_tailgate_painted_body";

constexpr const char * dirty_overlay_1 = "/truck/013_door_driver_group/100_truck_splatters_door_driver";
constexpr const char * dirty_overlay_2 = "/truck/014_door_pass_group/100_truck_splatters_door_pass";
constexpr const char * dirty_overlay_3 = "/truck/100_truck_splatters_body";

constexpr const char * node_speedometer_needle_path = "/truck/200_dash_parts_group/200_speedometer_needle";
constexpr const char * node_tachometer_needle_path = "/truck/200_dash_parts_group/201_tachometer_needle";
constexpr const char * node_left_turn_indicator_path = "/truck/200_dash_parts_group/205_left_turn_indicator";
constexpr const char * node_right_turn_indicator_path = "/truck/200_dash_parts_group/206_right_turn_indicator";

constexpr const char * node_left_blinker_on_path = "/truck/500_blinkers_driver_on";
constexpr const char * node_left_blinker_off_path = "/truck/500_blinkers_driver_off";
constexpr const char * node_right_blinker_on_path = "/truck/500_blinkers_pass_on";
constexpr const char * node_right_blinker_off_path = "/truck/500_blinkers_pass_off";
constexpr const char * node_brakes_on_path = "/truck/500_brakes_on";
constexpr const char * node_brakes_off_path = "/truck/500_brakes_off";
constexpr const char * node_lights_low_on_path = "/truck/500_headlights_low_on_group";
constexpr const char * node_lights_low_off_path = "/truck/500_headlights_low_off_group";
constexpr const char * node_lights_high_on_path = "/truck/500_headlights_high_on_group";
constexpr const char * node_lights_high_off_path = "/truck/500_headlights_high_off_group";

constexpr const char * node_left_wiper_path = "/truck/022_wiper_driver_pivot/022_wiper_driver";
constexpr const char * node_right_wiper_path = "/truck/023_wiper_pass_pivot/023_wiper_pass";

constexpr const char * node_steering_wheel_path = "/truck/027_steering_wheel_group/027_steering_wheel_pivot";

const char * ui_assets_path = nullptr;

} // namespace

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv::Obj lv_demo_truck(const char * assets_path)
{
    ui_assets_path = assets_path;
    lv::Obj viewer = lv::gltf_create(lv::display_screen_active());

    lv::gltf_set_distance(viewer, .15f);
    // lv::gltf_set_pitch(viewer, -85.f);
    viewer.set_size(LV_PCT(100), LV_PCT(100));
    viewer.remove_flag(lv::ObjFlag::Scrollable);
    lv::gltf_set_background_mode(viewer, lv::GltfBgMode::Solid);

    // lv::gltf_set_focal_x(viewer, -10.f);
    char truck_model_path[256];
    lv::sprintf_snprintf(truck_model_path, sizeof(truck_model_path), "%s/%s", ui_assets_path, "lv_truck.glb");
    lv::GltfModel model = lv::gltf_load_model_from_file(viewer, truck_model_path);
    LV_ASSERT_NULL(model.raw());

    lv::gltf_set_focal_y(viewer, 1);
    init_subjects(viewer);
    init_anim_controllers(viewer);
    init_paintset_controllers(viewer);
    init_tire_controllers(viewer);
    init_lights_controller(viewer);
    init_wipers_controller(viewer);
    init_interior_controller(viewer);
    init_camera_controller(viewer);

    create_control_panel(viewer);

    set_tireset_speed_type(tireset_controller, SpeedUnit::Kmph);

    /* One lambda per code: the event is typed by it, so there is nothing to switch on. They all
     * share the file's mouse state, which is why none of them captures anything. */
    viewer.on(lv::events::Pressed, [](auto & e) { on_mouse_event(e.target(), LV_EVENT_PRESSED); });
    viewer.on(lv::events::Pressing, [](auto & e) { on_mouse_event(e.target(), LV_EVENT_PRESSING); });
    viewer.on(lv::events::Released, [](auto & e) { on_mouse_event(e.target(), LV_EVENT_RELEASED); });
    viewer.on(lv::events::PressLost, [](auto & e) { on_mouse_event(e.target(), LV_EVENT_PRESS_LOST); });

    close_all_windows();
    close_all_doors();
    apply_dirt(false);
    set_wiper_speed(wipers_controller, WipersSetting::Off);
    set_lightset_headlight_type(lights_controller, Headlights::Off);
    close_hatch(tailgate_open_close);
    close_hatch(hood_open_close);
    close_hatch(sunroof_open_close);
    set_camera_num(camera_controller, Camera::Exterior);
    init_checkbox_states();
    select_paintset_A();
    enable_antialiasing(true);

    return viewer;
}

namespace {

/**********************
 *   STATIC FUNCTIONS
 **********************/

Foldout * lv_demo_foldout(lv::Obj parent, const char * title)
{
    auto * foldout = new Foldout();

    lv::Button title_btn = lv::Button::create(parent);
    title_btn.set_size(LV_PCT(100), 30);
    title_btn.style(lv::Part::Main)
    .bg_color(lv::Color::hex(0xFF6B35))
    .bg_opa(LV_OPA_0)
    .radius(0)
    .shadow_width(0)
    .border_color(lv::Color::white())
    .border_opa(LV_OPA_30)
    .border_width(3)
    .border_side(lv::BorderSide::Bottom)
    .pad_all(5)
    .margin_top(-3)
    .margin_bottom(-4);
    title_btn.on(lv::events::Clicked, [foldout](auto &) { show_foldout(foldout); });
    title_btn.set_layout(LV_LAYOUT_FLEX);
    title_btn.set_flex_flow(lv::FlexFlow::Row);

    lv::Label right_arrow = lv::Label::create(title_btn);
    right_arrow.set_text_static(lv::symbol::RIGHT);
    right_arrow.style(lv::Part::Main).text_color(lv::Color::white()).margin_right(2);
    lv::Label button_label = lv::Label::create(title_btn);
    button_label.set_text_static(title);
    button_label.style(lv::Part::Main).text_color(lv::Color::white());

    lv::Obj foldout_contents = add_row(parent);
    foldout_contents.style(lv::Part::Main).pad_all(0).margin_all(0);
    foldout_contents.set_width(LV_PCT(100));

    lv::Obj title_row = add_row(foldout_contents);
    title_row.style(lv::Part::Main).margin_top(2);
    lv::Label down_arrow = lv::Label::create(title_row);
    down_arrow.set_text_static(lv::symbol::DOWN);
    down_arrow.style(lv::Part::Main).text_color(lv::Color::white()).margin_right(-7);
    add_title_to_row(title_row, title);
    title_row.set_flex_flow(lv::FlexFlow::Row);
    title_row.style(lv::Part::Main).pad_all(15).pad_top(0).pad_bottom(0).margin_bottom(0);
    title_row.on(lv::events::Clicked, [foldout](auto &) { hide_foldout(foldout); });

    foldout->title = title_row;
    foldout->title_button = title_btn;
    foldout->contents = foldout_contents;
    foldout->contents_visible = true;
    //hide_foldout(foldout);
    return foldout;
}

CameraController * lv_demo_truck_camera_controller(lv::Obj viewer)
{
    LV_UNUSED(viewer);
    auto * cameras = new CameraController();

    cameras->anim.set_exec_cb<&camera_update_anim_cb>()
    /* Set target of the Animation */
    .set_var(cameras)
    .set_user_data(cameras)
    /* Length of the Animation [ms] (this will change as soon as a valid speed is set)*/
    .set_duration(1000)
    /* Loop forever */
    .set_repeat_count(LV_ANIM_REPEAT_INFINITE)
    /* Set start and end values. E.g. 0, 150 */
    .set_values(0, 10000);
    cameras->running = cameras->anim.start();

    return cameras;
}

InteriorController * lv_demo_truck_interior(lv::Obj viewer)
{
    lv::GltfModel model = lv::gltf_get_primary_model(viewer);
    auto * interior = new InteriorController();
    interior->node_steering_wheel = lv::gltf_model_node_get_by_path(model, node_steering_wheel_path);
    interior->node_speedometer_needle = lv::gltf_model_node_get_by_path(model, node_speedometer_needle_path);
    interior->node_tachometer_needle = lv::gltf_model_node_get_by_path(model, node_tachometer_needle_path);
    interior->node_left_turn_indicator = lv::gltf_model_node_get_by_path(model, node_left_turn_indicator_path);
    interior->node_right_turn_indicator = lv::gltf_model_node_get_by_path(model, node_right_turn_indicator_path);

    interior->anim.set_exec_cb<&interior_update_anim_cb>()
    /* Set target of the Animation */
    .set_var(interior)
    .set_user_data(interior)
    /* Length of the Animation [ms] (this will change as soon as a valid speed is set)*/
    .set_duration(1000)
    /* Loop forever */
    .set_repeat_count(LV_ANIM_REPEAT_INFINITE)
    /* Set start and end values. E.g. 0, 150 */
    .set_values(0, 10000);
    interior->running = interior->anim.start();

    return interior;
}

Hatch * lv_demo_truck_hatch(lv::Obj viewer, const char * node_path, uint32_t length_ms,
                            float open_degrees, float closed_degrees, HatchType hatch_type)
{
    auto * hatch = new Hatch();

    hatch->open_degrees = open_degrees;
    hatch->closed_degrees = closed_degrees;
    hatch->length_ms = length_ms;
    hatch->hatch_type = hatch_type;

    lv::GltfModel model = lv::gltf_get_primary_model(viewer);
    hatch->node = lv::gltf_model_node_get_by_path(model, node_path);

    switch(hatch_type) {
        case HatchType::Door:
            hatch->anim.set_exec_cb<&hatch_open_close_on_x_anim_cb>();
            break;
        case HatchType::Window:
            hatch->anim.set_exec_cb<&hatch_open_close_on_y_anim_cb>();
            break;
        case HatchType::TrunkHood:
            hatch->anim.set_exec_cb<&hatch_open_close_on_z_anim_cb>();
            break;
        case HatchType::Sunroof:
            hatch->anim.set_exec_cb<&hatch_open_close_slide_z_anim_cb>();
            break;
        default:
            hatch->anim.set_exec_cb<&hatch_open_close_on_x_anim_cb>();
            break;
    }
    hatch->anim.set_completed_cb(hatch_open_close_complete_anim_cb)
    /* Set target of the Animation */
    .set_var(hatch)
    .set_user_data(hatch)
    /* Length of the Animation [ms] */
    .set_duration(hatch->length_ms)
    /* Set start and end values. E.g. 0, 150 */
    .set_values((int32_t)(hatch->closed_degrees * 100.f), (int32_t)(hatch->open_degrees * 100.f));

    hatch->last_set_value = (int32_t)(hatch->closed_degrees * 100.f);

    return hatch;
}

Tire * lv_demo_truck_tire(lv::Obj viewer, const char * node_steering_path, const char * node_spin_path,
                          const char * node_tire_type1_path, const char * node_tire_type2_path)
{
    auto * tire = new Tire();

    lv::GltfModel model = lv::gltf_get_primary_model(viewer);
    tire->node_steering = (node_steering_path == nullptr)
                          ? lv::GltfModelNode()
                          : lv::gltf_model_node_get_by_path(model, node_steering_path);
    tire->node_spin = lv::gltf_model_node_get_by_path(model, node_spin_path);
    tire->node_tire_type1 = lv::gltf_model_node_get_by_path(model, node_tire_type1_path);
    tire->node_tire_type2 = lv::gltf_model_node_get_by_path(model, node_tire_type2_path);

    tire->anim.set_exec_cb<&tire_spin_on_z_anim_cb>()
    /* Set target of the Animation */
    .set_var(tire)
    .set_user_data(tire)
    /* Length of the Animation [ms] (this will change as soon as a valid speed is set)*/
    .set_duration(1000)
    /* Loop forever */
    .set_repeat_count(LV_ANIM_REPEAT_INFINITE)
    /* Set start and end values. E.g. 0, 150 */
    .set_values(0, 36000);
    tire->running = tire->anim.start();

    return tire;
}

TiresetController * lv_demo_truck_tireset_controller(lv::Obj viewer, TireType tire_type)
{
    auto * tireset = new TiresetController();

    tireset->tire_FD_spin = lv_demo_truck_tire(viewer, steer_FD_path, tire_FD_path, tire_FD_type1_path, tire_FD_type2_path);
    tireset->tire_FP_spin = lv_demo_truck_tire(viewer, steer_FP_path, tire_FP_path, tire_FP_type1_path, tire_FP_type2_path);
    tireset->tire_BDP_spin = lv_demo_truck_tire(viewer, nullptr, tire_BDP_path, tire_BDP_type1_path, tire_BDP_type2_path);
    set_tireset_type(tireset, tire_type);
    return tireset;
}

LightsetController * lv_demo_truck_lightset_controller(lv::Obj viewer)
{
    auto * lightset = new LightsetController();

    lv::GltfModel model = lv::gltf_get_primary_model(viewer);
    lightset->node_left_blinker_on = lv::gltf_model_node_get_by_path(model, node_left_blinker_on_path);
    lightset->node_left_blinker_off = lv::gltf_model_node_get_by_path(model, node_left_blinker_off_path);
    lightset->node_right_blinker_on = lv::gltf_model_node_get_by_path(model, node_right_blinker_on_path);
    lightset->node_right_blinker_off = lv::gltf_model_node_get_by_path(model, node_right_blinker_off_path);
    lightset->node_brakes_on = lv::gltf_model_node_get_by_path(model, node_brakes_on_path);
    lightset->node_brakes_off = lv::gltf_model_node_get_by_path(model, node_brakes_off_path);
    lightset->node_lights_low_on = lv::gltf_model_node_get_by_path(model, node_lights_low_on_path);
    lightset->node_lights_low_off = lv::gltf_model_node_get_by_path(model, node_lights_low_off_path);
    lightset->node_lights_high_on = lv::gltf_model_node_get_by_path(model, node_lights_high_on_path);
    lightset->node_lights_high_off = lv::gltf_model_node_get_by_path(model, node_lights_high_off_path);

    lightset->anim.set_exec_cb<&blinker_lights_anim_cb>()
    /* Set target of the Animation */
    .set_var(lightset)
    .set_user_data(lightset)
    /* Length of the Animation [ms] (this will change as soon as a valid speed is set)*/
    .set_duration(667)
    /* Loop forever */
    .set_repeat_count(LV_ANIM_REPEAT_INFINITE)
    /* Set start and end values. E.g. 0, 150 */
    .set_values(0, 1000);
    lightset->running = lightset->anim.start();

    return lightset;
}

WipersController * lv_demo_truck_wipers_controller(lv::Obj viewer)
{
    auto * wipers = new WipersController();

    lv::GltfModel model = lv::gltf_get_primary_model(viewer);
    wipers->node_left_wiper = lv::gltf_model_node_get_by_path(model, node_left_wiper_path);
    wipers->node_right_wiper = lv::gltf_model_node_get_by_path(model, node_right_wiper_path);

    wipers->wipers_setting = WipersSetting::Off;
    wipers->next_wipers_setting = WipersSetting::Off;
    wipers->last_anim_value = 10000;

    wipers->anim.set_exec_cb<&wipers_anim_cb>()
    /* Set target of the Animation */
    .set_var(wipers)
    .set_user_data(wipers)
    /* Length of the Animation [ms] (this will change as soon as a valid speed is set)*/
    .set_duration(4000)
    /* Loop forever */
    .set_repeat_count(LV_ANIM_REPEAT_INFINITE)
    /* Set start and end values. E.g. 0, 150 */
    .set_values(0, 10000);
    lv::anim_delete(wipers, nullptr);
    wipers->running = nullptr;

    return wipers;
}

Paintset * lv_demo_truck_paintset(lv::Obj viewer, const char * body_node_path, const char * hood_node_path,
                                  const char * door_FD_node_path, const char * door_FP_node_path,
                                  const char * door_BD_node_path, const char * door_BP_node_path,
                                  const char * tailgate_node_path)
{
    auto * paintset = new Paintset();

    lv::GltfModel model = lv::gltf_get_primary_model(viewer);
    paintset->body_node = lv::gltf_model_node_get_by_path(model, body_node_path);
    paintset->hood_node = lv::gltf_model_node_get_by_path(model, hood_node_path);
    paintset->door_FD_node = lv::gltf_model_node_get_by_path(model, door_FD_node_path);
    paintset->door_FP_node = lv::gltf_model_node_get_by_path(model, door_FP_node_path);
    paintset->door_BD_node = lv::gltf_model_node_get_by_path(model, door_BD_node_path);
    paintset->door_BP_node = lv::gltf_model_node_get_by_path(model, door_BP_node_path);
    paintset->tailgate_node = lv::gltf_model_node_get_by_path(model, tailgate_node_path);
    return paintset;
}

/*********************************
 *   STATIC ANIMATION CALLBACKS
 *********************************/

/* What LVGL calls back with is the running copy, which it owns: a C pointer, read as one. */
void hatch_open_close_complete_anim_cb(lv_anim_t * anim)
{
    LV_ASSERT_NULL(anim);
    auto * hatch = static_cast<Hatch *>(lv_anim_get_user_data(anim));
    LV_ASSERT_NULL(hatch);
    hatch->running = nullptr;
    hatch_update_checkbox(hatch);
}

void hatch_update_checkbox(Hatch * hatch)
{
    LV_ASSERT_NULL(hatch);

    if(hatch->hatch_state == HatchState::Closed) {
        hatch->checkbox.add_state(lv::State::Checked);
    }
    else {
        hatch->checkbox.remove_state(lv::State::Checked);
    }

    if((door_FD_open_close->hatch_state != HatchState::Closed) || (door_FP_open_close->hatch_state != HatchState::Closed) ||
       (door_BD_open_close->hatch_state != HatchState::Closed) || (door_BP_open_close->hatch_state != HatchState::Closed)) {
        close_all_doors_btn.remove_flag(lv::ObjFlag::Hidden);
        open_all_doors_btn.add_flag(lv::ObjFlag::Hidden);
    }
    else {
        open_all_doors_btn.remove_flag(lv::ObjFlag::Hidden);
        close_all_doors_btn.add_flag(lv::ObjFlag::Hidden);
    }

    if((window_FD_open_close->hatch_state != HatchState::Closed) || (window_FP_open_close->hatch_state != HatchState::Closed) ||
       (window_BD_open_close->hatch_state != HatchState::Closed) || (window_BP_open_close->hatch_state != HatchState::Closed)) {
        close_all_windows_btn.remove_flag(lv::ObjFlag::Hidden);
        open_all_windows_btn.add_flag(lv::ObjFlag::Hidden);
    }
    else {
        open_all_windows_btn.remove_flag(lv::ObjFlag::Hidden);
        close_all_windows_btn.add_flag(lv::ObjFlag::Hidden);
    }
}

/*
 * The exec callbacks take the controller they animate, typed: LVGL calls them with the anim's
 * `var`, and `set_exec_cb<&fn>()` converts that `void *` back in one place. The C original casts
 * each callback to lv_anim_exec_xcb_t instead, and receives the running animation (see the
 * controllers above for why).
 */

void hatch_open_close_on_x_anim_cb(Hatch * hatch, int32_t anim_value)
{
    LV_ASSERT_NULL(hatch);
    hatch->last_set_value = anim_value;
    if(hatch->node) hatch->node.set_rotation_x(((float)anim_value / 100.f) * DEG_TO_RAD);
}

void hatch_open_close_on_y_anim_cb(Hatch * hatch, int32_t anim_value)
{
    LV_ASSERT_NULL(hatch);
    hatch->last_set_value = anim_value;
    if(hatch->node) hatch->node.set_rotation_y(((float)anim_value / 100.f) * DEG_TO_RAD);
}

void hatch_open_close_on_z_anim_cb(Hatch * hatch, int32_t anim_value)
{
    LV_ASSERT_NULL(hatch);
    hatch->last_set_value = anim_value;
    if(hatch->node) hatch->node.set_rotation_z(((float)anim_value / 100.f) * DEG_TO_RAD);
}

void hatch_open_close_slide_z_anim_cb(Hatch * hatch, int32_t anim_value)
{
    LV_ASSERT_NULL(hatch);
    hatch->last_set_value = anim_value;
    if(hatch->node) hatch->node.set_position_z(((float)anim_value / 100.f));
}

void tire_spin_on_z_anim_cb(Tire * tire, int32_t anim_value)
{
    LV_UNUSED(anim_value);
    LV_ASSERT_NULL(tire);
    float current_spin = tire->actual_spin_angle;
    current_spin += tire->goal_spin_rate;
    while(current_spin > TWO_PI) {
        current_spin -= TWO_PI;
    }
    tire->actual_spin_angle = current_spin;
    if(tire->node_spin) tire->node_spin.set_rotation_z(current_spin);
    if((tireset_controller != nullptr) && tire->node_steering) {
        tire->node_steering.set_rotation_x(tireset_controller->last_steer_angle);
    }
}

void blinker_lights_anim_cb(LightsetController * lights, int32_t anim_value)
{
    LV_ASSERT_NULL(lights);
    bool lights_on = (anim_value > 500);
    switch(lights->blinker_setting) {
        case Blinker::Left:
            hide_node(lights_on ? lights->node_left_blinker_off : lights->node_left_blinker_on);
            show_node(lights_on ? lights->node_left_blinker_on : lights->node_left_blinker_off);
            hide_node(lights->node_right_blinker_on);
            show_node(lights->node_right_blinker_off);
            if(interior_controller != nullptr) {
                hide_node(interior_controller->node_right_turn_indicator);
                if(lights_on) {
                    show_node(interior_controller->node_left_turn_indicator);
                }
                else {
                    hide_node(interior_controller->node_left_turn_indicator);
                }
            }
            break;
        case Blinker::Right:
            hide_node(lights_on ? lights->node_right_blinker_off : lights->node_right_blinker_on);
            show_node(lights_on ? lights->node_right_blinker_on : lights->node_right_blinker_off);
            hide_node(lights->node_left_blinker_on);
            show_node(lights->node_left_blinker_off);
            if(interior_controller != nullptr) {
                hide_node(interior_controller->node_left_turn_indicator);
                if(lights_on) {
                    show_node(interior_controller->node_right_turn_indicator);
                }
                else {
                    hide_node(interior_controller->node_right_turn_indicator);
                }
            }
            break;
        case Blinker::Hazard:
            hide_node(lights_on ? lights->node_left_blinker_off : lights->node_left_blinker_on);
            show_node(lights_on ? lights->node_left_blinker_on : lights->node_left_blinker_off);
            hide_node(lights_on ? lights->node_right_blinker_off : lights->node_right_blinker_on);
            show_node(lights_on ? lights->node_right_blinker_on : lights->node_right_blinker_off);
            if(interior_controller != nullptr) {
                if(lights_on) {
                    show_node(interior_controller->node_left_turn_indicator);
                    show_node(interior_controller->node_right_turn_indicator);
                }
                else {
                    hide_node(interior_controller->node_left_turn_indicator);
                    hide_node(interior_controller->node_right_turn_indicator);
                }
            }
            break;
        case Blinker::None:
        default:
            hide_node(lights->node_left_blinker_on);
            hide_node(lights->node_right_blinker_on);
            show_node(lights->node_left_blinker_off);
            show_node(lights->node_right_blinker_off);
            if(interior_controller != nullptr) {
                hide_node(interior_controller->node_left_turn_indicator);
                hide_node(interior_controller->node_right_turn_indicator);
            }
            break;
    }

    if(lights->brakes_active) {
        hide_node(lights->node_brakes_off);
        show_node(lights->node_brakes_on);
    }
    else {
        hide_node(lights->node_brakes_on);
        show_node(lights->node_brakes_off);
    }

    if(lights->last_applied_headlights_setting != lights->headlights_setting) {
        lights->last_applied_headlights_setting = lights->headlights_setting;
        switch(lights->headlights_setting) {
            case Headlights::Low:
                hide_node(lights->node_lights_low_off);
                hide_node(lights->node_lights_high_on);
                show_node(lights->node_lights_low_on);
                show_node(lights->node_lights_high_off);
                break;
            case Headlights::High:
                hide_node(lights->node_lights_low_off);
                hide_node(lights->node_lights_high_off);
                show_node(lights->node_lights_low_on);
                show_node(lights->node_lights_high_on);
                break;
            case Headlights::Off:
            default:
                hide_node(lights->node_lights_low_on);
                hide_node(lights->node_lights_high_on);
                show_node(lights->node_lights_low_off);
                show_node(lights->node_lights_high_off);
                break;
        }

    }

}

void camera_update_anim_cb(CameraController * cameras, int32_t anim_value)
{
    LV_UNUSED(anim_value);
    LV_ASSERT_NULL(cameras);
}

void interior_update_anim_cb(InteriorController * interior, int32_t anim_value)
{
    LV_UNUSED(anim_value);
    LV_ASSERT_NULL(interior);
    if(interior->node_steering_wheel) {
        float wheel_angle = tireset_controller->last_steer_angle;
        const float MAX_STEERING_WHEEL_TURN_RATE = ((PI * 0.06125f) / (1000.f / LV_DEF_REFR_PERIOD));
        const float BLINKER_RESET_ANGLE = 6.f * DEG_TO_RAD;
        float turn_rate_scale = 1.f;
        if(wheel_angle < tireset_controller->goal_steer_angle) {
            /* Turning left */
            turn_rate_scale = (((tireset_controller->goal_steer_angle - wheel_angle) / MAX_STEERING_WHEEL_TURN_RATE) / 50.f) + 1.f;
            wheel_angle += MAX_STEERING_WHEEL_TURN_RATE * turn_rate_scale;
            if(wheel_angle > tireset_controller->goal_steer_angle) wheel_angle = tireset_controller->goal_steer_angle;
            if(lights_controller->blinker_setting == Blinker::Left) {
                if(wheel_angle > lights_controller->blinker_ext_angle) lights_controller->blinker_ext_angle = wheel_angle;
            }
            else if(lights_controller->blinker_setting == Blinker::Right) {
                if(wheel_angle > lights_controller->blinker_ext_angle + BLINKER_RESET_ANGLE) set_lightset_blinker_type(
                        lights_controller, Blinker::None);
            }
        }
        else if(wheel_angle > tireset_controller->goal_steer_angle) {
            /* Turning right */
            turn_rate_scale = (((wheel_angle - tireset_controller->goal_steer_angle) / MAX_STEERING_WHEEL_TURN_RATE) / 50.f) + 1.f;
            wheel_angle -= MAX_STEERING_WHEEL_TURN_RATE * turn_rate_scale;
            if(wheel_angle < tireset_controller->goal_steer_angle) wheel_angle = tireset_controller->goal_steer_angle;
            if(lights_controller->blinker_setting == Blinker::Right) {
                if(wheel_angle < lights_controller->blinker_ext_angle) lights_controller->blinker_ext_angle = wheel_angle;
            }
            else if(lights_controller->blinker_setting == Blinker::Left) {
                if(wheel_angle < lights_controller->blinker_ext_angle - BLINKER_RESET_ANGLE) set_lightset_blinker_type(
                        lights_controller, Blinker::None);
            }
        }
        tireset_controller->last_steer_angle = wheel_angle;
        interior->node_steering_wheel.set_rotation_y((wheel_angle * -18.f));
    }

    if(interior->node_speedometer_needle) {
        float needle_angle = ((tireset_controller->goal_speed_ratio * 270.f) - 135.f) * DEG_TO_RAD;
        interior->node_speedometer_needle.set_rotation_y(needle_angle);
    }
    if(interior->node_tachometer_needle) {
        float needle_angle = ((tireset_controller->goal_speed_ratio * 125.f) - 105.f) * DEG_TO_RAD;
        needle_angle += (tireset_controller->tach_offset * 60.f) * DEG_TO_RAD;
        interior->node_tachometer_needle.set_rotation_y(needle_angle);
    }
    tireset_controller->tach_offset *= 0.95f;
}

void wipers_anim_cb(WipersController * wipers, int32_t anim_value)
{
    LV_ASSERT_NULL(wipers);
    float wiper_angle = 0.f;

    const float max_wiper_angle = -85.f;
    const float max_passenger_wiper_angle = -115.f;
    const float passenger_wiper_ratio = max_passenger_wiper_angle / max_wiper_angle;

    if((uint32_t)anim_value < wipers->last_anim_value) {
        /* animation has cycled, can switch to other mode */
        if(wipers->next_wipers_setting != wipers->wipers_setting) {
            wipers->wipers_setting = wipers->next_wipers_setting;
        }
    }
    wipers->last_anim_value = anim_value;

    switch(wipers->wipers_setting) {
        case WipersSetting::Int:
            if(anim_value < 2000) {
                wiper_angle = ((float)anim_value / 2000.f) * max_wiper_angle;
            }
            else if(anim_value < 4000) {
                wiper_angle = max_wiper_angle - (((float)(anim_value - 2000) / 2000.f) * max_wiper_angle);
            }
            break;
        case WipersSetting::Low:
            anim_value = anim_value % 5000;
            if(anim_value < 2000) {
                wiper_angle = ((float)anim_value / 2000.f) * max_wiper_angle;
            }
            else if(anim_value < 4000) {
                wiper_angle = max_wiper_angle - (((float)(anim_value - 2000) / 2000.f) * max_wiper_angle);
            }
            break;
        case WipersSetting::High:
            anim_value = anim_value % 2500;
            if(anim_value < 1000) {
                wiper_angle = ((float)anim_value / 1000.f) * max_wiper_angle;
            }
            else if(anim_value < 2000) {
                wiper_angle = max_wiper_angle - (((float)(anim_value - 1000) / 1000.f) * max_wiper_angle);
            }
            break;
        case WipersSetting::Off:
            wiper_angle = 0.f;
            [[fallthrough]];
        default:
            break;
    }
    wiper_angle *= DEG_TO_RAD;

    if(wiper_angle == 0.f) {
        /* animation is at bottom of cycle, can switch to off */
        if(wipers->next_wipers_setting != wipers->wipers_setting) {
            wipers->wipers_setting = WipersSetting::Off;
        }
    }

    if(wipers->wipers_setting == WipersSetting::Off) {
        if(wipers->running != nullptr) {
            /* lv_anim_delete matches on `var`, which is the controller here. In the C original the
             * running copy was its own `var`, so it deleted by that address instead. */
            lv::anim_delete(wipers, nullptr);
            wipers->running = nullptr;
        }
        if(wipers->next_wipers_setting != WipersSetting::Off) {
            wipers->running = wipers->anim.start();
            wipers->wipers_setting = wipers->next_wipers_setting;
            wipers->last_anim_value = 10000;
        }
    }

    if(wipers->node_left_wiper) wipers->node_left_wiper.set_rotation_x(wiper_angle);
    if(wipers->node_right_wiper) wipers->node_right_wiper.set_rotation_x(wiper_angle * passenger_wiper_ratio);
}

/***********************************
 *   STATIC INPUT EVENT CALLBACKS
 ***********************************/

void on_mouse_event(lv::Obj viewer, lv_event_code_t event_code)
{
    lv::Point current_pos = lv::indev_active().get_point();

    switch(event_code) {
        case LV_EVENT_PRESSED:
            mouse_state.is_dragging = true;
            mouse_state.last_pos = current_pos;
            break;
        case LV_EVENT_PRESSING:
            if(mouse_state.is_dragging && lv::gltf_get_camera(viewer) == 0) {
                int32_t delta_x = current_pos.x() - mouse_state.last_pos.x();
                int32_t delta_y = current_pos.y() - mouse_state.last_pos.y();

                float current_yaw = lv::gltf_get_yaw(viewer);
                float current_pitch = lv::gltf_get_pitch(viewer);

                float new_yaw = current_yaw + (delta_x * -mouse_state.sensitivity);
                float new_pitch = current_pitch + (delta_y * -mouse_state.sensitivity);

                if(new_pitch > 89.0f)
                    new_pitch = 89.0f;
                if(new_pitch < -89.0f)
                    new_pitch = -89.0f;
                if(new_pitch > 0)
                    new_pitch = 0;


                yaw_subject->set(new_yaw);
                pitch_subject->set(new_pitch);
            }
            mouse_state.last_pos = current_pos;
            break;

        case LV_EVENT_RELEASED:
        case LV_EVENT_PRESS_LOST:
            mouse_state.is_dragging = false;
            break;
        default:
            break;
    }
}

void show_foldout(Foldout * foldout)
{
    if(last_opened_foldout != nullptr) {
        hide_foldout(last_opened_foldout);
    }
    last_opened_foldout = foldout;
    foldout->contents_visible = true;
    if(foldout->contents) {
        foldout->contents.remove_flag(lv::ObjFlag::Hidden);
    }
    if(foldout->title) {
        foldout->title.remove_flag(lv::ObjFlag::Hidden);
    }
    if(foldout->title_button) {
        foldout->title_button.add_flag(lv::ObjFlag::Hidden);
    }
}

void hide_foldout(Foldout * foldout)
{
    last_opened_foldout = nullptr;
    foldout->contents_visible = false;
    if(foldout->contents) {
        foldout->contents.add_flag(lv::ObjFlag::Hidden);
    }
    if(foldout->title) {
        foldout->title.add_flag(lv::ObjFlag::Hidden);
    }
    if(foldout->title_button) {
        foldout->title_button.remove_flag(lv::ObjFlag::Hidden);
    }
}

/*
 * The C original's 32 event callbacks are the lambdas at their registration sites now. What
 * is left here is what more than one of them shares.
 */

/* A checkable button reads CHECKED after LVGL has toggled it, so "checked" means "was closed". */
void toggle_hatch(Hatch * hatch)
{
    if(hatch->checkbox.has_state(lv::State::Checked)) {
        close_hatch(hatch);
    }
    else {
        open_hatch(hatch);
    }
}

void gas_pressing()
{
    const float SPEED_GAIN_PER_SECOND_OF_GAS = 25.f;
    const float SPEED_GAIN_PER_FRAME_OF_GAS = SPEED_GAIN_PER_SECOND_OF_GAS / (float)LV_DEF_REFR_PERIOD;
    const float SPEED_GAIN_NORM_PER_FRAME_OF_GAS = SPEED_GAIN_PER_FRAME_OF_GAS / MAX_SPEED_KMH;

    float new_norm = tireset_controller->goal_speed_ratio + SPEED_GAIN_NORM_PER_FRAME_OF_GAS;
    tireset_controller->tach_offset += (SPEED_GAIN_NORM_PER_FRAME_OF_GAS * 5.f);
    tireset_controller->tach_offset = tireset_controller->tach_offset > 1.0f ? 1.0f : tireset_controller->tach_offset;
    new_norm = new_norm > 1.0f ? 1.0f : new_norm;
    new_norm = new_norm < 0.0f ? 0.0f : new_norm;
    int32_t new_slider_value = new_norm * MAX_SPIN_SLIDER_VALUE;
    tireset_controller->slider_speed.set_value(new_slider_value, LV_ANIM_OFF);
    set_tireset_speed_ratio(tireset_controller, new_norm);
}

void brakes_pressing()
{
    const float SPEED_LOST_PER_SECOND_OF_BRAKES = 15.f;
    const float SPEED_LOST_PER_FRAME_OF_BRAKES = SPEED_LOST_PER_SECOND_OF_BRAKES / (float)LV_DEF_REFR_PERIOD;
    const float SPEED_LOSS_NORM_PER_FRAME_OF_BRAKES = SPEED_LOST_PER_FRAME_OF_BRAKES / MAX_SPEED_KMH;

    float new_norm = tireset_controller->goal_speed_ratio - SPEED_LOSS_NORM_PER_FRAME_OF_BRAKES;
    tireset_controller->tach_offset -= (SPEED_LOSS_NORM_PER_FRAME_OF_BRAKES * 8.f);
    tireset_controller->tach_offset = tireset_controller->tach_offset < -1.0f ? -1.0f : tireset_controller->tach_offset;
    new_norm = new_norm > 1.0f ? 1.0f : new_norm;
    new_norm = new_norm < 0.0f ? 0.0f : new_norm;
    int32_t new_slider_value = new_norm * MAX_SPIN_SLIDER_VALUE;
    tireset_controller->slider_speed.set_value(new_slider_value, LV_ANIM_OFF);
    set_tireset_speed_ratio(tireset_controller, new_norm);
}

double distance_per_revolution(double tire_radius)
{
    return 2 * PI * tire_radius; // distance = circumference
}


double revolution_rate(double tire_radius, double travel_rate_kmh)
{
    double distance_per_revolution_meters = distance_per_revolution(tire_radius);
    double distance_per_minute = (travel_rate_kmh * 1000) / 60; // Convert km/h to m/min
    return distance_per_minute / distance_per_revolution_meters; // RPM
}


/**************************
*   STATIC STATE SETTERS
***************************/

void set_tire_type(Tire * tire, TireType tire_type)
{
    switch(tire_type) {
        case TireType::Clean:
            show_node(tire->node_tire_type1);
            hide_node(tire->node_tire_type2);
            break;
        case TireType::Dirty:
            hide_node(tire->node_tire_type1);
            show_node(tire->node_tire_type2);
            break;
        default:
            show_node(tire->node_tire_type1);
            hide_node(tire->node_tire_type2);
            break;
    }
}

void set_tireset_type(TiresetController * tireset, TireType tire_type)
{
    tireset->tire_type = tire_type;
    set_tire_type(tireset->tire_FD_spin, tire_type);
    set_tire_type(tireset->tire_FP_spin, tire_type);
    set_tire_type(tireset->tire_BDP_spin, tire_type);
}

void set_tireset_speed_type(TiresetController * tireset, SpeedUnit speed_type)
{
    tireset->speed_type = speed_type;
    if(speed_type == SpeedUnit::Mph) {
        tireset->checkbox_mph.add_state(lv::State::Checked);
        tireset->checkbox_kmph.remove_state(lv::State::Checked);
        tireset->label_speed_type.set_text_static("mph");
    }
    else {
        tireset->checkbox_kmph.add_state(lv::State::Checked);
        tireset->checkbox_mph.remove_state(lv::State::Checked);
        tireset->label_speed_type.set_text_static("km/h");
    }
    set_tireset_speed_ratio(tireset, tireset->goal_speed_ratio);
}

void set_lightset_blinker_type(LightsetController * lights, Blinker blinker_type)
{
    if(lights->blinker_setting == blinker_type) {
        blinker_type = Blinker::None;
    }
    left_blinker_btn.remove_state(lv::State::Checked);
    right_blinker_btn.remove_state(lv::State::Checked);
    hazard_blinker_btn.remove_state(lv::State::Checked);
    lights->blinker_setting = blinker_type;
    lights->blinker_set_angle = tireset_controller->last_steer_angle;
    lights->blinker_ext_angle = tireset_controller->last_steer_angle;
    switch(blinker_type) {
        case Blinker::Unset:
        case Blinker::None:
            break;
        case Blinker::Left:
            left_blinker_btn.add_state(lv::State::Checked);
            break;
        case Blinker::Right:
            right_blinker_btn.add_state(lv::State::Checked);
            break;
        case Blinker::Hazard:
            hazard_blinker_btn.add_state(lv::State::Checked);
            break;
    }
}

void set_lightset_headlight_type(LightsetController * lights, Headlights headlights_type)
{
    if(lights->headlights_setting == headlights_type) {
        headlights_type = Headlights::Off;
    }
    lights->headlights_setting = headlights_type;
    lights->checkbox_headlights_low.remove_state(lv::State::Checked);
    lights->checkbox_headlights_high.remove_state(lv::State::Checked);
    switch(headlights_type) {
        case Headlights::Low:
            lights->checkbox_headlights_low.add_state(lv::State::Checked);
            break;
        case Headlights::High:
            lights->checkbox_headlights_high.add_state(lv::State::Checked);
            break;
        case Headlights::Off:
        default:
            break;
    }

}

void set_camera_num(CameraController * cameras, Camera camera_type)
{
    cameras->next_camera_setting = camera_type;
    cameras->checkbox_camera_interior.remove_state(lv::State::Checked);
    cameras->checkbox_camera_exterior.remove_state(lv::State::Checked);
    cameras->checkbox_camera_free.remove_state(lv::State::Checked);
    switch(camera_type) {
        case Camera::Interior:
            cameras->checkbox_camera_interior.add_state(lv::State::Checked);
            lv::gltf_set_camera(cameras->viewer, 2);
            break;
        case Camera::Exterior:
            cameras->checkbox_camera_exterior.add_state(lv::State::Checked);
            lv::gltf_set_camera(cameras->viewer, 1);
            break;
        case Camera::Unset:
        default:
            cameras->checkbox_camera_free.add_state(lv::State::Checked);
            lv::gltf_set_camera(cameras->viewer, 0);
            break;
    }

}

void set_wiper_speed(WipersController * wipers, WipersSetting wipers_setting)
{
    if(wipers->next_wipers_setting == wipers_setting) {
        wipers_setting = WipersSetting::Off;
    }
    //wipers->wipers_setting = wipers_setting;
    wipers->next_wipers_setting = wipers_setting;

    wipers->btn_wipers_low.remove_state(lv::State::Checked);
    wipers->btn_wipers_med.remove_state(lv::State::Checked);
    wipers->btn_wipers_high.remove_state(lv::State::Checked);
    switch(wipers_setting) {
        case WipersSetting::Int:
            wipers->btn_wipers_low.add_state(lv::State::Checked);
            break;
        case WipersSetting::Low:
            wipers->btn_wipers_med.add_state(lv::State::Checked);
            break;
        case WipersSetting::High:
            wipers->btn_wipers_high.add_state(lv::State::Checked);
            break;
        case WipersSetting::Off:
        default:
            break;
    }
    if(wipers->running == nullptr) wipers->running = wipers->anim.start();

}

void set_tireset_speed_ratio(TiresetController * tireset, float max_speed_ratio)
{
    tireset->goal_speed_ratio = max_speed_ratio;
    float goal_spin = tireset->goal_speed_ratio * MAX_SPIN_RATE;
    tireset->goal_spin_rate = goal_spin;
    tireset->tire_FD_spin->goal_spin_rate = tireset->goal_spin_rate;
    tireset->tire_FP_spin->goal_spin_rate = tireset->goal_spin_rate;
    tireset->tire_BDP_spin->goal_spin_rate = tireset->goal_spin_rate;
    char speed[8];
    float conv_factor = 1.f;
    if(tireset->speed_type == SpeedUnit::Mph) {
        conv_factor = KM_TO_MILE;
    }
    lv::sprintf_snprintf(speed, sizeof(speed), "%0.0f", (tireset->goal_speed_ratio  * MAX_SPEED_KMH * conv_factor));
    tireset_controller->label_speed.set_text(speed);
}

void set_tireset_steer_ratio(TiresetController * tireset, float goal_steer_ratio)
{
    tireset->goal_steer_ratio = goal_steer_ratio;
    tireset->goal_steer_angle = -(tireset->goal_steer_ratio * MAX_STEER_ANGLE);
}

void select_paintset_A()
{
    hide_all_paintsets();
    show_paintset(paintset_red);
}

void select_paintset_B()
{
    hide_all_paintsets();
    show_paintset(paintset_gray);
}

void select_paintset_C()
{
    hide_all_paintsets();
    show_paintset(paintset_green);
}

void hide_all_paintsets()
{
    hide_paintset(paintset_red);
    hide_paintset(paintset_gray);
    hide_paintset(paintset_green);
}

void hide_node(lv::GltfModelNode node)
{
    if(!node) return;
    node.set_scale_x(0.f);
    node.set_scale_y(0.f);
    node.set_scale_z(0.f);
}

void show_node(lv::GltfModelNode node)
{
    if(!node) return;
    node.set_scale_x(1.f);
    node.set_scale_y(1.f);
    node.set_scale_z(1.f);
}

void show_paintset(Paintset * paintset)
{
    LV_ASSERT_NULL(paintset);
    paintset->button.add_state(lv::State::Checked);
    show_node(paintset->body_node);
    show_node(paintset->hood_node);
    show_node(paintset->door_FD_node);
    show_node(paintset->door_FP_node);
    show_node(paintset->door_BD_node);
    show_node(paintset->door_BP_node);
    show_node(paintset->tailgate_node);
}

void hide_paintset(Paintset * paintset)
{
    LV_ASSERT_NULL(paintset);
    paintset->button.remove_state(lv::State::Checked);
    hide_node(paintset->body_node);
    hide_node(paintset->hood_node);
    hide_node(paintset->door_FD_node);
    hide_node(paintset->door_FP_node);
    hide_node(paintset->door_BD_node);
    hide_node(paintset->door_BP_node);
    hide_node(paintset->tailgate_node);
}

void apply_dirt(bool truck_is_dirty)
{
    if(truck_is_dirty) {
        tireset_controller->tire_type = TireType::Dirty;
        show_node(node_dirty_overlay_1);
        show_node(node_dirty_overlay_2);
        show_node(node_dirty_overlay_3);
    }
    else {
        tireset_controller->tire_type = TireType::Clean;
        hide_node(node_dirty_overlay_1);
        hide_node(node_dirty_overlay_2);
        hide_node(node_dirty_overlay_3);
    }
    set_tireset_type(tireset_controller, tireset_controller->tire_type);
}

void enable_antialiasing(bool use_antialiasing)
{
    if(use_antialiasing) {
        checkbox_antialiasing.add_state(lv::State::Checked);
        lv::gltf_set_antialiasing_mode(camera_controller->viewer, lv::GltfAaMode::On);
    }
    else {
        checkbox_antialiasing.remove_state(lv::State::Checked);
        lv::gltf_set_antialiasing_mode(camera_controller->viewer, lv::GltfAaMode::Off);
    }
}

void open_all_doors()
{
    open_hatch(door_FD_open_close);
    open_hatch(door_FP_open_close);
    open_hatch(door_BD_open_close);
    open_hatch(door_BP_open_close);
}

void close_all_doors()
{
    close_hatch(door_FD_open_close);
    close_hatch(door_FP_open_close);
    close_hatch(door_BD_open_close);
    close_hatch(door_BP_open_close);
}

void open_all_windows()
{
    open_hatch(window_FD_open_close);
    open_hatch(window_FP_open_close);
    open_hatch(window_BD_open_close);
    open_hatch(window_BP_open_close);
    open_hatch(sunroof_open_close);
}

void close_all_windows()
{
    close_hatch(window_FD_open_close);
    close_hatch(window_FP_open_close);
    close_hatch(window_BD_open_close);
    close_hatch(window_BP_open_close);
    close_hatch(sunroof_open_close);
}

void open_hatch(Hatch * hatch)
{
    LV_ASSERT_NULL(hatch);

    if(hatch->hatch_state == HatchState::Unset) {
        hatch->hatch_state = HatchState::Open;
        hatch_update_checkbox(hatch);
        return;
    }

    hatch->hatch_state = HatchState::Open;
    int32_t start_value = hatch->last_set_value;
    int32_t goal_value = (int32_t)(hatch->open_degrees * 100.f);
    if(start_value == goal_value) return;
    hatch->anim.set_values(start_value, goal_value);
    /* By `var`, as in wipers_anim_cb. */
    if(hatch->running != nullptr) lv::anim_delete(hatch, nullptr);
    hatch->running = hatch->anim.start();

}

void close_hatch(Hatch * hatch)
{
    LV_ASSERT_NULL(hatch);

    if(hatch->hatch_state == HatchState::Unset) {
        hatch->hatch_state = HatchState::Closed;
        hatch_update_checkbox(hatch);
        return;
    }

    hatch->hatch_state = HatchState::Closed;
    int32_t start_value = hatch->last_set_value;
    int32_t goal_value = (int32_t)(hatch->closed_degrees * 100.f);
    if(start_value == goal_value) return;
    hatch->anim.set_values(start_value, goal_value);
    if(hatch->running != nullptr) lv::anim_delete(hatch, nullptr);
    hatch->running = hatch->anim.start();
}

/**************************
 *   STATIC INITIALIZERS
 **************************/

void init_anim_controllers(lv::Obj viewer)
{
    const uint32_t DOOR_OPEN_CLOSE_MS = 500;
    door_FD_open_close = lv_demo_truck_hatch(viewer, door_FD_path, DOOR_OPEN_CLOSE_MS, -60.f, 0.f, HatchType::Door);
    door_FP_open_close = lv_demo_truck_hatch(viewer, door_FP_path, DOOR_OPEN_CLOSE_MS, 60.f, 0.f, HatchType::Door);
    door_BD_open_close = lv_demo_truck_hatch(viewer, door_BD_path, DOOR_OPEN_CLOSE_MS, -60.f, 0.f, HatchType::Door);
    door_BP_open_close = lv_demo_truck_hatch(viewer, door_BP_path, DOOR_OPEN_CLOSE_MS, 60.f, 0.f, HatchType::Door);
    hood_open_close = lv_demo_truck_hatch(viewer, hood_path, DOOR_OPEN_CLOSE_MS, -40.f, 0.f, HatchType::TrunkHood);
    tailgate_open_close = lv_demo_truck_hatch(viewer, tailgate_path, DOOR_OPEN_CLOSE_MS, -85.f, 0.f, HatchType::TrunkHood);

    const uint32_t WINDOW_OPEN_CLOSE_MS = 1500;
    window_FD_open_close = lv_demo_truck_hatch(viewer, window_FD_path, WINDOW_OPEN_CLOSE_MS, -9.5f, 0.f, HatchType::Window);
    window_FP_open_close = lv_demo_truck_hatch(viewer, window_FP_path, WINDOW_OPEN_CLOSE_MS, 9.5f, 0.f, HatchType::Window);
    window_BD_open_close = lv_demo_truck_hatch(viewer, window_BD_path, WINDOW_OPEN_CLOSE_MS, -9.5f, 0.f, HatchType::Window);
    window_BP_open_close = lv_demo_truck_hatch(viewer, window_BP_path, WINDOW_OPEN_CLOSE_MS, 9.5f, 0.f, HatchType::Window);
    sunroof_open_close = lv_demo_truck_hatch(viewer, sunroof_path, WINDOW_OPEN_CLOSE_MS, -0.202454f, 0.202454f,
                                             HatchType::Sunroof);

}

void init_paintset_controllers(lv::Obj viewer)
{
    paintset_red = lv_demo_truck_paintset(viewer, paintset_A_body, paintset_A_hood, paintset_A_door_FD, paintset_A_door_FP,
                                          paintset_A_door_BD, paintset_A_door_BP, paintset_A_tailgate);
    paintset_gray = lv_demo_truck_paintset(viewer, paintset_B_body, paintset_B_hood, paintset_B_door_FD, paintset_B_door_FP,
                                           paintset_B_door_BD, paintset_B_door_BP, paintset_B_tailgate);
    paintset_green = lv_demo_truck_paintset(viewer, paintset_C_body, paintset_C_hood, paintset_C_door_FD,
                                            paintset_C_door_FP,
                                            paintset_C_door_BD, paintset_C_door_BP, paintset_C_tailgate);

    lv::GltfModel model = lv::gltf_get_primary_model(viewer);
    node_dirty_overlay_1 = lv::gltf_model_node_get_by_path(model, dirty_overlay_1);
    node_dirty_overlay_2 = lv::gltf_model_node_get_by_path(model, dirty_overlay_2);
    node_dirty_overlay_3 = lv::gltf_model_node_get_by_path(model, dirty_overlay_3);

}

void init_tire_controllers(lv::Obj viewer)
{
    MAX_SPIN_RATE = (revolution_rate(0.222f, MAX_SPEED_KMH) / 60.f) * ((float)LV_DEF_REFR_PERIOD / 1000.f);
    tireset_controller = lv_demo_truck_tireset_controller(viewer, TireType::Dirty);
}

void init_lights_controller(lv::Obj viewer)
{
    lights_controller = lv_demo_truck_lightset_controller(viewer);
}

void init_wipers_controller(lv::Obj viewer)
{
    wipers_controller = lv_demo_truck_wipers_controller(viewer);
}

void init_interior_controller(lv::Obj viewer)
{
    interior_controller = lv_demo_truck_interior(viewer);
}

void init_camera_controller(lv::Obj viewer)
{
    camera_controller = lv_demo_truck_camera_controller(viewer);
}

void init_subjects(lv::Obj viewer)
{
    lv::GltfModel model = lv::gltf_get_primary_model(viewer);
    yaw_subject = new lv::SubjectOf<float>(lv::gltf_get_yaw(viewer));
    pitch_subject = new lv::SubjectOf<float>(lv::gltf_get_pitch(viewer));
    animation_speed_subject = new lv::SubjectOf<int32_t>(LV_GLTF_ANIM_SPEED_NORMAL);
    animation_subject = new lv::SubjectOf<int32_t>((int32_t)model.get_animation());

    /* The C original passed the viewer as user_data and cast it back; the lambdas capture it. */
    animation_subject->add_observer([viewer](lv::Observer, lv_subject_t *) {
        lv::gltf_get_primary_model(viewer).play_animation(animation_subject->get());
    });
    animation_speed_subject->add_observer([viewer](lv::Observer, lv_subject_t *) {
        lv::gltf_get_primary_model(viewer).set_animation_speed(animation_speed_subject->get());
    });
    /* ...and smuggled lv_gltf_set_pitch / lv_gltf_set_yaw through a union with a void *, to share
     * one observer between the two. Two captureless lambdas cost nothing to store. */
    pitch_subject->add_observer_obj(viewer, [](lv::Observer observer, lv_subject_t *) {
        lv::gltf_set_pitch(observer.get_target_obj(), pitch_subject->get());
    });
    yaw_subject->add_observer_obj(viewer, [](lv::Observer observer, lv_subject_t *) {
        lv::gltf_set_yaw(observer.get_target_obj(), yaw_subject->get());
    });
}

void init_checkbox_states()
{
    hatch_update_checkbox(door_FD_open_close);
    hatch_update_checkbox(door_FP_open_close);
    hatch_update_checkbox(door_BD_open_close);
    hatch_update_checkbox(door_BP_open_close);
    hatch_update_checkbox(hood_open_close);
    hatch_update_checkbox(tailgate_open_close);

    hatch_update_checkbox(window_FD_open_close);
    hatch_update_checkbox(window_FP_open_close);
    hatch_update_checkbox(window_BD_open_close);
    hatch_update_checkbox(window_BP_open_close);
    hatch_update_checkbox(sunroof_open_close);
}
/*******************************
 *   STATIC UI PANEL CREATORS
 *******************************/

void create_control_panel(lv::Obj viewer)
{
    lv::Obj control_panel = lv::Obj::create(viewer);
    control_panel.set_size(LV_PCT(20), LV_PCT(100));
    control_panel.align(lv::Align::RightMid, 0, 0);
    style_control_panel(control_panel);

    create_about_panel(control_panel, viewer);
    create_doors_panel(control_panel, viewer);
    create_windows_panel(control_panel, viewer);
    create_paint_panel(control_panel, viewer);
    create_speed_panel(control_panel, viewer);
    create_steering_panel(control_panel, viewer);
    create_headlights_panel(control_panel, viewer);
    create_wipers_panel(control_panel, viewer);

    create_camera_panel(control_panel, viewer);
    create_options_panel(control_panel, viewer);

    //create_animation_panel(control_panel, viewer);
    //create_background_panel(control_panel);
    //create_antialiasing_panel(control_panel);

}

void create_about_panel(lv::Obj parent, lv::Obj viewer)
{
    LV_UNUSED(viewer);

    // lv::Obj panel = add_foldout_header(parent, "About");

    logo_viewer = lv::gltf_create(parent);
    logo_viewer.set_size(128, 64);
    parent.style(lv::Part::Main).pad_top(25).pad_bottom(25).margin_all(0);
    logo_viewer.style(lv::Part::Main).pad_all(0).margin_all(0).margin_top(-12).margin_left(10);
    logo_viewer.remove_flag(lv::ObjFlag::Scrollable);
    lv::gltf_set_background_mode(logo_viewer, lv::GltfBgMode::Solid);

    char logo_model_path[256];
    lv::sprintf_snprintf(logo_model_path, sizeof(logo_model_path), "%s/%s", ui_assets_path, "lvgl_logo_with_text.glb");
    lv::GltfModel model = lv::gltf_load_model_from_file(logo_viewer, logo_model_path);
    LV_ASSERT_NULL(model.raw());
    model.play_animation(0);
    lv::gltf_set_camera(logo_viewer, 1);
    lv::gltf_set_antialiasing_mode(logo_viewer, lv::GltfAaMode::On);

    lv::Label title_label = lv::Label::create(parent);
    title_label.set_text_static("   9.5.0   ");
    title_label.style(lv::Part::Main)
    .text_font(lv::font_montserrat_14)
    .text_color(lv::Color::white())
    .margin_bottom(2)
    .margin_top(-32)
    .margin_left(81)
    .bg_color(lv::Color::hex3(0x000000))
    .bg_opa(LV_OPA_50)
    .radius(3);
    add_sep(parent);
}

/* The door and window grids repeat this block once per hatch in the C original. */
lv::Button add_hatch_toggle(lv::Obj grid, const char * label, Hatch * hatch)
{
    lv::Button button = add_labeled_event_button_to_row(grid, lv::Color::hex(ACCENT_COLOR), label,
    [hatch](auto &) {
        toggle_hatch(hatch);
    });
    button.set_size(LV_PCT(47), 34);
    button.add_flag(lv::ObjFlag::Checkable);
    style_toggle_button(button, lv::Color::hex(ACCENT_COLOR));
    return button;
}

void create_doors_panel(lv::Obj parent, lv::Obj viewer)
{
    LV_UNUSED(viewer);
    lv::Obj panel = add_foldout_header(parent, "Doors");
    panel.style(lv::Part::Main).pad_top(0);

    /* --- Open All / Close All row --- */
    lv::Obj doors_button_row = add_row(panel);
    doors_button_row.set_flex_flow(lv::FlexFlow::Row);
    doors_button_row.style(lv::Part::Main).pad_all(15).pad_top(0).pad_bottom(0);

    open_all_doors_btn = add_labeled_event_button_to_row(doors_button_row, lv::Color::hex(0xFF6B35), "Open All",
    [](auto &) {
        open_all_doors();
    });
    style_toggle_button(open_all_doors_btn, lv::Color::hex(0xFF6B35));

    close_all_doors_btn = add_labeled_event_button_to_row(doors_button_row, lv::Color::hex(0xFF6B35), "Close All",
    [](auto &) {
        close_all_doors();
    });
    style_toggle_button(close_all_doors_btn, lv::Color::hex(0xFF6B35));
    close_all_doors_btn.add_flag(lv::ObjFlag::Hidden);

    /* --- 2x2 door grid --- */
    lv::Obj door_grid = add_row(panel);
    door_grid.set_flex_flow(lv::FlexFlow::RowWrap);
    door_grid.style(lv::Part::Main).pad_all(15).pad_top(0).pad_bottom(8).pad_row(8).pad_column(8);

    /* Row 1: Front Driver | Front Passenger */
    door_FD_open_close->checkbox = add_hatch_toggle(door_grid, "Driver", door_FD_open_close);
    door_FP_open_close->checkbox = add_hatch_toggle(door_grid, "Passenger", door_FP_open_close);

    /* Row 2: Back Driver | Back Passenger */
    door_BD_open_close->checkbox = add_hatch_toggle(door_grid, "Rear Left", door_BD_open_close);
    door_BP_open_close->checkbox = add_hatch_toggle(door_grid, "Rear Right", door_BP_open_close);

    /* --- Hood + Tailgate row --- */
    lv::Obj extra_row = add_row(panel);
    extra_row.set_flex_flow(lv::FlexFlow::Row);
    extra_row.style(lv::Part::Main).pad_all(15).pad_top(0).pad_bottom(8).pad_column(8);

    hood_open_close->checkbox = add_hatch_toggle(extra_row, "Hood", hood_open_close);
    tailgate_open_close->checkbox = add_hatch_toggle(extra_row, "Tailgate", tailgate_open_close);

    add_sep(panel);
}
void create_windows_panel(lv::Obj parent, lv::Obj viewer)
{
    LV_UNUSED(viewer);
    lv::Obj panel = add_foldout_header(parent, "Windows");

    /* --- Open All / Close All row --- */
    lv::Obj windows_row = add_row(panel);
    windows_row.set_flex_flow(lv::FlexFlow::Row);
    windows_row.style(lv::Part::Main).pad_all(15).pad_top(0).pad_bottom(0);

    open_all_windows_btn = add_labeled_event_button_to_row(windows_row, lv::Color::hex(0xFF6B35), "Open All",
    [](auto &) {
        open_all_windows();
    });
    style_toggle_button(open_all_windows_btn, lv::Color::hex(0xFF6B35));

    close_all_windows_btn = add_labeled_event_button_to_row(windows_row, lv::Color::hex(0xFF6B35), "Close All",
    [](auto &) {
        close_all_windows();
    });
    style_toggle_button(close_all_windows_btn, lv::Color::hex(0xFF6B35));
    close_all_windows_btn.add_flag(lv::ObjFlag::Hidden);

    /* --- 2x2 window grid --- */
    lv::Obj window_grid = add_row(panel);
    window_grid.set_flex_flow(lv::FlexFlow::RowWrap);
    window_grid.style(lv::Part::Main).pad_all(15).pad_top(0).pad_bottom(8).pad_row(8).pad_column(8);

    window_FD_open_close->checkbox = add_hatch_toggle(window_grid, "Driver", window_FD_open_close);
    window_FP_open_close->checkbox = add_hatch_toggle(window_grid, "Passenger", window_FP_open_close);
    window_BD_open_close->checkbox = add_hatch_toggle(window_grid, "Rear Left", window_BD_open_close);
    window_BP_open_close->checkbox = add_hatch_toggle(window_grid, "Rear Right", window_BP_open_close);

    /* --- Sunroof row --- */
    lv::Obj sunroof_row = add_row(panel);
    sunroof_row.set_flex_flow(lv::FlexFlow::Row);
    sunroof_row.style(lv::Part::Main).pad_all(15).pad_top(0).pad_bottom(8);

    sunroof_open_close->checkbox = add_hatch_toggle(sunroof_row, "Sunroof", sunroof_open_close);

    add_sep(panel);
}

void create_paint_panel(lv::Obj parent, lv::Obj viewer)
{
    LV_UNUSED(viewer);
    lv::Obj panel = add_foldout_header(parent, "Paint");

    /* --- Paint color selection row --- */
    lv::Obj paint_row = add_row(panel);
    paint_row.set_flex_flow(lv::FlexFlow::Row);
    paint_row.style(lv::Part::Main).pad_all(15).pad_top(0).pad_bottom(8).pad_column(8);

    paintset_red->button = add_labeled_event_button_to_row(paint_row, lv::Color::hex(0xCC2200), "Red",
    [](auto &) {
        select_paintset_A();
    });
    paintset_red->button.set_size(LV_PCT(30), 34);
    paintset_red->button.add_flag(lv::ObjFlag::Checkable);
    style_toggle_button(paintset_red->button, lv::Color::hex(0xCC2200));

    paintset_gray->button = add_labeled_event_button_to_row(paint_row, lv::Color::hex(0x888888), "Gray",
    [](auto &) {
        select_paintset_B();
    });
    paintset_gray->button.set_size(LV_PCT(30), 34);
    paintset_gray->button.add_flag(lv::ObjFlag::Checkable);
    style_toggle_button(paintset_gray->button, lv::Color::hex(0x888888));

    paintset_green->button = add_labeled_event_button_to_row(paint_row, lv::Color::hex(0x2E7D32), "Green",
    [](auto &) {
        select_paintset_C();
    });
    paintset_green->button.set_size(LV_PCT(30), 34);
    paintset_green->button.add_flag(lv::ObjFlag::Checkable);
    style_toggle_button(paintset_green->button, lv::Color::hex(0x2E7D32));

    /* --- Add Mud / Remove Mud row --- */
    lv::Obj mud_row = add_row(panel);
    mud_row.set_flex_flow(lv::FlexFlow::Row);
    mud_row.style(lv::Part::Main).pad_all(15).pad_top(0).pad_bottom(8).pad_column(8);

    mud_toggle_btn = add_labeled_event_button_to_row(mud_row, lv::Color::hex(0xFF6B35), "Add Mud",
    [](auto &) {
        has_mud = !has_mud;
        apply_dirt(has_mud);
        lv::Label btn_label = mud_toggle_btn.get_child(0).as<lv::Label>();
        if(has_mud) {
            btn_label.set_text_static("Remove mud");
            mud_toggle_btn.remove_state(lv::State::Checked);
        }
        else {
            mud_toggle_btn.add_state(lv::State::Checked);
            btn_label.set_text_static("Add mud");
        }
    });
    style_toggle_button(mud_toggle_btn, lv::Color::hex(0xFF6B35));
    mud_toggle_btn.add_state(lv::State::Checked);

    add_sep(panel);
}

void create_speed_panel(lv::Obj parent, lv::Obj viewer)
{
    LV_UNUSED(viewer);
    lv::Obj panel = add_foldout_header(parent, "Speed");

    /* --- Gas / Brake row --- */
    lv::Obj speed_row4 = add_row(panel);
    speed_row4.set_flex_flow(lv::FlexFlow::Row);
    speed_row4.style(lv::Part::Main).pad_all(15).pad_top(0).pad_bottom(0).margin_bottom(0);

    lv::Button gas_btn = add_button_to_row(speed_row4, lv::Color::hex(0x22A646));
    gas_btn.set_size(LV_PCT(35), 30);
    gas_btn.on(lv::events::Pressing, [](auto &) { gas_pressing(); });
    lv::Label gas_btn_label = lv::Label::create(gas_btn);
    gas_btn_label.set_text_static("Gas");
    gas_btn_label.style(lv::Part::Main).text_color(lv::Color::white());
    gas_btn_label.center();

    lv::Button brakes_btn = add_button_to_row(speed_row4, lv::Color::hex(0xD92D2D));
    brakes_btn.set_size(LV_PCT(45), 30);
    brakes_btn.on(lv::events::Pressed, [](auto &) { lights_controller->brakes_active = true; });
    brakes_btn.on(lv::events::Pressing, [](auto &) { brakes_pressing(); });
    brakes_btn.on(lv::events::Released, [](auto &) { lights_controller->brakes_active = false; });
    lv::Label brakes_btn_label = lv::Label::create(brakes_btn);
    brakes_btn_label.set_text_static("Brake");
    brakes_btn_label.style(lv::Part::Main).text_color(lv::Color::white());
    brakes_btn_label.center();

    /* --- Speed readout row --- */
    lv::Obj speed_row3 = add_row(panel);
    speed_row3.set_flex_flow(lv::FlexFlow::Row);
    speed_row3.style(lv::Part::Main).pad_all(15).pad_top(0).pad_bottom(0).margin_top(0).margin_bottom(0);
    lv::Label speed_label = lv::Label::create(speed_row3);
    speed_label.set_text("0");
    speed_label.style(lv::Part::Main).text_color(lv::Color::white());
#if LV_FONT_MONTSERRAT_26
    speed_label.style(lv::Part::Main).text_font(lv::font_montserrat_26);
#endif
    speed_label.center();
    tireset_controller->label_speed = speed_label;

    lv::Label speed_slider_label = lv::Label::create(speed_row3);
    speed_slider_label.set_text_static("km/h");
    speed_slider_label.style(lv::Part::Main).text_color(lv::Color::white());

    speed_slider_label.center();
    tireset_controller->label_speed_type = speed_slider_label;

    /* --- Speed slider row --- */
    lv::Obj speed_row2 = add_row(panel);
    speed_row2.set_flex_flow(lv::FlexFlow::Row);
    speed_row2.style(lv::Part::Main).pad_all(15).pad_top(0).pad_bottom(4).margin_bottom(4);

    lv::Slider speed_slider = add_slider_to_row(speed_row2, lv::Color::hex(0xFF6B35));
    speed_slider.on(lv::events::ValueChanged, [speed_slider](auto &) {
        float goal_spin = ((float)speed_slider.get_value() / MAX_SPIN_SLIDER_VALUE);
        set_tireset_speed_ratio(tireset_controller, goal_spin);
    });
    speed_slider.set_min_value(0);
    speed_slider.style(lv::Part::Main).pad_all(5);
    speed_slider.set_max_value((int32_t)MAX_SPIN_SLIDER_VALUE);
    tireset_controller->slider_speed = speed_slider;

    /* --- Unit toggle row --- */
    lv::Obj unit_row = add_row(panel);
    unit_row.set_flex_flow(lv::FlexFlow::Row);
    unit_row.style(lv::Part::Main).pad_all(15).pad_top(0).pad_bottom(8).pad_column(8);

    lv::Button mph_btn = add_labeled_event_button_to_row(unit_row, lv::Color::hex(0xFF6B35), "mph",
    [](auto &) {
        set_tireset_speed_type(tireset_controller, SpeedUnit::Mph);
    });
    mph_btn.set_size(LV_PCT(47), 34);
    mph_btn.add_flag(lv::ObjFlag::Checkable);
    style_toggle_button(mph_btn, lv::Color::hex(0xFF6B35));
    tireset_controller->checkbox_mph = mph_btn;

    lv::Button kmph_btn = add_labeled_event_button_to_row(unit_row, lv::Color::hex(0xFF6B35), "km/h",
    [](auto &) {
        set_tireset_speed_type(tireset_controller, SpeedUnit::Kmph);
    });
    kmph_btn.set_size(LV_PCT(47), 34);
    kmph_btn.add_flag(lv::ObjFlag::Checkable);
    style_toggle_button(kmph_btn, lv::Color::hex(0xFF6B35));
    tireset_controller->checkbox_kmph = kmph_btn;

    add_sep(panel);
}

void create_steering_panel(lv::Obj parent, lv::Obj viewer)
{
    LV_UNUSED(viewer);
    lv::Obj panel = add_foldout_header(parent, "Steering");

    /* --- Steering slider row --- */
    lv::Obj steering_row2 = add_row(panel);
    steering_row2.set_flex_flow(lv::FlexFlow::Row);
    steering_row2.style(lv::Part::Main).pad_all(15).pad_top(0).pad_bottom(4).margin_bottom(4);

    lv::Slider steering_slider = add_slider_to_row(steering_row2, lv::Color::hex(0xFF6B35));
    steering_slider.set_min_value((int32_t) -MIN_MAX_STEER_SLIDER_VALUE);
    steering_slider.set_max_value((int32_t)MIN_MAX_STEER_SLIDER_VALUE);
    steering_slider.set_value(0, LV_ANIM_OFF);
    steering_slider.set_mode(lv::Slider::Mode::Symmetrical);
    steering_slider.style(lv::Part::Main).pad_all(5);
    steering_slider.on(lv::events::ValueChanged, [steering_slider](auto &) {
        float goal_steer = (float)steering_slider.get_value() / MIN_MAX_STEER_SLIDER_VALUE;
        set_tireset_steer_ratio(tireset_controller, goal_steer);
    });
    tireset_controller->slider_steering = steering_slider;

    /* --- Blinker buttons row --- */
    lv::Obj steering_row = add_row(panel);
    steering_row.set_flex_flow(lv::FlexFlow::Row);
    steering_row.style(lv::Part::Main).pad_all(15).pad_top(0).pad_bottom(8).pad_column(8).margin_bottom(0);

    left_blinker_btn = add_button_to_row(steering_row, lv::Color::hex(0xFF6B35));
    left_blinker_btn.set_size(LV_PCT(30), 34);
    left_blinker_btn.add_flag(lv::ObjFlag::Checkable);
    left_blinker_btn.on(lv::events::Clicked, [](auto &) { set_lightset_blinker_type(lights_controller, Blinker::Left); });
    style_toggle_button(left_blinker_btn, lv::Color::hex(0xFF6B35));
    lv::Label left_blinker_label = lv::Label::create(left_blinker_btn);
    left_blinker_label.set_text_static(lv::symbol::LEFT);
    left_blinker_label.style(lv::Part::Main).text_color(lv::Color::white());
    left_blinker_label.center();

    hazard_blinker_btn = add_button_to_row(steering_row, lv::Color::hex(0xFFB300));
    hazard_blinker_btn.set_size(LV_PCT(30), 34);
    hazard_blinker_btn.add_flag(lv::ObjFlag::Checkable);
    hazard_blinker_btn.on(lv::events::Clicked, [](auto &) { set_lightset_blinker_type(lights_controller, Blinker::Hazard); });
    style_toggle_button(hazard_blinker_btn, lv::Color::hex(0xFFB300));
    lv::Label hazard_blinker_label = lv::Label::create(hazard_blinker_btn);
    hazard_blinker_label.set_text_static(lv::symbol::WARNING);
    hazard_blinker_label.style(lv::Part::Main).text_color(lv::Color::white());
    hazard_blinker_label.center();

    right_blinker_btn = add_button_to_row(steering_row, lv::Color::hex(0xFF6B35));
    right_blinker_btn.set_size(LV_PCT(30), 34);
    right_blinker_btn.add_flag(lv::ObjFlag::Checkable);
    right_blinker_btn.on(lv::events::Clicked, [](auto &) { set_lightset_blinker_type(lights_controller, Blinker::Right); });
    style_toggle_button(right_blinker_btn, lv::Color::hex(0xFF6B35));
    lv::Label right_blinker_label = lv::Label::create(right_blinker_btn);
    right_blinker_label.set_text_static(lv::symbol::RIGHT);
    right_blinker_label.style(lv::Part::Main).text_color(lv::Color::white());
    right_blinker_label.center();

    add_sep(panel);
}

void create_headlights_panel(lv::Obj parent, lv::Obj viewer)
{
    LV_UNUSED(viewer);

    lv::Obj panel = add_foldout_header(parent, "Headlights");
    lights_controller->checkbox_headlights_low = add_labeled_checkbox_row(panel, "Low", [](auto &) {
        set_lightset_headlight_type(lights_controller, Headlights::Low);
    });
    lights_controller->checkbox_headlights_high = add_labeled_checkbox_row(panel, "High", [](auto &) {
        set_lightset_headlight_type(lights_controller, Headlights::High);
    });
    add_sep(panel);
}

void create_wipers_panel(lv::Obj parent, lv::Obj viewer)
{

    LV_UNUSED(viewer);
    lv::Obj panel = add_foldout_header(parent, "Wipers");

    lv::Obj wipers_row = add_row(panel);
    wipers_row.set_flex_flow(lv::FlexFlow::Row);
    wipers_row.style(lv::Part::Main).pad_all(15).pad_top(0).pad_bottom(0).margin_bottom(0);

    wipers_controller->btn_wipers_low = add_labeled_event_button_to_row(wipers_row, lv::Color::hex(0xFF6B35), "Slow",
    [](auto &) {
        set_wiper_speed(wipers_controller, WipersSetting::Int);
    });
    wipers_controller->btn_wipers_low.set_size(LV_PCT(25), 30);
    wipers_controller->btn_wipers_low.add_flag(lv::ObjFlag::Checkable);
    style_toggle_button(wipers_controller->btn_wipers_low, lv::Color::hex(0xFF6B35));

    wipers_controller->btn_wipers_med = add_labeled_event_button_to_row(wipers_row, lv::Color::hex(0xFF6B35), "Medium",
    [](auto &) {
        set_wiper_speed(wipers_controller, WipersSetting::Low);
    });
    style_toggle_button(wipers_controller->btn_wipers_med, lv::Color::hex(0xFF6B35));

    wipers_controller->btn_wipers_med.set_size(LV_PCT(25), 30);
    wipers_controller->btn_wipers_high = add_labeled_event_button_to_row(wipers_row, lv::Color::hex(0xFF6B35), "Fast",
    [](auto &) {
        set_wiper_speed(wipers_controller, WipersSetting::High);
    });
    wipers_controller->btn_wipers_high.set_size(LV_PCT(25), 30);
    style_toggle_button(wipers_controller->btn_wipers_high, lv::Color::hex(0xFF6B35));

    add_sep(panel);
}
void create_camera_panel(lv::Obj parent, lv::Obj viewer)
{
    lv::Obj panel = add_foldout_header(parent, "Cameras");

    lv::Obj camera_row = add_row(panel);
    camera_row.set_flex_flow(lv::FlexFlow::Row);
    camera_row.style(lv::Part::Main).pad_all(15).pad_top(0).pad_bottom(8).pad_column(8);

    camera_controller->checkbox_camera_interior = add_labeled_event_button_to_row(camera_row,
                                                                                  lv::Color::hex(0xFF6B35),
                                                                                  "Interior",
    [](auto &) {
        set_camera_num(camera_controller, Camera::Interior);
    });
    camera_controller->checkbox_camera_interior.set_size(LV_PCT(30), 34);
    camera_controller->checkbox_camera_interior.add_flag(lv::ObjFlag::Checkable);
    style_toggle_button(camera_controller->checkbox_camera_interior, lv::Color::hex(0xFF6B35));

    camera_controller->checkbox_camera_exterior = add_labeled_event_button_to_row(camera_row,
                                                                                  lv::Color::hex(0xFF6B35),
                                                                                  "Exterior",
    [](auto &) {
        set_camera_num(camera_controller, Camera::Exterior);
    });
    camera_controller->checkbox_camera_exterior.set_size(LV_PCT(30), 34);
    camera_controller->checkbox_camera_exterior.add_flag(lv::ObjFlag::Checkable);
    style_toggle_button(camera_controller->checkbox_camera_exterior, lv::Color::hex(0xFF6B35));

    camera_controller->checkbox_camera_free = add_labeled_event_button_to_row(camera_row,
                                                                              lv::Color::hex(0xFF6B35),
                                                                              "Free",
    [](auto &) {
        set_camera_num(camera_controller, Camera::Unset);
    });
    camera_controller->checkbox_camera_free.set_size(LV_PCT(30), 34);
    camera_controller->checkbox_camera_free.add_flag(lv::ObjFlag::Checkable);
    style_toggle_button(camera_controller->checkbox_camera_free, lv::Color::hex(0xFF6B35));

    camera_controller->viewer = viewer;
    add_sep(panel);
}

void create_options_panel(lv::Obj parent, lv::Obj viewer)
{
    LV_UNUSED(viewer);
    lv::Obj panel = add_foldout_header(parent, "Options");

    /* --- Resolution label --- */
    lv::Obj res_label_row = add_row(panel);
    res_label_row.set_flex_flow(lv::FlexFlow::Row);
    res_label_row.style(lv::Part::Main).pad_all(15).pad_top(0).pad_bottom(4);

    lv::Label res_label = lv::Label::create(res_label_row);
    res_label.set_text_static("Resolution");
    res_label.style(lv::Part::Main).text_color(lv::Color::hex(0x888888));

    /* --- Resolution dropdown --- */
    lv::Obj res_row = add_row(panel);
    res_row.set_flex_flow(lv::FlexFlow::Row);
    res_row.style(lv::Part::Main).pad_all(15).pad_top(0).pad_bottom(8);

    lv::Dropdown res_dropdown = lv::Dropdown::create(res_row);
    res_dropdown.set_options_static("800 x 480\n"
                                    "800 x 600\n"
                                    "1024 x 600\n"
                                    "1024 x 768\n"
                                    "1024 x 800\n"
                                    "1280 x 720\n"
                                    "1280 x 800\n"
                                    "1366 x 768\n"
                                    "1920 x 1080");
    res_dropdown.set_width(LV_PCT(90));
    res_dropdown.on(lv::events::ValueChanged, [res_dropdown](auto &) {
        static const struct {
            int w, h;
        } resolutions[] = {
            {800,  480}, {800,  600},
            {1024, 600}, {1024, 768}, {1024, 800},
            {1280, 720}, {1280, 800},
            {1366, 768},
            {1920, 1080}
        };

        uint32_t idx = res_dropdown.get_selected();
        lv::display_get_default().set_resolution(resolutions[idx].w, resolutions[idx].h);
    });

    /* Style the dropdown to match the dark theme */
    res_dropdown.style(lv::Part::Main)
    .bg_color(lv::Color::hex(0x1A1A1A))
    .border_color(lv::Color::hex(0x444444))
    .border_width(1)
    .radius(8)
    .text_color(lv::Color::white())
    .shadow_width(0);

    /* Style the dropdown list */
    lv::Obj res_list = res_dropdown.get_list();
    res_list.style(lv::Part::Main)
    .bg_color(lv::Color::hex(0x1A1A1A))
    .border_color(lv::Color::hex(0x444444))
    .border_width(1)
    .radius(8)
    .text_color(lv::Color::white());
    res_list.style(lv::Part::Selected | lv::State::Checked)
    .bg_color(lv::Color::hex(0xFF6B35))
    .text_color(lv::Color::white());

    /* --- Anti-alias toggle --- */
    lv::Obj antialias_row = add_row(panel);
    antialias_row.set_flex_flow(lv::FlexFlow::Row);
    antialias_row.style(lv::Part::Main).pad_all(15).pad_top(0).pad_bottom(8);

    checkbox_antialiasing = add_labeled_event_button_to_row(antialias_row, lv::Color::hex(0xFF6B35), "Anti-Alias",
    [](auto &) {
        enable_antialiasing(checkbox_antialiasing.has_state(lv::State::Checked));
    });
    checkbox_antialiasing.set_size(LV_PCT(60), 34);
    checkbox_antialiasing.add_flag(lv::ObjFlag::Checkable);
    style_toggle_button(checkbox_antialiasing, lv::Color::hex(0xFF6B35));
    add_sep(panel);
}


/*****************************
 *   STATIC UI CREATE UTILS
 *****************************/

lv::Label add_title_to_row(lv::Obj row, const char * title)
{
    lv::Label title_label = lv::Label::create(row);
    title_label.set_text_static(title);
    title_label.style(lv::Part::Main)
    .text_font(lv::font_montserrat_14)
    .text_color(lv::Color::white())
    .margin_bottom(2);
    return title_label;
}

lv::Obj add_foldout_header(lv::Obj parent, const char * title)
{

    Foldout * foldout = lv_demo_foldout(parent, title);
    if(last_opened_foldout == nullptr) {
        /* Show the first foldout (About) */
        show_foldout(foldout);
    }
    else {
        /* Hide the other foldouts */

        /* Retain a reference to the first foldout */
        Foldout * first_foldout = last_opened_foldout;

        /* Hide the new foldout */
        hide_foldout(foldout);

        /* Restore the first foldout reference */
        last_opened_foldout = first_foldout;
    }
    return foldout->contents;
}

lv::Obj add_row(lv::Obj parent)
{
    lv::Obj row = lv::Obj::create(parent);
    row.set_size(LV_PCT(100), LV_SIZE_CONTENT);
    row.style(lv::Part::Main)
    .bg_opa(LV_OPA_TRANSP)
    .border_width(0)
    .pad_left(20)
    .pad_bottom(10)
    .pad_right(20);
    row.set_layout(LV_LAYOUT_FLEX);
    row.set_flex_flow(lv::FlexFlow::Column);
    return row;
}

lv::Obj add_sep(lv::Obj parent)
{
    lv::Obj sep = lv::Obj::create(parent);
    sep.set_size(LV_PCT(100), 3);
    sep.style(lv::Part::Main)
    .bg_opa(LV_OPA_30)
    .bg_color(lv::Color::hex(0xFFFFFF))
    .pad_top(0)
    .pad_bottom(0)
    .margin_left(10)
    .margin_right(10)
    .margin_bottom(0)
    .radius(4)
    .border_width(0);
    return sep;
}



lv::Button add_button_to_row(lv::Obj row, lv::Color color)
{
    lv::Button btn = lv::Button::create(row);
    btn.set_size(LV_PCT(100), 30);
    btn.style(lv::Part::Main).bg_color(color).radius(4);

    return btn;
}

template <class F>
lv::Button add_labeled_event_button_to_row(lv::Obj row, lv::Color color, const char * label, F && on_clicked)
{
    lv::Button button = add_button_to_row(row, color);
    button.on(lv::events::Clicked, std::forward<F>(on_clicked));
    lv::Label button_label = lv::Label::create(button);
    button_label.set_text_static(label);
    button_label.style(lv::Part::Main).text_color(lv::Color::white());
    button_label.center();
    return button;
}

lv::Slider add_slider_to_row(lv::Obj row, lv::Color color)
{
    lv::Slider sldr = lv::Slider::create(row);
    sldr.set_size(LV_PCT(100), 20);
    sldr.style(lv::Part::Main).bg_color(color).radius(4).margin_all(6);
    style_slider(sldr, lv::Color::hex(SLIDER_COLOR));

    return sldr;
}

template <class F>
lv::Checkbox add_checkbox_to_row(lv::Obj row, lv::Color color, F && on_clicked)
{
    lv::Checkbox checkbox = lv::Checkbox::create(row);
    checkbox.set_size(20, CHECKBOX_HEIGHT);
    checkbox.style(lv::Part::Main).pad_all(0).margin_all(0).bg_color(color).radius(4);
    checkbox.on(lv::events::Clicked, std::forward<F>(on_clicked));

    return checkbox;
}

template <class F>
lv::Checkbox add_labeled_checkbox_row(lv::Obj panel, const char * label, F && on_clicked)
{
    lv::Obj row = add_row(panel);
    row.set_flex_flow(lv::FlexFlow::Row);
    row.style(lv::Part::Main).pad_all(15).pad_top(0).pad_bottom(0);

    lv::Checkbox checkbox = add_checkbox_to_row(row, lv::Color::hex(0xFF6B35), std::forward<F>(on_clicked));
    lv::Label checkbox_label = lv::Label::create(row);
    checkbox_label.style(lv::Part::Main).pad_top(2);
    checkbox_label.set_text_static(label);
    checkbox_label.style(lv::Part::Main).text_color(lv::Color::white());
    style_checkbox(checkbox, lv::Color::hex(0xFF6B35));
    return checkbox;
}


void style_checkbox(lv::Obj checkbox, lv::Color accent_color)
{
    /* --- Tick box (the square) --- */
    checkbox.style(lv::Part::Indicator)
    .radius(6)
    .bg_color(lv::Color::hex(0x1A1A1A))
    .border_width(2)
    .border_color(lv::Color::hex(0x444444));

    /* Checked state */
    checkbox.style(lv::Part::Indicator | lv::State::Checked)
    .bg_color(accent_color)
    .border_color(accent_color)
    .shadow_width(8)
    .shadow_color(accent_color)
    .shadow_opa(150);

    /* Pressed state */
    checkbox.style(lv::Part::Indicator | lv::State::Pressed)
    .bg_color(lv::Color::mix(accent_color, lv::Color::black(), 180))
    .border_color(accent_color);

    checkbox.style(lv::Part::Indicator | lv::State::Disabled)
    .bg_color(lv::Color::hex(0x0F0F0F))
    .border_color(lv::Color::hex(0x222222))
    .opa(102);

    checkbox.style(lv::Part::Main).shadow_width(0).bg_opa(LV_OPA_TRANSP);
}

void style_toggle_button(lv::Obj btn, lv::Color accent_color)
{
    /* --- Default (unselected) state --- */
    btn.style(lv::Part::Main)
    .bg_color(lv::Color::hex(0x1A1A1A))
    .radius(8)
    .border_width(1)
    .border_color(lv::Color::hex(0x444444))
    .shadow_width(0)
    /* Label color unselected */
    .text_color(lv::Color::hex(0x888888));

    /* --- Pressed state --- */
    btn.style(lv::Part::Main | lv::State::Pressed)
    .bg_color(lv::Color::mix(accent_color, lv::Color::black(), 180))
    .border_color(accent_color)
    .text_color(lv::Color::white());

    /* --- Checked/active state (for toggle buttons) --- */
    btn.style(lv::Part::Main | lv::State::Checked)
    .bg_color(accent_color)
    .border_color(accent_color)
    .text_color(lv::Color::white())
    .shadow_width(10)
    .shadow_color(accent_color)
    .shadow_opa(150);

    /* --- Disabled state --- */
    btn.style(lv::Part::Main | lv::State::Disabled)
    .bg_color(lv::Color::hex(0x0F0F0F))
    .border_color(lv::Color::hex(0x222222))
    .text_color(lv::Color::hex(0x444444))
    .opa(102);
}

void style_slider(lv::Obj slider, lv::Color accent_color)
{
    slider.style(lv::Part::Main)
    .bg_color(lv::Color::hex(0x1A1A1A))
    .radius(20)
    .border_width(1)
    .border_color(lv::Color::hex(0x444444));

    slider.style(lv::Part::Indicator).bg_color(accent_color).radius(20);

    slider.style(lv::Part::Knob)
    .bg_color(lv::Color::white())
    .radius(LV_RADIUS_CIRCLE)
    .shadow_width(6)
    .shadow_color(accent_color)
    .shadow_opa(150)
    .border_width(2)
    .border_color(accent_color);

    slider.style(lv::Part::Main | lv::State::Disabled)
    .bg_color(lv::Color::hex(0x0F0F0F))
    .border_color(lv::Color::hex(0x222222))
    .opa(128);

    lv::Color dimmed_accent = lv::Color::mix(accent_color, lv::Color::black(), 128);
    slider.style(lv::Part::Indicator | lv::State::Disabled).bg_color(dimmed_accent).opa(102);

    slider.style(lv::Part::Knob | lv::State::Disabled)
    .bg_color(lv::Color::hex(0xCCCCCC))
    .shadow_width(2)
    .shadow_opa(51);
}



void style_control_panel(lv::Obj panel)
{

    panel.style(lv::Part::Main)
    .bg_color(lv::Color::hex(0x2C2C2C))
    .border_width(1)
    .border_color(lv::Color::hex(0x555555))
    .radius(8)
    .pad_all(5);
    panel.set_layout(LV_LAYOUT_FLEX);
    panel.set_flex_flow(lv::FlexFlow::Column);

    panel.set_flex_align(lv::FlexAlign::Start, lv::FlexAlign::Start, lv::FlexAlign::Start);
    panel.style(lv::Part::Main).bg_opa(128);

}

} // namespace
