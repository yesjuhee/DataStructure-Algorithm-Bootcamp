#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define P pair<int, int>

using namespace std;

int visited[10001] = {0};
vector<P> edge[10001];
// edge[0][0].first = vertex 0에 연결된 첫 번째 edge의 가중치
// edge[0][0].second = vertex 0에 연결된 첫 번째 edge의 도착 정점
// edge[0] -> {3, 1} : vertex 0 - vertex 1 은 weight 3짜리 edge로 연결됨

int prim()
{
    int new_vertex = 0, new_distance = 0, result = 0, vertex_from_now = 0;
    priority_queue<P> pq; // first = 가중치, second = 정점
    pq.push(P(0, 0));

    while (!pq.empty())
    {
        new_vertex = pq.top().second; // 새로 추가되는 vertex
        new_distance = -pq.top().first; // 새로 추가되는 edge의 값
        pq.pop();
        
        if (visited[new_vertex]) //new_vertex가 사이클을 형성하는지 확인
            continue;
        visited[new_vertex] = 1; // 정점 방문 표시

        // result에 추가 (전체 비용 계산)
        result += new_distance;
        
        for (int i = 0; i < edge[new_vertex].size(); i++)
        {
            // new_vertex에서 뻗어나오는 edge 수 만큼 반복하여 edge를 pq에 추가
            vertex_from_now = edge[new_vertex][i].second; // 새로운 edge에서 도착하는 정점 찾기
            
            if (!visited[vertex_from_now])
            {
                // 도착한 적이 없는 vertex에 연결된 edge라면 pq에 추가
                pq.push({-edge[new_vertex][i].first, edge[new_vertex][i].second});
            }
        }
    }
    return result; // 가중치의 전체 합 리턴
}

int main()
{
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
