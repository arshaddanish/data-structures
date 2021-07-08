#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

void push()
{
  if (top == SIZE - 1)
  {
    printf("Stack overflow\n");
    return;
  }

  int item;
  printf("Enter item\n");
  scanf("%d", &item);
  stack[++top] = item;
}

void pop()
{
  if (top == -1)
  {
    printf("Stack underflow\n");
    return;
  }

  printf("Popped item: %d\n", stack[top]);
  top--;
}

void display()
{
  printf("Stack:\n");
  for (int i = top; i >= 0; i--)
  {
    printf("%d\t", stack[i]);
  }
  printf("\n");
}

int main()
{
  int ch = -1;

  while (ch != 0)
  {
    printf("1 - Push\n");
    printf("2 - Pop\n");
    printf("0 - Exit\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      push();
      display();
      break;

    case 2:
      pop();
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