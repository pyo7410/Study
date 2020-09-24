#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

using pii = pair<int, int>;
int v, e, k;

// cost, index
vector<pair<int, int>> adj[20001];
int d[20001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> v >> e >> k;

    // 문제에선 간선이 1부터 시작하므로
    fill(d, d + v + 1, INF);

    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        // cost, index
        adj[u].push_back({w, v});
    }

    // cost, 인덱스
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // 출발지점의 거리는 0으로 초기화
    d[k] = 0;

    // cost, 인덱스 
    pq.push({d[k], k});

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        // 큐에 저장된 값
        int dist = cur.first;
        int idx = cur.second;

        if (d[idx] != dist)
        {
            // d에 저장된 거리와 큐에 저장된 거리가 다르다는것은
            // 큐에 저장된 후 d의 값이 바뀌었단 이야기 이므로
            // continue;
            continue;
        }

        // 큐에서 꺼낸 인덱스와 연결된 인덱스의 정보
        for (auto nxt : adj[idx])
        {
            int cost = nxt.first;
            int nidx = nxt.second;

            if (d[nidx] > dist + cost)
            {
                d[nidx] = dist + cost;
                pq.push({d[nidx], nidx});
            }
        }
    }

    // 각 정점까지 갈 수 있는 최단 거리
    // INF 라면 가는 길이 없다는 의미
    for (int i = 1; i <= v; ++i)
    {
        if (d[i] == INF)
        {
            cout << "INF\n";
        }
        else
        {
            cout << d[i] << "\n";
        }
    }

    return 0;
}