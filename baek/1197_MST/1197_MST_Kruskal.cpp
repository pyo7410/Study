#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 각 노드의 연결된 부모를 저장
vector<int> p(100005, -1);

int find(int x)
{
    // 만약 부모가 없다면
    if (p[x] < 0)
    {
        // 값을 그대로 반환
        return x;
    }

    // 부모가 있다면 최종 부모를 찾을때까지 재귀를 하고
    // 찾은 값을 반환
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v)
{
    u = find(u);
    v = find(v);

    // 만약 u와 v의 부모가 같다면
    // 싸이클 즉, union이므로 false를 return
    if (u == v)
    {
        return false;
    }

    // u와 v의 부모가 다를경우
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
    
    return 1;
}

// 정점의 개수, 간선의 개수
int v, e;

// 가중치, a 정점, b 정점
// 간선을 저장한다.
pair<int, pair<int, int>> edge[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int v, e;
    cin >> v >> e;

    for (int i = 0; i < e; ++i)
    {
        // a 번 정점과 b번 정점이 가중치 c인 간선으로 연결
        int a, b, c;
        cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;
    }

    // edge는 간선을 저장하므로
    sort(edge, edge + e);

    int cnt = 0;
    int ans = 0;

    for (int i = 0; i < e; ++i)
    {
        int cost = edge[i].first;
        int v1 = edge[i].second.first;
        int v2 = edge[i].second.second;

        // 같은 그룹이 맞다면 continue;
        if (!is_diff_group(v1, v2))
        {
            continue;
        }
        
        ans += cost;
        cnt++;

        // 간선의 개수 - 1 만큼 MST를 구했다면 전부 구한것이므로
        if (cnt == v - 1)
        {
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}