#include <stdio.h>

int M[5][5], r, c;
struct tuple
{
  int row;
  int col;
  int val;
} tup[20], tr[20];

void readMatrix()
{
  printf("Enter no of rows & columns\n");
  scanf("%d%d", &r, &c);
  printf("Enter elements\n");
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      scanf("%d", &M[i][j]);
    }
  }
}

void tuple()
{
  tup[0].row = r;
  tup[0].col = c;
  int k = 1;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (M[i][j] != 0)
      {
        tup[k].row = i;
        tup[k].col = j;
        tup[k++].val = M[i][j];
      }
    }
  }
  tup[0].val = k - 1;
}

void transpose()
{
  tr[0].row = tup[0].col;
  tr[0].col = tup[0].row;
  tr[0].val = tup[0].val;
  int k = 1;
  for (int i = 0; i < tup[0].col; i++)
  {
    for (int j = 1; j <= tup[0].val; j++)
    {
      if (tup[j].col == i)
      {
        tr[k].row = tup[j].col;
        tr[k].col = tup[j].row;
        tr[k++].val = tup[j].val;
      }
    }
  }
}

void displayMatrix()
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

void displayTuple(struct tuple *tup)
{
  printf("row\tcol\tval\n");
  for (int i = 0; i <= tup[0].val; i++)
  {
    printf("%d\t%d\t%d\n", tup[i].row, tup[i].col, tup[i].val);
  }
}

void main()
{
  printf("Enter matrix\n");
  readMatrix();
  tuple();
  transpose();
  printf("Matrix in normal form\n");
  displayMatrix();
  printf("Matrix in tuple form\n");
  displayTuple(tup);
  printf("Transpose matrix in tuple form\n");
  displayTuple(tr);
}