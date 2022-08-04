#include <painlessMesh.h>
#define   MESH_PREFIX     "xiaoqiu"  //设置mesh信息，名字密码随意，一样就行
#define   MESH_PASSWORD   "bangbangda"
#define   MESH_PORT       5555
Scheduler userScheduler;
painlessMesh  mesh;
void sendMessage() ;
Task taskSendMessage( TASK_SECOND * 1 , TASK_FOREVER, &sendMessage );
//只发送不接收
void sendMessage() {
  String msg = "hello";//发送消息，不一定是hello，随便一个，两端要写一样呀
  //  msg += mesh.getNodeId();
  mesh.sendBroadcast( msg );
  taskSendMessage.setInterval( random( TASK_SECOND * 1, TASK_SECOND * 5 ));
}
void setup() {
  Serial.begin(115200);
  pinMode(5, INPUT);
  mesh.setDebugMsgTypes( ERROR | STARTUP );
  mesh.init( MESH_PREFIX, MESH_PASSWORD, &userScheduler, MESH_PORT );
}

void loop() {
  if (digitalRead(5) == LOW) {//如果来人，发一个消息告诉另一块8266，来人了，开灯吧
       delay(2000);//这里我加了延时，太家可以不加试试看，加延时的目的一是稳定光电开关，二是不想人以来立即开灯，吓死了
    userScheduler.addTask( taskSendMessage );
    taskSendMessage.enable();
 
 if (digitalRead(5) == LOW) {
  mesh.update();
  delay(300);
}
