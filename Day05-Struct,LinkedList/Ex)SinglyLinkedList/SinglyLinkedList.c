#define _CRT_SECURE_NO_WARNINGS
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

}

// Print all nodes
void print(linkedList_h* L) {

}

// Insert new node at front
void push_front(linkedList_h* L, char* x) {

}

// Insert new node at back
void push_back(linkedList_h* L, char* x) {

}

// Insert new node behind pre node
void insert(linkedList_h* L, listNode* pre, char* x) {

}

// Delete node p
void erase(linkedList_h* L, listNode* p) {

}

// Delete node at front
void pop_front(linkedList_h* L) {

}

// Delete node at back
void pop_back(linkedList_h* L) {

}

// Search node which contains x
listNode* find(linkedList_h* L, char* x) {

}

// Reverse the order of nodes in list
void reverse(linkedList_h* L) {

}