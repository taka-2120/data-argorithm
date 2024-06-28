#include <stdio.h>
#define MAX 100

int main()
{
  int count;
  scanf("%d", &count);

  int matrix[MAX][MAX];
  for (int i = 0; i < count; i++)
  {
    for (int j = 0; j < count; j++)
    {
      matrix[i][j] = 0;
    }
  }

  for (int i = 0; i < count; i++)
  {
    int key, links;
    scanf("%d %d", &key, &links);
    key -= 1;

    for (int j = 0; j < links; j++)
    {
      int node;
      scanf("%d", &node);
      node -= 1;
      matrix[key][node] = 1;
    }
  }

  for (int i = 0; i < count; i++)
  {
    for (int j = 0; j < count; j++)
    {
      if (j != count && j != 0)
      {
        printf(" ");
      }
      printf("%d", matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}
