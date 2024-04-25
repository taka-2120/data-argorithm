#include <stdio.h>
#include <limits.h>
#include <math.h>

int max_profit(int prices[], int n)
{
  int max_profit = INT_MIN;
  int min_price = prices[0];

  for (int i = 1; i < n; i++)
  {
    int current_price = prices[i];
    int profit = current_price - min_price;

    if (max_profit < profit)
    {
      max_profit = profit;
    }

    if (min_price > current_price)
    {
      min_price = current_price;
    }
  }

  return max_profit;
}

int main()
{
  int count;
  scanf("%d", &count);

  if (count < 2 || 200000 < count)
  {
    return 1;
  }

  int array[count];
  for (int i = 0; i < count; i++)
  {
    scanf("%d", &array[i]);

    if (array[i] < 1 || pow(10, 9) < array[i])
    {
      return 1;
    }
  }

  int profit = max_profit(array, count);
  printf("%d\n", profit);

  return 0;
}