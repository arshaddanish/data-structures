#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int *arr, int n, int i)
{
  int largest, l, r;
  largest = i;
  l = 2 * i;
  r = 2 * i + 1;

  if (l <= n && arr[l] > arr[largest])
    largest = l;
  if (r <= n && arr[r] > arr[largest])
    largest = r;

  if (largest != i)
  {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
  }
}

void display(int *arr, int n)
{
  for (int i = 1; i <= n; i++)
  {
    printf("%d\t", arr[i]);
  }
  printf("\n");
}

void heapSort(int *arr, int n)
{
  for (int i = n / 2; i >= 1; i--)
  {
    heapify(arr, n, i);
  }
  printf("Heap:\n");
  display(arr, n);

  for (int i = n; i > 1; i--)
  {
    swap(&arr[1], &arr[i]);
    heapify(arr, i - 1, 1);
  }
  printf("Sorted array:\n");
  display(arr, n);
}

void main()
{
  int n, arr[100];
  printf("Enter array size\n");
  scanf("%d", &n);
  printf("Enter array elements\n");
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &arr[i]);
  }

  heapSort(arr, n);
}