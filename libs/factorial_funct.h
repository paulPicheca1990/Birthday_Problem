#ifndef __FACTORIAL_FUNC_H__
#define __FACTORIAL_FUNC_H__

#include "../libs/number_struct.h"

long long unsigned int factorial( unsigned long long int number );

long long unsigned int factorial_iterative( unsigned long long int number );

unsigned long long int calculate_factorial( NUMBER *list );

NUMBER *create_factorial_list( unsigned long long int number );

NUMBER *populate_factorial_list( unsigned long long int number );

NUMBER *reduce_list_factorial_division( 
  unsigned long long int n, unsigned long long int r );

void print_factorial_list( NUMBER *list );

#endif