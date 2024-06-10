#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 10
void input();
void copy_marks(int arr[]);
void sort(int arr[]);
void creating_list(int roll, int marks,char name[]);
void printList();
void addStudent();
void removeStudent();
void search();

struct student
{
    int roll;
    int marks;
    char name[50];
    struct student *next;
} bsse14[size];

struct student *head = NULL;
struct student *temp = NULL;
int length = 0;

int main()
{
    int marks[size], choice;
    input();
    copy_marks(marks);

    // now create the link list according to highest marks to lowest marks
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (marks[i] == bsse14[j].marks)
            {
                creating_list(bsse14[j].roll, bsse14[j].marks,bsse14[j].name);
            }
        }
    }

    while (1)
    {
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
void input()
{
    FILE *fp;
    fp = fopen("input.txt", "r");
    for (int i = 0; i < size; i++)
    {
        fscanf(fp, "%d %d ", &bsse14[i].roll,&bsse14[i].marks);
        fgets(bsse14[i].name, 50,fp);
    }   

    fclose(fp);
}

void copy_marks(int arr[])
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = bsse14[i].marks;
    }
    sort(arr);
}

void sort(int arr[])
{

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void creating_list(int roll, int marks,char name[])
{
    // create a node
    struct student *link=(struct student *)malloc(sizeof(struct student));

    link->roll = roll;
    link->marks = marks;
   strcpy(link->name, name);

    link->next = NULL;

    if (head == NULL)
    {
        head = link;
        temp = link;
    }
    else
    {
        temp->next = link;
        temp = link;
    }
}

void printList()
{
    struct student *ptr = head;
    // start from the beginning
    printf("\tMarks\t\tRoll\tNames\n");
    while (ptr != NULL)
    {   
        // length++;
        printf("\t%d \t\t%d\t%s\n", ptr->marks, ptr->roll,ptr->name);
        ptr = ptr->next;
        
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

void removeStudent(){

    struct student* prevnode;
    temp=head;
    int roll;
    printf("\nEnter roll to delete:");
    scanf("%d",&roll);

    while(temp->roll!=roll){
        prevnode=temp;
        temp=temp->next;
    }
    if(temp==head)head=head->next;
    else{
        prevnode->next=temp->next;        
    }
    free(temp);

}

void search(){
    int roll,flag=0;
    printf("\nEnter roll to search:");
    scanf("%d",&roll);
    temp=head;

    while(temp!=NULL){
        if(roll==temp->roll){
            flag=1;
            break;
        }
        else{
            temp=temp->next;
        }
    }
    if(flag==0)printf("Student not found\n");
    if(flag==1)printf("\nStudent found\nstudent's name:%s\nstudent's marks:%d\n",temp->name,temp->marks);


}