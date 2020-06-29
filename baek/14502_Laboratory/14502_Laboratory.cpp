#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int n, m;
int a[10][10]; // ����
int b[10][10]; // ���纻

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int bfs()
{
    queue<pair<int, int>> q;
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            b[i][j] = a[i][j]; // �迭�� ����
            if (b[i][j] == 2)
            {
                // ���̷����� ��ġ�� ������ġ��
                q.push(make_pair(i, j));
            }
        }
    }

    while (!q.empty())
    {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        // ���̷����� �����¿�� �̵�����
        for (int k = 0; k < 4; ++k)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if (b[nx][ny] == 0)
                {
                    b[nx][ny] = 2; // ���̷��� ����
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (b[i][j] == 0)
            {
                cnt += 1;
            }
        }
    }

    return cnt;
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

    int ans = 0;

    for (int x1 = 0; x1 < n; ++x1)
    {
        for (int y1 = 0; y1 < m; ++y1)
        {
            if (a[x1][y1] != 0)
            {
                continue;
            }
            for (int x2 = 0; x2 < n; ++x2)
            {
                for (int y2 = 0; y2 < m; ++y2)
                {
                    if (a[x2][y2] != 0)
                    {
                        continue;
                    }
                    for (int x3 = 0; x3 < n; ++x3)
                    {
                        for (int y3 = 0; y3 < m; ++y3)
                        {
                            // �� 3���� ����� ���� ����
                            // 0�� �ƴϿ��� �ϰ�
                            // �� 3���� ��ġ�� ���� �޶�� �Ѵ�.
                            if (a[x3][y3] != 0)
                            {
                                continue;
                            }
                            if (x1 == x2 && y1 == y2)
                            {
                                continue;
                            }
                            // x1, y1�� x3, y3�� ���ؾ��Ѵ�!!
                            if (x1 == x3 && y1 == y3)
                            {
                                continue;
                            }
                            if (x2 == x3 && y2 == y3)
                            {
                                continue;
                            }

                            // ���� ����
                            a[x1][y1] = 1;
                            a[x2][y2] = 1;
                            a[x3][y3] = 1;

                            int cur = bfs();

                            if (ans < cur)
                            {
                                ans = cur;
                            }

                            // �ٸ� ����� ���� ����� ���� ������ ���� �ʱ�ȭ
                            a[x1][y1] = 0;
                            a[x2][y2] = 0;
                            a[x3][y3] = 0;
                        }
                    }
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
