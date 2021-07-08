#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
} *front = NULL, *rear, *newnode, *temp;

void enqueue()
{
  newnode = (struct node *)malloc(sizeof(struct node));
  printf("Enter item\n");
  scanf("%d", &newnode->data);
  newnode->next = NULL;

  if (front == NULL)
  {
    front = rear = newnode;
  }
  else
  {
    rear->next = newnode;
    rear = newnode;
  }
}

void dequeue()
{
  if (front == NULL)
  {
    printf("Queue underflow\n");
    return;
  }

  printf("Deleted item: %d\n", front->data);
  temp = front;
  front = front->next;
  free(temp);
}

void display()
{
  printf("Queue:\n");
  temp = front;
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
    printf("1 - Enqueue\n");
    printf("2 - Dequeue\n");
    printf("0 - Exit\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      enqueue();
      display();
      break;

    case 2:
      dequeue();
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