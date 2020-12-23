// ***** 0. Documentation Section *****
// TableTrafficLight.c for Lab 10
// Runs on LM4F120/TM4C123
// Index implementation of a Moore finite state machine to operate a traffic light.  
// Daniel Valvano, Jonathan Valvano
// November 7, 2013

// east/west red light connected to PB5
// east/west yellow light connected to PB4
// east/west green light connected to PB3
// north/south facing red light connected to PB2
// north/south facing yellow light connected to PB1
// north/south facing green light connected to PB0
// pedestrian detector connected to PE2 (1=pedestrian present)
// north/south car detector connected to PE1 (1=car present)
// east/west car detector connected to PE0 (1=car present)
// "walk" light connected to PF3 (built-in green LED)
// "don't walk" light connected to PF1 (built-in red LED)

// ***** 1. Pre-processor Directives Section *****
#include "TExaS.h"
#include "tm4c123gh6pm.h"

// ***** 2. Global Declarations Section *****

#define NVIC_ST_CTRL_R      (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R    (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R   (*((volatile unsigned long *)0xE000E018))

// represents a State of the FSM
struct State

{
unsigned char out[5];     // PB7-4 to right motor, PB3-0 to left
unsigned char wout[3];    // WALK SIGNAL LED
unsigned short wait;      // in 10ms units       
unsigned char next[8];    // input 0x00 means ok,
                          // 0x01 means right side bumped something,
                          // 0x02 means left side bumped something,
                          // 0x03 means head-on collision (both)
};

typedef const struct State StateType;

StateType Fsm[10] = 

{
	
{{0x14} , {0} , 1,   {0, 1, 2, 3,4,5,6,7} },    // WY , SR      // In=0) No Pedestrians(PE2=0) , No Cars are On South & West (PE1=0,PE0=0) 
	
{{0x0C} , {0x02} , 10, {0, 1, 2, 3,4,5,6,7} },  // WG , SR      // In=1) No Pedestrians(PE2=0) , Cars are On West (PE0=1), No Cars On South (PE1=0) 
 
{{0x21} , {0x02} , 10, {0, 1, 2, 3,4,5,6,7} },  // WR , SG      // In=2) No Pedestrians(PE2=0) , No Cars On West (PE0=0) , Cars are On South (PE1=1)
	
{{0x21} , {0} , 1,   {0, 1, 2, 3,4,5,6,7} },                    // In=3) No Pedestrians(PE2=0) , Cars are On South & West (PE1=1,PE0=1)
	
 //---------------------------------------------------------------------------------------------------------//
  
{{0x24},{0x08,0x02,0x00},1,   {0, 1, 2, 3,4,5,6,7} },          // In=4) Pedestrians (PE2=1)   , No Cars On South & West (PE1=0,PE0=0)
	
{{0x0A},{0x02},1,   {0, 1, 2, 3,4,5,6,7} },                    // In=5) Pedestrians (PE2=1)   , No Cars On South (PE1=0) , Cars On West (PE0=1)
	
{{0x11},{0x02}, 1,  {0, 1, 2, 3,4,5,6,7} },                    // In=6) Pedestrians (PE2=1)   , Cars On South (PE1=1) , No Cars On West (PE0=0)
	
{{0x21,0x12,0x0C,0x14},{0x02,0x08},2, {0, 1, 2, 3,4,5,6,7} },   // In=7) Pedestrians (PE2=1)   , Cars On South (PE1=1) , Cars On West (PE1=1)

{{0x14} , {0x02} , 1,   {0, 1, 2, 3,4,5,6,7} }, // WY , SR      // In=2) No Pedestrians(PE2=0) , No Cars On West (PE0=0) , Cars are On South (PE1=1)


{{0x22} , {0x02} , 1,   {0, 1, 2, 3,4,5,6,7} }, // WR , SY 



};

// FUNCTION PROTOTYPES: Each subroutine defined
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts

