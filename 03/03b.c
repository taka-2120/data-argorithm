#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

typedef struct Process
{
  char *name;
  int quantum;
} Process;

typedef struct Queue
{
  int front, rear, size;
  unsigned capacity;
  Process *array;
} Queue;

Process emptyProcess()
{
  Process empProcess;
  empProcess.name = malloc(10 * sizeof(char));
  empProcess.name = "invalid";
  empProcess.quantum = 0;
  return empProcess;
}

struct Queue *createQueue(unsigned capacity)
{
  struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
  queue->capacity = capacity;
  queue->front = queue->size = 0;

  queue->rear = capacity - 1;
  queue->array = (Process *)malloc(queue->capacity * sizeof(Process));
  return queue;
}

int isFull(struct Queue *queue)
{
  return (queue->size == queue->capacity);
}

int isEmpty(struct Queue *queue)
{
  return (queue->size == 0);
}

void enqueue(struct Queue *queue, Process item)
{
  if (isFull(queue))
  {
    return;
  }
  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->array[queue->rear] = item;
  queue->size = queue->size + 1;
}

Process dequeue(struct Queue *queue)
{
  if (isEmpty(queue))
  {
    return emptyProcess();
  }
  Process item = queue->array[queue->front];
  queue->front = (queue->front + 1) % queue->capacity;
  queue->size = queue->size - 1;
  return item;
}

Process front(struct Queue *queue)
{
  if (isEmpty(queue))
  {
    return emptyProcess();
  }
  return queue->array[queue->front];
}

Process rear(struct Queue *queue)
{
  if (isEmpty(queue))
  {
    return emptyProcess();
  }
  return queue->array[queue->rear];
}

int main()
{
  int count, quantum;
  scanf("%d %d", &count, &quantum);

  Queue *queue = createQueue(count);

  for (int i = 0; i < count; i++)
  {
    Process process;
    process.name = (char *)malloc(10 * sizeof(char));
    scanf("%10s %d", process.name, &process.quantum);
    enqueue(queue, process);
  }

  int processTime = 0;

  while (queue->size != 0)
  {
    if (front(queue).quantum <= quantum)
    {
      Process process = dequeue(queue);
      printf("%s %d\n", process.name, processTime + process.quantum);
      processTime += process.quantum;
    }
    else
    {
      Process process = dequeue(queue);
      int remain = process.quantum - quantum;
      process.quantum = remain;
      enqueue(queue, process);
      processTime += quantum;
    }
  }

  return 0;
}