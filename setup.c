#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "header_file.h" 

uint8_t timeout_counter = 0;
uint8_t fall_speed = 10;

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

  T2CONCLR = 0x8000; // stops timer
  TMR2 = 0;         // resets timer

 volatile int* ifs_ptr = (volatile int*) 0xbf881030; // points to IFC(0)
 


if((*ifs_ptr & 0x100) != 0){ 
	display_print();
	timeout_counter++;            
  *ifs_ptr &= ~(0x100);    // clears flag    0x18000108 -> 0x18000008
}

if( timeout_counter == fall_speed){
	fall_down();
	timeout_counter = 0;
	
}




//display_print();




 
T2CONSET = 0x8000;   // start timer
  return;

  
}