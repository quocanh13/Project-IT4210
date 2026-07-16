
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

void set_led(uint8_t led_index, uint8_t state);      // Thiết lập trạng thái bật tắt cho đèn LED (0 - 1)
uint8_t get_led(uint8_t led_index);                  // Lấy trạng thái hiện tại của đèn LED (0 - 1)
void turn_off_all_leds(void);
void turn_on_led(uint8_t pos);

#endif