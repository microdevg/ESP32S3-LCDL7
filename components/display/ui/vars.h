#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// enum declarations

// Flow global variables

enum FlowGlobalVariables {
    FLOW_GLOBAL_VARIABLE_TEMP = 0,
    FLOW_GLOBAL_VARIABLE_CONFIG = 1
};

// Native global variables

extern const char *get_var_temp();
extern void set_var_temp(const char *value);
extern const char *get_var_config();
extern void set_var_config(const char *value);

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/