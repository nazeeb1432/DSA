#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int root;
    struct tree *left;
    struct tree *right;
};

struct tree* newNode(int data)
{
    struct tree *node = (struct tree*)malloc(sizeof(struct tree));
    node->root = data;
    node->left = node->right = NULL;
    return node;
}

struct tree* create(struct tree *t1, int input)
{
    struct tree *Root = t1;
    
    // if( Root == NULL )
    // {
    //     Root = newNode(input);
    //     //return ;
    // }
    // else if ( input < Root->root )
    // {
    //     // Root = Root->left ;
    //     if(Root->left == NULL){
    //         Root->left = newNode(input);
    //         break;
    //     }
    //     create(Root, input);
    // }
    // else
    // {
    //     Root = Root->right ;
    //     create(Root, input);
    // }
    struct tree *node = newNode(input);
    while(Root!=NULL)
    {
        if(Root->root >= input)
        {
            if(Root->left == NULL)
            {
                Root->left = node;
                break;
            }
            else Root = Root->left;
        }
        else
        {
            if(Root->right == NULL)
            {
                Root->right = node;
                break;
            }
            else Root = Root ->right;
        }
    }
    
    return Root;
}



int pre_traversal(struct tree *s )
{
    printf("%d ",s->root);
    if(s->left)
    {
        pre_traversal(s->left);
    }
    
    if (s->right)
    {
        pre_traversal(s->right);
    }
    
}

void inorder_traversal(struct tree *s )
{
    if( s != NULL )
    {
        inorder_traversal(s->left);
        printf("%d ",s->root);
        inorder_traversal(s->right);
    }
}

int postorder_traversal(struct tree *s )
{
    if( s != NULL )
    {
        postorder_traversal(s->left);
        postorder_traversal(s->right);
        printf("%d ",s->root);
    }
}



int main()
{
    int arr[] = {7,5,6,2,4,3,1,10,8,9};
    int n = sizeof(arr)/sizeof(int) ;
    //struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    struct tree *t1 ;
    
    t1 = newNode(arr[0]);
    for (int i = 1; i < n; i++)
    {
        create(t1, arr[i]);          //  arr[i]->
    }

    inorder_traversal(t1);
    

    return 0;
}



      /*              7
                4        9
             2     5    8  10*/