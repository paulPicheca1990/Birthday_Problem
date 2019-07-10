#ifndef __FACTORIAL_H__
#define __FACTORIAL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct _NUMBER {
  unsigned long long int value;
  struct _NUMBER* next;  
  struct _NUMBER* prev;
} NUMBER;

NUMBER* create_number_list( 
  unsigned long long int number, NUMBER *next, NUMBER *prev );

NUMBER* remove_duplicate_number_links( NUMBER *set_a, NUMBER *set_b );
 
void remove_number_link( NUMBER *list );

NUMBER* remove_number_link_b( NUMBER *list );

void print_number_list( NUMBER *list );

#endif