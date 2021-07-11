#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
  struct node *prev;
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
  newnode->prev = NULL;
  newnode->next = head;
  if (head)
  {
    head->prev = newnode;
  }
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
    newnode->prev = NULL;
    head = newnode;
    return;
  }

  temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newnode;
  newnode->prev = temp;
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
    newnode->prev = NULL;
    newnode->next = head;
    if (head)
    {
      head->prev = newnode;
    }
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
  if (temp->next)
  {
    temp->next->prev = newnode;
  }
  temp->next = newnode;
  newnode->prev = temp;
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
  if (head)
  {
    head->prev = NULL;
  }
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

  temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->prev->next = NULL;
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
    if (head)
    {
      head->prev = NULL;
    }
    free(temp);
    return;
  }

  int i = 1;
  temp = head;
  while (i < pos)
  {
    temp = temp->next;
    i++;
  }
  temp->prev->next = temp->next;
  if (temp->next)
  {
    temp->next->prev = temp->prev;
  }
  free(temp);
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
    printf("6 - Delete from a specified position\n");
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

    case 0:
      printf("Exited...\n");
      break;

    default:
      printf("Enter a valid choice\n");
    }
  }
}