#include <stdio.h>
#include <stdlib.h>
#define size 5
int stack[size];
int top = -1;
void push(int item);
int pop();
void display();
int isfull();
int isempty();

int main()
{
    int op,item;
    printf ("\n\t\tEnter any operation you want to do in stack: ");
    printf ("\n1. Push: ");
    printf ("\n2. Pop: ");
    printf ("\n3. Display: ");
    printf ("\n4. Exit: ");
    while (1)
    {
        printf ("\nYour Choice: ");
        scanf ("%d",&op);
        switch (op)
        {
        case 1:
        printf ("Element to push in the stack: ");
        scanf ("%d",&item);
        push(item);
            break;
        case 2:
        item = pop();
        printf ("Poped Element is: %d",item);
            break;
        case 3:
        display();
        break;
        case 4:
        exit(1);
        
        default:
        printf ("Wrong Input! ");
            break;
        }
        printf ("\n.................\n");
    }
    return 0;
}

void push (int item)
{
   if (isfull())
   {
       printf ("\nStack is Overflow ");
       return ;
   }
   top = top + 1;
   stack[top] = item;
}
int pop()
{
	int item;
	if(isempty())
	{
		printf("\nUnderflow\n");
		exit(1);
	}
	item=stack[top];
	top--;
	return item;
}
void display()
{
	int i;
	if(isempty())
	{
		printf("\nstack is empty\n");
		return ;
	}
	printf("\nNow the stack is : \n\n");
	for (i=top;i>=0;i--)
	{
		printf("\t%d\n",stack[i]);
	
	}
	
}
int isfull()
{
	if(top==size-1)
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
 	if (top==-1)
 	{
 		return 1;
	 }
	 else
	 {
	 	return 0;
	 }
 }