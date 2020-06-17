#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a[20001];
int color[20001];
// 0 : �湮 ����
// 1 : �׷��ȣ 1 �湮
// 2 : �׷��ȣ 2 �湮

bool dfs(int node, int c)
{
    color[node] = c;
    for (int i = 0; i < a[node].size(); ++i)
    {
        int next = a[node][i];
        if (color[next] == 0)
        {
            if (dfs(next, 3 - c) == false) // �̺б׷����̹Ƿ� 1, 2 �ݺ�
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

        // �ʱ�ȭ
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
