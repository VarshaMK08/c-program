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
        root = createNode(data);

    if (data < root->data)
        root->llink = insert(root->llink, data);

    else if (data > root->data)
        root->rlink = insert(root->rlink, data);

    return root;
}

int countLeafNode(NODE root)
{
    if (root == NULL)
        return 0;

    if (root->llink == NULL && root->rlink == NULL)
        return 1;

    return countLeafNode(root->llink) + countLeafNode(root->rlink);
}

int main()
{
    NODE root = NULL;
    int i, n;
    int data;

    printf("Enter the number of nodes :");
    scanf("%d", &n);

    printf("Enter the value of the nodes:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Total number of leaf nodes are: %d", countLeafNode(root));
}