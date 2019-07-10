#include "../libs/number_struct.h"

/**
 * This function returns a newly allocated pointer to a NUMBER structure
 * 
 * @param: (unsigned long long int) number - this is the number to initialize the member "value" of the struct
 * @param: (NUMBER *) next - pointer to NUMBER struct for the next element within the dualy linked list of numbers
 * @param: (NUMBER *) prev - pointer to NUMBER struct for the previous element within the dualy linked list of numbers
 * @return: (NUMBER *)
 */
NUMBER* create_number_list( unsigned long long int number, NUMBER *next, NUMBER *prev ) {
  NUMBER *list = (NUMBER*)malloc(sizeof(NUMBER));
  list->value = ( (number >= 1) ? number : 1 );
  list->next = next;
  list->prev = prev;

  return list;
}

/**
 * This function iterates through the first dualy-linked list "set_a" and removes occurances of set_a found within set_b
 * 
 * @param: (NUMBER *) set_a - this is the main set of numbers which will have elements removed from
 * @param: (NUMBER *) set_b - this is the second set of numbers which will be searched through for occurrances matched within set_a 
 * @return: (NUMBER *)
 */
NUMBER* remove_duplicate_number_links( NUMBER *set_a, NUMBER *set_b ){  
  NUMBER *current_set_a = set_a;
  NUMBER *current_set_b = set_b;

  while( current_set_a != NULL ) {
    while( current_set_b != NULL ) {
      if( current_set_a->value == current_set_b->value ){                             
        remove_number_link( current_set_a ); 
        // To remove duplicates (problem --> curent_set_b = set_b for every iteration... set is reset)                      
        //set_b = remove_link_b( current_set_b ); 
      } 

      current_set_b = current_set_b->next;
    }       
    current_set_a = current_set_a->next;
    current_set_b = set_b;        
  }  

  return set_a;
}

/**
 * This function iterates through the pointer to the dualy-linked list (NUMBER *) 
 * and prints their values to the terminal
 */
void print_number_list( NUMBER *list ) {
  NUMBER * current = list;

  while( current != NULL ){
   __mingw_printf( "%llu ", current->value);   
    current = current->next;
  }
  __mingw_printf( "\n\n" );
}
 
/**
 * This function removes the current node from the dualy-linked list within the NUMBER pointer
 * 
 * @NOTE: this will remove the current node (element being pointed to) and join the 
 *        previous node (if applicable) to the next node (if applicable)
 */
void remove_number_link( NUMBER *list ) {
  NUMBER *next = list->next; // Get the next value

  if( next == NULL ) { // there is not a next    
    next = list;
    if( list->prev != NULL )
      list->prev->next = NULL;          
  }
  else { // There is a next
    if( list->prev != NULL )    
      list->prev->next = next;    

    next->prev = list->prev;
    next = list;                    
  } 
  free(next); 
}

/**
 * This function removes the current node from the dualy-linked list within the NUMBER pointer
 * 
 * @NOTE: this will remove the current node (element being pointed to) and join the 
 *        previous node (if applicable) to the next node (if applicable)
 * 
 *        Also, this will return the current pointer being executed on
 */
NUMBER* remove_number_link_b( NUMBER *list ) {      
  NUMBER *current = list;  

  if( current->next != NULL ) {    
    if( current->prev != NULL ) {      
      list->next->prev = list->prev;
      list->prev->next = list->next;            
      list = list->next;      
    } else {      
      list->next->prev = NULL;
      list = list->next;  
    }
  } else {    
    return NULL;
  }
  free(current);

  return list;
}
