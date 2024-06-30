#include <stdio.h>

int main()
{
  int count;
  scanf("%d", &count);

  int array[count];
  for (int i = 0; i < count; i++)
  {
    scanf("%d", &array[i]);
  }

  // Insertion Sort
  for (int i = 1; i < count; i++)
  {
    int key = array[i];
    int j = i - 1;

    while (j >= 0 && array[j] > key)
    {
      array[j + 1] = array[j];
      j -= 1;
    }
    array[j + 1] = key;


    // Print
    for (int k = 0; k < count; k++)
    {
      if (k != 0) {
        printf(" ");
      }
      printf("%d", array[k]);
    }
    printf("\n");
  }
  return 0;
}
