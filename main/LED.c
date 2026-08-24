#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"


#define LED_COUNT 10

static const gpio_num_t led_pins[LED_COUNT] =
{
    GPIO_NUM_15,
    GPIO_NUM_2,
    GPIO_NUM_0,
    GPIO_NUM_4,
    GPIO_NUM_5,
    GPIO_NUM_18,
    GPIO_NUM_19,
    GPIO_NUM_21,
    GPIO_NUM_22,
    GPIO_NUM_23
 
};

static const char *TAG = "LED_BAR";


void app_main(void)
{
    //postavljanje svih 10 pinova kao output
    for(int i = 0; i< LED_COUNT; i++)
    {
        gpio_reset_pin(led_pins[i]);
        gpio_set_direction(led_pins[i], GPIO_MODE_OUTPUT);
        gpio_set_level(led_pins[i], 0);
    }

    ESP_LOGI(TAG, "LED bar initialized");

    while (1)
    {
        for (int count = 1; count <= LED_COUNT; count++)
        {
            for (int i = 0; i < LED_COUNT; i++)
            {
                if (i < count)
                {
                    gpio_set_level(led_pins[i], 1);
                }
                else
                {
                    gpio_set_level(led_pins[i], 0);
                }
            }

            ESP_LOGI(TAG, "LED BAR LEVEL = %d/%d", count, LED_COUNT);

            vTaskDelay(pdMS_TO_TICKS(500));
        }

        for (int i = 0; i < LED_COUNT; i++)
        {
            gpio_set_level(led_pins[i], 0);
        }

        vTaskDelay(pdMS_TO_TICKS(1000));
    }

}

/*OVO ISPOD POSTAVLJA LED-ice DA IZGLEDAJU KAO DA SE PUNI BATERIJA*/

/*
    while (1)
{
    for (int count = 1; count <= LED_COUNT; count++)
    {
        for (int i = 0; i < LED_COUNT; i++)
        {
            if (i < count)
            {
                gpio_set_level(led_pins[i], 1);
            }
            else
            {
                gpio_set_level(led_pins[i], 0);
            }
        }

        ESP_LOGI(TAG, "LED BAR LEVEL = %d/%d", count, LED_COUNT);

        vTaskDelay(pdMS_TO_TICKS(500));
    }

    for (int i = 0; i < LED_COUNT; i++)
    {
        gpio_set_level(led_pins[i], 0);
    }

    vTaskDelay(pdMS_TO_TICKS(1000));
}
*/

    
//bruh, meni je onaj stari projekt s blinkanjem LED-ice ubacio u repo gdje treba ic projekt s ovim LED zaslonom od 10 ledica...