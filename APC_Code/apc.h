#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1
#define x *
#include <stddef.h>   
typedef int data_t;
// Node structure for doubly linked list
typedef struct node
{
	struct node *prev; // Pointer to previous node
	data_t data;   // Stores single digit
	struct node *next; // Pointer to next node
}APC;

typedef struct node1
{
	data_t count;
	struct node1 *link;
}APCS;

/* Include the prototypes here */
int insert_number_at_last(char *str, APC **head, APC **tail);
int insert_at_last(APC **head, APC **tail, int data);
int insert_at_first(APC **head, APC **tail, int data);
int add(APC *tail1, APC *tail2, APC **headR, APC **tailR);
int compare_list(APC *head1, APC *head2);
void subtract(APC *tail1, APC *tail2, APC **headR, APC **tailR);
void Delete_list(APC *head);
int multiplication(APC *tail1, APC *tail2, APC **headR, APC **tailR);
void division(APC *head1, APC *tail1, APC *head2, APC *tail2, int neg1, int neg2);
APC* copy_list(APC *head, APC **tail);


int insert_count_at_last(APCS **head, APCS **tail, int data);
void printlist(APC*head);

#endif