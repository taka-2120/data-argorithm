#include <stdio.h>
#include <limits.h>

// TODO

int main()
{
  int count;
  scanf("%d", &count);

  int last_value, max_diff = INT_MIN;
  for (int i = 0; i < count; i++)
  {
    int current_value;
    scanf("%d", &current_value);

    if (i != 0)
    {
      int diff = current_value - last_value;
      if (max_diff < diff)
      {
        max_diff = diff;
      }
    }

    last_value = current_value;
  }

  printf("%d\n", max_diff);

  return 0;
}