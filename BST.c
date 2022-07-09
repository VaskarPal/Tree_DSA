#include<stdio.h>
#include<stdlib.h>
struct node
{
    int key;
    struct node *left, *right;
   
};

struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> key = item;
    temp -> left = temp -> right = NULL;
    return temp;
}

struct node* inorder(struct node* root)
{
    if (root != NULL)
    {
        inorder(root -> left);
        printf ("%d", root -> key);
        inorder(root -> right);
    }
}

struct node* insert(struct node* node, int key)
{
    if (node == NULL)
    {
        return newNode(key);
    }
    
       if (key > node -> key)
       {
           node -> right = insert(node -> right, key);
       }
       else
       {
           node -> left = insert(node -> left, key);
       }
    return node;
}

struct node* minValue(struct node* node)
{
    struct node* current = node;
    while (current && current -> left != NULL)
    {
        current = current -> left;
    }
    return current;
}

struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root -> key)
    {
        root -> left = deleteNode(root -> left, key);
    }
    else if (key > root -> right)
    {
        root -> right = deleteNode(root -> right, key);
    }
    else
    {
        if (root -> left == NULL)
        {
            struct node* temp = root -> right;
            free(root);
            return temp;
        }
        else if(root -> right == NULL)
        {
            struct node* temp = root -> left;
            free(root);
            return temp;
        }
        struct node* temp = minValue(root -> right);
        root -> key = temp -> key;
        root -> right = deleteNode(root -> right, key);
    }
    return root;
}

int main ()
{
    struct node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    printf ("Inorder Traversal of a given Tree is : \n");
    inorder(root);
    printf("\nDelete 20\n");
    root = deleteNode(root,20);
    printf("Modified Traversal of the given Tree is: \n");
    inorder(root);
    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Modified Traversal of the given Tree is: \n");
    inorder(root);
    return 0;
}

