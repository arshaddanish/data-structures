#include <stdio.h>

void insertionSort(int *arr, int n)
{
  int x, j;
  for (int i = 1; i < n; i++)
  {
    x = arr[i];
    j = i - 1;
    while (j >= 0 && x < arr[j])
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = x;
  }
}

void main()
{
  int n, arr[100];
  printf("Enter array size\n");
  scanf("%d", &n);
  printf("Enter array elements\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  insertionSort(arr, n);

  printf("Sorted array\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d\t", arr[i]);
  }
  printf("\n");
}