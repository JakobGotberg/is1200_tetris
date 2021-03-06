/* mipslabdata.c
   This file compiled 2015 by F Lundevall
   from original code written by Axel Isaksson

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "header_file.h"  /* Declatations for these labs */


uint8_t rotationPosition = 0;
uint8_t row = 1;
uint8_t block = 5;
uint8_t downCollision = 0;
uint8_t leftCollision = 0;
uint8_t rightCollision = 0;
uint8_t gameover = 0;
uint8_t score = 0;
uint8_t lowest_row = 1;

uint8_t go_left_flag = 0;
uint8_t go_right_flag = 0;
uint8_t new_shape_flag = 0;


shape obj;

shape T0;
shape O;
shape L0;
shape L1;
shape L2;
shape L3;
shape I0;
shape I1;
shape J0;
shape J1;
shape J2;
shape J3;
shape T0;
shape T1;
shape T2;
shape T3;
shape Z0;
shape Z1;
shape S0;
shape S1;

void shape_init()
{
//shape O
	
	//Cube 1
	O.row1 = 1;
	O.block1 = 6;
	//Cube 2
	O.row2 = 1;		//left collision cube
	O.block2 = 5;
	//Cube3
	O.row3 = 2;
	O.block3 = 6;
	//Cube 4
	O.row4 = 2;		//left collision cube
	O.block4 = 5;

    //Bottom, left, right cubes
    O.bottom_cube = 2;
    O.left_cube = 6;
    O.right_cube = 5;

	//shape L
	
	//Cube 1
	L0.row1 = 1; 
	L0.block1 = 4;
	//Cube 2
	L0.row2 = 2;
	L0.block2 = 2;
	//Cube 3
	L0.row3 = 2;
	L0.block3 = 3;
	//Cube 4
	L0.row4 = 2;
	L0.block4 = 4;

    //Bottom, left, right cubes
    L0.bottom_cube = 2;
    L0.left_cube = 2;
    L0.right_cube = 4;


	//Cube 1
	L1.row1 = 1; 
	L1.block1 = 6;
	//Cube 2
	L1.row2 = 2;
	L1.block2 = 6;
	//Cube 3
	L1.row3 = 3;
	L1.block3 = 6;
	//Cube 4
	L1.row4 = 3;
	L1.block4 = 5;

     //Bottom, left, and right cubes
    L1.bottom_cube = 3;
    L1.left_cube = 6;
    L1.right_cube = 5;
	
	
	//Cube 1
	L2.row1 = 1; 
	L2.block1 = 6;
	//Cube 2
	L2.row2 = 1;
	L2.block2 = 5;
	//Cube 3
	L2.row3 = 1;
	L2.block3 = 4;
	//Cube 4
	L2.row4 = 2;
	L2.block4 = 6;

    //Bottom, left, and right cubes
    L2.bottom_cube = 2;
    L2.left_cube = 6;
    L2.right_cube = 4;

	
	//Cube 1
	L3.row1 = 1; 
	L3.block1 = 6;
	//Cube 2
	L3.row2 = 1;
	L3.block2 = 5;
	//Cube 3
	L3.row3 = 2;
	L3.block3 = 5;
	//Cube 4
	L3.row4 = 3;
	L3.block4 = 5;

     //Bottom, left, and right cubes
    L3.bottom_cube = 3;
    L3.left_cube = 6;
    L3.right_cube = 5;

	//shape I
	//Cube 1
	I0.row1 = 1; 
	I0.block1 = 7;
	//Cube 2
	I0.row2 = 1;
	I0.block2 = 6;
	//Cube 3
	I0.row3 = 1;
	I0.block3 = 5;
	//Cube 4
	I0.row4 = 1;
	I0.block4 = 4;

     //Bottom, left, and right cubes
    I0.bottom_cube = 1;
    I0.left_cube = 7;
    I0.right_cube = 4;

	//Cube 1
	I1.row1 = 1; 
	I1.block1 = 6;
	//Cube 2
	I1.row2 = 2;
	I1.block2 = 6;
	//Cube 3
	I1.row3 = 3;
	I1.block3 = 6;
	//Cube 4
	I1.row4 = 4;
	I1.block4 = 6;

    //Bottom, left, and right cubes
    I1.bottom_cube = 4;
    I1.left_cube = 6;
    I1.right_cube = 6;

	//shape J
	//Cube 1
	J0.row1 = 1; 
	J0.block1 = 6;
	//Cube 2
	J0.row2 = 2;
	J0.block2 = 6;
	//Cube 3
	J0.row3 = 2;
	J0.block3 = 5;
	//Cube 4
	J0.row4 = 2;
	J0.block4 = 4;

    //Bottom, left, and right cubes
    J0.bottom_cube = 2;
    J0.left_cube = 6;
    J0.right_cube = 4;

	//Cube 1
	J1.row1 = 1; 
	J1.block1 = 6;
	//Cube 2
	J1.row2 = 1;
	J1.block2 = 5;
	//Cube 3
	J1.row3 = 2;
	J1.block3 = 6;
	//Cube 4
	J1.row4 = 3;
	J1.block4 = 6;

    //Bottom, left, and right cubes
    J1.bottom_cube = 3;
    J1.left_cube = 6;
    J1.right_cube = 5;

	//Cube 1
	J2.row1 = 1; 
	J2.block1 = 6;
	//Cube 2
	J2.row2 = 1;
	J2.block2 = 5;
	//Cube 3
	J2.row3 = 1;
	J2.block3 = 4;
	//Cube 4
	J2.row4 = 2;
	J2.block4 = 4;

    //Bottom, left, and right cubes
    J2.bottom_cube = 2;
    J2.left_cube = 6;
    J2.right_cube = 4;

	//Cube 1
	J3.row1 = 1; 
	J3.block1 = 4;
	//Cube 2
	J3.row2 = 2;
	J3.block2 = 4;
	//Cube 3
	J3.row3 = 3;
	J3.block3 = 5;
	//Cube 4
	J3.row4 = 3;
	J3.block4 = 4;

     //Bottom, left, and right cubes
    J3.bottom_cube = 3;
    J3.left_cube = 5;
    J3.right_cube = 4;

	//shape T
	//Cube 1
	T0.row1 = 1; 
	T0.block1 = 5;
	//Cube 2
	T0.row2 = 2;
	T0.block2 = 6;
	//Cube 3
	T0.row3 = 2;
	T0.block3 = 5;
	//Cube 4
	T0.row4 = 2;
	T0.block4 = 4;

    //Bottom, left, and right cubes
    T0.bottom_cube = 2;
    T0.left_cube = 6;
    T0.right_cube = 4;

    
	//Cube 1
	T1.row1 = 1; 
	T1.block1 = 5;
	//Cube 2
	T1.row2 = 2;
	T1.block2 = 5;
	//Cube 3
	T1.row3 = 2;
	T1.block3 = 4;
	//Cube 4
	T1.row4 = 3;
	T1.block4 = 5;

     //Bottom, left, and right cubes
    T1.bottom_cube = 3;
    T1.left_cube = 5;
    T1.right_cube = 4;

	//Cube 1
	T2.row1 = 1; 
	T2.block1 = 6;
	//Cube 2
	T2.row2 = 1;
	T2.block2 = 5;
	//Cube 3
	T2.row3 = 1;
	T2.block3 = 4;
	//Cube 4
	T2.row4 = 2;
	T2.block4 = 5;

    //Bottom, left, and right cubes
    T2.bottom_cube = 2;
    T2.left_cube = 6;
    T2.right_cube = 4;

	
	//Cube 1
	T3.row1 = 1; 
	T3.block1 = 5;
	//Cube 2
	T3.row2 = 2;
	T3.block2 = 6;
	//Cube 3
	T3.row3 = 2;
	T3.block3 = 5;
	//Cube 4
	T3.row4 = 3;
	T3.block4 = 5;

     //Bottom, left, and right cubes
    T3.bottom_cube = 3;
    T3.left_cube = 6;
    T3.right_cube = 5;

	//Cube 1
	Z0.row1 = 1; 
	Z0.block1 = 6;
	//Cube 2
	Z0.row2 = 1;
	Z0.block2 = 5;
	//Cube 3
	Z0.row3 = 2;
	Z0.block3 = 5;
	//Cube 4
	Z0.row4 = 2;
	Z0.block4 = 4;

     //Bottom, left, and right cubes
    Z0.bottom_cube = 2;
    Z0.left_cube = 6;
    Z0.right_cube = 4;

	//Cube 1
	Z1.row1 = 1; 
	Z1.block1 = 4;
	//Cube 2
	Z1.row2 = 2;
	Z1.block2 = 5;
	//Cube 3
	Z1.row3 = 2;
	Z1.block3 = 4;
	//Cube 4
	Z1.row4 = 3;
	Z1.block4 = 5;
    
    //Bottom, left, and right cubes
    Z1.bottom_cube = 3;
    Z1.left_cube = 5;
    Z1.right_cube = 4;

	//shape S
	//Cube 1
	S0.row1 = 1; 
	S0.block1 = 5;
	//Cube 2
	S0.row2 = 1;
	S0.block2 = 4;
	//Cube 3
	S0.row3 = 2;
	S0.block3 = 6;
	//Cube 4
	S0.row4 = 2;
	S0.block4 = 5;

     //Bottom, left, and right cubes
    S0.bottom_cube = 2;
    S0.left_cube = 6;
    S0.right_cube = 4;

	//Cube 1
	S1.row1 = 1; 
	S1.block1 = 5;
	//Cube 2
	S1.row2 = 2;
	S1.block2 = 5;
	//Cube 3
	S1.row3 = 2;
	S1.block3 = 4;
	//Cube 4
	S1.row4 = 3;
	S1.block4 = 4;

       //Bottom, left, and right cubes
    S0.bottom_cube = 3;
    S0.left_cube = 5;
    S0.right_cube = 4;




}


