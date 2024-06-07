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
  Node *tmp = NIL;
  Node *parent = root;
  Node *current = malloc(sizeof(Node));

  current->key = key;
  current->left = NIL;
  current->right = NIL;
  current->parent = NIL;

  while (parent != NIL)
  {
    tmp = parent;
    if (current->key < parent->key)
    {
      parent = parent->left;
    }
    else
    {
      parent = parent->right;
    }
  }

  current->parent = tmp;

  if (tmp == NIL)
  {
    root = current;
  }
  else if (current->key < tmp->key)
  {
    tmp->left = current;
  }
  else
  {
    tmp->right = current;
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

Node *find(Node *node, int target)
{
  while (node != NIL && target != node->key)
  {
    if (target < node->key)
    {
      node = node->left;
    }
    else
    {
      node = node->right;
    }
  }
  return node;
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
    else if (operation[0] == 'f')
    {
      int key;
      scanf("%d", &key);
      Node *node = root;
      node = find(node, key);
      printf(node == NIL ? "no\n" : "yes\n");
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
