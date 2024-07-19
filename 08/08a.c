#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int key;
  struct Node *parent, *left, *right;
} typedef Node;

Node *root, *NIL;

void insert(int key)
{
  Node *parent = NIL;
  Node *child = root;
  Node *current = malloc(sizeof(Node));

  current->key = key;
  current->left = NIL;
  current->right = NIL;
  current->parent = NIL;

  while (child != NIL)
  {
    parent = child;
    if (current->key < child->key)
    {
      child = child->left;
    }
    else
    {
      child = child->right;
    }
  }

  current->parent = parent;

  if (parent == NIL)
  {
    root = current;
  }
  else if (current->key < parent->key)
  {
    parent->left = current;
  }
  else
  {
    parent->right = current;
  }
}

void inOrder(Node *node)
{
  if (node == NIL)
  {
    return;
  }

  inOrder(node->left);
  printf(" %d", node->key);
  inOrder(node->right);
}

void preOrder(Node *node)
{
  if (node == NIL)
  {
    return;
  }

  printf(" %d", node->key);
  preOrder(node->left);
  preOrder(node->right);
}

int main()
{
  int count;
  scanf("%d", &count);

  for (int i = 0; i < count; i++)
  {
    char operation[10];
    scanf("%s", operation);

    if (operation[0] == 'i')
    {
      int key;
      scanf("%d", &key);
      insert(key);
    }
    else
    {
      inOrder(root);
      printf("\n");
      preOrder(root);
      printf("\n");
    }
  }

  return 0;
}
