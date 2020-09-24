#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int in[1001];
int result[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(m, vector<int>(n + 1, 0));
    for (int i = 0; i < m; ++i)
    {
        int num;
        cin >> num;

        int singer1;
        cin >> singer1;

        for (int j = 1; j < num; ++j)
        {
            int singer2;
            cin >> singer2;

            v[i][singer1] = singer2;
            singer1 = singer2;

            in[singer2] += 1;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (!in[i])
        {
            q.push(i);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (q.empty()) // 싸이클이 발생 했으므로 순서를 만족할 수 없다.
        {
            cout << 0 << "\n";
            return 0;
        }

        // 큐의 가장 앞의 원소를 빼서 result에 넣어준다.
        int x = q.front();
        q.pop();
        result[i] = x;

        // 꺼낸 원소에 연결되있는 모든 정점을 확인하면서 간선제거
        // 간선을 따라 검사하기 떄문에 중복 걱정 X
        for (int j = 0; j < m; ++j)
        {
            int y = v[j][x];

            if (--in[y] == 0)
            {
                q.push(y);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << result[i] << "\n";
    }

    return 0;
}
