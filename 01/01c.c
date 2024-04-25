#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n)
{
  if (n < 2)
  {
    return false;
  }

  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      return false;
    }
  }

  return true;
}

int main()
{
  int count;
  scanf("%d", &count);

  if (count < 1 || 10000 < count)
  {
    return 1;
  }

  int array[count];
  for (int i = 0; i < count; i++)
  {
    scanf("%d", &array[i]);

    if (count < 2 || 100000000 < count)
    {
      return 1;
    }
  }

  int prime_num_count = 0;
  for (int i = 0; i < count; i++)
  {
    if (is_prime(array[i]))
    {
      prime_num_count += 1;
    }
  }
  printf("%d\n", prime_num_count);

  return 0;
}