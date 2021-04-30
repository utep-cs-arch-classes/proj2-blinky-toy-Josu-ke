#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"

int main(void) {
  configureClocks();
  buzzer_init();
  switch_init();
  led_init();
  lcd_init();
  
  enableWDTInterrupts();

  

char width = screenWidth;
char height = screenHeight;

clearScreen(COLOR_BLACK);
drawPixel(height/2,width/2,COLOR_RED);
  for(int i=0; i< 20;i++){
    for(int j=0; j<=i;j++){
	
	drawPixel(50+i,50+j,COLOR_WHITE);
      }
  }


  or_sr(0x18);

}
