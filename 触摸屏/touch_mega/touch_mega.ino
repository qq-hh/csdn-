#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_SPI.h> //Hardware-specific library
#include "chiese.h"
#define MODEL ST7796S
#define CS   A5
#define CD   A3
#define RST  A4
#define LED  A0
LCDWIKI_SPI my_lcd(MODEL, CS, CD, RST, LED);
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

char *aspect_name[] = {"PORTRAIT", "LANDSCAPE", "PORTRAIT_REV", "LANDSCAPE_REV"};
char *color_name[] = { "BLUE", "GREEN", "RED", "WHITE" , "CYAN", "MAGENTA", "YELLOW"};
uint16_t color_mask[] = { 0x001F, 0x07E0, 0xF800, 0xFFFF, 0x07FF, 0xF81F, 0xFFE0 };

void show_32font(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *str, uint8_t mode)
{
  uint16_t i, j, k, c_num, color;
  boolean first = true;
  c_num = sizeof(tfont32) / sizeof(typFNT_GB32);
  for (k = 0; k < c_num; k++)
  {
    if ((pgm_read_byte(&tfont32[k].Index[0]) == *str) && (pgm_read_byte(&tfont32[k].Index[1]) == *(str + 1)))
    {
      my_lcd.Set_Addr_Window(x, y, x + 32 - 1, y + 32 - 1);
      for (j = 0; j < 128; j++)
      {
        for (i = 0; i < 8; i++)
        {
          if (mode) //叠加模式
          {
            if (pgm_read_byte(&tfont32[k].Msk[j]) & (0x80 >> i))
            {
              my_lcd.Set_Draw_color(fc);
              my_lcd.Draw_Pixel(x + ((j * 8 + i) % 32), y + ((j * 8 + i) / 32));
            }
          }
          else   //非叠加模式
          {
            if (pgm_read_byte(&tfont32[k].Msk[j]) & (0x80 >> i))
            {
              color = fc;
            }
            else
            {
              color = bc;
            }
            my_lcd.Push_Any_Color(&color, 1, first, 0);
            first = false;
          }
        }
      }
    }
  }
}

void show_chinese(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *str, uint16_t csize, uint8_t mode)
{
  int i = 0;
  if (x > (my_lcd.Get_Display_Width() - csize) || y > (my_lcd.Get_Display_Height() - csize))
  {
    return;
  }
  while (*str != '\0')
  {
    if (csize == 32)
    {
      show_32font(x, y, fc, bc, str, mode);
    }
    str += 3;
    x += csize;
  }
} 

void setup()
{
  my_lcd.Init_LCD();
  my_lcd.Fill_Screen(BLACK);
  show_chinese(0 , 100, BLUE, WHITE, "北京瓜豆科技有限公司", 32, 1);

}

void loop()
{

}
