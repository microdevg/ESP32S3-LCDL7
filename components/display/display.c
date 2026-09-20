#include <stdio.h>
#include "display.h"
#include "waveshare_rgb_lcd_port.h"
#include "ui/ui.h"

#include "ui/vars.h"


#include <string.h>
#include "ui/vars.h"


#define TEMPERATURA_STRING_LEN  20

char temperatura[TEMPERATURA_STRING_LEN] = { 0 };




char* get_var_temperatura() {
    return temperatura;
}

void set_var_temperatura(const char *value) {
    strncpy(temperatura, value, sizeof(temperatura) / sizeof(char));
    temperatura[sizeof(temperatura) / sizeof(char) - 1] = 0;
}




esp_err_t display_init(void)
{

    waveshare_esp32_s3_rgb_lcd_init(); 
    wavesahre_rgb_lcd_bl_on();  

    return ESP_OK;
}

esp_err_t display_ui_start(){
        ui_init();
        return ESP_OK;

}



esp_err_t display_set_temperatura(float value){

    char new_val[TEMPERATURA_STRING_LEN]; 

    snprintf(new_val, sizeof(new_val), "%.1f", value);

    set_var_temperatura(new_val);
    return ESP_OK;
}

esp_err_t display_refresh(){
    ui_tick(); // Con esta funcion refresco pantalla
    return ESP_OK;
}

esp_err_t display_show_example(void){
        example_lvgl_demo_ui();
        return ESP_OK;
}
