#ifndef LVGL_JOYSTICK_H
#define LVGL_JOYSTICK_H

#ifdef __cplusplus
extern "C" {
#endif

#pragma once
#include <lvgl.h>

// Callback function type
typedef void (*joystick_position_cb_t)(uint8_t joystick_id, int16_t x,
                                       int16_t y);

// Enum for how joystick reports data in the callback
typedef enum {
  JOYSTICK_REPORT_MODE_ABSOLUTE,  // stick position relation to center
  JOYSTICK_REPORT_MODE_RELATIVE   // stick change in position
} joystick_report_mode_t;

// Structure to hold joystick data
typedef struct {
  uint8_t joystick_id;
  uint8_t base_radius;
  uint8_t stick_radius;
  joystick_report_mode_t report_mode;
  joystick_position_cb_t position_callback;
} joystick_data_t;

// Function prototypes
void create_joystick(lv_obj_t *parent, uint8_t joystick_id,
                     lv_align_t base_align, int base_x, int base_y,
                     int base_radius, int stick_radius, lv_style_t *base_style,
                     lv_style_t *stick_style,
                     joystick_position_cb_t position_callback,
                     joystick_report_mode_t report_mode);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif  // LVGL_JOYSTICK_H
