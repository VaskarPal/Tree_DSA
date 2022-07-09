#include <stdio.h>
#include <stdlib.h>
#define size 5
int q[size];
int rear = -1;
int front = -1;
void insert (int item);
int delete();
void display();
int isfull();
int isempty();
 int main()
 {
     int op,item;
     printf ("\n\t\tEnter Your Choice from the below Queue operations: ");
     printf ("\n1. Insert: ");
     printf ("\n2. Delete: ");
     printf ("\n3. Display: ");
     printf ("\n4. Exit: ");

     while(1)
     {
         printf ("\nYour Choice: ");
         scanf ("%d",&op);
         switch (op)
         {
             case 1:
             printf ("\nEnter the element to Insert: ");
             scanf ("%d",&item);
             insert (item);
             break;
             case 2:
             item = delete();
             printf ("\nElement is deleted : %d",item);
             break;
             case 3:
             display ();
             break;
             case 4:
             exit (1);
             break;
             default :
             printf ("Wrong Input! ");

         }
         printf ("\n................\n");
     }
     return 0;
 }

 void insert(int item)
 {
     if (isfull())
     {
         printf ("Queue is Overflow");
     }
     else
     {
         if (front == -1)
         front = 0;
         rear = rear +1;
         q[rear] = item;
     }
 }

 int delete ()
 {
     int item;
     if (isempty())
     {
         printf ("Queue is Underflow");
     }
     item = q[front];
     front = front + 1;
     return item;
 }
 void display()
{
	int i;
	if(isempty())
	{
		printf("\nQueue is underflow condition. ");
	
	}
	for (i=front;i<=rear;i++)
	{
		printf("\t%d\n",q[i]);
	}
}
int isfull()
{
	if(rear==size-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isempty()
{
	if(front==-1 ||front>rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}