#include <iostream>
#include <queue>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m;

int box[1001][1001];
bool visited[1001][1001];

void bfs()
{
    queue<pair<int, int>> q;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (box[i][j] == 1)
            {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (!visited[nx][ny])
                {
                    box[nx][ny] = box[x][y] + 1;

                    visited[nx][ny] = visited;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> box[i][j];

            if (box[i][j] == -1)
            {
                visited[i][j] = true;
            }
        }
    }

    bfs();

    int ans = -1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (box[i][j] == 0)
            {
                cout << -1 << "\n";
                return 0;
            }

            if (ans < box[i][j])
            {
                // box는 1부터 시작했으므로
                // 일수는 -1 해주어야 한다.
                ans = box[i][j] - 1;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
