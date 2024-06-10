#include<stdio.h>
#include<stdlib.h>


void printList();
void creating_list(int i);
void insertbeg();
void insertend();
void insert_after_a_given_pos();
void deletebeg();
void deleteend();
void delete_specific_pos();
void search();


struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;
struct node *temp=NULL;
int length=0;

int main(int argc,char *argv[])
{

    for(int i=1;i<=10;i++) creating_list(i);

    printf("Before insertion: ");
    printList();

    printf("\nlength: %d",length);

    insertbeg();
    printf("\nAfter insertion at beg: ");
    printList();

    insertend();
    printf("\nAfter insertion at end: ");
    printList();

    insert_after_a_given_pos();
    printf("\nAfter insertion at given pos: ");
    printList();

    deletebeg();
    printf("\nAfter deletion at beginning: ");
    printList();

    deleteend();
    printf("\nAfter deletion at end:");
    printList();

    delete_specific_pos();
    printf("\nAfter deletion at given position: ");
    printList();

    search();


    return 0;
}

void printList() {
   struct node *ptr = head;
   //start from the beginning
   while(ptr != NULL) {
       length++;
      printf("%d-->",ptr->data);
      ptr = ptr->next;
     
   }printf("NULL");
	
}

void creating_list(int i) {
   int data;
   struct node *newNode = (struct node*) malloc(sizeof(struct node));
    printf("\nEnter data %d:",i);
    scanf("%d",&data);
   newNode->data = data;

   newNode->next=0;

   if(head==NULL) {
    head=temp=newNode;
    
   }
   else {
    temp->next=newNode;
    temp=newNode;
   }

}

void insertbeg(){
    struct node *link = (struct node*) malloc(sizeof(struct node));

    printf("\nEnter new data at the top:");
    scanf("%d",&link->data);

    link->next=head;
    head=link;
}

void insertend(){
    struct node *newNode = (struct node*) malloc(sizeof(struct node));

    printf("\nEnter new data at the end:");
    scanf("%d",&newNode->data);

    newNode->next=0;
    temp=head;

    while(temp->next!=0) temp=temp->next;

    temp->next=newNode;
}

void insert_after_a_given_pos(){
    int pos,i=1;
    printf("\nEnter position to insert:");
    scanf("%d",&pos);

    if(pos>length) printf("Invalid position");
    else{
            struct node *link = (struct node*)malloc(sizeof(struct node));
            temp=head;
            while(i<pos) {
                temp=temp->next;
                i++;
            }
            printf("\nEnter new data after a given pos:");
            scanf("%d",&link->data);

            link->next=temp->next;
            temp->next=link;


    }
    

}

void deletebeg(){
    temp=head;
    head=head->next;
    free(temp);

}

void deleteend(){
    struct node *prev;
    temp=head;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    if(temp==head) head=NULL;
    else{
        prev->next=NULL;
    }
    free(temp);
}

void delete_specific_pos(){
    struct node *nextnode;
    temp=head;
    int pos,i=1;
    printf("\nEnter position to delete:");
    scanf("%d",&pos);

    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;

    free(nextnode);
}

void search(){
    
    int value,flag=0;
    printf("\nEnter value to search:");
    scanf("%d",&value);
    temp=head;
    while(temp!=NULL){
        if(value==temp->data){
            flag=1;
            break;
        }
        else{
            temp=temp->next;
        }
    }

    if(flag==0) printf("Not found\n");
    else printf("Found\n");
}