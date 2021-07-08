#include <stdio.h>
#include <string.h>
#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char c)
{
  if (top == SIZE - 1)
  {
    printf("Stack overflow\n");
    return;
  }

  stack[++top] = c;
}

char pop()
{
  if (top == -1)
  {
    printf("Stack underflow\n");
    return 0;
  }

  return stack[top--];
}

int main()
{
  char exp[20];
  printf("Enter expression\n");
  scanf("%[^\n]%*c", exp);

  int x, y;
  for (int i = strlen(exp) - 1; i >= 0; i--)
  {
    switch (exp[i])
    {
    case '/':
      x = pop() - '0';
      y = pop() - '0';
      push(x / y + '0');
      break;

    case '*':
      x = pop() - '0';
      y = pop() - '0';
      push(x * y + '0');
      break;

    case '+':
      x = pop() - '0';
      y = pop() - '0';
      push(x + y + '0');
      break;

    case '-':
      x = pop() - '0';
      y = pop() - '0';
      push(x - y + '0');
      break;

    default:
      push(exp[i]);
    }
  }

  printf("Value: %d\n", stack[top] - '0');

  return 0;
}