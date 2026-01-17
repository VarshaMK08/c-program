#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
typedef struct node *NODE;

NODE rear = NULL;

void enqueue(int data)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = data;

    if (rear == NULL)
    {
        rear = temp;
        rear->link = rear;
    }

    else
    {
        temp->link = rear->link;
        rear->link = temp;
        rear = temp;
    }
}

void dequeue()
{
    NODE front;

    if (rear == NULL)
    {
        printf("Queue is empty");
    }
    front = rear->link;

    if (front == rear)
    {
        printf("%d deleted", front->data);
        free(front);
        rear = NULL;
    }
    else
    {
        rear->link = front->link;
        printf("%d deleted", front->data);
        free(front);
    }
}

void display()
{
    if (rear == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        NODE temp = rear->link;
        printf("Queue list:");
        do
        {
            printf("%d ", temp->data);
            temp = temp->link;
        } while (temp != rear->link);
    }
}

int main()
{
    int option, data;
    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter the Option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;
        }
    }
}