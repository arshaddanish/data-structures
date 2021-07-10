#include <stdio.h>

void merge(int *arr, int low, int mid, int high)
{
  int temp[high + 1];
  int i, j, k;
  i = low;
  j = mid + 1;
  k = low;

  while (i <= mid && j <= high)
  {
    if (arr[i] <= arr[j])
      temp[k++] = arr[i++];
    else
      temp[k++] = arr[j++];
  }
  while (i <= mid)
  {
    temp[k++] = arr[i++];
  }
  while (j <= high)
  {
    temp[k++] = arr[j++];
  }

  for (int i = low; i <= high; i++)
  {
    arr[i] = temp[i];
  }
}

void mergeSort(int *arr, int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
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

  mergeSort(arr, 0, n - 1);

  printf("Sorted array\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d\t", arr[i]);
  }
  printf("\n");
}