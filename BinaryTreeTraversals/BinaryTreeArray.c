#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct tree{
    int data;
    struct tree* left;
    struct tree* right;
};

struct tree* root=NULL;

struct tree* createTreeFromArray(int arr[],int index,int n){
    if(index>=n){
        return NULL;
    }
    if(arr[index]==-1){
        return 0;
    }
    struct tree* newNode=(struct tree*) malloc(sizeof(struct tree));

    newNode->data=arr[index];
    newNode->left=createTreeFromArray(arr,2*index+1,n);
    newNode->right=createTreeFromArray(arr,2*index+2,n);

    return newNode;
}
void preorder(struct tree* root){
    
    if(root==0){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);//recursive call
    preorder(root->right);
} 

void inorder(struct tree* root){
    if(root==0){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(struct tree* root){
    if(root==0){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main(){

    int arr[]={25,15,30,10,20,-1,40};
    int n=sizeof(arr)/sizeof(arr[0]);

    root=createTreeFromArray(arr,0,n);

    printf("preorder is:\n");
    preorder(root);
    printf("\ninorder is:\n");
    inorder(root);
    printf("\npostorder is:\n");
    postorder(root);
    


    return 0;
}