#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int sticker[3][100001];
int dp[3][100001];

// 배열의 인덱스가 1부터 시작함을 주의
int solve(int i, int n)
{
    if (n <= 0)
    {
        return 0;
    }

    if (dp[i][n] != -1)
    {
        return dp[i][n];
    }

    // 스티커는 대각선 위나 아래 혹은 아예 안뗄수도 있다!
    if (i == 1)
    {
        dp[i][n] = max({solve(2, n - 1), solve(1, n - 2), solve(2, n - 2)}) + sticker[i][n];
    }
    else
    {
        dp[i][n] = max({solve(1, n - 1), solve(1, n - 2), solve(2, n - 2)}) + sticker[i][n];
    }
    
    return dp[i][n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 1; i <= 2; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cin >> sticker[i][j];
            }
        }

        // 0으로 초기화 할 경우 sticker가 전부 0 이라면
        // 정답은 0이 될 수 도 있으므로 -1 로 초기화를 해야
        // 메모이제이션을 사용하여
        // 시간초과를 막을 수 있다.
        memset(dp, -1, sizeof(dp));

        int result = 0;
        for (int i = 1; i <= 2; ++i)
        {
            result = max(result, solve(i, n));
        }

        cout << result << "\n";
    }

    return 0;
}