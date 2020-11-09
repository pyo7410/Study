#include <iostream>
#include <queue>
using namespace std;

int graph[201][201];
int n, m;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int bfs(int y, int x)
{
    queue<pair<int, int>> q;
    q.push({y, x});

    while (!q.empty())
    {
        int xx = q.front().second;
        int yy = q.front().first;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx >= 0 && ny >= 0 && nx < m && ny < n)
            {
                if (graph[ny][nx] == 0)
                {
                    continue;
                }

                if (graph[ny][nx] == 1)
                {
                    graph[ny][nx] = graph[yy][xx] + 1;
                    q.push({ny, nx});
                }
            }
        }
    }

    return graph[n - 1][m - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%1d", &graph[i][j]);
        }
    }

    cout << bfs(0, 0) << "\n";

    return 0;
}