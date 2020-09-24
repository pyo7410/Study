#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// 가중치, 현재 노드, 연결된 노드
using ti3 = tuple<int, int, int>;
int v, e;

// MST에 포함여부 판단
bool chk[100005];

// cost, index
vector<pair<int, int>> adj[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> v >> e;

    for (int i = 0; i < e; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;

        // 연결되어 있으므로 양쪽에 넣어주어야 한다.
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    int cnt = 0;
    int ans = 0;

    priority_queue<ti3, vector<ti3>, greater<ti3>> pq;

    // 1번 노드부터 시작(다른노드도 상관없음)
    // 1번 노드와 연결된 간선들을 큐에 넣음
    for (auto nxt : adj[1])
    {
        // 가중치, 현재 노드, 연결된 노드
        pq.push({nxt.first, 1, nxt.second});
    }

    // 1번 노드를 선택했으므로 MST에 추가
    chk[1] = true;

    while (1)
    {
        int cost, v1, v2;
        tie(cost, v1, v2) = pq.top();
        pq.pop();

        // 만약 연결된 노드가 이미 MST에 포함되어있다면
        if (chk[v2])
        {
            continue;
        }

        chk[v2] = true;

        ans += cost;
        cnt++;

        if (cnt == v - 1)
        {
            break;
        }

        // v2를 MST에 추가하고 v2와 연결된 간선을 전부 큐에 추가
        for (auto nxt : adj[v2])
        {
            // 만약 연결된 간선중 이미 MST에 포함된 간선이 있다면 제외
            if (!chk[nxt.second])
            {
                pq.push({nxt.first, v2, nxt.second});
            }
        }
    }
    
    cout << ans << "\n";

    return 0;
}