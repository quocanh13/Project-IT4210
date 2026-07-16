#include "led.h"
#include "lcd.h"
#include <math.h>

const uint16_t LED[] = {LED_1, LED_2, LED_3, LED_4, LED_5, LED_6};
const int MAX_RANDOM_COUNT = 20;
uint32_t prev_time = 0;
uint8_t is_start = 0;
uint8_t random_count = 0;

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

uint8_t get_led(uint8_t led_index){
    return HAL_GPIO_ReadPin(LED_PORT, LED[led_index]);
}

uint8_t random_position(void)
{
    uint32_t seed;
    seed += HAL_GetTick();

    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;

    return seed % 6;
}

void random_led(){
    uint8_t index = random_position();
    set_led(index, 1);
}

void start_random_led(){
    random_count = 0;
    is_start = 1;
}

void stop_random_led(){
    is_start = 0;
}

void next_random_led(unsigned int level){
    if(!is_start) 
        return;

    uint32_t cur_time = HAL_GetTick();
    float interval = 5000.0 / pow(1.1, level);
    if(cur_time - prev_time > interval){
        turn_off_all_leds();
        for(int i = 0; i < 3; i++)
            random_led();
        prev_time = cur_time;
        random_count++;
        if(random_count >= MAX_RANDOM_COUNT)
            is_start = 0;
    }
}