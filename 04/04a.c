#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
  int sCount;
  scanf("%d", &sCount);
  int sArray[sCount];
  for (int i = 0; i < sCount; i++)
  {
    scanf("%d", &sArray[i]);
  }

  int tCount;
  scanf("%d", &tCount);
  int tArray[tCount];
  for (int i = 0; i < tCount; i++)
  {
    scanf("%d", &tArray[i]);
  }

  int capacity = 10;
  int *numbers = malloc(capacity * sizeof(int));
  int count = 0;
  for (int i = 0; i < sCount; i++)
  {
    int key = sArray[i];
    for (int j = 0; j < tCount; j++)
    {
      if (tArray[j] == key)
      {
        bool sameFound = false;
        for (int k = 0; k < count; k++)
        {
          if (numbers[k] == key)
          {
            sameFound = true;
            break;
          }
        }
        if (!sameFound)
        {
          if (count == capacity)
          {
            capacity *= 2;
            numbers = realloc(numbers, capacity * sizeof(int));
          }
          numbers[count] = key;
          count += 1;
        }
      }
    }
  }
  printf("%d\n", count);
  free(numbers);
  numbers = NULL;
  return 0;
}
