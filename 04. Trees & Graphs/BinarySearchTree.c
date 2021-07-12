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

// .........

int max(int a, int b)
{
  return a > b ? a : b;
}

int height(struct node *temp)
{
  if (temp == NULL)
    return -1;
  return max(height(temp->left), height(temp->right)) + 1;
}

struct node *inorderPredecessor(struct node *temp)
{
  if (temp->right)
    return inorderPredecessor(temp->right);
  return temp;
}

struct node *inorderSuccessor(struct node *temp)
{
  if (temp->left)
    return inorderSuccessor(temp->left);
  return temp;
}

struct node *delete (struct node *temp, int data)
{
  if (temp == NULL)
    return NULL;
  if (data == temp->data)
  {
    if (temp->left == NULL && temp->right == NULL)
    {
      free(temp);
      return NULL;
    }
    if (height(temp->left) > height(temp->right))
    {
      struct node *pre = inorderPredecessor(temp->left);
      temp->data = pre->data;
      temp->left = delete (temp->left, pre->data);
    }
    else
    {
      struct node *suc = inorderSuccessor(temp->right);
      temp->data = suc->data;
      temp->right = delete (temp->right, suc->data);
    }
  }
  if (data < temp->data)
    temp->left = delete (temp->left, data);
  else
    temp->right = delete (temp->right, data);
  return temp;
}

// .........

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
      printf("Enter data\n");
      scanf("%d", &data);
      root = delete (root, data);
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