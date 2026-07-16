#include "game_random.h"

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
