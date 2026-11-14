#include <stdio.h>


#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "display.h"


float temperature = 10;

void app_main(void)
{
    display_init();
    display_ui_start();

    while(1){
        display_refresh();
        temperature = temperature + 1.1;
        display_set_temperature(temperature);
        vTaskDelay(500 / portTICK_PERIOD_MS);

    }
}
