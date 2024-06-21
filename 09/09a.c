#include <stdio.h>
#define NIL -1

int parent(int index)
{
  return index / 2;
}
int left(int index)
{
  return index * 2;
}
int right(int index)
{
  return index * 2 + 1;
}

int main(void)
{
  int size;
  scanf("%d", &size);

  int tree[size + 1];

  for (int i = 1; i <= size; i++)
  {
    scanf("%d", &tree[i]);
  }

  for (int i = 1; i <= size; i++)
  {
    printf("node %d: key = %d, ", i, tree[i]);
    int p = parent(i);
    int l = left(i);
    int r = right(i);
    if (p <= size && p != 0)
    {
      printf("parent key = %d, ", tree[p]);
    }
    if (l <= size)
    {
      printf("left key = %d, ", tree[l]);
    }
    if (r <= size)
    {
      printf("right key = %d, ", tree[r]);
    }
    printf("\n");
  }

  return 0;
}