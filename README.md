# LVGL glTF Demo - Truck Demo

This is an example of loading a glTF and adjusting it's presentation factors in realtime.
It started as a port of lv_port_linux.

The truck model and the initial commit of this repo was created by Matt Kimball for LVGL.

## C++

The demo is written in C++20 on top of [lvglpp](lvglpp/README.md), the C++ binding that
[cpp-binding](https://github.com/edeavilac/cpp-binding) generates for the LVGL in `lvgl/`.
`ui/src/lv_demo_truck.cpp` is a port of the original C demo that keeps its structure and
order, and its header comment lists what the binding changes. `src/main.cpp` still calls the
display and input drivers in C, because the binding does not wrap `src/drivers`.

