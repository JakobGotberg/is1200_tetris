

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

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

	collision_array[collision_row][collision_block] = 1;

}

//Display shape look-up function
void display_shape()
{
if(shape == 'T'){
	display_shape_T(row, block);
} else if(shape == 'L'){
	display_shape_L(row, block);
	} else if(shape == 'J'){
		display_shape_J(row,block);
	} else if(shape == 'Z'){
		display_shape_Z(row, block);
	} else if(shape == 'S'){
		display_shape_S(row, block);
	} else if(shape == 'I'){
		display_shape_I(row,block);
	} else if(shape == 'O'){
		display_shape_O(row,block);
	}
}

//Display shape, shape-specific functions
void display_shape_T(){
	switch(rotationPosition){
		case 0:
		logic_to_pixel_set(row,block - 1 );
		logic_to_pixel_set(row + 1, block);
		logic_to_pixel_set(row + 1, block - 1);
		logic_to_pixel_set(row + 1, block - 2);
		break;
		case 1:
		logic_to_pixel_set(row,block );
		logic_to_pixel_set(row + 1, block);
		logic_to_pixel_set(row + 1, block - 1);
		logic_to_pixel_set(row + 2, block);
		break;
		case 2:
		logic_to_pixel_set(row,block );
		logic_to_pixel_set(row, block-1);
		logic_to_pixel_set(row, block - 2);
		logic_to_pixel_set(row + 1, block-1);
		break;
		case 3:
		logic_to_pixel_set(row, block-1 );
		logic_to_pixel_set(row+1, block-1);
		logic_to_pixel_set(row+2, block - 1);
		logic_to_pixel_set(row + 1, block);
		break;
	}
}
void display_shape_L(){
	switch(rotationPosition){
		case 0:
		logic_to_pixel_set(row,block -2);
		logic_to_pixel_set(row +1, block);
		logic_to_pixel_set(row+1, block-1);
		logic_to_pixel_set(row+1, block-2);
		break;
		case 1:
		logic_to_pixel_set(row,block);
		logic_to_pixel_set(row +1, block);
		logic_to_pixel_set(row+2, block);
		logic_to_pixel_set(row+2, block-1);
		break;
		case 2:
		logic_to_pixel_set(row,block);
		logic_to_pixel_set(row, block-1);
		logic_to_pixel_set(row, block-2);
		logic_to_pixel_set(row+1, block);
		break;
		case 3:
		logic_to_pixel_set(row,block);
		logic_to_pixel_set(row, block-1);
		logic_to_pixel_set(row+1, block-1);
		logic_to_pixel_set(row+2, block-1);
		break;
	}
}
void display_shape_J(){
	switch(rotationPosition){
		case 0:
		logic_to_pixel_set(row,block);
		logic_to_pixel_set(row+1, block);
		logic_to_pixel_set(row+1, block-1);
		logic_to_pixel_set(row+1, block-2);
		break;
		case 1:
		logic_to_pixel_set(row,block);
		logic_to_pixel_set(row+1, block);
		logic_to_pixel_set(row+2, block);
		logic_to_pixel_set(row, block-1);
		break;
		case 2:
		logic_to_pixel_set(row,block);
		logic_to_pixel_set(row, block-1);
		logic_to_pixel_set(row, block-2);
		logic_to_pixel_set(row+1, block-2);
		break;
		case 3:
		logic_to_pixel_set(row,block-1);
		logic_to_pixel_set(row+1, block-1);
		logic_to_pixel_set(row+2, block);
		logic_to_pixel_set(row+2, block-1);
		break;
	}
}
void display_shape_Z(){
	switch(rotationPosition){
		case 0:
		logic_to_pixel_set(row,block);
		logic_to_pixel_set(row, block-1);
		logic_to_pixel_set(row+1, block-1);
		logic_to_pixel_set(row+1, block-2);
		break;
		case 1:
		logic_to_pixel_set(row,block-1);
		logic_to_pixel_set(row+1, block);
		logic_to_pixel_set(row+1, block-1);
		logic_to_pixel_set(row+2, block);
		break;
		case 2:
		logic_to_pixel_set(row,block);
		logic_to_pixel_set(row, block-1);
		logic_to_pixel_set(row+1, block-1);
		logic_to_pixel_set(row+1, block-2);
		break;
		case 3:
		logic_to_pixel_set(row,block-1);
		logic_to_pixel_set(row+1, block);
		logic_to_pixel_set(row+1, block-1);
		logic_to_pixel_set(row+2, block);		
		break;
	}
}
void display_shape_S(){
	switch(rotationPosition){
		case 0:
		logic_to_pixel_set(row,block-1);
		logic_to_pixel_set(row, block-2);
		logic_to_pixel_set(row+1, block);
		logic_to_pixel_set(row+1, block-1);
		break;
		case 1:
		logic_to_pixel_set(row,block);
		logic_to_pixel_set(row+1, block);
		logic_to_pixel_set(row+1, block-1);
		logic_to_pixel_set(row+2, block-1);		
		break;
		case 2:
		logic_to_pixel_set(row,block-1);
		logic_to_pixel_set(row, block-2);
		logic_to_pixel_set(row+1, block);
		logic_to_pixel_set(row+1, block-1);
		break;
		case 3:
		logic_to_pixel_set(row,block);
		logic_to_pixel_set(row+1, block);
		logic_to_pixel_set(row+1, block-1);
		logic_to_pixel_set(row+2, block-1);					
		break;
	}
}
void display_shape_I(){
	switch(rotationPosition){
		case 0:
		logic_to_pixel_set(row,block);
		logic_to_pixel_set(row+1,block);
		logic_to_pixel_set(row+2,block);
		logic_to_pixel_set(row+3,block);
		break;
		case 1:
		logic_to_pixel_set(row,block);
		logic_to_pixel_set(row,block-1);
		logic_to_pixel_set(row,block-2);
		logic_to_pixel_set(row,block-3);	
		break;
		case 2:
		logic_to_pixel_set(row,block);
		logic_to_pixel_set(row+1,block);
		logic_to_pixel_set(row+2,block);
		logic_to_pixel_set(row+3,block);	
		break;
		case 3:
		logic_to_pixel_set(row,block);
		logic_to_pixel_set(row,block-1);
		logic_to_pixel_set(row,block-2);
		logic_to_pixel_set(row,block-3);						
		break;
	}
}
void display_shape_O(){
		logic_to_pixel_set(row,block);
		logic_to_pixel_set(row, block-1);
		logic_to_pixel_set(row + 1, block);
		logic_to_pixel_set(row + 1, block-1);
}

