/* Author: Garret Andreine
 * Date: 5/27/2020
 * Purpose: CS50 Final project
 * All the functions needed to create a random number.
 */

#include "random.h"
#include <time.h>
#include <stdlib.h>

void gen_init(void){
  time_t t;
  // Intializes random number generator with a seed based off the time
  srand((unsigned) time(&t));
}

int rand_num (void){
  long x;
  int y;

  x = rand() % 9;  // Creates random number and modulus it by 9
  y = (int) x;  // Giving us a long value 0 - 8 then casts it as an int

  return y; // returns random number of 0 - 8
}
