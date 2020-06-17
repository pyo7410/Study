#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;

int a[101][101];
int d[101][101];
int check[101][101];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    check[x][y] = true; // check를 잊지말자!
    d[x][y] = 1;

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;

        q.pop();

        for (int k = 0; k < 4; ++k)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                // bfs는 단계별로 진행이 되므로 마지막에는 check를 통해
                // 빨리 들어간 값이 저장되있다.
                if (a[nx][ny] == 1 && check[nx][ny] == false)
                {
                    d[nx][ny] = d[x][y] + 1;
                    q.push(make_pair(nx, ny));
                    check[nx][ny] = true;
                }
            }
        }
    }
}

int main()
{
	scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%1d", &a[i][j]);
        }
    }

    bfs(0, 0);
    
    cout << d[n - 1][m - 1] << "\n";

    return 0;
}
