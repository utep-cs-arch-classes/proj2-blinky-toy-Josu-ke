#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
//stops the current state

void stop(){
   buzzer_set_period(0);
}

char toggle_red()
{
  static char state = 0;

  switch(state){
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;
}

char toggle_green()
{
  char changed = 0;

  if(red_on){
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}

void lol(){
  char changed = 0;

  static enum {R=0, G=1}
  color = G;
  switch(color){
  case R:
    changed = toggle_red();
    color = G;
    break;
  case G:
    changed = toggle_green();
    color = R;
    break;
  }

  led_changed = changed;
}

void play_tone(){
  buzzer_set_period(2217);
}
void play_another_tone(){
  buzzer_set_period(1040);
}

void state_blink(){
  char changed = 0;



  static enum {R=0, G=1} color = G;

  switch (color) {

  case R: changed = toggle_red(); color = G; break;

  case G: changed = toggle_green(); color = R; break;

  }



  led_changed = changed;

  led_update();
   
}
