#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int in[32001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 1 ~ n 까지 이므로 n + 1
    vector<vector<int>> v(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);

        // 들어오는 간선의 경로 +1
        in[b] += 1;
    }

    priority_queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (!in[i])
        {
            // -를 하고 우선순위 큐에 넣어주면 작은 숫자의 우선순위가 더 커지게 되어
            // 문제에서 요구하는 쉬운 문제는 먼저 푼다가 가능해 진다.
            q.push(-i);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        // 항상 문제를 모두 풀 수 있는 경우만 주어지므로 큐가 비었는지는 안봐도 된다.
        int x = -q.top();
        cout << x << " ";
        q.pop();

        for (int j = 0; j < v[x].size(); ++j)
        {
            int y = v[x][j];

            if (--in[y] == 0)
            {
                q.push(-y);
            }
        }
    }
    
    return 0;
}
