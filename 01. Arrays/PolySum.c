#include <stdio.h>

struct poly
{
  int coef;
  int exp;
};
struct poly p1[20], p2[20], p3[40];
int m, n, i, j, k;

void read(struct poly *p, int *size)
{
  printf("Enter no of terms\n");
  scanf("%d", size);
  printf("Enter coefficient & exponent of each term\n");
  for (i = 0; i < *size; i++)
  {
    printf("Term %d: ", i + 1);
    scanf("%d%d", &p[i].coef, &p[i].exp);
  }
}

void addPoly()
{
  i = j = k = 0;
  while (i < m && j < n)
  {
    if (p1[i].exp == p2[j].exp)
    {
      p3[k].exp = p1[i].exp;
      p3[k++].coef = p1[i++].coef + p2[j++].coef;
    }
    else if (p1[i].exp > p2[j].exp)
    {
      p3[k++] = p1[i++];
    }
    else
    {
      p3[k++] = p2[j++];
    }
  }
  while (i < m)
  {
    p3[k++] = p1[i++];
  }
  while (j < n)
  {
    p3[k++] = p2[j++];
  }
}

void display(struct poly *p, int size)
{
  for (i = 0; i < size - 1; i++)
  {
    printf("%dx^%d + ", p[i].coef, p[i].exp);
  }
  printf("%dx^%d\n", p[size - 1].coef, p[size - 1].exp);
}

void main()
{
  printf("Polynomial 1:\n");
  read(p1, &m);
  printf("Polynomial 2:\n");
  read(p2, &n);

  addPoly();
  printf("Polynomial 1:\n");
  display(p1, m);
  printf("Polynomial 2:\n");
  display(p2, n);
  printf("Resultant polynomial:\n");
  display(p3, k);
}