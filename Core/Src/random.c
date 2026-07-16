#include "random.h"
#include "led.h"
#include "main.h"

#define LCG_A  1664525U
#define LCG_C  1013904223U

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

void rand_led(unsigned int level){
    uint8_t pos = random_position();
    turn_on_led(pos);
}
