#include<ESP8266WiFi.h>
const char* ssid = "zhenbang";//wifi设置换成自己的
const char*  password = "17718409969";
String message = "";
WiFiServer server(80);
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(WiFi.localIP());//打印IP地址，这是esp8266是作为http的服务器，连接需要知道它的IP
  server.begin();
}
String httpResponse = "HTTP/1.0 200 OK\r\n"
                      "Connection: close\r\n"
                      "Content-Type: application/json;\r\n"
                      "\r\n"
                      "{\"code\":1}";//发送响应部分，客户端发送HTTP消息，收到后给个响应
void loop() {
  WiFiClient incomingClient = server.available();
  if (incomingClient) {
    if (incomingClient.find("\r\n\r\n")) {//只读取message部分
      while (incomingClient.available()) {
        message = message + char(incomingClient.read());
      }
  }
    Serial.println(message);//打印消息
    delay(10);
    message = "";//清除message内容
    incomingClient.print(httpResponse);//给客户端响应
  }
}
