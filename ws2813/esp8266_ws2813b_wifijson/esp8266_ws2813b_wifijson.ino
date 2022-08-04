#include <ESP8266WiFi.h>
#include <Adafruit_NeoPixel.h>
#include <ArduinoJson.h>
//路由器WIFI和密码
const char* ssid = "zhenbang";//wifi设置换成自己的
const char*  password = "17718409969";
String message = "";
//静态地址、网关、子网掩码
IPAddress local_IP(192, 168, 31, 112);
IPAddress gateway(192, 168, 31, 1);
IPAddress subnet(255, 255, 255, 0);
//创建server
WiFiServer server(80);//端口号，随意修改，范围0-65535
#define PIN        0  //GPIO0接口
#define NUMPIXELS  12  //彩灯个数
Adafruit_NeoPixel led(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  //波特率
  Serial.begin(115200);
  WiFi.config(local_IP, gateway, subnet);//设置静态IP
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);//路由器的WiFi名称和密码
  //连接WIFI
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(WiFi.localIP());
  server.begin();
  led.begin();
  led.setBrightness(255); //设置亮度 (0~255)
}
void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
  }
  DynamicJsonDocument  doc(1024);
  WiFiClient incomingClient = server.available();
  if (incomingClient) {
    // 通过串口监视器输出客户端请求信息
    if (incomingClient.find("\r\n\r\n")) {
      while (incomingClient.available()) {
        message = message + char(incomingClient.read());
      }
      Serial.println(message);
      deserializeJson(doc, message);
      JsonObject obj = doc.as<JsonObject>();
      String action = obj["action"];
      String num = obj["num"];
      String color = obj["color"];
      // 通过串口监视器输出解析后的数据信息
      Serial.println(action);
      if (action == "open") {
        if (color == "red") {
          for (int i = 0; i < obj["num"].size(); i++) {
            int j = obj["num"][i].as<int>();
            led.setPixelColor(j, led.Color(255, 0, 0));
            led.show();
            delay(50);
          }
        }
        if (color == "blue") {
          for (int i = 0; i < obj["num"].size(); i++) {
            int j = obj["num"][i].as<int>();
            led.setPixelColor(j, led.Color(0, 0, 255));
            led.show();
            delay(50);
          }
        }
        if (color == "green") {
          for (int i = 0; i < obj["num"].size(); i++) {
            int j = obj["num"][i].as<int>();
            led.setPixelColor(j, led.Color(0, 255, 0));
            led.show();
            delay(50);
          }
        }
      }
      if (action == "close") {
        for (int i = 0; i < obj["num"].size(); i++) {
          int j = obj["num"][i].as<int>();
          led.setPixelColor(j, led.Color(0, 0, 0));
          led.show();
          delay(50);
        }
      }
    }
    String httpResponse = "HTTP/1.0 200 OK\r\n"
                          "Connection: close\r\n"
                          "Content-Type: application/json;\r\n"
                          "\r\n"
                          "{\"code\":1}";
    incomingClient.print(httpResponse);
    message = "";
  }
}
