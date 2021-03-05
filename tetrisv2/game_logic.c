

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "header_file.h"  /* Declatations for these labs */

// game logic



void logic_to_pixel_set( uint8_t row, uint8_t block )
{
	uint8_t pixel_row = row + 66 + ((row -1 ) * 2);
	uint8_t pixel_block = block * 3 -2;
	uint8_t collision_row = row-1;
	uint8_t collision_block = 10 - block;

	pixel_set(pixel_row, pixel_block);
	pixel_set(pixel_row, pixel_block + 1);
	pixel_set(pixel_row, pixel_block + 2);

	pixel_set(pixel_row + 1, pixel_block);
	pixel_set(pixel_row + 1, pixel_block + 1);
	pixel_set(pixel_row + 1, pixel_block + 2);

	pixel_set(pixel_row + 2, pixel_block);
	pixel_set(pixel_row + 2, pixel_block + 1);
	pixel_set(pixel_row + 2, pixel_block + 2);

	collision_array[collision_row][collision_block] = 1;

}

void logic_to_pixel_clr( uint8_t row, uint8_t block )
{
	uint8_t pixel_row = row + 66 + ((row -1 ) * 2);
	uint8_t pixel_block = block * 3 -2;
	uint8_t collision_row = row-1;
	uint8_t collision_block = 10 - block;

	pixel_clr(pixel_row, pixel_block);
	pixel_clr(pixel_row, pixel_block + 1);
	pixel_clr(pixel_row, pixel_block + 2);

	pixel_clr(pixel_row + 1, pixel_block);
	pixel_clr(pixel_row + 1, pixel_block + 1);
	pixel_clr(pixel_row + 1, pixel_block + 2);

	pixel_clr(pixel_row + 2, pixel_block);
	pixel_clr(pixel_row + 2, pixel_block + 1);
	pixel_clr(pixel_row + 2, pixel_block + 2);

	collision_array[collision_row][collision_block] = 0;

}


void display_shape()
{
	logic_to_pixel_set(obj.r1, obj.b1);
	logic_to_pixel_set(obj.r2, obj.b2);
	logic_to_pixel_set(obj.r3, obj.b3);
	logic_to_pixel_set(obj.r4, obj.b4);
}

void delete_shape()
{
	logic_to_pixel_clr(obj.r1, obj.b1);
	logic_to_pixel_clr(obj.r2, obj.b2);
	logic_to_pixel_clr(obj.r3, obj.b3);
	logic_to_pixel_clr(obj.r4, obj.b4);
}

void btn_check()
{
	if(getbtns() & 1)
		go_left_flag = 1;

	if(getbtns() & 2)
		go_right_flag = 1;

	//rotate_flag = (getbtns & 4);

}

// checks collision with other blocks
uint8_t collision_check(uint8_t row, uint8_t block)
{
	int collision_row = row - 1;
	int collision_block = 10 - block;

	return collision_array[collision_row][collision_block];
}

uint8_t collision_check_left()
{	
	switch(obj.shape_index)
	{
		case 1:	// shape O
		if( collision_check(obj.r1,obj.b1+1) || collision_check(obj.r3,obj.b3+1))
			return 1;
		break;

		case 2: // shape L0
		if( collision_check(obj.r1,obj.b1+1) || collision_check(obj.r2,obj.b2+1)
			 || collision_check(obj.r4,obj.b4+1))
			return 1;
		break;

		case 3: // L1
		if(0)
			return 1;
		break;

		case 4: // L2
		if(0)
			return 1;
		break;

		case 5: //L3
		if(0)
			return 1;
		break;

		case 6: // I0
		if(0)
			return 1;
		break;

		case 7: // I1
		if(0)
			return 1;
		break;

		case 8: // J0
		if(0)
			return 1;
		break;

		case 9: // J1
		if(0)
			return 1;
		break;

		case 10: // J2
		if(0)
			return 1;
		break;

		case 11: // J3
		if(0)
			return 1;
		break;

		case 12: // T0
		if(0)
			return 1;
		break;

		case 13: // T1
		if(0)
			return 1;
		break;

		case 14: // T2
		if(0)
			return 1;
		break;

		case 15: // T3
		if(0)
			return 1;
		break;

		case 16: // Z0
		if(0)
			return 1;
		break;

		case 17: // Z1
		if(0)
			return 1;
		break;

		case 18: // S0
		if(0)
			return 1;
		break;

		case 19: //S1
		if(0)
			return 1;
		break;

	}
return 0;

}

