#include "../libs/bday_prop_calc.h"

long double bday_probability( unsigned long long int persons ) {  
  unsigned long long int set = 365; // 365 days in a year

  if( persons > set || persons == 1 )
    return 0.000000000000000000000000000000;

  NUMBER *result_list = reduce_list_factorial_division( 365, persons );
  unsigned long long int factorial_calc = calculate_factorial(result_list);

  long double result = ( (long double)factorial_calc /  powl(set, persons) ) * (long double)100.00;     

  return result;
}