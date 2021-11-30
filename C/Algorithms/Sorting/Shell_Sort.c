// Generic Shell Sort
// #include "sort.h"

/**
 * @brief           Shell Sort a list of elements
 * 
 * @param list      (void *) to list containing elements of any type
 * @param keyfunct  Pointer to function that returns (int) value that
 *                  should be used for comparing elements
 * @param list_len  Number of elements in list
 * @param elem_size sizeof() list element
 */

#include <stdlib.h>
#include <string.h> // memcpy

#define ELEMENT_AT(list, pos, len) (((char*)list) + ((pos)*(len)))

void ssort(void *list, int (*keyfunct)(void *), int list_len, int elem_size) {
    int D = list_len/2;
    while (D >= 1) {
        // k keeps track of [index of] element being re-positioned.
        int k = D; 
        while (k < list_len) {
            void *elem = malloc(elem_size); // Current in re-positioning
            memcpy(elem, ELEMENT_AT(list, k, elem_size), elem_size);
            // To assure the number being compared to list[k] is in the same
            // sublist, we subtract, from k's position the current
            // distance (D) we are working with
            int comparee = k - D;
            // Insertion Sort'ing sublists 
            while (comparee >= 0 && (*keyfunct)(elem) < (*keyfunct)(ELEMENT_AT(list, comparee, elem_size))) {
                memcpy(ELEMENT_AT(list, comparee + D, elem_size), ELEMENT_AT(list, comparee, elem_size), elem_size);
                comparee -= D;
            }
            memcpy(ELEMENT_AT(list, comparee + D, elem_size), elem, elem_size);
            k++;
            free(elem);
        }
        D = D/2; // Decreasing comparison distance
    }
}