void delete_shape()
{
	if(shape == 'T'){
		delete_shape_T(row, block);	
	} else if(shape == 'L'){
		delete_shape_L(row, block);
	} else if(shape == 'J'){
		delete_shape_J(row, block);
	} else if(shape == 'O'){
		delete_shape_O(row, block);
	} else if(shape == 'Z'){
		delete_shape_Z(row,block);
	} else if(shape == 'S'){
		delete_shape_S(row,block);
	} else if(shape == 'I'){
		delete_shape_I(row,block);
	}
}

//Delete shape, shape-specific functions
void delete_shape_O(){
		logic_to_pixel_clr(row,block);
		logic_to_pixel_clr(row, block-1);
		logic_to_pixel_clr(row + 1, block);
		logic_to_pixel_clr(row + 1, block-1);
}
void delete_shape_T(){
	switch(rotationPosition){
		case 0:
		logic_to_pixel_clr(row,block - 1 );
		logic_to_pixel_clr(row + 1, block);
		logic_to_pixel_clr(row + 1, block - 1);
		logic_to_pixel_clr(row + 1, block - 2);
		break;
		case 1:
		logic_to_pixel_clr(row,block );
		logic_to_pixel_clr(row + 1, block);
		logic_to_pixel_clr(row + 1, block - 1);
		logic_to_pixel_clr(row + 2, block);
		break;
		case 2:
		logic_to_pixel_clr(row,block );
		logic_to_pixel_clr(row, block-1);
		logic_to_pixel_clr(row, block - 2);
		logic_to_pixel_clr(row + 1, block-1);
		break;
		case 3:
		logic_to_pixel_clr(row, block-1 );
		logic_to_pixel_clr(row+1, block-1);
		logic_to_pixel_clr(row+2, block - 1);
		logic_to_pixel_clr(row + 1, block);
		break;
	}
}
void delete_shape_L(){
	switch(rotationPosition){
		case 0:
		logic_to_pixel_clr(row,block -2);
		logic_to_pixel_clr(row +1, block);
		logic_to_pixel_clr(row+1, block-1);
		logic_to_pixel_clr(row+1, block-2);
		break;
		case 1:
		logic_to_pixel_clr(row,block);
		logic_to_pixel_clr(row +1, block);
		logic_to_pixel_clr(row+2, block);
		logic_to_pixel_clr(row+2, block-1);
		break;
		case 2:
		logic_to_pixel_clr(row,block);
		logic_to_pixel_clr(row, block-1);
		logic_to_pixel_clr(row, block-2);
		logic_to_pixel_clr(row+1, block);
		break;
		case 3:
		logic_to_pixel_clr(row,block);
		logic_to_pixel_clr(row, block-1);
		logic_to_pixel_clr(row+1, block-1);
		logic_to_pixel_clr(row+2, block-1);
		break;
	}
}
void delete_shape_J(){
	switch(rotationPosition){
		case 0:
		logic_to_pixel_clr(row,block);
		logic_to_pixel_clr(row+1, block);
		logic_to_pixel_clr(row+1, block-1);
		logic_to_pixel_clr(row+1, block-2);
		break;
		case 1:
		logic_to_pixel_clr(row,block);
		logic_to_pixel_clr(row+1, block);
		logic_to_pixel_clr(row+2, block);
		logic_to_pixel_clr(row, block-1);
		break;
		case 2:
		logic_to_pixel_clr(row,block);
		logic_to_pixel_clr(row, block-1);
		logic_to_pixel_clr(row, block-2);
		logic_to_pixel_clr(row+1, block-2);
		break;
		case 3:
		logic_to_pixel_clr(row,block-1);
		logic_to_pixel_clr(row+1, block-1);
		logic_to_pixel_clr(row+2, block);
		logic_to_pixel_clr(row+2, block-1);
		break;
	}
}
void delete_shape_Z(){
	switch(rotationPosition){
		case 0:
		logic_to_pixel_clr(row,block);
		logic_to_pixel_clr(row, block-1);
		logic_to_pixel_clr(row+1, block-1);
		logic_to_pixel_clr(row+1, block-2);
		break;
		case 1:
		logic_to_pixel_clr(row,block-1);
		logic_to_pixel_clr(row+1, block);
		logic_to_pixel_clr(row+1, block-1);
		logic_to_pixel_clr(row+2, block);
		break;
		case 2:
		logic_to_pixel_clr(row,block);
		logic_to_pixel_clr(row, block-1);
		logic_to_pixel_clr(row+1, block-1);
		logic_to_pixel_clr(row+1, block-2);
		break;
		case 3:
		logic_to_pixel_clr(row,block-1);
		logic_to_pixel_clr(row+1, block);
		logic_to_pixel_clr(row+1, block-1);
		logic_to_pixel_clr(row+2, block);		
		break;
	}
}
void delete_shape_S(){
	switch(rotationPosition){
		case 0:
		logic_to_pixel_clr(row,block-1);
		logic_to_pixel_clr(row, block-2);
		logic_to_pixel_clr(row+1, block);
		logic_to_pixel_clr(row+1, block-1);
		break;
		case 1:
		logic_to_pixel_clr(row,block);
		logic_to_pixel_clr(row+1, block);
		logic_to_pixel_clr(row+1, block-1);
		logic_to_pixel_clr(row+2, block-1);		
		break;
		case 2:
		logic_to_pixel_clr(row,block-1);
		logic_to_pixel_clr(row, block-2);
		logic_to_pixel_clr(row+1, block);
		logic_to_pixel_clr(row+1, block-1);
		break;
		case 3:
		logic_to_pixel_clr(row,block);
		logic_to_pixel_clr(row+1, block);
		logic_to_pixel_clr(row+1, block-1);
		logic_to_pixel_clr(row+2, block-1);					
		break;
	}
}
void delete_shape_I(){
	switch(rotationPosition){
		case 0:
		logic_to_pixel_clr(row,block);
		logic_to_pixel_clr(row+1,block);
		logic_to_pixel_clr(row+2,block);
		logic_to_pixel_clr(row+3,block);
		break;
		case 1:
		logic_to_pixel_clr(row,block);
		logic_to_pixel_clr(row,block-1);
		logic_to_pixel_clr(row,block-2);
		logic_to_pixel_clr(row,block-3);	
		break;
		case 2:
		logic_to_pixel_clr(row,block);
		logic_to_pixel_clr(row+1,block);
		logic_to_pixel_clr(row+2,block);
		logic_to_pixel_clr(row+3,block);	
		break;
		case 3:
		logic_to_pixel_clr(row,block);
		logic_to_pixel_clr(row,block-1);
		logic_to_pixel_clr(row,block-2);
		logic_to_pixel_clr(row,block-3);						
		break;
	}
}




