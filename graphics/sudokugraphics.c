#include <graphics.h>
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
    	rectangle(0, 0, BOARD_SIZE, BOARD_SIZE);
  
    	getch(); 
  
    	closegraph(); 
  
    	return 0; 
}
