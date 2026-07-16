#include "main.h"
#include "lcd.h"

void lcd_send_cmd(char cmd) {
    char data_u, data_l;
    uint8_t data_t[4];
    data_u = (cmd & 0xf0);
    data_l = ((cmd << 4) & 0xf0);

    data_t[0] = data_u | 0x0C;  
    data_t[1] = data_u | 0x08;  
    data_t[2] = data_l | 0x0C;  
    data_t[3] = data_l | 0x08;  
    HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDR, (uint8_t *)data_t, 4, 100);
}

void lcd_send_data(char data) {
    char data_u, data_l;
    uint8_t data_t[4];
    data_u = (data & 0xf0);
    data_l = ((data << 4) & 0xf0);

    data_t[0] = data_u | 0x0D;  
    data_t[1] = data_u | 0x09;  
    data_t[2] = data_l | 0x0D;  
    data_t[3] = data_l | 0x09;  
    HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDR, (uint8_t *)data_t, 4, 100);
}

void lcd_init(void) {
    HAL_Delay(50);
    
    lcd_send_cmd(LCD_WAKEUP_8BIT);          HAL_Delay(5);
    lcd_send_cmd(LCD_WAKEUP_8BIT);          HAL_Delay(1);
    lcd_send_cmd(LCD_WAKEUP_8BIT);          HAL_Delay(10);
    
    lcd_send_cmd(LCD_SET_4BIT_MODE);        HAL_Delay(10);  
    
    lcd_send_cmd(LCD_FUNCTION_SET_4BIT);    HAL_Delay(1);   
    lcd_send_cmd(LCD_DISPLAY_OFF);          HAL_Delay(1);   
    lcd_send_cmd(LCD_CLEAR_SCREEN);         HAL_Delay(2);   
    lcd_send_cmd(LCD_ENTRY_MODE);           HAL_Delay(1);  
    lcd_send_cmd(LCD_DISPLAY_ON);                
}

void lcd_clear(void) {
    lcd_send_cmd(LCD_CLEAR_SCREEN); 
    HAL_Delay(5);       
}


void lcd_set_cursor(int row, int col) {
    uint8_t address;
    switch (row) {
        case 0: 
            address = 0x00; 
            break;
        case 1: 
            address = 0x40;
            break;
        default: 
            address = 0x00;
    }
    
    address += col;
    lcd_send_cmd(0x80 | address);
}

void lcd_print(char *str) {
    while (*str) lcd_send_data(*str++);
}