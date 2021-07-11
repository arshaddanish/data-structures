#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
} *head = NULL, *newnode, *temp;

int length()
{
  int len = 0;
  temp = head;
  while (temp != NULL)
  {
    len++;
    temp = temp->next;
  }
  return len;
}

void insertBegin()
{
  newnode = (struct node *)malloc(sizeof(struct node));
  printf("Enter node value\n");
  scanf("%d", &newnode->data);
  newnode->next = head;
  head = newnode;
}

void insertEnd()
{
  newnode = (struct node *)malloc(sizeof(struct node));
  printf("Enter node value\n");
  scanf("%d", &newnode->data);
  newnode->next = NULL;

  if (head == NULL)
  {
    head = newnode;
    return;
  }

  temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newnode;
}

void insertPos()
{
  int pos;
  printf("Enter position\n");
  scanf("%d", &pos);
  if (pos < 1 || pos > length() + 1)
  {
    printf("Invalid position\n");
    return;
  }

  newnode = (struct node *)malloc(sizeof(struct node));
  printf("Enter node value\n");
  scanf("%d", &newnode->data);

  if (pos == 1)
  {
    newnode->next = head;
    head = newnode;
    return;
  }

  int i = 1;
  temp = head;
  while (i < pos - 1)
  {
    temp = temp->next;
    i++;
  }
  newnode->next = temp->next;
  temp->next = newnode;
}

void deleteBegin()
{
  if (head == NULL)
  {
    printf("List is Empty\n");
    return;
  }

  temp = head;
  head = head->next;
  free(temp);
}

void deleteEnd()
{
  if (head == NULL)
  {
    printf("List is Empty\n");
    return;
  }

  if (head->next == NULL)
  {
    free(head);
    head = NULL;
    return;
  }

  struct node *prevnode;
  temp = head;
  while (temp->next != NULL)
  {
    prevnode = temp;
    temp = temp->next;
  }
  prevnode->next = NULL;
  free(temp);
}

void deletePos()
{
  int pos;
  printf("Enter position\n");
  scanf("%d", &pos);

  if (pos < 1 || pos > length())
  {
    printf("Invalid position\n");
    return;
  }

  if (pos == 1)
  {
    temp = head;
    head = head->next;
    free(temp);
    return;
  }

  struct node *prevnode;
  int i = 1;
  temp = head;
  while (i < pos)
  {
    prevnode = temp;
    temp = temp->next;
    i++;
  }
  prevnode->next = temp->next;
  free(temp);
}

void reverse()
{
  if (head == NULL || head->next == NULL)
  {
    return;
  }

  struct node *prevnode, *nextnode;
  prevnode = NULL;
  temp = head;
  while (temp != NULL)
  {
    nextnode = temp->next;
    temp->next = prevnode;
    prevnode = temp;
    temp = nextnode;
  }
  head = prevnode;
}

void display()
{
  printf("List:\n");
  temp = head;
  while (temp != NULL)
  {
    printf("%d\t", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main()
{
  int ch = -1;
  while (ch != 0)
  {
    printf("1 - Insert at beginning\n");
    printf("2 - Insert at end\n");
    printf("3 - Insert at a specified position\n");
    printf("4 - Delete from beginning\n");
    printf("5 - Delete from end\n");
    printf("6 - Delete from a specified postion\n");
    printf("7 - Reverse\n");
    printf("0 - Exit\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      insertBegin();
      display();
      break;

    case 2:
      insertEnd();
      display();
      break;

    case 3:
      insertPos();
      display();
      break;

    case 4:
      deleteBegin();
      display();
      break;

    case 5:
      deleteEnd();
      display();
      break;

    case 6:
      deletePos();
      display();
      break;

    case 7:
      reverse();
      display();
      break;

    case 0:
      printf("Exited...\n");
      break;

    default:
      printf("Enter a valid choice\n");
    }
  }

  return 0;
}