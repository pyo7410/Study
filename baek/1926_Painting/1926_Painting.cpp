#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int a[501][501];
bool visited[501][501];
int n, m;

class Info {
public:
    int x;
    int y;

    Info(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int bfs(int i, int j)
{
    // 시작지점까지 포함
    int painting_size = 1;
    queue<Info> q;
    q.push(Info(j, i));
    visited[i][j] = true;

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n)
            {
                if (a[ny][nx] == 1 && !visited[ny][nx])
                {
                    painting_size++;
                    visited[ny][nx] = true;
                    q.push(Info(nx, ny));
                }
            }
        }
    }
    
    return painting_size;
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
            cin >> a[i][j];
        }
    }

    int cnt = 0;
    int max_size = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == 1 && !visited[i][j])
            {
                cnt++;
                max_size = max(bfs(i, j), max_size);
            }
        }
    }

    cout << cnt << "\n" << max_size << "\n";

    return 0;
}