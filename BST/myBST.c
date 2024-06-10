#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data){

    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=node->right=NULL;
    return node;

}

void create_Tree(struct node* root,int input){

    struct node*node=newNode(input);

    while(root!=NULL){
        if(input<=root->data){
            if(root->left==NULL){
                root->left=node;
                break;
            }
            else root=root->left;
        }
        else//input>root->data
        {
            if(root->right==NULL){
                root->right=node;
                break;
            }else root=root->right;
        }
    }
}

void inorder(struct node* root){
    if(root==0){//base condition
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

bool search(struct node* root,int key){

        if(root==NULL)return false;//base condition
    
        if(root->data==key){
            return true;
        }else if(key<root->data){
             return search(root->left,key);//kebol search diye kaj na korate just return diyechi shamne
        }else if(key>root->data){
            return search(root->right,key);
        }
    
}

struct node* searchNode(struct node* root,int key){
    if(root==NULL) return NULL;

     if(root->data==key){
        return root;
     }else if(key<root->data){
        return searchNode(root->left,key);
     }else if(key>root->data){
        return searchNode(root->right,key);
    }
}

int find_min(struct node* root){
    if(root->left==NULL) return root->data;//base condition
    find_min(root->left);
}
int find_max(struct node* root){
    if(root->right==NULL)return root->data;
    find_max(root->right);
}

int successor(struct node* root,int data){
    if(root==NULL) return -1;//base condn,khuje na pele

    struct node* targetNode=searchNode(root,data);

    if(targetNode==NULL)return -1;

    if(targetNode->right!=NULL){
        return find_min(targetNode->right);
    }

    struct node* successor=NULL;
    struct node* ancestor=root;

    while(ancestor!=targetNode){
        if(data<ancestor->data){
            successor=ancestor;
            ancestor=ancestor->left;
        }else{
            ancestor=ancestor->right;
        }
    }

    if(successor==NULL)return -1;

    return successor->data;



}
struct node* inorderSuccessor(struct node* root){//for deletion operation
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

struct node* delete_node(struct node* root,int key){
    if(root->data>key){
        root->left=delete_node(root->left,key);
    }
    else if(root->data<key){
        root->right=delete_node(root->right,key);
    }
    else
    {


        //case 1-No child
        if(root->left==NULL && root->right==NULL){
            return NULL;
        }


        //case 2-one child
        if(root->left==NULL){
            return root->right;
        }
        else if(root->right==NULL){
            return root->left;
        }

        //case 3-two child
        struct node* IS=(struct node*)malloc(sizeof(struct node));
        IS=inorderSuccessor(root->right);
        root->data=IS->data;
        root->right=delete_node(root->right,IS->data);


    }
    return root;
}

int main(){

    int arr[]={15,6,18,3,7,17,20,2,4,13,9};
    int n=sizeof(arr)/sizeof(arr[0]);

    struct node* root=NULL;
    root=newNode(arr[0]);


    for(int i=1;i<n;i++){
        create_Tree(root,arr[i]);
    }
    printf("\nInorder traversal of the tree:\n");
    inorder(root);
    int key;
    printf("\nEnter element to search:");
    scanf("%d",&key);

    bool found;
    found=search(root,key);

    if(found){
        printf("Element found");
    }else{
        printf("No Element Found");
    }
    //find minimum and maximum in tree
    printf("\nMinimum in BST:%d\n",find_min(root));
    printf("\nMaximum in BST:%d\n",find_max(root));

    //successor
    int data;
    printf("\nEnter a node to find its successor:");
    scanf("%d",&data);

    int output=successor(root,data);
    if(output!=-1){
        printf("Successor of %d is %d\n",data,output);
    }else{
        printf("No successor found\n");
    }

    //deletion:
    printf("\nEnter data to delete:");
    scanf("%d",&data);
    printf("\nBefore deletion:\n");
    inorder(root);
    printf("\nAfter deletion:\n");
    delete_node(root,data);
    inorder(root);

    return 0;
}