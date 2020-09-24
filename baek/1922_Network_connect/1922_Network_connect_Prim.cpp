#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
using namespace std;

using ti3 = tuple<int, int, int>;
bool chk[1001];

// cost, 연결된 노드
vector<pair<int, int>> adj[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    priority_queue<ti3, vector<ti3>, greater<ti3>> pq;
    
    for (auto nxt : adj[1])
    {
        // cost, 현재노드, 연결된 노드
        pq.push({nxt.first, 1, nxt.second});
    }

    chk[1] = true;

    int cnt = 0;
    int ans = 0;
    while (1)
    {
        int cost, v1, v2;
        tie(cost, v1, v2) = pq.top();
        pq.pop();

        if (chk[v2])
        {
            continue;
        }

        chk[v2] = true;

        ans += cost;
        cnt++;

        if (cnt == n - 1)
        {
            break;
        }

        for (auto nxt : adj[v2])
        {
            if (!chk[nxt.second])
            {
                pq.push({nxt.first, v2, nxt.second});
            }
        }
    }

    cout << ans << "\n";

    return 0;
}