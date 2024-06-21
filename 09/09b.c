#include <stdio.h>

int left(int index)
{
  return index * 2;
}

int right(int index)
{
  return index * 2 + 1;
}

void maxHeapify(int tree[], int index, int size)
{
  int l = left(index);
  int r = right(index);
  int largest;

  if (l <= size && tree[l] > tree[index])
  {
    largest = l;
  }
  else
  {
    largest = index;
  }
  if (r <= size && tree[r] > tree[largest])
  {
    largest = r;
  }

  if (largest != index)
  {
    int tmp = tree[index];
    tree[index] = tree[largest];
    tree[largest] = tmp;

    maxHeapify(tree, largest, size);
  }
}

void buildMaxHeap(int tree[], int size)
{
  for (int i = size / 2; i >= 1; i--)
  {
    maxHeapify(tree, i, size);
  }
}

int main()
{
  int size;
  scanf("%d", &size);

  int tree[size + 1];

  for (int i = 1; i <= size; i++)
  {
    scanf("%d", &tree[i]);
  }

  buildMaxHeap(tree, size);

  for (int i = 1; i <= size; i++)
  {
    printf(" %d", tree[i]);
  }

  printf("\n");

  return 0;
}
