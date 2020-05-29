/* Author: Garret Andreine
 * Date: 5/27/2020
 * Purpose: CS50 Final project
 * Header file for random.c
 */

 #include <time.h>
 #include <stdlib.h>
 // Includes needed libraries

#ifndef __RAND_H
#define __RAND_H

/******************gen_init********************
* Initializes random number generator based off a seed of the time
*
* Returns:
*   void */
void gen_init(void);


/******************rand_num********************
* Creates random integer of 0-9
*
* Returns:
*   int with random value */
int rand_num (void); // Gets a random number 1 through 10


#endif // __RAND_H
