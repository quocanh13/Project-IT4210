#include "button.h"
#include "game.h"

const uint16_t BUTTON[] = {BUTTON_1, BUTTON_2, BUTTON_3, BUTTON_4, BUTTON_5, BUTTON_6};

void handle_press_button(uint16_t pin){
    for(int i = 0; i < 6; i++){
        if(!BUTTON[i] == pin) continue;
        press_button(i);
    }
}

