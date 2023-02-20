#pragma once
#define MAX_ELEMENT 100

typedef struct {
  int heap[MAX_ELEMENT];
  int heap_size;
} heapType;

heapType* createHeap();
void push(heapType* h, int item);
int top(heapType* h);
void pop(heapType* h);
void print(heapType* h);
int size(heapType* h);
