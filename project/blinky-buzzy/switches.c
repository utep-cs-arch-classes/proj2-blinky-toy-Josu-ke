#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"

char switch_state, switch_state_down, switch_state_down2, switch_state_down3, switch_state_down4, switch_state_changed; /* effectively boolean */

static char switch_update_interrupt_sense(){
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);/* if switch down, sense up */
  return p2val;

}
void switch_init()/* setup switch */{
  P2REN |= SWITCHES;/* enables resistors for switches */
  P2IE |= SWITCHES;/* enable interrupts from switches */
  P2OUT |= SWITCHES;/* pull-ups for switches */
  P2DIR &= ~SWITCHES;/* set switches' bits for input */
  switch_update_interrupt_sense();
  //led_update();
}

void switch_interrupt_handler(){
  char p2val = switch_update_interrupt_sense();
  switch_state_down = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  switch_state_down2 = (p2val & SW2) ? 0 : 1; /* 0 when SW2 is up*/
  switch_state_down3 = (p2val & SW3) ? 0 : 1;
  switch_state_down4 = (p2val & SW4) ? 0 : 1; /* 0 when SW4 is up*/
  switch_state_changed = 1;

  if(switch_state_down == 1){
    switch_state = 1;
  }

  else if(switch_state_down2 == 1){
    switch_state = 2;
  }

  else if(switch_state_down3 == 1){
    switch_state = 3;
  }
  
  else if(switch_state_down4 == 1){
    switch_state = 4;
   }
  switch_state_changed = 1; //Indicates that a state change occured
}
