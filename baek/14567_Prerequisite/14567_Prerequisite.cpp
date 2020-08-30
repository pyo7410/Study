#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> in(n + 1, 0);
    vector<vector<int>> subject(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;

        subject[a].push_back(b);
        in[b] += 1;
    }

    vector<int> result(n + 1);
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; ++i)
    {
        if (!in[i])
        {
            q.push({i, 1});
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        int x = q.front().first;
        int semester = q.front().second;
        result[x] = semester;
        q.pop();

        for (int j = 0; j < subject[x].size(); ++j)
        {
            int y = subject[x][j];

            if (--in[y] == 0)
            {
                q.push({y, semester + 1});
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << result[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
