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
  if (head == NULL)
    return len;

  temp = head;
  while (temp->next != head)
  {
    len++;
    temp = temp->next;
  }
  return len + 1;
}

void insertBegin()
{
  newnode = (struct node *)malloc(sizeof(struct node));
  printf("Enter node value\n");
  scanf("%d", &newnode->data);

  if (head == NULL)
  {
    newnode->next = newnode;
    head = newnode;
    return;
  }

  temp = head;
  while (temp->next != head)
  {
    temp = temp->next;
  }
  temp->next = newnode;
  newnode->next = head;
  head = newnode;
}

void insertEnd()
{
  newnode = (struct node *)malloc(sizeof(struct node));
  printf("Enter node value\n");
  scanf("%d", &newnode->data);

  if (head == NULL)
  {
    newnode->next = newnode;
    head = newnode;
    return;
  }

  temp = head;
  while (temp->next != head)
  {
    temp = temp->next;
  }
  temp->next = newnode;
  newnode->next = head;
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

  if (pos == 1)
  {
    insertBegin();
    return;
  }

  newnode = (struct node *)malloc(sizeof(struct node));
  printf("Enter node value\n");
  scanf("%d", &newnode->data);

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
    printf("List underflow\n");
    return;
  }

  if (head->next == head)
  {
    free(head);
    head = NULL;
    return;
  }

  temp = head;
  while (temp->next != head)
  {
    temp = temp->next;
  }
  temp->next = head->next;
  temp = head;
  head = head->next;
  free(temp);
}

void deleteEnd()
{
  if (head == NULL)
  {
    printf("List underflow\n");
    return;
  }

  if (head->next == head)
  {
    free(head);
    head = NULL;
    return;
  }

  struct node *prevnode;
  temp = head;
  while (temp->next != head)
  {
    prevnode = temp;
    temp = temp->next;
  }
  prevnode->next = head;
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
    deleteBegin();
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

void display()
{
  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }

  printf("List:\n");
  temp = head;
  do
  {
    printf("%d\t", temp->data);
    temp = temp->next;
  } while (temp != head);
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