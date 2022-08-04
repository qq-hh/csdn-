#ifndef __FONT_H
#define __FONT_H 

#ifdef __AVR__
#include <avr/pgmspace.h>
#elif defined(ESP8266)
#include <pgmspace.h>
#else
#define PROGMEM
#endif

typedef struct 
{
       unsigned char Index[2];  
       char Msk[128];
}typFNT_GB32; 
//字体取模：宋体常规小四
const typFNT_GB32 tfont32[] PROGMEM =
{
"北",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x20,0x00,0x00,0x1C,0x38,0x00,
0x00,0x18,0x30,0x00,0x00,0x18,0x30,0x00,0x00,0x18,0x30,0x00,0x00,0x18,0x30,0x00,
0x00,0x18,0x30,0x00,0x00,0x18,0x30,0x10,0x00,0x18,0x30,0x38,0x3F,0xF8,0x30,0x70,
0x00,0x18,0x31,0xC0,0x00,0x18,0x33,0x00,0x00,0x18,0x3C,0x00,0x00,0x18,0x30,0x00,
0x00,0x18,0x30,0x00,0x00,0x18,0x30,0x00,0x00,0x18,0x30,0x00,0x00,0x18,0x30,0x00,
0x00,0x18,0x30,0x00,0x00,0x18,0x30,0x00,0x00,0x18,0x30,0x08,0x00,0x78,0x30,0x08,
0x07,0x98,0x30,0x08,0x3E,0x18,0x30,0x08,0x38,0x18,0x30,0x08,0x00,0x18,0x30,0x1C,
0x00,0x18,0x3F,0xFC,0x00,0x18,0x1F,0xF8,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,/*"北",0*/
"京",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x03,0x80,0x00,
0x00,0x01,0xC0,0x00,0x00,0x00,0xC0,0x10,0x00,0x00,0x80,0x38,0x3F,0xFF,0xFF,0xFC,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0xFF,0xFF,0x80,
0x00,0xC0,0x03,0x00,0x00,0xC0,0x03,0x00,0x00,0xC0,0x03,0x00,0x00,0xC0,0x03,0x00,
0x00,0xC0,0x03,0x00,0x00,0xC0,0x03,0x00,0x00,0xFF,0xFF,0x00,0x00,0xC1,0x83,0x00,
0x00,0x01,0x80,0x00,0x00,0x21,0x88,0x00,0x00,0x71,0x86,0x00,0x00,0x61,0x83,0x00,
0x00,0xC1,0x81,0x80,0x01,0x81,0x80,0xE0,0x03,0x01,0x80,0x60,0x04,0x01,0x80,0x70,
0x18,0x1F,0x80,0x30,0x20,0x07,0x80,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,/*"京",1*/
"瓜",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x07,0xC0,
0x00,0x00,0x7F,0x80,0x01,0xFF,0xC4,0x00,0x01,0x83,0x04,0x00,0x01,0x83,0x04,0x00,
0x01,0x83,0x04,0x00,0x01,0x83,0x04,0x00,0x01,0x83,0x04,0x00,0x01,0x83,0x04,0x00,
0x01,0x83,0x04,0x00,0x01,0x83,0x06,0x00,0x01,0x83,0x02,0x00,0x01,0x83,0x02,0x00,
0x01,0x83,0x02,0x00,0x01,0x03,0x03,0x00,0x01,0x03,0x03,0x00,0x01,0x03,0x01,0x00,
0x03,0x03,0x01,0x80,0x03,0x03,0x21,0x80,0x03,0x03,0x18,0xC0,0x02,0x03,0x0C,0xC0,
0x06,0x03,0x3E,0x60,0x04,0x03,0xC6,0x70,0x0C,0x03,0x86,0x38,0x08,0x03,0x06,0x1E,
0x10,0x00,0x00,0x10,0x20,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"瓜",0*/
"豆",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,
0x0F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x80,0x01,0xFF,0xFF,0xC0,0x01,0x80,0x01,0x80,
0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
0x01,0x80,0x01,0x80,0x01,0xFF,0xFF,0x80,0x01,0x80,0x01,0x80,0x01,0x00,0x00,0x00,
0x00,0x40,0x04,0x00,0x00,0x20,0x0F,0x00,0x00,0x30,0x0E,0x00,0x00,0x18,0x0C,0x00,
0x00,0x18,0x18,0x00,0x00,0x18,0x10,0x00,0x00,0x18,0x30,0x00,0x00,0x00,0x20,0x18,
0x3F,0xFF,0xFF,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"豆",1*/
"科",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x0C,0x00,0xE0,
0x00,0x3C,0x00,0xC0,0x07,0xE0,0x00,0xC0,0x38,0xC0,0x00,0xC0,0x00,0xC0,0x60,0xC0,
0x00,0xC0,0x30,0xC0,0x00,0xC0,0x18,0xC0,0x00,0xC0,0x18,0xC0,0x00,0xC4,0x00,0xC0,
0x3F,0xFE,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x40,0xC0,0x01,0xC0,0x60,0xC0,
0x01,0xF0,0x30,0xC0,0x03,0xDC,0x10,0xC0,0x02,0xCC,0x00,0xCC,0x06,0xC4,0x00,0xFC,
0x04,0xC4,0x0F,0xC0,0x08,0xC1,0xF0,0xC0,0x10,0xC6,0x00,0xC0,0x20,0xC0,0x00,0xC0,
0x40,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,
0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0x80,0x00,0x80,0x00,0x00,0x00,0x00,/*"科",0*/
"技",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x08,0x00,0x01,0xC0,0x0E,0x00,
0x01,0x80,0x0C,0x00,0x01,0x80,0x0C,0x00,0x01,0x80,0x0C,0x00,0x01,0x80,0x0C,0x00,
0x01,0x98,0x0C,0x18,0x3F,0xFF,0xFF,0xFC,0x01,0x80,0x0C,0x00,0x01,0x80,0x0C,0x00,
0x01,0x80,0x0C,0x00,0x01,0x80,0x0C,0x00,0x01,0x8C,0x0C,0x20,0x01,0xB3,0xFF,0xF0,
0x01,0xC0,0x80,0x60,0x0F,0x80,0x80,0x60,0x3D,0x80,0x40,0xC0,0x31,0x80,0x40,0xC0,
0x01,0x80,0x61,0x80,0x01,0x80,0x21,0x80,0x01,0x80,0x33,0x00,0x01,0x80,0x16,0x00,
0x01,0x80,0x0E,0x00,0x01,0x80,0x1E,0x00,0x01,0x80,0x37,0x00,0x01,0x80,0xE3,0xC0,
0x1F,0x81,0x80,0xF8,0x07,0x8E,0x00,0x7C,0x02,0x30,0x00,0x00,0x00,0x00,0x00,0x00,/*"技",1*/
"有",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x03,0x80,0x00,
0x00,0x03,0x00,0x00,0x00,0x07,0x00,0x10,0x00,0x06,0x00,0x38,0x3F,0xFF,0xFF,0xFC,
0x00,0x0C,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x30,0x01,0x00,
0x00,0x3F,0xFF,0x80,0x00,0x60,0x01,0x00,0x00,0xE0,0x01,0x00,0x01,0xE0,0x01,0x00,
0x03,0x60,0x01,0x00,0x06,0x7F,0xFF,0x00,0x0C,0x60,0x01,0x00,0x10,0x60,0x01,0x00,
0x20,0x60,0x01,0x00,0x00,0x60,0x01,0x00,0x00,0x7F,0xFF,0x00,0x00,0x60,0x01,0x00,
0x00,0x60,0x01,0x00,0x00,0x60,0x01,0x00,0x00,0x60,0x01,0x00,0x00,0x60,0x01,0x00,
0x00,0x60,0x3F,0x00,0x00,0x60,0x07,0x00,0x00,0x40,0x02,0x00,0x00,0x00,0x00,0x00,/*"有",0*/
"限",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x22,0x00,0x40,
0x0F,0xF3,0xFF,0xE0,0x08,0x63,0x00,0x40,0x08,0x63,0x00,0x40,0x08,0x43,0x00,0x40,
0x08,0x43,0x00,0x40,0x08,0xC3,0x00,0x40,0x08,0x83,0xFF,0xC0,0x08,0x83,0x00,0x40,
0x08,0x83,0x00,0x40,0x08,0x83,0x00,0x40,0x08,0x43,0x00,0x40,0x08,0x43,0xFF,0xC0,
0x08,0x23,0x20,0x40,0x08,0x33,0x10,0x20,0x08,0x33,0x10,0x70,0x08,0x33,0x10,0x60,
0x08,0x33,0x19,0x80,0x08,0x33,0x0B,0x00,0x09,0xF3,0x0C,0x00,0x08,0xE3,0x06,0x00,
0x08,0x83,0x07,0x00,0x08,0x03,0x1B,0x80,0x08,0x03,0x21,0xC0,0x08,0x03,0xC0,0xF8,
0x08,0x03,0x80,0x78,0x08,0x01,0x00,0x10,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"限",1*/
"公",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x08,0x20,0x00,
0x00,0x0C,0x20,0x00,0x00,0x18,0x10,0x00,0x00,0x18,0x10,0x00,0x00,0x30,0x18,0x00,
0x00,0x30,0x08,0x00,0x00,0x60,0x0C,0x00,0x00,0x60,0x06,0x00,0x00,0xC0,0x06,0x00,
0x00,0x80,0x03,0x00,0x01,0x81,0x01,0x80,0x03,0x01,0x81,0xE0,0x06,0x01,0xC0,0xF0,
0x0C,0x03,0x80,0x7C,0x18,0x03,0x00,0x30,0x20,0x06,0x00,0x00,0x00,0x0C,0x00,0x00,
0x00,0x0C,0x00,0x00,0x00,0x18,0x10,0x00,0x00,0x30,0x08,0x00,0x00,0x20,0x0C,0x00,
0x00,0x60,0x06,0x00,0x00,0xC0,0x03,0x00,0x01,0x80,0x03,0x80,0x07,0xFF,0xFF,0x80,
0x03,0xF8,0x01,0xC0,0x03,0x00,0x00,0xC0,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,/*"公",0*/
"司",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,
0x07,0xFF,0xFF,0xE0,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x60,
0x00,0x00,0x00,0x60,0x00,0x00,0x18,0x60,0x1F,0xFF,0xFC,0x60,0x00,0x00,0x00,0x60,
0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x60,0x02,0x00,0x40,0x60,0x03,0xFF,0xE0,0x60,
0x03,0x00,0x40,0x60,0x03,0x00,0x40,0x60,0x03,0x00,0x40,0x60,0x03,0x00,0x40,0x60,
0x03,0x00,0x40,0x60,0x03,0x00,0x40,0x60,0x03,0xFF,0xC0,0x60,0x03,0x00,0x40,0x60,
0x03,0x00,0x60,0x60,0x02,0x00,0x00,0x60,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x60,
0x00,0x00,0x0F,0xC0,0x00,0x00,0x01,0xC0,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,/*"司",1*/
};

#endif
