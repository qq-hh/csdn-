void speech(){
  unsigned char i = 0;
  unsigned char head[46];

  head[0] = 0xFD;
  head[1] = 0x00;
  head[2] = 0x2B;
  head[3] = 0x01;
  head[4] = 0x00;
  head[5] = 0xD4;
  head[6] = 0xE7;
  head[7] = 0xC9;
  head[8] = 0xCF;
  head[9] = 0xBA;
  head[10] = 0xC3;
  head[11] = 0xA3;
  head[12] = 0xAC;
  head[13] = 0xCF;
  head[14] = 0xD6;
  head[15] = 0xD4;
  head[16] = 0xDA;
  head[17] = 0xCA;
  head[18] = 0xC7;
  head[19] = 0xB1;
  head[20] = 0xB1;
  head[21] = 0xBE;
  head[22] = 0xA9;
  head[23] = 0xCA;
  head[24] = 0xB1;
  head[25] = 0xBC;
  head[26] = 0xE4;
  head[27] = 0xBE;
  head[28] = 0xC5;
  head[29] = 0xB5;
  head[30] = 0xE3;
  head[31] = 0xB0;
  head[32] = 0xEB;
  head[33] = 0xA3;
  head[34] = 0xAC;
  head[35] = 0xC5;
  head[36] = 0xAC;
  head[37] = 0xC1;
  head[38] = 0xA6;
  head[39] = 0xD1;
  head[40] = 0xA7;
  head[41] = 0xCF;
  head[42] = 0xB0;
  head[43] = 0xD1;
  head[44] = 0xBD;
  head[45] = 0xA8;

  for(i=0; i<46; i++){
    Serial.write(head[i]);
  }
}
void setup() {
  Serial.begin(9600);
}

void loop() {
  speech();
  delay(10000);

}
