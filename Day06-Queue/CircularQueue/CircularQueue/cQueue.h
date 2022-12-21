#pragma once
#define cQ_SIZE 4

typedef int element;

typedef struct {
  element queue[cQ_SIZE];
  int front, rear;
} QueueType;

QueueType* createCQueue(void);
int isEmpty(QueueType* cQ);
int isFull(QueueType* cQ);
void push(QueueType* cQ, element item);
element pop(QueueType* cQ);
element front(QueueType* cQ);
element back(QueueType* cQ);
void print(QueueType* cQ);
