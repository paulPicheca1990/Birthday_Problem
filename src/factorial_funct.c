#include "../libs/factorial_funct.h"

/**
 * This function retruns the factorial calculation for a given number
 *  
 * @param: (unsigned long long int) number - the inital number for the factorial calc
 * @return: (unsigned long long int) result of the factorial calculation
 * 
 * @Note: This is an actual recursive function (calls itself over and over again)
 */
long long unsigned int factorial( unsigned long long int number ) {  
  if( number <= 1 && number >=0 )
    return 1;

  return number * factorial( number - 1 );
}

/**
 * This function retruns the factorial calculation for a given number
 *  
 * @param: (unsigned long long int) number - the inital number for the factorial calc
 * @return: (unsigned long long int) result of the factorial calculation
 * 
 * @Note: This is an iterative function (simulates calling itself over and over)
 */
long long unsigned int factorial_iterative( unsigned long long int number ) {  
  long long unsigned int result = 1;
  if( number <= 1 && number >=0 )
    return result;

  while( number > 0 ) {
    result *= number * (number - 1);
    number--;
  }

  return result;  
}

/** 
 * This function will create a pointer to a dualy-linked-list (NUMBER) using
 * the inital seed provided as input (number)
 * 
 * @param: (unsigned long long int) number - this is the integer for the initial seed of the factorial 
 * @return: (NUMBER *) list of factorial numbers 
 * 
 * @Note: this function calls populate_factorial_list() for creating the values for the factorial list
 */
NUMBER *create_factorial_list( unsigned long long int number ){  
  NUMBER *list = populate_factorial_list( number );
  return list; 
}

/** 
 * This function will create a pointer to a dualy-linked-list (NUMBER) using
 * the inital seed provided as input (number)
 * 
 * @param: (unsigned long long int) number - this is the integer for the initial seed of the factorial 
 * @return: (NUMBER *) list of factorial numbers
 * 
 * @Note: this function calls populate_factorial_list() for creating the values for the factorial list
 */
NUMBER *populate_factorial_list( unsigned long long int number ) {
  NUMBER *list = create_number_list( number--, NULL, NULL );
  NUMBER *current = list;
  
  while( number >= 1 ){    
    current->next = create_number_list( number--, NULL, current);
    current = current->next;
  }

  return list;
}

/**
 * This function will calculate the factorial result using the numbers within the (NUMBER *)
 * dualy-linked-list of numbers
 * 
 * @param: (NUMBER *) list - the list of numbers for calculating the factorial
 * @return: (unsigned long long int) result of the factorial calculation
 */
unsigned long long int calculate_factorial( NUMBER *list ) {
  NUMBER *current = list;

  unsigned long long int result = 1;
  while( current != NULL ) {    
    result *= current->value;        
    current = current->next;
  }

  return result;
}

/**
 * This function performs factorial division using two newly allocated (NUMBER) pointers.
 * 
 * @Remarks: 
 *  - One (NUMBER *) represents the numerator and the other (NUMBER *) represents the denominator.
 *  - the numbers in the numerator are removed when the same number is found within the denominator.
 * 
 * @formula: (n!) / (n - r)!
 * 
 * @E.g. (n!) / (n - r)!; n = {4}, r = {2}  
 *  = (4!) / (4 - 2)!
 *    => (4 x 3 x 2 x 1) / (2 x 1)
 *    => (4 x 3) / 1
 *    => (4 x 3)
 * 
 * @param: (unsigned long long int)n - this is the initial seed for the factorial within the numerator
 * @param: (unsigned long long int)r - this is the stop case for the factorial in the denominator
 * @return: (NUMBER *) containing the reduced numerator after the factorial division
 */
NUMBER *reduce_list_factorial_division( unsigned long long int n, unsigned long long int r ) {
  NUMBER *numerator = populate_factorial_list(n);  
  NUMBER *denominator = populate_factorial_list(n - r);  
    
  numerator = remove_duplicate_number_links( numerator, denominator);
  free(denominator);  
  
  return numerator;
}

/**
 * This function will print the numbers within the factorial number list to the terminal
 * @see: print_number_list(NUMBER *)
 * @return: (void)
 */
void print_factorial_list( NUMBER *list ){
  print_number_list(list);
}




