#include <stdio.h>


#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "display.h"


void app_main(void)
{
    display_init();
    display_ui_start();

    while(1){
        display_refresh();
        vTaskDelay(500 / portTICK_PERIOD_MS);

    }
}
