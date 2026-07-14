#ifndef lcd
#define lcd

#include "main.h"

extern I2C_HandleTypeDef hi2c1;


// Địa chỉ của LCD
#define LCD_ADDR (0x27 << 1) 

// I2C dùng cho LCD
#define LCD_I2C hi2c1

// Mã lệnh
// --- Các lệnh cơ bản ---
#define LCD_CLEAR_SCREEN            0x01  // Xóa toàn bộ màn hình
#define LCD_RETURN_HOME             0x02  // Đưa con trỏ về đầu dòng 1

// --- Cài đặt hướng con trỏ (Entry Mode Set) ---
#define LCD_ENTRY_MODE              0x06  // Tự dịch trỏ sang phải sau mỗi chữ, không dịch màn hình

// --- Điều khiển Bật/Tắt (Display Control) ---
#define LCD_DISPLAY_OFF             0x08  // Tắt màn hình, tắt con trỏ
#define LCD_DISPLAY_ON              0x0C  // Bật màn hình, tắt con trỏ
#define LCD_DISPLAY_ON_CURSOR       0x0E  // Bật màn hình, bật con trỏ gạch dưới
#define LCD_DISPLAY_ON_CURSOR_BLINK 0x0F  // Bật màn hình, bật con trỏ nhấp nháy

// --- Cài đặt giao tiếp (Function Set) ---
#define LCD_WAKEUP_8BIT             0x30  // Đánh thức / Reset / Giao tiếp 8-bit
#define LCD_SET_4BIT_MODE           0x20  // Cài đặt chuyển sang giao tiếp 4-bit
#define LCD_FUNCTION_SET_4BIT       0x28  // Giao tiếp 4-bit, 2 dòng, font 5x8 pixel

// --- Chuyển dòng (Set DDRAM Address) ---
#define LCD_SET_ROW_1               0x80  // Ép con trỏ về vị trí đầu dòng 1
#define LCD_SET_ROW_2               0xC0  // Ép con trỏ về vị trí đầu dòng 2
// Mã lệnh

void lcd_send_data(char data);              // Hàm gửi dữ liệu xuống LCD
void lcd_send_cmd(char cmd);                // Hàm gửi lệnh xuống LCD
void lcd_init(void);                        // Hàm khởi tạo LCD ở chế độ 4 bit
void lcd_set_cursor(int row, int col);      // Hàm thiết lập vị trí con trỏ
void lcd_print(char *str);                  // Hàm in xâu ra màn hình tính từ vị trí con trỏ hiện tại

#endif