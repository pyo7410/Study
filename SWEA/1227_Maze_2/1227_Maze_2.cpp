#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

int maze[100][100];
int visited[100][100];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

void bfs(int i, int j)
{
    // 0으로 초기화
    memset(visited, 0, sizeof(maze));

    queue<pair<int, int>> q;
    q.push(make_pair(i, j));

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        visited[x][y] = 1;

        for (int k = 0; k < 4; ++k)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < 100 && ny >= 0 && ny < 100)
            {
                if (visited[nx][ny] == 0)
                {
                    if (maze[nx][ny] == 0 || maze[nx][ny] == 3)
                    {
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }    
}

int main()
{
	for (int test_case = 1; test_case <= 10; ++test_case)
    {
        int n;
        cin >> n;

        pair<int, int> start, end;
        for (int i = 0; i < 100; ++i)
        {
            for (int j = 0; j < 100; ++j)
            {
                scanf("%1d", &maze[i][j]);
                if (maze[i][j] == 2)
                {
                    start = make_pair(i, j);
                }
                else if (maze[i][j] == 3)
                {
                    end = make_pair(i, j);
                }
            }
        }

        bfs(start.first, start.second);

        printf("#%d %d\n", test_case, visited[end.first][end.second]);
    }

    return 0;
}
