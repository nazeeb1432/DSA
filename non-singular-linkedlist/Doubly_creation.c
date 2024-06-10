#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
  struct node *prev;
};

struct node *head = NULL;
struct node *temp = NULL;

int length;

void print_list();
void insert_data();
void insertAtBeg();
void insertAtEnd();
void insertAtPos();
void insertAfterPos();
void delete_node();
void deleteAtBeg();
void deleteAtEnd();
void deleteFromPos();
void reverse_print();

void reverseDLL();

int main()
{
  int choice, option;
  while (1)
  {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter node's data:\n");
    scanf("%d", &newnode->data);

    newnode->next = 0;
    newnode->prev = 0;

    if (head == NULL)
    {
      head = temp = newnode;
    }
    else
    {
      temp->next = newnode;
      newnode->prev = temp;
      temp = newnode;
    }
    printf("\n1.continue\n2.quit-");
    scanf("%d", &choice);
    if (choice == 2)
      break;
  }

  while (1)
  {
    printf("\n1.print\n2.insert\n3.delete\n4.reverse the DLL\n5.reverse print\n6.quit");
    printf("\nEnter your option:");
    scanf("%d", &option);
    if (option == 1)
    {
      print_list();
    }
    else if (option == 2)
    {
      insert_data();
    }
    else if (option == 3)
    {
      delete_node();
    }
    else if (option == 4)
      reverseDLL();
    else if (option == 5)
    {
      reverse_print();
    }
    else if(option == 6){
      break;
    }
  }
  return 0;
}

void print_list()
{
  struct node *ptr = head;
  length = 0;
  while (ptr != NULL)
  {
    printf("%d-->", ptr->data);
    length++;
    ptr = ptr->next;
  }
  printf("NULL\n");
}

void insert_data()
{
  int choice;
  printf("\n1.insert_at_beginning\n2.insert at end\n3.insert at position\n4.insert after a position");
  printf("\nEnter your choice:");
  scanf("%d", &choice);

  switch (choice)
  {
  case 1:
    insertAtBeg();
    break;
  case 2:
    insertAtEnd();
    break;
  case 3:
    insertAtPos();
    break;
  case 4:
    insertAfterPos();
    break;
  default:
    break;
  }
}

void insertAtBeg()
{
  struct node *newnode1 = (struct node *)malloc(sizeof(struct node));
  printf("Enter data to insert:");
  scanf("%d", &newnode1->data);
  newnode1->next = 0;
  newnode1->prev = 0;
  // now let us insert
  newnode1->next = head;
  head->prev = newnode1;
  head = newnode1;
  print_list();
}

void insertAtEnd()
{
  struct node *newnode2 = (struct node *)malloc(sizeof(struct node));

  printf("Enter data to insert:");
  scanf("%d", &newnode2->data);
  newnode2->next = 0;
  newnode2->prev = 0;
  temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }

  // insert at the last
  temp->next = newnode2;
  newnode2->prev = temp;
  print_list();
}

void insertAtPos()
{
  int pos;
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  printf("Enter node's data to insert:\n");
  scanf("%d", &newnode->data);

  newnode->next = 0;
  newnode->prev = 0;
  printf("Enter position to insert:");
  scanf("%d", &pos);
  if (pos == 0 || pos > length)
    printf("Invalid position");
  else if (pos == 1)
    insertAtBeg();
  else
  {
    temp = head;
    int i = 1;
    while (i < pos - 1)
    {
      temp = temp->next;
      i++;
    }
    //temp has now come to the current position
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next->prev = newnode;
    print_list();
  }
}

void insertAfterPos()
{
  int pos, i = 1;
  struct node *newnode = (struct node *)malloc(sizeof(struct node *));
  printf("Enter data to insert:");
  scanf("%d", &newnode->data);
  newnode->next = 0;
  newnode->prev = 0;

  temp = head;

  printf("\nEnter the position after which you wanna insert my boy:");
  scanf("%d", &pos);
  if(pos==length)insertAtEnd();
  while (i < pos)
  {
    temp = temp->next;
    i++;
  }
  newnode->next = temp->next;
  temp->next = newnode;
  newnode->prev = temp;
  newnode->next->prev = newnode;
  print_list();
}

void delete_node()
{
  int choice;
  printf("\nWhat do you want?\n");
  printf("1.delete from beginning\n2.delete from end\n3.delete from a position\n");
  printf("choose:");
  scanf("%d", &choice);

  switch (choice)
  {
  case 1:
    deleteAtBeg();
    break;
  case 2:
    deleteAtEnd();
    break;
  case 3:
    deleteFromPos();
    break;
  default:
    break;
  }
}

void deleteAtBeg()
{
  temp = head;
  head = head->next;
  free(temp);
  print_list();
}

void deleteAtEnd()
{
  temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->prev->next = 0;
  free(temp);
  print_list();
}

void deleteFromPos()
{
  int position;
  printf("Enter the position you want to delete:");
  scanf("%d", &position);
  if (position == 1)
    deleteAtBeg();
  else if (position == length)
    deleteAtEnd();
  else if (position > length)
    printf("Invalid position");
  else
  {
    temp = head;
    int i = 1;
    while (i < position)
    {
      temp = temp->next;
      i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);

    print_list();
  }
}

void reverseDLL()
{
  temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  struct node *current, *nextnode;
  // now reverse process--
  current = head;
  while (current != 0)
  {
    nextnode = current->next;
    current->next = current->prev;
    current->prev = nextnode;
    current = nextnode;
  }

  current = head;
  head = temp;
  temp = current;

  print_list();
}
void reverse_print(){
  temp=head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  while(temp->prev!=head){
    printf("%d-->", temp->data);
    temp=temp->prev;
  }
}