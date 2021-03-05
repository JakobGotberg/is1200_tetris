

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
if(shape == 'T'){
	display_shape_T();
} else if(shape == 'L'){
	display_shape_L();
	} else if(shape == 'J'){
		display_shape_J();
	} else if(shape == 'Z'){
		display_shape_Z();
	} else if(shape == 'S'){
		display_shape_S();
	} else if(shape == 'I'){
		display_shape_I();
	} else if(shape == 'O'){
		display_shape_O();
	}
}

void delete_shape()
{
	if(shape == 'T'){
		delete_shape_T();	
	} else if(shape == 'L'){
		delete_shape_L();
	} else if(shape == 'J'){
		delete_shape_J();
	} else if(shape == 'O'){
		delete_shape_O();
	} else if(shape == 'Z'){
		delete_shape_Z();
	} else if(shape == 'S'){
		delete_shape_S();
	} else if(shape == 'I'){
		delete_shape_I();
	}
}

//Collision check per shape
void collision_check_per_shape(char direction){
if(shape == 'T'){
	switch(direction){
		case 'v':
		collision_check_down_shape_T();
		break;
		case '<':
		collision_check_left_shape_T();
		break;
		case '>':
		collision_check_right_shape_T();		
	}
} else if(shape == 'L'){
	switch(direction){
		case 'v':
		collision_check_down_shape_L();
		break;
		case '<':
		collision_check_left_shape_L();
		break;
		case '>':
		collision_check_right_shape_L();		
		} 
	} else if(shape == 'J'){
		switch(direction){
		case 'v':
		collision_check_down_shape_J();
		break;
		case '<':
		collision_check_left_shape_J();
		break;
		case '>':
		collision_check_right_shape_J();		
	} 
	} else if(shape == 'Z'){
		switch(direction){
		case 'v':
		collision_check_down_shape_Z();
		break;
		case '<':
		collision_check_left_shape_Z();
		break;
		case '>':
		collision_check_right_shape_Z();		
	} 
	} else if(shape == 'S'){
		switch(direction){
		case 'v':
		collision_check_down_shape_S();
		break;
		case '<':
		collision_check_left_shape_S();
		break;
		case '>':
		collision_check_right_shape_S();		
	} 
	} else if(shape == 'I'){
		switch(direction){
		case 'v':
		collision_check_down_shape_I();
		break;
		case '<':
		collision_check_left_shape_I();
		break;
		case '>':
		collision_check_right_shape_I();		
	} 
	}
}

char rng()
{

return 'z';

}
/*
void row_check_old()
{



	int i, j;
	j = row+3;
	/*
	if(row <= 17)
		j = row+3;

	if(row == 18)
		j = row+2;

	if(row == 19)
		j = row+1;

	if(row == 20)
		j == row;
		*/

	for(i = 0; i < 1; i++){
		if((collision_check(row+1, 1) + 
			collision_check(row+1, 2) + 
			collision_check(row+1, 3) +
			collision_check(row+1, 4) + 
			collision_check(row+1, 5) + 
			collision_check(row+1, 6) +
			collision_check(row+1, 7) + 
			collision_check(row+1, 8) + 
			collision_check(row+1, 9) + 
			collision_check(row+1, 10)) == 10)
			{ row_clear(row); }
	}

	
}
*/
	
	void row_check()
{
	int row = object.r1;
	int clear = 0;
	for(int i = row; i < row + 4; i++){
		for(int p = 1; p < 11; p++){
			clear += collision_check(i, p);
		}
		if(clear == 10){
			row_clear(i);
			score++;
		}
		clear = 0;
	}	
}

/*
void row_clear_old(uint8_t _row)
{

logic_to_pixel_set(9,1);
	score++;
	int i, j;
	for(i = 1; i < 11; i++){
		logic_to_pixel_clr(_row, i);
	}

	// checks if rows above have blocks that needs to be moved down and moves them.
	for(j = _row-1; j != 1; j--){
		for(i = 1; i < 11; i++){
			if(collision_check(j,i)){
				logic_to_pixel_clr(j,i);
				logic_to_pixel_set(j+1,i);
			}
	}

}
}
*/
void row_clear(uint8_t _row)
{
	for(int i = 1; i < 11; i++){
		logic_to_pixel_clr(_row, i);
	}
	
	move_rows_down(_row);
}

void move_rows_down(int clearedRow){
	for(int i = clearedRow; i > 0; i--){
		for(int p = 1; p < 11; p++){
			int moveDown = collision_check(i-1, p);
			if(moveDown == 1){
				logic_to_pixel_clr(i-1, p);
				logic_to_pixel_set(i, p);
			}	
		}
	}
}

// goes left, once per btn-press, as long as there is no collision
void go_left(uint8_t row, uint8_t block, char shape)
{
	if(block != 1 && (collision_check(row, block+1) == 0)){
		delete_shape();
		display_shape();
	}
}
// goes rigth, once per btn-press, as long as there is no collision
void go_right(uint8_t row, uint8_t block, char shape)
{
	if(block != 10 && (collision_check(row, block-1) == 0))
delete_shape();
display_shape();
}

// checks collision with other blocks
uint8_t collision_check(uint8_t row, uint8_t block)
{
	int collision_row = row - 1;
	int collision_block = 10 - block;

	return collision_array[collision_row][collision_block];
}

//&& /*(downCollision == 0)*/
void fall_down()
{
	collision_check_per_shape(shape);
	if(row != 19 && (downCollision == 0)){
		delete_shape();
		row++;
		display_shape();
	}
}

