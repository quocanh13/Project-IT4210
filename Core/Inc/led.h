
#ifndef __LED_H__
#define __LED_H__

#include "main.h"
#include "stdint.h"

/* LED defines */
#define LED_PORT GPIOA
#define LED_1 GPIO_PIN_6
#define LED_2 GPIO_PIN_7
#define LED_3 GPIO_PIN_9
#define LED_4 GPIO_PIN_10
#define LED_5 GPIO_PIN_11
#define LED_6 GPIO_PIN_12

void set_led(uint16_t led, uint8_t state);      // Thiết lập trạng thái bật tắt cho đèn LED (0 - 1)
uint8_t get_led(uint8_t led_index);                  // Lấy trạng thái hiện tại của đèn LED (0 - 1)
void rand_led(unsigned int level);              // Làm đèn LED nhảy ngẫu nhiên

#define LCG_A  1664525U
#define LCG_C  1013904223U

extern uint32_t seed;

/* LED functions */
void set_led(uint16_t led, uint8_t state);
void rand_led(unsigned int level);
void turn_off_all_leds(void);
void turn_on_led(uint8_t pos);

/* Random functions (merged from game_random) */
void random_seed(void);
uint8_t random_get(uint8_t max);
uint8_t random_position(void);

#endif