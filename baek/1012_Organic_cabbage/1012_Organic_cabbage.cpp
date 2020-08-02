#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int field[50][50];
int n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        field[x][y] = 2;

        for (int k = 0; k < 4; ++k)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (field[nx][ny] == 1)
                {
                    field[nx][ny] = 2;
                    q.push(make_pair(nx, ny));
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

    int t, k, x, y;

    cin >> t;

    while (t--)
    {
        memset(field, 0, sizeof(field));

        cin >> m >> n >> k;

        for (int i = 0; i < k; ++i)
        {
            cin >> x >> y;
            field[y][x] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (field[i][j] == 1)
                {
                    cnt += 1;
                    bfs(i, j);    
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
