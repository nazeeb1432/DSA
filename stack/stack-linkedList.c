#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

struct node{
    int data;
    struct node *next;
};

struct node *top=0;
void push(int x){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;

    if()
    
}

int main(){

     int choice;

  do
  {

    printf("\nEnter choice:\n1)Push\n2)Pop\n3)Peek\n4)Display\n5.Quit-->");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      Push();
      break;
    case 2:
      Pop();
      break;
    case 3:
      Peek();
      break;
    case 4:
      Display();
      break;

    default:
      break;
    }
  } while (choice != 5);

  return 0;

    

}