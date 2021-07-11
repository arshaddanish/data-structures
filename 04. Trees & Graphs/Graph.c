#include <stdio.h>
#define SIZE 10

int n, M[10][10], Q[SIZE];
int front = -1, rear = -1;

void enqueue(int item)
{
  if (rear == SIZE - 1)
  {
    printf("Queue overflow\n");
    return;
  }

  if (front == -1)
    front = 0;
  Q[++rear] = item;
}

int dequeue()
{
  if (front == -1)
  {
    printf("Queue underflow\n");
    return 0;
  }

  int item = Q[front];
  if (front == rear)
    front = rear = -1;
  else
    front++;
  return item;
}

int isEmpty()
{
  return front == -1 ? 1 : 0;
}

void BFS(int start)
{
  int visited[10] = {0};

  printf("%d\t", start);
  visited[start] = 1;
  enqueue(start);

  while (!isEmpty())
  {
    int i = dequeue();
    for (int j = 1; j <= n; j++)
    {
      if (M[i][j] == 1 && visited[j] != 1)
      {
        printf("%d\t", j);
        visited[j] = 1;
        enqueue(j);
      }
    }
  }
}

void DFS(int i)
{
  static int visited[10] = {0};

  printf("%d\t", i);
  visited[i] = 1;
  for (int j = 1; j <= n; j++)
  {
    if (M[i][j] == 1 && visited[j] != 1)
      DFS(j);
  }
}

void main()
{
  printf("Enter no of vertices\n");
  scanf("%d", &n);
  printf("Enter adjacency matrix\n");
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      scanf("%d", &M[i][j]);
    }
  }

  printf("Breadth First Search:\n");
  BFS(1);
  printf("\n");

  printf("Depth First Search:\n");
  DFS(1);
  printf("\n");
}