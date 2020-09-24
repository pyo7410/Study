#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// cost, a 정점, b 정점
pair<int, pair<int, int>> edge[101];
vector<int> p(101, -1);

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

int solution(int n, vector<vector<int>> costs) 
{
    int answer = 0;
    int cnt = 0;
    
    for (int i = 0; i < costs.size(); ++i)
    {
        edge[i].second.first = costs[i][0];
        edge[i].second.second = costs[i][1];
        edge[i].first = costs[i][2];
    }

    // cost를 기준으로 오름차순 정렬
    sort(edge, edge + costs.size());

    for (int i = 0; i < costs.size(); ++i)
    {
        int cost = edge[i].first;
        int v1 = edge[i].second.first;
        int v2 = edge[i].second.second;

        // 같은 그룹이라면 continue;
        if (!is_diff_group(v1, v2))
        {
            continue;
        }

        answer += cost;
        cnt++;

        if (cnt == n - 1)
        {
            break;
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> costs(m, vector<int>(3));

    for (int i = 0; i < m; ++i)
    {
        cin >> costs[i][0] >> costs[i][1] >> costs[i][2];
    }

    cout << solution(n, costs) << "\n";

    return 0;
}