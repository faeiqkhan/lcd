#include "FreeRTOS.h"
#include "task.h"
#include "LiquidCrystal_I2C.h"

#define LCD_I2C_ADDRESS 0x27
#define LCD_NUM_ROWS 2
#define LCD_NUM_COLUMNS 16

LiquidCrystal_I2C lcd(LCD_I2C_ADDRESS, LCD_NUM_COLUMNS, LCD_NUM_ROWS);

void LCD_Init()
{
  lcd.begin(LCD_NUM_COLUMNS, LCD_NUM_ROWS);
  lcd.clear();
}

void LCD_Clear()
{
  lcd.clear();
}

void LCD_SetCursor(uint8_t row, uint8_t col)
{
  lcd.setCursor(col, row);
}

void LCD_WriteString(const char* string)
{
  lcd.print(string);
}

void Task_LCD(void* pvParameters)
{
  LCD_Init();
  LCD_Clear();
  LCD_SetCursor(0, 0);
  LCD_WriteString("Hello, World!");

  while (1)
  {
    // Task code
    // ...
  }
}
