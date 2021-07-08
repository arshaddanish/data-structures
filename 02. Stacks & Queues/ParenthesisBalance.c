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

void pop()
{
  if (top == -1)
  {
    printf("Stack underflow\n");
    return;
  }

  top--;
}

int isEmpty()
{
  if (top == -1)
  {
    return 1;
  }
  return 0;
}

int match(char c)
{
  if (c == '}' && stack[top] == '{' || c == ']' && stack[top] == '[' || c == ')' && stack[top] == '(')
  {
    return 1;
  }
  return 0;
}

void main()
{
  char exp[20];
  printf("Enter expression\n");
  scanf("%[^\n]%*c", exp);

  for (int i = 0; i < strlen(exp); i++)
  {
    if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
    {
      push(exp[i]);
    }
    else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
    {
      if (!isEmpty() && match(exp[i]))
      {
        pop();
      }
      else
      {
        printf("Parenthesis are not balanced\n");
        return;
      }
    }
  }

  if (isEmpty())
  {
    printf("Parenthesis are balanced\n");
  }
  else
  {
    printf("Parenthesis are not balanced\n");
  }
}