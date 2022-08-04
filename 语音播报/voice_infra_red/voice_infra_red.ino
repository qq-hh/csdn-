void speech(){
  unsigned char i = 0;
  unsigned char head[20];

  head[0] = 0xFD;
  head[1] = 0x00;
  head[2] = 0x11;
  head[3] = 0x01;
  head[4] = 0x00;
  head[5] = 0xC4;
  head[6] = 0xFA;
  head[7] = 0xBA;
  head[8] = 0xC3;
  head[9] = 0xA3;
  head[10] = 0xAC;
  head[11] = 0xBB;
  head[12] = 0xB6;  
  head[13] = 0xD3;
  head[14] = 0xAD;
  head[15] = 0xB9;
  head[16] = 0xE2;
  head[17] = 0xC1;
  head[18] = 0xD9;
  head[19] = 0x95;

  for(i=0; i<20; i++){
    Serial.write(head[i]);
  }
} 
void setup() {
  Serial.begin(9600);
}

void loop() {
   if (digitalRead(5) == LOW) {
  speech();
  delay(1000);
   }
}
