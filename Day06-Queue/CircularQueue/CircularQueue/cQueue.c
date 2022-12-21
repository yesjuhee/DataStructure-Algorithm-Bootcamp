#include <stdio.h>
#include <stdlib.h>

#include "cQueue.h"

QueueType* createCQueue(void) {
  QueueType* cQ;
  cQ = (QueueType*)malloc(sizeof(QueueType));
  cQ->front = 0;
  cQ->rear = 0;
  return cQ;
}

// Check whether queue is empty
int isEmpty(QueueType* cQ) {
    // front==rear -> empty
    if (cQ->front == cQ->rear)
    {
        printf("Circular Queue is empty!\n");
        return 1;
    }
    else return 0;
}

// Check whether queue is full
int isFull(QueueType* cQ) {
    // rear + 1 == front -> full
    if ((cQ->rear+1 % cQ_SIZE) == cQ->front)
    {
        return 1;
    }
    else return 0;
}

// Push item at rear
void push(QueueType* cQ, element item) {
    // Error handling : queue is full
    if(isFull(cQ))
    {
        return;
    }
    // rear를 +1 하고 그 자리에 삽입
    cQ->rear = cQ->rear+1 % cQ_SIZE;
    cQ->queue[cQ->rear] = item;
}

// Return item at front and delete
element pop(QueueType* cQ) {
    // Error handling : queue is empty
    if(isEmpty(cQ))
    {
        return -1;
    }
    // front를 +1하고 front 자리의 요소를 반환
    cQ->front = cQ->front+1 % cQ_SIZE;
    return cQ->queue[cQ->front];
}

// Return item at front
element front(QueueType* cQ) {
    // Error handling : queue is empty
    if(isEmpty(cQ))
    {
        return -1;
    }
    return cQ->queue[cQ->front+1 % cQ_SIZE];
}

// Return item at rear
element back(QueueType* cQ) {
    // Error handling : queue is empty
    if(isEmpty(cQ))
    {
        return -1;
    }
    return cQ->queue[cQ->rear];
}

// Print all items
void print(QueueType* cQ) {
    // front + 1부터 rear까지
    int index = cQ->front;
    while(index != cQ->rear)
    {
        index = (index + 1) % cQ_SIZE;
        printf("%d ", cQ->queue[index]);
    }
    printf("\n");
}
