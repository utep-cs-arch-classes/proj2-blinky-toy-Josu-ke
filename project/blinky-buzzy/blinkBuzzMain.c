#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"

int main(void) {
  ConfigureClocks();
  switch_init();
  led_init();
  enableWDTInterrupts();


  or_sr(0x18)

}