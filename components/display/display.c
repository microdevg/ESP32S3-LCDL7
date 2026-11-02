#include <stdio.h>
#include "display.h"
#include "waveshare_rgb_lcd_port.h"
#include "ui/ui.h"



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
 //   ui_tick(); // Con esta funcion refresco pantalla
    return ESP_OK;
}

esp_err_t display_show_example(void){
        example_lvgl_demo_ui();
        return ESP_OK;
}
