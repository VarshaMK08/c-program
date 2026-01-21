#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *llink, *rlink;
};
typedef struct node *NODE;

NODE createNode(int data)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = data;
    temp->llink = NULL;
    temp->rlink = NULL;
    return temp;
}

NODE insert(NODE root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->llink = insert(root->llink, data);

    else if (data > root->data)
        root->rlink = insert(root->rlink, data);

    return root;
}

void PrintPath(int path[], int length)
{
    for (int i = 0; i < length; i++)
        printf("%d ", path[i]);
    printf("\n");
}

void rootToLeaf(NODE root, int path[], int length)
{
    if (root == NULL)
        return;

    path[length] = root->data;
    length++;

    if (root->llink == NULL && root->rlink == NULL)
        PrintPath(path, length);

    else
    {
        rootToLeaf(root->llink, path, length);
        rootToLeaf(root->rlink, path, length);
    }
}

int main()
{
    NODE root = NULL;
    int i, n;
    int data, path[100];

    printf("Enter the number of nodes :");
    scanf("%d", &n);

    printf("Enter the value of the nodes:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Root to Leaf Path:");
    rootToLeaf(root, path, 0);
    return 0;
}