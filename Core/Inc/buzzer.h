#ifndef __BUZZER_H__
#define __BUZZER_H__

#include "main.h"

extern TIM_HandleTypeDef htim3;

typedef struct {
    uint16_t freq_hz;   // 0 = nghỉ (lặng)
    uint16_t duration_ms;
} Note;

void buzzer_init(void);
void buzzer_play_tone(uint16_t freq_hz, uint16_t duration_ms);
void buzzer_play_melody(const Note *melody, uint16_t len);
void buzzer_stop(void);

// Các hiệu ứng âm thanh của game
void sound_game_start(void);
void sound_game_end(void);
void sound_hit(void);
void sound_miss(void);
void sound_level_up(void);
void sound_level_down(void);
void sound_countdown(void);

#endif