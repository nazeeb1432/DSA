#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int input)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = input;
    newnode->left = newnode->right = NULL;
    return newnode;
}

void create_tree(struct node *root, int input)
{
    struct node *newnode = newNode(input);

    while (root != NULL)
    {
        if (input <= root->data)
        {
            if (root->left == NULL)
            {
                root->left = newnode;
                break;
            }
            else
                root = root->left;
        }
        else
        {
            if (root->right == NULL)
            {
                root->right = newnode;
                break;
            }
            else
                root = root->right;
        }
    }
}

void inorder(struct node* root){
    if(root==0){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

bool search(struct node* root,int key){
    while(root!=NULL){
        if(root->data==key){
            return true;
        }
        else if(key<root->data){
            return search(root->left,key);
        }
        else if(key>root->data){
            return search(root->right,key);
        }
    }
}
int find_min(struct tree *root){
    if(root->left==NULL) return root->data;
    find_min(root->left);

int main()
{
    int arr[] = {7, 5, 6, 2, 4, 3, 1, 10, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    struct node *root = NULL;
    root = newNode(arr[0]);

    for (int i = 1; i < n; i++)
    {
        create_tree(root, arr[i]);
    }
    printf("\nInorder traversal of the tree:\n");
    inorder(root);

    printf("\nEnter value to search:");
    scanf("%d",&key);
    bool found=search(root,key);
    if(found){
        printf("\nElement found\n");

    }else printf("\nNo element found\n");

    //find minimum and maximum of a tree

}
