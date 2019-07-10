/* ###################################################
 * <Author>: Paul Picheca
 * <Data>: 2019-06-19
 * <Purpose>: This is program will 
 * 
 * <Remarks>: The program should do 
 * 
 * ################################################### */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/console_formating.h"
#include "./libs/number_struct.h"
#include "./libs/bday_prop_calc.h"

void print_title() {  

  // Sizing and Templating
  const int number_of_columns = NUMBER_OF_COLUMNS;
  const int total_width = TOTAL_PROGRAM_WIDTH;
  char *format = format_string( ( total_width / number_of_columns ), '-' );  

  // Display
  printf( "%s\n", PROGRAM_TITLE );  
  print_dividing_bar();
  print_columns( format, COLUMNS, number_of_columns );
  print_dividing_bar();  
  
  // Free Used memory
  free(format);
}

void calculate_bday_problem( unsigned long long int persons ) {  
  const int number_of_columns = NUMBER_OF_COLUMNS;
  const int column_size = ( TOTAL_PROGRAM_WIDTH / number_of_columns );
  char *format_llint = format_lld( column_size, '-' );
  char *format_Lfloat = format_Lf( ( column_size - 5 ), 42, '-' );
  
  printf( format_llint, persons );
  printf( " | " );
  __mingw_printf( format_Lfloat, bday_probability( persons ) );  
  printf( " %%\n" );

  free(format_llint);
  free(format_Lfloat);
}

/** ################################################################################# 
 *  > Main Driver
 *  #################################################################################
 */
int main( int argc, char *argv[] ) {      
  int index = 1;
  int extra_cmd_args = argc - 1;
  unsigned long long int persons; 

  print_title();
  while( index <= extra_cmd_args ) {
    persons = atoi(argv[index++]);
    calculate_bday_problem( persons );
  } 
  
  return 0;
}