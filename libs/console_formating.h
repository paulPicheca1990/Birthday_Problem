#ifndef __CONSOLE_FORMATIING_H__
#define __CONSOLE_FORMATIING_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/** ################################################################################# 
 *  > Constants
 *  #################################################################################
 */
extern const int TOTAL_PROGRAM_WIDTH;
extern const char *COLUMNS[];
extern const int NUMBER_OF_COLUMNS; 
extern const char *PROGRAM_TITLE;

/** ################################################################################# 
 *  > Formatting Methods
 *  #################################################################################
 */
char *get_text_bar();

char *format_string( const int size,  const char direction );

char *format_lld( const int size, const char direction );

char *format_Lf( const int size, const int digits, const char direction );

void print_columns( const char *format, const char *columns[], const int number_of_columns );

void print_dividing_bar();

#endif