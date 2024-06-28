#include <stdio.h>
#define MAX 100
#define NOT_VISITED 0
#define CURRENT 1
#define VISITED 2

int count, time;
int matrix[MAX][MAX];
int status[MAX], first_visit_at[MAX], finish_visit_at[MAX];

void visit(int id)
{
  status[id] = CURRENT;
  time += 1;
  first_visit_at[id] = time;

  for (int i = 0; i < count; i++)
  {
    if (matrix[id][i] == 0)
    {
      continue;
    }

    if (status[i] == NOT_VISITED)
    {
      visit(i);
    }
  }
  status[id] = VISITED;
  time += 1;
  finish_visit_at[id] = time;
}

void dfs()
{
  for (int i = 0; i < count; i++)
  {
    status[i] = NOT_VISITED;
  }
  time = 0;

  for (int i = 0; i < count; i++)
  {
    if (status[i] == NOT_VISITED)
    {
      visit(i);
    }
  }

  for (int i = 0; i < count; i++)
  {
    printf("%d %d %d\n", i + 1, first_visit_at[i], finish_visit_at[i]);
  }
}

int main()
{
  scanf("%d", &count);

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
  
  dfs();

  return 0;
}
