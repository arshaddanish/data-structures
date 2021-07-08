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
    printf("Stack uderflow\n");
    return 0;
  }

  return stack[top--];
}

int main()
{
  char str[20];
  printf("Enter a string\n");
  scanf("%[^\n]%*c", str);

  for (int i = 0; i < strlen(str); i++)
  {
    push(str[i]);
  }

  for (int i = 0; i < strlen(str); i++)
  {
    str[i] = pop();
  }

  printf("Reversed string: %s\n", str);

  return 0;
}