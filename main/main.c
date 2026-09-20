#include <stdio.h>


#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "display.h"



float temp = 23.0;
void app_main(void)
{
    display_init();
    display_ui_start();
    display_set_temperatura(temp);

    while(1){
        temp +=0.41;
        display_set_temperatura(temp);
        display_refresh();
        vTaskDelay(2000 / portTICK_PERIOD_MS);

    }
}
