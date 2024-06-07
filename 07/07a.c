#include <stdio.h>
#include <stdlib.h>

#define NIL -1
#define MAX 100000

struct Node
{
  int parent;
  int left;
  int right;
} typedef Node;

Node tree[MAX];
int depthList[MAX];

void getDepth(int index, int depth)
{
  depthList[index] = depth;
  if (tree[index].right != NIL)
  {
    getDepth(tree[index].right, depth);
  }
  if (tree[index].left != NIL)
  {
    getDepth(tree[index].left, depth + 1);
  }
}

void printTree(int count)
{
  for (int i = 0; i < count; i++)
  {
    printf("node %d: ", i);
    printf("parent = %d, ", tree[i].parent);
    printf("depth = %d, ", depthList[i]);

    if (tree[i].parent == NIL)
    {
      printf("root, ");
    }
    else if (tree[i].left == NIL)
    {
      printf("leaf, ");
    }
    else
    {
      printf("internal node, ");
    }

    printf("[");
    for (int j = 0, child = tree[i].left; child != NIL; j++, child = tree[child].right)
    {
      if (child != NIL && j != 0)
      {
        printf(", ");
      }
      printf("%d", child);
    }
    printf("]\n");
  }
}

int main()
{
  int size;
  scanf("%d", &size);
  for (int i = 0; i < size; i++)
  {
    tree[i].parent = tree[i].left = tree[i].right = NIL;
  }

  for (int i = 0; i < size; i++)
  {
    int parent, childCount, prevLeft;
    scanf("%d %d", &parent, &childCount);

    for (int c = 0; c < childCount; c++)
    {
      int child;
      scanf("%d", &child);

      if (c == 0)
      {
        tree[parent].left = child;
      }
      else
      {
        tree[prevLeft].right = child;
      }

      prevLeft = child;
      tree[prevLeft].parent = parent;
    }
  }

  int right = NIL;
  for (int i = 0; i < size; i++)
  {
    if (tree[i].parent == NIL)
    {
      right = i;
    }
  }
  getDepth(right, 0);
  printTree(size);

  return 0;
}
