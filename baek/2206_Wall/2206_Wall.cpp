#include <iostream>
#include <queue>
using namespace std;

int n, m;

// 1 : 안부숨, 0 : 부숨
// 부쉇는지 안부쉈는지에 따라 해당지점을 다시 갈 수 있음을 주의!!
bool visited[1001][1001][2];
int a[1001][1001];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

class Info
{
public:
    bool isBreak;
    int x;
    int y;
    int cnt;

    Info(bool isBreak, int x, int y, int cnt)
    {
        this->isBreak = isBreak;
        this->x = x;
        this->y = y;
        this->cnt = cnt;
    }
};

int bfs()
{
    int result = 1;
    queue<Info> q;
    // 시작 칸도 포함
    q.push(Info(true, 0, 0, 1));
    visited[0][0][1] = true;

    while (!q.empty())
    {
        bool isBreak = q.front().isBreak;
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        q.pop();

        if (x == m - 1 && y == n - 1)
        {
            return cnt;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < m && ny < n)
            {
                if (a[ny][nx] == 0 && !visited[ny][nx][isBreak])
                {
                    visited[ny][nx][isBreak] = true;

                    // 끝나는 칸도 포함
                    q.push(Info(isBreak, nx, ny, cnt + 1));
                }

                if (a[ny][nx] == 1 && isBreak)
                {
                    if (!visited[ny][nx][isBreak])
                    {
                        visited[ny][nx][isBreak] = true;

                        // 끝나는 칸도 포함
                        q.push(Info(!isBreak, nx, ny, cnt + 1));
                    }
                }
            }
        }
    }

    return -1;
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

    int result = bfs();

    cout << result << "\n";

    return 0;
}