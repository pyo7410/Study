#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int n;

// bool�� �ڷ����� 1byte �̹Ƿ�
// bool�� ��� �޸��ʰ��� ���� �� �ִ�.
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
                        // BFS�� �湮ǥ�ø� ť���� �� ������ �ƴ϶�
                        // ť�� ������ �ؾ��Ѵ�.
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

    // ������ �ƴ� ���
    // R, G, B ������ ������ִ� �����鸸 ���ε��� �湮�Ͽ� ������ count
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

    // ���ϻ���
    // visited �ʱ�ȭ
    memset(visited, false, sizeof(visited));
    int cw = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            // ���ϻ����̹Ƿ� ������ ����� ���̸� ������
            // �� ���ʻ��� �ٸ��� ������ �ٲٸ� ��
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
