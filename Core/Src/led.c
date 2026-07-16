#include "led.h"

/* LED pin array */
const uint16_t LED[] = {LED_1, LED_2, LED_3, LED_4, LED_5, LED_6};

/* ---- LED functions ---- */

void set_led(uint8_t led_index, uint8_t state){
    if (state)
        HAL_GPIO_WritePin(LED_PORT, LED[led_index], GPIO_PIN_SET);
    else
        HAL_GPIO_WritePin(LED_PORT, LED[led_index], GPIO_PIN_RESET);
}

void turn_off_all_leds(void)
{
    for (int i = 0; i < 6; i++)
    {
        HAL_GPIO_WritePin(LED_PORT, LED[i], GPIO_PIN_RESET);
    }
}

void turn_on_led(uint8_t pos)
{
    turn_off_all_leds();
    if (pos < 6)
    {
        HAL_GPIO_WritePin(LED_PORT, LED[pos], GPIO_PIN_SET);
    }
}

uint8_t get_led(uint8_t led_index){
    return HAL_GPIO_ReadPin(LED_PORT, LED[led_index]);
}
