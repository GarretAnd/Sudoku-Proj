#include "random.h"
#include <time.h>
#include <stdlib.h>

void gen_init(void){
  time_t t;
  // Intializes random number generator
  srand((unsigned) time(&t));
}

int rand_num (void){
  long x;
  int y;

  x = rand() % 9;  // Creates random number and modulus it by 9
  y = (int) x;  // Giving us a long value 0 - 8 then casts it as an int

  return y; // returns random number of 0-9
}

