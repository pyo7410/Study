#include <iostream>
#define INF 987654321
using namespace std;

int d[105][105];
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        // 1 부터 시작했으므로 + 1을 해준다.
        fill(d[i], d[i] + 1 + n, INF);
    }

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // 최소 비용을 구하는 문제이고
        // 노선은 하나가 아닐 수 있으므로
        // 현재 저장된 값보다 작은 값을 저장한다.
        d[a][b] = min(d[a][b], c);
    }

    for (int i = 1; i <= n; ++i)
    {
        // 자기 자신은 0
        d[i][i] = 0;
    }

    // k 는 각 번호당 한번씩 거쳐가는 경로의 비용을 구하기 위해 반복
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                // 현재 저장된 경로의 비용보다 k를 거쳐가는 비용이 더 적다면
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            // 초기값을 INF로 했으므로 0으로 출력
            if (d[i][j] == INF)
            {
                cout << "0 ";
            }
            else
            {
                cout << d[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}