#include <stdio.h>
#include <stdlib.h>

struct node
{
  int coef;
  int exp;
  struct node *next;
} *p1 = NULL, *p2 = NULL, *p3 = NULL, *t1, *t2, *t3, *newnode;

void readPoly(struct node **p)
{
  int n;
  printf("Enter no of terms\n");
  scanf("%d", &n);
  printf("Enter coefficient and exponent of each term\n");
  for (int i = 0; i < n; i++)
  {
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Term %d: ", i + 1);
    scanf("%d%d", &newnode->coef, &newnode->exp);
    newnode->next = NULL;

    if (*p == NULL)
    {
      *p = t1 = newnode;
    }
    else
    {
      t1->next = newnode;
      t1 = newnode;
    }
  }
}

void createNode(int coef, int exp)
{
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->coef = coef;
  newnode->exp = exp;
  newnode->next = NULL;

  if (p3 == NULL)
  {
    p3 = t3 = newnode;
  }
  else
  {
    t3->next = newnode;
    t3 = newnode;
  }
}

void addPoly()
{
  t1 = p1;
  t2 = p2;
  while (t1 && t2)
  {
    if (t1->exp == t2->exp)
    {
      createNode(t1->coef + t2->coef, t1->exp);
      t1 = t1->next;
      t2 = t2->next;
    }
    else if (t1->exp > t2->exp)
    {
      createNode(t1->coef, t1->exp);
      t1 = t1->next;
    }
    else
    {
      createNode(t2->coef, t2->exp);
      t2 = t2->next;
    }
  }
  while (t1)
  {
    createNode(t1->coef, t1->exp);
    t1 = t1->next;
  }
  while (t2)
  {
    createNode(t2->coef, t2->exp);
    t2 = t2->next;
  }
}

void displayPoly(struct node *p)
{
  while (p->next)
  {
    printf("%dx^%d + ", p->coef, p->exp);
    p = p->next;
  }
  printf("%dx^%d\n", p->coef, p->exp);
}

void main()
{
  printf("Polynomial 1\n");
  readPoly(&p1);
  printf("Polynomial 2\n");
  readPoly(&p2);

  addPoly();

  printf("Polynomial 1\n");
  displayPoly(p1);
  printf("Polynomial 2\n");
  displayPoly(p2);
  printf("Resultant polynomial\n");
  displayPoly(p3);
}
