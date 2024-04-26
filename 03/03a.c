#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define COUNT 400

typedef struct Stack
{
  int top;
  unsigned capacity;
  int *array;
} Stack;

struct Stack *createStack(unsigned capacity)
{
  struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (int *)malloc(stack->capacity * sizeof(int));
  return stack;
}

int isEmpty(struct Stack *stack)
{
  return stack->top == -1;
}

int isFull(struct Stack *stack)
{
  return stack->top == stack->capacity;
}

void push(struct Stack *stack, int item)
{
  if (isFull(stack))
    return;
  stack->array[++stack->top] = item;
}

int pop(struct Stack *stack)
{
  if (isEmpty(stack))
    return INT_MIN;
  return stack->array[stack->top--];
}

int main()
{
  char formula[COUNT];
  fgets(formula, COUNT, stdin);

  Stack *stack = createStack(100);

  int tmpValue = 0;
  int isNumLoaded = false;
  for (int i = 0; i < COUNT; i++)
  {
    if (formula[i] == ' ')
    {
      if (isNumLoaded)
      {
        push(stack, tmpValue);
        tmpValue = 0;
        isNumLoaded = false;
      }
    }
    else if ('0' <= formula[i] && formula[i] <= '9')
    {
      tmpValue = tmpValue * 10 + (formula[i] - '0');
      isNumLoaded = true;
    }
    else if (formula[i] == '+')
    {
      int value1 = pop(stack);
      int value2 = pop(stack);
      int result = value2 + value1;
      push(stack, result);
    }
    else if (formula[i] == '-')
    {
      int value1 = pop(stack);
      int value2 = pop(stack);
      int result = value2 - value1;
      push(stack, result);
    }
    else if (formula[i] == '*')
    {
      int value1 = pop(stack);
      int value2 = pop(stack);
      int result = value2 * value1;
      push(stack, result);
    }
    else if (formula[i] == '/')
    {
      int value1 = pop(stack);
      int value2 = pop(stack);
      int result = value2 / value1;
      push(stack, result);
    }
    else
    {
      break;
    }
  }

  int result = pop(stack);
  printf("%d\n", result);

  return 0;
}