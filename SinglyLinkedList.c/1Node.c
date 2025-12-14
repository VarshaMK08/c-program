#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node *NODE;  

void DisplayList(NODE head)
{
    NODE temp = head;
    printf("Linked List: ");
    while(temp!= NULL){
    printf("%d -> ",temp->data);
    temp = temp->next;
    }
    printf("NULL");

}

int main(){
    NODE first,second,third;

    first = (NODE)malloc(sizeof(struct node));
    first -> data = 10;
    first -> next = NULL;

    second = (NODE)malloc(sizeof(struct node));
    second -> data = 20;
    second -> next = NULL;

    third = (NODE)malloc(sizeof(struct node));
    third -> data = 40;
    third -> next = NULL;

    first -> next = second;
    second -> next = third;
  
    DisplayList(first);

    return 0;
}