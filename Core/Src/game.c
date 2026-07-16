#include <stdio.h>
#include "led.h"
#include "lcd.h"

unsigned int score = 0;

void reset_state(){
    score = 0;
    for(int i = 0; i < 6; i++){
        turn_off_all_leds();
    }
}

void get_score(){
    return score;
}

void press_button(uint8_t button){
    uint8_t led_state = get_led(button);
    if(led_state){
        set_led(button, 0);
        score++;
    } else {
        score--;
    }
    char s[20];
    sprintf(s, "%i", score);
    lcd_print(s);
}