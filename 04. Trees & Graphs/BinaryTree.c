#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
} *root = NULL;

struct node *createTree()
{
  int data;
  scanf("%d", &data);
  if (data == -1)
    return NULL;
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = data;
  printf("Enter left child of %d\n", newnode->data);
  newnode->left = createTree();
  printf("Enter right child of %d\n", newnode->data);
  newnode->right = createTree();
  return newnode;
}

void preorder(struct node *temp)
{
  if (temp == NULL)
    return;
  printf("%d\t", temp->data);
  preorder(temp->left);
  preorder(temp->right);
}

void inorder(struct node *temp)
{
  if (temp == NULL)
    return;
  inorder(temp->left);
  printf("%d\t", temp->data);
  inorder(temp->right);
}

void postorder(struct node *temp)
{
  if (temp == NULL)
    return;
  postorder(temp->left);
  postorder(temp->right);
  printf("%d\t", temp->data);
}

void main()
{
  printf("Enter root\n");
  root = createTree();

  printf("Preorder:\t");
  preorder(root);
  printf("\n");
  printf("Inorder:\t");
  inorder(root);
  printf("\n");
  printf("Postorder:\t");
  postorder(root);
  printf("\n");
}