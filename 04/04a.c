#include <stdio.h>

int main(void)
{
  int n, q;

  scanf("%d", &n);
  int sArray[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &sArray[i]);
  }

  scanf("%d", &q);
  int tArray[q];
  for (int i = 0; i < q; i++)
  {
    scanf("%d", &tArray[i]);
  }


  int match = 0;

  for (int i = 0; i < q; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (tArray[i] == sArray[j])
      {
        match++;
        break;
      }
    }
  }
  printf("%d\n", match);

  return 0;
}