uint8_t collision_check_right()
{
	switch(obj.shape_index)
	{
		case 1: // shape O
		if(collision_check(obj.r2,obj.b2-1) || collision_check(obj.r4,obj.b4-1))
			{return 1;}
		break;

		case 2: // shape L0
		if(collision_check(obj.r1,obj.b1-1) || collision_check(obj.r2,obj.b2-1) || 
			collision_check(obj.r3, obj.b3-1))
			return 1;
		break;

		case 3: // L1
		if(0)
			return 1;
		break;

		case 4: // L2
		if(0)
			return 1;
		break;

		case 5: //L3
		if(0)
			return 1;
		break;

		case 6: // I0
		if(0)
			return 1;
		break;

		case 7: // I1
		if(0)
			return 1;
		break;

		case 8: // J0
		if(0)
			return 1;
		break;

		case 9: // J1
		if(0)
			return 1;
		break;

		case 10: // J2
		if(0)
			return 1;
		break;

		case 11: // J3
		if(0)
			return 1;
		break;

		case 12: // T0
		if(0)
			return 1;
		break;

		case 13: // T1
		if(0)
			return 1;
		break;

		case 14: // T2
		if(0)
			return 1;
		break;

		case 15: // T3
		if(0)
			return 1;
		break;

		case 16: // Z0
		if(0)
			return 1;
		break;

		case 17: // Z1
		if(0)
			return 1;
		break;

		case 18: // S0
		if(0)
			return 1;
		break;

		case 19: //S1
		if(0)
			return 1;
		break;
	}
	return 0;
}

uint8_t collision_check_down()
{
	switch(obj.shape_index)
	{
		case 1: // shape O
		if(collision_check(obj.r3+1,obj.b3) || collision_check(obj.r4+1,obj.b4))
			{return 1;}
		break;

		case 2: // shape L0
		if(collision_check(obj.r3+1,obj.b3) || collision_check(obj.r4+1,obj.b4))
			return 1;
		break;

		case 3: // L1
		if(0)
			return 1;
		break;

		case 4: // L2
		if(0)
			return 1;
		break;

		case 5: //L3
		if(0)
			return 1;
		break;

		case 6: // I0
		if(0)
			return 1;
		break;

		case 7: // I1
		if(0)
			return 1;
		break;

		case 8: // J0
		if(0)
			return 1;
		break;

		case 9: // J1
		if(0)
			return 1;
		break;

		case 10: // J2
		if(0)
			return 1;
		break;

		case 11: // J3
		if(0)
			return 1;
		break;

		case 12: // T0
		if(0)
			return 1;
		break;

		case 13: // T1
		if(0)
			return 1;
		break;

		case 14: // T2
		if(0)
			return 1;
		break;

		case 15: // T3
		if(0)
			return 1;
		break;

		case 16: // Z0
		if(0)
			return 1;
		break;

		case 17: // Z1
		if(0)
			return 1;
		break;

		case 18: // S0
		if(0)
			return 1;
		break;

		case 19: //S1
		if(0)
			return 1;
		break;
	}
	return 0;
}



// goes left, once per btn-press, as long as there is no collision
void go_left()
{
	

	if((obj.left_cube != 10) && !( collision_check_left() )) {
		delete_shape();
		obj.b1++;
		obj.b2++;
		obj.b3++;
		obj.b4++;
		obj.left_cube++;
		obj.right_cube++;
		display_shape();
	}
	leftCollision = 0;
}


// goes rigth, once per btn-press, as long as there is no collision
void go_right()
{
	//rightCollision = collision_check_right();
	if(obj.right_cube != 1 && !( collision_check_right() )) {
		delete_shape();
		obj.b1--;
		obj.b2--;
		obj.b3--;
		obj.b4--;
		obj.right_cube--;
		obj.left_cube--;
		display_shape();
	}
	rightCollision = 0;
}


//falls down, faster and faster. only falls if the 
void fall_down()
{
	
	downCollision = collision_check_down();
	if(obj.bottom_cube != 20 && (downCollision == 0)){
		delete_shape();
		obj.r1++;
		obj.r2++;
		obj.r3++;
		obj.r4++;
		obj.bottom_cube++;
		display_shape();
		
	}
	else{
		row_check();
		new_shape_flag = 1;
	}

}

shape shape_handler(uint8_t s)
{
	switch(s)
	{
		case 1:
			return O;
			break;

		case 2:
			return L1;
			break;

		case 3:
			return I1;
			break;

		case 4:
			return J3;
			break;

		case 5:
			return T0;
			break;

		case 6:
			return Z0;
			break;

		case 7:
			return S0;
			break;
	}
}

	
	void row_check()
{
	uint8_t row = obj.r1;
	int clear = 0;
	int i;
	int p;
	for(i = row; i < row + 4; i++){
		for(p = 1; p < 11; p++){
			clear += collision_check(i, p);
		}
		if(clear == 10){
			row_clear(i);
			score++;
		}
		clear = 0;
	}	
}

void row_clear(uint8_t _row)
{
	int i;
	for(i = 1; i < 11; i++){
		logic_to_pixel_clr(_row, i);
	}
	
	move_rows_down(_row);
}

void move_rows_down(uint8_t clearedRow){
	int i;
	int p;
	for(i = clearedRow; i > 0; i--){
		for(p = 1; p < 11; p++){
			int moveDown = collision_check(i-1, p);
			if(moveDown == 1){
				logic_to_pixel_clr(i-1, p);
				logic_to_pixel_set(i, p);
			}	
		}
	}
}


