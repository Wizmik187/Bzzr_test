/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/gpio.h"
#include "driver/ledc.h"

#include "esp_log.h"
#include "sdkconfig.h"

/* Use project configuration menu (idf.py menuconfig) to choose the GPIO to blink,
   or you can edit the following line and set a number here.
*/
#define BZR_EN1 14
#define BZR_EN2 13

#define LEDC_TIMER              LEDC_TIMER_0
#define LEDC_MODE               LEDC_LOW_SPEED_MODE
#define LEDC_OUTPUT_IO          (3) // Define the output GPIO
#define LEDC_CHANNEL            LEDC_CHANNEL_0
#define LEDC_DUTY_RES           LEDC_TIMER_13_BIT // Set duty resolution to 13 bits
#define LEDC_DUTY               (4095) // Set duty to 50%. ((2 ** 13) - 1) * 50% = 4095
#define LEDC_FREQUENCY          (5000) // Frequency in Hertz. Set frequency at 5 kHz


#define cL 131
#define dL 147
#define eL 165
#define fL 175
#define gL 196
#define aL 220
#define bL 247

#define c 262
#define d 294
#define e 330
#define f 349
#define g 392
#define a 440
#define b 494

#define cH 523
#define dH 587
#define eH 659
#define fH 698
#define gH 784
#define aH 880
#define bH 988
#define cHH 1046

static void configure_GPIO(void)
{

    gpio_reset_pin(BZR_EN1);
    gpio_reset_pin(BZR_EN2);

    /* Set the GPIO as a push/pull output */
    gpio_set_direction(BZR_EN1, GPIO_MODE_OUTPUT);
    gpio_set_direction(BZR_EN2, GPIO_MODE_OUTPUT);
}

void sound(uint32_t freq,uint32_t duration)
{

        // Prepare and then apply the LEDC PWM timer configuration
    ledc_timer_config_t ledc_timer = {
        .speed_mode       = LEDC_MODE,
        .timer_num        = LEDC_TIMER,
        .duty_resolution  = LEDC_DUTY_RES,
        .freq_hz          = freq,  // Set output frequency at 5 kHz
        .clk_cfg          = LEDC_AUTO_CLK
    };
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));

    // Prepare and then apply the LEDC PWM channel configuration
    ledc_channel_config_t ledc_channel = {
        .speed_mode     = LEDC_MODE,
        .channel        = LEDC_CHANNEL,
        .timer_sel      = LEDC_TIMER,
        .intr_type      = LEDC_INTR_DISABLE,
        .gpio_num       = LEDC_OUTPUT_IO,
        .duty           = 0, // Set duty to 0%
        .hpoint         = 0
    };
    ESP_ERROR_CHECK(ledc_channel_config(&ledc_channel));
    
    gpio_set_level(BZR_EN1, 1);
    gpio_set_level(BZR_EN2, 1);

    ESP_ERROR_CHECK(ledc_set_duty(LEDC_MODE, LEDC_CHANNEL, 4095)); // 4095
    // Update duty to apply the new value
    ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, LEDC_CHANNEL));

    vTaskDelay((duration/portTICK_PERIOD_MS) * 0.7);
    //gpio_set_level(BZR_EN1, 0);
    gpio_set_level(BZR_EN1, 0);
    vTaskDelay((duration/portTICK_PERIOD_MS) * 0.2);
    gpio_set_level(BZR_EN2, 0);
    vTaskDelay((duration/portTICK_PERIOD_MS) * 0.1);
    ESP_ERROR_CHECK(ledc_set_duty(LEDC_MODE, LEDC_CHANNEL, 0));
    // Update duty to apply the new value
    ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, LEDC_CHANNEL));

}

#define _FULL 2000
#define _2 (_FULL / 2)
#define _4 (_FULL / 4)
#define _8 (_FULL / 8)
#define _16 (_FULL / 16)


