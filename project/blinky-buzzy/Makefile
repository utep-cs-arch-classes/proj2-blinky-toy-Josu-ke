

# makfile configuration

COMMON_OBJECTS  =

CPU             = msp430g2553

CFLAGS          = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include



#switch the compiler (for the internal make rules)

CC              = msp430-elf-gcc

AS              = msp430-elf-as



all: buzzer.elf



#additional rules for files

buzzer.elf: ${COMMON_OBJECTS} buzzer.o blinkBuzzMain.o wdInterruptHandler.o p_interrupt_handler.o switches.o stateMachines.o led.o ../lib/libTimer.a

	${CC} ${CFLAGS} -o $@ $^



load: buzzer.elf

	msp430loader.sh buzzer.elf



clean:

	rm -f *.o *.elf



buzzer.c: buzzer.h

blinkBuzzMain.c: buzzer.h switches.h led.h 



wdInterruptHandler.o: stateMachines.h switches.h led.h

stateMachines.o: stateMachines.h buzzer.h led.h

switches.o: buzzer.h switches.h switches.c


