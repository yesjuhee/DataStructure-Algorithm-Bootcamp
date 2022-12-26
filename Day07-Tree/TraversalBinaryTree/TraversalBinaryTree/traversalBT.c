#include <stdio.h>
#include <stdlib.h>
#include "traversalBT.h"

// data is parant node
// Allocate data dynamically, and assume that leftNode and rightNode were already assigned
// then, return data
treeNode* makeRootNode(element data, treeNode* leftNode, treeNode* rightNode)
{
    // 루트 노드 동적 할당
    treeNode *new_node;
    new_node = (treeNode*)malloc(sizeof(treeNode));
    // 데이터 대입
    new_node->data = data;
    // 자식 노드 할당
    new_node->left = leftNode;
    new_node->right = rightNode;
                                
    return new_node;
}

// Preorder traversal: -*AB/CD
void preorder_t(treeNode* root)
{
    if (root == NULL) return;
    printf("%c", root->data);
    preorder_t(root->left);
    preorder_t(root->right);
}

// Inorder traversal: A*B-C/D
void inorder(treeNode* root)
{
    if (root == NULL) return;
    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);
}

// Postorder traversal: AB*CD/-
void postorder_t(treeNode* root)
{
    if (root == NULL) return;
    postorder_t(root->left);
    postorder_t(root->right);
    printf("%c", root->data);
}
