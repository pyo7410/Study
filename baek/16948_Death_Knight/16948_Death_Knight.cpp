#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};
int dist[200][200];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    cin >> n;

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    memset(dist, -1, sizeof(dist)); // dist �迭�� ��� ���� -1�� �ʱ�ȭ

    dist[r1][c1] = 0; // ������ �Ÿ� �ʱ�ȭ

    queue<pair<int, int>> q;
    q.push(make_pair(r1, c1));

    while (!q.empty())
    {
        int x, y;
        tie(x, y) = q.front(); // tuple ����� �ִ� tie �Լ��� �̿��� pair�� ���� x, y�� ����
        q.pop();

        for (int i = 0; i < 6; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx <= n && 0 <= ny && ny <= n) // ü������ ũ��� n x n
            {
                if (dist[nx][ny] == -1)
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    cout << dist[r2][c2] << "\n";
    
    return 0;
}