char rng()
{

return 'z';

}

// falls down, once per "tick", as long as there is no collision
void fall_down(uint8_t row, uint8_t block, char shape)
{
	collision_check_per_shape('V');
	if(row != 19 && (downCollision == 0)){
		delete_shape();
		row++;
		display_shape();
		
	}
}

// goes left, once per btn-press, as long as there is no collision
void go_left(uint8_t row, uint8_t block, char shape)
{
	if(block != 1 && (collision_check(row, block+1) == 0)){
		delete_shape(row, block, shape);
		display_shape(row, block+1, shape);
	}
}
// goes rigth, once per btn-press, as long as there is no collision
void go_right(uint8_t row, uint8_t block, char shape)
{
	if(block != 10 && (collision_check(row, block-1) == 0))
delete_shape(row, block, shape);
display_shape(row, block-1, shape);
}

// checks collision with other blocks
uint8_t collision_check(uint8_t row, uint8_t block)
{
	int collision_row = row - 1;
	int collision_block = 10 - block;

	return collision_array[collision_row][collision_block];
}



//Collision check per shape
void collision_check_per_shape(char direction){
	if(shape == 'T'){
		switch(direction){
			case 'V':
			collision_check_down_shape_T();
			break;
			case '<':
			collision_check_left_shape_T();
			break;
			case '>':
			collision_check_right_shape_T();
			break;		
			}	
	} else if(shape == 'L'){
		switch(direction){
			case 'V':
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
			case 'V':
			collision_check_down_shape_J();
			break;
			case '<':
			collision_check_left_shape_J();
			break;
			case '>':
			collision_check_right_shape_J();		
			} 
	} else if(shape == 'O'){
		switch(direction){
			case 'V':
			collision_check_down_shape_O();
			break;
			case '<':
			collision_check_left_shape_O();
			break;
			case '>':
			collision_check_right_shape_O();		
			} 
	} else if(shape == 'Z'){
		switch(direction){
			case 'V':
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
			case 'V':
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
			case 'V':
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

//Collision check shape T
void collision_check_down_shape_T(){

	switch(rotationPosition){
		case 0:

		downCollision += collision_check(row+2, block);
		downCollision += collision_check(row+2, block-1);
		downCollision += collision_check(row+2, block-2);
		break;
		case 1:
		downCollision  += collision_check(row+3, block);
		downCollision  += collision_check(row+2, block-1);
		break;
		case 2:
		downCollision  = collision_check(row+1, block);
		downCollision  = collision_check(row+2, block-1);
		downCollision  = collision_check(row+1, block-2);
		break;
		case 3:
		downCollision  = collision_check(row+2, block);
		downCollision = collision_check(row+3, block-1);
		break;
	}
}
void collision_check_left_shape_T(){
	switch(rotationPosition){
		case 0:
		leftCollision  = collision_check(row, block);
		leftCollision = collision_check(row+1, block+1);
		break;
		case 1:
		leftCollision  = collision_check(row, block+1);
		leftCollision  = collision_check(row+1, block+1);
		leftCollision  = collision_check(row+2, block+1);
		break;
		case 2:
		leftCollision  = collision_check(row, block+1);
		leftCollision  = collision_check(row+1, block);
		break;
		case 3:
		leftCollision  = collision_check(row, block);
		leftCollision  = collision_check(row+1, block+1);
		leftCollision  = collision_check(row+2, block+1);
		break;
	}
}
void collision_check_right_shape_T(){
	switch(rotationPosition){
		case 0:
		rightCollision  = collision_check(row, block-2);
		rightCollision = collision_check(row+1, block-3);
		break;
		case 1:
		rightCollision  = collision_check(row, block-1);
		rightCollision  = collision_check(row+1, block-2);
		rightCollision  = collision_check(row+2, block-1);
		break;
		case 2:
		rightCollision  = collision_check(row, block-3);
		rightCollision  = collision_check(row+1, block-2);
		break;
		case 3:
		rightCollision  = collision_check(row, block-2);
		rightCollision  = collision_check(row+1, block-2);
		rightCollision  = collision_check(row+2, block-2);
		break;
	}
}

//Collision check shape L
void collision_check_down_shape_L(){
	switch(rotationPosition){
		case 0:
		downCollision  = collision_check(row+2, block);
		downCollision  = collision_check(row+2, block-1);
		downCollision  = collision_check(row+2, block-2);
		break;
		case 1:
		downCollision  = collision_check(row+3, block);
		downCollision  = collision_check(row+3, block-1);
		break;
		case 2:
		downCollision  = collision_check(row+1, block);
		downCollision  = collision_check(row+1, block-1);
		downCollision  = collision_check(row+2, block-2);
		break;
		case 3:
		downCollision  = collision_check(row+3, block);
		downCollision  = collision_check(row+3, block-1);
		break;
	}
}
void collision_check_left_shape_L(){
	switch(rotationPosition){
		case 0:
		leftCollision  = collision_check(row, block-1);
		leftCollision  = collision_check(row+1, block+1);
		break;
		case 1:
		leftCollision  = collision_check(row, block+1);
		leftCollision  = collision_check(row+1, block+1);
		leftCollision  = collision_check(row+2, block+1);
		break;
		case 2:
		leftCollision  = collision_check(row, block+1);
		leftCollision  = collision_check(row+1, block+1);
		break;
		case 3:
		leftCollision  = collision_check(row, block+1);
		leftCollision  = collision_check(row+1, block);
		leftCollision  = collision_check(row+2, block);
		break;
	}
}
void collision_check_right_shape_L(){
	switch(rotationPosition){
		case 0:
		rightCollision  = collision_check(row, block-3);
		rightCollision  = collision_check(row+1, block-3);
		break;
		case 1:
		rightCollision  = collision_check(row, block-1);
		rightCollision  = collision_check(row+1, block-1);
		rightCollision  = collision_check(row+2, block-2);
		break;
		case 2:
		rightCollision  = collision_check(row, block-3);
		rightCollision  = collision_check(row+1, block-1);
		break;
		case 3:
		rightCollision  = collision_check(row, block-2);
		rightCollision  = collision_check(row+1, block-2);
		rightCollision  = collision_check(row+2, block-2);
		break;
	}
}

//Collision check shape J
void collision_check_down_shape_J(){
	switch(rotationPosition){
		case 0:
		downCollision  += collision_check(row+2, block);
		downCollision  += collision_check(row+2, block-1);
		downCollision  += collision_check(row+2, block-2);
		break;
		case 1:
		downCollision += collision_check(row+3, block);
		downCollision  += collision_check(row+1, block-1);
		break;
		case 2:
		downCollision  += collision_check(row+1, block);
		downCollision  += collision_check(row+1, block-1);
		downCollision  += collision_check(row+2, block-2);
		break;
		case 3:
		downCollision += collision_check(row+3, block);
		downCollision += collision_check(row+3, block-1);
		break;
	}
}
void collision_check_left_shape_J(){
	switch(rotationPosition){
		case 0:
		leftCollision  += collision_check(row, block+1);
		leftCollision += collision_check(row+1, block+1);
		break;
		case 1:
		leftCollision  += collision_check(row, block+1);
		leftCollision  += collision_check(row, block+1);
		leftCollision  += collision_check(row+1, block+1);
		leftCollision  += collision_check(row+2, block+1);
		break;
		case 2:
		leftCollision  += collision_check(row, block+1);
		leftCollision += collision_check(row+1, block-1);
		break;
		case 3:
		leftCollision  += collision_check(row, block+1);
		leftCollision  += collision_check(row+1, block+1);
		leftCollision  += collision_check(row+2, block+2);
		break;
	}
}
void collision_check_right_shape_J(){
	switch(rotationPosition){
		case 0:
		rightCollision  += collision_check(row, block-1);
		rightCollision  += collision_check(row+1, block-3);
		break;
		case 1:
		rightCollision  += collision_check(row, block-2);
		rightCollision  += collision_check(row+1, block-1);
		rightCollision  += collision_check(row+2, block-1);
		break;
		case 2:
		rightCollision  += collision_check(row, block-3);
		rightCollision  += collision_check(row+1, block-3);
		break;
		case 3:
		rightCollision  += collision_check(row, block-2);
		rightCollision  += collision_check(row+1, block-2);
		rightCollision  += collision_check(row+2, block-2);
		break;
	}
}

//Collision check shape Z
void collision_check_down_shape_Z(){
	switch(rotationPosition){
		case 0:
		downCollision  += collision_check(row+1, block);
		downCollision  += collision_check(row+2, block-1);
		downCollision  += collision_check(row+2, block-2);
		break;
		case 1:
		downCollision += collision_check(row+3, block);
		downCollision  += collision_check(row+2, block-1);
		break;
		case 2:
		downCollision  += collision_check(row+1, block);
		downCollision  += collision_check(row+2, block-1);
		downCollision  += collision_check(row+2, block-2);
		break;
		case 3:
		downCollision += collision_check(row+3, block);
		downCollision  += collision_check(row+2, block-1);
		break;
	}
}
void collision_check_left_shape_Z(){
	switch(rotationPosition){
		case 0:
		leftCollision  += collision_check(row, block+1);
		leftCollision += collision_check(row+1, block);
		break;
		case 1:
		leftCollision  += collision_check(row, block);
		leftCollision  += collision_check(row+1, block+1);
		leftCollision  += collision_check(row+2, block+1);
		break;
		case 2:
		leftCollision  += collision_check(row, block+1);
		leftCollision += collision_check(row+1, block);
		break;
		case 3:
		leftCollision  += collision_check(row, block);
		leftCollision  += collision_check(row+1, block+1);
		leftCollision  += collision_check(row+2, block+1);
		break;
	}
}
void collision_check_right_shape_Z(){
	switch(rotationPosition){
		case 0:
		rightCollision  += collision_check(row, block-2);
		rightCollision  += collision_check(row+1, block-3);
		break;
		case 1:
		rightCollision  += collision_check(row, block-2);
		rightCollision  += collision_check(row+1, block-2);
		rightCollision  += collision_check(row+2, block-1);
		break;
		case 2:
		rightCollision  += collision_check(row, block-2);
		rightCollision  += collision_check(row+1, block-3);
		break;
		case 3:
		rightCollision  += collision_check(row, block-2);
		rightCollision  += collision_check(row+1, block-2);
		rightCollision  += collision_check(row+2, block-1);
		break;
	}
}

//Collision check shape S
void collision_check_down_shape_S(){
	switch(rotationPosition){
		case 0:
		downCollision  += collision_check(row+2, block);
		downCollision  += collision_check(row+2, block-1);
		downCollision  += collision_check(row+1, block-2);
		break;
		case 1:
		downCollision  += collision_check(row+2, block);
		downCollision  += collision_check(row+3, block-1);
		break;
		case 2:
		downCollision  += collision_check(row+2, block);
		downCollision  += collision_check(row+2, block-1);
		downCollision  += collision_check(row+1, block-2);
		break;
		case 3:
		downCollision += collision_check(row+2, block);
		downCollision  += collision_check(row+3, block-1);
		break;
	}
}
void collision_check_left_shape_S(){
	switch(rotationPosition){
		case 0:
		leftCollision += collision_check(row, block);
		leftCollision += collision_check(row+1, block+1);
		break;
		case 1:
		leftCollision += collision_check(row, block+1);
		leftCollision += collision_check(row+1, block+1);
		leftCollision += collision_check(row+2, block);
		break;
		case 2:
		leftCollision += collision_check(row, block);
		leftCollision += collision_check(row+1, block+1);
		break;
		case 3:
		leftCollision += collision_check(row, block+1);
		leftCollision += collision_check(row+1, block+1);
		leftCollision += collision_check(row+2, block);
		break;
	}
}
void collision_check_right_shape_S(){
	switch(rotationPosition){
		case 0:
		rightCollision  += collision_check(row, block-3);
		rightCollision  += collision_check(row+1, block-2);
		break;
		case 1:
		rightCollision  += collision_check(row, block-1);
		rightCollision  += collision_check(row+1, block-2);
		rightCollision  += collision_check(row+2, block-2);
		break;
		case 2:
		rightCollision  += collision_check(row, block-3);
		rightCollision  += collision_check(row+1, block-2);
		break;
		case 3:
		rightCollision  += collision_check(row, block-1);
		rightCollision  += collision_check(row+1, block-2);
		rightCollision  += collision_check(row+2, block-2);
		break;
	}
}

//Collision check shape I
void collision_check_down_shape_I(){
	switch(rotationPosition){
		case 0:
		downCollision  += collision_check(row+1, block);
		downCollision  += collision_check(row+1, block-1);
		downCollision  += collision_check(row+1, block-2);
		downCollision  += collision_check(row+1, block-3);
		break;
		case 1:
		downCollision  += collision_check(row+4, block);
		break;
		case 2:
		downCollision  += collision_check(row+1, block);
		downCollision  += collision_check(row+1, block-1);
		downCollision  += collision_check(row+1, block-2);
		downCollision  += collision_check(row+1, block-3);
		break;
		case 3:
		downCollision  += collision_check(row+4, block);
		break;
	}
}
void collision_check_left_shape_I(){
	switch(rotationPosition){
		case 0:
		leftCollision += collision_check(row, block +1);
		break;
		case 1:
		leftCollision += collision_check(row, block+1);
		leftCollision += collision_check(row+1, block+1);
		leftCollision += collision_check(row+2, block+1);
		leftCollision += collision_check(row+3, block+1);
		break;
		case 2:
		leftCollision += collision_check(row, block +1);
		break;
		case 3:
		leftCollision += collision_check(row, block+1);
		leftCollision += collision_check(row+1, block+1);
		leftCollision += collision_check(row+2, block+1);
		leftCollision += collision_check(row+3, block+1);
		break;
	}
}
void collision_check_right_shape_I(){
	switch(rotationPosition){
		case 0:
		rightCollision  += collision_check(row, block-4);
		break;
		case 1:
		rightCollision  += collision_check(row, block-1);
		rightCollision  += collision_check(row+1, block-1);
		rightCollision  += collision_check(row+2, block-1);
		rightCollision  += collision_check(row+2, block-1);
		break;
		case 2:
		rightCollision  += collision_check(row, block-4);
		break;
		case 3:
		rightCollision  += collision_check(row, block-1);
		rightCollision  += collision_check(row+1, block-1);
		rightCollision  += collision_check(row+2, block-1);
		rightCollision  += collision_check(row+2, block-1);
		break;
	}
}


//Collision check shape O
void collision_check_down_shape_O(){
	switch(rotationPosition){
		case 0:
		downCollision  += collision_check(row+2, block);
		downCollision  += collision_check(row+2, block-1);
		break;
		case 1:
		downCollision  += collision_check(row+2, block);
		downCollision  += collision_check(row+2, block-1);
		break;
		case 2:
		downCollision  += collision_check(row+2, block);
		downCollision  += collision_check(row+2, block-1);
		break;
		case 3:
		downCollision  += collision_check(row+2, block);
		downCollision  += collision_check(row+2, block-1);
		break;
	}
}
void collision_check_left_shape_O(){
	switch(rotationPosition){
		case 0:
		leftCollision += collision_check(row, block +1);
		leftCollision += collision_check(row+1, block +1);
		break;
		case 1:
		leftCollision += collision_check(row, block +1);
		leftCollision += collision_check(row+1, block +1);
		break;
		case 2:
		leftCollision += collision_check(row, block +1);
		leftCollision += collision_check(row+1, block +1);
		break;
		case 3:
		leftCollision += collision_check(row, block +1);
		leftCollision += collision_check(row+1, block +1);
		break;
	}
}
void collision_check_right_shape_O(){
	switch(rotationPosition){
		case 0:
		rightCollision += collision_check(row, block -2);
		rightCollision += collision_check(row+1, block-2);
		break;
		case 1:
		rightCollision += collision_check(row, block -2);
		rightCollision += collision_check(row+1, block-2);
		break;
		case 2:
		rightCollision += collision_check(row, block -2);
		rightCollision += collision_check(row+1, block-2);
		break;
		case 3:
		rightCollision += collision_check(row, block -2);
		rightCollision += collision_check(row+1, block-2);
		break;
	}
}


























