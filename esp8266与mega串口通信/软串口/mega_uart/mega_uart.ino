//mega2560硬串口代码
#include <SoftwareSerial.h>
SoftwareSerial arduinoSerial = SoftwareSerial(10, 11);
String  message = "";//定义字符串接收串口消息
void setup() {
  Serial.begin(9600);
  arduinoSerial.begin(9600);
  arduinoSerial.flush();
}

void loop()
{
  if (arduinoSerial.available() > 0) {
    while (arduinoSerial.available() > 0)
    {
      message = message + char(arduinoSerial.read());

    }

    Serial.println(message);//打印消息

    message = "";//清除消息，大家可以试下不清除，消息是一直累加的
  }
}
