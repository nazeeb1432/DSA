#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root=NULL;

struct node* create_tree(){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    int value;
    printf("Enter data(-1 for no node):");
    scanf("%d",&value);
    if(value==-1)return 0;
    newNode->data=value;
    printf("\nEnter left child of %d:\n",value);
    newNode->left=create_tree();
    printf("\nEnter right child of %d:\n",value);
    newNode->right=create_tree();

    return newNode;


}

int main(){

    root=create_tree();

    return 0;
}