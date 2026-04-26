/* Name					:  Praveena Vasu
   Date of completion   :  02/02/2026
   Desccription         :  APC (Arbitrary Precision Calculator) is a C-based project that performs arithmetic
                           operations on very large integers that cannot be stored in standard data types like 
						   int, long, or long long .APC solves this limitation by handling numbers digit by digit
						   using linked lists.
						   */





#include <stdio.h>
#include <stdlib.h>
#include "apc.h"

// Main function to handle input, operation selection, and result display
int main(int argc, char* argv[])
{
     // Check for correct number of command line arguments
    if (argc != 4)
    {
        printf("Insufficient argument count!\n");
        return 1;
    }

    // Detect negative sign for first and second operands
    int neg1 = 0, neg2 = 0;

    if (argv[1][0] == '-') neg1 = 1;
    if (argv[3][0] == '-') neg2 = 1;

    // Declare head and tail pointers for operands and result
    APC *head1 = NULL, *tail1 = NULL;
    APC *head2 = NULL, *tail2 = NULL;
    APC *headR = NULL, *tailR = NULL;
    // Extract operator from command line
    char op = argv[2][0];

    /* Convert input strings to linked lists (skip '-' sign if present) */
    if (insert_number_at_last(argv[1] + neg1, &head1, &tail1) != SUCCESS)
        return 1;
    if (insert_number_at_last(argv[3] + neg2, &head2, &tail2) != SUCCESS)
        return 1;
     // Perform operation based on operator
    switch (op)
    {
        case '+':
        {
            // Same sign → ADD
            if (neg1 == neg2)
            {
                add(tail1, tail2, &headR, &tailR);
                if (neg1) printf("-");
                printlist(headR);
            }
            else
            {
                int cmp = compare_list(head1, head2);
                if (cmp == 0)
                {
                    printf("0\n");
                }
                else if (cmp > 0)
                {
                    subtract(tail1, tail2, &headR, &tailR);
                    if (neg1) printf("-");
                    printlist(headR);
                }
                else
                {
                    subtract(tail2, tail1, &headR, &tailR);
                    if (neg2) printf("-");
                    printlist(headR);
                }
            }
            break;
        }

        case '-': // Handle subtraction using sign inversion
        {
            // Convert a - b as a + (-b)
            neg2 = !neg2; // flip second number's sign
            int cmp = compare_list(head1, head2);
            if (neg1 == neg2)
            {
                add(tail1, tail2, &headR, &tailR);
                if (neg1) printf("-");
                printlist(headR);
            }
            else
            {
                if (cmp == 0)
                {
                    printf("0\n");
                }
                else if (cmp > 0)
                {
                    subtract(tail1, tail2, &headR, &tailR);
                    if (neg1) printf("-");
                    printlist(headR);
                }
                else
                {
                    subtract(tail2, tail1, &headR, &tailR);
                    if (neg2) printf("-");
                    printlist(headR);
                }
            }
            break;
        }

        case 'x':// Handle multiplication with sign using XOR
        {
            int negative = neg1 ^ neg2; // XOR → sign of result
            multiplication(tail1, tail2, &headR, &tailR);
            if (negative) printf("-");
            printlist(headR);
            break;
        }

        case '/':// Handle division with sign using XOR
        {
            int negative = neg1 ^ neg2; // XOR → sign of result
            printf("Result: ");
            division(head1, tail1, head2, tail2, neg1, neg2);
            break;
        }

        default:
            printf("Invalid Input: Try again...\n");
            break;
    }

    // Clean up memory
    Delete_list(head1);
    Delete_list(head2);
    Delete_list(headR);

    return 0;
}