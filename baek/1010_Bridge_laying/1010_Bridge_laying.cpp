#include <iostream>
#include <cstring>
using namespace std;

long long dp[31][31];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        // 매번 마다 0으로 초기화 잊지말자!
        memset(dp, 0, sizeof(dp));
        int n, m;
        cin >> n >> m;

        // 다리 1개를 m의 포인트에 놓으면 가지수는 m개가 된다
        for (int i = 1; i <= m; ++i)
        {
            dp[1][i] = i;
        }

        for (int i = 2; i <= n; ++i)
        {
            // 다리는 겹치면 안되므로 i 아래로만 새로운 다리를 놓을 수 있다!
            for (int j = i; j <= m; ++j)
            {
                // i 아래에 세워지는 다리는 절! 대! i를 넘을 수 없다는 것에 주의
                for (int k = j; k >= i; k--)
                {
                    dp[i][j] += dp[i - 1][k - 1];
                }
            }
        }

        cout << dp[n][m] << "\n";
    }
    
    return 0;
}
