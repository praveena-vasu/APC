#include "apc.h"
// Perform addition of two large numbers

int add(APC *tail1,APC *tail2,APC **res_head,APC **res_tail)
{
     // Add digits from tail with carry
    int res=0,carry=0;
    APC *temp1 = tail1;
    APC *temp2 = tail2;

    while(temp1 != NULL || temp2 != NULL)
    {
        res = carry;

        if(temp1 != NULL)
        {
        res = res + temp1->data;
        temp1 = temp1->prev;
        }
        if(temp2 != NULL)
        {
            res = res + temp2->data;
            temp2 = temp2->prev;
        }
        
        carry = res / 10; // carry if present
        res = res % 10;  
            
        insert_at_first(res_head,res_tail,res); // inserting the number at first
    }
    if(carry)  // if carry inserting directly to the list
      insert_at_first(res_head,res_tail,carry);
}