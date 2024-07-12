#include <stdio.h>

void bubbleSort(int A[], int n, int *swap_count)
{
  *swap_count = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = n - 1; j > i; j--)
    {
      if (A[j] < A[j - 1])
      {
        // Swap A[j] and A[j - 1]
        int temp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = temp;
        (*swap_count)++;
      }
    }
  }
}

int main()
{
  int N;
  scanf("%d", &N);

  int A[N];
  for (int i = 0; i < N; i++)
  {
    scanf("%d", &A[i]);
  }

  int swap_count;
  bubbleSort(A, N, &swap_count);

  for (int i = 0; i < N; i++)
  {
    printf("%d", A[i]);
    if (i < N - 1)
    {
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n", swap_count);

  return 0;
}
