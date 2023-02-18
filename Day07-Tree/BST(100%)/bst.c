#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

void inorder(treeNode* root) {
  if (root) {
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
  }
}

// Search x from BST
treeNode* find(treeNode* root, element x) {
  treeNode* p;
  p = root;
  while (p != NULL) {
    if (x < p->key)
      p = p->left;
    else if (x == p->key)
      return p;
    else
      p = p->right;
  }
  //printf("Key %d does not exist.\n", x);
  return p;
}

// Insert x, check p->key
// If x already exists, do not insert
treeNode* insert(treeNode* p, element x) {
  treeNode* newNode;
  if (p == NULL) {
    newNode = (treeNode*)malloc(sizeof(treeNode));
    newNode->key = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  } else if (x < p->key)
    p->left = insert(p->left, x);
  else if (x > p->key)
    p->right = insert(p->right, x);
  else
    printf("You already have %d!\n", x);

  return p;
}

// Delete node which has key
void erase(treeNode* root, element key) {
  treeNode *parent, *p, *succ, *succ_parent;
  treeNode* child;

  parent = NULL;
  // p = node to delete
  // parent = parent of p
  p = root;
  while ((p != NULL) && (p->key != key)) {
    parent = p;
    if (key < p->key)
      p = p->left;
    else
      p = p->right;
  }

  // Key was not found
  if (p == NULL) {
    printf("Key %d does not exist.\n", key);
    return;
  }

  // Terminal node
  if ((p->left == NULL) && (p->right == NULL)) {
    // if BST has more than two nodes
    if (parent != NULL) {
      if (parent->left == p)
        parent->left = NULL;
      else
        parent->right = NULL;
    } else
      root = NULL;
  }

  // If the node has one child
  else if ((p->left == NULL) || (p->right == NULL)) {
    if (p->left != NULL)
      child = p->left;
    else
      child = p->right;

    // p is not root
    if (parent != NULL) {
      if (parent->left == p)
        parent->left = child;
      else
        parent->right = child;
    } else
      root = child;
  }

  // If the node has two children
  else {
    succ_parent = p;
    succ = p->left;
    while (succ->right != NULL) {  // Find successor from left tree
      succ_parent = succ;
      succ = succ->right;
    }
    // Suppose inorder is: 2 3 5
    // In this case: succ->left == NULL
    // succ_parent->left should be NULL
    if (succ_parent->left == succ)
      succ_parent->left = succ->left;
    else
      succ_parent->right = succ->left;
    p->key = succ->key;
    p = succ;
  }
  free(p);
}