#include "led.h"

unsigned int score = 0;

void reset_state(){
    score = 0;
    for(int i = 0; i < 6; i++){
        set_led(LED[i], 0);
    }
}

void get_score(){
    return score;
}

void press_button(uint8_t button){
    uint8_t led_state = get_led(LED[button]);
    if(led_state){
        set_led(LED[button], 0);
        score++;
    } else {
        score--;
    }
}