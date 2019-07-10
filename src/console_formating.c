
#include "../libs/console_formating.h"

const int TOTAL_PROGRAM_WIDTH = 100;
const char *COLUMNS[] = {"People", "Probability"};
const int NUMBER_OF_COLUMNS = sizeof(COLUMNS) / sizeof( COLUMNS[0] );
const char *PROGRAM_TITLE = "People Having different Birthdays";

/**
 * This returns an allocated string containing 400 repeated '=' characters
 * @param: (void)
 * @return: (char *)
 */
char *get_text_bar() {
  int bar_size = 400;
  char *bar = (char *)malloc( sizeof(char) * (bar_size + 1) ); // (1) for '\0'
  
  int index = 0;
  for( index = 0; index < bar_size; index++ ) {
    bar[index] = '=';    
  }  
  bar[index++] = '\0';

  return bar;
}

/**
 * This returns an allocated string containing a format
 * for printing "String" values via the printf() function
 * 
 * @param: (const int) size - the size of padding for the string printed
 * @param: (const char) direction - direction of the padding {left, Right}
 * 
 * @Note:
 *  This function is only for printing string types through printf()
 * 
 *  The direction variable is a character which accepts {+, -} only.
 *  (+) means the padding will be left aligned
 *  (-) means the padding will be right aligned
 * 
 * @TODO: implement direction into the padding. 
 *        (Default): {Left aligned}
 * 
 * @TODO: refactor all format_*() functions into one nice modular function
 */
char *format_string( const int size,  const char direction ) {  
  char *preprocess_string = "%%-%ds";
  
  int number_of_digits = (int) ( log10(size) + 1 );
  int format_string_size = strlen( preprocess_string ) - 3 + number_of_digits; 
    
  char *format_string = (char *)malloc( sizeof(char) * format_string_size + 1 ); // Don't forget the '\0' character
  format_string[format_string_size] = '\0';

  sprintf(format_string, preprocess_string, size );  

  return format_string;
}

/**
 * This returns an allocated string containing a format
 * for printing "Long Long Integers" values via the printf() function
 * 
 * @param: (const int) size - the size of padding for the string printed
 * @param: (const char) direction - direction of the padding {left, Right}
 * 
 * @Note:
 *  This function is only for printing string types through printf()
 * 
 *  The direction variable is a character which accepts {+, -} only.
 *  (+) means the padding will be left aligned
 *  (-) means the padding will be right aligned
 * 
 * @TODO: implement direction into the padding. 
 *        (Default): {Left aligned}
 * 
 * @TODO: refactor all format_*() functions into one nice modular function
 */
char *format_lld( const int size, const char direction ) {
  char *preprocess_string = "%%%dlld";
  
  int number_of_digits = (int) ( log10(size) + 1 );
  int format_string_size = strlen( preprocess_string ) - number_of_digits; 
  
  char *format_string = (char *)malloc( sizeof( format_string_size ) + 1 ); // Don't forget the '\0' character

  sprintf(format_string, preprocess_string, size );  

  return format_string;
}

/**
 * This returns an allocated string containing a format
 * for printing "Long Long Floating/Double" values via the printf() function
 * 
 * @param: (const int) size - the size of padding for the string printed
 * @param: (const char) direction - direction of the padding {left, Right}
 * 
 * @Note:
 *  This function is only for printing string types through printf()
 * 
 *  The direction variable is a character which accepts {+, -} only.
 *  (+) means the padding will be left aligned
 *  (-) means the padding will be right aligned
 * 
 * @TODO: implement direction into the padding. 
 *        (Default): {Left aligned}
 * 
 * @TODO: refactor all format_*() functions into one nice modular function
 */
char *format_Lf( const int size, const int digits, const char direction ) {
  char *preprocess_string = "%%%d.%dLf";
  
  int number_of_digits = (int) ( log10(size) + 1 ) + (int) ( log10(digits) + 1 );
  int format_string_size = strlen( preprocess_string ) - number_of_digits; 
  
  char *format_string = (char *)malloc( sizeof( format_string_size ) + 1 ); // Don't forget the '\0' character

  sprintf(format_string, preprocess_string, size, digits );  

  return format_string;
}

/**
 * This function prints the columns to the terminal via the printf() function
 * 
 * @param: (const char *)format - this is the string containing the format for printf()
 * @param: (const char *)columns[] - collection of column names to be printed
 * @param: (const int)number_of_columns - this is the number of columns within the columns input
 * 
 * @Note: columns is a pointer which points to an array.   
 *        Therefore, the size of the array cannot be dynamically calculated 
 *        iterating through the entire collection.  * 
 *        Hense, the extra input "number_of_columns"
 */
void print_columns( const char *format, const char *columns[], const int number_of_columns ) {
  int index;  
  for( index = 0; index < number_of_columns; index++ ) {
    printf( format, columns[index] );
    if( index != (number_of_columns - 1) && number_of_columns > 1 )
      printf( " | " );
  }
  printf( "\n" );
}

void print_dividing_bar(){
  // Gather sizing information
  char *bar = get_text_bar();
  const int total_width = TOTAL_PROGRAM_WIDTH;

  // Display
  printf( "%.*s\n", total_width, bar );

  // Free Used Memory
  free(bar);
}