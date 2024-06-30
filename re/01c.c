#include <stdio.h>
#include <stdbool.h>

bool is_prime(int value)
{
  for (int i = 2; i < value; i++)
  {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

int main()
{
  int count;
  scanf("%d", &count);

  int pcount = 0;
  for (int i = 0; i < count; i++)
  {
    int value;
    scanf("%d", &value);
    if (is_prime(value)) {
      pcount += 1;
    }
  }
  printf("%d\n", pcount);

  return 0;
}
