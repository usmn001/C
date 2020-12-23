// ***** 0. Documentation Section *****
// SwitchLEDInterface.c for Lab 8
// Runs on LM4F120/TM4C123
// Use simple programming structures in C to toggle an LED
// while a button is pressed and turn the LED on when the
// button is released.  This lab requires external hardware
// to be wired to the LaunchPad using the prototyping board.
// January 11, 2014

// Lab 8
//      Jon Valvano and Ramesh Yerraballi
//      November 21, 2013

// ***** 1. Pre-processor Directives Section *****
#include "TExaS.h"
#include "tm4c123gh6pm.h"

// ***** 2. Global Declarations Section *****

// FUNCTION PROTOTYPES: Each subroutine defined
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts

// ***** 3. Subroutines Section *****

// PE0, PB0, or PA2 connected to positive logic momentary switch using 10 k ohm pull down resistor
// PE1, PB1, or PA3 connected to positive logic LED through 470 ohm current limiting resistor
// To avoid damaging your hardware, ensure that your circuits match the schematic
// shown in Lab8_artist.sch (PCB Artist schematic file) or 
// Lab8_artist.pdf (compatible with many various readers like Adobe Acrobat).
void delay(unsigned long time)
{
unsigned long i;
while(time > 0)
{
i=666665;
//i = 6666665;

while(i > 0)
{
i = i - 1;
}

time = time - 1;
}

}

int main(void)
{ 
//**********************************************************************
// The following version tests input on PE0 and output on PE1
//**********************************************************************

TExaS_Init(SW_PIN_PE0, LED_PIN_PE1);  // activate grader and set system clock to 80 MHz
  
EnableInterrupts();                   // enable interrupts for the grader
SYSCTL_RCGC2_R |= 0x10;               // 1) E clock
GPIO_PORTE_DIR_R=0x02;                // PE1 IS OUTPUT AND PE0 IS INPUT
GPIO_PORTE_DATA_R=0x02;               //MAKING PE1=1;	
GPIO_PORTE_AMSEL_R &= 0x00;           // 3) disable analog function
GPIO_PORTE_PCTL_R &= 0x00000000;      // 4) GPIO clear bit PCTL  	
GPIO_PORTE_AFSEL_R &= 0x00;           // 6) no alternate function
GPIO_PORTE_DEN_R |= 0x03;             // 7) enable digital pins PE0 & PE1 
	
while(1)
{
		
//GPIO_PORTE_DATA_R=0x02;               //MAKING PE1=1;
        	                            // waiting for about 100ms
if(GPIO_PORTE_DATA_R == 0x03)	
{
GPIO_PORTE_DATA_R=0x00;
delay(2);
GPIO_PORTE_DATA_R=0x02;	
delay(2);

}	
else
GPIO_PORTE_DATA_R=0x02;

}
  
}
