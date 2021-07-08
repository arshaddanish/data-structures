#include <stdio.h>
#define SIZE 5

struct priorityQ
{
  int item;
  int prio;
};
struct priorityQ PQ[SIZE];
int front = -1, rear = -1;

void sort()
{
  struct priorityQ temp;
  int k = 0;
  for (int i = front; i < rear; i++)
  {
    for (int j = front; j < rear - k; j++)
    {
      if (PQ[j].prio < PQ[j + 1].prio)
      {
        temp = PQ[j];
        PQ[j] = PQ[j + 1];
        PQ[j + 1] = temp;
      }
    }
    k++;
  }
}

void enqueue()
{
  if (rear == SIZE - 1)
  {
    printf("Queue overflow\n");
    return;
  }

  struct priorityQ temp;
  printf("Enter item & its priority\n");
  scanf("%d%d", &temp.item, &temp.prio);
  if (front == -1)
    front = 0;
  PQ[++rear] = temp;

  sort();
}

void dequeue()
{
  if (front == -1)
  {
    printf("Queue underflow\n");
    return;
  }

  printf("Deleted item: %d  Priority: %d\n", PQ[front].item, PQ[front].prio);
  if (front == rear)
    front = rear = -1;
  else
    front++;
}

void display()
{
  if (front == -1)
  {
    printf("Queue is empty\n");
    return;
  }

  printf("Queue(Item, Priority):\n");
  for (int i = front; i <= rear; i++)
  {
    printf("%d\t%d\n", PQ[i].item, PQ[i].prio);
  }
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