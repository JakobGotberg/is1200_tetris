#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "header_file.h" 

uint8_t timeout_counter = 0;
uint8_t fall_speed = 5;	//lower fall_speeds -> faster fall
uint8_t index = 1;


void timer_setup( void )
{
TMR2 = 0;
T2CON |= 0x70;  // preset with 256
PR2 = 31250;     // re is (80 * 10^6)/256/10
T2CONSET = 0x8000; //starts timer

IEC(0) = 0x100;               // start interrupt with flag 8
IPC(2) = 0x00000014;         // sets priorety to 5
enable_interrupt();

  return;
}


void user_isr( void )
{
// stops timer
T2CONCLR = 0x8000; 
// resets timer, no need for it really
TMR2 = 0;         

// points to IFC(0)	
volatile int* ifs_ptr = (volatile int*) 0xbf881030;  
int interrupt_test = 0;

if((*ifs_ptr & 0x100) != 0){ 

	if(go_left_flag){
		go_left();
		go_left_flag = 0;
	}

	if(go_right_flag){
		go_right();
		go_right_flag = 0;
	}

	if(interrupt_test == 1){
	logic_to_pixel_set(index, 7);
	index++;
}

timeout_counter++;
// clears flag    0x18000108 -> 0x18000008	            
*ifs_ptr &= ~(0x100);    
}


	
// falls down, if shape hits floor or other shape; new shape falls from roof 
if( timeout_counter == fall_speed ){




	fall_down();
	timeout_counter = 0;
}

T2CONSET = 0x8000;   // start timer
  return;

}