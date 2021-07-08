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

int isEmpty()
{
  if (top == -1)
  {
    return 1;
  }
  return 0;
}

int prio(char c)
{
  switch (c)
  {
  case '/':
  case '*':
    return 2;
  case '+':
  case '-':
    return 1;
  case '(':
    return 0;
  }
}

void convert(char *exp, char *post)
{
  int k = 0;
  for (int i = 0; i < strlen(exp); i++)
  {
    switch (exp[i])
    {
    case '(':
      push(exp[i]);
      break;

    case ')':
      while (stack[top] != '(')
      {
        post[k++] = pop();
      }
      pop();
      break;

    case '/':
    case '*':
    case '+':
    case '-':
      while (!isEmpty() && prio(exp[i]) <= prio(stack[top]))
      {
        post[k++] = pop();
      }
      push(exp[i]);
      break;

    default:
      post[k++] = exp[i];
    }
  }

  while (!isEmpty())
  {
    post[k++] = pop();
  }
  post[k] = '\0';
}

void evaluate(char *post)
{
  int x, y;
  for (int i = 0; i < strlen(post); i++)
  {
    switch (post[i])
    {
    case '/':
      y = pop() - '0';
      x = pop() - '0';
      push(x / y + '0');
      break;

    case '*':
      y = pop() - '0';
      x = pop() - '0';
      push(x * y + '0');
      break;

    case '+':
      y = pop() - '0';
      x = pop() - '0';
      push(x + y + '0');
      break;

    case '-':
      y = pop() - '0';
      x = pop() - '0';
      push(x - y + '0');
      break;

    default:
      push(post[i]);
    }
  }
}

int main()
{
  char exp[20];
  printf("Enter expression\n");
  scanf("%[^\n]%*c", exp);

  char post[20] = "";
  convert(exp, post);
  printf("Postfix Expression: %s\n", post);

  evaluate(post);

  printf("Value: %d\n", stack[top] - '0');

  return 0;
}