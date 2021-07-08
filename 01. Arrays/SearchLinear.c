#include <stdio.h>

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

  printf("Enter item to be searched\n");
  scanf("%d", &key);
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == key)
    {
      printf("Item found at index %d\n", i);
      return;
    }
  }
  printf("Item not found\n");
}