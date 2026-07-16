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

void rand_led(unsigned int level){
    uint8_t pos = random_position();
    turn_on_led(pos);
}

/* ---- Random functions (merged from game_random.c) ---- */

uint32_t seed = 0;

void random_seed(void){
    seed = HAL_GetTick();
}

uint8_t random_get(uint8_t max){
    if (max == 0) return 0;
    seed ^= HAL_GetTick();
    seed = LCG_A * seed + LCG_C;
    return (uint8_t)((seed >> 16) % max);
}

uint8_t random_position(void){
    return random_get(6);
}