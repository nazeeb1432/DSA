#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 5

 struct student{
    int roll;
    int marks;
    char name[50];
    struct node* next;
}bsse14[size];

struct student *head=NULL;
struct student *temp=NULL;
int len=0;

void input();
void copy_marks(int arr[]);
void sort();
void create_list(int roll,int marks,char name[]);
void addStudent();
void removeStudent();
void search();
void printList();

int main(){

    int marks[size],choice;
    input();
    copy_marks(marks);

    for(int i=0; i<size;i++){
        for(int j=0; j<size; j++){
            if(marks[i]==bsse14[j].marks){
                create_List(bsse14[j].roll,bsse14[j].marks,bsse14[j].name);
            }
        }
    }

    while(1){
        
    
        printf("1.print list\n2.Add student\n3.Remove student\n4.search\n5.Quit\n");
        printf("Enter choice:");
        scanf("%d", &choice);
        if (choice == 1)
            printList();
        else if (choice == 2)
        {
            addStudent();
            printList();
        }
        else if (choice == 3)
        {
            removeStudent();
            printList();
        }
        else if (choice == 4)
        {
            search();
        }
        else if(choice==5)break;
    

    
    }
    

    return 0;
}
void input(){
    printf("Enter roll,marks,name:\n");
    for(int i=0;i<size;i++){
        scanf("%d %d %s",&bsse14[i].roll,&bsse14[i].marks,bsse14[i].name);
    }
}
void copy_marks(int arr[]){
    for(int i=0;i<size;i++){
        arr[i]==bsse14[i].marks;
    }
    sort(arr);
}
void sort(int arr[]){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;i<size;j++){
            if(arr[i]<arr[j]){
                int temp=arr[j];
                arr[j] = arr[i];
                arr[i]=temp;
            }
        }
    }
}
void create_list(int roll,int marks,char name[]){
    struct student* newnode=(struct student*)malloc(sizeof(struct student));
    newnode->roll=roll;
    newnode->marks=marks;
    strcpy(newnode->name,name);//structure e eivabe dhukate hoyy

    if(head==NULL){
        temp=head=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
}

void printList(){
    struct student* ptr=head;

    printf("\tMarks\t\tRoll\tname\n");
    while(ptr!=NULL){
        printf("\t%d \t\t%d\t%s\n",ptr->marks,ptr->roll,ptr->name);
        ptr=ptr->next;
    }

}

void addStudent(){
    struct student* link=(struct student*)malloc(sizeof(struct student));
    struct student *prevstudent;//prev pointer maintain kora lagbe
    temp=head;
    printf("\nEnter new roll:");
    scanf("%d",&link->roll);
    printf("Enter new marks:");
    scanf("%d",&link->marks);
    printf("Enter new name:");
    scanf("%s",link->name);

    if(link->marks<=temp->marks){
        while(temp!=NULL && temp->marks>=link->marks){
            prevstudent=temp;
            temp=temp->next;

        }
        if(temp==NULL){
            prevstudent->next=link;
            link->next=NULL;
        }
        else{            
            prevstudent->next=link;
            link->next=temp;
        }
    }
    else{
        link->next=head;
        head=link;
    }

}

