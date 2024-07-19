#include <stdio.h>

void selectionSort(int A[], int N, int *swap_count)
{
  *swap_count = 0;

  for (int i = 0; i < N - 1; i++)
  {
    int mini = i;
    for (int j = i + 1; j < N; j++)
    {
      if (A[j] < A[mini])
      {
        mini = j;
      }
    }

    if (i != mini)
    {
      int temp = A[i];
      A[i] = A[mini];
      A[mini] = temp;
      (*swap_count)++;
    }
  }
}

int main(void)
{
  int n;

  scanf("%d", &n);
  int A[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }

  int swap_count;
  selectionSort(A, n, &swap_count);

  for (int i = 0; i < n; i++)
  {
    if (i > 0)
    {
      printf(" ");
    }
    printf("%d", A[i]);
  }
  printf("\n");

  printf("%d\n", swap_count);

  return 0;
}
