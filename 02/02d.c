#include <stdio.h>
#include <math.h>

#define MAXN 1000000

long long count = 0;

void insertionSort(int A[], int n, int g)
{
  for (int i = g; i < n; i++)
  {
    int v = A[i];
    int j = i - g;
    while (j >= 0 && A[j] > v)
    {
      A[j + g] = A[j];
      j = j - g;
      count++;
    }
    A[j + g] = v;
  }
}

void shellSort(int A[], int n)
{
  int m = 0;
  int G[100];

  for (int h = 1; h <= n; h = 3 * h + 1)
  {
    G[m] = h;
    m++;
  }

  for (int i = 0; i < m / 2; i++)
  {
    int temp = G[i];
    G[i] = G[m - i - 1];
    G[m - i - 1] = temp;
  }

  printf("%d\n", m);
  for (int i = 0; i < m; i++)
  {
    if (i > 0)
      printf(" ");
    printf("%d", G[i]);
  }
  printf("\n");

  for (int i = 0; i < m; i++)
  {
    insertionSort(A, n, G[i]);
  }
}

int main(void)
{
  int n;
  scanf("%d", &n);

  int A[MAXN];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }

  shellSort(A, n);

  printf("%lld\n", count);
  for (int i = 0; i < n; i++)
  {
    printf("%d\n", A[i]);
  }

  return 0;
}
