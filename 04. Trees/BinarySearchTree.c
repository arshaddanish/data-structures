#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
} *root = NULL;

struct node *insert(struct node *temp, int data)
{
  if (temp == NULL)
  {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
  }
  if (data < temp->data)
    temp->left = insert(temp->left, data);
  else if (data > temp->data)
    temp->right = insert(temp->right, data);
  return temp;
}

struct node *search(struct node *temp, int data)
{
  if (temp == NULL)
    return NULL;
  if (data == temp->data)
    return temp;
  if (data < temp->data)
    return search(temp->left, data);
  else
    return search(temp->right, data);
}

void inorder(struct node *temp)
{
  if (temp == NULL)
    return;
  inorder(temp->left);
  printf("%d\t", temp->data);
  inorder(temp->right);
}

void main()
{
  int ch = -1, data;
  struct node *temp;

  while (ch != 0)
  {
    printf("1 - Insert\n");
    printf("2 - Delete\n");
    printf("3 - Search\n");
    printf("4 - Display\n");
    printf("0 - Exit\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      printf("Enter data\n");
      scanf("%d", &data);
      root = insert(root, data);
      break;

    case 2:
      break;

    case 3:
      printf("Enter data to be searched\n");
      scanf("%d", &data);
      temp = search(root, data);
      if (temp)
        printf("Data found\n");
      else
        printf("Data not found\n");
      break;

    case 4:
      printf("Inorder:\t");
      inorder(root);
      printf("\n");
      break;

    case 0:
      printf("Exited...\n");
      break;

    default:
      printf("Enter a valid choice\n");
    }
  }
}