#include <painlessMesh.h>
#define   MESH_PREFIX     "xiaoqiu"   //设置mesh信息，名字密码随意，一样就行
#define   MESH_PASSWORD   "bangbangda"
#define   MESH_PORT       5555
#define ledr 5 //我用的是rgb共阳极灯，大家灯不一样的话，点灯部分百度一下或者问我
#define  ledg 4
#define  ledb  2
Scheduler userScheduler;
painlessMesh  mesh;
void receivedCallback( uint32_t from, String &msg ) {//收消息
  String message = msg.c_str();
  Serial.println(message);
  if (message == "hello") {//8266收到另一块发来的消息后，开灯红色，这里我写了5s关灯
    digitalWrite(ledr, 0);
    digitalWrite(ledg, 255);
    digitalWrite(ledb, 255);
    delay(5000);
    digitalWrite(ledr, 255);
    digitalWrite(ledg, 255);
    digitalWrite(ledb, 255);
    delay(300);
    message="";
  }
}
void setup() {
  Serial.begin(115200);
  pinMode(ledr, OUTPUT);//rgb初始化
  pinMode(ledg, OUTPUT);
  pinMode(ledb, OUTPUT);
  digitalWrite(ledr, 255);//此处是关灯
  digitalWrite(ledg, 255);
  digitalWrite(ledb, 255);
  mesh.setDebugMsgTypes( ERROR | STARTUP );
  //只接收不发送
  mesh.init( MESH_PREFIX, MESH_PASSWORD, &userScheduler, MESH_PORT );
  mesh.onReceive(&receivedCallback);
}
void loop() {

  mesh.update();
}
