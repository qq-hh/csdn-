#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
const char* ssid = "zhenbang";//wifi设置换成自己的
const char*  password = "17718409969";

void setup() {
  Serial.begin(9600, SERIAL_8N1);   // 初始化串口通讯波特率为9600

  WiFi.mode(WIFI_STA);                         
  WiFi.begin(ssid, password);                   
  while (WiFi.status() != WL_CONNECTED)         
  {
    delay(1000);
    Serial.print("waiting for ");
  }
  Serial.println("WiFi connected!");   // NodeMCU将通过串口监视器输出"连接成功"信息。
}

void loop() {
  String info = "";
  while (Serial.available() > 0) {
    delay(300);
    info = Serial.readString();
    Serial.println(info);
  }
}
