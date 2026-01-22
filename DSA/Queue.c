#include <stdio.h>
#define size 5

int queue[size];
int front = 0, rear = -1;

void insert()
{
    int data;
    if (rear == size - 1)
        printf("Queue overflow");

    printf("Enter the value: ");
    scanf("%d", &data);
    rear++;
    queue[rear] = data;
}

void delete()
{
    if (front > rear)
    {
        printf("Queue is empty");
    }

    printf("deleted %d", queue[front]);
    front++;
}
void display()
{
    if (front > rear)
    {
        printf("Queue is empty");
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
}

int main()
{
    int option;
    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter the Option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insert();
            break;

        case 2:
            delete();
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;
        }
    }
}