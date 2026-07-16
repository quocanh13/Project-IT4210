
#ifndef __GAME_H__
#define __GAME_H__

#include <stdint.h>

unsigned int get_score();       // Hàm lấy điểm số hiện tại
void reset_state();             // Hàm reset trạng thái điểm và led
void press_button(uint8_t button);      // Hàm xử lý sự kiện nhấn button

extern volatile uint8_t score_updated;  // Cờ báo cần cập nhật LCD

#endif