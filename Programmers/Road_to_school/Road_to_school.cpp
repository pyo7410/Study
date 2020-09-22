#include <iostream>
#include <string>
#include <vector>
#define MOD 1000000007
using namespace std;

// 1, 1부터 시작하게하여 DP 처리를 할 수 있게한다.
int d[101][101];

int solution(int m, int n, vector<vector<int>> puddles) 
{
    int answer = 0;
    int x, y;
    
    for (int i = 0; i < puddles.size(); ++i)
    {
        x = puddles[i][0];
        y = puddles[i][1];

        d[y][x] = -1;
    }

    // 행의 맨 위와 열의 맨 앞은 갈 수 있는 가지수는 반드시 한가지 뿐이다.
    // 초기화
    /*for (int i = 1; i <= m; ++i)
    {
        d[1][i] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        d[i][1] = 1;
    }*/
    
    d[1][1] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (d[i][j] == -1)
            {
                continue;
            }

            if (d[i - 1][j] == -1)
            {
                d[i][j] += d[i][j - 1];
                d[i][j] %= MOD;
            }
            else if (d[i][j - 1] == -1)
            {
                d[i][j] += d[i - 1][j];
                d[i][j] %= MOD;
            }
            else
            {
                d[i][j] += d[i - 1][j] + d[i][j - 1];
                d[i][j] %= MOD;
            }
        }
    }

    answer = d[n][m] % MOD;
    
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n;
    cin >> m >> n;

    int k;
    cin >> k;

    vector<vector<int>> puddles(k, vector<int>(2));
    for (int i = 0; i < k; ++i)
    {
        cin >> puddles[i][0] >> puddles[i][1];
    }

    cout << solution(m, n, puddles) << "\n";

    return 0;
}