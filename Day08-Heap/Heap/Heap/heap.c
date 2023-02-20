#include "heap.h"

#include <stdio.h>
#include <stdlib.h>

// Create an empty heap
heapType* createHeap() {
  heapType* h = (heapType*)malloc(sizeof(heapType));
  h->heap_size = 0;
  return h;
}

// Insert node that has item to heap
void push(heapType* h, int item) {
    int i;
    i = ++h->heap_size;     // 새로 생성될 노드 번호
    
    // item이 부모 노드의 값보다 크면 위로 올리기
    while ((i != 1) && (item > h->heap[i / 2]))
    {
        h->heap[i] = h->heap[i/2];  // 부모 노드를 i 위치로 이동
        i /= 2;                     // i를 부모 노드의 번호로 변경
    }
    h->heap[i] = item;
}

// Return root
int top(heapType* h) {
    return h->heap[1];
}

// Remove root
void pop(heapType* h) {
    int parent, child, temp;
    temp = h->heap[h->heap_size--];     // root와 바꿔치기할 마지막 원소의 값
    parent = 1;                         // temp의 위치를 탐색할 인덱스, root 부터 시작
    child = 2;                          // parent의 자식 중 큰 값을 찾기 위한 인덱스
    
    while (child <= h->heap_size)
    {
        if ((child < h->heap_size) && (h->heap[child] < h->heap[child + 1]))
            child++;    // 오른쪽 자식이 큰 경우 오른쪽 자식을 선택
        
        if (temp >= h->heap[child])
            break;      // 현재 parent의 위치에 temp가 들어가도 괜찮으면 break
        else            // 현재 parent보다 child위치의 값이 더 크면
        {
            h->heap[parent] = h->heap[child];   // child 노드를 위로 올려주고
            parent = child;                     // parent를 아래로 내려서 다시 while문 실행
            child = child * 2;
        }
    }
    
    h->heap[parent] = temp;             // parent의 최종 위치에 temp 값을 저장
}

// Print
void print(heapType* h) {
    int i;
    for (i = 1; i <= h->heap_size; i++)
        printf("%d ", h->heap[i]);
    printf("\n");
}

// Return number of elements
int size(heapType* h) {
    return h->heap_size;
}
