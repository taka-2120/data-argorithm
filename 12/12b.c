#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 100
#define INF INT_MAX

typedef struct
{
  int v, weight;
} Edge;

typedef struct
{
  Edge edges[MAXN];
  int size;
} AdjList;

AdjList adj[MAXN];
int dist[MAXN];
int n;

void dijkstra(int src)
{
  int visited[MAXN] = {0};
  for (int i = 0; i < n; i++)
  {
    dist[i] = INF;
  }
  dist[src] = 0;

  for (int i = 0; i < n; i++)
  {
    int u = -1;
    for (int j = 0; j < n; j++)
    {
      if (!visited[j] && (u == -1 || dist[j] < dist[u]))
      {
        u = j;
      }
    }

    if (dist[u] == INF)
      break;

    visited[u] = 1;

    for (int j = 0; j < adj[u].size; j++)
    {
      int v = adj[u].edges[j].v;
      int weight = adj[u].edges[j].weight;

      if (dist[u] + weight < dist[v])
      {
        dist[v] = dist[u] + weight;
      }
    }
  }
}

int main()
{
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    int u, k;
    scanf("%d %d", &u, &k);
    adj[u].size = k;

    for (int j = 0; j < k; j++)
    {
      int v, c;
      scanf("%d %d", &v, &c);
      adj[u].edges[j].v = v;
      adj[u].edges[j].weight = c;
    }
  }

  dijkstra(0);

  for (int i = 0; i < n; i++)
  {
    printf("%d %d\n", i, dist[i]);
  }

  return 0;
}
