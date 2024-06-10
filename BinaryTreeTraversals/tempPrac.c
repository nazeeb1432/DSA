#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_tree(){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    int value;
    printf("\nEnter value(-1 for no node):");
    scanf("%d",&value);
    if(value==-1){
        return 0;
    }
    newnode->data=value;
    printf("Enter left child of %d:",value);
    newnode->left=create_tree();
    printf("Enter right child of %d:",value);
    newnode->right=create_tree();

    return newnode;

}

void preorder(struct node* root){
    if(root==0){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
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

    struct node* root=NULL;
    root=create_tree();

    printf("Preorder traversal:\n");
    preorder(root);
    printf("\nInorder traversal:\n");
    inorder(root);
    printf("\nPostorder traversal:\n");
    postorder(root);
    

    return 0;
}