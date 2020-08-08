#include <iostream>
using namespace std;

int a[16][16];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    int x, y;
    int cnt = 1;
    // 배열에 행과 열을 한칸씩 추가하여 점화식에 의해
    // 0행과 0열이 이동하는 경우의 수가 1이되게 해준다.
    a[0][1] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            a[i][j] = a[i - 1][j] + a[i][j - 1];
            if (k == cnt)
            {
                x = i;
                y = j;
            }
            cnt += 1;
        }
    }

    if (k == 0)
    {
        cout << a[n][m] << "\n";
    }
    else
    {
        // 1부터 시작했으므로
        int nx = n - x + 1;
        int ny = m - y + 1;

        // 위에서부터 칸의 수에 대한 경우의 수가 배열에 저장되어있으므로
        // O 까지의 경우의 수 * O에서 (n, m) 까지의 경우의 수 = O을 거쳐가는 경우의 수
        // nx, ny는 O에서 (n, m) 까지의 사각형의 마지막 좌표이므로
        // 크기를 구해서 경우의 수를 알 수 있다.
        // e.g. nx = 2, ny = 3일경우 a[2][3] 의 경우의 수와 같다!
        cout << a[x][y] * a[nx][ny] << "\n";
    }
    

    return 0;
}
