#include <stdio.h>
#define SIZE 5

int Q[SIZE];
int front = -1, rear = -1;

void insertFront()
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
    front = rear = 0;
  else
    front = (front - 1 + SIZE) % SIZE;
  Q[front] = item;
}

void insertRear()
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

void deleteFront()
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

void deleteRear()
{
  if (front == -1)
  {
    printf("Queue underflow\n");
    return;
  }

  printf("Deleted item: %d\n", Q[rear]);
  if (front == rear)
    front = rear = -1;
  else
    rear = (rear - 1 + SIZE) % SIZE;
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
    printf("1 - Insert at front\n");
    printf("2 - Insert at rear\n");
    printf("3 - Delete from front\n");
    printf("4 - Delete from rear\n");
    printf("0 - Exit\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      insertFront();
      display();
      break;

    case 2:
      insertRear();
      display();
      break;

    case 3:
      deleteFront();
      display();
      break;

    case 4:
      deleteRear();
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