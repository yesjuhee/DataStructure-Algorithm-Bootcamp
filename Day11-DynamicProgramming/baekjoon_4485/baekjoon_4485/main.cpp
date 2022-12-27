// 질문
// 1. 입력 방식
// 2. 벡터의 배열 함수 인자 전달
// 3. 벡터 배열 크기 동적할당? n으로 설정

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdlib.h>
#include <string>

using namespace std;

#define INF 100000000

//void make_matrix(int n, vector<pair<int, int>> &graph)
//{
//    // n*n개의 값 입력받기
//    int *cost_array;
//    cost_array = (int*)malloc(sizeof(int)*n*n);
//    for (int i = 0; i < n*n; i++)
//    {
//        scanf("%d", cost_array+i);
//    }
//
//    // graph에 edge 올바르게 저장하기
//    for (int i = 0; i < n*n - 1; i++)
//    {
//        if (i % n == n-1)
//        {
//            // 마지막 열에 있는 vertex
//            graph[i].push_back({i+3, cost_array[i+3]});
//        }
//    }
//}

int main(void)
{
    int n;
    int problem_num = 0;
    
    while(1)
    {
        // n 입력
        scanf(" %d", &n);
        if (n == 0)
        {
            return 0;
        }
        
        // 행렬 입력 받기
        vector<pair<int, int>> graph[n*n];
        // make_matrix(n, graph);
        
            // n*n개의 값 입력받기
        int *cost_array;
        cost_array = (int*)malloc(sizeof(int)*n*n);
        for (int i = 0; i < n*n; i++)
        {
            scanf("%d", cost_array+i);
        }
    
            // graph에 edge 올바르게 저장하기
        for (int i = 0; i < n*n - 1; i++)
        {
            // 모퉁이 3개 vertex
            if (i == 0)
            {
                graph[i].push_back({i+1, cost_array[i+1]});
                graph[i].push_back({i+n, cost_array[i+n]});
                continue;
            }
            else if (i == n-1)
            {
                graph[i].push_back({i-1, cost_array[i-1]});
                graph[i].push_back({i+n, cost_array[i+n]});
                continue;
            }
            else if (i == n*(n-1))
            {
                graph[i].push_back({i-n, cost_array[i-n]});
                graph[i].push_back({i+1, cost_array[i+1]});
                continue;
            }
            
            // 모서리
            if (i / n == 0)
            {
                // 첫 번째 row에 있는 vertex
                graph[i].push_back({i-1, cost_array[i-1]});
                graph[i].push_back({i+1, cost_array[i+1]});
                graph[i].push_back({i+n, cost_array[i+n]});
                continue;
            }
            else if (i / n == n - 1)
            {
                // 마지막 row에 있는 vertex
                graph[i].push_back({i-n, cost_array[i-n]});
                graph[i].push_back({i-1, cost_array[i-1]});
                graph[i].push_back({i+1, cost_array[i+1]});
//                printf("마지막 row 입력:graph[%d]에 {%d, %d} 저장\n", i, i-1, cost_array[i-1]);
//                printf("마지막 row 입력:graph[%d]에 {%d, %d} 저장\n", i, i+1, cost_array[i+1]);
//                printf("마지막 row 입력:graph[%d]에 {%d, %d} 저장\n", i, i-n, cost_array[i-n]);
                continue;
            }
            else if (i % n == 0)
            {
                // 첫 번째 column에 있는 vertex
                graph[i].push_back({i-n, cost_array[i-n]});
                graph[i].push_back({i+1, cost_array[i+1]});
                graph[i].push_back({i+n, cost_array[i+n]});
                continue;
                //printf("1:graph[%d]에 {%d, %d} 저장\n", i, i+n, cost_array[i+n]);
            }
            else if (i % n == n - 1)
            {
                // 마지막 column에 있는 vertex
                graph[i].push_back({i-n, cost_array[i-n]});
                graph[i].push_back({i-1, cost_array[i-1]});
                graph[i].push_back({i+n, cost_array[i+n]});
                continue;
                //printf("1:graph[%d]에 {%d, %d} 저장\n", i, i+n, cost_array[i+n]);
            }
            
            // 일반적인 경우
            graph[i].push_back({i-n, cost_array[i-n]});
            graph[i].push_back({i-1, cost_array[i-1]});
            graph[i].push_back({i+1, cost_array[i+1]});
            graph[i].push_back({i+n, cost_array[i+n]});
            //printf("3:graph[%d]에 {%d, %d} 저장\n", i, i+1, cost_array[i+1]);
            //printf("3:graph[%d]에 {%d, %d} 저장\n", i, i+n, cost_array[i+n]);
            
        }
        
        // 최소 거리 배열 초기화
        //int shortest_distance[n*n];
        int shortest_distance[n*n];
        fill(shortest_distance, shortest_distance+n*n, INF);
        
        // 다익스트라 함수 실행
        int start = 0;
        int distance = 0, min_node_index = 0, new_cost = 0;
        priority_queue<pair<int,int>> pq; //{거리, 정점 인덱스}

        pq.push({-cost_array[0], start}); // 시작 정점으로 가기 위한 최단 경로 설정
        shortest_distance[start] = cost_array[0];
        
        while (!pq.empty())
        {
            // 최단 거리 노드(min_node_index) 찾기
            min_node_index = pq.top().second;
            distance = -pq.top().first;
            pq.pop();

            if (shortest_distance[min_node_index] < distance) // 이미 최단경로를 체크한 경우
                continue;

            for (int i = 0; i < graph[min_node_index].size(); i++)
            {
                int modifying_node = graph[min_node_index][i].first;
                int second_cost = graph[min_node_index][i].second;
                
                new_cost = distance + second_cost;
                if (new_cost < shortest_distance[modifying_node])
                {
                    shortest_distance[modifying_node] = new_cost;
                    //printf("shortest_distance[%d] = new(%d)\n", modifying_node, new_cost);
                    pq.push({-new_cost, modifying_node});
                }
            }
        }
        
        // 출력
        //printf("shortest distance : ");
//        for (int i=0; i<n*n; i++)
//        {
//            printf("%d ", shortest_distance[i]);
//        }
        printf("Problem %d: %d\n", ++problem_num, shortest_distance[n*n-1]);
        free(cost_array);
    }
        
    return 0;
}

