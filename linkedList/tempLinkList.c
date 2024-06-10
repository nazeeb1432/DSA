#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void LinkListTraversal(struct node* ptr){
    while(ptr!=NULL){
        printf("%d-->",ptr->data);
        ptr=ptr->next;
    }printf("Null\n");
}

struct node* insertAtBeginning(struct node* head,int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    head=ptr;
    return head;
}

struct node* insertAtIndex(struct node* head,int data,int index){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;

    struct node* p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

struct node* insertAtLast(struct node* head,int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    struct node* p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

struct node* insertAfterNode(struct node* head,struct node* nod,int data){
     struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    
    ptr->next=nod->next;
    nod->next=ptr;
    return head;

}

int main(){

    struct node* head;
    struct node* second;
    struct node* third;
    struct node* fourth;

    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    fourth=(struct node*)malloc(sizeof(struct node));

    head->data=7;
    head->next=second;

    second->data=9;
    second->next=third;

    third->data=11;
    third->next=fourth;

    fourth->data=15;
    fourth->next=NULL;

    printf("Before insertion:\n");
    LinkListTraversal(head);

    head=insertAtBeginning(head,999);

    printf("After insertion\n");
    LinkListTraversal(head);

    printf("\n");
    head=insertAtIndex(head,56,2);
    LinkListTraversal(head);

    printf("\n");
    //insert at the last element
    printf("Inserting at last:\n");
    head=insertAtLast(head,223);
    LinkListTraversal(head);

    printf("\n");
    printf("insert after second node\n");
    head=insertAfterNode(head,second,111);

    LinkListTraversal(head);
    

    return 0;
}