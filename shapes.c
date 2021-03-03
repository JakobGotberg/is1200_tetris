

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "header_file.h"  /* Declatations for these labs */


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