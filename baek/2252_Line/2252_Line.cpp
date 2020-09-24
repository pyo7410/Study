#include <iostream>
#include <queue>
using namespace std;

int in[32001];
int result[32001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> students(n + 1);

    int a, b;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        students[a].push_back(b);
        in[b]++; 
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        // 0 이라면
        if (!in[i])
        {
            q.push(i);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        int x = q.front();
        q.pop();

        result[i] = x;

        for (int j = 0; j < students[x].size(); ++j)
        {
            int y = students[x][j];

            if (--in[y] == 0)
            {
                q.push(y);
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