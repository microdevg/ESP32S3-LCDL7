#include <stdio.h>
#include "display.h"
#include "waveshare_rgb_lcd_port.h"
#include "ui/ui.h"


#include <string.h>
#include "ui/vars.h"

#include "ui/actions.h"
#include "ui/screens.h"

void action_change_window(lv_event_t * e) {
    // Agrega aquí tu lógica de LVGL, por ejemplo:
    if(e->user_data == 0){
        loadScreen(SCREEN_ID_MAIN); 

    }  
    else{
        loadScreen(SCREEN_ID_OPTIONS);
    }
}

extern void action_update_config(lv_event_t * e) {
    lv_obj_t * slider = lv_event_get_target(e);
    
    // 2. Leer su valor actual
    int32_t valor = lv_slider_get_value(slider);
    
    // 3. Convertir el entero a string y pasarlo a set_var_config
    char valor_str[16];
    snprintf(valor_str, sizeof(valor_str), "%d", (int)valor);
    set_var_config(valor_str);
   ui_tick(); // Con esta funcion refresco pantalla

    ESP_LOGI("UI", "Nuevo valor del slider: %s", valor_str);
}


char config[100] = { "--"};
char temp[100] = {""};

 const char *get_var_temp() {
    return temp;
}

void set_var_temp( const char *value) {
    strncpy(temp, value, sizeof(temp) / sizeof(char));
    temp[sizeof(temp) / sizeof(char) - 1] = 0;
}

 const char *get_var_config() {
    return config;
}

void set_var_config( const char *value) {
    strncpy(config, value, sizeof(config) / sizeof(char));
    config[sizeof(config) / sizeof(char) - 1] = 0;
    printf("update config");
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


esp_err_t display_refresh(){
    ui_tick(); // Con esta funcion refresco pantalla
    return ESP_OK;
}

esp_err_t display_show_example(void){
        example_lvgl_demo_ui();
        return ESP_OK;
}


esp_err_t display_set_temperature(float temp){
        char temperatura_value[100]={0};
        sprintf(temperatura_value,"%.2f\n",temp);
        printf("[Test]%s\n",temperatura_value);
        set_var_temp(temperatura_value);
        return ESP_OK;
}
