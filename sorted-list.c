#include "sorted-list.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACK_EMPTY -1

/**
 * \param lst This is a pointer to the list which will be sorted using the insertion sort algorithm.
 */
void insertion_sort(sorted_list_t* lst){
  for (size_t i = 1; i < lst->length; i++) {
    int key = lst->data[i]; // Element to be placed in the sorted portion
    int j = i - 1;

    // Move elements of lst->data[], that are greater than key, to one position ahead 
    // of their current position
    while (j >= 0 && lst->data[j] > key) {
      lst->data[j + 1] = lst->data[j];
      j = j - 1;
    }
    lst->data[j + 1] = key; // Place the key at the correct position
  }
}
/**
 * Initialize a sorted list.
 *
 * \param lst This is a pointer to space that should be initialized as a sorted list. The caller of
 * this function retains ownership of the memory that lst points to (meaning the caller must free it
 * if the pointer was returned from malloc)
 */
void sorted_list_init(sorted_list_t* lst) {

  lst->data = NULL;
  lst->length = 0;
}

/**
 * Destroy a sorted list. Free any memory allocated to store the list, but not the list itself.
 *
 * \param lst This is a pointer to the space that holds the list being destroyred. This function
 * should free any memory used to represent the list, but the caller retains ownership of the lst
 * pointer itself.
 */
void sorted_list_destroy(sorted_list_t* lst) {
  free(lst->data);

  sorted_list_init(lst);
}

/**
 * Add an element to a sorted list, maintaining the lowest-to-highest sorted order.
 *
 * \param lst   The list that is being inserted to
 * \param value The value being inserted
 */
void sorted_list_insert(sorted_list_t* lst, int value) {
  // Only inserts into list, does not order it yet.
  lst->data = realloc(lst->data, sizeof(int)*(lst->length + 1));
  lst->data[lst->length] = value;
  lst->length++;
  insertion_sort(lst);
}

/**
 * Count how many times a value appears in a sorted list.
 *
 * \param lst The list being searched
 * \param value The value being counted
 * \returns the number of times value appears in lst
 */
size_t sorted_list_count(sorted_list_t* lst, int value) {
  size_t count = 0;
    
  // Traverse through the list and count occurrences of the value
  for (size_t i = 0; i < lst->length; i++) {
    if (lst->data[i] == value) {
      count++;
    }
  }
  return count;
}

/**
 * Print the values in a sorted list in ascending order, separated by spaces and followed by a
 * newline.
 *
 * \param lst The list to print
 */
void sorted_list_print(sorted_list_t* lst) {
  if (lst->length == 0){
    printf("%d\n", STACK_EMPTY);
  }
  else{
    for (size_t i = 0; i < lst->length; i++)
    {
      printf("%d ", *(lst->data + i));
    }
    printf("\n");
  }
}
