#include <stdio.h>
#include <stdlib.h>

#include "cQueue.h"

QueueType* createCQueue() {
  QueueType* cQ;
  cQ = (QueueType*)malloc(sizeof(QueueType));
  cQ->front = 0;
  cQ->rear = 0;
  return cQ;
}

// Check whether queue is empty
int isEmpty(QueueType* cQ) {
}

// Check whether queue is full
int isFull(QueueType* cQ) {
}

// Push item at rear
void push(QueueType* cQ, element item) {

}

// Return item at front and delete
element pop(QueueType* cQ) {
}

// Return item at front
element front(QueueType* cQ) {
}

// Return item at rear
element back(QueueType* cQ) {
}

// Print all items
void print(QueueType* cQ) {
}