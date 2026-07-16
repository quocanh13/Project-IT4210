#ifndef __GAME_RANDOM_H__
#define __GAME_RANDOM_H__

#include "main.h"
#include "stdint.h"

#define LCG_A  1664525U
#define LCG_C  1013904223U

extern uint32_t seed;

void random_seed(void);
uint8_t random_get(uint8_t max);
uint8_t random_position(void);

#endif
