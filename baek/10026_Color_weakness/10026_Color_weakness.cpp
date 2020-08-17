#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int n;

// bool의 자료형은 1byte 이므로
// bool을 써야 메모리초과를 줄일 수 있다.
bool visited[100][100];
char v[100][100];

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});

    visited[i][j] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int k = 0; k < 4; ++k)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                if (!visited[nx][ny])
                {
                    if (v[nx][ny] == v[x][y])
                    {
                        // BFS는 방문표시를 큐에서 뺀 다음이 아니라
                        // 큐에 넣을때 해야한다.
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
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

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> v[i][j];
        }
    }

    int non_cw = 0;

    // 색약이 아닌 경우
    // R, G, B 각각에 연결되있는 지점들만 따로따로 방문하여 구역을 count
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!visited[i][j])
            {
                bfs(i, j);
                non_cw++;
            }
        }
    }

    // 적록색약
    // visited 초기화
    memset(visited, false, sizeof(visited));
    int cw = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            // 적록색약이므로 적색과 녹색의 차이를 못느낌
            // 즉 한쪽색을 다른쪽 색으로 바꾸면 됨
            if (v[i][j] == 'G')
            {
                v[i][j] = 'R';
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!visited[i][j])
            {
                bfs(i, j);
                cw++;
            }
        }
    }

    cout << non_cw << " " << cw << "\n";
    
    return 0;
}
