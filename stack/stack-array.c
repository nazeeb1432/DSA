#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 5
int stack[N];
int top = -1;

void Push();
void Pop();
void Peek();
void Display();

int main()
{

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

void Push(){
  int x;
  printf("\nEnter value to be pushed: ");
  scanf("%d",&x);
  if(top==N-1){
    printf("Overflow!!");
  }
  else{
    top++;
    stack[top]=x;
  }
}
void Pop(){
  int item;
  if(top==-1){
    printf("underflow\n");
  }
  else{
    item=stack[top];
    top--;
    printf("\n%d\n",item);
  }
}
void Peek(){
  if(top==-1){
    printf("stack is empty");
  }
  else{
    printf("%d\n",stack[top]);
  }
}
void Display(){
  int i;
  for(int i=top;i>=0;i--){
    printf("%d\n",stack[i]);
  }
}