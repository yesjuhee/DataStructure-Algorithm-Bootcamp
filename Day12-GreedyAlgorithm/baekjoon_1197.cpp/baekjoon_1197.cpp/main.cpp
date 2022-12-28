// 최소 스패닝 트리

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define P pair<int, int>

using namespace std;


int visited[10001] = {0};
vector<P> edge[10001];
// 가중치 저장. edge[0][0].first = 가중치, edge[0][0].second = 도착 정점

int prim()
{
    int now = 0, dist = 0, result = 0, vertex_from_now = 0;
    priority_queue<P> pq; // first = 가중치, second = 정점
    pq.push(P(0, 1));

    while (!pq.empty())
    {
        now = pq.top().second;
        dist = -pq.top().first;
        pq.pop();

        if (visited[now])
            continue;
        visited[now] = 1;

        result += dist;

        for (int i = 0; i < edge[now].size(); i++)
        {
            vertex_from_now = edge[now][i].second;
            if (!visited[vertex_from_now])
            {
                // 도착한 적이 없는 vertex에 연결된 edge라면 pq에 추가
                pq.push({-edge[now][i].first, edge[now][i].second});
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

    // 입력
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        cin >> A >> B >> C;
        edge[A].push_back({C, B});
        edge[B].push_back({C, A});
    }

    int result = prim();
    cout << result << '\n';

    return 0;
}
