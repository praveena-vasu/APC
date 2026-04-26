#include<stdio.h>
#include<stdlib.h>
#include"apc.h"

void division(APC *head1, APC *tail1, APC *head2, APC *tail2, int neg1, int neg2)
{
    // Divide by zero check
    if (head2->data == 0 && head2->next == NULL)
    {
        printf("Division by zero error\n");
        return;
    }

    int negative = neg1 ^ neg2;//Result is 1 only when one number is negative
                               //If signs are different → result is negative
                               //If signs are same → result is positive

    // Copy dividend & divisor (absolute values)
    APC *dividend_tail, *divisor_tail;
    APC *dividend = copy_list(head1, &dividend_tail);
    APC *divisor  = copy_list(head2, &divisor_tail);

    int count = 0;

    // Repeated subtraction
    while (compare_list(dividend, divisor) >= 0)
    {
        APC *temp_head = NULL, *temp_tail = NULL;
        subtract(dividend_tail, divisor_tail, &temp_head, &temp_tail);

        Delete_list(dividend);
        dividend = temp_head;
        dividend_tail = temp_tail;
        count++;
    }

    // Store quotient digits in APCS
    APCS *qhead = NULL, *qtail = NULL;

    if (count == 0)
    {
        insert_count_at_last(&qhead, &qtail, 0);
    }
    else
    {
        int digits[20], i = 0;
        while (count)
        {
            digits[i++] = count % 10;
            count /= 10;
        }
        for (int j = i - 1; j >= 0; j--)
            insert_count_at_last(&qhead, &qtail, digits[j]);
    }

    // Print result
    if (negative)
        printf("-");

    APCS *temp = qhead;
    while (temp)
    {
        printf("%d", temp->count);
        temp = temp->link;
    }
    printf("\n");

    Delete_list(dividend);
}