void SysTick_Init(void){
  NVIC_ST_CTRL_R = 0;               // disable SysTick during setup
  NVIC_ST_CTRL_R = 0x00000005;      // enable SysTick with core clock
}
// The delay parameter is in units of the 80 MHz core clock. (12.5 ns)
void SysTick_Wait(unsigned long delay){
  NVIC_ST_RELOAD_R = delay-1;  // number of counts to wait
  NVIC_ST_CURRENT_R = 0;       // any value written to CURRENT clears
  while((NVIC_ST_CTRL_R&0x00010000)==0){ // wait for count flag
  }
}
// 800000*12.5ns equals 10ms
void SysTick_Wait10ms(unsigned long delay){
  unsigned long i;
  for(i=0; i<delay; i++){
    SysTick_Wait(800000);  // wait 10ms
  }
}

// ALLOCATING PORT B FOR TRAFFIC LIGHTS SIGNALLING

void PortB_Init(void)
{ 
volatile unsigned long delay;
SYSCTL_RCGC2_R |= 0x02;            // 1) activate Port B
delay = SYSCTL_RCGC2_R;            // allow time for clock to stabilize
                                   // 2) no need to unlock PB7-0
GPIO_PORTB_AMSEL_R = 0x00;         // 3) disable analog function on PB7-0
GPIO_PORTB_PCTL_R = 0x00000000;    // 4) configure PB7-0 as GPIO
GPIO_PORTB_DIR_R = 0xFF;           // 5) make PB7-0 out
GPIO_PORTB_AFSEL_R = 0x00;         // 6) disable alt funct on PB7-0
GPIO_PORTB_DR8R_R = 0xFF;          // enable 8 mA drive on PB7-0
GPIO_PORTB_DEN_R = 0xFF;           // 7) enable digital I/O on PB7-0

}

// ALLOCATING PORT E TO BE INPUT PORT FOR SENSORS

void PortE_Init(void)
{ 

volatile unsigned long delay;
	
SYSCTL_RCGC2_R |= 0x10;            // 1) activate Port E

delay = SYSCTL_RCGC2_R;            // allow time for clock to stabilize
                                   
	                                 // 2) no need to unlock PE1-0

GPIO_PORTE_AMSEL_R &= ~0x07;       // 3) disable analog function on PE2-0	

GPIO_PORTE_PCTL_R &= ~0x000000FF;  // 4) configure PE1-0 as GPIO

GPIO_PORTE_DIR_R &= ~0x07;         // 5) make PE2-0 in

GPIO_PORTE_AFSEL_R &= ~0x07;       // 6) disable alt funct on PE2-0

GPIO_PORTE_DEN_R |= 0x07;          // 7) enable digital I/O on PE2-0

}


// ALLOCATING PORT F TO BE OUPUT PORT FOR PEDESTRIANS LED'S

void PortF_Init(void)
{ 
volatile unsigned long delay;
SYSCTL_RCGC2_R |= 0x00000020;      // 1) activate Port F
delay = SYSCTL_RCGC2_R;            // allow time for clock to stabilize
//GPIO_PORTF_LOCK_R = 0x4C4F434B;    // 2) unlock PortF PF0
//GPIO_PORTF_CR_R |= 0x1F;           // allow changes to PF4-0 
GPIO_PORTF_AMSEL_R = 0x00;         // 2) disable analog function on PortF Pins	
GPIO_PORTF_AFSEL_R= 0x00;          // 3) disable alt funct on PortF Pins
GPIO_PORTF_PCTL_R = 0x0;           // 4) configure PF1-0 as GPIO
GPIO_PORTF_DIR_R = 0x0A;           // 5) make PF3,PF1 out
GPIO_PORTF_DEN_R = 0x0A;           // 6) enable digital I/O on PF3,PF1


}


// ***** 3. Subroutines Section *****
unsigned char cState,input,i;      // current State (0 to 9) 

int main(void)

