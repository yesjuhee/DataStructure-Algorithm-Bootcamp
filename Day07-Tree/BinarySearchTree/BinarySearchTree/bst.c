#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

void inorder(treeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

// Search x from BST, return node which has x
// Otherwise, return NULL
treeNode* find(treeNode* root, element x)
{
    if (root == NULL) return NULL;
    if (root->key == x) return root;
    else if (root->key > x) return find(root->left, x);
    else return find(root->right, x);
}

// Insert x, check p->key
// If x already exists, do not insert
treeNode* insert(treeNode* root, element x)
{
    // solution : 재귀함수를 통해 x가 들어가야 할 말단 노드를 찾아줌
    treeNode* current_node = root;
    if (current_node == NULL) // 말단 노드에 도착
    {
        // 새 노드 생성 후 반환
        treeNode* new_node;
        new_node = (treeNode*)malloc(sizeof(treeNode));
        new_node->key = x;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    else if (x < current_node->key)
    {
        // 왼쪽으로 한 칸 더 내려가서 탐색, 탐색 결과 연결
        current_node->left = insert(current_node->left, x);
    }
    else if (x > current_node->key)
    {
        // 오른쪽으로 한 칸 더 내려가서 탐색, 탐색 결과 연결
        current_node->right = insert(current_node->right, x);
    }
    else if (x == current_node->key)
    {
        // 중복 값인 경우 탐색 멈춤
        printf("Error : You already have %d!!\n", x);
    }
    
    // current_node != NULL 이었던 경우 (말단이 아니었던 경우)
    // 위의 if문에 따라 다음 자식 노드로 탐색을 넘겨주고
    // 자신을 return하여 계속 연결
    return current_node;
}

// Delete node which has key
// Will be a long~function
// if 1: key not found
// if 2: terminal node
// if 3: the node has one child
// if 4: the node has two children (solution chose successor from left tree)
void erase_node(treeNode* root, element key)
{    
    treeNode *delete_node, *parent_node; // 삭제할 노드와 부모 노드
    treeNode *succ, *succ_parent;         // 계승할 노드와 계승 노드의 부모 노드
    treeNode *child;                     // 차수가 1일 때, 삭제할 노드의 자식 노드
    
    // delete_node와 parent_node 찾기
    parent_node = NULL;
    delete_node = root;
    while((delete_node != NULL) && (delete_node->key != key))
    {
        parent_node = delete_node;
        if (key < delete_node->key) delete_node = delete_node->left;
        else delete_node = delete_node->right;
    }
    
// case 1 : 존재하지 않는 key값 - 에러 처리
    if (delete_node == NULL)
    {
        printf("Key %d does not exist.\n", key);
        return;
    }
    
// case 2 : 단말 노드 - 바로 삭제
    if ((delete_node->left == NULL) && (delete_node->right == NULL))
    {
        if (parent_node == NULL) // delete_node가 root인 경우
        {
            // root만 제거하고 끝
            root = NULL;
        }
        else if (parent_node->left == delete_node) // is_left
        {
            parent_node->left = NULL;
        }
        else //is_right
        {
            parent_node->right = NULL;
        }
        
        free(delete_node);
        return;
    }
// case 3 : delete_node에 자식 노드 1개 존재 - 자식과 부모 연결
    else if ((delete_node->left == NULL) || (delete_node->right == NULL))
    {
        // 자식 노드가 delete_node의 왼쪽인지 오른쪽인지 체크
        if (delete_node->left != NULL) child = delete_node->left;
        else child = delete_node->right;
        
        if (parent_node == NULL) root = child;    // delete_node가 root일 경우 처리
        else
        {
            if (parent_node->left == delete_node) //is_left
            {
                parent_node->left = child;
            }
            else                                  //is_right
            {
                parent_node->right = child;
            }
        }
        
        free(delete_node);
        return;
    }
// case 4 : delete_node에 자식 노드 2개 존재 -> 왼쪽 서브 트리에서 가장 큰 자손으로 대체
    else
    {
        // 계승자와 계승자 부모 찾기
        succ_parent = delete_node;
        succ = delete_node->left;
        while (succ->right != NULL)
        {
            succ_parent = succ;
            succ = succ->right;
        }
        
        // 계승자를 고립시키기 위해 계승자의 부모와 계승자의 자식 연결
        if (succ_parent->left == succ)
        {
            // 예외적인 경우 : 바로 왼쪽 자식이 왼쪽 서브트리에서 가장 큰 자손일 경우
            succ_parent->left = succ->left;
        }
        else
        {
            // 일반적인 경우
            succ_parent->right = succ->left;
        }
        // delete_node 자리의 key값을 계승자 노드의 key값으로 바꿔치기 하고 succ 노드는 해제시킴
        delete_node->key = succ->key;
        delete_node = succ;
        free(delete_node);
        return;
    }
}
