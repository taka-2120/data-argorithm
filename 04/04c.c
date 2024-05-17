#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define STR_LEN 13
#define MAX 1046527

char table[MAX][STR_LEN];

int getChar(char ch)
{
  switch (ch)
  {
  case 'A':
    return 1;
  case 'C':
    return 2;
  case 'G':
    return 3;
  case 'T':
    return 4;
  default:
    return 0;
  }
}

long long getKey(char str[])
{
  long long sum = 0, p = 1;

  for (int i = 0; i < strlen(str); i++)
  {
    sum += p * getChar(str[i]);
    p *= 5;
  }
  return sum;
}

int h1(int key)
{
  return key % MAX;
}

int h2(int key)
{
  return 1 + (key % (MAX - 1));
}

void insert(char str[])
{
  long long key = getKey(str);

  for (long long i = 0;; i++)
  {
    long long hash = (h1(key) + i * h2(key)) % MAX;
    if (strcmp(table[hash], str) == 0)
    {
      return;
    }
    else if (strlen(table[hash]) == 0)
    {
      strcpy(table[hash], str);
      return;
    }
  }
}

bool find(char str[])
{
  long long key = getKey(str);

  for (long long i = 0;; i++)
  {
    long long hash = (h1(key) + i * h2(key)) % MAX;
    if (strcmp(table[hash], str) == 0)
    {
      return true;
    }
    else if (strlen(table[hash]) == 0)
    {
      return false;
    }
  }
  return false;
}

int main()
{
  for (int i = 0; i < MAX; i++)
  {
    table[i][0] = '\0';
  }

  int count;
  scanf("%d", &count);

  for (int i = 0; i < count; i++)
  {
    char operation[6];
    char string[STR_LEN];
    scanf("%s %s", operation, string);

    if (operation[0] == 'i')
    {
      insert(string);
    }
    else
    {
      bool matched = find(string);
      printf(matched ? "yes\n" : "no\n");
    }
  }

  return 0;
}
