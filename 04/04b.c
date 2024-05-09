#include <stdio.h>

int binarySearch(int array[], int n, int target)
{
  int left = 0, right = n - 1, count = 0;

  while (left <= right)
  {
    int mid = left + (right - left) / 2;

    if (array[mid] == target)
    {
      count++;
      break;
    }
    else if (array[mid] < target)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }

  return count;
}

int main()
{
  int n, q;
  scanf("%d", &n);
  int sArray[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &sArray[i]);
  }

  scanf("%d", &q);
  int tArray[q];
  for (int i = 0; i < q; i++)
  {
    scanf("%d", &tArray[i]);
  }

  int match = 0;
  for (int i = 0; i < q; i++)
  {
    match += binarySearch(sArray, n, tArray[i]);
  }

  printf("%d\n", match);

  return 0;
}
