#include <stdio.h>
#define SIZE 5

int Q[SIZE];
int front = -1, rear = -1;

void enqueue()
{
  if ((rear + 1) % SIZE == front)
  {
    printf("Queue overflow\n");
    return;
  }

  int item;
  printf("Enter item\n");
  scanf("%d", &item);
  if (front == -1)
    front = 0;
  rear = (rear + 1) % SIZE;
  Q[rear] = item;
}

void dequeue()
{
  if (front == -1)
  {
    printf("Queue underflow\n");
    return;
  }

  printf("Deleted item: %d\n", Q[front]);
  if (front == rear)
    front = rear = -1;
  else
    front = (front + 1) % SIZE;
}

void display()
{
  if (front == -1)
  {
    printf("Queue is empty\n");
    return;
  }

  printf("Queue:\n");
  for (int i = front; i != rear; i = (i + 1) % SIZE)
  {
    printf("%d\t", Q[i]);
  }
  printf("%d\n", Q[rear]);
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