{ 

TExaS_Init(SW_PIN_PE210, LED_PIN_PB543210);  // activate grader and set system clock to 80 MHz
EnableInterrupts();
SysTick_Init();	                             // Initializing Systick Timer
PortB_Init();                                // initialize traffic llights outputs on Port B
PortE_Init();                                // initialize sensor inputs on Port E
PortF_Init();                                // initialize pedestrian led output on Port F
cState = 0;                                  // initial state = 0 	
i=0;
while(1)
{
	
// Output based on current state

GPIO_PORTB_DATA_R = Fsm[cState].out[0];      // TRAFFIC LIGHTS

GPIO_PORTF_DATA_R =Fsm[cState].wout[0];      // PEDESTRIAN LIGHTS
	
// Wait for time according to state

SysTick_Wait10ms(Fsm[cState].wait);
	
// Get input     

input = GPIO_PORTE_DATA_R&0x07;              // Input 0,1,2,3

	
	
if (input==0x01)

{

i=i+1;	

if (i==2)
{

GPIO_PORTB_DATA_R = Fsm[9].out[0];          	// WEST RED , SOUTH YELLOW
GPIO_PORTF_DATA_R =Fsm[9].wout[0];           // DON'T WALK RED LED ON
SysTick_Wait10ms(Fsm[9].wait);	              // WAIT 1S
	

GPIO_PORTB_DATA_R = Fsm[1].out[0];            // WEST GREEN ,SOUTH RED
GPIO_PORTF_DATA_R =Fsm[1].wout[0];            // DON'T WALK RED LED ON
SysTick_Wait10ms(Fsm[1].wait);	              // WAIT 1S 
i=0;
}                                            

}

if(input==0x02)
	
{

if(GPIO_PORTB_DATA_R != 0x21)	
GPIO_PORTB_DATA_R = Fsm[8].out[0];      // WY , SR

GPIO_PORTF_DATA_R =Fsm[8].wout[0];      // PEDESTRIAN LIGHTS	
	
SysTick_Wait10ms(Fsm[8].wait);

GPIO_PORTB_DATA_R = Fsm[2].out[0];      // WR , SG

GPIO_PORTF_DATA_R =Fsm[2].wout[0];      // PEDESTRIAN LIGHTS	
	
SysTick_Wait10ms(Fsm[2].wait);
	
	
}


if(input==0x04)
{
	
if(GPIO_PORTB_DATA_R != 0x24)
	
GPIO_PORTB_DATA_R = Fsm[8].out[0];           // WEST YELLOW , SOUTH RED
GPIO_PORTF_DATA_R =Fsm[8].wout[0];           // DON'T WALK RED LED ON
SysTick_Wait10ms(Fsm[8].wait);	             // WAIT 0.1S
	

GPIO_PORTB_DATA_R = Fsm[4].out[0];           // WEST RED , SOUTH RED	
GPIO_PORTF_DATA_R =Fsm[4].wout[0];           // WALK LED GREEN
SysTick_Wait10ms(Fsm[4].wait);	             // WAIT 1S


}	

	
if(input==0x07)

{
	
GPIO_PORTB_DATA_R = Fsm[4].out[0];           // WEST RED , SOUTH RED	
GPIO_PORTF_DATA_R =Fsm[4].wout[1];           // DON'T WALK RED LED ON
SysTick_Wait10ms(Fsm[4].wait);	             // WAIT 1S 	

GPIO_PORTF_DATA_R =Fsm[4].wout[2];           // DON'T WALK RED LED OFF & WALK LED OFF
SysTick_Wait10ms(Fsm[4].wait);	             // WAIT 1S 	

GPIO_PORTF_DATA_R =Fsm[4].wout[1];           // DON'T WALK RED LED ON
SysTick_Wait10ms(Fsm[4].wait);	             // WAIT 1S 
	

GPIO_PORTB_DATA_R = Fsm[2].out[0];           // WEST RED , SOUTH GREEN
GPIO_PORTF_DATA_R =Fsm[2].wout[0];           // DON'T WALK LED RED	
SysTick_Wait10ms(Fsm[2].wait);	             // WAIT 1S

	
GPIO_PORTB_DATA_R = Fsm[4].out[0];           // WEST RED , SOUTH RED	
GPIO_PORTF_DATA_R =Fsm[4].wout[0];           // WALK LED ON
SysTick_Wait10ms(Fsm[4].wait);	             // WAIT 1S
	
}	




	
// Change the state based on input and current state

cState = Fsm[cState].next[input];     


}// While bracket




}// main function bracket

