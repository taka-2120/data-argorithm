#include <stdio.h>
#define MAX 100
#define UNDEFINED (1 << 21)
#define NOT_VISITED 0
#define CURRENT 1
#define VISITED 2

int size;
int matrix[MAX][MAX];

int prim()
{
  int current, minCost;
  int status[MAX], weight[MAX], parent[MAX];

  for (int i = 0; i < size; i++)
  {
    status[i] = NOT_VISITED;
    parent[i] = -1;
    weight[i] = UNDEFINED;
  }

  // The cost to reach to parent is Zero
  weight[0] = 0;

  while (1)
  {
    minCost = UNDEFINED;
    current = -1;

    for (int i = 0; i < size; i++)
    {
      if (minCost > weight[i] && status[i] != VISITED)
      {
        current = i;
        minCost = weight[i];
      }
    }

    if (current == -1)
    {
      break;
    }

    status[current] = VISITED;

    for (int i = 0; i < size; i++)
    {
      if (status[i] != VISITED && matrix[current][i] != UNDEFINED)
      {
        if (weight[i] > matrix[current][i])
        {
          weight[i] = matrix[current][i];
          parent[i] = current;
          status[i] = CURRENT;
        }
      }
    }
  }

  int sum = 0;
  for (int i = 0; i < size; i++)
  {
    if (parent[i] != -1)
    {
      sum += matrix[i][parent[i]];
    }
  }

  return sum;
}

int main()
{
  scanf("%d", &size);

  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      int value;
      scanf("%d", &value);
      matrix[i][j] = value == -1 ? UNDEFINED : value;
    }
  }

  printf("%d\n", prim());

  return 0;
}
