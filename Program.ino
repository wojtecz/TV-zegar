#include <TVout.h>
#include <fontALL.h>
#include "schematic.h"
#include "TVOlogo.h"
                                                                                           //|
#include <virtuabotixRTC.h>                                                                              //|

virtuabotixRTC myRTC(2, 3, 4);

TVout TV;
int i=0;

void setup() {
  Serial.begin(9600);
  // Ustawianie godziny
  // seconds, minutes, hours, day of the week, day of the month, month, year
//  myRTC.setDS1302Time(00, 8, 18, 2, 31, 12, 2019);
  TV.begin(PAL,120,96);
  TV.select_font(font8x8ext);
 
  TV.println();
  TV.println();
  TV.println();
  TV.println();
  TV.println();
  TV.println("    Prosze");
  TV.println("    Czekac");
  TV.delay(1000);
  intro();
  myRTC.updateTime();  
  
  }
void loop(){
  TV.clear_screen();
  TV.println();
  TV.println();
  TV.println();
  TV.print("Dziala");
  TV.delay(5000);
  }
  
void intro() {
unsigned char w,l,wb;
  int index;
  w = pgm_read_byte(TVOlogo);
  l = pgm_read_byte(TVOlogo+1);
  if (w&7)
    wb = w/8 + 1;
  else
    wb = w/8;
  index = wb*(l-1) + 2;
  for ( unsigned char i = 1; i < l; i++ ) {
    TV.bitmap((TV.hres() - w)/2,0,TVOlogo,index,w,i);
    index-= wb;
    TV.delay(50);
  }
  for (unsigned char i = 0; i < (TV.vres() - l)/2; i++) {
    TV.bitmap((TV.hres() - w)/2,i,TVOlogo);
    TV.delay(50);
  }
  TV.delay(3000);
  TV.clear_screen();
}
