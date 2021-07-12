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

int isOperator(char c)
{
  switch (c)
  {
  case '+':
  case '-':
  case '/':
  case '*':
  case '^':
    return 1;
  }
  return 0;
}

void evaluate(char *pre)
{
  int x, y;
  for (int i = strlen(pre) - 1; i >= 0; i--)
  {
    if (isOperator(pre[i]))
    {
      x = pop() - '0';
      y = pop() - '0';
    }
    switch (pre[i])
    {
    case '/':
      push(x / y + '0');
      break;

    case '*':
      push(x * y + '0');
      break;

    case '+':
      push(x + y + '0');
      break;

    case '-':
      push(x - y + '0');
      break;

    default:
      push(pre[i]);
    }
  }
}

int main()
{
  char pre[20];
  printf("Enter prefix expression\n");
  scanf("%[^\n]%*c", pre);

  evaluate(pre);
  printf("Value: %d\n", stack[top] - '0');

  return 0;
}