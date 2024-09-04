#include <stdio.h>
#include <stdlib.h>
// Definition of Node for Binary search tree
struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};

// Function to create a new Node in heap
struct BstNode *GetNewNode(int data)
{
    struct BstNode *newNode = (struct BstNode *)calloc(1, sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// To insert data in BST, returns address of root node
struct BstNode *Insert(struct BstNode *root, int data)
{
    if (root == NULL)
    { // empty tree
        root = GetNewNode(data);
    }
    // if data to be inserted is lesser, insert in left subtree.
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    // else, insert in right subtree.
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}
// To search an element in BST, returns true if element is found
int Search(struct BstNode *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->data == data)
    {
        return 1;
    }
    else if (data <= root->data)
    {
        return Search(root->left, data);
    }
    else
    {
        return Search(root->right, data);
    }
}
int main()
{
    struct BstNode *root = NULL;
    // Creating an empty tree
    int num,op;
    while (1)
    {
        printf("1)inserted\n");
        printf("2)searched\n");
        printf("chose one option ..\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1: // insert
            printf("enter the number to be enter into BST..\n");
            scanf("%d", &num);
            root = Insert(root, num);
            break;
        case 2: // search   
            printf("enter the number to be searched in BST..\n");
            scanf("%d", &num);
            if (Search(root, num) == 1)
                printf("Found\n");
            else
                printf("Not Found\n");
            break;
        }
    }
}