#include <stdio.h>
#include "display.h"
#include "waveshare_rgb_lcd_port.h"
#include "ui/ui.h"


#include <string.h>
#include "ui/vars.h"

char temp[100] = {""};

const char *get_var_temp() {
    return temp;
}

void set_var_temp(const char *value) {
    strncpy(temp, value, sizeof(temp) / sizeof(char));
    temp[sizeof(temp) / sizeof(char) - 1] = 0;
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
