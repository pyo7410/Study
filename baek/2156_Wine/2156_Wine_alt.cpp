#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int wine[10001];

// 해당 자리에서 cnt가 전부 다르므로
// 즉, 와인을 안마셨을때와 마셨을때의 값이 덮어 씌어지는 것을 막기위해
// 2차원 배열사용
int dp[10001][3];

int solve(int n, int cnt)
{
    if (n <= 0)
    {
        return 0;
    }

    if (dp[n][cnt] != -1)
    {
        return dp[n][cnt];
    }

    
    if (cnt < 2)
    {
        // 한잔도 안먹었거나 한잔만 먹었을 경우
        // 현재 잔을 먹거나 안먹을 수 있다.
        dp[n][cnt] = max(solve(n - 1, cnt + 1) + wine[n], solve(n - 1, 0));
    }
    else
    {
        // 두잔 연속해서 먹었다면 현재 잔을 먹지 못한다.
        dp[n][cnt] = solve(n - 1, 0);
    }
    
    
    return dp[n][cnt];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> wine[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(n, 0) << "\n";

    return 0;
}