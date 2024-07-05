#include <iostream>
#include <queue>
using namespace std;

static const int MAX = 100;
static const int INFTY = (1 << 21);

int node_count;
int matrix[MAX][MAX];
int node_distance[MAX];

void bfs(int val)
{
  queue<int> queue;
  queue.push(val);

  for (int i = 0; i < node_count; i++)
  {
    node_distance[i] = INFTY;
  }

  node_distance[val] = 0;

  int current;
  while (!queue.empty())
  {
    current = queue.front();
    queue.pop();
    for (int i = 0; i < node_count; i++)
    {
      if (matrix[current][i] == 0)
      {
        continue;
      }

      if (node_distance[i] != INFTY)
      {
        continue;
      }

      node_distance[i] = node_distance[current] + 1;
      queue.push(i);
    }
  }

  for (int i = 0; i < node_count; i++)
  {
    cout << i + 1 << " " << (node_distance[i] == INFTY ? -1 : node_distance[i]) << endl;
  }
}

int main()
{
  cin >> node_count;

  for (int i = 0; i < node_count; i++)
  {
    for (int j = 0; j < node_count; j++)
    {
      matrix[i][j] = 0;
    }
  }

  for (int i = 0; i < node_count; i++)
  {
    int key, links;
    cin >> key >> links;
    key -= 1;

    for (int j = 0; j < links; j++)
    {
      int node;
      cin >> node;
      node -= 1;
      matrix[key][node] = 1;
    }
  }

  bfs(0);

  return 0;
}