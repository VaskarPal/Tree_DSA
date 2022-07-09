#include <stdio.h>
#include <stdlib.h>
#define size 7
struct node
{
   int data;
   struct node *next;
};
struct node *chain[size];
void init()
{
    int i;
    for (i=0; i<size; i++)
    {
        chain[i] = NULL;
    }
}
void insert(int val)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = val;
    newNode -> next = NULL;
    int key = val % size;

    if (chain[key] == NULL)
    {
        chain[key] = newNode;
    }
    else
    {
        struct node* temp = chain[key];
        while (temp -> next)
        {
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
}
void print()
{
    int i;
    
    for ( i = 0; i < size; i++)
    {
        struct node * temp = chain[i];
        printf ("Chain[%d]--> ", i);
        while (temp)
        {
            printf ("%d--> ",temp -> data);
            temp = temp -> next;
        }
        printf ("NULL\n");

    }
}
int main()
{
    init();

    insert(7);
    insert(3);
    insert(10);
    insert(23);
    insert(2);
    insert(33);
    insert(63);

    print();
    return 0;
}