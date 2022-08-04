#include "LCDWIKI_GUI.h"//Core graphics library
#include "LCDWIKI_SPI.h"//Hardware-specific library
#include "LCDWIKI_TOUCH.h" //touch screen library

#define MODEL ST7796S
#define CS   A5
#define CD   A3
#define RST  A4
#define LED  A0
#define TCS   45
#define TCLK  46
#define TDOUT 47
#define TDIN  48
#define TIRQ  49
LCDWIKI_SPI my_lcd(MODEL, CS, CD, RST, LED);
LCDWIKI_TOUCH my_touch(TCS, TCLK, TDOUT, TDIN, TIRQ);
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
uint16_t color_mask[] = {0xF800, 0xFFE0, 0x07E0, 0x07FF, 0x001F, 0xF81F}; //color select
#define COLORBOXSIZE my_lcd.Get_Display_Width()/6
#define PENBOXSIZE my_lcd.Get_Display_Width()/4

int16_t old_color, current_color, flag_colour;
int16_t old_pen, current_pen, flag_pen;
boolean show_flag = true;

void show_string(uint8_t *str, int16_t x, int16_t y, uint8_t csize, uint16_t fc, uint16_t bc, boolean mode)
{

  my_lcd.Set_Text_Mode(mode);
  my_lcd.Set_Text_Size(csize);
  my_lcd.Set_Text_colour(fc);
  my_lcd.Set_Text_Back_colour(bc);
  my_lcd.Print_String(str, x, y);
}
int x=100;
void button1(void)//对button两个按钮定义，同一横排y轴相同，x不同
{
  my_lcd.Set_Draw_color(GREEN);//底色
  my_lcd.Fill_Round_Rectangle(100, 150, 150, 200, 20); //距左  上   横向   纵向  四周边角设计
  my_lcd.Fill_Round_Rectangle(200, 150, 250 , 200, 20); //距左  上   横向   纵向  四周边角设计
  show_string("LED1", 100, x, 2, BLUE, BLACK, 1); //文字
  show_string("LED2", 200, 165, 2, RED, BLACK, 1);
}

void button2(void)
{
  my_lcd.Set_Draw_color(RED);
  my_lcd.Fill_Round_Rectangle(100, 80, 150, 130, 20);
  my_lcd.Fill_Round_Rectangle(200, 80, 250 , 130, 20);
  show_string("LED1", 100, 100, 2, BLUE, BLACK, 1);
  show_string("LED2", 200, 100, 2, YELLOW, BLACK, 1);

}
void button3(void)
{
  my_lcd.Set_Draw_color(BLUE);
  my_lcd.Fill_Round_Rectangle(100, 220, 150, 270, 20);
  my_lcd.Fill_Round_Rectangle(200, 220, 250 , 270, 20);
  show_string("LED1", 100, 240, 2, RED, BLACK, 1);
  show_string("LED2", 200, 240, 2, YELLOW, BLACK, 1);

}
void button4(void)
{
  my_lcd.Set_Draw_color(YELLOW);
  my_lcd.Fill_Round_Rectangle(100, 290, 150, 340, 20);
  my_lcd.Fill_Round_Rectangle(200, 290, 250 , 340, 20);
  show_string("LED1", 100, 305, 2, BLUE, WHITE, 1);
  show_string("LED2", 200, 305, 2, BLUE, WHITE, 1);
  show_string("CLOSE", 100, 345, 2, RED, WHITE, 1);
  show_string("CLOSE", 200, 345, 2, RED, WHITE, 1);
  show_string("Please control the light switch", 20, 400, 2, WHITE, WHITE, 1);
}

void setup(void)
{

  my_lcd.Init_LCD();
  my_lcd.Set_Rotation(0);
  my_touch.TP_Set_Rotation(3);
  my_touch.TP_Init(my_lcd.Get_Rotation(), my_lcd.Get_Display_Width(), my_lcd.Get_Display_Height());
  my_lcd.Fill_Screen(BLACK);
  button1();
  button2();
  button3();
  button4();
  current_color = RED;
  current_pen = 0;
  Serial.begin(38400);
}

void loop()
{
comme:
  my_touch.TP_Scan(0);
  if (my_touch.TP_Get_State()&TP_PRES_DOWN)//如果有触摸
  {
    Serial.println(my_touch.y);//打印坐标
    Serial.println(my_touch.x);
    //对button1区域两个按钮触发点击范围判断
    if ((my_touch.y > 150) && (my_touch.y < 200))
    {
      if (((my_touch.x > 100) && (my_touch.x < 150)) && !flag_pen)
      {
        Serial.println("1");//传给zigbee，串口透传，zigbee终端收到消息发给uno，uno控制灯
        delay(300);
      }
      if (((my_touch.x > 200) && (my_touch.x < 250)) && !flag_pen)
      {

        Serial.println("2");
        delay(300);

      }
    }

    //对button2区域两个按钮触发点击范围判断
    if ((my_touch.y > 80) && (my_touch.y < 110))
    {
      if (((my_touch.x > 100) && (my_touch.x < 130)) && !flag_pen)
      {

        Serial.println("3");
        delay(300);

      }
      if (((my_touch.x > 200) && (my_touch.x < 250)) && !flag_pen)
      {

        Serial.println("4");
        delay(300);
      }
    }
    //对button3区域两个按钮触发点击范围判断
    if ((my_touch.y > 220) && (my_touch.y < 260))
    {
      if (((my_touch.x > 80) && (my_touch.x < 130)) && !flag_pen)
      {

        Serial.println("5");
        delay(300);

      }
      if (((my_touch.x > 200) && (my_touch.x < 250)) && !flag_pen)
      {

        Serial.println("6");
        delay(300);
      }
    }
    //对button4区域两个按钮触发点击范围判断
    if ((my_touch.y > 300) && (my_touch.y < 340))
    {
      if (((my_touch.x > 80) && (my_touch.x < 130)) && !flag_pen)
      {

        Serial.println("7");
        delay(300);

      }
      if (((my_touch.x > 200) && (my_touch.x < 250)) && !flag_pen)
      {
 
        Serial.println("8");
        delay(300);
      }
    }
  }
}
