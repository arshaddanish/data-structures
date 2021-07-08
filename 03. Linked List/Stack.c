#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
} *top = NULL, *newnode, *temp;

void push()
{
  newnode = (struct node *)malloc(sizeof(struct node));
  printf("Enter item\n");
  scanf("%d", &newnode->data);
  newnode->next = top;
  top = newnode;
}

void pop()
{
  if (top == NULL)
  {
    printf("Stack underflow\n");
    return;
  }

  printf("Popped item: %d\t", top->data);
  temp = top;
  top = top->next;
  free(temp);
}

void display()
{
  printf("Stack:\n");
  temp = top;
  while (temp != NULL)
  {
    printf("%d\t", temp->data);
    temp = temp->next;
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

  return 0;
}