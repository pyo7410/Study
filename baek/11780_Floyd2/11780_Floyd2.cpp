#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int d[101][101];
int next_d[101][101];
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        // 1부터 시작했으므로 끝나는 지점에 +1을 한다.
        fill(d[i], d[i] + 1 + n, INF);
    }

    while (m--)  
    {
        int a, b, c;
        cin >> a >> b >> c;

        // 단방향이므로
        d[a][b] = min(d[a][b], c);

        // a에서 b로 갈때 경로는 입력받은 직후에 b뿐이므로 b가 된다.
        next_d[a][b] = b;
    }

    // 자기 자신은 0으로 초기화해야함을 주의!!
    for (int i = 1; i <= n; ++i)
    {
        d[i][i] = 0;
    }

    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {                
                if (d[i][j] > d[i][k] + d[k][j])
                {
                    // d[i][j]로 가기위한 최단경로는 k를 통과하는 경로이므로
                    next_d[i][j] = next_d[i][k];
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    // 모든 경로의 비용 출력
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
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

    // i 에서 j로 가는 모든 경로를 출력
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            // d[i][j]로 가는 경로가 없거나 자기자신일 경우 0 출력
            if (d[i][j] == INF || d[i][j] == 0)
            {
                cout << "0\n";
                continue;
            }

            vector<int> path;
            int start = i;

            // i 에서 부터 j 로 가는 경로를 출력
            // j 에 도착할때까지 반복
            while (start != j)
            {
                path.push_back(start);
                start = next_d[start][j];
            }
            // 마지막 j도 넣어줘야 한다.
            path.push_back(j);

            // 경로상에 있는 도시 개수 출력
            cout << path.size() << " ";

            // 도시 순서대로 출력
            for (auto city : path)
            {
                cout << city << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}