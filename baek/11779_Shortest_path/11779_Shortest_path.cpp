#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

using pii = pair<int, int>;
int v, e, st, en;

// cost, index
vector<pii> adj[1001];

// 거리 기록
int d[1001];

// 경로 기록
int pre[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> v >> e;

    fill(d, d + v + 1, INF);

    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({w, v});
    }

    cin >> st >> en;

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // 시작점 거리 0으로 세팅
    d[st] = 0;
    pq.push({d[st], st});

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        int dist = cur.first;
        int idx = cur.second;

        if (dist != d[idx])
        {
            continue;
        }

        for (auto nxt : adj[idx])
        {
            int cost = nxt.first;
            int nidx = nxt.second;

            if (d[nidx] > cost + dist)
            {
                d[nidx] = cost + dist;
                pq.push({d[nidx], nidx});
                pre[nidx] = idx;
            }
        }
    }

    cout << d[en] << "\n";
    
    vector<int> path;
    int cur = en;

    while (cur != st)
    {
        path.push_back(cur);
        cur = pre[cur];
    }

    path.push_back(cur);

    reverse(path.begin(), path.end());
    
    cout << path.size() << "\n";

    for (auto x : path)
    {
        cout << x << " ";
    }

    cout << "\n";

    return 0;
}