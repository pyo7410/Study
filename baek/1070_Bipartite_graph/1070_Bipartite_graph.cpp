#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a[20001];
int color[20001];
// 0 : 방문 안함
// 1 : 그룹번호 1 방문
// 2 : 그룹번호 2 방문

bool dfs(int node, int c)
{
    color[node] = c;
    for (int i = 0; i < a[node].size(); ++i)
    {
        int next = a[node][i];
        if (color[next] == 0)
        {
            if (dfs(next, 3 - c) == false) // 이분그래프이므로 1, 2 반복
            {
                return false;
            }
        }
        else if (color[next] == color[node])
        {
            return false;
        }
    }
    return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int k, v, e;
    int from, to;
    cin >> k;

    while (k--)
    {
        cin >> v >> e;

        // 초기화
        for (int i = 1; i <= v; ++i)
        {
            a[i].clear();
            color[i] = 0;
        }

        for (int i = 0; i < e; ++i)
        {
            cin >> from >> to;

            a[from].push_back(to);
            a[to].push_back(from);
        }

        bool ok = true;
        for (int i = 1; i <= v; ++i)
        {
            if (color[i] == 0)
            {
                if (dfs(i, 1) == false)
                {
                    ok = false;
                }
            }
        }
        if (ok)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
