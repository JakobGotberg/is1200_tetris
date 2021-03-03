
#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "header_file.h"  /* Declatations for these labs */


//Collision check shape T
void collision_check_down_shape_T(){
	switch(rotationPosition){
		case 0:
		downCollision = collision_check(row+2, block);
		downCollision = collision_check(row+2, block-1);
		downCollision = collision_check(row+2, block-2);
		break;
		case 1:
		downCollision = collision_check(row+3, block);
		downCollision = collision_check(row+2, block-1);
		break;
		case 2:
		downCollision = collision_check(row+1, block);
		downCollision = collision_check(row+2, block-1);
		downCollision = collision_check(row+1, block-2);
		break;
		case 3:
		downCollision = collision_check(row+2, block);
		downCollision = collision_check(row+3, block-1);
		break;
	}
}
void collision_check_left_shape_T(){
	switch(rotationPosition){
		case 0:
		leftCollision = collision_check(row, block);
		leftCollision = collision_check(row+1, block+1);
		break;
		case 1:
		leftCollision = collision_check(row, block+1);
		leftCollision = collision_check(row+1, block+1);
		leftCollision = collision_check(row+2, block+1);
		break;
		case 2:
		leftCollision = collision_check(row, block+1);
		leftCollision = collision_check(row+1, block);
		break;
		case 3:
		leftCollision = collision_check(row, block);
		leftCollision = collision_check(row+1, block+1);
		leftCollision = collision_check(row+2, block+1);
		break;
	}
}
void collision_check_right_shape_T(){
	switch(rotationPosition){
		case 0:
		rightCollision = collision_check(row, block-2);
		rightCollision = collision_check(row+1, block-3);
		break;
		case 1:
		rightCollision = collision_check(row, block-1);
		rightCollision = collision_check(row+1, block-2);
		rightCollision = collision_check(row+2, block-1);
		break;
		case 2:
		rightCollision = collision_check(row, block-3);
		rightCollision = collision_check(row+1, block-2);
		break;
		case 3:
		rightCollision = collision_check(row, block-2);
		rightCollision = collision_check(row+1, block-2);
		rightCollision = collision_check(row+2, block-2);
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