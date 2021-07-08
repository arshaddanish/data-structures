#include <stdio.h>

int A[5][5], B[5][5], r1, c1, r2, c2;
struct tuple
{
  int row;
  int col;
  int val;
} t1[20], t2[20], t3[20];

void readMatrix(int (*M)[5], int *r, int *c)
{
  printf("Enter no of rows & columns\n");
  scanf("%d%d", r, c);
  printf("Enter elements\n");
  for (int i = 0; i < *r; i++)
  {
    for (int j = 0; j < *c; j++)
    {
      scanf("%d", &M[i][j]);
    }
  }
}

void tuple(int (*M)[5], int r, int c, struct tuple *t)
{
  t[0].row = r;
  t[0].col = c;
  int k = 1;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (M[i][j] != 0)
      {
        t[k].row = i;
        t[k].col = j;
        t[k++].val = M[i][j];
      }
    }
  }
  t[0].val = k - 1;
}

void addSparse()
{
  if (t1[0].row != t2[0].row || t1[0].col != t2[0].col)
  {
    printf("Matrices are not compatible for addition\n");
    return;
  }

  t3[0].row = t1[0].row;
  t3[0].col = t1[0].col;
  int i, j, k;
  i = j = k = 1;
  while (i <= t1[0].val && j <= t2[0].val)
  {
    if (t1[i].row < t2[j].row)
    {
      t3[k++] = t1[i++];
    }
    else if (t1[i].row > t2[j].row)
    {
      t3[k++] = t2[j++];
    }
    else
    {
      if (t1[i].col < t2[j].col)
      {
        t3[k++] = t1[i++];
      }
      else if (t1[i].col > t2[j].col)
      {
        t3[k++] = t2[j++];
      }
      else
      {
        t3[k].row = t1[i].row;
        t3[k].col = t1[i].col;
        t3[k++].val = t1[i++].val + t2[j++].val;
      }
    }
  }
  while (i <= t1[0].val)
  {
    t3[k++] = t1[i++];
  }
  while (j <= t2[0].val)
  {
    t3[k++] = t2[j++];
  }
  t3[0].val = k - 1;
}

void displayMatrix(int (*M)[5], int r, int c)
{
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      printf("%d\t", M[i][j]);
    }
    printf("\n");
  }
}

void displayTuple(struct tuple *t)
{
  printf("row\tcol\tval\n");
  for (int i = 0; i <= t[0].val; i++)
  {
    printf("%d\t%d\t%d\n", t[i].row, t[i].col, t[i].val);
  }
}

void main()
{
  printf("Matrix 1\n");
  readMatrix(A, &r1, &c1);
  printf("Matrix 2\n");
  readMatrix(B, &r2, &c2);

  tuple(A, r1, c1, t1);
  tuple(B, r2, c2, t2);

  printf("Matrix 1 in normal form\n");
  displayMatrix(A, r1, c1);
  printf("Matrix 2 in normal form\n");
  displayMatrix(B, r2, c2);
  printf("Matrix 1 in tuple form\n");
  displayTuple(t1);
  printf("Matrix 2 in tuple form\n");
  displayTuple(t2);

  addSparse();
  if (t3[0].row)
  {
    printf("Resultant matrix in tuple form\n");
    displayTuple(t3);
  }
}