void app_main(void)
{
    /* Configure the peripheral according to the LED type */
    // 도 레 미 파 솔 라 시
    // c  d  e  f  g  a  b
    configure_GPIO();
    // 
    while (1) {
        vTaskDelay(_8 / portTICK_PERIOD_MS);
        sound(e,_4);
        sound(e,_8);
        sound(aL,_8);
        sound(aL,_8);
        sound(c,_8);
        sound(d,_8);
        vTaskDelay(_8 / portTICK_PERIOD_MS);
        sound(e,_8);
        sound(e,_8);
        sound(e,_8);
        sound(aL,_8);
        sound(aL,_8);
        sound(c,_8);
        sound(d,_8);
        vTaskDelay(_8 / portTICK_PERIOD_MS);
        sound(e,_8);
        sound(e,_8);
        sound(e,_8);
        sound(aL,_8);
        sound(aL,_8);
        sound(c,_8);
        sound(d,_8);
        vTaskDelay(_8 / portTICK_PERIOD_MS);
        sound(e,_8);
        sound(e,_8);
        sound(e,_8);
        sound(e,_8);
        sound(e,_8);
        sound(f,_8);
        sound(e,_8);
        sound(d,_4 + _8);
        sound(c,_4 + _8);
        sound(f,_8);
        sound(e,_8);
        sound(d,_4 + _8);
        sound(c,_4 + _8);
        sound(f,_8);
        sound(e,_8);
        sound(d, _4);
        sound(e, _8);
        sound(d, _8);
        sound(c, _4 + _8);
        sound(g, _8);
        sound(a, _4);
        sound(b, _4);
        sound(cH, _4);
        sound(a, _4);
        sound(eH, _2 + _4);
        vTaskDelay(_8 / portTICK_PERIOD_MS);
        sound(e, _8);
        sound(a, _4);
        sound(b, _4);
        sound(cH, _4);
        sound(g, _4);
        sound(eH, _2 + _4);
        vTaskDelay(_8 / portTICK_PERIOD_MS);
        sound(e, _8);
        sound(a, _4);
        sound(b, _4);
        sound(cH, _4);
        sound(cH, _8);
        sound(g, _8);
        
        sound(g, _8 + _16);
        sound(g, _8 + _16);
        sound(g, _8);
        sound(g, _8 + _16);
        sound(e, _8 + _16);
        sound(f, _8);
        sound(g, _8 + _16);
        sound(g, _4 + _16);
        sound(g, _8 + _16);
        sound(g, _8 + _16);
        sound(a, _8);
        sound(g, _4);
        sound(e, _2);
        vTaskDelay(_8 / portTICK_PERIOD_MS);
        sound(a, _8);
        sound(a, _4);
        sound(b, _4);
        sound(cH, _4);
        sound(a, _4);
        sound(eH, _2 + _4);
        vTaskDelay(_8 / portTICK_PERIOD_MS);
        sound(e, _8);
        sound(a, _4);
        sound(b, _4);
        sound(cH, _4);
        sound(eH, _8);
        sound(cH, _8);
        sound(dH, _4 + _8);
        sound(cH, _8);
        sound(b, _4);
        sound(g, _8);
        sound(g, _8+ _4);
        sound(e, _8);
        sound(e, _8+_4);
        sound(c, _4);

        sound(g, _8 + _16);
        sound(g, _8 + _16);
        sound(g, _8);
        sound(g, _8 + _16);
        sound(e, _8 + _16);
        sound(f, _8);
        sound(g, _8 + _16);
        sound(g, _4 + _16);
        sound(g, _8 + _16);
        sound(g, _8 + _16);
        sound(a, _8);
        sound(g, _4);
        sound(e, _2);
        vTaskDelay(_8 / portTICK_PERIOD_MS);
        sound(a, _8);
        sound(a, _4);
        sound(b, _4);
        sound(cH, _4);
        sound(eH, _4);

        sound(a, _8 + _16);
        sound(a, _8 + _16);
        sound(a, _8);
        sound(a, _16);
        sound(a, _8 +_16 +_4);

        sound(a, _8 + _16);
        sound(a, _8 + _16);
        sound(a, _8);
        sound(a, _16);
        sound(a, _8 +_16 +_4);

        sound(g, _8 + _16);
        sound(g, _8 + _16);
        sound(g, _8);
        sound(g, _16);
        sound(g, _8 +_16 +_4);

        sound(g, _8 + _16);
        sound(g, _8 + _16);
        sound(g, _8);
        sound(g, _8 + _16);
        sound(e, _8 +_16);
        sound(e, _8);

        sound(f, _8 + _16);
        sound(f, _8 + _16);
        sound(f, _8);
        sound(f, _16);
        sound(f, _8 +_16 +_4);

        sound(f, _8 + _16);
        sound(f, _8 + _16);
        sound(f, _8);
        sound(f, _8 + _16);
        sound(a, _8 +_16);
        sound(g, _8);

        sound(e, _8 + _16);
        sound(e, _8 + _16);
        sound(e, _8);
        sound(e, _16);
        sound(e, _8 +_16 +_4);

        sound(a, _4);

        sound(b, _4);
        sound(cH, _4);
        sound(eH, _4);

        sound(a, _8 + _16);
        sound(a, _8 + _16);
        sound(a, _8);
        sound(a, _16);
        sound(a, _8 +_16 +_4);

        sound(a, _8 + _16);
        sound(a, _8 + _16);
        sound(a, _8);
        sound(a, _8+_16);
        sound(cH, _16 +_8);
        sound(b, _8);

        sound(g, _8 + _16);
        sound(g, _8 + _16);
        sound(g, _8);
        sound(g, _16);
        sound(g, _8 +_16 +_4);

        sound(g, _8 + _16);
        sound(g, _8 + _16);
        sound(g, _8);
        sound(g, _8+_16);
        sound(e, _8 +_16);
        sound(e, _8);

        sound(f, _8 + _16);
        sound(f, _8 + _16);
        sound(f, _8);
        sound(f, _16);
        sound(f, _8 +_16 +_4);

        sound(f, _8 + _16);
        sound(f, _8 + _16);
        sound(f, _8);
        sound(f, _8+_16);
        sound(a, _8 +_16);
        sound(g, _8);

        sound(e, _8+_16);
        sound(e, _8+_16);
        sound(e, _8);
        sound(d, _16);
        sound(e, _8+_16);
        sound(c, _8);
        sound(aL, _8 + _FULL);

    }
}
