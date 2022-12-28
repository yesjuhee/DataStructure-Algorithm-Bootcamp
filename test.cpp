#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define P pair<int, int>

using namespace std;

// prim 알고리즘 전반적 구현 출처: https://huiung.tistory.com/76

int visited[10001] = {0};
vector<P> edge[10001];
// 가중치 저장. edge[0][0].first = 가중치, edge[0][0].second = 도착 정점

int prim()
{
    int now = 0, dist = 0, result = 0, vertex_from_now = 0;
    priority_queue<P> pq; // first = 가중치, second = 정점
    pq.push(P(0, 0));

    while (!pq.empty())
    {
        // do something

        if (visited[now])
            continue;
        visited[now] = 1; // 정점 방문 표시

        // do something

        for (int i = 0; i < edge[now].size(); i++)
        {
            // do something
            if (!visited[vertex_from_now])
            {
                // do something
            }
        }
    }
    return result; // 가중치의 전체 합 리턴
}

int main()
{
    int V = 0, E = 0, A = 0, B = 0, C = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 그래프 edge 입력
    edge[0].push_back(P(3, 1));
    edge[1].push_back(P(3, 0));
    edge[0].push_back(P(17, 2));
    edge[2].push_back(P(17, 0));
    edge[0].push_back(P(6, 3));
    edge[3].push_back(P(6, 0));
    edge[1].push_back(P(5, 3));
    edge[3].push_back(P(5, 1));
    edge[1].push_back(P(12, 6));
    edge[6].push_back(P(12, 1));
    edge[2].push_back(P(10, 4));
    edge[4].push_back(P(10, 2));
    edge[2].push_back(P(8, 5));
    edge[5].push_back(P(8, 2));
    edge[3].push_back(P(9, 4));
    edge[4].push_back(P(9, 3));
    edge[4].push_back(P(4, 5));
    edge[5].push_back(P(4, 4));
    edge[4].push_back(P(2, 6));
    edge[6].push_back(P(2, 4));
    edge[5].push_back(P(14, 6));
    edge[6].push_back(P(14, 5));

    int result = prim();
    // The answer must be 31
    cout << result << '\n';

    return 0;
}
