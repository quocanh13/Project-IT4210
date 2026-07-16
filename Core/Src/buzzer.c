#include "buzzer.h"

void buzzer_init(void) {
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
    buzzer_stop();
}

void buzzer_stop(void) {
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 0);
}

// TIM3 chạy ở APB1 clock (16MHz theo cấu hình hiện tại của bạn)
static void set_frequency(uint16_t freq_hz) {
    if (freq_hz == 0) {
        buzzer_stop();
        return;
    }
    uint32_t timer_clk = 16000000; // đổi lại nếu bạn tăng SYSCLK sau này
    uint32_t psc = 15;             // chia clock xuống 1MHz cho dễ tính
    uint32_t tick_clk = timer_clk / (psc + 1);
    uint32_t arr = (tick_clk / freq_hz) - 1;

    __HAL_TIM_SET_PRESCALER(&htim3, psc);
    __HAL_TIM_SET_AUTORELOAD(&htim3, arr);
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, arr / 2); // duty 50%
}

void buzzer_play_tone(uint16_t freq_hz, uint16_t duration_ms) {
    set_frequency(freq_hz);
    HAL_Delay(duration_ms);
    buzzer_stop();
}

void buzzer_play_melody(const Note *melody, uint16_t len) {
    for (uint16_t i = 0; i < len; i++) {
        set_frequency(melody[i].freq_hz);
        HAL_Delay(melody[i].duration_ms);
        buzzer_stop();
        HAL_Delay(10); // khoảng nghỉ nhỏ giữa các nốt cho rõ tiếng
    }
}

/* ---- Tần số các nốt nhạc (Hz) ---- */
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_E5 659
#define NOTE_G5 784
#define REST    0

void sound_game_start(void) {
    static const Note m[] = {
        {NOTE_C4, 120}, {NOTE_E4, 120}, {NOTE_G4, 120}, {NOTE_C5, 250}
    };
    buzzer_play_melody(m, 4);
}

void sound_game_end(void) {
    static const Note m[] = {
        {NOTE_G4, 150}, {NOTE_E4, 150}, {NOTE_C4, 150}, {REST, 50}, {NOTE_C4, 300}
    };
    buzzer_play_melody(m, 5);
}

void sound_hit(void) {
    buzzer_play_tone(NOTE_C5, 100);
}

void sound_miss(void) {
    // Rớt từ 262Hz (C4) xuống 196Hz (G3)
    static const Note m[] = {
        {NOTE_C4, 150}, {NOTE_G3, 300}
    };
    buzzer_play_melody(m, 2);
}


void sound_level_up(void) {
    // E4 -> G4 -> C5 -> E5 -> G5
    static const Note m[] = {
        {NOTE_E4, 100}, {NOTE_G4, 100}, {NOTE_C5, 100}, {NOTE_E5, 150}, {NOTE_G5, 200}
    };
    buzzer_play_melody(m, 5);
}

void sound_level_down(void) {
    // E5 -> C5 -> G4 -> E4
    static const Note m[] = {
        {NOTE_E5, 100}, {NOTE_C5, 100}, {NOTE_G4, 100}, {NOTE_E4, 250}
    };
    buzzer_play_melody(m, 4);
}

void sound_countdown(void) {
    // C5 (ngắn) x3 lần, kết thúc bằng G5 (dài)
    static const Note m[] = {
        {NOTE_C5, 150}, {REST, 350},
        {NOTE_C5, 150}, {REST, 350},
        {NOTE_C5, 150}, {REST, 350},
        {NOTE_G5, 400}
    };
    buzzer_play_melody(m, 7);
}