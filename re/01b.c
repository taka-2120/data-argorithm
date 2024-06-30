#include <stdio.h>
#include <math.h>
// Greatest Common Divisor: When x >= y, GCD will be equal to the GCD between y and x % y.

int gcd1(int x, int y)
{
  if (x < y)
  {
    int tmp = x;
    x = y;
    y = tmp;
  }

  while (y != 0)
  {
    int tmp = y;
    y = x % y;
    x = tmp;
  }

  return x;
}

int gcd(int x, int y)
{
  if (x < y)
  {
    int tmp = x;
    x = y;
    y = tmp;
  }
  
  if (y == 0) {
    return x;
  }

  return gcd(y, x % y);
}

int main()
{
  int x, y;
  scanf("%d %d", &x, &y);

  int ans = gcd(x, y);
  printf("%d\n", ans);

  return 0;
}
