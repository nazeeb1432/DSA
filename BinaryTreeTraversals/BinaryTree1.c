#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create(){

    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    int value;
    printf("\nEnter value(-1 for no node):");
    scanf("%d",&value);
    if(value==-1){
        return 0;
    }
    newnode->data=value;
    printf("Enter left child of %d:",value);
    newnode->left=create();//recursion
    printf("Enter right child of %d:",value);
    newnode->right=create();//recursion

    return newnode;//jei node call korechilo 


}
void preorder(struct node* root){
    
    if(root==0){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);//recursive call
    preorder(root->right);
} 

void inorder(struct node* root){
    if(root==0){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(struct node* root){
    if(root==0){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main(){

    struct node* root;
    root=NULL;
    root=create();

    printf("preorder is:\n");
    preorder(root);
    printf("\ninorder is:\n");
    inorder(root);
    printf("\npostorder is:\n");
    postorder(root);
    

    return 0;
}