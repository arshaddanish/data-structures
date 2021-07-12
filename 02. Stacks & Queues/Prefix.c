#include <stdio.h>
#include <string.h>
#include <math.h>
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

int isEmpty()
{
  return top == -1 ? 1 : 0;
}

int ICP(char c)
{
  switch (c)
  {
  case '+':
  case '-':
    return 2;
  case '/':
  case '*':
    return 4;
  case '^':
    return 5;
  case '(':
    return 7;
  }
}

int ISP(char c)
{
  switch (c)
  {
  case '(':
    return 0;
  case '+':
  case '-':
    return 1;
  case '/':
  case '*':
    return 3;
  case '^':
    return 6;
  }
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

void reverse(char *exp)
{
  for (int i = 0; i < strlen(exp); i++)
  {
    if (exp[i] == '(')
      push(')');
    else if (exp[i] == ')')
      push('(');
    else
      push(exp[i]);
  }

  for (int i = 0; i < strlen(exp); i++)
  {
    exp[i] = pop();
  }
}

void convert(char *exp, char *pre)
{
  int k = 0;
  for (int i = 0; i < strlen(exp); i++)
  {
    switch (exp[i])
    {
    case ')':
      while (stack[top] != '(')
      {
        pre[k++] = pop();
      }
      pop();
      break;

    case '(':
    case '+':
    case '-':
    case '/':
    case '*':
    case '^':
      while (!isEmpty() && ICP(exp[i]) < ISP(stack[top]))
      {
        pre[k++] = pop();
      }
      push(exp[i]);
      break;

    default:
      pre[k++] = exp[i];
    }
  }

  while (!isEmpty())
  {
    pre[k++] = pop();
  }
  pre[k] = '\0';
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
    case '+':
      push(x + y + '0');
      break;

    case '-':
      push(x - y + '0');
      break;

    case '/':
      push(x / y + '0');
      break;

    case '*':
      push(x * y + '0');
      break;

    case '^':
      push(pow(x, y) + '0');
      break;

    default:
      push(pre[i]);
    }
  }
}

int main()
{
  char exp[20], pre[20];
  printf("Enter expression\n");
  scanf("%[^\n]%*c", exp);

  reverse(exp);
  convert(exp, pre);
  reverse(pre);
  printf("Prefix expression\n");
  printf("%s\n", pre);

  evaluate(pre);
  printf("Value: %d\n", stack[top] - '0');

  return 0;
}