#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int w, h;

int a[51][51];
int d[51][51];

int dx[8] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, 1, -1, -1, 1, -1, 1};

void bfs(int x, int y, int cnt)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    d[x][y] = cnt;

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;

        q.pop();

        for (int k = 0; k < 8; ++k)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (0 <= nx && nx < w && 0 <= ny && ny < h)
            {
                if (a[nx][ny] == 1 && d[nx][ny] == 0)
                {
                    d[nx][ny] = cnt;
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

    while (true)
    {
        int cnt = 0;

        cin >> h >> w; // 입력값의 w, h가 바뀌어 있음을 주의하자!

        if (w == 0 && h == 0)
        {
            break;
        }

        for (int i = 0; i < w; ++i)
        {
            for (int j = 0; j < h; ++j)
            {
                d[i][j] = 0;
                cin >> a[i][j];
            }
        }

        for (int i = 0; i < w; ++i)
        {
            for (int j = 0; j < h; ++j)
            {
                if (a[i][j] == 1 && d[i][j] == 0)
                {
                    bfs(i, j, ++cnt);
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
