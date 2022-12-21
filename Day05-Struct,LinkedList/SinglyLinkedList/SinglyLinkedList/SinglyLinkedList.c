#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SinglyLinkedList.h"

// Create an empty linked list
linkedList_h* createLinkedList_h(void) {
  linkedList_h* L;
  L = (linkedList_h*)malloc(sizeof(linkedList_h));
  L->head = NULL;
  return L;
}

// Free all memories
void freeLinkedList(linkedList_h* L) {
    listNode* delete_node;
    while(L->head != NULL)
    {
        delete_node = L->head;
        L->head = L->head->link;
        free(delete_node);
    }
}

// Print all nodes
void print(linkedList_h* L) {
    listNode* current_node = L->head;
    while (current_node != NULL) // 포인터가 NULL을 가리킬 때까지(끝까지) 반복
    {
        // 현재 가리키고 있는 노드를 출력
        printf("%s ", current_node->data);
        // current_node 포인터를 다음 노드를 가리키도록 설정
        current_node = current_node->link;
    }
    printf("\n");
}

// Insert new node at front
void push_front(linkedList_h* L, char* x) {
    // 새 노드 동적 할당 & 세팅
    listNode* new_node;
    new_node = (listNode*)malloc(sizeof(listNode));
    strcpy(new_node->data, x);
    // 헤더가 가리키는 노드를 새 노드가 가리키도록 지정
    new_node->link = L->head;
    // 헤더가 새 노드를 가리키도록 지정
    L->head = new_node;
}

// Insert new node at back
void push_back(linkedList_h* L, char* x) {
    listNode* current_node;
    // 새 노드 동적 할당 & 세팅
    listNode* new_node;
    new_node = (listNode*)malloc(sizeof(listNode));
    strcpy(new_node->data, x);
    new_node->link = NULL;
    // 리스트가 비어있을 경우 헤더를 연결하고 끝
    if (L->head == NULL)
    {
        L->head = new_node;
        return;
    }
    // 처음부터 탐색하여 마지막 노드가 새 노드를 가리키도록 지정
    current_node = L->head;
    while (current_node->link != NULL)
    {
        current_node = current_node->link;
    }
    current_node->link = new_node;
}

// Insert new node behind pre node
void insert(linkedList_h* L, listNode* pre, char* x) {
    // 새 노드 동적 할당 & 세팅
    listNode* new_node;
    new_node = (listNode*)malloc(sizeof(listNode));
    strcpy(new_node->data, x);
    // Error Handling : 잘못된 값 입력
    if (pre == NULL)
    {
        printf("Error : wrong input\n");
        return;
    }
    // 새 노드의 링크 세팅 : 이전 노드가 가리키는 노드를 가리키도록 지정
    new_node->link = pre->link;
    // 이전 노드의 링크 세팅 : 새 노드를 가리키도록 지정
    pre->link = new_node;
}

// Delete node p
void erase_node(linkedList_h* L, listNode* p) {
    listNode* previous_node = L->head;
    // Error Handling : 잘못된 값 입력
    if (p == NULL)
    {
        printf("Error : wrong input\n");
        return;
    }
    // p가 첫 번째 노드인 경우
    if (L->head == p)
    {
        L->head = L->head->link;
        free(p);
        return;
    }
    // p의 이전 노드 찾기
    while(previous_node->link != p)
    {
        previous_node = previous_node->link;
    }
    // p의 이전 노드의 링크를 p의 다음 노드로 연결
    previous_node->link = p->link;
    free(p);
}

// Delete node at front
void pop_front(linkedList_h* L) {
    listNode* delete_node = L->head;
    // Error Handling : empty list
    if (L->head == NULL)
    {
        printf("Error : list is empty\n");
        return;
    }
    // 헤더를 다음 다음 노드와 연결
    L->head = L->head->link;
    free(delete_node);
}

// Delete node at back
void pop_back(linkedList_h* L) {
    listNode* current_node = L->head;
    listNode* previous_node = NULL;
    // Error handling : empty list
    if (L->head==NULL)
    {
        printf("Error : list is empty\n");
        return;
    }
    // 맨 마지막 노드를 찾아가며 previous_node와 current_node 변경
    while(current_node->link != NULL)
    {
        previous_node = current_node;
        current_node = current_node->link;
    }
    // 리스트에 노드 한 개만 존재 -> 헤더에 NULL을 저장하고 return
    if (previous_node == NULL)
    {
        free(L->head);
        L->head = NULL;
        return;
    }
    // 일반적인 경우 previous_node(맨 뒤에서 두번째 노드)의 링크에 NULL저장
    previous_node->link = NULL;
    free(current_node);
}

// Search node which contains x
listNode* find(linkedList_h* L, char* x) {
    listNode* current_node = L->head;
    while (current_node != NULL)
    {
        if (strcmp(current_node->data, x) == 0) // 둘이 같다면
        {
            return current_node;
        }
        current_node = current_node->link;
    }
    return current_node; // 존재하지 않는 경우 NULL을 return
}

// Reverse the order of nodes in list
void reverse(linkedList_h* L) {
    // 3개의 포인터를 이용하여 값들을 임시로 저장
    // new_head의 링크를 previous_node로 연결하고, 그 다음에 이용할 노드는 nex_node가 가리키고 있어야 함
    listNode *previous_node, *new_head, *next_node;
    
    previous_node = L->head;
    new_head = NULL;
    next_node = NULL;
    
    while(previous_node != NULL)
    {
        // next_node, new_head, previous_node 한 칸씩 전진
        next_node = new_head;
        new_head = previous_node;
        previous_node = previous_node->link;
        // new_head의 링크 연결
        new_head->link = next_node;
    }
    L->head = new_head;
}
