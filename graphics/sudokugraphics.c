#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>
//#include "libsudoku.h"
//#include "creator.h"
//#include "solver.h"

const int BOARD_SIZE = 500;

int main(void){
	int gd = DETECT, gm;
	clrscr();
	initgraph(&gd, &gm, "");
	// circle function 
    	rectangle(0, 0, BOARD_SIZE, BOARD_SIZE);
  
    	getch(); 
  
    	// closegraph function closes the 
    	// graphics mode and deallocates 
    	// all memory allocated by 
    	// graphics system . 
    	closegraph(); 
  
    	return 0; 
}
