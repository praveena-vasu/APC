#include<stdio.h>
#include<stdlib.h>
#include "apc.h"
// Perform subtraction of two large numbers
void subtract(APC *tail1, APC *tail2, APC **headR, APC **tailR)
 {
    // Subtract digits using borrow
    int borrow = 0;
    APC *temp1 = tail1; // temp variable
    APC *temp2 = tail2;
    int diff;

    *headR = NULL;
    *tailR = NULL;

    while (temp1 != NULL) 
    {
        int d1 = temp1->data;
        int d2 = (temp2 != NULL) ? temp2->data : 0;

        diff = d1 - d2 - borrow;

        if (diff < 0) 
        {
            diff = diff + 10;
            borrow = 1;
        } 
        else
        {
            borrow = 0;
       }

        // Insert at first
        insert_at_first(headR, tailR, diff);

        temp1 = temp1->prev;
        if (temp2 != NULL) 
            temp2 = temp2->prev;
    }

    // Remove leading zeros
    while (*headR!=NULL && (*headR)->data == 0 && (*headR)->next != NULL)
     {
        APC *to_remove = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(to_remove);
    }
}