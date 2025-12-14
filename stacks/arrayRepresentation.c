#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int s[MAX], top = -1;

int push(int, int);
int pop(int);
void display(int);

int main()
{
    int choice, item;
    while (choice != 4)
    {
        printf("\n1.push\n2.pop\n3.display\n4.exit\n");
        printf("Enter the Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &item);
            top = push(top, item);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            display(top);
            break;
        case 4:

            break;
        }
    }
    return 0;
}

int push(int top, int val)
{
    if (top == MAX - 1)
    {
        printf("Overflow");
    }
    else
    {
        top++;
        s[top] = val;
        printf("inserted %d", s[top]);
    }
    return top;
}
int pop(int top)
{
    if (top == -1)
    {
        printf("Underflow");
    }
    else
    {
        printf("popped %d", s[top]);
        top--;
    }
    return top;
}
void display(int top)
{
    if (top == -1)
    {
        printf("Empty");
    }
    else
    {
        printf("Stack: ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", s[i]);
        }
    }
    return;
}