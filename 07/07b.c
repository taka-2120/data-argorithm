#include <stdio.h>

#define MAX 25
#define NIL -1

struct Node
{
  int parent;
  int left;
  int right;
} typedef Node;

Node tree[MAX];

void init(int count)
{
  for (int i = 0; i < count; i++)
  {
    tree[i].parent = tree[i].left = tree[i].right = NIL;
  }
}

int main()
{
  int count;
  scanf("%d", &count);

  init(count);

  for (int i = 0; i < count; i += 1)
  {
    int parent, left, right;
    scanf("%d %d %d", &parent, &left, &right);

    tree[i].parent = parent;
    tree[i].left = left;
    tree[i].right = right;
  }
  return 0;
}
