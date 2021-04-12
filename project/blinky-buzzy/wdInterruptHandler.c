#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "led.h"




void __interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
  static char blink_count = 0;
  if (++blink_count == 125) { //Every half a second
    if(switch_state == 1){ //tone is played
       play_tone();
       // state_blink();
    }
    if(switch_state == 2){
      play_another_tone();
    }
    if(switch_state == 3){
      state_blink();
    }
    if(switch_state == 4){
      stop();
    }
    blink_count = 0;

  }

}
