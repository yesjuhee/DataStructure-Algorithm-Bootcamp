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
//    // 중복 여부 검사
//    if (find(root, x) != NULL)
//    {
//        printf("Error : %d already exists!!\n", x);
//        return NULL;
//    }
//
//    // 삽입할 노드 생성, 할당
//    treeNode* new_node;
//    new_node = (treeNode*)malloc(sizeof(treeNode));
//    new_node->key = x;
//    new_node->left = NULL;
//    new_node->right = NULL;
//
//    // 루트 존재 여부 검사
//    if (root == NULL)
//    {
//        root = new_node;
//        return root;
//    }
//
//    // 삽입 위치 탐색 (부모 노드 찾기)
//    treeNode* search_pointer = root;
//    treeNode* parent_pointer = search_pointer;
//    while (search_pointer != NULL)
//    {
//        parent_pointer = search_pointer;
//        if (x > search_pointer->key)
//        {
//            search_pointer = search_pointer->right;
//        }
//        else // if (x < search_pointer->key)
//        {
//            search_pointer = search_pointer->left;
//        }
//    }
//    // 삽입
//    if (parent_pointer->key < x)
//    {
//        parent_pointer->right = new_node;
//    }
//    else
//    {
//        parent_pointer->left = new_node;
//    }
//    return root;
    
    // solution : 재귀함수를 통해 x가 들어가야 할 말단 노드를 찾아줌
    treeNode* current_node;
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
//    treeNode* delete_node = find(root, key);
//    treeNode *current_node = NULL, *parent_node = NULL; // 탐색을 위한 포인터
//    treeNode *temp_node = NULL, *new_root_node = NULL,
//    *new_roots_parent_node = NULL;; // degree 2 인 노드 삭제를 위한 포인터
//    int degree = 0, is_left = 0;
//
//    // case 1 : 존재하지 않는 key값 - 에러 처리
//    if (delete_node == NULL)
//    {
//        printf("Error : %d does not exist!!\n", key);
//        return;
//    }
//
//    // 디그리 개수 세기
//    if (delete_node->left != NULL) degree++;
//    if (delete_node->right != NULL) degree++;
//    // 부모 노드 찾기
//    current_node = root;
//    while(current_node->key != key)
//    {
//        parent_node = current_node;
//        if (current_node->key < key)
//        {
//            current_node = current_node->right;
//            is_left = 0;
//        }
//        else // current_node->key > key
//        {
//            current_node = current_node->left;
//            is_left = 1;
//        }
//    }
//
//    // case 2 : 단말 노드 - 바로 삭제
//    if (degree == 0)
//    {
//        if (parent_node == NULL) // delete_node가 root인 경우
//        {
//            root = NULL;
//        }
//        else if (is_left)
//        {
//            parent_node->left = NULL;
//        }
//        else //is_right
//        {
//            parent_node->right = NULL;
//        }
//
//        free(delete_node);
//        return;
//    }
//
//    // case 3 : delete_node에 자식 노드 1개 존재 - 자식과 부모 연결
//    if (degree == 1)
//    {
//        if (parent_node == NULL) // delete_node가 root인 경우
//        {
//            if (delete_node->left != NULL)
//            {
//                root = delete_node->left;
//            }
//            else
//            {
//                root = delete_node->right;
//            }
//
//        }
//        else if (delete_node->left != NULL) // 왼쪽에 자식을 가진 경우
//        {
//            if (is_left) parent_node->left = delete_node->left;
//            else parent_node->right = delete_node->left;
//        }
//        else // 오른쪽에 자식을 가진 경우
//        {
//            if (is_left) parent_node->left = delete_node->right;
//            else parent_node->right = delete_node->right;
//        }
//        free(delete_node);
//        return;
//    }
//
//    // case 4 : delete_node에 자식 노드 2개 존재 -> 오른쪽 서브 트리에서 가장 작은 자손으로 대체
//    if (degree == 2)
//    {
//        // new_root_node 찾기 (오른쪽 서브트리에서 가장 왼쪽인 노드)
//        new_roots_parent_node = delete_node;
//        new_root_node = delete_node->right;
//        while(new_root_node->left != NULL)
//        {
//            new_roots_parent_node = new_root_node;
//            new_root_node = new_root_node->left;
//        }
//
//        // temp_node를 new_node 부모의 오른쪽에 연결
//        temp_node = (treeNode*)malloc(sizeof(treeNode));
//        temp_node->key = -1;
//        delete_node->right = temp_node;
//
//        // new_root_node의 자손들을 temp_node로 이동
//        temp_node->left = NULL;
//        temp_node->right = new_root_node->right;
//        new_root_node->right = NULL;
//
//        // delete_node의 부모를 new_root_node와 연결
//        if (parent_node == NULL)
//        {
//            root = new_root_node;
//        }
//        else if(is_left)
//        {
//            parent_node->left = new_root_node;
//        }
//        else
//        {
//            parent_node->right = new_root_node;
//        }
//
//        // delete_node의 자손들을 new_root_node로 이동
//        new_root_node->left = delete_node->left;
//        new_root_node->right = delete_node->right;
//
//        // delete_node 삭제
//        free(delete_node);
//
//        // temp_node 삭제
//        erase_node(root, -1);
//    }
}
