#include <stdio.h>

int binarySearch(int arr[], int n, int target)
{
  int left = 0, right = n - 1, count = 0;

  while (left <= right)
  {
    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
    {
      count++;
      break;
    }

    else if (arr[mid] < target)
      left = mid + 1;

    else
      right = mid - 1;
  }

  return count;
}

int main()
{
  int n, q;
  scanf("%d", &n);
  int S[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  int T[q];
  for (int i = 0; i < q; i++)
  {
    scanf("%d", &T[i]);
  }

  int count = 0;
  for (int i = 0; i < q; i++)
  {
    count += binarySearch(S, n, T[i]);
  }

  printf("%d\n", count);

  return 0;
}
