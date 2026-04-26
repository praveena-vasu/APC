#include<stdio.h>
#include<stdlib.h>
#include "apc.h"
// Creates and returns a duplicate of a given linked list
APC* copy_list(APC *head, APC **tail)
{
    APC *rev_head = NULL, *rev_tail = NULL;

    while (head!=NULL)
    {
        insert_at_last(&rev_head, &rev_tail, head->data);
        head = head->next;
    }

    *tail = rev_tail;
    return rev_head;
}
// Converts numeric string into linked list
int insert_number_at_last(char *str, APC **head, APC **tail)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
        {
            printf("Invalid number\n");
            return FAILURE;
        }

        insert_at_last(head, tail, str[i] - '0');
        i++;
    }
    return SUCCESS;
}


// Insert a node at the end of doubly linked list
int insert_at_last(APC **head, APC **tail, int data)
{
    APC *new = malloc(sizeof(APC));
    new->data = data;
    new->next = NULL;
    new->prev = *tail;

    if (*head == NULL)
        *head = *tail = new;
    else
    {
        (*tail)->next = new;
        *tail = new;
    }
    return SUCCESS;
}


// Insert a node at the beginning of doubly linked list
int insert_at_first(APC** head,APC** tail,int data)
{
    APC *new = malloc(sizeof(APC));
    if (new == NULL)
    {
        printf("Memory allocation failed\n");
        return FAILURE;
    }

    new->data = data;
    new->prev = NULL;
    new->next = *head;

    if (*head == NULL)   // empty list
    {
        *head = *tail = new;
    }
    else           // non-empty list
    {
        (*head)->prev = new;
        *head = new;
    }

    return SUCCESS;
}


// Insert digit at last of singly linked list (quotient/COUNT)
int insert_count_at_last(APCS **head, APCS **tail, int data)
{
    APCS *new_node = malloc(sizeof(APCS));
    if (!new_node) return FAILURE;

    new_node->count = data;
    new_node->link = NULL;

    if (*head == NULL)
        *head = *tail = new_node;
    else
    {
        (*tail)->link = new_node;
        *tail = new_node;
    }
    return SUCCESS;
}

// Returns 1 if head1 > head2
// Returns -1 if head1 < head2
// Returns 0 if equal
// Compare two numbers stored in linked lists
int compare_list(APC *head1, APC *head2) 
{
    int len1 = 0, len2 = 0;
    APC *temp1 = head1;
    APC *temp2 = head2;

    while (temp1!=NULL) 
    {
         len1++;
         temp1 = temp1->next; 
    }
    while (temp2!=NULL)
     {
         len2++; 
         temp2 = temp2->next; 
     }

    if (len1 > len2) return 1;
    if (len1 < len2) return -1;

    //if (len1==len2)
    temp1 = head1;
    temp2 = head2;

    while (temp1!=NULL && temp2!=NULL)
     {
        if (temp1->data > temp2->data) return 1;
        if (temp1->data < temp2->data) return -1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return 0; // Numbers are equal
}

// Free all nodes of a linked list
void Delete_list(APC *head)
{
    APC *temp = head;
    while (temp != NULL)
    {
        APC *next = temp->next;  // store next node
        free(temp);              // free current node
        temp = next;             // move to next node
    }
}

// Print number stored in linked list
void printlist(APC *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return ;
    }

    APC *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