// 512 element, 
// 0-127 first page, 
// 128-255 secound page
// 256 - 383 third page
// 384 - 511 
uint8_t dis_arr[] = 
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

uint8_t* dis_ptr = dis_arr;

uint8_t logic_array[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,		// row 20
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};	// row 1

uint8_t* log_ptr = logic_array;

uint8_t collision_array[20][10] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,		// row 20
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

char textbuffer[4][16];

const uint8_t const font[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 94, 0, 0, 0, 0,
	0, 0, 4, 3, 4, 3, 0, 0,
	0, 36, 126, 36, 36, 126, 36, 0,
	0, 36, 74, 255, 82, 36, 0, 0,
	0, 70, 38, 16, 8, 100, 98, 0,
	0, 52, 74, 74, 52, 32, 80, 0,
	0, 0, 0, 4, 3, 0, 0, 0,
	0, 0, 0, 126, 129, 0, 0, 0,
	0, 0, 0, 129, 126, 0, 0, 0,
	0, 42, 28, 62, 28, 42, 0, 0,
	0, 8, 8, 62, 8, 8, 0, 0,
	0, 0, 0, 128, 96, 0, 0, 0,
	0, 8, 8, 8, 8, 8, 0, 0,
	0, 0, 0, 0, 96, 0, 0, 0,
	0, 64, 32, 16, 8, 4, 2, 0,
	0, 62, 65, 73, 65, 62, 0, 0,
	0, 0, 66, 127, 64, 0, 0, 0,
	0, 0, 98, 81, 73, 70, 0, 0,
	0, 0, 34, 73, 73, 54, 0, 0,
	0, 0, 14, 8, 127, 8, 0, 0,
	0, 0, 35, 69, 69, 57, 0, 0,
	0, 0, 62, 73, 73, 50, 0, 0,
	0, 0, 1, 97, 25, 7, 0, 0,
	0, 0, 54, 73, 73, 54, 0, 0,
	0, 0, 6, 9, 9, 126, 0, 0,
	0, 0, 0, 102, 0, 0, 0, 0,
	0, 0, 128, 102, 0, 0, 0, 0,
	0, 0, 8, 20, 34, 65, 0, 0,
	0, 0, 20, 20, 20, 20, 0, 0,
	0, 0, 65, 34, 20, 8, 0, 0,
	0, 2, 1, 81, 9, 6, 0, 0,
	0, 28, 34, 89, 89, 82, 12, 0,
	0, 0, 126, 9, 9, 126, 0, 0,
	0, 0, 127, 73, 73, 54, 0, 0,
	0, 0, 62, 65, 65, 34, 0, 0,
	0, 0, 127, 65, 65, 62, 0, 0,
	0, 0, 127, 73, 73, 65, 0, 0,
	0, 0, 127, 9, 9, 1, 0, 0,
	0, 0, 62, 65, 81, 50, 0, 0,
	0, 0, 127, 8, 8, 127, 0, 0,
	0, 0, 65, 127, 65, 0, 0, 0,
	0, 0, 32, 64, 64, 63, 0, 0,
	0, 0, 127, 8, 20, 99, 0, 0,
	0, 0, 127, 64, 64, 64, 0, 0,
	0, 127, 2, 4, 2, 127, 0, 0,
	0, 127, 6, 8, 48, 127, 0, 0,
	0, 0, 62, 65, 65, 62, 0, 0,
	0, 0, 127, 9, 9, 6, 0, 0,
	0, 0, 62, 65, 97, 126, 64, 0,
	0, 0, 127, 9, 9, 118, 0, 0,
	0, 0, 38, 73, 73, 50, 0, 0,
	0, 1, 1, 127, 1, 1, 0, 0,
	0, 0, 63, 64, 64, 63, 0, 0,
	0, 31, 32, 64, 32, 31, 0, 0,
	0, 63, 64, 48, 64, 63, 0, 0,
	0, 0, 119, 8, 8, 119, 0, 0,
	0, 3, 4, 120, 4, 3, 0, 0,
	0, 0, 113, 73, 73, 71, 0, 0,
	0, 0, 127, 65, 65, 0, 0, 0,
	0, 2, 4, 8, 16, 32, 64, 0,
	0, 0, 0, 65, 65, 127, 0, 0,
	0, 4, 2, 1, 2, 4, 0, 0,
	0, 64, 64, 64, 64, 64, 64, 0,
	0, 0, 1, 2, 4, 0, 0, 0,
	0, 0, 48, 72, 40, 120, 0, 0,
	0, 0, 127, 72, 72, 48, 0, 0,
	0, 0, 48, 72, 72, 0, 0, 0,
	0, 0, 48, 72, 72, 127, 0, 0,
	0, 0, 48, 88, 88, 16, 0, 0,
	0, 0, 126, 9, 1, 2, 0, 0,
	0, 0, 80, 152, 152, 112, 0, 0,
	0, 0, 127, 8, 8, 112, 0, 0,
	0, 0, 0, 122, 0, 0, 0, 0,
	0, 0, 64, 128, 128, 122, 0, 0,
	0, 0, 127, 16, 40, 72, 0, 0,
	0, 0, 0, 127, 0, 0, 0, 0,
	0, 120, 8, 16, 8, 112, 0, 0,
	0, 0, 120, 8, 8, 112, 0, 0,
	0, 0, 48, 72, 72, 48, 0, 0,
	0, 0, 248, 40, 40, 16, 0, 0,
	0, 0, 16, 40, 40, 248, 0, 0,
	0, 0, 112, 8, 8, 16, 0, 0,
	0, 0, 72, 84, 84, 36, 0, 0,
	0, 0, 8, 60, 72, 32, 0, 0,
	0, 0, 56, 64, 32, 120, 0, 0,
	0, 0, 56, 64, 56, 0, 0, 0,
	0, 56, 64, 32, 64, 56, 0, 0,
	0, 0, 72, 48, 48, 72, 0, 0,
	0, 0, 24, 160, 160, 120, 0, 0,
	0, 0, 100, 84, 84, 76, 0, 0,
	0, 0, 8, 28, 34, 65, 0, 0,
	0, 0, 0, 126, 0, 0, 0, 0,
	0, 0, 65, 34, 28, 8, 0, 0,
	0, 0, 4, 2, 4, 2, 0, 0,
	0, 120, 68, 66, 68, 120, 0, 0,
};

const uint8_t const icon[] = {
	0, 0, 15, 15, 0xf0, 0xf0, 0, 0,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 15, 211, 109, 58, 253, 8,
	178, 77, 58, 199, 122, 197, 242, 173,
	242, 237, 186, 215, 40, 215, 41, 214,
	35, 175, 91, 212, 63, 234, 149, 111,
	171, 84, 253, 252, 254, 253, 126, 184,
	195, 52, 201, 22, 225, 27, 196, 19,
	165, 74, 36, 146, 72, 162, 85, 8,
	226, 25, 166, 80, 167, 216, 167, 88,
	106, 149, 161, 95, 135, 91, 175, 87,
	142, 123, 134, 127, 134, 121, 134, 121,
	132, 59, 192, 27, 164, 74, 177, 70,
	184, 69, 186, 69, 254, 80, 175, 217,
};


