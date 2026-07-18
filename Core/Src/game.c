#include <stdio.h>
#include "led.h"
#include "lcd.h"
#include "buzzer.h"
#include "led.h"

unsigned int score = 0;
volatile uint8_t pending_sound = 0;
uint8_t level = 0;

void reset_state(){
    score = 0;
    turn_off_all_leds();
    sound_game_start();
}

unsigned int get_score(){
    return score;
}

void press_button(uint8_t button){
    if(!is_start)
        return;
    uint8_t led_state = get_led(button);
    if(led_state){
        set_led(button, 0);
        score++;
        pending_sound = 1;
    } else {
        if(score > 0) 
            score--;
        pending_sound = 2;
    }
    char s[20];

    lcd_print_game(level, score);
}

void press_level_up_button(){
    level += 1;
    score = 0;
    stop_random_led();
    lcd_print_game(level, score);
    pending_sound = 4;
}

void press_level_down_button(){
    if(level > 0)
        level--;
    score = 0;
    stop_random_led();
    lcd_print_game(level, score);
    pending_sound = 5;
}

void press_start_button(){
    score = 0;
    lcd_print_game(level, score);
    start_random_led();
    pending_sound = 6;
}