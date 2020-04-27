#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> a[1001];
bool check_dfs[1001];
bool check_bfs[1001];
// memset(check,false,sizeof(check)); 으로 check 하나로 초기화 해서 사용가능

void dfs(int node)
{
    int next;

    cout << node << " ";

    check_dfs[node] = true;
    for (int i = 0; i < a[node].size(); ++i)
    {
        next = a[node][i];
        if (check_dfs[next] == false)
        {
            dfs(next);
        }
    }
}

void bfs(int start)
{
    queue<int> q;
    int node, next;

    check_bfs[start] = true;
    q.push(start);

    while (!q.empty())
    {
        node = q.front();
        q.pop();

        cout << node << " ";

        for (int i = 0; i < a[node].size(); ++i)
        {
            next = a[node][i];
            if (check_bfs[next] == false)
            {
                check_bfs[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n, m, v;
    int from, to;
    cin >> n >> m >> v;

    for (int i = 1; i <= m; ++i)
    {
        cin >> from >> to;

        a[from].push_back(to);
        a[to].push_back(from);
    }

    for (int i = 1; i <= n; ++i)
    {
        sort(a[i].begin(), a[i].end());
    }

    dfs(v);
    cout << "\n";
    bfs(v);
    cout << "\n";

    return 0;
}
