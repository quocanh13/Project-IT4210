
#ifndef __LED_H__
#define __LED_H__

#include "main.h"
#include "stdint.h"

#define LED_PORT GPIOA
#define LED_1 GPIO_PIN_6
#define LED_2 GPIO_PIN_7
#define LED_3 GPIO_PIN_9
#define LED_4 GPIO_PIN_10
#define LED_5 GPIO_PIN_11
#define LED_6 GPIO_PIN_12

void set_led(uint16_t led, uint8_t state);      // Thiết lập trạng thái bật tắt cho đèn LED (0 - 1)
uint8_t get_led(uint16_t led);                  // Lấy trạng thái hiện tại của đèn LED (0 - 1)
void rand_led(unsigned int level);              // Làm đèn LED nhảy ngẫu nhiên

#endif