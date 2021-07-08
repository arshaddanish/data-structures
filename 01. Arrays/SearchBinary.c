#include <stdio.h>

void sort(int *arr, int n)
{
  int temp;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1 - i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  printf("Sorted array\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d\t", arr[i]);
  }
  printf("\n");
}

void main()
{
  int n, arr[100], key;
  printf("Enter array size\n");
  scanf("%d", &n);
  printf("Enter array\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  sort(arr, n);

  printf("Enter item to be searched\n");
  scanf("%d", &key);
  int low, mid, high;
  low = 0;
  high = n - 1;
  while (low <= high)
  {
    mid = (low + high) / 2;
    if (arr[mid] == key)
    {
      printf("Item found at index %d\n", mid);
      return;
    }
    if (arr[mid] < key)
      low = mid + 1;
    else
      high = mid - 1;
  }

  printf("Item not found\n");
}