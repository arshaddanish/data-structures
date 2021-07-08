#include <stdio.h>

void selectionSort(int *arr, int n)
{
  int min, temp;
  for (int i = 0; i < n - 1; i++)
  {
    min = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[min])
        min = j;
    }
    if (min != i)
    {
      temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
    }
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

  selectionSort(arr, n);

  printf("Sorted array\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d\t", arr[i]);
  }
  printf("\n");
}