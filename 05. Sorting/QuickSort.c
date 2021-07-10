#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int *arr, int low, int high)
{
  int pivot, i, j;
  pivot = low;
  i = low;
  j = high;

  while (i < j)
  {
    while (arr[i] <= arr[pivot] && i < high)
      i++;
    while (arr[j] > arr[pivot])
      j--;
    if (i < j)
      swap(&arr[i], &arr[j]);
  }
  swap(&arr[pivot], &arr[j]);

  return j;
}

void quickSort(int *arr, int low, int high)
{
  if (low < high)
  {
    int p = partition(arr, low, high);
    quickSort(arr, low, p - 1);
    quickSort(arr, p + 1, high);
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

  quickSort(arr, 0, n - 1);

  printf("Sorted array\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d\t", arr[i]);
  }
  printf("\n");
}