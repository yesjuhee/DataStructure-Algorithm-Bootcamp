#pragma once
typedef char element;

typedef struct TreeNode{
    element data;
    struct TreeNode* left;
    struct TreeNode* right;
} treeNode;

treeNode* makeRootNode(element data, treeNode* leftNode, treeNode* rightNode);
void preorder_t(treeNode* root);
void inorder(treeNode* root);
void postorder_t(treeNode* root);
