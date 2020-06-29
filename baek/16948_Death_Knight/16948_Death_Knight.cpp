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

    memset(dist, -1, sizeof(dist)); // dist 배열의 모든 값을 -1로 초기화

    dist[r1][c1] = 0; // 시작점 거리 초기화

    queue<pair<int, int>> q;
    q.push(make_pair(r1, c1));

    while (!q.empty())
    {
        int x, y;
        tie(x, y) = q.front(); // tuple 헤더에 있는 tie 함수를 이용해 pair를 각각 x, y에 저장
        q.pop();

        for (int i = 0; i < 6; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx <= n && 0 <= ny && ny <= n) // 체스판의 크기는 n x n
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
