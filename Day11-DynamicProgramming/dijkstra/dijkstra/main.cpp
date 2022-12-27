#include <stdio.h>
#include <algorithm>
using namespace std;

#define INF 10000000
#define N 5

int weight[N][N] = {{0, 10, 5, INF, INF},
                    {INF, 0, 2, 1, INF},
                    {INF, 3, 0, 9, 2},
                    {INF, INF, INF, 0, 4},
                    {7, INF, INF, 6, 0}};
bool visited[N] = {false};
int dist[N] = {0};
int min_node = 0;

// 방문하지 않은 노드들 중,
// 최단 거리가 가장 짧은 노드 인덱스 반환
int get_smallest_node()
{
    int min = INF;
    int node = -1;
    for (int i = 0; i < N; i++)
    {
        if (visited[i] == true)
            continue;
        if (min > dist[i])
        {
            min = dist[i];
            node = i;
        }
    }
    return node;
}

void dijkstra(int start)
{
    // 방문한 노드에 시작 정점 저장
    visited[start] = true;
    // distance 배열 초기화
    for (int i = 0; i < N; i++)
    {
        dist[i] = weight[start][i];
    }

    while (1)
    {
        // 1. 최소 노드 추가
        min_node = get_smallest_node();
        if (min_node == -1)
        {
            break;
        }
        visited[min_node] = true;

        // 2. 1로 인해 단축되는 경로 있는지 확인하여 distance 값 수정
        for (int i = 0; i < N; i++)
        {
            if (visited[i] == true || weight[min_node][i] == INF)
            {
                continue;
            }
            dist[i] = min(dist[i], dist[min_node] + weight[min_node][i]);
        }
    }
}

int main(void)
{
    dijkstra(0);
    for (int i = 0; i < N; i++)
        printf("dist[%d]: %d\n", i, dist[i]);

    return 0;
}
