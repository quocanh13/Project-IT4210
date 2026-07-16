
#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <stdint.h>

void random_seed(void);
uint8_t random_get(uint8_t max);
uint8_t random_position(void);
void rand_led(unsigned int level);

#endif
