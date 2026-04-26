#include "apc.h"
#include<stdlib.h>
#include<stdio.h>
// Perform multiplication of two large numbers
int multiplication(APC *tail1, APC *tail2, APC **headR, APC **tailR)
{
     // Multiply digit by digit and accumulate result
    APC *t2 = tail2;
    APC *result_head = NULL, *result_tail = NULL;
    int shift = 0;

    while (t2!=NULL)
    {
        APC *t1 = tail1;
        APC *temp_head = NULL, *temp_tail = NULL;
        int carry = 0;

        // multiply one digit
        while (t1!=NULL)
        {
            int prod = (t1->data * t2->data) + carry;
            carry = prod / 10;
            insert_at_first(&temp_head, &temp_tail, prod % 10);
            t1 = t1->prev;
        }

        if (carry)
            insert_at_first(&temp_head, &temp_tail, carry);

        // append zeros (SHIFT LEFT)
        for (int i = 0; i < shift; i++)
            insert_at_last(&temp_head, &temp_tail, 0);

        // add to final result
        if (result_head == NULL)
        {
            result_head = temp_head;
            result_tail = temp_tail;
        }
        else
        {
            APC *sum_head = NULL, *sum_tail = NULL;
            add(result_tail, temp_tail, &sum_head, &sum_tail);

            Delete_list(result_head);
            Delete_list(temp_head);

            result_head = sum_head;
            result_tail = sum_tail;
        }

        shift++;
        t2 = t2->prev;
    }
     
    *headR = result_head;
    *tailR = result_tail;
    return SUCCESS;
}