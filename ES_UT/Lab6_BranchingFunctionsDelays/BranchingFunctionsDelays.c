// BranchingFunctionsDelays.c Lab 6
// Runs on LM4F120/TM4C123
// Use simple programming structures in C to 
// toggle an LED while a button is pressed and 
// turn the LED on when the button is released.  
// This lab will use the hardware already built into the LaunchPad.
// Daniel Valvano, Jonathan Valvano
// January 8, 2014

// built-in connection: PF0 connected to negative logic momentary switch, SW2
// built-in connection: PF1 connected to red LED
// built-in connection: PF2 connected to blue LED
// built-in connection: PF3 connected to green LED
// built-in connection: PF4 connected to negative logic momentary switch, SW1

#include "TExaS.h"
#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))
#define SYSCTL_RCGC2_GPIOF      0x00000020  // port F Clock Gating Control
#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x4005D520))	
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x4005D524))
// basic functions defined at end of startup.s
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts

void Delay100ms(unsigned long time)
{
  unsigned long i;
  while(time > 0){
    
		i = 1333333;  // this number means 100ms
    while(i > 0){
      i = i - 1;
    }
    time = time - 1; // decrements every 100 ms
  }
}

void ini()
{

	
SYSCTL_RCGC2_R=0x00000020;

Delay100ms(3);

//GPIO_PORTF_LOCK_R=0x0;	      // UNLOCKING THE PORT F ALL BITS

//GPIO_PORTF_CR_R=0x1F;               // UNLOCKING PORT F PF0

GPIO_PORTF_DIR_R=0x04;                // MAKING PF4=0 I.E INPUT AND PF2=1 I.E OUTPUT

GPIO_PORTF_AFSEL_R=0x00;              // DISABLING ALTERNATE FUNCTION FOR 5 BITS OF PORTF	

GPIO_PORTF_PUR_R=0x10;                // ENABLING PULL UP FOR PF4	
	
GPIO_PORTF_DEN_R=0x14;                // ENABLING DIGITAL I/O FOR PF4 AND PF2	

GPIO_PORTF_AMSEL_R=0x00;              // DISABLING ALTERNATE MODES FOR PORT F PINS	

}

int main(void)
{ 

unsigned long volatile delay;

TExaS_Init(SW_PIN_PF4, LED_PIN_PF2);  // activate grader and set system clock to 80 MHz

// initialization goes here

ini();

EnableInterrupts();           // enable interrupts for the grader

while(1)

{

GPIO_PORTF_DATA_R=0x04;	
	
if(GPIO_PORTF_DATA_R ==0x04)

{
	
GPIO_PORTF_DATA_R=0x04;	

Delay100ms(1);

GPIO_PORTF_DATA_R=0x00;	

Delay100ms(1);

}	



//if(GPIO_PORTF_DATA_R==0x05)

//GPIO_PORTF_DATA_R=0x00;

//Delay100ms(1);

//GPIO_PORTF_DATA_R=0x04;

//Delay100ms(1);

//if(GPIO_PORTF_DATA_R==0x15)
	
//GPIO_PORTF_DATA_R=0x04;	

// body goes here

}

}
