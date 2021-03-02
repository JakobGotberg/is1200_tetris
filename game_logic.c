

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

void display_shape( uint8_t row, uint8_t block, char shape)
{


	if(shape == 'T' || shape == 't'){
		logic_to_pixel_set(row,block - 1 );
		logic_to_pixel_set(row + 1, block);
		logic_to_pixel_set(row + 1, block - 1);
		logic_to_pixel_set(row + 1, block - 2);
		
	}

	if(shape == 'L' || shape == 'l'){
		logic_to_pixel_set(row,block -2);
		logic_to_pixel_set(row +1, block);
		logic_to_pixel_set(row+1, block-1);
		logic_to_pixel_set(row+1, block-2);
	}

	if(shape == 'J' || shape == 'j'){
		logic_to_pixel_set(row,block);
		logic_to_pixel_set(row+1, block);
		logic_to_pixel_set(row+1, block-1);
		logic_to_pixel_set(row+1, block-2);
	}

	if(shape == 'O' || shape == 'o'){
		logic_to_pixel_set(row,block);
		logic_to_pixel_set(row, block-1);
		logic_to_pixel_set(row+1, block);
		logic_to_pixel_set(row+1, block-1);
	}

	if(shape == 'Z' || shape == 'z'){
		logic_to_pixel_set(row,block-1);
		logic_to_pixel_set(row, block-2);
		logic_to_pixel_set(row+1, block);
		logic_to_pixel_set(row+1, block-1);
	}

	if(shape == 'S' || shape == 's'){
		logic_to_pixel_set(row,block);
		logic_to_pixel_set(row, block-1);
		logic_to_pixel_set(row+1, block-1);
		logic_to_pixel_set(row+1, block-2);
	}

	if(shape == 'I' || shape == 'i'){
		logic_to_pixel_set(row,block);
		logic_to_pixel_set(row+1,block);
		logic_to_pixel_set(row+2,block);
		logic_to_pixel_set(row+3,block);
	}

}

void delete_shape( uint8_t row, uint8_t block, char shape)
{


	if(shape == 'T' || shape == 't'){
		logic_to_pixel_clr(row,block - 1 );
		logic_to_pixel_clr(row + 1, block);
		logic_to_pixel_clr(row + 1, block - 1);
		logic_to_pixel_clr(row + 1, block - 2);
		
	}

	if(shape == 'L' || shape == 'l'){
		logic_to_pixel_clr(row,block -2);
		logic_to_pixel_clr(row +1, block);
		logic_to_pixel_clr(row+1, block-1);
		logic_to_pixel_clr(row+1, block-2);
	}

	if(shape == 'J' || shape == 'j'){
		logic_to_pixel_clr(row,block);
		logic_to_pixel_clr(row+1, block);
		logic_to_pixel_clr(row+1, block-1);
		logic_to_pixel_clr(row+1, block-2);
	}

	if(shape == 'O' || shape == 'o'){
		logic_to_pixel_clr(row,block);
		logic_to_pixel_clr(row, block-1);
		logic_to_pixel_clr(row+1, block);
		logic_to_pixel_clr(row+1, block-1);
	}

	if(shape == 'Z' || shape == 'z'){
		logic_to_pixel_clr(row,block-1);
		logic_to_pixel_clr(row, block-2);
		logic_to_pixel_clr(row+1, block);
		logic_to_pixel_clr(row+1, block-1);
	}

	if(shape == 'S' || shape == 's'){
		logic_to_pixel_clr(row,block);
		logic_to_pixel_clr(row, block-1);
		logic_to_pixel_clr(row+1, block-1);
		logic_to_pixel_clr(row+1, block-2);
	}

	if(shape == 'I' || shape == 'i'){
		logic_to_pixel_clr(row,block);
		logic_to_pixel_clr(row+1,block);
		logic_to_pixel_clr(row+2,block);
		logic_to_pixel_clr(row+3,block);
	}

}

char rng()
{

return 'z';

}

void fall_down(uint8_t row, uint8_t block, char shape)
{
delete_shape(row, block, shape);
display_shape(row+1, block, shape);
}

void go_left(uint8_t row, uint8_t block, char shape)
{
delete_shape(row, block, shape);
display_shape(row, block+1, shape);

}

void go_right(uint8_t row, uint8_t block, char shape)
{
delete_shape(row, block, shape);
display_shape(row, block-1, shape);
}

/*
	ground, return 1
	down, return 2
	right, return 3
	left, return 4
	wall_right 5
	wall_left 6
*/























