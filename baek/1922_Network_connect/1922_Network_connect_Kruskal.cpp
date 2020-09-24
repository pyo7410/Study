#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// cost, a 정점, b 정점
pair<int, pair<int, int>> edge[100001];
vector<int> p(100001, -1);

int find(int x)
{
    if (p[x] < 0)
    {
        return x;
    }

    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v)
{
    u = find(u);
    v = find(v);

    if (u == v)
    {
        return false;
    }

    if (p[u] == p[v])
    {
        p[u]--;
    }

    if (p[u] < p[v])
    {
        p[v] = u;
    }
    else
    {
        p[u] = v;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;
    }

    sort(edge, edge + m);

    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < m; ++i)
    {
        int cost = edge[i].first;
        int v1 = edge[i].second.first;
        int v2 = edge[i].second.second;

        if (!is_diff_group(v1, v2))
        {
            continue;
        }

        ans += cost;
        cnt++;

        if (cnt == n - 1)
        {
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}