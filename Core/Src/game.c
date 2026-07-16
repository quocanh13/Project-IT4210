#include <stdio.h>
#include "led.h"
#include "lcd.h"
#include "random.h"

unsigned int score = 0;
uint32_t last_round_time = 0;

void reset_state(){
    score = 0;
    turn_off_all_leds();
}

unsigned int get_score(){
    return score;
}

void press_button(uint8_t button){
    uint8_t led_state = get_led(button);
    if(led_state){
        set_led(button, 0);
        score++;
    } else {
        if(score > 0) 
            score--;
    }
    char s[20];

    lcd_set_cursor(0, 0);
    lcd_print("                         ");
    
    lcd_set_cursor(0, 0);
    sprintf(s, "%i %i %i            ", button, led_state, score);
    lcd_print(s);
}

uint8_t is_game_running = 1;

void pause_game(void) {
    is_game_running = 0;
    turn_off_all_leds();
}

void resume_game(void) {
    is_game_running = 1;
    last_round_time = HAL_GetTick(); 
    rand_led(1);                  
}

void game_loop(uint32_t round_timeout) {
    if (!is_game_running) {
        return;
    }

    if (last_round_time == 0) {
        last_round_time = HAL_GetTick();
    }

    if (HAL_GetTick() - last_round_time >= round_timeout) {
        next_round();
        last_round_time = HAL_GetTick();
    }
}