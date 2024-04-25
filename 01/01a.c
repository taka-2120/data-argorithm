#include <stdio.h>

void printArray(int arr[], int length)
{
  for (int i = 0; i < length; i++)
  {
    printf(i == length - 1 ? "%d\n" : "%d ", arr[i]);
  }
}

void insertionSort(int arr[], int length)
{
  printArray(arr, length);
  for (int i = 1; i < length; i++)
  {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }

    arr[j + 1] = key;
    printArray(arr, length);
  }
}

int main()
{
  int length;
  scanf("%d", &length);

  int arr[length];
  for (int i = 0; i < length; i++)
  {
    scanf("%d", &arr[i]);
  }

  insertionSort(arr, length);

  return 0;
}