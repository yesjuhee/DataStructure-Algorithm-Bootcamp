// 녹색 옷 입은 애가 젤다지?

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdlib.h>
#include <string>

using namespace std;

#define INF 100000000

vector<pair<int, int>> graph[125*125];
int cost_array[125*125];
int shortest_distance[125*125];


void make_matrix(int n)
{
    // n*n개의 값 입력받기
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
            continue;
        }
        else if (i % n == 0)
        {
            // 첫 번째 column에 있는 vertex
            graph[i].push_back({i-n, cost_array[i-n]});
            graph[i].push_back({i+1, cost_array[i+1]});
            graph[i].push_back({i+n, cost_array[i+n]});
            continue;
        }
        else if (i % n == n - 1)
        {
            // 마지막 column에 있는 vertex
            graph[i].push_back({i-n, cost_array[i-n]});
            graph[i].push_back({i-1, cost_array[i-1]});
            graph[i].push_back({i+n, cost_array[i+n]});
            continue;
        }
        
        // 일반적인 경우
        graph[i].push_back({i-n, cost_array[i-n]});
        graph[i].push_back({i-1, cost_array[i-1]});
        graph[i].push_back({i+1, cost_array[i+1]});
        graph[i].push_back({i+n, cost_array[i+n]});
    }
}

void dijkstra(int start)
{
    // 다익스트라 함수 실행
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
                pq.push({-new_cost, modifying_node});
            }
        }
    }
}

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
        
        // 최소 거리 배열 초기화
        fill(shortest_distance, shortest_distance+n*n, INF);
        // 비용 배열 초기화
        fill(cost_array, cost_array+n*n, 0);
        // 그래프 초기화
        for(int i = 0; i < n*n; i++)
        {
            graph[i].clear();
        }
        
        // 행렬 입력 받기
        make_matrix(n);
        
        
        
        dijkstra(0);
        
        printf("Problem %d: %d\n", ++problem_num, shortest_distance[n*n-1]);
    }
        
    return 0;
}

