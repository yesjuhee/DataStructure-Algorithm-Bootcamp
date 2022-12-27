#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 10000000
#define N 5

// graph[0].first = 정점 0에서 first로 감
// graph[0].second = 정점 0에서 first로 갈 때 드는 비용
vector<pair<int,int>> graph[N];
// 최단거리 배열
int shortest_distance[N];

void dijkstra(int start)
{
    int distance = 0, min_node_index = 0, new_cost = 0;
    priority_queue<pair<int,int>> pq; // {거리, 정점 인덱스}, 우선순위 큐는 기본이 내림차순임에 유의

    pq.push({0, start}); // 시작 정점으로 가기 위한 최단 경로는 0으로 설정
    shortest_distance[start] = 0;
    
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
  // 간선 정보 입력.
  // 아래 줄 내용: 정점 0에서 정점 0으로 갈 때 드는 비용은 0이다
  graph[0].push_back({0, 0});
  graph[0].push_back({1, 10});
  graph[0].push_back({2, 5});

  graph[1].push_back({1, 0});
  graph[1].push_back({2, 2});
  graph[1].push_back({3, 1});
  
  graph[2].push_back({1, 3});
  graph[2].push_back({2, 0});
  graph[2].push_back({3, 9});
  graph[2].push_back({4, 2});

  graph[3].push_back({3, 0});
  graph[3].push_back({4, 4});

  graph[4].push_back({0, 7});
  graph[4].push_back({3, 6});
  graph[4].push_back({4, 0});

  // 최단거리 배열을 모두 INF로 초기화
  fill(shortest_distance, shortest_distance + N, INF);

  dijkstra(0);

  for (int i = 0; i < N; i++)
  {
      printf("shortest_distance[%d]: %d\n", i, shortest_distance[i]);
  }
  return 0;
}
