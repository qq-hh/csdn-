#include <Adafruit_NeoPixel.h>
#define PIN        0  //信号输出引脚GPIO0
#define NUMPIXELS  12  //灯个数

Adafruit_NeoPixel led(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {

  led.begin();
  led.setBrightness(255); //设置亮度 (0~255)
}

void loop() {
  for (int j = 0; j < 13; j++) {
   led.setPixelColor(j, led.Color(100, 90, 255));
  led.show();
    delay(50);
  }
delay(3000);
  for (int j = 0; j < 13; j++) {
   led.setPixelColor(j, led.Color(255,0,0));//红色
  led.show();
    delay(50);
  }
delay(3000);
  for (int j = 0; j < 13; j++) {
   led.setPixelColor(j, led.Color(0, 255,0));//绿色
  led.show();
    delay(50);
  }
delay(3000);
  for (int j = 0; j < 13; j++) {
   led.setPixelColor(j, led.Color(0, 0, 255));//蓝色
  led.show();
    delay(50);
  }
delay(3000);
 for (int j = 0; j < 13; j++) {
   led.setPixelColor(j, led.Color(255,255,0));//黄色
  led.show();
    delay(50);
  }
delay(3000);
 for (int j = 0; j < 13; j++) {
   led.setPixelColor(j, led.Color(255,97,0));//橙色
  led.show();
    delay(50);
  }
delay(3000);
}
